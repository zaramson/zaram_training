// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


//======================

void Vriscv_top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vriscv_top::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vriscv_top::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vriscv_top::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vriscv_top::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+149,"o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+150,"o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+151,"o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+152,"o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+153,"o_riscv_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+154,"o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+155,"o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+156,"i_clk", false,-1);
        tracep->declBit(c+157,"i_rstn", false,-1);
        tracep->declBus(c+159,"riscv_top XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+149,"riscv_top o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+150,"riscv_top o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+151,"riscv_top o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+152,"riscv_top o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+153,"riscv_top o_riscv_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+154,"riscv_top o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+156,"riscv_top i_clk", false,-1);
        tracep->declBit(c+157,"riscv_top i_rstn", false,-1);
        tracep->declBus(c+98,"riscv_top mux31_pc_out", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top reg_pc_out", false,-1, 31,0);
        tracep->declBus(c+100,"riscv_top imem_instr", false,-1, 31,0);
        tracep->declBus(c+101,"riscv_top adder_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+102,"riscv_top ctrl_src_imm", false,-1, 2,0);
        tracep->declBus(c+103,"riscv_top ctrl_src_mux41", false,-1, 1,0);
        tracep->declBit(c+104,"riscv_top ctrl_src_mux21_rs1", false,-1);
        tracep->declBit(c+105,"riscv_top ctrl_src_mux21_rs2", false,-1);
        tracep->declBit(c+106,"riscv_top ctrl_reg_wr_en", false,-1);
        tracep->declBit(c+107,"riscv_top ctrl_mem_wr_en", false,-1);
        tracep->declBus(c+108,"riscv_top ctrl_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+109,"riscv_top ctrl_src_alu", false,-1, 3,0);
        tracep->declBus(c+158,"riscv_top regfile_rs1_out", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_top regfile_rs2_out", false,-1, 31,0);
        tracep->declBus(c+111,"riscv_top immext_out", false,-1, 31,0);
        tracep->declBus(c+112,"riscv_top mux21_rs1_out", false,-1, 31,0);
        tracep->declBus(c+113,"riscv_top mux21_rs2_out", false,-1, 31,0);
        tracep->declBus(c+114,"riscv_top adder_pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+115,"riscv_top alu_out", false,-1, 31,0);
        tracep->declBit(c+116,"riscv_top alu_zero", false,-1);
        tracep->declBus(c+115,"riscv_top dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+107,"riscv_top dmem_intf_wen", false,-1);
        tracep->declBus(c+117,"riscv_top dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+118,"riscv_top dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+119,"riscv_top dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+120,"riscv_top dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+121,"riscv_top mux41_out", false,-1, 31,0);
        tracep->declBit(c+122,"riscv_top take_branch", false,-1);
        tracep->declBus(c+123,"riscv_top src_pc", false,-1, 1,0);
        tracep->declBus(c+159,"riscv_top u_riscv_mux31_pc XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_mux31_pc DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_mux31_pc IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_mux31_pc ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_mux31_pc ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_mux31_pc ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_mux31_pc ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_mux31_pc ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_mux31_pc ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_mux31_pc ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_mux31_pc ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_mux31_pc ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_mux31_pc ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_mux31_pc ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_mux31_pc OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_mux31_pc OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_mux31_pc OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_mux31_pc OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_mux31_pc OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_mux31_pc OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_mux31_pc OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_mux31_pc OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_mux31_pc OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux31_pc SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux31_pc SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux31_pc SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_mux31_pc SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux31_pc SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux31_pc SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux31_pc SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_mux31_pc SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_mux31_pc SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_mux31_pc SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_mux31_pc SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_mux31_pc SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_mux31_pc SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_mux31_pc SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_mux31_pc SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_mux31_pc SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_mux31_pc SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_mux31_pc SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux31_pc FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux31_pc FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_mux31_pc FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux31_pc FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux31_pc FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux31_pc FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux31_pc FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_mux31_pc FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux31_pc FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux31_pc FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux31_pc FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux31_pc FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_mux31_pc FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux31_pc FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux31_pc FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux31_pc FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux31_pc FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux31_pc FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux31_pc FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+98,"riscv_top u_riscv_mux31_pc o_mux31_out", false,-1, 31,0);
        tracep->declBus(c+101,"riscv_top u_riscv_mux31_pc i_mux31_a", false,-1, 31,0);
        tracep->declBus(c+114,"riscv_top u_riscv_mux31_pc i_mux31_b", false,-1, 31,0);
        tracep->declBus(c+115,"riscv_top u_riscv_mux31_pc i_mux31_c", false,-1, 31,0);
        tracep->declBus(c+123,"riscv_top u_riscv_mux31_pc i_mux31_sel", false,-1, 1,0);
        tracep->declBus(c+159,"riscv_top u_riscv_register_pc XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_register_pc DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_register_pc IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_register_pc ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_register_pc ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_register_pc ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_register_pc ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_register_pc ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_register_pc ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_register_pc ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_register_pc ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_register_pc ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_register_pc ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_register_pc ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_register_pc OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_register_pc OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_register_pc OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_register_pc OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_register_pc OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_register_pc OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_register_pc OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_register_pc OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_register_pc OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_register_pc SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_register_pc SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_register_pc SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_register_pc SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_register_pc SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_register_pc SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_register_pc SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_register_pc SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_register_pc SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_register_pc SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_register_pc SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_register_pc SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_register_pc SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_register_pc SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_register_pc SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_register_pc SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_register_pc SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_register_pc SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_register_pc FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_register_pc FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_register_pc FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_register_pc FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_register_pc FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_register_pc FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_register_pc FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_register_pc FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_register_pc FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_register_pc FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_register_pc FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_register_pc FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_register_pc FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_register_pc FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_register_pc FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_register_pc FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_register_pc FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_register_pc FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_register_pc FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+99,"riscv_top u_riscv_register_pc o_register_out", false,-1, 31,0);
        tracep->declBus(c+98,"riscv_top u_riscv_register_pc i_register_in", false,-1, 31,0);
        tracep->declBit(c+156,"riscv_top u_riscv_register_pc i_register_clk", false,-1);
        tracep->declBit(c+195,"riscv_top u_riscv_register_pc i_register_en", false,-1);
        tracep->declBit(c+157,"riscv_top u_riscv_register_pc i_register_rstn", false,-1);
        tracep->declBus(c+159,"riscv_top u_riscv_imem XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_imem DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_imem IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_imem ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_imem ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_imem ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_imem ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_imem ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_imem ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_imem ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_imem ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_imem ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_imem ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_imem ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_imem OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_imem OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_imem OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_imem OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_imem OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_imem OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_imem OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_imem OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_imem OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_imem SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_imem SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_imem SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_imem SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_imem SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_imem SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_imem SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_imem SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_imem SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_imem SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_imem SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_imem SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_imem SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_imem SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_imem SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_imem SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_imem SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_imem SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_imem FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_imem FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_imem FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_imem FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_imem FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_imem FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_imem FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_imem FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_imem FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_imem FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_imem FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_imem FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_imem FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_imem FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_imem FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_imem FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_imem FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_imem FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_imem FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+100,"riscv_top u_riscv_imem o_imem_instr", false,-1, 31,0);
        tracep->declBus(c+124,"riscv_top u_riscv_imem i_imem_addr", false,-1, 13,0);
        tracep->declArray(c+1,"riscv_top u_riscv_imem IMEM_INIT_FILE", false,-1, 1023,0);
        tracep->declBus(c+159,"riscv_top u_riscv_adder_pc_plus_4 XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_adder_pc_plus_4 DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_adder_pc_plus_4 IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_adder_pc_plus_4 ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_adder_pc_plus_4 OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_adder_pc_plus_4 SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_adder_pc_plus_4 SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_adder_pc_plus_4 SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_adder_pc_plus_4 SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_adder_pc_plus_4 SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_adder_pc_plus_4 SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_adder_pc_plus_4 SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_adder_pc_plus_4 SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_adder_pc_plus_4 SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_adder_pc_plus_4 SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_adder_pc_plus_4 SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_adder_pc_plus_4 SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_adder_pc_plus_4 SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_adder_pc_plus_4 SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_adder_pc_plus_4 SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_adder_pc_plus_4 SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_adder_pc_plus_4 SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_adder_pc_plus_4 SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_adder_pc_plus_4 FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+101,"riscv_top u_riscv_adder_pc_plus_4 o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top u_riscv_adder_pc_plus_4 i_adder_a", false,-1, 31,0);
        tracep->declBus(c+196,"riscv_top u_riscv_adder_pc_plus_4 i_adder_b", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_ctrl XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_ctrl DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_ctrl IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_ctrl ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_ctrl ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_ctrl ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_ctrl ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_ctrl ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_ctrl ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_ctrl ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_ctrl ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_ctrl ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_ctrl ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_ctrl ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_ctrl OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_ctrl OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_ctrl OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_ctrl OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_ctrl OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_ctrl OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_ctrl OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_ctrl OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_ctrl OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_ctrl SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_ctrl SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_ctrl SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_ctrl SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_ctrl SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_ctrl SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_ctrl SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_ctrl SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_ctrl SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_ctrl SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_ctrl SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_ctrl SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_ctrl SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_ctrl SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_ctrl SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_ctrl SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_ctrl SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_ctrl SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_ctrl FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_ctrl FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_ctrl FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_ctrl FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_ctrl FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_ctrl FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_ctrl FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_ctrl FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_ctrl FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_ctrl FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_ctrl FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_ctrl FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_ctrl FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_ctrl FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_ctrl FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_ctrl FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_ctrl FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_ctrl FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_ctrl FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+102,"riscv_top u_riscv_ctrl o_ctrl_src_imm", false,-1, 2,0);
        tracep->declBus(c+103,"riscv_top u_riscv_ctrl o_ctrl_src_mux41", false,-1, 1,0);
        tracep->declBit(c+104,"riscv_top u_riscv_ctrl o_ctrl_src_mux21_rs1", false,-1);
        tracep->declBit(c+105,"riscv_top u_riscv_ctrl o_ctrl_src_mux21_rs2", false,-1);
        tracep->declBit(c+106,"riscv_top u_riscv_ctrl o_ctrl_reg_wr_en", false,-1);
        tracep->declBit(c+107,"riscv_top u_riscv_ctrl o_ctrl_mem_wr_en", false,-1);
        tracep->declBus(c+108,"riscv_top u_riscv_ctrl o_ctrl_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+109,"riscv_top u_riscv_ctrl o_ctrl_src_alu", false,-1, 3,0);
        tracep->declBit(c+116,"riscv_top u_riscv_ctrl i_ctrl_alu_zero", false,-1);
        tracep->declBus(c+125,"riscv_top u_riscv_ctrl i_ctrl_opcode", false,-1, 6,0);
        tracep->declBus(c+126,"riscv_top u_riscv_ctrl i_ctrl_funct3", false,-1, 2,0);
        tracep->declBit(c+127,"riscv_top u_riscv_ctrl i_ctrl_funct7_5b", false,-1);
        tracep->declArray(c+128,"riscv_top u_riscv_ctrl DEBUG_INSTR", false,-1, 255,0);
        tracep->declBus(c+159,"riscv_top u_riscv_regfile XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_regfile DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_regfile IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_regfile ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_regfile ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_regfile ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_regfile ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_regfile ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_regfile ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_regfile ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_regfile ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_regfile ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_regfile ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_regfile ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_regfile OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_regfile OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_regfile OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_regfile OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_regfile OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_regfile OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_regfile OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_regfile OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_regfile OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_regfile SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_regfile SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_regfile SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_regfile SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_regfile SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_regfile SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_regfile SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_regfile SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_regfile SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_regfile SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_regfile SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_regfile SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_regfile SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_regfile SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_regfile SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_regfile SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_regfile SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_regfile SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_regfile FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_regfile FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_regfile FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_regfile FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_regfile FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_regfile FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_regfile FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_regfile FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_regfile FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_regfile FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_regfile FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_regfile FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_regfile FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_regfile FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_regfile FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_regfile FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_regfile FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_regfile FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_regfile FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+158,"riscv_top u_riscv_regfile o_regfile_rs1_out", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_top u_riscv_regfile o_regfile_rs2_out", false,-1, 31,0);
        tracep->declBus(c+136,"riscv_top u_riscv_regfile i_regfile_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+137,"riscv_top u_riscv_regfile i_regfile_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+138,"riscv_top u_riscv_regfile i_regfile_wr_addr", false,-1, 4,0);
        tracep->declBus(c+121,"riscv_top u_riscv_regfile i_regfile_wr_data", false,-1, 31,0);
        tracep->declBit(c+106,"riscv_top u_riscv_regfile i_regfile_wen", false,-1);
        tracep->declBit(c+156,"riscv_top u_riscv_regfile i_regfile_clk", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+65+i*1,"riscv_top u_riscv_regfile registers", true,(i+0), 31,0);}}
        tracep->declBus(c+159,"riscv_top u_riscv_immext XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_immext DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_immext IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_immext ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_immext ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_immext ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_immext ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_immext ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_immext ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_immext ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_immext ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_immext ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_immext ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_immext ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_immext OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_immext OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_immext OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_immext OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_immext OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_immext OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_immext OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_immext OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_immext OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_immext SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_immext SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_immext SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_immext SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_immext SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_immext SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_immext SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_immext SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_immext SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_immext SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_immext SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_immext SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_immext SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_immext SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_immext SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_immext SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_immext SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_immext SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_immext FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_immext FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_immext FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_immext FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_immext FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_immext FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_immext FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_immext FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_immext FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_immext FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_immext FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_immext FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_immext FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_immext FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_immext FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_immext FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_immext FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_immext FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_immext FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+111,"riscv_top u_riscv_immext o_immext_out", false,-1, 31,0);
        tracep->declBus(c+100,"riscv_top u_riscv_immext i_immext_instr", false,-1, 31,0);
        tracep->declBus(c+102,"riscv_top u_riscv_immext i_immext_src", false,-1, 2,0);
        tracep->declBus(c+159,"riscv_top u_riscv_mux21_rs1 XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_mux21_rs1 DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_mux21_rs1 IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_mux21_rs1 ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_mux21_rs1 OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_mux21_rs1 OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_mux21_rs1 OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_mux21_rs1 OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_mux21_rs1 OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_mux21_rs1 OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_mux21_rs1 OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_mux21_rs1 OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_mux21_rs1 OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux21_rs1 SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux21_rs1 SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux21_rs1 SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_mux21_rs1 SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux21_rs1 SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux21_rs1 SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux21_rs1 SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_mux21_rs1 SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_mux21_rs1 SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_mux21_rs1 SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_mux21_rs1 SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_mux21_rs1 SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_mux21_rs1 SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_mux21_rs1 SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_mux21_rs1 SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_mux21_rs1 SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_mux21_rs1 SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_mux21_rs1 SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux21_rs1 FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux21_rs1 FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_mux21_rs1 FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux21_rs1 FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux21_rs1 FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux21_rs1 FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux21_rs1 FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_mux21_rs1 FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux21_rs1 FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux21_rs1 FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux21_rs1 FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux21_rs1 FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_mux21_rs1 FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux21_rs1 FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux21_rs1 FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux21_rs1 FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux21_rs1 FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux21_rs1 FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux21_rs1 FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+112,"riscv_top u_riscv_mux21_rs1 o_mux21_out", false,-1, 31,0);
        tracep->declBus(c+158,"riscv_top u_riscv_mux21_rs1 i_mux21_a", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top u_riscv_mux21_rs1 i_mux21_b", false,-1, 31,0);
        tracep->declBit(c+104,"riscv_top u_riscv_mux21_rs1 i_mux21_sel", false,-1);
        tracep->declBus(c+159,"riscv_top u_riscv_mux21_rs2 XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_mux21_rs2 DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_mux21_rs2 IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_mux21_rs2 ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_mux21_rs2 OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_mux21_rs2 OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_mux21_rs2 OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_mux21_rs2 OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_mux21_rs2 OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_mux21_rs2 OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_mux21_rs2 OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_mux21_rs2 OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_mux21_rs2 OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux21_rs2 SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux21_rs2 SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux21_rs2 SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_mux21_rs2 SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux21_rs2 SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux21_rs2 SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux21_rs2 SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_mux21_rs2 SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_mux21_rs2 SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_mux21_rs2 SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_mux21_rs2 SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_mux21_rs2 SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_mux21_rs2 SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_mux21_rs2 SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_mux21_rs2 SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_mux21_rs2 SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_mux21_rs2 SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_mux21_rs2 SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux21_rs2 FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux21_rs2 FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_mux21_rs2 FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux21_rs2 FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux21_rs2 FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux21_rs2 FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux21_rs2 FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_mux21_rs2 FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux21_rs2 FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux21_rs2 FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux21_rs2 FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux21_rs2 FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_mux21_rs2 FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux21_rs2 FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux21_rs2 FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux21_rs2 FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux21_rs2 FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux21_rs2 FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux21_rs2 FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+113,"riscv_top u_riscv_mux21_rs2 o_mux21_out", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_top u_riscv_mux21_rs2 i_mux21_a", false,-1, 31,0);
        tracep->declBus(c+111,"riscv_top u_riscv_mux21_rs2 i_mux21_b", false,-1, 31,0);
        tracep->declBit(c+105,"riscv_top u_riscv_mux21_rs2 i_mux21_sel", false,-1);
        tracep->declBus(c+159,"riscv_top u_riscv_adder_pc_plus_imm XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_adder_pc_plus_imm DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_adder_pc_plus_imm IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_adder_pc_plus_imm ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_adder_pc_plus_imm OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_adder_pc_plus_imm SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_adder_pc_plus_imm SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_adder_pc_plus_imm SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_adder_pc_plus_imm SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_adder_pc_plus_imm SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_adder_pc_plus_imm SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_adder_pc_plus_imm SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_adder_pc_plus_imm SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_adder_pc_plus_imm SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_adder_pc_plus_imm SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_adder_pc_plus_imm SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_adder_pc_plus_imm SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_adder_pc_plus_imm SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_adder_pc_plus_imm SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_adder_pc_plus_imm SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_adder_pc_plus_imm SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_adder_pc_plus_imm SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_adder_pc_plus_imm SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_adder_pc_plus_imm FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+114,"riscv_top u_riscv_adder_pc_plus_imm o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top u_riscv_adder_pc_plus_imm i_adder_a", false,-1, 31,0);
        tracep->declBus(c+111,"riscv_top u_riscv_adder_pc_plus_imm i_adder_b", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_alu XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_alu DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_alu IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_alu ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_alu ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_alu ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_alu ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_alu ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_alu ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_alu ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_alu ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_alu ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_alu ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_alu ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_alu OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_alu OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_alu OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_alu OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_alu OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_alu OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_alu OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_alu OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_alu OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_alu SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_alu SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_alu SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_alu SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_alu SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_alu SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_alu SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_alu SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_alu SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_alu SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_alu SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_alu SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_alu SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_alu SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_alu SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_alu SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_alu SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_alu SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_alu FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_alu FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_alu FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_alu FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_alu FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_alu FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_alu FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_alu FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_alu FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_alu FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_alu FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_alu FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_alu FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_alu FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_alu FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_alu FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_alu FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_alu FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_alu FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+115,"riscv_top u_riscv_alu o_alu_out", false,-1, 31,0);
        tracep->declBit(c+116,"riscv_top u_riscv_alu o_alu_zero", false,-1);
        tracep->declBus(c+112,"riscv_top u_riscv_alu i_alu_a", false,-1, 31,0);
        tracep->declBus(c+113,"riscv_top u_riscv_alu i_alu_b", false,-1, 31,0);
        tracep->declBus(c+109,"riscv_top u_riscv_alu i_alu_ctrl", false,-1, 3,0);
        tracep->declArray(c+139,"riscv_top u_riscv_alu DEBUG_ALU_OP", false,-1, 255,0);
        tracep->declBus(c+159,"riscv_top u_riscv_dmem_interface XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_dmem_interface DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_dmem_interface IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_dmem_interface ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_dmem_interface ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_dmem_interface ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_dmem_interface ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_dmem_interface ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_dmem_interface ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_dmem_interface ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_dmem_interface ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_dmem_interface ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_dmem_interface ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_dmem_interface ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_dmem_interface OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_dmem_interface OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_dmem_interface OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_dmem_interface OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_dmem_interface OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_dmem_interface OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_dmem_interface OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_dmem_interface OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_dmem_interface OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_dmem_interface SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_dmem_interface SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_dmem_interface SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_dmem_interface SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_dmem_interface SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_dmem_interface SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_dmem_interface SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_dmem_interface SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_dmem_interface SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_dmem_interface SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_dmem_interface SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_dmem_interface SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_dmem_interface SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_dmem_interface SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_dmem_interface SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_dmem_interface SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_dmem_interface SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_dmem_interface SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_dmem_interface FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_dmem_interface FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_dmem_interface FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_dmem_interface FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_dmem_interface FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_dmem_interface FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_dmem_interface FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_dmem_interface FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_dmem_interface FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_dmem_interface FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_dmem_interface FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_dmem_interface FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_dmem_interface FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_dmem_interface FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_dmem_interface FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_dmem_interface FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_dmem_interface FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_dmem_interface FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_dmem_interface FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+115,"riscv_top u_riscv_dmem_interface o_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+107,"riscv_top u_riscv_dmem_interface o_dmem_intf_wen", false,-1);
        tracep->declBus(c+115,"riscv_top u_riscv_dmem_interface i_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+107,"riscv_top u_riscv_dmem_interface i_dmem_intf_wen", false,-1);
        tracep->declBus(c+117,"riscv_top u_riscv_dmem_interface o_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+118,"riscv_top u_riscv_dmem_interface o_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+119,"riscv_top u_riscv_dmem_interface o_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_top u_riscv_dmem_interface i_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+108,"riscv_top u_riscv_dmem_interface i_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+120,"riscv_top u_riscv_dmem_interface i_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+126,"riscv_top u_riscv_dmem_interface i_dmem_intf_func3", false,-1, 2,0);
        tracep->declBus(c+147,"riscv_top u_riscv_dmem_interface byte_aligned_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_dmem XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_dmem DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_dmem IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_dmem ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_dmem ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_dmem ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_dmem ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_dmem ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_dmem ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_dmem ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_dmem ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_dmem ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_dmem ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_dmem ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_dmem OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_dmem OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_dmem OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_dmem OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_dmem OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_dmem OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_dmem OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_dmem OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_dmem OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_dmem SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_dmem SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_dmem SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_dmem SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_dmem SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_dmem SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_dmem SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_dmem SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_dmem SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_dmem SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_dmem SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_dmem SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_dmem SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_dmem SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_dmem SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_dmem SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_dmem SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_dmem SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_dmem FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_dmem FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_dmem FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_dmem FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_dmem FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_dmem FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_dmem FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_dmem FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_dmem FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_dmem FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_dmem FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_dmem FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_dmem FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_dmem FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_dmem FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_dmem FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_dmem FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_dmem FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_dmem FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+120,"riscv_top u_riscv_dmem o_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+148,"riscv_top u_riscv_dmem i_dmem_addr", false,-1, 13,0);
        tracep->declBit(c+107,"riscv_top u_riscv_dmem i_dmem_wen", false,-1);
        tracep->declBus(c+117,"riscv_top u_riscv_dmem i_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+118,"riscv_top u_riscv_dmem i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBit(c+156,"riscv_top u_riscv_dmem i_dmem_clk", false,-1);
        tracep->declArray(c+33,"riscv_top u_riscv_dmem DMEM_INIT_FILE", false,-1, 1023,0);
        tracep->declBus(c+97,"riscv_top u_riscv_dmem i", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_mux41 XLEN", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_mux41 DMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_mux41 IMEM_ADDR_BIT", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_mux41 ALU_CTRL_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"riscv_top u_riscv_mux41 ALU_CTRL_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"riscv_top u_riscv_mux41 ALU_CTRL_XOR", false,-1, 3,0);
        tracep->declBus(c+164,"riscv_top u_riscv_mux41 ALU_CTRL_OR", false,-1, 3,0);
        tracep->declBus(c+165,"riscv_top u_riscv_mux41 ALU_CTRL_AND", false,-1, 3,0);
        tracep->declBus(c+166,"riscv_top u_riscv_mux41 ALU_CTRL_SLL", false,-1, 3,0);
        tracep->declBus(c+167,"riscv_top u_riscv_mux41 ALU_CTRL_SRL", false,-1, 3,0);
        tracep->declBus(c+168,"riscv_top u_riscv_mux41 ALU_CTRL_SRA", false,-1, 3,0);
        tracep->declBus(c+169,"riscv_top u_riscv_mux41 ALU_CTRL_SLT", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_mux41 ALU_CTRL_SLTU", false,-1, 3,0);
        tracep->declBus(c+171,"riscv_top u_riscv_mux41 ALU_CTRL_NOP", false,-1, 3,0);
        tracep->declBus(c+172,"riscv_top u_riscv_mux41 OPCODE_R_OP", false,-1, 6,0);
        tracep->declBus(c+173,"riscv_top u_riscv_mux41 OPCODE_I_OP", false,-1, 6,0);
        tracep->declBus(c+174,"riscv_top u_riscv_mux41 OPCODE_I_LOAD", false,-1, 6,0);
        tracep->declBus(c+175,"riscv_top u_riscv_mux41 OPCODE_S_STORE", false,-1, 6,0);
        tracep->declBus(c+176,"riscv_top u_riscv_mux41 OPCODE_B_BRANCH", false,-1, 6,0);
        tracep->declBus(c+177,"riscv_top u_riscv_mux41 OPCODE_J_JAL", false,-1, 6,0);
        tracep->declBus(c+178,"riscv_top u_riscv_mux41 OPCODE_I_JALR", false,-1, 6,0);
        tracep->declBus(c+179,"riscv_top u_riscv_mux41 OPCODE_U_LUI", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_mux41 OPCODE_U_AUIPC", false,-1, 6,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux41 SRC_IMM_R", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux41 SRC_IMM_I", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux41 SRC_IMM_S", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_mux41 SRC_IMM_B", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux41 SRC_IMM_J", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux41 SRC_IMM_U", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux41 SRC_IMM_X", false,-1, 2,0);
        tracep->declBus(c+188,"riscv_top u_riscv_mux41 SRC_PC_PC_4", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_mux41 SRC_PC_PC_IMM", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_mux41 SRC_PC_RS_IMM", false,-1, 1,0);
        tracep->declBus(c+188,"riscv_top u_riscv_mux41 SRC_RD_ALU", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_mux41 SRC_RD_DME", false,-1, 1,0);
        tracep->declBus(c+190,"riscv_top u_riscv_mux41 SRC_RD_PC4", false,-1, 1,0);
        tracep->declBus(c+191,"riscv_top u_riscv_mux41 SRC_RD_IMM", false,-1, 1,0);
        tracep->declBus(c+192,"riscv_top u_riscv_mux41 SRC_ALU_A_RS1", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_mux41 SRC_ALU_A_PC", false,-1, 0,0);
        tracep->declBus(c+192,"riscv_top u_riscv_mux41 SRC_ALU_B_RS2", false,-1, 0,0);
        tracep->declBus(c+193,"riscv_top u_riscv_mux41 SRC_ALU_B_IMM", false,-1, 0,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux41 FUNCT3_ALU_ADD_SUB", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux41 FUNCT3_ALU_XOR", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_mux41 FUNCT3_ALU_OR", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux41 FUNCT3_ALU_AND", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux41 FUNCT3_ALU_SLL", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux41 FUNCT3_ALU_SRL_SRA", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux41 FUNCT3_ALU_SLT", false,-1, 2,0);
        tracep->declBus(c+184,"riscv_top u_riscv_mux41 FUNCT3_ALU_SLTU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux41 FUNCT3_BRANCH_BEQ", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux41 FUNCT3_BRANCH_BNE", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux41 FUNCT3_BRANCH_BLT", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux41 FUNCT3_BRANCH_BGE", false,-1, 2,0);
        tracep->declBus(c+194,"riscv_top u_riscv_mux41 FUNCT3_BRANCH_BLTU", false,-1, 2,0);
        tracep->declBus(c+187,"riscv_top u_riscv_mux41 FUNCT3_BRANCH_BGEU", false,-1, 2,0);
        tracep->declBus(c+181,"riscv_top u_riscv_mux41 FUNCT3_MEM_BYTE", false,-1, 2,0);
        tracep->declBus(c+182,"riscv_top u_riscv_mux41 FUNCT3_MEM_HALF", false,-1, 2,0);
        tracep->declBus(c+183,"riscv_top u_riscv_mux41 FUNCT3_MEM_WORD", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_mux41 FUNCT3_MEM_BYTEU", false,-1, 2,0);
        tracep->declBus(c+186,"riscv_top u_riscv_mux41 FUNCT3_MEM_HALFU", false,-1, 2,0);
        tracep->declBus(c+121,"riscv_top u_riscv_mux41 o_mux41_out", false,-1, 31,0);
        tracep->declBus(c+115,"riscv_top u_riscv_mux41 i_mux41_a", false,-1, 31,0);
        tracep->declBus(c+119,"riscv_top u_riscv_mux41 i_mux41_b", false,-1, 31,0);
        tracep->declBus(c+101,"riscv_top u_riscv_mux41 i_mux41_c", false,-1, 31,0);
        tracep->declBus(c+111,"riscv_top u_riscv_mux41 i_mux41_d", false,-1, 31,0);
        tracep->declBus(c+103,"riscv_top u_riscv_mux41 i_mux41_sel", false,-1, 1,0);
    }
}

void Vriscv_top::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vriscv_top::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vriscv_top::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullWData(oldp+1,(vlTOPp->riscv_top__DOT__u_riscv_imem__DOT__IMEM_INIT_FILE),1024);
        tracep->fullWData(oldp+33,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__DMEM_INIT_FILE),1024);
        tracep->fullIData(oldp+65,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[0]),32);
        tracep->fullIData(oldp+66,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[1]),32);
        tracep->fullIData(oldp+67,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[2]),32);
        tracep->fullIData(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[3]),32);
        tracep->fullIData(oldp+69,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[4]),32);
        tracep->fullIData(oldp+70,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[5]),32);
        tracep->fullIData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[6]),32);
        tracep->fullIData(oldp+72,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[7]),32);
        tracep->fullIData(oldp+73,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[8]),32);
        tracep->fullIData(oldp+74,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[9]),32);
        tracep->fullIData(oldp+75,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[10]),32);
        tracep->fullIData(oldp+76,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[11]),32);
        tracep->fullIData(oldp+77,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[12]),32);
        tracep->fullIData(oldp+78,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[13]),32);
        tracep->fullIData(oldp+79,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[14]),32);
        tracep->fullIData(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[15]),32);
        tracep->fullIData(oldp+81,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[16]),32);
        tracep->fullIData(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[17]),32);
        tracep->fullIData(oldp+83,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[18]),32);
        tracep->fullIData(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[19]),32);
        tracep->fullIData(oldp+85,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[20]),32);
        tracep->fullIData(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[21]),32);
        tracep->fullIData(oldp+87,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[22]),32);
        tracep->fullIData(oldp+88,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[23]),32);
        tracep->fullIData(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[24]),32);
        tracep->fullIData(oldp+90,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[25]),32);
        tracep->fullIData(oldp+91,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[26]),32);
        tracep->fullIData(oldp+92,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[27]),32);
        tracep->fullIData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[28]),32);
        tracep->fullIData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[29]),32);
        tracep->fullIData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[30]),32);
        tracep->fullIData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[31]),32);
        tracep->fullIData(oldp+97,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
        tracep->fullIData(oldp+98,(((0U == (IData)(vlTOPp->riscv_top__DOT__src_pc))
                                     ? ((IData)(4U) 
                                        + vlTOPp->riscv_top__DOT__reg_pc_out)
                                     : ((1U == (IData)(vlTOPp->riscv_top__DOT__src_pc))
                                         ? (vlTOPp->riscv_top__DOT__reg_pc_out 
                                            + vlTOPp->riscv_top__DOT__immext_out)
                                         : ((2U == (IData)(vlTOPp->riscv_top__DOT__src_pc))
                                             ? vlTOPp->riscv_top__DOT__alu_out
                                             : 0U)))),32);
        tracep->fullIData(oldp+99,(vlTOPp->riscv_top__DOT__reg_pc_out),32);
        tracep->fullIData(oldp+100,(vlTOPp->riscv_top__DOT__imem_instr),32);
        tracep->fullIData(oldp+101,(((IData)(4U) + vlTOPp->riscv_top__DOT__reg_pc_out)),32);
        tracep->fullCData(oldp+102,(vlTOPp->riscv_top__DOT__ctrl_src_imm),3);
        tracep->fullCData(oldp+103,(vlTOPp->riscv_top__DOT__ctrl_src_mux41),2);
        tracep->fullBit(oldp+104,((0x17U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__imem_instr))));
        tracep->fullBit(oldp+105,(vlTOPp->riscv_top__DOT__ctrl_src_mux21_rs2));
        tracep->fullBit(oldp+106,((1U & (~ ((0x23U 
                                             == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__imem_instr)))))));
        tracep->fullBit(oldp+107,((0x23U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__imem_instr))));
        tracep->fullCData(oldp+108,((((3U == (0x7fU 
                                              & vlTOPp->riscv_top__DOT__imem_instr)) 
                                      | (0x23U == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__imem_instr)))
                                      ? ((0x4000U & vlTOPp->riscv_top__DOT__imem_instr)
                                          ? ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__imem_instr)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__imem_instr)
                                                  ? 3U
                                                  : 1U))
                                          : ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__imem_instr)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__imem_instr)
                                                  ? 3U
                                                  : 1U)))
                                      : 0xfU)),4);
        tracep->fullCData(oldp+109,(vlTOPp->riscv_top__DOT__ctrl_src_alu),4);
        tracep->fullIData(oldp+110,(vlTOPp->riscv_top__DOT__regfile_rs2_out),32);
        tracep->fullIData(oldp+111,(vlTOPp->riscv_top__DOT__immext_out),32);
        tracep->fullIData(oldp+112,(vlTOPp->riscv_top__DOT__mux21_rs1_out),32);
        tracep->fullIData(oldp+113,(vlTOPp->riscv_top__DOT__mux21_rs2_out),32);
        tracep->fullIData(oldp+114,((vlTOPp->riscv_top__DOT__reg_pc_out 
                                     + vlTOPp->riscv_top__DOT__immext_out)),32);
        tracep->fullIData(oldp+115,(vlTOPp->riscv_top__DOT__alu_out),32);
        tracep->fullBit(oldp+116,((0U == vlTOPp->riscv_top__DOT__alu_out)));
        tracep->fullIData(oldp+117,(vlTOPp->riscv_top__DOT__dmem_intf_wr_data),32);
        tracep->fullCData(oldp+118,(vlTOPp->riscv_top__DOT__dmem_intf_byte_sel),4);
        tracep->fullIData(oldp+119,(((0x4000U & vlTOPp->riscv_top__DOT__imem_instr)
                                      ? ((0x2000U & vlTOPp->riscv_top__DOT__imem_instr)
                                          ? 0U : ((0x1000U 
                                                   & vlTOPp->riscv_top__DOT__imem_instr)
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                      : ((0x2000U & vlTOPp->riscv_top__DOT__imem_instr)
                                          ? ((0x1000U 
                                              & vlTOPp->riscv_top__DOT__imem_instr)
                                              ? 0U : vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                          : ((0x1000U 
                                              & vlTOPp->riscv_top__DOT__imem_instr)
                                              ? ((0xffff0000U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                              : ((0xffffff00U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 7U)))) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))),32);
        tracep->fullIData(oldp+120,(vlTOPp->riscv_top__DOT__dmem_rd_data),32);
        tracep->fullIData(oldp+121,(((2U & (IData)(vlTOPp->riscv_top__DOT__ctrl_src_mux41))
                                      ? ((1U & (IData)(vlTOPp->riscv_top__DOT__ctrl_src_mux41))
                                          ? vlTOPp->riscv_top__DOT__immext_out
                                          : ((IData)(4U) 
                                             + vlTOPp->riscv_top__DOT__reg_pc_out))
                                      : ((1U & (IData)(vlTOPp->riscv_top__DOT__ctrl_src_mux41))
                                          ? ((0x4000U 
                                              & vlTOPp->riscv_top__DOT__imem_instr)
                                              ? ((0x2000U 
                                                  & vlTOPp->riscv_top__DOT__imem_instr)
                                                  ? 0U
                                                  : 
                                                 ((0x1000U 
                                                   & vlTOPp->riscv_top__DOT__imem_instr)
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                              : ((0x2000U 
                                                  & vlTOPp->riscv_top__DOT__imem_instr)
                                                  ? 
                                                 ((0x1000U 
                                                   & vlTOPp->riscv_top__DOT__imem_instr)
                                                   ? 0U
                                                   : vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                  : 
                                                 ((0x1000U 
                                                   & vlTOPp->riscv_top__DOT__imem_instr)
                                                   ? 
                                                  ((0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                      >> 0xfU)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                                   : 
                                                  ((0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))
                                          : vlTOPp->riscv_top__DOT__alu_out))),32);
        tracep->fullBit(oldp+122,(((0x63U == (0x7fU 
                                              & vlTOPp->riscv_top__DOT__imem_instr)) 
                                   & ((0x4000U & vlTOPp->riscv_top__DOT__imem_instr)
                                       ? ((0x2000U 
                                           & vlTOPp->riscv_top__DOT__imem_instr)
                                           ? ((0x1000U 
                                               & vlTOPp->riscv_top__DOT__imem_instr)
                                               ? (0U 
                                                  == vlTOPp->riscv_top__DOT__alu_out)
                                               : (0U 
                                                  != vlTOPp->riscv_top__DOT__alu_out))
                                           : ((0x1000U 
                                               & vlTOPp->riscv_top__DOT__imem_instr)
                                               ? (0U 
                                                  == vlTOPp->riscv_top__DOT__alu_out)
                                               : (0U 
                                                  != vlTOPp->riscv_top__DOT__alu_out)))
                                       : ((~ (vlTOPp->riscv_top__DOT__imem_instr 
                                              >> 0xdU)) 
                                          & ((0x1000U 
                                              & vlTOPp->riscv_top__DOT__imem_instr)
                                              ? (0U 
                                                 != vlTOPp->riscv_top__DOT__alu_out)
                                              : (0U 
                                                 == vlTOPp->riscv_top__DOT__alu_out)))))));
        tracep->fullCData(oldp+123,(vlTOPp->riscv_top__DOT__src_pc),2);
        tracep->fullSData(oldp+124,((0x3fffU & (vlTOPp->riscv_top__DOT__reg_pc_out 
                                                >> 2U))),14);
        tracep->fullCData(oldp+125,((0x7fU & vlTOPp->riscv_top__DOT__imem_instr)),7);
        tracep->fullCData(oldp+126,((7U & (vlTOPp->riscv_top__DOT__imem_instr 
                                           >> 0xcU))),3);
        tracep->fullBit(oldp+127,((1U & (vlTOPp->riscv_top__DOT__imem_instr 
                                         >> 0x1eU))));
        tracep->fullWData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
        tracep->fullCData(oldp+136,((0x1fU & (vlTOPp->riscv_top__DOT__imem_instr 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+137,((0x1fU & (vlTOPp->riscv_top__DOT__imem_instr 
                                              >> 0x14U))),5);
        tracep->fullCData(oldp+138,((0x1fU & (vlTOPp->riscv_top__DOT__imem_instr 
                                              >> 7U))),5);
        tracep->fullWData(oldp+139,(vlTOPp->riscv_top__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),256);
        tracep->fullIData(oldp+147,(vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        tracep->fullSData(oldp+148,((0x3fffU & (vlTOPp->riscv_top__DOT__alu_out 
                                                >> 2U))),14);
        tracep->fullIData(oldp+149,(vlTOPp->o_riscv_imem_pc),32);
        tracep->fullIData(oldp+150,(vlTOPp->o_riscv_imem_instr),32);
        tracep->fullIData(oldp+151,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->fullBit(oldp+152,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->fullCData(oldp+153,(vlTOPp->o_riscv_dmem_byte_sel),4);
        tracep->fullIData(oldp+154,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->fullIData(oldp+155,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->fullBit(oldp+156,(vlTOPp->i_clk));
        tracep->fullBit(oldp+157,(vlTOPp->i_rstn));
        tracep->fullIData(oldp+158,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers
                                    [(0x1fU & (vlTOPp->riscv_top__DOT__imem_instr 
                                               >> 0xfU))]),32);
        tracep->fullIData(oldp+159,(0x20U),32);
        tracep->fullIData(oldp+160,(0x10U),32);
        tracep->fullCData(oldp+161,(0U),4);
        tracep->fullCData(oldp+162,(1U),4);
        tracep->fullCData(oldp+163,(2U),4);
        tracep->fullCData(oldp+164,(3U),4);
        tracep->fullCData(oldp+165,(4U),4);
        tracep->fullCData(oldp+166,(5U),4);
        tracep->fullCData(oldp+167,(6U),4);
        tracep->fullCData(oldp+168,(7U),4);
        tracep->fullCData(oldp+169,(8U),4);
        tracep->fullCData(oldp+170,(9U),4);
        tracep->fullCData(oldp+171,(0xfU),4);
        tracep->fullCData(oldp+172,(0x33U),7);
        tracep->fullCData(oldp+173,(0x13U),7);
        tracep->fullCData(oldp+174,(3U),7);
        tracep->fullCData(oldp+175,(0x23U),7);
        tracep->fullCData(oldp+176,(0x63U),7);
        tracep->fullCData(oldp+177,(0x6fU),7);
        tracep->fullCData(oldp+178,(0x67U),7);
        tracep->fullCData(oldp+179,(0x37U),7);
        tracep->fullCData(oldp+180,(0x17U),7);
        tracep->fullCData(oldp+181,(0U),3);
        tracep->fullCData(oldp+182,(1U),3);
        tracep->fullCData(oldp+183,(2U),3);
        tracep->fullCData(oldp+184,(3U),3);
        tracep->fullCData(oldp+185,(4U),3);
        tracep->fullCData(oldp+186,(5U),3);
        tracep->fullCData(oldp+187,(7U),3);
        tracep->fullCData(oldp+188,(0U),2);
        tracep->fullCData(oldp+189,(1U),2);
        tracep->fullCData(oldp+190,(2U),2);
        tracep->fullCData(oldp+191,(3U),2);
        tracep->fullBit(oldp+192,(0U));
        tracep->fullBit(oldp+193,(1U));
        tracep->fullCData(oldp+194,(6U),3);
        tracep->fullBit(oldp+195,(1U));
        tracep->fullIData(oldp+196,(4U),32);
    }
}
