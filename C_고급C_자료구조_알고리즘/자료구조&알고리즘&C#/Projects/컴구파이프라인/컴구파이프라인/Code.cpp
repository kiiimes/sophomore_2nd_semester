#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/**************************************/

struct Control
{
	unsigned char RegDst;
	unsigned char Jump;
	unsigned char Branch;
	unsigned char MemRead;
	unsigned char MemtoReg;
	unsigned char ALUOp;
	unsigned char MemWrite;
	unsigned char ALUSrc;
	unsigned char RegWrite;
};

struct Reg_Read
{
	unsigned int Read_data_1;
	unsigned int Read_data_2;
};

struct ALU
{
	unsigned char zero; // 1: enable, 0: disable
	unsigned int ALU_result;
};

struct Control control;
struct Reg_Read reg_read;
struct ALU alu;
unsigned int mem[64] = { 0 };
unsigned int reg[32] = { 0 };

/**************************************/

unsigned int Inst_Fetch(unsigned int read_addr);
void Register_Read(unsigned int read_reg_1, unsigned int read_reg_2);
void Control_Signal(unsigned int opcode);
unsigned char ALU_Control_Signal(unsigned char signal);
void ALU_func(unsigned char ALU_control, unsigned int a, unsigned int b);
unsigned int Memory_Access(unsigned char MemWrite, unsigned char MemRead, unsigned int addr, unsigned int write_data);
void Register_Write(unsigned char RegWrite, unsigned int Write_reg, unsigned int Write_data);
unsigned int Sign_Extend(unsigned int inst_16);
unsigned int Shift_Left_2(unsigned int inst);
unsigned int Add(unsigned int a, unsigned int b);
unsigned int Mux(char signal, unsigned int a_0, unsigned int b_1);
void print_reg_mem(void);

/**************************************/

int main(void)
{
	unsigned int pc = 0;
	FILE *fp;
	unsigned int inst = 0;
	unsigned int inst_31_26 = 0;
	unsigned int inst_25_21 = 0;
	unsigned int inst_20_16 = 0;
	unsigned int inst_15_11 = 0;
	unsigned int inst_15_0 = 0;
	unsigned int inst_5_0 = 0;
	unsigned int inst_ext_32 = 0;
	unsigned int inst_ext_shift = 0;
	unsigned int pc_add_4 = 0;
	unsigned int pc_add_inst = 0;
	unsigned int mux_result = 0;
	unsigned char ALU_control = 0;
	unsigned int inst_25_0 = 0;
	unsigned int jump_addr = 0;
	unsigned int mem_result = 0;
	unsigned int add_result = 0;
	int total_cycle = 0;

	// register initialization
	/**************************************/
	reg[8] = 41621;
	reg[9] = 41621;
	reg[16] = 40;
	/**************************************/

	// memory initialization
	/**************************************/
	mem[40] = 3578;

	if (!(fp = fopen("input_3.txt", "r")))
	{
		printf("error: file open fail !!\n");
		exit(1);
	}

	while (feof(fp) == false)
	{
		fscanf(fp, "%x", &inst);
		mem[pc] = inst;//mem에 instruction 넣음
		pc = pc + 4;
	}
	/**************************************/

	// control initialization
	/**************************************/
	control.RegDst = 0;
	control.Jump = 0;
	control.Branch = 0;
	control.MemRead = 0;
	control.ALUOp = 0;
	control.MemWrite = 0;
	control.ALUSrc = 0;
	control.RegWrite = 0;
	/**************************************/

	print_reg_mem();

	printf("\n ***** Processor START !!! ***** \n");

	pc = 0;

	while (pc < 64)
	{
		// pc +4
		pc_add_4 = Add(pc, 4);

		// instruction fetch
		inst = Inst_Fetch(pc);
		printf("Instruction = %08x \n", inst);

		// instruction decode
		inst_31_26 = inst >> 26;
		inst_25_21 = (inst & 0x03e00000) >> 21;
		inst_20_16 = (inst & 0x001f0000) >> 16;
		inst_15_11 = (inst & 0x0000f800) >> 11;
		inst_15_0 = inst & 0x0000ffff;
		inst_25_0 = inst & 0x03ffffff;
		inst_5_0 = (Sign_Extend(inst_15_0) << 26) >> 26;

		//printf("%x, %x, %x, %x, %x, %x", inst_31_26, inst_25_21, inst_20_16, inst_15_11, inst_15_0, inst_25_0);

		pc_add_inst = ((pc_add_4 >> 28) << 28) + Shift_Left_2(inst_25_0);
		// register read
		Register_Read(inst_25_21, inst_20_16);

		// create control signal
		Control_Signal(inst_31_26);

		// create ALU control signal
		ALU_control = ALU_Control_Signal(inst_5_0);
		// ALU
		ALU_func(ALU_control, Mux(control.ALUSrc, reg_read.Read_data_2, Sign_Extend(inst_15_0)), reg_read.Read_data_1);

		// memory access
		Memory_Access(control.MemWrite, control.MemRead, alu.ALU_result, reg_read.Read_data_2);
		// register write
		Register_Write(control.RegWrite, Mux(control.RegDst, inst_20_16, inst_15_11),
			Mux(control.MemtoReg, alu.ALU_result,
				Memory_Access(control.MemWrite, control.MemRead, alu.ALU_result, reg_read.Read_data_2)));

		add_result = Add(pc_add_4, Shift_Left_2(Sign_Extend(inst_15_0)));

		pc = Mux((control.Branch&alu.zero), pc_add_4, add_result);
		pc = Mux(control.Jump, pc, pc_add_inst);
		total_cycle++;

		// result
		/********************************/
		printf("PC : %d \n", pc);
		printf("Total cycle : %d \n", total_cycle);
		print_reg_mem();
		/********************************/

		system("pause");
	}

	printf("\n ***** Processor END !!! ***** \n");

	return 0;
}

unsigned int Inst_Fetch(unsigned int read_addr)
{
	return mem[read_addr];
}

void Register_Read(unsigned int read_reg_1, unsigned int read_reg_2)
{
	reg_read.Read_data_1 = reg[read_reg_1];
	reg_read.Read_data_2 = reg[read_reg_2];
}//rd rt

void Control_Signal(unsigned int opcode)
{
	//opcode는 31~26
	if (opcode == 0) {
		control.RegDst = 1;
		control.ALUSrc = 0;
		control.MemtoReg = 0;
		control.RegWrite = 1;
		control.MemRead = 0;
		control.MemWrite = 0;
		control.Branch = 0;
		control.ALUOp = 2;
		control.Jump = 0;
	}//R-format
	else if (opcode == 35) {
		control.RegDst = 0;
		control.ALUSrc = 1;
		control.MemtoReg = 1;
		control.RegWrite = 1;
		control.MemRead = 1;
		control.MemWrite = 0;
		control.Branch = 0;
		control.ALUOp = 0;
		control.Jump = 0;
	}//lw
	else if (opcode == 43) {
		control.RegDst = 1;
		control.ALUSrc = 1;
		control.MemtoReg = 1;
		control.RegWrite = 0;
		control.MemRead = 0;
		control.MemWrite = 1;
		control.Branch = 0;
		control.ALUOp = 0;
		control.Jump = 0;
	}//sw
	else if (opcode == 4) {
		control.RegDst = 0;
		control.ALUSrc = 0;
		control.MemtoReg = 1;
		control.RegWrite = 0;
		control.MemRead = 0;
		control.MemWrite = 0;
		control.Branch = 1;
		control.ALUOp = 1;
		control.Jump = 0;
	}//beq
	else if (opcode == 2) {
		control.RegDst = 0;
		control.ALUSrc = 0;
		control.MemtoReg = 0;
		control.RegWrite = 0;
		control.MemRead = 0;
		control.MemWrite = 0;
		control.Branch = 0;
		control.ALUOp = 0;
		control.Jump = 1;
	}//jump
};

unsigned char ALU_Control_Signal(unsigned char signal)
{
	if (control.ALUOp == 0) {
		return 2;//add
	}
	else if (control.ALUOp == 1) {
		return 6;//subtract
	}
	else if (control.ALUOp == 2) {
		switch (signal) {
		case 32:return 2;//add
		case 34:return 6;//subtract
		case 36:return 0;//and
		case 37:return 1;//or
		case 42:return 7;//slt
		}
	}
}

void ALU_func(unsigned char ALU_control, unsigned int a, unsigned int b)
{
	if (ALU_control == 0) {
		alu.ALU_result = a&b;
	}
	else if (ALU_control == 1) {
		alu.ALU_result = a | b;
	}
	else if (ALU_control == 2) {
		alu.ALU_result = a + b;
	}
	else if (ALU_control == 6) {
		alu.ALU_result = a - b;
	}
	else if (ALU_control == 7) {
		alu.ALU_result = a < b;
	}
	alu.zero = !alu.ALU_result;
}

unsigned int Memory_Access(unsigned char MemWrite, unsigned char MemRead, unsigned int addr, unsigned int write_data)
{
	if (MemWrite) {
		mem[addr] = write_data;
	}
	else if (MemRead) {
		return mem[addr];
	}
	return 0;
}

void Register_Write(unsigned char RegWrite, unsigned int Write_reg, unsigned int Write_data)
{
	//write data의 값.......
	//regwrite는 컨트롤시그널이고 write_reg는 주소
	//컨트롤시그널이면 
	if (RegWrite) {
		//registerwrite를 부를때 write_reg에 mux반환값을 넣어야됨
		//write data에서도 mux반환값이 들어가야됨
		reg[Write_reg] = Write_data;
	}
}//data를쓸때 memtoReg 1이면 이거를 register에서 써줌regwrite 그러면 write_data에 부를때 control.memtoReg를 넣어줌


unsigned int Sign_Extend(unsigned int inst_16)
{
	unsigned int inst_32 = 0;
	if ((inst_16 & 0x00008000)) // minus
	{
		inst_32 = inst_16 | 0xffff0000;
	}
	else // plus
	{
		inst_32 = inst_16;
	}

	return inst_32;
}

unsigned int Shift_Left_2(unsigned int inst)
{
	return inst << 2;
}

unsigned int Mux(char signal, unsigned int a_0, unsigned int b_1)
{
	if (signal == 0) {
		return a_0;
	}
	else if (signal == 1) {
		return b_1;
	}

}//부를때 signal에 그 제어하는거 종류 변수 넣어서 불러줌!! 그래서 그중에서 1이면 위에꺼 아니면 아래꺼
 //반환 해줌

unsigned int Add(unsigned int a, unsigned int b)
{
	return a + b;
}

void print_reg_mem(void)
{
	int reg_index = 0;
	int mem_index = 0;

	printf("\n===================== REGISTER =====================\n");

	for (reg_index = 0; reg_index < 8; reg_index++)
	{
		printf("reg[%02d] = %08d        reg[%02d] = %08d        reg[%02d] = %08d        reg[%02d] = %08d \n",
			reg_index, reg[reg_index], reg_index + 8, reg[reg_index + 8], reg_index + 16, reg[reg_index + 16], reg_index + 24, reg[reg_index + 24]);
	}

	printf("===================== REGISTER =====================\n");

	printf("\n===================== MEMORY =====================\n");

	for (mem_index = 0; mem_index < 32; mem_index = mem_index + 4)
	{
		printf("mem[%02d] = %012d        mem[%02d] = %012d \n",
			mem_index, mem[mem_index], mem_index + 32, mem[mem_index + 32]);
	}
	printf("===================== MEMORY =====================\n");
}
