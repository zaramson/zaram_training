// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: BS_masking.v
//	* Date			: 2024-06-25 17:17:23
//	* Description	:
// ==================================================

module BS_masking 
(
	output	[3:0]	o_Y,
	input	[3:0]	i_X,
	input	[2:0]	i_mask,
	input			i_shift,
	input			i_left,
	input			i_arith,
	input			i_MSB
);
	
	wire	w_left;
	wire	w_right;
	wire	w_mask_left;
	wire	w_mask_right;
	wire	w_kill;
	wire	w_signext;
	wire	w_mask_signext;
	wire	w_X_kill;

	assign	w_left			=	i_shift 		& 	i_left;
	assign	w_right			=	i_shift 		& 	~i_left;
	assign	w_mask_left 	= 	~(i_mask		&	w_left);
	assign	w_mask_right 	= 	~(i_mask		&	w_right);
	assign	w_kill			=	~w_mask_left	|	~w_mask_right;	
	assign	w_signext		=	i_arith			&	i_MSB;
	assign	w_mask_signext	=	~(i_mask		&	w_signext);
	assign	w_X_kill		=	~i_X			&	~w_kill;
	assign	o_Y				=	~w_mask_signext	|	w_X_kill;	

endmodule
