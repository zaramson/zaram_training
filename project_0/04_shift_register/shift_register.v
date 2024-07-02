// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: shift_register.v
//	* Date			: 2024-07-01 16:54:57
//	* Description	:
// ==================================================

module shift_register 
(
	output					o_Sout,
	output		[8-1:0]		o_Qout,
	input		[8-1:0] 	i_D,
	input					i_Load,
	input					i_Sin,
	input					i_Clk
);

	mux_dff
	u_mux_dff_0(
	.o_out				(o_Qout[0]			),
	.i_in0				(i_Sin				),
	.i_in1				(i_D[0]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);

	mux_dff
	u_mux_dff_1(
	.o_out				(o_Qout[1]			),
	.i_in0				(o_Qout[0]			),
	.i_in1				(i_D[1]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);

	mux_dff
	u_mux_dff_2(
	.o_out				(o_Qout[2]			),
	.i_in0				(o_Qout[1]			),
	.i_in1				(i_D[2]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);

	mux_dff
	u_mux_dff_3(
	.o_out				(o_Qout[3]			),
	.i_in0				(o_Qout[2]			),
	.i_in1				(i_D[3]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);

	mux_dff
	u_mux_dff_4(
	.o_out				(o_Qout[4]			),
	.i_in0				(o_Qout[3]			),
	.i_in1				(i_D[4]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);

	mux_dff
	u_mux_dff_5(
	.o_out				(o_Qout[5]			),
	.i_in0				(o_Qout[4]			),
	.i_in1				(i_D[5]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);

	mux_dff
	u_mux_dff_6(
	.o_out				(o_Qout[6]			),
	.i_in0				(o_Qout[5]			),
	.i_in1				(i_D[6]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);

	mux_dff
	u_mux_dff_7(
	.o_out				(o_Qout[7]			),
	.i_in0				(o_Qout[6]			),
	.i_in1				(i_D[7]				),
	.i_sel				(i_Load				),
	.i_clk				(i_Clk				)
	);

	assign o_Sout = o_Qout[7];
	
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
