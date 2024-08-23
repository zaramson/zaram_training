

module riscv_mux21 #(
	`include	"riscv_param.v"
)
(
	output	reg		[XLEN-1:0] 	o_mux21_out,
	input	wire	[XLEN-1:0] 	i_mux21_a,
	input	wire	[XLEN-1:0] 	i_mux21_b,
	input	wire	 			i_mux21_sel
);


	always @(*)	begin
		case (i_mux21_sel)
			1'b0 	:	o_mux21_out = i_mux21_a;
			1'b1 	:	o_mux21_out = i_mux21_b;
			default :	o_mux21_out = 32'dx;
		endcase
	end


endmodule


