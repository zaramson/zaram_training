
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	50	// Sim. Cycles
`define UPBND		15

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"upcnt.v"

module upcnt_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire		[$clog2(`UPBND+1)-1:0]	o_cnt;
	reg									i_clk;
	reg									i_rstn;

	upcnt
	#(
	.UPBND				(`UPBND				)
	)
	u_upcnt(
	.o_cnt				(o_cnt				),
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
	integer			err = 0;

	task init;
		begin
			taskState	= "Init";
			i_clk		= 0;
			i_rstn		= 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input	[9:0]	n;
		begin
			taskState		= "Reset";
			#(n*1000/`CLKFREQ);
			i_rstn = 1;
			taskState		= "";
		end
	endtask
// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		resetReleaseAfterNCycles(4);

		for (i=0; i<`SIMCYCLE; i++) begin
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
			$dumpfile("upcnt_tb.vcd");
			$dumpvars;
		end
	end

endmodule




