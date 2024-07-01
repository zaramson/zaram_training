// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: barrel_shifter_tb.v
//	* Date			: 2024-07-01 10:16:33
//	* Description	:
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	10		// Sim. Cycles

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"barrel_shifter.v"

module barrel_shifter_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire	[7:0]	o_Y;
	reg 	[7:0]	i_A;
	reg		[2:0]	i_k;

	barrel_shifter
	u_barrel_shifter(
	.o_Y				(o_Y				),
	.i_A				(i_A				),
	.i_k				(i_k				)
	);


// ----------------------------------
// Tasks
// ----------------------------------
	reg [8*32-1:0] 	taskState;

	task init;
		begin
			taskState	= "Init";
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
			#(1000/`CLKFREQ);
			taskState	= "ROTATE_0";
			i_k[0]		= 0;
			i_k[1]		= 0;
			i_k[2]		= 0;
			i_A			= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "ROTATE_1";
			i_k[0]		= 1;
			i_k[1]		= 0;
			i_k[2]		= 0;
			i_A			= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "ROTATE_2";
			i_k[0]		= 0;
			i_k[1]		= 1;
			i_k[2]		= 0;
			i_A			= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "ROTATE_3";
			i_k[0]		= 1;
			i_k[1]		= 1;
			i_k[2]		= 0;
			i_A			= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "ROTATE_4";
			i_k[0]		= 0;
			i_k[1]		= 0;
			i_k[2]		= 1;
			i_A			= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "ROTATE_5";
			i_k[0]		= 1;
			i_k[1]		= 0;
			i_k[2]		= 1;
			i_A			= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "ROTATE_6";
			i_k[0]		= 0;
			i_k[1]		= 1;
			i_k[2]		= 1;
			i_A			= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "ROTATE_7";
			i_k[0]		= 1;
			i_k[1]		= 1;
			i_k[2]		= 1;
			i_A			= $urandom;
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
			$dumpfile("barrel_shifter_tb.vcd");
			$dumpvars;
		end
	end

endmodule
