

module riscv_regfile #(
	`include "riscv_param.v"
)
(
	output	wire	[XLEN-1:0]	o_regfile_rs1_out,
	output	wire	[XLEN-1:0]	o_regfile_rs2_out,
	input	wire	[5-1:0	 ]	i_regfile_rs1_addr,
	input	wire	[5-1:0	 ]	i_regfile_rs2_addr,
	input	wire	[5-1:0	 ]	i_regfile_wr_addr,
	input	wire	[XLEN-1:0]	i_regfile_wr_data,
	input	wire				i_regfile_wen,
	input	wire				i_regfile_clk
);

	// 32-bit 32 registers
	reg		[XLEN-1:0]	registers[0:31];


	// Read
	assign	o_regfile_rs1_out = registers[i_regfile_rs1_addr];
	assign	o_regfile_rs2_out = registers[i_regfile_rs2_addr];

	// Hardwired reigster[0] = 0
	initial	registers[0] = 32'd0;

	
	// Write
	always @(posedge i_regfile_clk) begin
		if (i_regfile_wen && (i_regfile_wr_addr != 0)) begin
			registers[i_regfile_wr_addr] <= i_regfile_wr_data;
		end else begin
			registers[i_regfile_wr_addr] <= registers[i_regfile_wr_addr];
		end
	end

endmodule
