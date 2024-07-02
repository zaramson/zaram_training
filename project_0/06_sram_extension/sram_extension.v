// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: sram_extension.v
//	* Date			: 2024-07-02 13:44:12
//	* Description	:
// ==================================================

`include	"spsram.v"

module sram_extension
#(
	parameter	BW_DATA	=	64,
	parameter	BW_ADDR	=	6
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
	#(
	.BW_DATA			(32			),
	.BW_ADDR			(4			)
	)
	u_spsram_0(
	.o_data				(o_data[32-1:0]			),
	.i_data				(i_data[32-1:0]			),
	.i_addr				(i_addr[3:0]			),
	.i_wen				(i_wen					),
	.i_cen				(~i_addr[5] & ~i_addr[4]),
	.i_oen				(~i_addr[5]	& ~i_addr[4]),
	.i_clk				(i_clk					)
	);


	spsram
	#(
	.BW_DATA			(32			),
	.BW_ADDR			(4			)
	)	
	u_spsram_1(
	.o_data				(o_data[32-1:0]			),
	.i_data				(i_data[32-1:0]			),
	.i_addr				(i_addr[3:0]			),
	.i_wen				(i_wen					),
	.i_cen				(~i_addr[5] & i_addr[4]	),
	.i_oen				(~i_addr[5]	& i_addr[4]	),
	.i_clk				(i_clk					)
	);

	spsram
	#(
	.BW_DATA			(32			),
	.BW_ADDR			(4			)
	)	
	u_spsram_2(
	.o_data				(o_data[32-1:0]			),
	.i_data				(i_data[32-1:0]			),
	.i_addr				(i_addr[3:0]			),
	.i_wen				(i_wen					),
	.i_cen				(i_addr[5] & ~i_addr[4]	),
	.i_oen				(i_addr[5] & ~i_addr[4]	),
	.i_clk				(i_clk					)
	);

	spsram
	#(
	.BW_DATA			(32			),
	.BW_ADDR			(4			)
	)	
	u_spsram_3(
	.o_data				(o_data[32-1:0]			),
	.i_data				(i_data[32-1:0]			),
	.i_addr				(i_addr[3:0]			),
	.i_wen				(i_wen					),
	.i_cen				(i_addr[5] & i_addr[4]	),
	.i_oen				(i_addr[5] & i_addr[4]	),
	.i_clk				(i_clk					)
	);

	spsram
	#(
	.BW_DATA			(32			),
	.BW_ADDR			(4			)
	)
	u_spsram_4(
	.o_data				(o_data[64-1:32]		),
	.i_data				(i_data[64-1:32]		),
	.i_addr				(i_addr[3:0]			),
	.i_wen				(i_wen					),
	.i_cen				(~i_addr[5] & ~i_addr[4]),
	.i_oen				(~i_addr[5]	& ~i_addr[4]),
	.i_clk				(i_clk					)
	);


	spsram
	#(
	.BW_DATA			(32			),
	.BW_ADDR			(4			)
	)	
	u_spsram_5(
	.o_data				(o_data[64-1:32]		),
	.i_data				(i_data[64-1:32]		),
	.i_addr				(i_addr[3:0]			),
	.i_wen				(i_wen					),
	.i_cen				(~i_addr[5] & i_addr[4]	),
	.i_oen				(~i_addr[5]	& i_addr[4]	),
	.i_clk				(i_clk					)
	);

	spsram
	#(
	.BW_DATA			(32			),
	.BW_ADDR			(4			)
	)	
	u_spsram_6(
	.o_data				(o_data[64-1:32]		),
	.i_data				(i_data[64-1:32]		),
	.i_addr				(i_addr[3:0]			),
	.i_wen				(i_wen					),
	.i_cen				(i_addr[5] & ~i_addr[4]	),
	.i_oen				(i_addr[5] & ~i_addr[4]	),
	.i_clk				(i_clk					)
	);

	spsram
	#(
	.BW_DATA			(32			),
	.BW_ADDR			(4			)
	)	
	u_spsram_7(
	.o_data				(o_data[64-1:32]		),
	.i_data				(i_data[64-1:32]		),
	.i_addr				(i_addr[3:0]			),
	.i_wen				(i_wen					),
	.i_cen				(i_addr[5] & i_addr[4]	),
	.i_oen				(i_addr[5] & i_addr[4]	),
	.i_clk				(i_clk					)
	);


endmodule

