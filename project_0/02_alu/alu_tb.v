// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: alu_tb.v
//	* Date			: 2024-07-01 15:50:14
//	* Description	:
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	5		// Sim. Cycles
`define BW_DATA		4

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"alu.v"

module alu_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire	[`BW_DATA-1:0]	o_Y;
	wire					o_Cout;
	reg		[`BW_DATA-1:0]	i_A;
	reg		[`BW_DATA-1:0]	i_B;
	reg		[2:0]			i_F;

	alu
	#(
	.BW_DATA			(`BW_DATA			)
	)
	u_alu(
	.o_Y				(o_Y				),
	.o_Cout				(o_Cout				),
	.i_A				(i_A				),
	.i_B				(i_B				),
	.i_F				(i_F				)
	);



// ----------------------------------
// Tasks
// ----------------------------------
	reg [8*32-1:0] 	taskState;

	task init;
		begin
			taskState	= "Init";
			i_A  		= 0;
			i_B  		= 0;
			i_F			= 0;
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
			taskState	= "A & B";
            i_F	= 3'b000;
			i_A	= $urandom;
            i_B	= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "A | B";
            i_F	= 3'b001;
			i_A	= $urandom;
            i_B	= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "A + B";
            i_F	= 3'b010;
			i_A	= $urandom;
            i_B	= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "not used";
            i_F	= 3'b011;
			i_A	= $urandom;
            i_B	= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "A & ~B";
            i_F	= 3'b100;
			i_A	= $urandom;
            i_B	= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "A | ~B";
            i_F	= 3'b101;
			i_A	= $urandom;
            i_B	= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "A - B";
            i_F	= 3'b110;
			i_A	= $urandom;
            i_B	= $urandom;
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
			taskState	= "SLT";
            i_F	= 3'b111;
			i_A	= $urandom;
            i_B	= $urandom;
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
			$dumpfile("alu_tb.vcd");
			$dumpvars;
		end
	end

endmodule
