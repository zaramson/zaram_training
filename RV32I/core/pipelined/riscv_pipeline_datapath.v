// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_pipeline_datapath.v
//	* Date			: 2024-08-08 17:45:32
//	* Description	:
// ==================================================


`ifndef		NOINC
`include	"../common/riscv_configs.v"
`include	"../common/riscv_adder.v"
`include	"../common/riscv_alu.v"
`include	"../common/riscv_immext.v"
`include	"../common/riscv_mux.v"
`include	"../common/riscv_regfile.v"
`include	"../common/riscv_register.v"

`include	"./riscv_fd_register.v"
`include	"./riscv_de_register.v"
`include	"./riscv_em_register.v"
`include	"./riscv_mw_register.v"
`include	"./riscv_hazard_unit.v"
`endif

module riscv_pipeline_datapath
#(
	parameter	REGISTER_INIT	= 0
)
(	
	output		[`XLEN-1:0]		o_dp_pc,
	output						o_dp_alu_zero,
	output		[`XLEN-1:0]		o_dp_mem_addr,
	output		[`XLEN-1:0]		o_dp_mem_wr_data,
	output						o_dp_mem_wr_en,
	output		[3:0]			o_dp_mem_byte_sel,
	output		[2:0]			o_dp_mem_func3,
	output		[`XLEN-1:0]		o_dp_instr_d, //for conect ctrl
	input		[`XLEN-1:0]		i_dp_mem_rd_data,
	input		[`XLEN-1:0]		i_dp_instr,
	input		[2:0]			i_dp_src_imm,
	input		[1:0]			i_dp_src_pc,
	input		[1:0]			i_dp_src_rd,
	input						i_dp_src_alu_a,
	input						i_dp_src_alu_b,
	input						i_dp_reg_wr_en,
	input						i_dp_mem_wr_en,
	input		[3:0]			i_dp_mem_byte_sel,
	input		[3:0]			i_dp_alu_ctrl,
	input						i_clk,
	input						i_rstn
);

	//	PC Register
	wire		[`XLEN-1:0]		pc_next;
	wire		[`XLEN-1:0]		pc_plus_4;
	wire		[`XLEN-1:0]		pc_plus_imm;

	//	Register File
	wire		[`XLEN-1:0]		regfile_rs1_data;
	wire		[`XLEN-1:0]		regfile_rs2_data;
	wire		[`XLEN-1:0]		regfile_rd_data;

	//	Immediate
	wire		[`XLEN-1:0]		immediate;

	//	ALU
	wire		[`XLEN-1:0]		alu_a;
	wire		[`XLEN-1:0]		alu_b;
	wire		[`XLEN-1:0]		alu_result;


	//	MUX Concat
	wire		[(3*`XLEN)-1:0]	mux_concat_pc;
	wire		[(4*`XLEN)-1:0]	mux_concat_rd;
	wire		[(2*`XLEN)-1:0]	mux_concat_alu_a;
	wire		[(2*`XLEN)-1:0]	mux_concat_alu_b;

	assign	mux_concat_pc			= {alu_result,		pc_plus_imm,		pc_plus_4                      	} ;
	assign	mux_concat_rd			= {imm_ext_w,		pcplus4_w,			rd_data_w,	alu_result_w 		} ;

	assign	mux_concat_forward_ae	= {alu_result_m,	regfile_rd_data,	rs1_data_e                      } ;
	assign	mux_concat_forward_be	= {alu_result_m,	regfile_rd_data,	rs2_data_e                      } ;


	wire		[`XLEN-1:0]		forward_ae_result;
	wire		[`XLEN-1:0]		forward_be_result;

	assign	mux_concat_alu_a		= {pc_e,			forward_ae_result                                   } ;
	assign	mux_concat_alu_b		= {imm_ext_e,		forward_be_result                                   } ;

	// F/D Register
	wire		[`XLEN-1:0]		instr_d;
	wire		[`XLEN-1:0]		pc_d;
	wire		[`XLEN-1:0]		pcplus4_d;

	assign 	o_dp_instr_d		= instr_d;

	// D/E Register
	wire		[1:0]			src_pc_e;
	wire		[2:0]			src_imm_e;
	wire		[1:0]			src_rd_e;
	wire						src_alu_a_e;
	wire						src_alu_b_e;
	wire						reg_wr_en_e;
	wire						mem_wr_en_e;
	wire		[3:0]			mem_byte_sel_e;
	wire		[3:0]			alu_ctrl_e;
	wire		[`XLEN-1:0]		rs1_data_e;
	wire		[`XLEN-1:0]		rs2_data_e;
	wire		[`XLEN-1:0]		pc_e;
	wire		[	   4:0]		rs1_addr_e;
	wire		[	   4:0]		rs2_addr_e;
	wire		[	   4:0]		rd_addr_e;
	wire		[	   2:0]		func3_e;
	wire		[`XLEN-1:0]		imm_ext_e;
	wire		[`XLEN-1:0]		pcplus4_e;


	// E/M Register
	wire		[1:0]			src_rd_m;
	wire						reg_wr_en_m;
	wire						mem_wr_en_m;
	wire		[3:0]			mem_byte_sel_m;
	wire		[`XLEN-1:0]		alu_result_m;
	wire		[`XLEN-1:0]		write_data_m;
	wire		[      4:0]		rd_addr_m;
	wire		[      2:0]		func3_m;
	wire		[`XLEN-1:0]		pcplus4_m;
	wire		[`XLEN-1:0]		imm_ext_m;


	assign	o_dp_mem_wr_en		= mem_wr_en_m;
	assign	o_dp_mem_byte_sel	= mem_byte_sel_m;
	assign	o_dp_mem_addr		= alu_result_m;
	assign	o_dp_mem_wr_data	= write_data_m;
	assign	o_dp_mem_func3		= func3_m;


	// M/W Register
	wire		[1:0]			src_rd_w;
	wire						reg_wr_en_w;
	wire		[`XLEN-1:0]		alu_result_w;
	wire		[`XLEN-1:0]		rd_data_w;
	wire		[	   4:0]		rd_addr_w;
	wire		[`XLEN-1:0]		pcplus4_w;
	wire		[`XLEN-1:0]		imm_ext_w;


	//  Hazard Unit
	wire	stall_f;
	wire	stall_d;
	wire	flush_d;
	wire	flush_e;
	wire	forward_ae;
	wire	forward_be;


	riscv_mux
	#(
		.N_MUX_IN			(3					)
	)
	u_riscv_mux_pc(
		.o_mux_data			(pc_next			),
		.i_mux_concat_data	(mux_concat_pc		),
		.i_mux_sel			(src_pc_e			)
	);

	riscv_register
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_register_pc(
		.o_register_q		(o_dp_pc			),
		.i_register_d		(pc_next			),
		.i_register_en		(1'b1				),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
	);


	riscv_fd_register
	#(
		.REGISTER_INIT		(REGISTER_INIT			)
	)
	u_riscv_fd_register(
	.o_fd_register_instr	(instr_d		),
	.o_fd_register_pc		(pc_d			),
	.o_fd_register_pcplus4	(pcplus4_d		),
	.i_fd_register_instr	(i_dp_instr		),
	.i_fd_register_pc		(o_dp_pc		),
	.i_fd_register_pcplus4	(pc_plus_4		),
	.i_fd_register_en		(stall_f		),
	.i_clk					(i_clk			),
	.i_rstn					(flush_d		)
	);


	riscv_regfile
	u_riscv_regfile(
		.o_regfile_rs1_data	(regfile_rs1_data	),
		.o_regfile_rs2_data	(regfile_rs2_data	),
		.i_regfile_rs1_addr	(instr_d[19:15]	),
		.i_regfile_rs2_addr	(instr_d[24:20]	),
		.i_regfile_rd_data	(regfile_rd_data	), 
		.i_regfile_rd_addr	(instr_d[11: 7]	),
		.i_regfile_rd_wen	(reg_wr_en_w		), 
		.i_clk				(i_clk				)
	);

	riscv_immext
	u_riscv_immext(
		.o_imm_ext			(immediate			),
		.i_imm_instr		(instr_d			),
		.i_imm_src			(i_dp_src_imm		)
	);

	riscv_adder
	u_riscv_adder_pc_plus_4(
		.o_adder_sum		(pc_plus_4			),
		.i_adder_a			(o_dp_pc			),
		.i_adder_b			(32'd4				)
	);

	riscv_adder
	u_riscv_adder_pc_plus_imm(
		.o_adder_sum		(pc_plus_imm		),
		.i_adder_a			(pc_e			),
		.i_adder_b			(imm_ext_e			)
	);


	riscv_de_register
	#(
	.REGISTER_INIT				(REGISTER_INIT				)
	)
	u_riscv_de_register(
	.o_de_register_src_pc		(src_pc_e      				),
	.o_de_register_src_imm		(src_imm_e     				),
	.o_de_register_src_rd		(src_rd_e      				),
	.o_de_register_src_alu_a	(src_alu_a_e   				),
	.o_de_register_src_alu_b	(src_alu_b_e   				),
	.o_de_register_reg_wr_en	(reg_wr_en_e   				),
	.o_de_register_mem_wr_en	(mem_wr_en_e   				),
	.o_de_register_mem_byte_sel	(mem_byte_sel_e				),
	.o_de_register_alu_ctrl		(alu_ctrl_e    				),
	.o_de_register_rs1_data		(rs1_data_e    				),
	.o_de_register_rs2_data		(rs2_data_e    				),
	.o_de_register_pc			(pc_e          				),
	.o_de_register_rs1_addr		(rs1_addr_e    				),
	.o_de_register_rs2_addr		(rs2_addr_e    				),
	.o_de_register_rd_addr		(rd_addr_e     				),
	.o_de_register_func3		(func3_e       				),
	.o_de_register_imm_ext		(imm_ext_e     				),
	.o_de_register_pcplus4		(pcplus4_e     				),
	.i_de_register_src_pc		(i_dp_src_pc				),
	.i_de_register_src_imm		(i_dp_src_imm				),
	.i_de_register_src_rd		(i_dp_src_rd				),
	.i_de_register_src_alu_a	(i_dp_src_alu_a				),
	.i_de_register_src_alu_b	(i_dp_src_alu_b				),
	.i_de_register_reg_wr_en	(i_dp_reg_wr_en				),
	.i_de_register_mem_wr_en	(i_dp_mem_wr_en				), 
	.i_de_register_mem_byte_sel	(i_dp_mem_byte_sel			), 
	.i_de_register_alu_ctrl		(i_dp_alu_ctrl				),
	.i_de_register_rs1_data		(regfile_rs1_data			),
	.i_de_register_rs2_data		(regfile_rs2_data			),
	.i_de_register_pc			(pc_d						),
	.i_de_register_rs1_addr		(instr_d[19:15]				),
	.i_de_register_rs2_addr		(instr_d[24:20]				),
	.i_de_register_rd_addr		(instr_d[11: 7]				),
	.i_de_register_func3		(instr_d[14: 12]			),
	.i_de_register_imm_ext		(immediate					),
	.i_de_register_pcplus4		(pcplus4_d					),
	.i_de_register_en			(stall_d					),
	.i_clk						(i_clk						),
	.i_rstn						(flush_e					)
	);


	riscv_mux
	#(
		.N_MUX_IN			(3					)
	)
	u_riscv_mux_forward_ae(
		.o_mux_data			(forward_ae_result		),
		.i_mux_concat_data	(mux_concat_forward_ae	),
		.i_mux_sel			(forward_ae				)
	);


	riscv_mux
	#(
		.N_MUX_IN			(3					)
	)
	u_riscv_mux_forward_be(
		.o_mux_data			(forward_be_result		),
		.i_mux_concat_data	(mux_concat_forward_be	),
		.i_mux_sel			(forward_be				)
	);


	riscv_alu
	u_riscv_alu(
		.o_alu_result		(alu_result			),
		.o_alu_zero			(o_dp_alu_zero		),
		.i_alu_a			(alu_a				),
		.i_alu_b			(alu_b				),
		.i_alu_ctrl			(i_dp_alu_ctrl		)
	);


	riscv_mux
	#(
		.N_MUX_IN			(2					)
	)
	u_riscv_mux_alu_a(
		.o_mux_data			(alu_a				),
		.i_mux_concat_data	(mux_concat_alu_a	),
		.i_mux_sel			(i_dp_src_alu_a		)
	);

	riscv_mux
	#(
		.N_MUX_IN			(2					)
	)
	u_riscv_mux_alu_b(
		.o_mux_data			(alu_b				),
		.i_mux_concat_data	(mux_concat_alu_b	),
		.i_mux_sel			(i_dp_src_alu_b		)
	);


	riscv_em_register
	#(
	.REGISTER_INIT				(REGISTER_INIT				)
	)
	u_riscv_em_register(
	.o_em_register_src_rd		(src_rd_m			), 
	.o_em_register_reg_wr_en	(reg_wr_en_m		),
	.o_em_register_mem_wr_en	(mem_wr_en_m		),
	.o_em_register_mem_byte_sel	(mem_byte_sel_m		),
	.o_em_register_alu_result	(alu_result_m		),
	.o_em_register_write_data	(write_data_m		),
	.o_em_register_rd_addr		(rd_addr_m			),
	.o_em_register_func3		(func3_m			),
	.o_em_register_pcplus4		(pcplus4_m			),
	.o_em_register_imm_ext		(imm_ext_m			),
	.i_em_register_src_rd		(src_rd_e			),
	.i_em_register_reg_wr_en	(reg_wr_en_e		),
	.i_em_register_mem_wr_en	(mem_wr_en_e		),
	.i_em_register_mem_byte_sel	(mem_byte_sel_e		),
	.i_em_register_alu_result	(alu_result			),
	.i_em_register_write_data	(forward_be_result	),
	.i_em_register_rd_addr		(rd_addr_e			),
	.i_em_register_func3		(func3_e			),
	.i_em_register_pcplus4		(pcplus4_e			),
	.i_em_register_imm_ext		(imm_ext_e			),
	.i_em_register_en			(1'b1				),
	.i_clk						(i_clk				),
	.i_rstn						(i_rstn				)
	);


	riscv_mw_register
	#(
	.REGISTER_INIT			(REGISTER_INIT			)
	)
	u_riscv_mw_register(
	.o_mw_register_src_rd		(src_rd_w			),
	.o_mw_register_reg_wr_en	(reg_wr_en_w		),
	.o_mw_register_alu_result	(alu_result_w		),
	.o_mw_register_rd_data		(rd_data_w			),
	.o_mw_register_rd_addr		(rd_addr_w			),
	.o_mw_register_pcplus4		(pcplus4_w			),
	.o_mw_register_imm_ext		(imm_ext_w			),
	.i_mw_register_src_rd		(src_rd_m			),
	.i_mw_register_reg_wr_en	(reg_wr_en_m		),
	.i_mw_register_alu_result	(alu_result_m		),
	.i_mw_register_rd_data		(i_dp_mem_rd_data	),
	.i_mw_register_rd_addr		(rd_addr_m			),
	.i_mw_register_pcplus4		(pcplus4_m			),
	.i_mw_register_imm_ext		(imm_ext_m			),
	.i_mw_register_en			(1'b1				),
	.i_clk						(i_clk				),
	.i_rstn						(i_rstn				)
	);

	riscv_mux
	#(
		.N_MUX_IN			(4					)
	)
	u_riscv_mux_regfile_rd_data(
		.o_mux_data			(regfile_rd_data	),
		.i_mux_concat_data	(mux_concat_rd		),
		.i_mux_sel			(src_rd_w		)
	);


	riscv_hazard_unit
	u_riscv_hazard_unit(
	.o_hazard_stall_f		(stall_f	),
	.o_hazard_stall_d		(stall_d	),
	.o_hazard_flush_d		(flush_d	),
	.o_hazard_flush_e		(flush_e	),
	.o_hazard_forward_ae	(forward_ae),
	.o_hazard_forward_be	(forward_be),
	.i_hazard_rs1_addr_d	(instr_d[19:15]),
	.i_hazard_rs2_addr_d	(instr_d[24:20]),
	.i_hazard_rd_addr_e		(rd_addr_e	),
	.i_hazard_rs1_addr_e	(rs1_addr_e),
	.i_hazard_rs2_addr_e	(rs2_addr_e),
	.i_hazard_src_pc		(src_pc_e	),
	.i_hazard_src_rd_0		(src_rd_e[0]	),
	.i_hazard_rd_addr_m		(rd_addr_m	),
	.i_hazard_reg_wr_en_m	(reg_wr_en_m),
	.i_hazard_rd_addr_w		(rd_addr_w	),
	.i_hazard_reg_wr_en_w	(reg_wr_en_w)
	);


endmodule
