// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: BS_rotate_right.v
//	* Date			: 2024-06-25 14:12:01
//	* Description	:
// ==================================================

module BS_rotate_right 
(
    input 		[3:0] i_A,
    input 		[1:0] i_k,
    output reg	[3:0] o_Y
);
	
    
    always @(*) begin
        case (i_k)
            2'b00: 		o_Y = i_A;
            2'b01: 		o_Y = {i_A[0], i_A[3:1]};       // Rotate right 1
            2'b10: 		o_Y = {i_A[1:0], i_A[3:2]};     // Rotate right 2
            2'b11: 		o_Y = {i_A[2:0], i_A[3]};       // Rotate right 3
            default:	o_Y = i_A;
        endcase
    end
endmodule

