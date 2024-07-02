module seq_detect_mealy 
(
	output	reg		o_out,
	input			i_seq,
	input			i_clk,
	input			i_rstn
);
	
	reg	[2:0]	cState;
	reg	[2:0]	nState;
	reg			seq;

	//States
	localparam	S_IDLE	=	3'b000;
	localparam	S_H		=	3'b001;
	localparam	S_HL	=	3'b010;
	localparam	S_HLH	=	3'b011;


	//State Register
	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			cState	<= S_IDLE;
			seq		<= 1'b0;
		end else begin
			cState	<= nState;
			seq		<= i_seq;
		end
	end

	//'Next State' Comb. logic
	always @(*) begin
		if(seq == 1'b0) begin
			case(cState)
				S_IDLE	:	nState	=	S_IDLE;
				S_H	  	:	nState	=	S_HL;
				S_HL  	:	nState	=	S_IDLE;
				S_HLH 	:	nState	=	S_HL;
			endcase
		end else begin
			case(cState)
				S_IDLE	:	nState	=	S_H;
                S_H	  	:	nState	=	S_H;
                S_HL  	:	nState	=	S_HLH;
                S_HLH 	:	nState	=	S_H;
			endcase
		end
	end

	//'Output' Comb. Logic
	always @(*) begin
		case(cState)
			S_HLH	:	o_out	= (seq) ? 1'b1 : 1'b0;
			default	:	o_out	= 1'b0;
		endcase
	end

	//DEBUG
	`ifdef DEBUG
		reg [32*8-1:0]	stateMonitor;
		always @(*) begin
			case(cState)
			S_IDLE	:	stateMonitor	=	"S_IDLE";
            S_H	  	:	stateMonitor	=	"S_H";
            S_HL  	:	stateMonitor	=	"S_HL";
            S_HLH 	:	stateMonitor	=	"S_HLH";
			endcase
		end
	`endif


endmodule
