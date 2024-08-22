// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: Woong Choi (woongchoi@sm.ac.kr)
//	* Filename		: riscv_imem.v
//	* Description	: Instruction Memory
// ==================================================

`ifndef		NOINC
`include	"riscv_configs.v"
`endif

module riscv_imem
(	
	output		[         `XLEN-1:0]	o_imem_data,
	input		[`IMEM_ADDR_BIT-3:0]	i_imem_addr
);

	reg			[`XLEN-1:0]	imem_arr[0:2**(`IMEM_ADDR_BIT-2)-1];

//`ifdef	IMEM_INIT
//	reg	[8*128-1:0] IMEM_INIT_FILE;
//	initial	begin
//		$value$plusargs("text_mif=%s", IMEM_INIT_FILE);
//		$readmemh(IMEM_INIT_FILE, imem_arr);
//	end
//`endif

`ifdef	IMEM_INIT
	initial	$readmemh(`IMEM_INIT_FILE, imem_arr);
`endif

	assign		o_imem_data = imem_arr[i_imem_addr];

endmodule
