// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_configs.v
//	* Date			: 2024-07-18 17:33:21
//	* Description	:
// ==================================================


// --------------------------------------------------
//	RISC-V Integer Bit & Memory Specification
// --------------------------------------------------
`define	XLEN				32
`define	DMEM_ADDR_BIT		8
`define	IMEM_ADDR_BIT		8

`define	DMEM_INIT
`define	DMEM_INIT_FILE		"riscv_dmem.mif"
`define	IMEM_INIT
`define	IMEM_INIT_FILE		"riscv_imem.mif"

// --------------------------------------------------
//	ALU (Arithmetic & Logical Unit)
// --------------------------------------------------
//							{funct7[5], funct3}
`define	ALU_CTRL_ADD		4'b0000
`define	ALU_CTRL_SUB		4'b1000
`define	ALU_CTRL_XOR		4'b0100
`define	ALU_CTRL_OR			4'b0110
`define	ALU_CTRL_AND		4'b0111
`define	ALU_CTRL_SLL		4'b0001	// Shift Left Logical
`define	ALU_CTRL_SRL		4'b0101	// Shift Right Logical / Arithmetic
`define	ALU_CTRL_SRA		4'b1101	// Shift Right Logical / Arithmetic
`define	ALU_CTRL_SLT		4'b0010	// Set on Less Than
`define	ALU_CTRL_SLTU		4'b0011	// Set on Less Than Unsigned

// --------------------------------------------------
// Instruction opcodes
// --------------------------------------------------
`define	OPCODE_R_OP			7'b0110011	//	R-Type, x[rd] = x[rd] = x[rs1] 'op' x[rs2]
`define	OPCODE_I_OP			7'b0010011	//	I-Type, x[rd] = x[rs1] 'op' sext(imm)
`define	OPCODE_I_LOAD		7'b0000011	//	I-Type, x[rd] = sext(M[x[rs1] + sext(offset)][31:0])
`define	OPCODE_S_STORE		7'b0100011	//	S-Type, M[x[rs1] + sext(offset)] = x[rs2][31:0]
`define	OPCODE_B_BRANCH		7'b1100011	//	B-Type, if (rs1 'op' rs2) pc += sext(offset)
`define	OPCODE_J_JAL		7'b1101111	//	J-Type, x[rd] = pc + 4; pc += sext(offset)
`define	OPCODE_I_JALR		7'b1100111	//	J-Type, x[rd] = pc + 4; pc = (x[rs1] + sext(offset)) & ~1
`define	OPCODE_U_LUI		7'b0110111	//	U-Type, x[rd] = sext(imm[31:12] << 12)
`define	OPCODE_U_AUIPC		7'b0010111	//	U-Type, x[rd] = pc + sext(imm[31:12] << 12)
//`define	OPCODE_I_FENCE		7'b0001111	//	I-Type, 
//`define	OPCODE_I_SYSTEM		7'b1110011	//	I-Type, 

// --------------------------------------------------
//	Source Immidiate
// --------------------------------------------------
`define	SRC_IMM_R			3'b000
`define	SRC_IMM_I			3'b001
`define	SRC_IMM_S			3'b010
`define	SRC_IMM_B			3'b011
`define	SRC_IMM_J			3'b100
`define	SRC_IMM_U			3'b101
`define	SRC_IMM_X			3'b111

// --------------------------------------------------
//	Source (Next)PC 
// --------------------------------------------------
`define	SRC_PC_PC_4			2'b00
`define	SRC_PC_PC_IMM		2'b01
`define	SRC_PC_RS_IMM		2'b10

// --------------------------------------------------
// Source RD (Register File Write Data)
// --------------------------------------------------
`define	SRC_RD_ALU   		2'b00
`define	SRC_RD_DME   		2'b01
`define	SRC_RD_PC4			2'b10
`define	SRC_RD_IMM			2'b11

// --------------------------------------------------
// source alu
// --------------------------------------------------
`define	SRC_ALU_A_RS1   	1'b0
`define	SRC_ALU_A_PC   		1'b1
`define	SRC_ALU_B_RS2		1'b0
`define	SRC_ALU_B_IMM		1'b1

// --------------------------------------------------
// Funct3 for Branch
// --------------------------------------------------
`define FUNCT3_BRANCH_BEQ	3'b000
`define FUNCT3_BRANCH_BNE	3'b001
`define FUNCT3_BRANCH_BLT	3'b100
`define FUNCT3_BRANCH_BGE	3'b101
`define FUNCT3_BRANCH_BLTU	3'b110
`define FUNCT3_BRANCH_BGEU	3'b111

// --------------------------------------------------
// Funct3 for ALU
// --------------------------------------------------
`define	FUNCT3_ALU_ADD_SUB	3'b000
`define	FUNCT3_ALU_XOR		3'b100
`define	FUNCT3_ALU_OR		3'b110
`define	FUNCT3_ALU_AND		3'b111
`define	FUNCT3_ALU_SLL		3'b001
`define	FUNCT3_ALU_SRL_SRA	3'b101
`define	FUNCT3_ALU_SLT		3'b010
`define	FUNCT3_ALU_SLTU		3'b011
