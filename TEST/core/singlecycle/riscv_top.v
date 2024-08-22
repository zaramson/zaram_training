


`include	"../common/riscv_21mux.v         "
`include	"../common/riscv_31mux.v         "
`include	"../common/riscv_41mux.v         "
`include	"../common/riscv_adder.v         "
`include	"../common/riscv_alu.v           "
`include	"../common/riscv_configs.v       "
`include	"../common/riscv_ctrl.v          "
`include	"../common/riscv_dmem.v          "
`include	"../common/riscv_dmem_interface.v"
`include	"../common/riscv_imem.v          "
`include	"../common/riscv_immext.v        "
`include	"../common/riscv_regfile.v       "
`include	"../common/riscv_register.v      "



module riscv_top
#(
	`include "../common/riscv_param.v"
)
(	
	input						i_clk,
	input						i_rstn
);


	// mux_pc
	wire	[XLEN-1:0]	mux31_pc_out;

	// PC register
	wire	[XLEN-1:0]	reg_pc_out;

	// Instruction Memory
	wire	[XLEN-1:0]	imem_instr;


	// PC+4 Adder
	wire	[XLEN-1:0]	adder_pc_plus_4;

	// Control
	wire	[2:0]			ctrl_src_imm;
	wire	[1:0]			ctrl_src_mux41;
	wire					ctrl_src_mux21_a;
	wire					ctrl_src_mux21_b;
	wire					ctrl_reg_wr_en;
	wire					ctrl_mem_wr_en;
	wire	[3:0]			ctrl_mem_byte_sel;
	wire	[3:0]			ctrl_alu_ctrl;


	// Register File
	wire	[XLEN-1:0]		regfile_rs1_out;
	wire	[XLEN-1:0]		regfile_rs2_out;


	// Immediate Decode
	wire	[XLEN-1:0]		immext_out;


	// mux21_a
	wire	[XLEN-1:0] 		mux21_a_out;

	// mux21_b
	wire	[XLEN-1:0] 		mux21_b_out;


	// PC+IMM Adder
	wire	[XLEN-1:0]		adder_pc_plus_imm;


	// ALU
	wire	[XLEN-1:0]		alu_out;
	wire					alu_zero;
	

	// Data Memory
	wire	[XLEN-1:0]		dmem_rd_data;


	// mux41
	wire	[XLEN-1:0] 		mux41_out;
	
//TODO
	reg							take_branch;
	reg		[2-1:0]				src_pc;

	always @(*) begin
		if (imem_instr[6:0] == OPCODE_B_BRANCH) begin
			case (imem_instr[14:12])
				FUNCT3_BRANCH_BEQ	: take_branch =  alu_zero;
				FUNCT3_BRANCH_BNE 	: take_branch = !alu_zero;
				FUNCT3_BRANCH_BLT 	: take_branch = !alu_zero;
				FUNCT3_BRANCH_BGE 	: take_branch =  alu_zero;
				FUNCT3_BRANCH_BLTU	: take_branch = !alu_zero;
				FUNCT3_BRANCH_BGEU	: take_branch =  alu_zero;
				default				: take_branch = 1'b0;
			endcase
		end else begin
			take_branch	= 1'b0;
		end
	end

	always @(*) begin
		case (imem_instr[6:0])
			OPCODE_B_BRANCH		: src_pc	= (take_branch) ? SRC_PC_PC_IMM: SRC_PC_PC_4;
			OPCODE_J_JAL		: src_pc	= SRC_PC_PC_IMM;
			OPCODE_I_JALR		: src_pc	= SRC_PC_RS_IMM;
			default				: src_pc	= SRC_PC_PC_4;
		endcase
	end

	riscv_mux31
	u_riscv_mux31_pc(
	.o_mux31_out			(mux31_pc_out		),
	.i_mux31_a				(adder_pc_plus_4	),
	.i_mux31_b				(adder_pc_plus_imm	),
	.i_mux31_c				(mux41_out			),
	.i_mux31_sel			(src_pc				)
	);


	riscv_register
	u_riscv_register_pc(
		.o_register_out		(reg_pc_out			),
		.i_register_in		(mux_pc_out			),
		.i_register_clk		(i_clk				),
		.i_register_en		(1'b1				),
		.i_register_rstn	(i_rstn				),
	);


	riscv_imem
	u_riscv_imem(
		.o_imem_data		(imem_instr						),
		.i_imem_addr		(reg_pc_out[IMEM_ADDR_BIT-1:2]	)
	);


	riscv_adder
	u_riscv_adder_pc_plus_4(
		.o_adder_sum		(adder_pc_plus_4	),
		.i_adder_a			(reg_pc_out			),
		.i_adder_b			(32'd4				)
	);


	riscv_ctrl
	u_riscv_ctrl(
		.o_ctrl_src_imm			(ctrl_src_imm		),
		.o_ctrl_src_mux41		(ctrl_src_mux41   	),
		.o_ctrl_src_mux21_a		(ctrl_src_mux21_a	),
		.o_ctrl_src_mux21_b		(ctrl_src_mux21_b	),
		.o_ctrl_reg_wr_en		(ctrl_reg_wr_en		),
		.o_ctrl_mem_wr_en		(ctrl_mem_wr_en		),
		.o_ctrl_mem_byte_sel	(ctrl_mem_byte_sel	),
		.o_ctrl_alu_ctrl		(ctrl_alu_ctrl		),
		.i_ctrl_alu_zero		(alu_zero			),
		.i_ctrl_opcode			(imem_instr[6:0]	),
		.i_ctrl_funct3			(imem_instr[14:12]	),
		.i_ctrl_funct7_5b		(imem_instr[30]		)
	);


	riscv_regfile
	u_riscv_regfile(
		.o_regfile_rs1_out	(regfile_rs1_out	),
		.o_regfile_rs2_out	(regfile_rs2_out	),
		.i_regfile_rs1_addr	(imem_instr[19:15]	),
		.i_regfile_rs2_addr	(imem_instr[24:20]	),
		.i_regfile_wr_addr	(imem_instr[11: 7]	),
		.i_regfile_wr_data	(mux41_out			),
		.i_regfile_wen		(ctrl_reg_wr_en		),
		.i_regfile_clk		(i_clk				)
	);


	riscv_immext
	u_riscv_immext(
		.o_imm_ext			(immediate			),
		.i_imm_instr		(i_dp_instr			),
		.i_imm_src			(i_dp_src_imm		)
	);

