module parity 
#(
	parameter	BW_DATA = 8
)
(
	input	[BW_DATA-1:0]	i_A,
	output					o_Y
);

	assign	o_Y = ^i_A[BW_DATA-1:0];
	//assign	o_Y = ^i_A[7]^i_A[6]^i_A[5]^i_A[4]^i_A[3]^i_A[2]^i_A[1]^i_A[0];
	
endmodule
