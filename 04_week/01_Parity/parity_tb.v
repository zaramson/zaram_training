// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: parity_tb.v
//	* Date			: 2024-06-25 10:40:24
//	* Description	:
// ==================================================


// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define BW_DATA		8		// Bitwidth of ~~
`define NVEC		100		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"parity.v"

module parity_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg	[`BW_DATA-1:0]		i_A;
	wire					o_Y;

	parity
	#(
	.BW_DATA			(`BW_DATA			)
	)
	u_parity(
	.i_A				(i_A				),
	.o_Y				(o_Y				)
	);

// ----------------------------------
// Tasks
// ----------------------------------
	task init;
		begin
			i_A	= 0;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i;
	initial begin
		init();
		for (i=0; i<`SIMCYCLE; i++) begin
			{i_A} =  $urandom_range(0, 2**`BW_DATA-1);
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
			$dumpfile("parity_tb.vcd");
			$dumpvars;
		end
	end

endmodule




