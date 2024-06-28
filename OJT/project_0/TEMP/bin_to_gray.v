
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


