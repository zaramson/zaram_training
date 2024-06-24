// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: gray_cc.v
//	* Date			: 2024-06-24 10:52:14
//	* Description	: 
// ==================================================

module gray_cc 
//#(
//	parameter BW_DATA = 3
(
	//input	[BW_DATA-1:0]	i_binary,
	//output	[BW_DATA-1:0]	o_gray
	input	[2:0]	i_binary,
	output	[2:0]	o_gray
);
	
	assign o_gray[2] = i_binary[2];
	
	assign o_gray[1] = i_binary[2]^i_binary[1];
	assign o_gray[0] = i_binary[1]^i_binary[0];

endmodule
