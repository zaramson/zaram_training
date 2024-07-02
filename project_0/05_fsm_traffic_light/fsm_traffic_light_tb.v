// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: fsm_traffic_light_tb.v
//	* Date			: 2024-07-02 11:39:35
//	* Description	:
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	50		// Sim. Cycles
`define DEBUG


// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"fsm_traffic_light.v"

module fsm_traffic_light_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire		[1:0]	o_LA;
	wire		[1:0]	o_LB;
	wire				o_M;
	reg					i_TA;
	reg					i_TB;
	reg					i_P;
	reg					i_R;
	reg					i_clk;
	reg					i_rstn;

	fsm_traffic_light
	u_fsm_traffic_light(
	.o_LA				(o_LA				),
	.o_LB				(o_LB				),
	.o_M				(o_M				),
	.i_TA				(i_TA				),
	.i_TB				(i_TB				),
	.i_P				(i_P				),
	.i_R				(i_R				),
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
			i_TA		= 0;
			i_TB		= 0;
			i_P			= 0;
			i_R			= 0;
			i_clk		= 0;
			i_rstn		= 0;
		end
	endtask

	task resetNCycle;
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
		resetNCycle(4);

		for (i=0; i<`SIMCYCLE; i++) begin
			i_TA	= $urandom_range(0,1);
			i_TB	= $urandom_range(0,1);
			i_P		= $urandom_range(0,1);
			i_R		= $urandom_range(0,1);
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
			$dumpfile("fsm_traffic_light_tb.vcd");
			$dumpvars;
		end
	end

endmodule
