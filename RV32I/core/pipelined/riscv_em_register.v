// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_em_register.v
//	* Date			: 2024-08-08 11:21:41
//	* Description	:
// ==================================================





`ifndef		NOINC
`include	"../common/riscv_configs.v"
`endif

module riscv_em_register
#(
	parameter	REGISTER_INIT	= 0
)
(	
	output reg	[1:0]			o_em_register_src_rd,
	output reg					o_em_register_reg_wr_en,
	output reg					o_em_register_mem_wr_en,
	output reg	[3:0]			o_em_register_mem_byte_sel,
	output reg	[`XLEN-1:0]		o_em_register_alu_result,
	output reg	[`XLEN-1:0]		o_em_register_write_data,
	output reg	[      4:0]		o_em_register_rd_addr,
	output reg	[      2:0]		o_em_register_func3,
	output reg	[`XLEN-1:0]		o_em_register_pcplus4,
	output reg	[`XLEN-1:0]		o_em_register_imm_ext,
	input		[1:0]			i_em_register_src_rd,
	input						i_em_register_reg_wr_en,
	input						i_em_register_mem_wr_en,
	input		[3:0]			i_em_register_mem_byte_sel,
	input		[`XLEN-1:0]		i_em_register_alu_result,
	input		[`XLEN-1:0]		i_em_register_write_data,
	input		[      4:0]		i_em_register_rd_addr,
	input		[      2:0]		i_em_register_func3,
	input		[`XLEN-1:0]		i_em_register_pcplus4,
	input		[`XLEN-1:0]		i_em_register_imm_ext,
	input						i_em_register_en,
	input						i_clk,
	input						i_rstn
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_em_register_src_rd        <= REGISTER_INIT;
            o_em_register_reg_wr_en     <= REGISTER_INIT;
            o_em_register_mem_wr_en     <= REGISTER_INIT;
            o_em_register_mem_byte_sel  <= REGISTER_INIT;
            o_em_register_alu_result    <= REGISTER_INIT;
            o_em_register_write_data    <= REGISTER_INIT;
            o_em_register_rd_addr       <= REGISTER_INIT;
            o_em_register_func3         <= REGISTER_INIT;
            o_em_register_pcplus4       <= REGISTER_INIT;
            o_em_register_imm_ext       <= REGISTER_INIT;
		end else begin
			if(i_em_register_en) begin
				o_em_register_src_rd      	<= i_em_register_src_rd;
            	o_em_register_reg_wr_en     <= i_em_register_reg_wr_en;
            	o_em_register_mem_wr_en     <= i_em_register_mem_wr_en;
            	o_em_register_mem_byte_sel  <= i_em_register_mem_byte_sel;
            	o_em_register_alu_result    <= i_em_register_alu_result;
            	o_em_register_write_data    <= i_em_register_write_data;
            	o_em_register_rd_addr       <= i_em_register_rd_addr;
            	o_em_register_func3         <= i_em_register_func3;
            	o_em_register_pcplus4       <= i_em_register_pcplus4;
            	o_em_register_imm_ext       <= i_em_register_imm_ext;
			end else begin
				o_em_register_src_rd      	<= o_em_register_src_rd;
            	o_em_register_reg_wr_en     <= o_em_register_reg_wr_en;
            	o_em_register_mem_wr_en     <= o_em_register_mem_wr_en;
            	o_em_register_mem_byte_sel  <= o_em_register_mem_byte_sel;
            	o_em_register_alu_result    <= o_em_register_alu_result;
            	o_em_register_write_data    <= o_em_register_write_data;
            	o_em_register_rd_addr       <= o_em_register_rd_addr;
            	o_em_register_func3         <= o_em_register_func3;
            	o_em_register_pcplus4       <= o_em_register_pcplus4;
            	o_em_register_imm_ext       <= o_em_register_imm_ext;
			end
		end
	end

endmodule
