
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	50	// Sim. Cycles
`define DEBUG

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"seq_detect_mealy.v"

module seq_detect_mealy_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire			o_out;
	reg				i_seq;
	reg				i_clk;
	reg				i_rstn;

	seq_detect_mealy
	u_seq_detect_mealy(
	.o_out				(o_out				),
	.i_seq				(i_seq				),
	.i_clk				(i_clk				),
	.i_rstn				(i_rstn				)
	);



// ----------------------------------
// Clock
// ----------------------------------
	always	#(500/`CLKFREQ) i_clk = ~ i_clk;

// ----------------------------------
// Tasks
// ----------------------------------
	reg [8*32-1:0] 	taskState;

	task init;
		begin
			taskState	= "Init";
			i_seq		= 0;
			i_clk		= 0;
			i_rstn		= 0;
		end
	endtask

	task resetNCycles;
		input	[9:0]	n;
		begin
			taskState		= "Reset_ON";
			#(n*1000/`CLKFREQ);
			i_rstn = 1;
			taskState		= "Reset_OFF";
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		resetNCycles(4);

		for (i=0; i<`SIMCYCLE; i++) begin
			i_seq	= $urandom_range(0,1);
			#(1000/`CLKFREQ);
		end
		#(1000/`CLKFREQ);
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
			$dumpfile("seq_detect_mealy_tb.vcd");
			$dumpvars;
		end
	end

endmodule




