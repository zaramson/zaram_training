// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_mw_register.v
//	* Date			: 2024-08-08 13:10:28
//	* Description	:
// ==================================================






`ifndef		NOINC
`include	"../common/riscv_configs.v"
`endif

module riscv_mw_register
#(
	parameter	REGISTER_INIT	= 0
)
(	
	output reg	[1:0]			o_mw_register_src_rd,
	output reg					o_mw_register_reg_wr_en,
	output reg	[`XLEN-1:0]		o_mw_register_alu_result,
	output reg	[`XLEN-1:0]		o_mw_register_rd_data,
	output reg	[	   4:0]		o_mw_register_rd_addr,
	output reg	[`XLEN-1:0]		o_mw_register_pcplus4,
	output reg	[`XLEN-1:0]		o_mw_register_imm_ext,
	output reg					o_mw_register_is_load,
	output reg	[`XLEN-1:0]		o_mw_register_for_forward_result,

	input		[1:0]			i_mw_register_src_rd,
	input						i_mw_register_reg_wr_en,
	input		[`XLEN-1:0]		i_mw_register_alu_result,
	input		[`XLEN-1:0]		i_mw_register_rd_data,
	input		[      4:0]		i_mw_register_rd_addr,
	input		[`XLEN-1:0]		i_mw_register_pcplus4,
	input		[`XLEN-1:0]		i_mw_register_imm_ext,
	input						i_mw_register_en,
	input						i_mw_register_is_load,
	input		[`XLEN-1:0]		i_mw_register_for_forward_result,
	input						i_clk,
	input						i_rstn
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			 o_mw_register_src_rd     			 <= REGISTER_INIT;
             o_mw_register_reg_wr_en  			 <= REGISTER_INIT;
             o_mw_register_alu_result 			 <= REGISTER_INIT;
             o_mw_register_rd_data    			 <= REGISTER_INIT;
             o_mw_register_rd_addr    			 <= REGISTER_INIT;
             o_mw_register_pcplus4    			 <= REGISTER_INIT;
             o_mw_register_imm_ext    			 <= REGISTER_INIT;
             o_mw_register_is_load    			 <= REGISTER_INIT;
             o_mw_register_for_forward_result    <= REGISTER_INIT;
		end else begin
			if(i_mw_register_en) begin
			   	o_mw_register_src_rd	  			 <= i_mw_register_src_rd;
            	o_mw_register_reg_wr_en   			 <= i_mw_register_reg_wr_en;
            	o_mw_register_alu_result  			 <= i_mw_register_alu_result;
            	o_mw_register_rd_data     			 <= i_mw_register_rd_data;
            	o_mw_register_rd_addr     			 <= i_mw_register_rd_addr;
            	o_mw_register_pcplus4     			 <= i_mw_register_pcplus4;
            	o_mw_register_imm_ext     			 <= i_mw_register_imm_ext;
            	o_mw_register_is_load     			 <= i_mw_register_is_load;
            	o_mw_register_for_forward_result     <= i_mw_register_for_forward_result;
			end else begin
			   	o_mw_register_src_rd	  			 <= o_mw_register_src_rd;
            	o_mw_register_reg_wr_en   			 <= o_mw_register_reg_wr_en;
            	o_mw_register_alu_result  			 <= o_mw_register_alu_result;
            	o_mw_register_rd_data     			 <= o_mw_register_rd_data;
            	o_mw_register_rd_addr     			 <= o_mw_register_rd_addr;
            	o_mw_register_pcplus4     			 <= o_mw_register_pcplus4;
            	o_mw_register_imm_ext     			 <= o_mw_register_imm_ext;
            	o_mw_register_is_load     			 <= i_mw_register_is_load;
            	o_mw_register_for_forward_result     <= i_mw_register_for_forward_result;
			end
		end
	end

endmodule
