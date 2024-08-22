// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


void Vriscv_top::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vriscv_top::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgWData(oldp+0,(vlTOPp->riscv_top__DOT__u_riscv_imem__DOT__IMEM_INIT_FILE),1024);
            tracep->chgWData(oldp+32,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__DMEM_INIT_FILE),1024);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+64,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm),3);
            tracep->chgCData(oldp+65,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_rd),2);
            tracep->chgBit(oldp+66,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_alu_b));
            tracep->chgCData(oldp+67,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl),4);
            tracep->chgIData(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate),32);
            tracep->chgQData(oldp+69,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
            tracep->chgWData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+79,((0U == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)));
            tracep->chgCData(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc),2);
            tracep->chgIData(oldp+81,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result),32);
            tracep->chgIData(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__regfile_rs2_data),32);
            tracep->chgIData(oldp+83,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc))
                                        ? vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                       [vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc]
                                        : 0U)),32);
            tracep->chgIData(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a),32);
            tracep->chgIData(oldp+85,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b),32);
            tracep->chgWData(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_pc),96);
            tracep->chgWData(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd),128);
            tracep->chgQData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_a),64);
            tracep->chgQData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_b),64);
            tracep->chgIData(oldp+97,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+98,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+99,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[0]),32);
            tracep->chgIData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[1]),32);
            tracep->chgIData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[2]),32);
            tracep->chgIData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[3]),32);
            tracep->chgIData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[4]),32);
            tracep->chgIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[5]),32);
            tracep->chgIData(oldp+106,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[6]),32);
            tracep->chgIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[7]),32);
            tracep->chgIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[8]),32);
            tracep->chgIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[9]),32);
            tracep->chgIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[10]),32);
            tracep->chgIData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[11]),32);
            tracep->chgIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[12]),32);
            tracep->chgIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[13]),32);
            tracep->chgIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[14]),32);
            tracep->chgIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[15]),32);
            tracep->chgIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[16]),32);
            tracep->chgIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[17]),32);
            tracep->chgIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[18]),32);
            tracep->chgIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[19]),32);
            tracep->chgIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[20]),32);
            tracep->chgIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[21]),32);
            tracep->chgIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[22]),32);
            tracep->chgIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[23]),32);
            tracep->chgIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[24]),32);
            tracep->chgIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[25]),32);
            tracep->chgIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[26]),32);
            tracep->chgIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[27]),32);
            tracep->chgIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[28]),32);
            tracep->chgIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[29]),32);
            tracep->chgIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[30]),32);
            tracep->chgIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[31]),32);
            tracep->chgIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+135,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+136,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+137,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+138,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+139,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[3]),32);
            tracep->chgIData(oldp+140,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        }
        tracep->chgIData(oldp+141,(vlTOPp->o_riscv_imem_pc),32);
        tracep->chgIData(oldp+142,(vlTOPp->o_riscv_imem_instr),32);
        tracep->chgIData(oldp+143,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->chgBit(oldp+144,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->chgCData(oldp+145,(vlTOPp->o_riscv_dmem_byte_sel),4);
        tracep->chgIData(oldp+146,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->chgIData(oldp+147,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->chgBit(oldp+148,(vlTOPp->i_clk));
        tracep->chgBit(oldp+149,(vlTOPp->i_rstn));
        tracep->chgBit(oldp+150,((0x17U == (0x7fU & vlTOPp->o_riscv_imem_instr))));
        tracep->chgBit(oldp+151,((1U & (~ ((0x23U == 
                                            (0x7fU 
                                             & vlTOPp->o_riscv_imem_instr)) 
                                           | (0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->o_riscv_imem_instr)))))));
        tracep->chgIData(oldp+152,(((0x4000U & vlTOPp->o_riscv_imem_instr)
                                     ? ((0x2000U & vlTOPp->o_riscv_imem_instr)
                                         ? 0U : ((0x1000U 
                                                  & vlTOPp->o_riscv_imem_instr)
                                                  ? 
                                                 (0xffffU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                  : 
                                                 (0xffU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                     : ((0x2000U & vlTOPp->o_riscv_imem_instr)
                                         ? ((0x1000U 
                                             & vlTOPp->o_riscv_imem_instr)
                                             ? 0U : vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                         : ((0x1000U 
                                             & vlTOPp->o_riscv_imem_instr)
                                             ? ((0xffff0000U 
                                                 & ((- (IData)(
                                                               (1U 
                                                                & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                   >> 0xfU)))) 
                                                    << 0x10U)) 
                                                | (0xffffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                             : ((0xffffff00U 
                                                 & ((- (IData)(
                                                               (1U 
                                                                & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                   >> 7U)))) 
                                                    << 8U)) 
                                                | (0xffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))),32);
        tracep->chgBit(oldp+153,((0x23U == (0x7fU & vlTOPp->o_riscv_imem_instr))));
        tracep->chgCData(oldp+154,((((3U == (0x7fU 
                                             & vlTOPp->o_riscv_imem_instr)) 
                                     | (0x23U == (0x7fU 
                                                  & vlTOPp->o_riscv_imem_instr)))
                                     ? ((0x4000U & vlTOPp->o_riscv_imem_instr)
                                         ? ((0x2000U 
                                             & vlTOPp->o_riscv_imem_instr)
                                             ? 0xfU
                                             : ((0x1000U 
                                                 & vlTOPp->o_riscv_imem_instr)
                                                 ? 3U
                                                 : 1U))
                                         : ((0x2000U 
                                             & vlTOPp->o_riscv_imem_instr)
                                             ? 0xfU
                                             : ((0x1000U 
                                                 & vlTOPp->o_riscv_imem_instr)
                                                 ? 3U
                                                 : 1U)))
                                     : 0xfU)),4);
        tracep->chgIData(oldp+155,(((IData)(4U) + vlTOPp->o_riscv_imem_pc)),32);
        tracep->chgIData(oldp+156,((vlTOPp->o_riscv_imem_pc 
                                    + vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate)),32);
        tracep->chgIData(oldp+157,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->o_riscv_imem_instr 
                                              >> 0xfU))]),32);
        tracep->chgIData(oldp+158,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr
                                   [vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_rd]),32);
        tracep->chgCData(oldp+159,((0x1fU & (vlTOPp->o_riscv_imem_instr 
                                             >> 0xfU))),5);
        tracep->chgCData(oldp+160,((0x1fU & (vlTOPp->o_riscv_imem_instr 
                                             >> 0x14U))),5);
        tracep->chgCData(oldp+161,((0x1fU & (vlTOPp->o_riscv_imem_instr 
                                             >> 7U))),5);
        tracep->chgCData(oldp+162,((0x7fU & vlTOPp->o_riscv_imem_instr)),7);
        tracep->chgCData(oldp+163,((7U & (vlTOPp->o_riscv_imem_instr 
                                          >> 0xcU))),3);
        tracep->chgBit(oldp+164,((1U & (vlTOPp->o_riscv_imem_instr 
                                        >> 0x1eU))));
        tracep->chgBit(oldp+165,(((0x63U == (0x7fU 
                                             & vlTOPp->o_riscv_imem_instr)) 
                                  & ((0x4000U & vlTOPp->o_riscv_imem_instr)
                                      ? ((0x2000U & vlTOPp->o_riscv_imem_instr)
                                          ? ((0x1000U 
                                              & vlTOPp->o_riscv_imem_instr)
                                              ? (0U 
                                                 == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                                              : (0U 
                                                 != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result))
                                          : ((0x1000U 
                                              & vlTOPp->o_riscv_imem_instr)
                                              ? (0U 
                                                 == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                                              : (0U 
                                                 != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)))
                                      : ((~ (vlTOPp->o_riscv_imem_instr 
                                             >> 0xdU)) 
                                         & ((0x1000U 
                                             & vlTOPp->o_riscv_imem_instr)
                                             ? (0U 
                                                != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                                             : (0U 
                                                == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)))))));
        tracep->chgSData(oldp+166,((0x3fffU & (vlTOPp->o_riscv_imem_pc 
                                               >> 2U))),14);
        tracep->chgSData(oldp+167,((0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                                               >> 2U))),14);
        tracep->chgIData(oldp+168,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
    }
}

void Vriscv_top::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
