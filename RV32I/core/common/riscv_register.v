// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_register.v
//	* Date			: 2024-07-18 17:35:08
//	* Description	:
// ==================================================


`include	"riscv_configs.v"

module riscv_register
#(
	parameter	REGISTER_INIT	= 0
)
(	
	output reg	[`XLEN-1:0]		o_register_q,
	input		[`XLEN-1:0]		i_register_d,
	input						i_register_en,
	input						i_clk,
	input						i_rstn
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_register_q	<= REGISTER_INIT;
		end else begin
			if(i_register_en) begin
				o_register_q	<= i_register_d;
			end else begin
				o_register_q	<= o_register_q;
			end
		end
	end

endmodule
