// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: barrel_shifter.v
//	* Date			: 2024-06-28 18:08:45
//	* Description	:
// ==================================================

module barrel_shifter 
(
	output	[7:0]	o_Y;
	input 	[7:0]	i_A;
	input	[2:0]	i_k;
);
	
	wire	[7:0]	w_4rotate;
	wire	[7:0] 	w_2rotate;


	mux2
	u_mux2_0(
	.o_out				(w_4rotate[0]		),	//0,1,2..
	.i_sel				(i_k[2]				),	//fix 2
	.i_in0				(i_A[0]				),	//0,1,2..
	.i_in1				(i_A[4]				) 	//4,5,6,7 0,1,2,3
	);

	genvar i;
	generate
		for (i=0; i<4; i=i+1) begin
		
		end






endmodule







module mux2 
(
	output	reg	o_out,
	input		i_sel,
	input		i_in0,
	input		i_in1
);

	always @ (*) begin
		case(i_sel)
			0:			o_out = i_in0;
			1:			o_out = i_in1;
			default:	o_out = i_in1;
		endcase
	end

endmodule
