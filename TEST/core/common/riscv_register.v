

module riscv_register #(
	`include "riscv_param.v"
)
(
	output	reg		[XLEN-1:0]	o_register_out,
	input	wire	[XLEN-1:0]	i_register_in,
	input	wire				i_register_clk,
	input	wire				i_register_en,
	input	wire				i_register_rstn
);


	always @ (posedge i_register_clk or negedge i_register_rstn) begin
		if (!i_register_rstn) begin
			o_register_out <= 0;
		end else begin 
			if (i_register_en) begin
			o_register_out <= i_register_in;
			end	else begin
			o_register_out <= o_register_out;
			end
		end
	end

endmodule
