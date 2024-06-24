
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	50	// Sim. Cycles

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"posedge_vs_negedge.v"

module posedge_vs_negedge_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire	o_q_neg;
	wire	o_q_pos;
	reg		i_d;
	reg		i_clk;
	reg		i_rstn;

	dff_neg
	u_dff_neg(
	.o_q				(o_q_neg				),
	.i_d				(i_d					),
	.i_clk				(i_clk					),
	.i_rstn				(i_rstn					)
	);

	dff_pos
	u_dff_pos(
	.o_q				(o_q_pos					),
	.i_d				(i_d						),
	.i_clk				(i_clk						),
	.i_rstn				(i_rstn						)
	);


// ----------------------------------
// Clock
// ----------------------------------
	always	#(500/`CLKFREQ) i_clk = ~ i_clk;

// ----------------------------------
// Tasks
// ----------------------------------
	task init;
		begin
			i_d		= 0;
			i_clk	= 0;
			i_rstn	= 0;
		end
	endtask


	task resetReleaseAfterNCycles;
		input	[9:0]	n;
		begin
			#(n*1000/`CLKFREQ);
			i_rstn = 1'b1;
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
		j		= $urandom_range(0,10);
		#((		(j*0.1)) * 1000/`CLKFREQ);
		i_d 	= $urandom;
		i_rstn 	= $urandom;
		#((	1-	(j*0.1)) * 1000/`CLKFREQ);
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
			$dumpfile("posedge_vs_negedge_tb.vcd");
			$dumpvars;
		end
	end

endmodule




