// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: adder_cla_tb.v
//	* Date			: 2024-07-01 14:54:12
//	* Description	:
// ==================================================

// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define BW_DATA		32		// Bitwidth of ~~
`define NVEC		10		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"adder_cla.v"

module adder_cla_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	wire	[32-1:0]		o_S;
	wire					o_Cout;
	reg		[32-1:0]		i_A;
	reg		[32-1:0]		i_B;
	reg						i_Cin;

	adder_cla32
	u_adder_cla32(
	.o_S				(o_S				),
	.o_Cout				(o_Cout				),
	.i_A				(i_A				),
	.i_B				(i_B				),
	.i_Cin				(i_Cin				)
	);

// --------------------------------------------------
//	Test Vector Configuration
// --------------------------------------------------
	reg		[`BW_DATA-1:0]	vo_s[0:`NVEC-1];
	reg						vo_c[0:`NVEC-1];
	reg		[`BW_DATA-1:0]	vi_a[0:`NVEC-1];
	reg		[`BW_DATA-1:0]	vi_b[0:`NVEC-1];
	reg						vi_c[0:`NVEC-1];

	initial begin
		$readmemb("./vec/o_s.vec",			vo_s);
		$readmemb("./vec/o_c.vec",			vo_c);
		$readmemb("./vec/i_a.vec",			vi_a);
		$readmemb("./vec/i_b.vec",			vi_b);
		$readmemb("./vec/i_c.vec",			vi_c);
	end

// ----------------------------------
// Tasks
// ----------------------------------
	reg [8*32-1:0] 	taskState;
	reg 			err;

	task init;
		begin
			taskState	= "Init";
			err			= 0;
			i_A  		= 0;
			i_B  		= 0;
			i_Cin		= 0;
		end
	endtask

	task vecInsert;
		input	[$clog2(`NVEC)-1:0]	i;
		begin
			$sformat(taskState,	"VEC[%3d]", i);
			i_A				= vi_a[i];
			i_B				= vi_b[i];
			i_Cin			= vi_c[i];
		end
	endtask

	task vecVerify;
		input	[$clog2(`NVEC)-1:0]	i;
		begin
			#(0.1*1000/`CLKFREQ);
			if (o_S				!= vo_s[i]) begin $display("[Idx: %3d] Mismatched o_S", i); end
			if (o_Cout			!= vo_c[i]) begin $display("[Idx: %3d] Mismatched o_Cout", i); end
			if ((o_S != vo_s[i]) || (o_Cout != vo_c[i])) begin err++; end
			#(0.9*1000/`CLKFREQ);
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
			vecInsert(i);
			vecVerify(i);			
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
			$dumpfile("adder_cla_tb.vcd");
			$dumpvars;
		end
	end

endmodule
