// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: shift_register.v
//	* Date			: 2024-07-01 16:54:57
//	* Description	:
// ==================================================

module shift_register 
#(
	parameter BW_DATA = 8
)
(
	output					o_Sout,
	output	[BW_DATA-1:0]	o_Qout,
	input	[BW_DATA-1:0] 	i_D,
	input					i_Load,
	input					i_Sin,
	input					i_Clk
);

	mux_dff
	u_mux_dff_Inital(
	.o_out				(o_Qout[0]			),
	.i_in0				(i_Sin				),
	.i_in1				(i_D[0]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);


 	genvar i;	
	generate
		for (i=0; i<BW_DATA-1; i=i+1) begin
			mux_dff
			u_mux_dff(
			.o_out				(o_Qout[i+1]		),
			.i_in0				(o_Qout[i]			),
			.i_in1				(i_D[i+1]			),
			.i_sel				(i_Load				),
			.i_clk				(i_Clk				)
			);
		end
	endgenerate


	mux_dff
	u_mux_dff_Final(
	.o_out				(o_Qout[BW_DATA-1]			),
	.i_in0				(o_Qout[BW_DATA-2]			),
	.i_in1				(i_D[BW_DATA-1]				),
	.i_sel				(i_Load						),
	.i_clk				(i_Clk						)
	);

	assign o_Sout = o_Qout[BW_DATA-1];
	
endmodule



module mux_dff
(
	output	reg	o_out,
	input		i_in0,
	input		i_in1,
	input		i_sel,
	input		i_clk
);
	
	wire	w_mux_out;
	
	assign	w_mux_out = i_sel ? i_in1 : i_in0;

	always @ (posedge i_clk) begin
		o_out = w_mux_out;
	end

endmodule
