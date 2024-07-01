// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: alu.v
//	* Date			: 2024-07-01 15:36:05
//	* Description	:
// ==================================================

module alu 
#(
	parameter BW_DATA = 4
)
(
	output	reg	[BW_DATA-1:0]	o_Y,
	output	reg					o_Cout,
	input		[BW_DATA-1:0]	i_A,
	input		[BW_DATA-1:0]	i_B,
	input		[2:0]			i_F
);
	

	always @ (*) begin
		o_Cout	= 0;
		case (i_F)
			3'b000 	: o_Y			= i_A & i_B;
			3'b001 	: o_Y 			= i_A | i_B;
			3'b010 	: {o_Cout, o_Y} = i_A + i_B;
			3'b011 	: o_Y 			= 0;
			3'b100 	: o_Y 			= i_A & ~i_B;
			3'b101 	: o_Y 			= i_A | ~i_B;
			3'b110 	: o_Y			= i_A - i_B;
			3'b111 	: o_Y			= (i_A < i_B) ? 1 : 0;
			default : o_Y			= 0;
		endcase
	end


endmodule
