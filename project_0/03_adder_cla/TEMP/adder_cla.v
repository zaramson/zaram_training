
// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: adder_cla.v
//	* Date			: 2024-07-01 11:35:51
//	* Description	:
// ==================================================

module adder_cla32
#(
	parameter	BW_DATA = 32
)
(
	output		[BW_DATA-1:0]		o_S,
	output							o_Cout,
	input		[BW_DATA-1:0]		i_A,
	input		[BW_DATA-1:0]		i_B,
	input							i_Cin
);
	
	wire		[BW_DATA/4 -2:0]	w_Cout; //3, 7, 11, 15, 19, 23, 27, (31=Cout)

	genvar i;
	
	generate
		for (i=1; i<BW_DATA/4 -2; i=i+1) begin
			full_adder
			u_full_adder(
			.o_S				(o_S[i*4+3:i*4]		),
			.o_Cout				(					),
			.i_A				(i_A[i*4+3:i*4]		),
			.i_B				(i_B[i*4+3:i*4]		),
			.i_Cin				(w_Cout[i-1]		)
			);

			PG_adder
			u_PG_adder(
			.o_Cout				(w_Cout[i+1]		),
			.i_A				(i_A[i*4+3:i*4]		),
			.i_B				(i_B[i*4+3:i*4]		),
			.i_Cin				(w_Cout[i-1]		)
			);
		end
	endgenerate



	full_adder
	u_full_adder_INIT(
	.o_S				(o_S[3:0]			),
	.o_Cout				(					),
	.i_A				(i_A[3:0]			),
	.i_B				(i_B[3:0]			),
	.i_Cin				(i_Cin				)
	);

	PG_adder
	u_PG_adder_INIT(
	.o_Cout				(w_Cout[0]			),
	.i_A				(i_A[3:0]			),
	.i_B				(i_B[3:0]			),
	.i_Cin				(i_Cin				)
	);


	full_adder
	u_full_adder_FINAL(
	.o_S				(o_S[31:28]			),
	.o_Cout				(					),
	.i_A				(i_A[31:28]			),
	.i_B				(i_B[31:28]			),
	.i_Cin				(w_Cout[6]			)
	);

	PG_adder
	u_PG_adder_FINAL(
	.o_Cout				(o_Cout				),
	.i_A				(i_A[31:28]			),
	.i_B				(i_B[31:28]			),
	.i_Cin				(w_Cout[6]			)
	);


endmodule


module full_adder
#(	
	parameter	BW_DATA	= 4
)
(	
	output		[BW_DATA-1:0]	o_S,
	output						o_Cout,
	input		[BW_DATA-1:0]	i_A,
	input		[BW_DATA-1:0]	i_B,
	input						i_Cin
);

	assign	{o_Cout, o_S} = i_A + i_B + i_Cin;

endmodule

module PG_adder
#(	
	parameter	BW_DATA	= 4
)
(
	output					o_Cout,
	input	[BW_DATA-1:0]	i_A,
	input	[BW_DATA-1:0]	i_B,
	input					i_Cin
);

	wire	[BW_DATA-1:0]	w_G;
	wire	[BW_DATA-1:0]	w_P;
	wire	[BW_DATA-2:0]	w_GN;
	wire					w_PN;

	genvar i, j;
	
	generate
		for (i=0; i<4; i=i+1) begin

			assign	w_G[i] = i_A[i] & i_B[i];
			assign	w_P[i] = i_A[i] ^ i_B[i];

		end
	endgenerate


	assign w_GN[0] = w_G[1] | (w_P[1] & w_G[1]);

	generate
	for (j=0; j<BW_DATA-2; j=j+1) begin

		assign w_GN[j+1] = w_G[j+1] | (w_P[j+1] & w_GN[j]);

	end
	endgenerate

	assign w_PN = & w_P ;
	assign o_Cout = w_GN[BW_DATA-2] | (w_PN & i_Cin);

//	assign w_GN = w_G[3] | (w_P[3] & (w_G[2] | (w_P[2] & (w_G[1] | (w_P[1] & w_G[0]))))); 
//	assign w_PN = w_P[0] & w_P[1] & w_P[2] & w_P[3];
//	assign o_Cout = w_GN | (w_PN & i_Cin);

endmodule


