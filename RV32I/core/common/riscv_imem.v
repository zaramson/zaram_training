// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_imem.v
//	* Date			: 2024-07-18 17:33:56
//	* Description	:
// ==================================================


`include	"riscv_configs.v"

module riscv_imem
(	
	output		[         `XLEN-1:0]	o_imem_data,
	input		[`IMEM_ADDR_BIT-3:0]	i_imem_addr,
	input								i_clk
);

	reg			[`XLEN-1:0]	imem_arr[0:2**(`IMEM_ADDR_BIT-2)-1];

`ifdef	IMEM_INIT
	initial		$readmemh(`IMEM_INIT_FILE, imem_arr);
`endif

	assign		o_imem_data = imem_arr[i_imem_addr];

endmodule
