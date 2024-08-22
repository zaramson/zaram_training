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
        tracep->declBus(c+219,"o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+220,"o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+221,"o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+222,"o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+223,"o_riscv_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+224,"o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+225,"o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+226,"i_clk", false,-1);
        tracep->declBit(c+227,"i_rstn", false,-1);
        tracep->declBus(c+236,"riscv_top REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+219,"riscv_top o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+220,"riscv_top o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+221,"riscv_top o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+222,"riscv_top o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+223,"riscv_top o_riscv_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+224,"riscv_top o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+225,"riscv_top o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+226,"riscv_top i_clk", false,-1);
        tracep->declBit(c+227,"riscv_top i_rstn", false,-1);
        tracep->declBus(c+236,"riscv_top u_riscv_pipeline_cpu REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+219,"riscv_top u_riscv_pipeline_cpu o_cpu_imem_pc", false,-1, 31,0);
        tracep->declBus(c+221,"riscv_top u_riscv_pipeline_cpu o_cpu_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+222,"riscv_top u_riscv_pipeline_cpu o_cpu_dmem_wr_en", false,-1);
        tracep->declBus(c+223,"riscv_top u_riscv_pipeline_cpu o_cpu_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+224,"riscv_top u_riscv_pipeline_cpu o_cpu_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+220,"riscv_top u_riscv_pipeline_cpu i_cpu_imem_instr", false,-1, 31,0);
        tracep->declBus(c+225,"riscv_top u_riscv_pipeline_cpu i_cpu_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+226,"riscv_top u_riscv_pipeline_cpu i_clk", false,-1);
        tracep->declBit(c+227,"riscv_top u_riscv_pipeline_cpu i_rstn", false,-1);
        tracep->declBus(c+146,"riscv_top u_riscv_pipeline_cpu src_imm", false,-1, 2,0);
        tracep->declBus(c+147,"riscv_top u_riscv_pipeline_cpu src_rd", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipeline_cpu src_alu_a", false,-1);
        tracep->declBit(c+149,"riscv_top u_riscv_pipeline_cpu src_alu_b", false,-1);
        tracep->declBit(c+150,"riscv_top u_riscv_pipeline_cpu reg_wr_en", false,-1);
        tracep->declBus(c+151,"riscv_top u_riscv_pipeline_cpu alu_ctrl", false,-1, 3,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipeline_cpu mem_func3", false,-1, 2,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipeline_cpu instr_d", false,-1, 31,0);
        tracep->declBit(c+153,"riscv_top u_riscv_pipeline_cpu mem_wr_en", false,-1);
        tracep->declBus(c+154,"riscv_top u_riscv_pipeline_cpu mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipeline_cpu dmem_addr", false,-1, 31,0);
        tracep->declBus(c+228,"riscv_top u_riscv_pipeline_cpu dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_pipeline_cpu dmem_wr_data", false,-1, 31,0);
        tracep->declBit(c+68,"riscv_top u_riscv_pipeline_cpu dmem_wr_en", false,-1);
        tracep->declBus(c+69,"riscv_top u_riscv_pipeline_cpu dmem_byte_sel", false,-1, 3,0);
        tracep->declBit(c+155,"riscv_top u_riscv_pipeline_cpu is_load", false,-1);
        tracep->declBus(c+236,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+219,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath o_dp_pc", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath o_dp_mem_addr", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath o_dp_mem_wr_data", false,-1, 31,0);
        tracep->declBit(c+68,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath o_dp_mem_wr_en", false,-1);
        tracep->declBus(c+69,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath o_dp_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath o_dp_mem_func3", false,-1, 2,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath o_dp_instr_d", false,-1, 31,0);
        tracep->declBus(c+228,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_mem_rd_data", false,-1, 31,0);
        tracep->declBus(c+220,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_instr", false,-1, 31,0);
        tracep->declBus(c+146,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_src_imm", false,-1, 2,0);
        tracep->declBus(c+147,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_src_rd", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_src_alu_a", false,-1);
        tracep->declBit(c+149,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_src_alu_b", false,-1);
        tracep->declBit(c+150,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_reg_wr_en", false,-1);
        tracep->declBit(c+153,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_mem_wr_en", false,-1);
        tracep->declBus(c+154,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+151,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+155,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_dp_is_load", false,-1);
        tracep->declBit(c+226,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_clk", false,-1);
        tracep->declBit(c+227,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath i_rstn", false,-1);
        tracep->declBus(c+156,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pc_next", false,-1, 31,0);
        tracep->declBus(c+229,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+70,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+230,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath regfile_rs1_data", false,-1, 31,0);
        tracep->declBus(c+231,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath regfile_rs2_data", false,-1, 31,0);
        tracep->declBus(c+237,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath regfile_rd_data", false,-1, 31,0);
        tracep->declBus(c+157,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath immediate", false,-1, 31,0);
        tracep->declBus(c+158,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath alu_a", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath alu_b", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath alu_result", false,-1, 31,0);
        tracep->declBit(c+161,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath alu_zero", false,-1);
        tracep->declBus(c+162,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath regfile_rd_data_w", false,-1, 31,0);
        tracep->declArray(c+163,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mux_concat_pc", false,-1, 95,0);
        tracep->declArray(c+238,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mux_concat_rd", false,-1, 127,0);
        tracep->declQuad(c+166,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mux_concat_alu_a", false,-1, 63,0);
        tracep->declQuad(c+168,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mux_concat_alu_b", false,-1, 63,0);
        tracep->declArray(c+170,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mux_concat_forward_ae", false,-1, 95,0);
        tracep->declArray(c+173,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mux_concat_forward_be", false,-1, 95,0);
        tracep->declBus(c+176,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath forward_ae_result", false,-1, 31,0);
        tracep->declBus(c+177,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath forward_be_result", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath instr_d", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pc_d", false,-1, 31,0);
        tracep->declBus(c+72,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pcplus4_d", false,-1, 31,0);
        tracep->declBus(c+73,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath src_imm_e", false,-1, 2,0);
        tracep->declBus(c+74,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath src_rd_e", false,-1, 1,0);
        tracep->declBit(c+75,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath src_alu_a_e", false,-1);
        tracep->declBit(c+76,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath src_alu_b_e", false,-1);
        tracep->declBit(c+178,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath reg_wr_en_e", false,-1);
        tracep->declBit(c+77,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mem_wr_en_e", false,-1);
        tracep->declBus(c+78,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mem_byte_sel_e", false,-1, 3,0);
        tracep->declBus(c+79,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath alu_ctrl_e", false,-1, 3,0);
        tracep->declBus(c+80,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath rs1_data_e", false,-1, 31,0);
        tracep->declBus(c+81,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath rs2_data_e", false,-1, 31,0);
        tracep->declBus(c+82,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pc_e", false,-1, 31,0);
        tracep->declBus(c+83,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath rs1_addr_e", false,-1, 4,0);
        tracep->declBus(c+84,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath rs2_addr_e", false,-1, 4,0);
        tracep->declBus(c+179,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath rd_addr_e", false,-1, 4,0);
        tracep->declBus(c+85,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath func3_e", false,-1, 2,0);
        tracep->declBus(c+86,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath imm_ext_e", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pcplus4_e", false,-1, 31,0);
        tracep->declBus(c+88,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath opcode_e", false,-1, 6,0);
        tracep->declBus(c+180,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath src_pc_f", false,-1, 1,0);
        tracep->declBit(c+89,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath is_load_e", false,-1);
        tracep->declBus(c+90,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath src_rd_m", false,-1, 1,0);
        tracep->declBit(c+181,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath reg_wr_en_m", false,-1);
        tracep->declBit(c+68,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mem_wr_en_m", false,-1);
        tracep->declBus(c+69,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mem_byte_sel_m", false,-1, 3,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath alu_result_m", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath write_data_m", false,-1, 31,0);
        tracep->declBus(c+182,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath rd_addr_m", false,-1, 4,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath func3_m", false,-1, 2,0);
        tracep->declBus(c+91,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pcplus4_m", false,-1, 31,0);
        tracep->declBus(c+92,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath imm_ext_m", false,-1, 31,0);
        tracep->declBit(c+93,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath is_load_m", false,-1);
        tracep->declBus(c+94,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath for_forward_result_m", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath src_rd_w", false,-1, 1,0);
        tracep->declBit(c+183,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath reg_wr_en_w", false,-1);
        tracep->declBus(c+96,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath alu_result_w", false,-1, 31,0);
        tracep->declBus(c+97,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath rd_data_w", false,-1, 31,0);
        tracep->declBus(c+184,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath rd_addr_w", false,-1, 4,0);
        tracep->declBus(c+98,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath pcplus4_w", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath imm_ext_w", false,-1, 31,0);
        tracep->declBit(c+100,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath is_load_w", false,-1);
        tracep->declBus(c+101,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath for_forward_result_w", false,-1, 31,0);
        tracep->declBit(c+185,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath stall_f", false,-1);
        tracep->declBit(c+185,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath stall_d", false,-1);
        tracep->declBit(c+186,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath flush_d", false,-1);
        tracep->declBit(c+187,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath flush_e", false,-1);
        tracep->declBus(c+188,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath forward_ae", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath forward_be", false,-1, 1,0);
        tracep->declBit(c+232,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath take_branch", false,-1);
        tracep->declArray(c+102,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mux_concat_rd_m", false,-1, 95,0);
        tracep->declQuad(c+105,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath mux_concat_rd_w", false,-1, 63,0);
        tracep->declBus(c+242,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_pc N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_pc o_mux_data", false,-1, 31,0);
        tracep->declArray(c+163,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_pc i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+180,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_pc i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+190+i*1,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_pc mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+236,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_register_pc REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+219,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_register_pc o_register_q", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_register_pc i_register_d", false,-1, 31,0);
        tracep->declBit(c+193,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_register_pc i_register_en", false,-1);
        tracep->declBit(c+226,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_register_pc i_clk", false,-1);
        tracep->declBit(c+227,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_register_pc i_rstn", false,-1);
        tracep->declBus(c+236,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register o_fd_register_instr", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register o_fd_register_pc", false,-1, 31,0);
        tracep->declBus(c+72,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register o_fd_register_pcplus4", false,-1, 31,0);
        tracep->declBus(c+220,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register i_fd_register_instr", false,-1, 31,0);
        tracep->declBus(c+219,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register i_fd_register_pc", false,-1, 31,0);
        tracep->declBus(c+229,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register i_fd_register_pcplus4", false,-1, 31,0);
        tracep->declBit(c+193,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register i_fd_register_en", false,-1);
        tracep->declBit(c+226,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register i_clk", false,-1);
        tracep->declBit(c+227,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register i_rstn", false,-1);
        tracep->declBit(c+186,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_fd_register i_fd_register_clear", false,-1);
        tracep->declBus(c+230,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile o_regfile_rs1_data", false,-1, 31,0);
        tracep->declBus(c+231,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile o_regfile_rs2_data", false,-1, 31,0);
        tracep->declBus(c+194,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile i_regfile_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+195,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile i_regfile_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+162,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile i_regfile_rd_data", false,-1, 31,0);
        tracep->declBus(c+184,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile i_regfile_rd_addr", false,-1, 4,0);
        tracep->declBit(c+183,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile i_regfile_rd_wen", false,-1);
        tracep->declBit(c+226,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile i_clk", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+114+i*1,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_regfile registers", true,(i+0), 31,0);}}
        tracep->declBus(c+157,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_immext o_imm_ext", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_immext i_imm_instr", false,-1, 31,0);
        tracep->declBus(c+146,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_immext i_imm_src", false,-1, 2,0);
        tracep->declBus(c+229,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_adder_pc_plus_4 o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+219,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_adder_pc_plus_4 i_adder_a", false,-1, 31,0);
        tracep->declBus(c+243,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_adder_pc_plus_4 i_adder_b", false,-1, 31,0);
        tracep->declBus(c+70,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_adder_pc_plus_imm o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+82,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_adder_pc_plus_imm i_adder_a", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_adder_pc_plus_imm i_adder_b", false,-1, 31,0);
        tracep->declBus(c+236,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+73,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_src_imm", false,-1, 2,0);
        tracep->declBus(c+74,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_src_rd", false,-1, 1,0);
        tracep->declBit(c+75,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_src_alu_a", false,-1);
        tracep->declBit(c+76,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_src_alu_b", false,-1);
        tracep->declBit(c+178,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_reg_wr_en", false,-1);
        tracep->declBit(c+77,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_mem_wr_en", false,-1);
        tracep->declBus(c+78,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+79,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_alu_ctrl", false,-1, 3,0);
        tracep->declBus(c+80,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_rs1_data", false,-1, 31,0);
        tracep->declBus(c+81,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_rs2_data", false,-1, 31,0);
        tracep->declBus(c+82,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_pc", false,-1, 31,0);
        tracep->declBus(c+83,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+84,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+179,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_rd_addr", false,-1, 4,0);
        tracep->declBus(c+85,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_func3", false,-1, 2,0);
        tracep->declBus(c+86,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_imm_ext", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_pcplus4", false,-1, 31,0);
        tracep->declBus(c+88,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_opcode", false,-1, 6,0);
        tracep->declBit(c+89,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register o_de_register_is_load", false,-1);
        tracep->declBus(c+146,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_src_imm", false,-1, 2,0);
        tracep->declBus(c+147,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_src_rd", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_src_alu_a", false,-1);
        tracep->declBit(c+149,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_src_alu_b", false,-1);
        tracep->declBit(c+150,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_reg_wr_en", false,-1);
        tracep->declBit(c+153,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_mem_wr_en", false,-1);
        tracep->declBus(c+154,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+151,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_alu_ctrl", false,-1, 3,0);
        tracep->declBus(c+230,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_rs1_data", false,-1, 31,0);
        tracep->declBus(c+231,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_rs2_data", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_pc", false,-1, 31,0);
        tracep->declBus(c+194,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+195,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+196,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_rd_addr", false,-1, 4,0);
        tracep->declBus(c+197,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_func3", false,-1, 2,0);
        tracep->declBus(c+157,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_imm_ext", false,-1, 31,0);
        tracep->declBus(c+72,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_pcplus4", false,-1, 31,0);
        tracep->declBit(c+244,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_en", false,-1);
        tracep->declBus(c+198,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_opcode", false,-1, 6,0);
        tracep->declBit(c+155,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_is_load", false,-1);
        tracep->declBit(c+226,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_clk", false,-1);
        tracep->declBit(c+227,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_rstn", false,-1);
        tracep->declBit(c+187,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_de_register i_de_register_clear", false,-1);
        tracep->declBus(c+242,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_ae N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+176,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_ae o_mux_data", false,-1, 31,0);
        tracep->declArray(c+170,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_ae i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+188,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_ae i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+199+i*1,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_ae mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+242,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_be N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+177,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_be o_mux_data", false,-1, 31,0);
        tracep->declArray(c+173,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_be i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+189,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_be i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+202+i*1,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_forward_be mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+160,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_alu o_alu_result", false,-1, 31,0);
        tracep->declBit(c+161,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_alu o_alu_zero", false,-1);
        tracep->declBus(c+158,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_alu i_alu_a", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_alu i_alu_b", false,-1, 31,0);
        tracep->declBus(c+79,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_alu i_alu_ctrl", false,-1, 3,0);
        tracep->declQuad(c+107,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_alu DEBUG_ALU_OP", false,-1, 63,0);
        tracep->declBus(c+245,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_a N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+158,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_a o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+166,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_a i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+75,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_a i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+205+i*1,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_a mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+245,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_b N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_b o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+168,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_b i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+76,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_b i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+207+i*1,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_b mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+236,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+90,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_src_rd", false,-1, 1,0);
        tracep->declBit(c+181,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_reg_wr_en", false,-1);
        tracep->declBit(c+68,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_mem_wr_en", false,-1);
        tracep->declBus(c+69,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_alu_result", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_write_data", false,-1, 31,0);
        tracep->declBus(c+182,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_rd_addr", false,-1, 4,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_func3", false,-1, 2,0);
        tracep->declBus(c+91,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_pcplus4", false,-1, 31,0);
        tracep->declBus(c+92,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_imm_ext", false,-1, 31,0);
        tracep->declBit(c+93,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register o_em_register_is_load", false,-1);
        tracep->declBus(c+74,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_src_rd", false,-1, 1,0);
        tracep->declBit(c+178,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_reg_wr_en", false,-1);
        tracep->declBit(c+77,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_mem_wr_en", false,-1);
        tracep->declBus(c+78,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+160,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_alu_result", false,-1, 31,0);
        tracep->declBus(c+177,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_write_data", false,-1, 31,0);
        tracep->declBus(c+179,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_rd_addr", false,-1, 4,0);
        tracep->declBus(c+85,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_func3", false,-1, 2,0);
        tracep->declBus(c+87,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_pcplus4", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_imm_ext", false,-1, 31,0);
        tracep->declBit(c+244,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_en", false,-1);
        tracep->declBit(c+89,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_em_register_is_load", false,-1);
        tracep->declBit(c+226,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_clk", false,-1);
        tracep->declBit(c+227,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_em_register i_rstn", false,-1);
        tracep->declBus(c+242,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_pc4_imm_m N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+94,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_pc4_imm_m o_mux_data", false,-1, 31,0);
        tracep->declArray(c+102,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_pc4_imm_m i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+90,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_pc4_imm_m i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+109+i*1,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_alu_pc4_imm_m mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+236,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_src_rd", false,-1, 1,0);
        tracep->declBit(c+183,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_reg_wr_en", false,-1);
        tracep->declBus(c+96,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_alu_result", false,-1, 31,0);
        tracep->declBus(c+97,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_rd_data", false,-1, 31,0);
        tracep->declBus(c+184,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_rd_addr", false,-1, 4,0);
        tracep->declBus(c+98,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_pcplus4", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_imm_ext", false,-1, 31,0);
        tracep->declBit(c+100,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_is_load", false,-1);
        tracep->declBus(c+101,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register o_mw_register_for_forward_result", false,-1, 31,0);
        tracep->declBus(c+90,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_src_rd", false,-1, 1,0);
        tracep->declBit(c+181,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_reg_wr_en", false,-1);
        tracep->declBus(c+66,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_alu_result", false,-1, 31,0);
        tracep->declBus(c+228,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_rd_data", false,-1, 31,0);
        tracep->declBus(c+182,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_rd_addr", false,-1, 4,0);
        tracep->declBus(c+91,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_pcplus4", false,-1, 31,0);
        tracep->declBus(c+92,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_imm_ext", false,-1, 31,0);
        tracep->declBit(c+244,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_en", false,-1);
        tracep->declBit(c+93,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_is_load", false,-1);
        tracep->declBus(c+94,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_mw_register_for_forward_result", false,-1, 31,0);
        tracep->declBit(c+226,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_clk", false,-1);
        tracep->declBit(c+227,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mw_register i_rstn", false,-1);
        tracep->declBus(c+245,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_regfile_rd_data_w N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+162,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_regfile_rd_data_w o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+105,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_regfile_rd_data_w i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+100,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_regfile_rd_data_w i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+112+i*1,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_mux_regfile_rd_data_w mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBit(c+185,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit o_hazard_stall_f", false,-1);
        tracep->declBit(c+185,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit o_hazard_stall_d", false,-1);
        tracep->declBit(c+186,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit o_hazard_flush_d", false,-1);
        tracep->declBit(c+187,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit o_hazard_flush_e", false,-1);
        tracep->declBus(c+188,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit o_hazard_forward_ae", false,-1, 1,0);
        tracep->declBus(c+189,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit o_hazard_forward_be", false,-1, 1,0);
        tracep->declBus(c+194,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_rs1_addr_d", false,-1, 4,0);
        tracep->declBus(c+195,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_rs2_addr_d", false,-1, 4,0);
        tracep->declBus(c+179,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_rd_addr_e", false,-1, 4,0);
        tracep->declBus(c+83,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_rs1_addr_e", false,-1, 4,0);
        tracep->declBus(c+84,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_rs2_addr_e", false,-1, 4,0);
        tracep->declBus(c+180,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_src_pc", false,-1, 1,0);
        tracep->declBit(c+89,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_is_load_e", false,-1);
        tracep->declBus(c+182,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_rd_addr_m", false,-1, 4,0);
        tracep->declBit(c+181,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_reg_wr_en_m", false,-1);
        tracep->declBus(c+184,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_rd_addr_w", false,-1, 4,0);
        tracep->declBit(c+183,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit i_hazard_reg_wr_en_w", false,-1);
        tracep->declBit(c+185,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_datapath u_riscv_hazard_unit lwstall", false,-1);
        tracep->declBus(c+146,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_src_imm", false,-1, 2,0);
        tracep->declBus(c+147,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_src_rd", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_src_alu_a", false,-1);
        tracep->declBit(c+149,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_src_alu_b", false,-1);
        tracep->declBit(c+150,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_reg_wr_en", false,-1);
        tracep->declBit(c+153,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_mem_wr_en", false,-1);
        tracep->declBus(c+154,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+151,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+155,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl o_ctrl_is_load", false,-1);
        tracep->declBus(c+198,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl i_ctrl_opcode", false,-1, 6,0);
        tracep->declBus(c+197,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl i_ctrl_funct3", false,-1, 2,0);
        tracep->declBit(c+209,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl i_ctrl_funct7_5b", false,-1);
        tracep->declArray(c+210,"riscv_top u_riscv_pipeline_cpu u_riscv_pipeline_ctrl DEBUG_INSTR", false,-1, 255,0);
        tracep->declBus(c+221,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface o_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+222,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface o_dmem_intf_wen", false,-1);
        tracep->declBus(c+66,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface i_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+68,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface i_dmem_intf_wen", false,-1);
        tracep->declBus(c+224,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface o_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+223,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface o_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+228,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface o_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+67,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface i_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+69,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface i_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+225,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface i_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface i_dmem_intf_func3", false,-1, 2,0);
        tracep->declBus(c+218,"riscv_top u_riscv_pipeline_cpu u_riscv_dmem_interface byte_aligned_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+220,"riscv_top u_riscv_imem o_imem_data", false,-1, 31,0);
        tracep->declBus(c+233,"riscv_top u_riscv_imem i_imem_addr", false,-1, 13,0);
        tracep->declArray(c+1,"riscv_top u_riscv_imem IMEM_INIT_FILE", false,-1, 1023,0);
        tracep->declBus(c+225,"riscv_top u_riscv_dmem o_dmem_data", false,-1, 31,0);
        tracep->declBus(c+224,"riscv_top u_riscv_dmem i_dmem_data", false,-1, 31,0);
        tracep->declBus(c+234,"riscv_top u_riscv_dmem i_dmem_addr", false,-1, 13,0);
        tracep->declBus(c+223,"riscv_top u_riscv_dmem i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBit(c+222,"riscv_top u_riscv_dmem i_dmem_wr_en", false,-1);
        tracep->declBit(c+226,"riscv_top u_riscv_dmem i_clk", false,-1);
        tracep->declArray(c+33,"riscv_top u_riscv_dmem DMEM_INIT_FILE", false,-1, 1023,0);
        tracep->declBus(c+235,"riscv_top u_riscv_dmem i", false,-1, 31,0);
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
        tracep->fullCData(oldp+65,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m),3);
        tracep->fullIData(oldp+66,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m),32);
        tracep->fullIData(oldp+67,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__write_data_m),32);
        tracep->fullBit(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_m));
        tracep->fullCData(oldp+69,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_m),4);
        tracep->fullIData(oldp+70,((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e 
                                    + vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e)),32);
        tracep->fullIData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d),32);
        tracep->fullIData(oldp+72,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d),32);
        tracep->fullCData(oldp+73,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_imm_e),3);
        tracep->fullCData(oldp+74,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_e),2);
        tracep->fullBit(oldp+75,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_a_e));
        tracep->fullBit(oldp+76,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_b_e));
        tracep->fullBit(oldp+77,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_e));
        tracep->fullCData(oldp+78,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_e),4);
        tracep->fullCData(oldp+79,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e),4);
        tracep->fullIData(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_data_e),32);
        tracep->fullIData(oldp+81,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_data_e),32);
        tracep->fullIData(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e),32);
        tracep->fullCData(oldp+83,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_addr_e),5);
        tracep->fullCData(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_addr_e),5);
        tracep->fullCData(oldp+85,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e),3);
        tracep->fullIData(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e),32);
        tracep->fullIData(oldp+87,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_e),32);
        tracep->fullCData(oldp+88,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e),7);
        tracep->fullBit(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_e));
        tracep->fullCData(oldp+90,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_m),2);
        tracep->fullIData(oldp+91,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_m),32);
        tracep->fullIData(oldp+92,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_m),32);
        tracep->fullBit(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_m));
        tracep->fullIData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_m),32);
        tracep->fullCData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_w),2);
        tracep->fullIData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_w),32);
        tracep->fullIData(oldp+97,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_data_w),32);
        tracep->fullIData(oldp+98,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_w),32);
        tracep->fullIData(oldp+99,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_w),32);
        tracep->fullBit(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_w));
        tracep->fullIData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_w),32);
        tracep->fullWData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_m),96);
        tracep->fullQData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_w),64);
        tracep->fullQData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
        tracep->fullIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_regfile_rd_data_w__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_regfile_rd_data_w__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[0]),32);
        tracep->fullIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[1]),32);
        tracep->fullIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[2]),32);
        tracep->fullIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[3]),32);
        tracep->fullIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[4]),32);
        tracep->fullIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[5]),32);
        tracep->fullIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[6]),32);
        tracep->fullIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[7]),32);
        tracep->fullIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[8]),32);
        tracep->fullIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[9]),32);
        tracep->fullIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[10]),32);
        tracep->fullIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[11]),32);
        tracep->fullIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[12]),32);
        tracep->fullIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[13]),32);
        tracep->fullIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[14]),32);
        tracep->fullIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[15]),32);
        tracep->fullIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[16]),32);
        tracep->fullIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[17]),32);
        tracep->fullIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[18]),32);
        tracep->fullIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[19]),32);
        tracep->fullIData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[20]),32);
        tracep->fullIData(oldp+135,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[21]),32);
        tracep->fullIData(oldp+136,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[22]),32);
        tracep->fullIData(oldp+137,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[23]),32);
        tracep->fullIData(oldp+138,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[24]),32);
        tracep->fullIData(oldp+139,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[25]),32);
        tracep->fullIData(oldp+140,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[26]),32);
        tracep->fullIData(oldp+141,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[27]),32);
        tracep->fullIData(oldp+142,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[28]),32);
        tracep->fullIData(oldp+143,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[29]),32);
        tracep->fullIData(oldp+144,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[30]),32);
        tracep->fullIData(oldp+145,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[31]),32);
        tracep->fullCData(oldp+146,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm),3);
        tracep->fullCData(oldp+147,((((0x6fU == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                                      | (0x67U == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))
                                      ? 1U : ((0x37U 
                                               == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))
                                               ? 2U
                                               : 0U))),2);
        tracep->fullBit(oldp+148,((0x17U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))));
        tracep->fullBit(oldp+149,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_alu_b));
        tracep->fullBit(oldp+150,((1U & (~ ((0x23U 
                                             == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))))));
        tracep->fullCData(oldp+151,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__alu_ctrl),4);
        tracep->fullIData(oldp+152,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d),32);
        tracep->fullBit(oldp+153,((0x23U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))));
        tracep->fullCData(oldp+154,((((3U == (0x7fU 
                                              & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                                      | (0x23U == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))
                                      ? ((0x4000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                          ? ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                  ? 3U
                                                  : 1U))
                                          : ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                  ? 3U
                                                  : 1U)))
                                      : 0xfU)),4);
        tracep->fullBit(oldp+155,((3U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))));
        tracep->fullIData(oldp+156,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f))
                                      ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                     [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f]
                                      : 0U)),32);
        tracep->fullIData(oldp+157,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__immediate),32);
        tracep->fullIData(oldp+158,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a),32);
        tracep->fullIData(oldp+159,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b),32);
        tracep->fullIData(oldp+160,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result),32);
        tracep->fullBit(oldp+161,((0U == vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)));
        tracep->fullIData(oldp+162,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data_w),32);
        tracep->fullWData(oldp+163,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_pc),96);
        tracep->fullQData(oldp+166,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_a),64);
        tracep->fullQData(oldp+168,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_b),64);
        tracep->fullWData(oldp+170,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_ae),96);
        tracep->fullWData(oldp+173,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_be),96);
        tracep->fullIData(oldp+176,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae))
                                      ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr
                                     [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae]
                                      : 0U)),32);
        tracep->fullIData(oldp+177,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be_result),32);
        tracep->fullBit(oldp+178,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_e));
        tracep->fullCData(oldp+179,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_e),5);
        tracep->fullCData(oldp+180,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f),2);
        tracep->fullBit(oldp+181,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_m));
        tracep->fullCData(oldp+182,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_m),5);
        tracep->fullBit(oldp+183,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_w));
        tracep->fullCData(oldp+184,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_w),5);
        tracep->fullBit(oldp+185,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall));
        tracep->fullBit(oldp+186,((0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f))));
        tracep->fullBit(oldp+187,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e));
        tracep->fullCData(oldp+188,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae),2);
        tracep->fullCData(oldp+189,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be),2);
        tracep->fullIData(oldp+190,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+191,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+192,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
        tracep->fullBit(oldp+193,((1U & (~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall)))));
        tracep->fullCData(oldp+194,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+195,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                              >> 0x14U))),5);
        tracep->fullCData(oldp+196,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                              >> 7U))),5);
        tracep->fullCData(oldp+197,((7U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                           >> 0xcU))),3);
        tracep->fullCData(oldp+198,((0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)),7);
        tracep->fullIData(oldp+199,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+200,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+201,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+202,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+203,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+204,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+205,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+206,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+207,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+208,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1]),32);
        tracep->fullBit(oldp+209,((1U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                         >> 0x1eU))));
        tracep->fullWData(oldp+210,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR),256);
        tracep->fullIData(oldp+218,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        tracep->fullIData(oldp+219,(vlTOPp->o_riscv_imem_pc),32);
        tracep->fullIData(oldp+220,(vlTOPp->o_riscv_imem_instr),32);
        tracep->fullIData(oldp+221,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->fullBit(oldp+222,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->fullCData(oldp+223,(vlTOPp->o_riscv_dmem_byte_sel),4);
        tracep->fullIData(oldp+224,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->fullIData(oldp+225,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->fullBit(oldp+226,(vlTOPp->i_clk));
        tracep->fullBit(oldp+227,(vlTOPp->i_rstn));
        tracep->fullIData(oldp+228,(((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                                      ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                                          ? 0U : ((1U 
                                                   & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                      : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                                          ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                                              ? 0U : vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                          : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                                              ? ((0xffff0000U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                              : ((0xffffff00U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 7U)))) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))),32);
        tracep->fullIData(oldp+229,(((IData)(4U) + vlTOPp->o_riscv_imem_pc)),32);
        tracep->fullIData(oldp+230,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers
                                    [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                               >> 0xfU))]),32);
        tracep->fullIData(oldp+231,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers
                                    [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                               >> 0x14U))]),32);
        tracep->fullBit(oldp+232,(((0x63U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e)) 
                                   & ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                                       ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                                           ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                                               ? (0U 
                                                  == vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)
                                               : (0U 
                                                  != vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result))
                                           : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                                               ? (0U 
                                                  == vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)
                                               : (0U 
                                                  != vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)))
                                       : ((~ ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e) 
                                              >> 1U)) 
                                          & ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                                              ? (0U 
                                                 != vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)
                                              : (0U 
                                                 == vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)))))));
        tracep->fullSData(oldp+233,((0x3fffU & (vlTOPp->o_riscv_imem_pc 
                                                >> 2U))),14);
        tracep->fullSData(oldp+234,((0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                                                >> 2U))),14);
        tracep->fullIData(oldp+235,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
        tracep->fullIData(oldp+236,(0U),32);
        tracep->fullIData(oldp+237,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data),32);
        tracep->fullWData(oldp+238,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd),128);
        tracep->fullIData(oldp+242,(3U),32);
        tracep->fullIData(oldp+243,(4U),32);
        tracep->fullBit(oldp+244,(1U));
        tracep->fullIData(oldp+245,(2U),32);
    }
}
