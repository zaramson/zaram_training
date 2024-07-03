// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: barrel_shifter.v
//	* Date			: 2024-06-28 18:08:45
//	* Description	:
// ==================================================

module barrel_shifter 
(
	output	[7:0]	o_Y,
	input 	[7:0]	i_A,
	input	[2:0]	i_k
);
	
	wire	[7:0]	w_rotate_4;
	wire	[7:0] 	w_rotate_2;


//	mux2
//	u_mux2(
//	.o_out				(w_rotate_4[0]		),	//0,1,2,3 4,5,6,7   i
//	.i_sel				(i_k[2]				),	//fix 2
//	.i_in0				(i_A[0]				),	//0,1,2,3 4,5,6,7  	i
//	.i_in1				(i_A[4]				) 	//4,5,6,7 0,1,2,3   i+4 i-4
//	);

	genvar i, j, k;
	generate
		for (i=0; i<4; i=i+1) begin : rotate4_mux_1
			mux2
			u_mux2(
			.o_out				(w_rotate_4[i]		),	
			.i_sel				(i_k[2]				),	
			.i_in0				(i_A[i]				),	
			.i_in1				(i_A[i+4]			) 	
			);
		end

		for (i=4; i<8; i=i+1) begin : rotate4_mux_2
			mux2
			u_mux2(
			.o_out				(w_rotate_4[i]		),	
			.i_sel				(i_k[2]				),	
			.i_in0				(i_A[i]				),	
			.i_in1				(i_A[i-4]			) 	
			);
		end

//	mux2
//	u_mux2(
//	.o_out				(w_rotate_2[0]		),	//0,1,2,3 4,5,6,7   i
//	.i_sel				(i_k[1]				),	//fix 1
//	.i_in0				(w_rotate_4[0]		),	//0,1,2,3,4,5 6,7  	i
//	.i_in1				(w_rotate_4[2]		) 	//2,3,4,5,6,7 0,1   i+2 i-6
//	);

		for (j=0; j<6; j=j+1) begin : rotate2_mux_1
			mux2
			u_mux2(
			.o_out				(w_rotate_2[j]		),	
			.i_sel				(i_k[1]				),	
			.i_in0				(w_rotate_4[j]		),	
			.i_in1				(w_rotate_4[j+2]	) 	
			);
		end

		for (j=6; j<8; j=j+1) begin : rotate2_mux_2
			mux2
			u_mux2(
			.o_out				(w_rotate_2[j]		),	
			.i_sel				(i_k[1]				),	
			.i_in0				(w_rotate_4[j]		),	
			.i_in1				(w_rotate_4[j-6]	) 	
			);		
		end

//	mux2
//	u_mux2(
//	.o_out				(o_Y[0]				),	//0,1,2,3 4,5,6,7   i
//	.i_sel				(i_k[0]				),	//fix 0
//	.i_in0				(w_rotate_2[0]		),	//0,1,2,3,4,5,6 7  	i
//	.i_in1				(w_rotate_2[1]		) 	//1,2,3,4,5,6,7 0   i+1 i-7
//	);

		for (k=0; k<7; k=k+1) begin : rotate1_mux_1
			mux2
			u_mux2(
			.o_out				(o_Y[k]				),	
			.i_sel				(i_k[1]				),	
			.i_in0				(w_rotate_2[k]		),	
			.i_in1				(w_rotate_2[k+1]	) 	
			);
		end


		for (k=7; k<8; k=k+1) begin : rotate1_mux_2
			mux2
			u_mux2(
			.o_out				(o_Y[k]				),	
			.i_sel				(i_k[1]				),	
			.i_in0				(w_rotate_2[k]		),	
			.i_in1				(w_rotate_2[k-7]	) 	
			);
		end
	endgenerate

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
