// ==================================================
//	[ ZARAM OJT. ]
//	* Author		: Seok Jin Son (sonsj98@zaram.com)
//	* Filename		: riscv_de_register.v
//	* Date			: 2024-08-08 09:59:10
//	* Description	:
// ==================================================




`ifndef		NOINC
`include	"../common/riscv_configs.v"
`endif

module riscv_de_register
#(
	parameter	REGISTER_INIT	= 0
)
(	
	output reg	[1:0]			o_de_register_src_pc,
	output reg	[2:0]			o_de_register_src_imm,
	output reg	[1:0]			o_de_register_src_rd,
	output reg					o_de_register_src_alu_a,
	output reg					o_de_register_src_alu_b,
	output reg					o_de_register_reg_wr_en,
	output reg					o_de_register_mem_wr_en,
	output reg	[3:0]			o_de_register_mem_byte_sel,
	output reg	[3:0]			o_de_register_alu_ctrl,
	output reg	[`XLEN-1:0]		o_de_register_rs1_data,
	output reg	[`XLEN-1:0]		o_de_register_rs2_data,
	output reg	[`XLEN-1:0]		o_de_register_pc,
	output reg	[	   4:0]		o_de_register_rs1_addr,
	output reg	[	   4:0]		o_de_register_rs2_addr,
	output reg	[	   4:0]		o_de_register_rd_addr,
	output reg	[	   2:0]		o_de_register_func3,
	output reg	[`XLEN-1:0]		o_de_register_imm_ext,
	output reg	[`XLEN-1:0]		o_de_register_pcplus4,
	output reg	[6:0]			o_de_register_opcode,
	input		[1:0]			i_de_register_src_pc,
	input		[2:0]			i_de_register_src_imm,
	input		[1:0]			i_de_register_src_rd,
	input						i_de_register_src_alu_a,
	input						i_de_register_src_alu_b,
	input						i_de_register_reg_wr_en,
	input						i_de_register_mem_wr_en,
	input		[3:0]			i_de_register_mem_byte_sel,
	input		[3:0]			i_de_register_alu_ctrl,
	input		[`XLEN-1:0]		i_de_register_rs1_data,
	input		[`XLEN-1:0]		i_de_register_rs2_data,
	input		[`XLEN-1:0]		i_de_register_pc,
	input		[	   4:0]		i_de_register_rs1_addr,
	input		[	   4:0]		i_de_register_rs2_addr,
	input		[	   4:0]		i_de_register_rd_addr,
	input		[	   2:0]		i_de_register_func3,
	input		[`XLEN-1:0]		i_de_register_imm_ext,
	input		[`XLEN-1:0]		i_de_register_pcplus4,
	input						i_de_register_en,
	input		[6:0]			i_de_register_opcode,
	input						i_clk,
	input						i_rstn,
	input						i_de_register_clear
);

	always @(posedge i_clk or negedge i_rstn) begin
		if(!i_rstn) begin
			o_de_register_src_pc		<= REGISTER_INIT;
            o_de_register_src_imm       <= REGISTER_INIT;
            o_de_register_src_rd        <= REGISTER_INIT;
            o_de_register_src_alu_a		<= REGISTER_INIT;
            o_de_register_src_alu_b     <= REGISTER_INIT;
            o_de_register_reg_wr_en     <= REGISTER_INIT;
            o_de_register_mem_wr_en		<= REGISTER_INIT;
            o_de_register_mem_byte_sel  <= REGISTER_INIT;
            o_de_register_alu_ctrl      <= REGISTER_INIT;
            o_de_register_rs1_data		<= REGISTER_INIT;
            o_de_register_rs2_data      <= REGISTER_INIT;
            o_de_register_pc            <= REGISTER_INIT;
            o_de_register_rs1_addr		<= REGISTER_INIT;
            o_de_register_rs2_addr		<= REGISTER_INIT;
            o_de_register_rd_addr		<= REGISTER_INIT;
            o_de_register_func3			<= REGISTER_INIT;
            o_de_register_imm_ext       <= REGISTER_INIT;
            o_de_register_pcplus4       <= REGISTER_INIT;
			o_de_register_opcode		<= REGISTER_INIT;
		end else begin
			if(i_de_register_en) begin
				if(i_de_register_clear) begin
					o_de_register_src_pc		<= REGISTER_INIT;
                    o_de_register_src_imm       <= REGISTER_INIT;
                    o_de_register_src_rd        <= REGISTER_INIT;
                    o_de_register_src_alu_a		<= REGISTER_INIT;
                    o_de_register_src_alu_b     <= REGISTER_INIT;
                    o_de_register_reg_wr_en     <= REGISTER_INIT;
                    o_de_register_mem_wr_en		<= REGISTER_INIT;
                    o_de_register_mem_byte_sel  <= REGISTER_INIT;
                    o_de_register_alu_ctrl      <= REGISTER_INIT;
                    o_de_register_rs1_data		<= REGISTER_INIT;
                    o_de_register_rs2_data      <= REGISTER_INIT;
                    o_de_register_pc            <= REGISTER_INIT;
                    o_de_register_rs1_addr		<= REGISTER_INIT;
                    o_de_register_rs2_addr		<= REGISTER_INIT;
                    o_de_register_rd_addr		<= REGISTER_INIT;
                    o_de_register_func3			<= REGISTER_INIT;
                    o_de_register_imm_ext       <= REGISTER_INIT;
                    o_de_register_pcplus4       <= REGISTER_INIT;
				end else begin
					o_de_register_src_pc		<= i_de_register_src_pc;	  
                	o_de_register_src_imm       <= i_de_register_src_imm;     
                	o_de_register_src_rd        <= i_de_register_src_rd;      
                	o_de_register_src_alu_a		<= i_de_register_src_alu_a;	  
                	o_de_register_src_alu_b     <= i_de_register_src_alu_b;   
                	o_de_register_reg_wr_en     <= i_de_register_reg_wr_en;   
                	o_de_register_mem_wr_en		<= i_de_register_mem_wr_en;	  
                	o_de_register_mem_byte_sel  <= i_de_register_mem_byte_sel;
                	o_de_register_alu_ctrl      <= i_de_register_alu_ctrl;    
                	o_de_register_rs1_data		<= i_de_register_rs1_data;	  
                	o_de_register_rs2_data      <= i_de_register_rs2_data;    
                	o_de_register_pc            <= i_de_register_pc;          
                	o_de_register_rs1_addr		<= i_de_register_rs1_addr;	  
                	o_de_register_rs2_addr		<= i_de_register_rs2_addr;	  
                	o_de_register_rd_addr		<= i_de_register_rd_addr;	  
                	o_de_register_func3			<= i_de_register_func3;	  
                	o_de_register_imm_ext       <= i_de_register_imm_ext;     
                	o_de_register_pcplus4       <= i_de_register_pcplus4;
					o_de_register_opcode		<= i_de_register_opcode;
				end
			end else begin
				o_de_register_src_pc		<= o_de_register_src_pc;	  
                o_de_register_src_imm       <= o_de_register_src_imm;     
                o_de_register_src_rd        <= o_de_register_src_rd;      
                o_de_register_src_alu_a		<= o_de_register_src_alu_a;	  
                o_de_register_src_alu_b     <= o_de_register_src_alu_b;   
                o_de_register_reg_wr_en     <= o_de_register_reg_wr_en;   
                o_de_register_mem_wr_en		<= o_de_register_mem_wr_en;	  
                o_de_register_mem_byte_sel  <= o_de_register_mem_byte_sel;
                o_de_register_alu_ctrl      <= o_de_register_alu_ctrl;    
                o_de_register_rs1_data		<= o_de_register_rs1_data;	  
                o_de_register_rs2_data      <= o_de_register_rs2_data;    
                o_de_register_pc            <= o_de_register_pc;          
                o_de_register_rs1_addr		<= o_de_register_rs1_addr;	  
                o_de_register_rs2_addr		<= o_de_register_rs2_addr;	  
                o_de_register_rd_addr		<= o_de_register_rd_addr;	  
                o_de_register_func3			<= o_de_register_func3;	  
                o_de_register_imm_ext       <= o_de_register_imm_ext;     
                o_de_register_pcplus4       <= o_de_register_pcplus4;    
				o_de_register_opcode		<= o_de_register_opcode;
			end
		end
	end

endmodule
