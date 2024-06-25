// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: upcnt.v
//	* Date			: 2024-06-25 10:54:04
//	* Description	:
// ==================================================


module updw_cnt 
#(
	parameter	UPBND	= 31
)
(
	output	reg	[$clog2(UPBND+1)-1:0]	o_cnt,
	input								i_mode,
	input								i_clk,
	input								i_rstn
);
	
	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_cnt <= 0;
		end else begin
			if (i_mode) begin
				if (o_cnt == UPBND) begin
					o_cnt <= 0;
				end else begin
					o_cnt <= o_cnt + 1;
				end
			end	else begin
				if (o_cnt == 0)	begin
					o_cnt <= UPBND;
				end	else begin
					o_cnt <= o_cnt - 1;
				end
			end
		end
	end

endmodule
