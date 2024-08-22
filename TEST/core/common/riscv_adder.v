


module riscv_adder #(
	`include "riscv_param.v"
)
(
	output 	wire		[XLEN-1:0]	o_adder_sum,
	input 	wire		[XLEN-1:0]	i_adder_a,
	input 	wire		[XLEN-1:0]	i_adder_b
);

	assign	o_adder_sum = i_adder_a + i_adder_b;

endmodule
