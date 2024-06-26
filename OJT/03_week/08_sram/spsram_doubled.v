// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: spsram_doubled.v
//	* Date			: 2024-06-26 15:03:06
//	* Description	:
// ==================================================

`include	"spsram.v"

module spsram_doubled 
#(
	parameter	BW_DATA	=	32,
	parameter	BW_ADDR	=	5
)
(
	output	[BW_DATA-1:0]	o_data,
	input	[BW_DATA-1:0]	i_data,
	input	[BW_ADDR-1:0]	i_addr,
	input					i_wen,
	input					i_cen,
	input					i_oen,
	input					i_clk
);
	

	spsram
	u_spsram_0(
	.o_data				(o_data				),
	.i_data				(i_data				),
	.i_addr				(i_addr[3:0]		),
	.i_wen				(~i_addr[4]			),
	.i_cen				(i_cen				),
	.i_oen				(~i_addr[4]			),
	.i_clk				(i_clk				)
	);


	spsram
	u_spsram_1(
	.o_data				(o_data				),
	.i_data				(i_data				),
	.i_addr				(i_addr[3:0]		),
	.i_wen				(i_addr[4]			),
	.i_cen				(i_cen				),
	.i_oen				(i_addr[4]			),
	.i_clk				(i_clk				)
	);


endmodule





