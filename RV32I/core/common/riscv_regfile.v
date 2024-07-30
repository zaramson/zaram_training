// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: Woong Choi (woongchoi@sm.ac.kr)
//	* Filename		: riscv_regfile.v
//	* Description	: Register File for RV32I
// ==================================================

`ifndef		NOINC
`include	"riscv_configs.v"
`endif

module riscv_regfile
(
	output		[`XLEN-1:0]		o_regfile_rs1_data,
	output		[`XLEN-1:0]		o_regfile_rs2_data,
	input		[      4:0]		i_regfile_rs1_addr,
	input		[      4:0]		i_regfile_rs2_addr,
	input		[`XLEN-1:0]		i_regfile_rd_data,
	input		[      4:0]		i_regfile_rd_addr,
	input						i_regfile_rd_wen,
	input						i_clk
);

	// 32 base registers
	reg			[`XLEN-1:0]	registers[0:31];

	// Read ports for rs1 & rs2
	assign		o_regfile_rs1_data = registers[i_regfile_rs1_addr];
	assign		o_regfile_rs2_data = registers[i_regfile_rs2_addr];

	// Hardwired X0
	initial		registers[0] = `XLEN'b0;

	always @(posedge i_clk) begin
		//	"Write Enabled" and  "Write Address != 0"
		if (i_regfile_rd_wen && (i_regfile_rd_addr != 0)) begin
			registers[i_regfile_rd_addr] <= i_regfile_rd_data;
		//	Hold Data
		end else begin
			registers[i_regfile_rd_addr] <= registers[i_regfile_rd_addr];
		end
	end

endmodule
