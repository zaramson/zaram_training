

module riscv_mux31 #(
	`include "riscv_param.v"
)
(
	output	reg		[XLEN-1:0]	o_mux31_out,
	input	wire	[XLEN-1:0]	i_mux31_a,
	input	wire	[XLEN-1:0]	i_mux31_b,
	input	wire	[XLEN-1:0]	i_mux31_c,
	input	wire	[2-1:0]		i_mux31_sel

);

	always @(*) begin
		case (i_mux31_sel)
			2'b00	: o_mux31_out = i_mux31_a;
			2'b01	: o_mux31_out = i_mux31_b;
			2'b10 	: o_mux31_out = i_mux31_c;
			default : o_mux31_out = 32'dx;
		endcase
	end

endmodule
