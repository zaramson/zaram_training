// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: BS_rotate_right_tb.v
//	* Date			: 2024-06-25 14:28:48
//	* Description	:
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	50	// Sim. Cycles

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"BS_rotate_right.v"

module BS_rotate_right_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg 		[3:0] i_A;
	reg 		[1:0] i_k;
	wire		[3:0] o_Y;

	BS_rotate_right
	u_BS_rotate_right(
	.i_A				(i_A				),
	.i_k				(i_k				),
	.o_Y				(o_Y				)
	);

// ----------------------------------
// Task
// ----------------------------------
	reg [8*32-1:0] taskState;

	task init;
		begin
			i_A			= 0;
			i_k			= 0;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();

		for (i=0; i<`SIMCYCLE; i++) begin
			i_A = $urandom;
			i_k = $urandom;
			#(1000/`CLKFREQ);
		end
		$finish;
	end

// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------
	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end else begin
			$dumpfile("BS_rotate_right_tb.vcd");
			$dumpvars;
		end
	end

endmodule


