// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: shift_register_tb.v
//	* Date			: 2024-07-01 17:26:45
//	* Description	:
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	20		// Sim. Cycles
`define BW_DATA		8		// Bitwidth of ~~

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"shift_register.v"

module shift_register_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire					o_Sout;
	wire	[`BW_DATA-1:0]	o_Qout;
	reg		[`BW_DATA-1:0] 	i_D;
	reg						i_Load;
	reg						i_Sin;
	reg						i_Clk;

	shift_register
	u_shift_register(
	.o_Sout				(o_Sout				),
	.o_Qout				(o_Qout				),
	.i_D				(i_D				),
	.i_Load				(i_Load				),
	.i_Sin				(i_Sin				),
	.i_Clk				(i_Clk				)
	);


// ----------------------------------
// Clock
// ----------------------------------
	always	#(500/`CLKFREQ) i_Clk = ~ i_Clk;

// ----------------------------------
// Tasks
// ----------------------------------
	reg [8*32-1:0] 	taskState;

	task init;
		begin
			taskState	= "Init";
			i_D  		= 0;
			i_Load 		= 0;
			i_Sin		= 0;
			i_Clk		= 0;
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
			taskState	= "Serial-to-Parallel";
			i_Load 		= 0;
			i_D			= $urandom;
			i_Sin		= $urandom;
		end

			#(1000/`CLKFREQ);
			taskState	= "Input Parallel Data";
			i_Load 		= 1;
			i_D			= $urandom;
			i_Sin		= $urandom;

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "Parallel-to-Serial";
			i_Load 		= 0;
			i_D			= $urandom;
			i_Sin		= $urandom;
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
			$dumpfile("shift_register_tb.vcd");
			$dumpvars;
		end
	end

endmodule
