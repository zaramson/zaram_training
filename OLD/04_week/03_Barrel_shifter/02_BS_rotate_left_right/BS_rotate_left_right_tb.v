// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: BS_rotate_left_right_tb.v
//	* Date			: 2024-06-26 10:09:08
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
`include	"BS_rotate_left_right.v"

module BS_rotate_left_right_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg 		[3:0] 	i_A;
	reg 		[1:0] 	i_k;
	reg 				i_left;
	wire		[3:0] 	o_Y;

	BS_rotate_left_right
	u_BS_rotate_left_right(
	.i_A				(i_A				),
	.i_k				(i_k				),
	.i_left				(i_left				),
	.o_Y				(o_Y				)
	);

// ----------------------------------
// Task
// ----------------------------------
	reg [8*32-1:0] taskState;

	task init;
		begin
			taskState	= "Init";
			i_A			= 0;
			i_k			= 0;
			i_left		= 0;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();

		i_left	=	1;
		taskState	= "Rotate_left";

		for (i=0; i<`SIMCYCLE; i++) begin
			i_A = $urandom;
			i_k = $urandom;
			#(1000/`CLKFREQ);
		end

		i_left	=	0;
		taskState	= "Rotate_right";
		
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
			$dumpfile("BS_rotate_left_right_tb.vcd");
			$dumpvars;
		end
	end

endmodule


