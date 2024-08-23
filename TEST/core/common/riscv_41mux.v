

module riscv_mux41 #(
`include "riscv_param.v"
)
(
	output	reg		[XLEN-1:0]	o_mux41_out,
	input	wire	[XLEN-1:0]	i_mux41_a,
	input	wire	[XLEN-1:0]	i_mux41_b,
	input	wire	[XLEN-1:0]	i_mux41_c,
	input	wire	[XLEN-1:0]	i_mux41_d,
	input	wire	[2-1:0]		i_mux41_sel
);


	always @(*) begin
		case (i_mux41_sel)
			2'b00 	: o_mux41_out = i_mux41_a;
			2'b01 	: o_mux41_out = i_mux41_b;
			2'b10 	: o_mux41_out = i_mux41_c;
			2'b11 	: o_mux41_out = i_mux41_d;
			default : o_mux41_out = 32'dx;
		endcase
	end

endmodule
