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

struct IF_ID {
	unsigned int inst;
	unsigned int pcAdd4;
	int inst_cycle;
};

struct ID_EX {
	unsigned int inst;
	unsigned int inst_15_0;
	unsigned int inst_20_16;
	unsigned int inst_15_11;
	unsigned int readData1;
	unsigned int readData2;
	unsigned int pcAdd4;
	unsigned int RegDst;
	unsigned int ALUSrc;
	unsigned int MemtoReg;
	unsigned int RegWrite;
	unsigned int MemRead;
	unsigned int MemWrite;
	unsigned int Branch;
	unsigned int ALUOp;
	unsigned int Jump;
	int inst_cycle;
};

struct EX_MEM {
	unsigned int inst;
	unsigned char zero;
	unsigned int ALUResult;
	unsigned int AddResult;
	unsigned int dest;
	unsigned int wData;//데이터메모리에 쓸 데이터
	unsigned int MemtoReg;
	unsigned int MemRead;
	unsigned int MemWrite;
	unsigned int RegWrite;
	unsigned int Branch;
	int inst_cycle;
};

struct MEM_WB {
	unsigned int inst;
	unsigned int dest;
	unsigned int rData;
	unsigned int ALUResult;//MUX로 들어가는 데이터 두개 중 하나임
	unsigned int RegWrite;
	unsigned int MemtoReg;
	int inst_cycle;
};

struct Control control;
struct Reg_Read reg_read;
struct ALU alu;
struct IF_ID if_id;
struct ID_EX id_ex;
struct EX_MEM ex_mem;
struct MEM_WB mem_wb;
unsigned int mem[64] = { 0 };
unsigned int reg[32] = { 0 };

/**************************************/

void init();
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
void mem_wb_control();
void ex_mem_control();

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
	int cnt;

	// register initialization
	/**************************************/
	reg[8] = 41621;
	reg[9] = 41621;
	reg[16] = 40;
	/**************************************/

	// memory initialization
	/**************************************/
	mem[40] = 3578;

	if (!(fp = fopen("input_6.txt", "r")))
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

	/**************************************/
	init();
	/**************************************/

	print_reg_mem();

	printf("\n ***** Processor START !!! ***** \n");

	pc = 0;
	cnt = 0;

	while (true) {

		pc = Mux(id_ex.Jump, Mux((ex_mem.Branch&ex_mem.zero), pc_add_4, ex_mem.AddResult), pc_add_inst);

		if ((id_ex.inst_cycle <= 0) && (ex_mem.inst_cycle <= 0) && (mem_wb.inst_cycle <= 0) && (total_cycle>1)) {
			break;
		}
		//wb
		// register write
		Register_Write(mem_wb.RegWrite, mem_wb.dest,
			Mux(mem_wb.MemtoReg, mem_wb.ALUResult,
				mem_wb.rData));
		
		//mem
		// memory access
		mem_wb_control();
		mem_wb.ALUResult = ex_mem.ALUResult;
		mem_wb.dest = ex_mem.dest;
		mem_wb.inst_cycle = ex_mem.inst_cycle-1;
		mem_wb.inst = ex_mem.inst;

		Memory_Access(ex_mem.MemWrite, ex_mem.MemRead, ex_mem.ALUResult, ex_mem.wData);

		//ex
		// create ALU control signal
		ALU_control = ALU_Control_Signal((id_ex.inst_15_0 << 26) >> 26);
		// ALU
		ALU_func(ALU_control, id_ex.readData1 , Mux(id_ex.ALUSrc, id_ex.readData2, id_ex.inst_15_0));
		ex_mem.AddResult = Add(id_ex.pcAdd4, Shift_Left_2(id_ex.inst_15_0));
		//ex_mem control
		ex_mem_control();
		ex_mem.ALUResult = alu.ALU_result;
		ex_mem.zero = alu.zero;
		ex_mem.wData = id_ex.readData2;
		ex_mem.dest = Mux(id_ex.RegDst, id_ex.inst_20_16, id_ex.inst_15_11);
		ex_mem.inst_cycle = id_ex.inst_cycle-1;
		ex_mem.inst = id_ex.inst;

		//id
		// instruction decode

		inst_31_26 = if_id.inst >> 26;
		inst_25_21 = (if_id.inst & 0x03e00000) >> 21;
		id_ex.inst_20_16 = (if_id.inst & 0x001f0000) >> 16;
		id_ex.inst_15_11 = (if_id.inst & 0x0000f800) >> 11;
		id_ex.inst_15_0 = Sign_Extend(if_id.inst & 0x0000ffff);
		inst_25_0 = if_id.inst & 0x03ffffff;
		inst_5_0 = (if_id.inst << 26) >> 26;
		//printf("%x, %x, %x, %x, %x, %x", inst_31_26, inst_25_21, inst_20_16, inst_15_11, inst_15_0, inst_25_0);
		pc_add_inst = ((pc_add_4 >> 28) << 28) + Shift_Left_2(inst_25_0);
		// register read
		Register_Read(inst_25_21, id_ex.inst_20_16);
		

		id_ex.pcAdd4 = if_id.pcAdd4;
		id_ex.inst = if_id.inst;
		id_ex.inst_cycle = if_id.inst_cycle;

		// create control signal
		Control_Signal(inst_31_26);
		if (if_id.inst == 0) {
			id_ex.inst_cycle = 0;
		}

		//if
		// pc +4
		if_id.pcAdd4 = pc_add_4 = Add(pc, 4);
		// instruction fetch
		if_id.inst = inst = Inst_Fetch(pc);
		if_id.inst_cycle = 0;
		printf("Instruction = %08x \n", inst);

		total_cycle++;
		
		// result
		/********************************/
		printf("PC : %d \n", pc);
		printf("Total cycle : %d \n", total_cycle);

		printf("=== ID/EX === %x\n", id_ex.inst);
		printf("WB - RegWrite: %d, MemtoReg: %d\n", id_ex.RegWrite, id_ex.MemtoReg);
		printf("M  - Branch  : %d, MemRead : %d, MemWrite: %d \n", id_ex.Branch, id_ex.MemRead, id_ex.MemWrite);
		printf("EX - RegDst  : %d, ALUOp   : %d, ALUSrc  : %d \n", id_ex.RegDst, id_ex.ALUOp, id_ex.ALUSrc);
		printf("=== EX/MEM === %x\n", ex_mem.inst);
		printf("WB - RegWrite: %d, MemtoReg: %d\n", ex_mem.RegWrite, ex_mem.MemtoReg);
		printf("M  - Branch  : %d, MemRead : %d, MemWrite: %d \n", ex_mem.Branch, ex_mem.MemRead, ex_mem.MemWrite);
		printf("=== MEM/WB === %x\n", mem_wb.inst);
		printf("WB - RegWrite: %d, MemtoReg: %d \n", mem_wb.RegWrite, mem_wb.MemtoReg);

		print_reg_mem();
		/********************************/
		system("pause");
	}

	printf("\n ***** Processor END !!! ***** \n");

	return 0;
}

void init() {
	if_id.inst = 0;
	if_id.inst_cycle = 0;
	if_id.pcAdd4 = 0;
	id_ex.inst = 0;
	id_ex.inst_cycle = 0;
	id_ex.ALUOp = 0;
	id_ex.ALUSrc = 0;
	id_ex.Branch = 0;
	id_ex.inst_15_0 = 0;
	id_ex.inst_15_11 = 0;
	id_ex.inst_20_16 = 0;
	id_ex.Jump = 0;
	id_ex.MemRead = 0;
	id_ex.MemtoReg = 0;
	id_ex.MemWrite = 0;
	id_ex.pcAdd4 = 0;
	id_ex.readData1 = 0;
	id_ex.readData2 = 0;
	id_ex.RegDst = 0;
	id_ex.RegWrite = 0;
	ex_mem.inst = 0;
	ex_mem.inst_cycle = 0;
	ex_mem.AddResult = 0;
	ex_mem.ALUResult = 0;
	ex_mem.Branch = 0;
	ex_mem.MemRead = 0;
	ex_mem.MemtoReg = 0;
	ex_mem.MemWrite = 0;
	ex_mem.RegWrite = 0;
	ex_mem.wData = 0;
	ex_mem.zero = 0;
	mem_wb.inst = 0;
	mem_wb.inst_cycle = 0;
	mem_wb.ALUResult = 0;
	mem_wb.MemtoReg = 0;
	mem_wb.rData = 0;
	mem_wb.RegWrite = 0;
}

unsigned int Inst_Fetch(unsigned int read_addr)
{
	return mem[read_addr];
}

void Register_Read(unsigned int read_reg_1, unsigned int read_reg_2)
{
	id_ex.readData1 = reg[read_reg_1];
	id_ex.readData2 = reg[read_reg_2];
}//rd rt

void Control_Signal(unsigned int opcode)
{
	//opcode는 31~26
	if (opcode == 0) {
		id_ex.RegDst = 1;
		id_ex.ALUSrc = 0;
		id_ex.MemtoReg = 0;
		id_ex.RegWrite = 1;
		id_ex.MemRead = 0;
		id_ex.MemWrite = 0;
		id_ex.Branch = 0;
		id_ex.ALUOp = 2;
		id_ex.Jump = 0;
		id_ex.inst_cycle = 3;
	}//R-format
	else if (opcode == 35) {
		id_ex.RegDst = 0;
		id_ex.ALUSrc = 1;
		id_ex.MemtoReg = 1;
		id_ex.RegWrite = 1;
		id_ex.MemRead = 1;
		id_ex.MemWrite = 0;
		id_ex.Branch = 0;
		id_ex.ALUOp = 0;
		id_ex.Jump = 0;
		id_ex.inst_cycle = 3;
	}//lw
	else if (opcode == 43) {
		id_ex.RegDst = 0;
		id_ex.ALUSrc = 1;
		id_ex.MemtoReg = 0;
		id_ex.RegWrite = 0;
		id_ex.MemRead = 0;
		id_ex.MemWrite = 1;
		id_ex.Branch = 0;
		id_ex.ALUOp = 0;
		id_ex.Jump = 0;
		id_ex.inst_cycle = 2;
	}//sw
	else if (opcode == 4) {
		id_ex.RegDst = 0;
		id_ex.ALUSrc = 0;
		id_ex.MemtoReg = 1;
		id_ex.RegWrite = 0;
		id_ex.MemRead = 0;
		id_ex.MemWrite = 0;
		id_ex.Branch = 1;
		id_ex.ALUOp = 1;
		id_ex.Jump = 0;
		id_ex.inst_cycle = 2;
	}//beq
	else if (opcode == 2) {
		id_ex.RegDst = 0;
		id_ex.ALUSrc = 0;
		id_ex.MemtoReg = 0;
		id_ex.RegWrite = 0;
		id_ex.MemRead = 0;
		id_ex.MemWrite = 0;
		id_ex.Branch = 0;
		id_ex.ALUOp = 0;
		id_ex.Jump = 1;
		id_ex.inst_cycle = 1;
	}//jump
};

void ex_mem_control() {
	ex_mem.Branch = id_ex.Branch;
	ex_mem.MemRead = id_ex.MemRead;
	ex_mem.MemtoReg = id_ex.MemtoReg;
	ex_mem.MemWrite = id_ex.MemWrite;
	ex_mem.RegWrite = id_ex.RegWrite;
	//ex_mem.inst_cycle = id_ex.inst_cycle - 1;
}

void mem_wb_control() {
	mem_wb.MemtoReg = ex_mem.MemtoReg;
	mem_wb.RegWrite = ex_mem.RegWrite;
	//mem_wb.inst_cycle = ex_mem.inst_cycle - 1;
}

unsigned char ALU_Control_Signal(unsigned char signal)
{
	if (id_ex.ALUOp == 0) {
		return 2;//add
	}
	else if (id_ex.ALUOp == 1) {
		return 6;//subtract
	}
	else if (id_ex.ALUOp == 2) {
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
		mem_wb.rData = mem[addr];
	}
	return 0;
}

void Register_Write(unsigned char RegWrite, unsigned int Write_reg, unsigned int Write_data)
{
	if (RegWrite) {
		reg[Write_reg] = Write_data;
	}
}

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

}

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
