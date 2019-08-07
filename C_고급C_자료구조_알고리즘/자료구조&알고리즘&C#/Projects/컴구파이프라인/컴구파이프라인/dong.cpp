#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/**************************************/

typedef unsigned char byte;
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

struct EX {
	unsigned char RegDst;
	unsigned char ALUOp;
	unsigned char ALUSrc;

};
struct MEM {
	unsigned char Branch;
	unsigned char MemRead;
	unsigned char MemWrite;

};
struct WB {
	unsigned char RegWrite;
	unsigned char MemtoReg;

};
struct MEMWB {
	struct WB wb;
	unsigned int addr;
	unsigned int read_data;
	unsigned int alu_result;
	unsigned int write_reg;
};
struct EXMEM {
	struct WB wb;
	struct MEM mem;
	unsigned int addr;
	unsigned int pc_add_inst;
	unsigned int alu_result;
	unsigned char zero;
	unsigned int write_reg;
	unsigned int write_data;
	unsigned int pc_add_4;
};
struct IDEX {
	struct EX ex;
	struct MEM mem;
	struct WB wb;
	unsigned int addr;
	unsigned int inst_ext_32;
	Reg_Read reg_read;
	unsigned int pc_add_4;
	unsigned int inst_20_16;
	unsigned int inst_15_11;
};
struct IFID {
	unsigned int addr;
	unsigned int pc_add_4;
};

struct Control control;
struct Reg_Read reg_read;
struct ALU alu;
IDEX idex;
EXMEM exmem;
MEMWB memwb;
IFID ifid;

unsigned int mem[64] = { 0 };
unsigned int reg[32] = { 0 };
unsigned int pipeLine[4] = { 0 };

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
bool processEndCase();

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
	unsigned char PCSrc;
	unsigned int inst_25_0 = 0;
	unsigned int jump_addr = 0;
	unsigned int mem_result = 0;
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

	if (!(fp = fopen("input_7.txt", "r")))
	{
		printf("error: file open fail !!\n");
		exit(1);
	}

	while (feof(fp) == false)
	{
		fscanf(fp, "%x", &inst);
		mem[pc] = inst;
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

	// Pipeline initialization
	/**************************************/
	ifid.addr = 0;
	ifid.pc_add_4 = 0;

	idex.addr = 0;
	idex.wb = { 0,0 };
	idex.mem = { 0,0,0 };
	idex.ex = { 0,0,0 };
	idex.inst_ext_32 = 0;
	idex.reg_read = { 0,0 };

	exmem.wb = { 0,0 };
	exmem.mem = { 0,0,0 };
	exmem.addr = 0;

	memwb.wb = { 0,0 };
	memwb.addr = 0;

	/**************************************/

	print_reg_mem();

	printf("\n ***** Processor START !!! ***** \n");

	pc = 0;
	while (true)
	{


		// 5. WB

		Register_Write(memwb.wb.RegWrite, memwb.write_reg, Mux(memwb.wb.MemtoReg, memwb.alu_result, memwb.read_data));

		// 4. MEM


		memwb.addr = exmem.addr;

		memwb.wb = exmem.wb;


		memwb.read_data = Memory_Access(exmem.mem.MemWrite, exmem.mem.MemRead, exmem.alu_result, exmem.write_data);
		memwb.alu_result = exmem.alu_result;
		memwb.write_reg = exmem.write_reg;

		// 3. EX
		exmem.addr = idex.addr;

		exmem.mem = idex.mem;
		exmem.wb = idex.wb;

		ALU_control = ALU_Control_Signal(idex.inst_ext_32 & 0x0000003f);
		inst_ext_shift = Shift_Left_2(idex.inst_ext_32);

		exmem.pc_add_inst = Add(idex.pc_add_4, inst_ext_shift);

		ALU_func(ALU_control, idex.reg_read.Read_data_1, Mux(idex.ex.ALUSrc, idex.reg_read.Read_data_2, idex.inst_ext_32));

		exmem.alu_result = alu.ALU_result;
		exmem.zero = alu.zero;

		exmem.write_reg = Mux(idex.ex.RegDst, idex.inst_20_16, idex.inst_15_11);

		exmem.write_data = idex.reg_read.Read_data_2;

		exmem.pc_add_4 = idex.pc_add_4;

		pc = Mux(control.Jump,
			Mux(exmem.mem.Branch & exmem.zero, pc_add_4, exmem.pc_add_inst),
			(Shift_Left_2(jump_addr)));
		// 2. ID
		idex.addr = ifid.addr;

		inst_31_26 = ifid.addr >> 26;
		inst_25_21 = (ifid.addr & 0x03e00000) >> 21;
		idex.inst_20_16 = inst_20_16 = (ifid.addr & 0x001f0000) >> 16;
		idex.inst_15_11 = inst_15_11 = (ifid.addr & 0x0000f800) >> 11;
		inst_15_0 = ifid.addr & 0x0000ffff;
		inst_25_0 = ifid.addr & 0x03ffffff;

		jump_addr = inst_25_0;

		Register_Read(inst_25_21, inst_20_16);
		idex.reg_read = reg_read;

		inst_ext_32 = Sign_Extend(inst_15_0);
		idex.inst_ext_32 = inst_ext_32;

		Control_Signal(inst_31_26);

		idex.pc_add_4 = ifid.pc_add_4;

		// 1. IF

		pc_add_4 = Add(pc, 4);
		ifid.pc_add_4 = pc_add_4;

		inst = Inst_Fetch(pc);
		printf("Instruction = %08x \n", inst);

		ifid.addr = inst;

		total_cycle++;
		// result
		/********************************/

		printf("=== ID/EX === ADDR: %08x\n", idex.addr);
		printf("WB - RegWrite: %d, MemtoReg: %d\n", idex.wb.RegWrite, idex.wb.MemtoReg);
		printf("M  - Branch  : %d, MemRead : %d, MemWrite: %d \n", idex.mem.Branch, idex.mem.MemRead, idex.mem.MemWrite);
		printf("EX - RegDst  : %d, ALUOp   : %d, ALUSrc  : %d \n", idex.ex.RegDst, idex.ex.ALUOp, idex.ex.ALUSrc);
		printf("=== EX/MEM === ADDR: %08x\n", exmem.addr);
		printf("WB - RegWrite: %d, MemtoReg: %d\n", exmem.wb.RegWrite, exmem.wb.MemtoReg);
		printf("M  - Branch  : %d, MemRead : %d, MemWrite: %d \n", exmem.mem.Branch, exmem.mem.MemRead, exmem.mem.MemWrite);
		printf("=== MEM/WB === ADDR: %08x\n", memwb.addr);
		printf("WB - RegWrite: %d, MemtoReg: %d \n", memwb.wb.RegWrite, memwb.wb.MemtoReg);

		printf("PC : %d \n", pc);
		printf("Total cycle : %d \n", total_cycle);

		print_reg_mem();
		/********************************/

		if (processEndCase()) break;
		system("pause");
	}

	printf("\n ***** Processor END !!! ***** \n");



	return 0;
}

bool processEndCase()
{
	bool result;

	bool ID_fin = !ifid.addr;
	bool EX_fin = !idex.addr || (!idex.wb.RegWrite && !(idex.mem.MemWrite || idex.mem.MemRead));
	bool M_fin = (!exmem.addr || (!(exmem.mem.MemWrite || exmem.mem.MemRead) && !exmem.wb.RegWrite));
	bool WB_fin = (!memwb.addr || !memwb.wb.RegWrite);

	result = ID_fin && EX_fin && M_fin && WB_fin;

	return result;

}
unsigned int Inst_Fetch(unsigned int read_addr)
{
	return mem[read_addr];
}

void Register_Read(unsigned int read_reg_1, unsigned int read_reg_2)
{
	reg_read.Read_data_1 = reg[read_reg_1];
	reg_read.Read_data_2 = reg[read_reg_2];
}

void Control_Signal(unsigned int opcode)
{
	byte op[6];
	if (opcode == 2) control.Jump = 1;
	else control.Jump = 0;
	for (int i = 0; i < 6; i++) {
		op[i] = opcode & 0x01;
		opcode >>= 1;
	}
	byte data[4];
	data[0] = !op[0] & !op[1] & !op[2] & !op[3] & !op[4] & !op[5];
	data[1] = op[0] & op[1] & !op[2] & !op[3] & !op[4] & op[5];
	data[2] = op[0] & op[1] & !op[2] & op[3] & !op[4] & op[5];
	data[3] = !op[0] & !op[1] & op[2] & !op[3] & !op[4] & !op[5];

	control.RegDst = data[0];
	control.ALUSrc = data[1] | data[2];
	control.MemtoReg = data[1];
	control.RegWrite = data[0] | data[1];
	control.MemRead = data[1];
	control.MemWrite = data[2];
	control.Branch = data[3];
	control.ALUOp = (data[0] << 1) + data[3];

	idex.ex.RegDst = control.RegDst;
	idex.ex.ALUSrc = control.ALUSrc;
	idex.ex.ALUOp = control.ALUOp;
	idex.mem.Branch = control.Branch;
	idex.mem.MemRead = control.MemRead;
	idex.mem.MemWrite = control.MemWrite;
	idex.wb.MemtoReg = control.MemtoReg;
	idex.wb.RegWrite = control.RegWrite;

}
unsigned char ALU_Control_Signal(unsigned char signal)
{
	byte operation = 0;
	byte ALUOp0, ALUOp1;
	byte F0, F1, F2, F3;

	F0 = signal & 0x01;
	F1 = signal & 0x02;
	F2 = signal & 0x04;
	F3 = signal & 0x08;

	ALUOp0 = idex.ex.ALUOp & 0x01;
	ALUOp1 = idex.ex.ALUOp & 0x02;

	operation += ALUOp1 & (F0 | F3);
	operation += ((!ALUOp1) | (!F2)) << 1;
	operation += (ALUOp0 | ALUOp1 & F1) << 2;

	return operation;
}

void ALU_func(unsigned char ALU_control, unsigned int a, unsigned int b)
{
	alu.zero = 0;
	switch (ALU_control) {
	case 0x00:
		alu.ALU_result = a & b;
		break;
	case 0x01:
		alu.ALU_result = a | b;
		break;
	case 0x02:
		alu.ALU_result = a + b;
		break;
	case 0x06:
		alu.ALU_result = a - b;
		if (alu.ALU_result == 0)
			alu.zero = 1;
		break;

	}
}

unsigned int Memory_Access(unsigned char MemWrite, unsigned char MemRead, unsigned int addr, unsigned int write_data)
{
	if (MemWrite) {
		mem[addr] = write_data;
	}
	else if (MemRead) {
		return mem[addr];
	}
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
	return signal ? b_1 : a_0;
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
