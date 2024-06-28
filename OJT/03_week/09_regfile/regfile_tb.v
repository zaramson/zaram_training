// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: regfile_tb.v
//	* Date			: 2024-06-26 15:49:01
//	* Description	:
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100			// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	2**`BW_ADDR	// Sim. Cycles
`define BW_DATA		16			// Bitwidth of ~~
`define BW_ADDR		4			// Bitwidth of ~~
//`define MEM_INIT

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"regfile.v"

module regfile_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire	[`BW_DATA-1:0]	o_rf_rd_data0;
	wire	[`BW_DATA-1:0]	o_rf_rd_data1;
	reg		[`BW_ADDR-1:0]	i_rf_rd_addr0;
	reg		[`BW_ADDR-1:0]	i_rf_rd_addr1;
	reg		[`BW_DATA-1:0]	i_rf_wr_data;
	reg		[`BW_ADDR-1:0]	i_rf_wr_addr;
	reg						i_rf_wr_en;
	reg						i_clk;

	regfile
	#(
	.BW_DATA			(`BW_DATA			),
	.BW_ADDR			(`BW_ADDR			)
	)
	u_regfile(
	.o_rf_rd_data0		(o_rf_rd_data0		),
	.o_rf_rd_data1		(o_rf_rd_data1		),
	.i_rf_rd_addr0		(i_rf_rd_addr0		),
	.i_rf_rd_addr1		(i_rf_rd_addr1		),
	.i_rf_wr_data		(i_rf_wr_data		),
	.i_rf_wr_addr		(i_rf_wr_addr		),
	.i_rf_wr_en			(i_rf_wr_en			),
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
			i_rf_rd_addr0  	= 0;
			i_rf_rd_addr1  	= 0;
			i_rf_wr_data  	= 0;
			i_rf_wr_addr  	= 0;
			i_rf_wr_en  	= 0;
			i_clk		  	= 0;
		end
	endtask

	task regWR;
		input	[`BW_ADDR-1:0]	ti_rf_wr_addr;
		input	[`BW_DATA-1:0]	ti_rf_wr_data;
		begin
			@(negedge i_clk) begin
				taskState		= "WR";
				i_rf_wr_data	= ti_rf_wr_data;
				i_rf_wr_addr	= ti_rf_wr_addr;
				i_rf_wr_en		= 1;
			end
		end
	endtask

	task regRD;
		input	[`BW_ADDR-1:0]	ti_rf_rd_addr0;
		input	[`BW_ADDR-1:0]	ti_rf_rd_addr1;
		begin
			@(negedge i_clk) begin
				taskState		= "RD";
				i_rf_rd_addr0	= ti_rf_rd_addr0;
				i_rf_rd_addr1	= ti_rf_rd_addr1;
				i_rf_wr_en		= 0;
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
			regWR(i, i);
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			regRD(i, i);
		end

		for (i=0; i<`SIMCYCLE; i++) begin
			regWR(i, $urandom_range(0, 2**`BW_DATA-1));
			#(1000/`CLKFREQ);
			regRD(i, i);
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
			for (i=0; i<2**`BW_ADDR; i++) begin
				$dumpvars(0, u_regfile.rf_arr[i]);
			end
			$dumpvars;
		end else begin
			$dumpfile("regfile_tb.vcd");
			$dumpvars;
		end
	end

endmodule
