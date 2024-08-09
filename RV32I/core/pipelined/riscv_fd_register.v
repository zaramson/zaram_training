// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_fd_register.v
//	* Date			: 2024-08-08 09:41:12
//	* Description	:
// ==================================================



`ifndef		NOINC
`include	"../common/riscv_configs.v"
`endif

module riscv_fd_register
#(
	parameter	REGISTER_INIT	= 0
)
(	
	output reg	[`XLEN-1:0]		o_fd_register_instr,
	output reg	[`XLEN-1:0]		o_fd_register_pc,
	output reg	[`XLEN-1:0]		o_fd_register_pcplus4,
	input		[`XLEN-1:0]		i_fd_register_instr,
	input		[`XLEN-1:0]		i_fd_register_pc,
	input		[`XLEN-1:0]		i_fd_register_pcplus4,
	input						i_fd_register_en,
	input						i_clk,
	input						i_rstn
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_fd_register_instr		<= REGISTER_INIT;
			o_fd_register_pc		<= REGISTER_INIT;
			o_fd_register_pcplus4	<= REGISTER_INIT;
		end else begin
			if(i_fd_register_en) begin
				o_fd_register_instr	 	<= i_fd_register_instr;
				o_fd_register_pc	 	<= i_fd_register_pc;
				o_fd_register_pcplus4	<= i_fd_register_pcplus4;
			end else begin
				o_fd_register_instr		<= o_fd_register_instr;	 
				o_fd_register_pc	 	<= o_fd_register_pc;	 
				o_fd_register_pcplus4	<= o_fd_register_pcplus4;
			end
		end
	end

endmodule
