// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_hazard_unit.v
//	* Date			: 2024-08-08 14:21:11
//	* Description	:
// ==================================================




`ifndef		NOINC
`include	"../common/riscv_configs.v"
`endif

module riscv_hazard_unit
(	
	output 						o_hazard_stall_f,
	output 						o_hazard_stall_d,
	output 						o_hazard_flush_d,
	output 						o_hazard_flush_e,
	output reg	[	   1:0]		o_hazard_forward_ae,
	output reg	[	   1:0]		o_hazard_forward_be,
	input		[      4:0]		i_hazard_rs1_addr_d,
	input		[      4:0]		i_hazard_rs2_addr_d,
	input		[      4:0]		i_hazard_rd_addr_e,
	input		[      4:0]		i_hazard_rs1_addr_e,
	input		[      4:0]		i_hazard_rs2_addr_e,
	input		[      1:0]		i_hazard_src_pc,
	input						i_hazard_is_load_e,
	input		[      4:0]		i_hazard_rd_addr_m,
	input						i_hazard_reg_wr_en_m,
	input		[      4:0]		i_hazard_rd_addr_w,
	input						i_hazard_reg_wr_en_w
);


	always @(*) begin
	//Data hazard logic (SrcA of ALU)
		if(((i_hazard_rs1_addr_e == i_hazard_rd_addr_m) && i_hazard_reg_wr_en_m) && (i_hazard_rs1_addr_e !== 5'b00000)) begin
			o_hazard_forward_ae = 2'b10;
		end else if (((i_hazard_rs1_addr_e == i_hazard_rd_addr_w) && i_hazard_reg_wr_en_w) && (i_hazard_rs1_addr_e !== 5'b00000)) begin
			o_hazard_forward_ae = 2'b01;
		end else begin
			o_hazard_forward_ae = 2'b00;
		end

	//Data hazard logic (SrcB of ALU)
		if(((i_hazard_rs2_addr_e == i_hazard_rd_addr_m) && i_hazard_reg_wr_en_m) && (i_hazard_rs2_addr_e !== 5'b00000)) begin
			o_hazard_forward_be = 2'b10;
		end else if (((i_hazard_rs2_addr_e == i_hazard_rd_addr_w) && i_hazard_reg_wr_en_w) && (i_hazard_rs2_addr_e !== 5'b00000)) begin
			o_hazard_forward_be = 2'b01;
		end else begin
			o_hazard_forward_be = 2'b00;
		end

	end


	//Load word stall logic
		wire lwstall;

		assign lwstall = ((i_hazard_rs1_addr_d == i_hazard_rd_addr_e) || (i_hazard_rs2_addr_d == i_hazard_rd_addr_e)) && i_hazard_is_load_e;
		
		assign o_hazard_stall_f = lwstall;
		assign o_hazard_stall_d = lwstall;

	//Control hazard flush

		assign o_hazard_flush_d = (i_hazard_src_pc != 2'b00);
		assign o_hazard_flush_e = (i_hazard_src_pc != 2'b00) || lwstall;



endmodule
