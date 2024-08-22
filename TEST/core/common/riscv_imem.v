

module riscv_imem #(
	`include "riscv_param.v"
)
(
	output	reg		[XLEN-1:0]				o_imem_instr,
	input	wire	[IMEM_ADDR_BIT-2-1:0]	i_imem_addr
);

	reg		[XLEN-1:0]	imem_arr[0:2**(IMEM_ADDR_BIT-2)-1];

`ifdef	IMEM_INIT
	reg	[8*128-1:0] IMEM_INIT_FILE;
	initial	begin
		$value$plusargs("text_mif=%s", IMEM_INIT_FILE);
		$readmemh(IMEM_INIT_FILE, imem_arr);
	end
`endif

	assign	o_imem_instr = imem_arr[i_imem_addr];

endmodule
