

// --------------------------------------------------
//	RISC-V Global parm
// --------------------------------------------------
parameter	XLEN	=	32,

// --------------------------------------------------
//	MEM parm
// --------------------------------------------------
parameter	DMEM_ADDR_BIT	=	16,
parameter	IMEM_ADDR_BIT	=	16,


// --------------------------------------------------
//	ALU parm
// --------------------------------------------------
parameter	ALU_CTRL_ADD	=	4'b0000,
parameter	ALU_CTRL_SUB	=	4'b0001,
parameter	ALU_CTRL_XOR	=	4'b0010,
parameter	ALU_CTRL_OR		=	4'b0011,
parameter	ALU_CTRL_AND	=	4'b0100,
parameter	ALU_CTRL_SLL	=	4'b0101,
parameter	ALU_CTRL_SRL	=	4'b0110,
parameter	ALU_CTRL_SRA	=	4'b0111,
parameter	ALU_CTRL_SLT	=	4'b1000,
parameter	ALU_CTRL_SLTU	=	4'b1001,
parameter	ALU_CTRL_NOP	=	4'b1111,

// --------------------------------------------------
// Instruction opcodes
// --------------------------------------------------
parameter	OPCODE_R_OP		=	7'b0110011,	//	R-Type, x[rd] = x[rd] = x[rs1] 'op' x[rs2]
parameter	OPCODE_I_OP		=	7'b0010011,	//	I-Type, x[rd] = x[rs1] 'op' sext(imm)
parameter	OPCODE_I_LOAD	=	7'b0000011,	//	I-Type, x[rd] = sext(M[x[rs1] + sext(offset)][31:0])
parameter	OPCODE_S_STORE	=	7'b0100011,	//	S-Type, M[x[rs1] + sext(offset)] = x[rs2][31:0]
parameter	OPCODE_B_BRANCH	=	7'b1100011,	//	B-Type, if (rs1 'op' rs2) pc += sext(offset)
parameter	OPCODE_J_JAL	=	7'b1101111,	//	J-Type, x[rd] = pc + 4; pc += sext(offset)
parameter	OPCODE_I_JALR	=	7'b1100111,	//	J-Type, x[rd] = pc + 4; pc = (x[rs1] + sext(offset)) & ~1
parameter	OPCODE_U_LUI	=	7'b0110111,	//	U-Type, x[rd] = sext(imm[31:12] << 12)
parameter	OPCODE_U_AUIPC	=	7'b0010111,	//	U-Type, x[rd] = pc + sext(imm[31:12] << 12)

// --------------------------------------------------
//	Source Immediate
// --------------------------------------------------
parameter	SRC_IMM_R		=	3'b000,
parameter	SRC_IMM_I		=	3'b001,
parameter	SRC_IMM_S		=	3'b010,
parameter	SRC_IMM_B		=	3'b011,
parameter	SRC_IMM_J		=	3'b100,
parameter	SRC_IMM_U		=	3'b101,
parameter	SRC_IMM_X		=	3'b111,


// --------------------------------------------------
//	Source (Next)PC 
// --------------------------------------------------
parameter	SRC_PC_PC_4		=	2'b00,
parameter	SRC_PC_PC_IMM	=	2'b01,
parameter	SRC_PC_RS_IMM	=	2'b10,

// --------------------------------------------------
// Source RD (Register File Write Data)
// --------------------------------------------------
parameter	SRC_RD_ALU   	=	2'b00,
parameter	SRC_RD_DME   	=	2'b01,
parameter	SRC_RD_PC4		=	2'b10,
parameter	SRC_RD_IMM		=	2'b11,

// --------------------------------------------------
// source alu
// --------------------------------------------------
parameter	SRC_ALU_A_RS1   =	1'b0,
parameter	SRC_ALU_A_PC   	=	1'b1,
parameter	SRC_ALU_B_RS2	=	1'b0,
parameter	SRC_ALU_B_IMM	=	1'b1,

// --------------------------------------------------
// Funct3 for ALU
// --------------------------------------------------
parameter	FUNCT3_ALU_ADD_SUB	=	3'b000,
parameter	FUNCT3_ALU_XOR		=	3'b100,
parameter	FUNCT3_ALU_OR		=	3'b110,
parameter	FUNCT3_ALU_AND		=	3'b111,
parameter	FUNCT3_ALU_SLL		=	3'b001,
parameter	FUNCT3_ALU_SRL_SRA	=	3'b101,
parameter	FUNCT3_ALU_SLT		=	3'b010,
parameter	FUNCT3_ALU_SLTU		=	3'b011,

// --------------------------------------------------
// Funct3 for Branch
// --------------------------------------------------
parameter 	FUNCT3_BRANCH_BEQ	=	3'b000,
parameter 	FUNCT3_BRANCH_BNE	=	3'b001,
parameter 	FUNCT3_BRANCH_BLT	=	3'b100,
parameter 	FUNCT3_BRANCH_BGE	=	3'b101,
parameter 	FUNCT3_BRANCH_BLTU	=	3'b110,
parameter 	FUNCT3_BRANCH_BGEU	=	3'b111,

// --------------------------------------------------
// Funct3 for LOAD/STORE
// --------------------------------------------------
parameter	FUNCT3_MEM_BYTE		=	3'b000,
parameter	FUNCT3_MEM_HALF		=	3'b001,
parameter	FUNCT3_MEM_WORD		=	3'b010,
parameter	FUNCT3_MEM_BYTEU	=	3'b100,
parameter	FUNCT3_MEM_HALFU	=	3'b101
