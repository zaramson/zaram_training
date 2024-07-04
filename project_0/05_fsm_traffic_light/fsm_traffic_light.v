// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: fsm_traffic_light.v
//	* Date			: 2024-07-02 09:57:22
//	* Description	:
// ==================================================

module fsm_traffic_light 
(
	output	reg	[1:0]	o_LA,
	output	reg	[1:0]	o_LB,
	output	reg			o_M,
	input				i_TA,
	input				i_TB,
	input				i_P,
	input				i_R,
	input				i_clk,
	input				i_rstn
);

	reg	[2:0]	L_cState;
	reg	[2:0]	M_cState;
	reg	[1:0]	L_nState;
	reg	[1:0]	M_nState;


	//===================
	// (Mode FSM)
	//===================

	//States 
	localparam	MS0	=	2'b00;
    localparam	MS1 =	2'b01;

	//State Register
	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			M_cState	<= MS0;
		end else begin
			M_cState	<= M_nState;
		end
	end

	//'Next State' Comb. logic
	always @(*) begin
		case (M_cState)
			MS0 : begin
				if (!i_P) begin
					M_nState = MS0;
				end else begin
					M_nState = MS1;
				end
			end
            MS1 : begin
				if (!i_R) begin
					M_nState = MS1;
				end else begin
					M_nState = MS0;
				end
			end
		endcase
	end



	//'Output' Comb. Logic
	always @(*) begin
		case(M_cState)
			MS0	: o_M = 1'b0;
			LS1	: o_M = 1'b1;
		endcase
	end

	//===================
	// (Lights FSM)
	//===================

	//States
	localparam	LS0	=	3'b000;
	localparam	LS1 =	3'b001;
	localparam	LS2 =	3'b010;
	localparam	LS3	=	3'b011;

	//Light outputs
	localparam	GREEN	= 2'b00;
	localparam	RED		= 2'b01;
	localparam	YELLOW	= 2'b10;

	//State Register
	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			L_cState	<= LS0;
		end else begin
			L_cState	<= L_nState;
		end
	end

	//'Next State' Comb. logic
	always @(*) begin
		case (L_cState)
			LS0 : begin
				if (i_TA) begin
					L_nState = LS0;
				end else begin
					L_nState = LS1;
				end
			end
            LS1 : L_nState = LS2;
            LS2 : begin
				if (o_M | i_TB) begin
					L_nState = LS2;
				end else begin
					L_nState = LS3;
				end
			end
            LS3 : L_nState = LS0;
		endcase
	end


	//'Output' Comb. Logic
	always @(*) begin
		case(L_cState)
			LS0	:	begin
				o_LA = GREEN;
				o_LB = RED;
			end
			LS1	:	begin
				o_LA = YELLOW;
				o_LB = RED;
			end
			LS2	:	begin
				o_LA = RED;
				o_LB = GREEN;
			end
			LS3	:	begin
				o_LA = RED;
				o_LB = YELLOW;
			end
		endcase
	end


	//DEBUG
	`ifdef DEBUG
		reg [32*8-1:0]	L_stateMonitor;
		always @(*) begin
			case(L_cState)
			LS0:	L_stateMonitor	=	"LS0";
            LS1:	L_stateMonitor	=	"LS1";
            LS2:	L_stateMonitor	=	"LS2";
            LS3:	L_stateMonitor	=	"LS3";
			endcase
		end

		reg [32*8-1:0]	M_stateMonitor;
		always @(*) begin
			case(M_cState)
			MS0:	M_stateMonitor	=	"MS0";
            MS1:	M_stateMonitor	=	"MS1";
			endcase
		end

		reg [32*8-1:0]	o_LA_colorMonitor;
		always @(*) begin
			case(o_LA)
			GREEN	:	o_LA_colorMonitor	=	"GREEN";
            RED		:	o_LA_colorMonitor	=	"RED";
            YELLOW	:	o_LA_colorMonitor	=	"YELLOW";
			endcase
		end

		reg [32*8-1:0]	o_LB_colorMonitor;
		always @(*) begin
			case(o_LB)
			GREEN	:	o_LB_colorMonitor	=	"GREEN";
            RED		:	o_LB_colorMonitor	=	"RED";
            YELLOW	:	o_LB_colorMonitor	=	"YELLOW";
			endcase
		end
	`endif
	

endmodule
