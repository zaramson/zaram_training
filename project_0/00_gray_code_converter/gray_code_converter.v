// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: gray_code_converter.v
//	* Date			: 2024-06-28 17:04:30
//	* Description	:
// ==================================================

module bin_to_gray
#(
	parameter BW_DATA = 8
)
(
	output	[BW_DATA-1:0] o_gray,
	input	[BW_DATA-1:0] i_binary
);
	

	assign o_gray[BW_DATA-1] = i_binary[BW_DATA-1];

	genvar i;
	generate
		for (i=0; i<BW_DATA-1; i=i+1) begin
			assign o_gray[i] = i_binary[i+1]^i_binary[i];
		end
	endgenerate

endmodule


module gray_to_bin
#(
	parameter BW_DATA = 8
)
(
	output	[BW_DATA-1:0] o_binary,
	input	[BW_DATA-1:0] i_gray
);
	

	assign o_binary[BW_DATA-1] = i_gray[BW_DATA-1];

	genvar i;
	generate
		for (i=0; i<BW_DATA-1; i=i+1) begin
			assign o_binary[i] = o_binary[i+1]^i_gray[i];
		end
	endgenerate



endmodule
