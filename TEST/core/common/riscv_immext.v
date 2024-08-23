

module riscv_immext #(
	`include "riscv_param.v"
)
(
	output	reg		[XLEN-1:0]	o_immext_out,
	input	wire	[XLEN-1:0]	i_immext_instr,
	input	wire	[3-1:0]		i_immext_src
);


// Instruction Format
// R, I, S, B, U, J type
// default : R type

	always @(*) begin
		case(i_immext_src) 
			SRC_IMM_I	: o_immext_out	= {{20{i_immext_instr[31   ]}}, i_immext_instr[31:20]														};  
			SRC_IMM_S	: o_immext_out	= {{20{i_immext_instr[31   ]}}, i_immext_instr[31:25], i_immext_instr[11: 7]								}; 
			SRC_IMM_B	: o_immext_out	= {{20{i_immext_instr[31   ]}}, i_immext_instr[7    ], i_immext_instr[30:25], i_immext_instr[11: 8], 1'b0	}; 
			SRC_IMM_U	: o_immext_out	= {    i_immext_instr[31:12]  , 12'b0																}; 
			SRC_IMM_J	: o_immext_out	= {{12{i_immext_instr[31   ]}}, i_immext_instr[19:12], i_immext_instr[20   ], i_immext_instr[30:21], 1'b0	}; 
			default		: o_immext_out	= {32{1'bx}};
		endcase             
	end

endmodule
