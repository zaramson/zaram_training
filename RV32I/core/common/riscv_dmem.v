// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_dmem.v
//	* Date			: 2024-07-18 17:33:32
//	* Description	:
// ==================================================


`include	"riscv_configs.v"

module riscv_dmem
(	
	output		[         `XLEN-1:0]	o_dmem_data,
	input		[         `XLEN-1:0]	i_dmem_data,
	input		[`DMEM_ADDR_BIT-3:0]	i_dmem_addr,
	input		[       `XLEN/8-1:0]	i_dmem_byte_sel,
	input								i_dmem_wr_en,
	input								i_clk
);

	reg			[`XLEN-1:0]	dmem_arr[0:2**(`DMEM_ADDR_BIT-2)-1];

`ifdef	DMEM_INIT
	initial		$readmemh(`DMEM_INIT_FILE, dmem_arr);
`endif

	//	Memory Read (output is not switching during write)
	assign		o_dmem_data = (i_dmem_wr_en) ? o_dmem_data : dmem_arr[i_dmem_addr];

	//	Memory Write (to support sb, sh, sw)
	//		- i_dmem_byte_sel = sb: 4'b0001, sh: 4'b0011, sw: 4'b1111
	integer		i;
	always @(posedge i_clk) begin
		if (i_dmem_wr_en) begin
			for (i=0; i<`XLEN/8; i++) begin
				if (i_dmem_byte_sel[i]) begin
					dmem_arr[i_dmem_addr][8*i+:8] <= i_dmem_data[8*i+:8];
				end
			end
		end else begin
			dmem_arr[i_dmem_addr] <= dmem_arr[i_dmem_addr];
		end
	end

endmodule
