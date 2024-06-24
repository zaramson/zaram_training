// ==================================================
//	[ VLSISYS Lab. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: gray_cc_tb.v
//	* Date			: 2024-06-24 11:28:06
//	* Description	: 
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define BW_DATA		3		// Bitwidth of ~~
`define NVEC		100		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"gray_cc.v"

module gray_cc_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg		[2:0]	i_binary;
	wire	[2:0]	o_gray;

	gray_cc
	u_gray_cc(
	.i_binary			(i_binary			),
	.o_gray				(o_gray				)
	);

// ----------------------------------
// Tasks
// ----------------------------------
	task init;
		begin
			i_binary	= 0;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i;
	initial begin
		init();
		for (i=0; i<`SIMCYCLE; i++) begin
			{i_binary} =  $urandom_range(0, 2**`BW_DATA-1);
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
			$dumpfile("gray_cc_tb.vcd");
			$dumpvars;
		end
	end

endmodule
