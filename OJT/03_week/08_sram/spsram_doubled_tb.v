// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: spsram_doubled_tb.v
//	* Date			: 2024-06-26 15:12:43
//	* Description	:
// ==================================================


// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	32	// Sim. Cycles
`define BW_DATA		32		// Bitwidth of ~~
`define BW_ADDR		5		// Bitwidth of ~~

`define SPSRAM_ASYNC

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"spsram_doubled.v"

module spsram_doubled_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire	[`BW_DATA-1:0]	o_data;
	reg		[`BW_DATA-1:0]	i_data;
	reg		[`BW_ADDR-1:0]	i_addr;
	reg						i_wen;
	reg						i_cen;
	reg						i_oen;
	reg						i_clk;

	spsram_doubled
	#(
	.BW_DATA			(`BW_DATA			),
	.BW_ADDR			(`BW_ADDR			)
	)
	u_spsram_doubled(
	.o_data				(o_data				),
	.i_data				(i_data				),
	.i_addr				(i_addr				),
	.i_wen				(i_wen				),
	.i_cen				(i_cen				),
	.i_oen				(i_oen				),
	.i_clk				(i_clk				)
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
			i_data  	= 0;
			i_addr  	= 0;
			i_wen		= 0;
			i_cen		= 0;
			i_oen		= 0;
			i_clk		= 0;
		end
	endtask

	task memWR;
		input	[`BW_ADDR-1:0]	ti_addr;
		input	[`BW_DATA-1:0]	ti_data;
		begin
			@(negedge i_clk) begin
				taskState	= "WR";
				i_data		= ti_data;
				i_addr		= ti_addr;
				i_wen		= 1;
				i_cen		= 1;
				i_oen		= 0;
			end
		end
	endtask

	task memRD;
		input	[`BW_ADDR-1:0] ti_addr;
		begin
			@(negedge i_clk) begin
				taskState	= "RD";
				i_addr		= ti_addr;
				i_wen		= 0;
				i_cen		= 1;
				i_oen		= 1;
			end
		end
	endtask


// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		#(4*1000/`CLKFREQ);

		for (i=0; i<`SIMCYCLE; i++) begin
			memWR(i, i);
		end
		for (i=0; i<`SIMCYCLE; i++) begin
			memRD(i);
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
			$dumpfile("spsram_doubled_tb.vcd");
			$dumpvars;
		end
	end

endmodule
