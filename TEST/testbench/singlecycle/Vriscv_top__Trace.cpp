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
            tracep->chgIData(oldp+64,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[0]),32);
            tracep->chgIData(oldp+65,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[1]),32);
            tracep->chgIData(oldp+66,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[2]),32);
            tracep->chgIData(oldp+67,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[3]),32);
            tracep->chgIData(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[4]),32);
            tracep->chgIData(oldp+69,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[5]),32);
            tracep->chgIData(oldp+70,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[6]),32);
            tracep->chgIData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[7]),32);
            tracep->chgIData(oldp+72,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[8]),32);
            tracep->chgIData(oldp+73,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[9]),32);
            tracep->chgIData(oldp+74,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[10]),32);
            tracep->chgIData(oldp+75,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[11]),32);
            tracep->chgIData(oldp+76,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[12]),32);
            tracep->chgIData(oldp+77,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[13]),32);
            tracep->chgIData(oldp+78,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[14]),32);
            tracep->chgIData(oldp+79,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[15]),32);
            tracep->chgIData(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[16]),32);
            tracep->chgIData(oldp+81,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[17]),32);
            tracep->chgIData(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[18]),32);
            tracep->chgIData(oldp+83,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[19]),32);
            tracep->chgIData(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[20]),32);
            tracep->chgIData(oldp+85,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[21]),32);
            tracep->chgIData(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[22]),32);
            tracep->chgIData(oldp+87,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[23]),32);
            tracep->chgIData(oldp+88,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[24]),32);
            tracep->chgIData(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[25]),32);
            tracep->chgIData(oldp+90,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[26]),32);
            tracep->chgIData(oldp+91,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[27]),32);
            tracep->chgIData(oldp+92,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[28]),32);
            tracep->chgIData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[29]),32);
            tracep->chgIData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[30]),32);
            tracep->chgIData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers[31]),32);
            tracep->chgIData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+97,(((0U == (IData)(vlTOPp->riscv_top__DOT__src_pc))
                                        ? ((IData)(4U) 
                                           + vlTOPp->riscv_top__DOT__reg_pc_out)
                                        : ((1U == (IData)(vlTOPp->riscv_top__DOT__src_pc))
                                            ? (vlTOPp->riscv_top__DOT__reg_pc_out 
                                               + vlTOPp->riscv_top__DOT__immext_out)
                                            : ((2U 
                                                == (IData)(vlTOPp->riscv_top__DOT__src_pc))
                                                ? vlTOPp->riscv_top__DOT__alu_out
                                                : 0U)))),32);
            tracep->chgIData(oldp+98,(vlTOPp->riscv_top__DOT__reg_pc_out),32);
            tracep->chgIData(oldp+99,(vlTOPp->riscv_top__DOT__imem_instr),32);
            tracep->chgIData(oldp+100,(((IData)(4U) 
                                        + vlTOPp->riscv_top__DOT__reg_pc_out)),32);
            tracep->chgCData(oldp+101,(vlTOPp->riscv_top__DOT__ctrl_src_imm),3);
            tracep->chgCData(oldp+102,(vlTOPp->riscv_top__DOT__ctrl_src_mux41),2);
            tracep->chgBit(oldp+103,((0x17U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__imem_instr))));
            tracep->chgBit(oldp+104,(vlTOPp->riscv_top__DOT__ctrl_src_mux21_rs2));
            tracep->chgBit(oldp+105,((1U & (~ ((0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)) 
                                               | (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__imem_instr)))))));
            tracep->chgBit(oldp+106,((0x23U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__imem_instr))));
            tracep->chgCData(oldp+107,((((3U == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)) 
                                         | (0x23U == 
                                            (0x7fU 
                                             & vlTOPp->riscv_top__DOT__imem_instr)))
                                         ? ((0x4000U 
                                             & vlTOPp->riscv_top__DOT__imem_instr)
                                             ? ((0x2000U 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)
                                                 ? 0xfU
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__imem_instr)
                                                  ? 3U
                                                  : 1U))
                                             : ((0x2000U 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)
                                                 ? 0xfU
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__imem_instr)
                                                  ? 3U
                                                  : 1U)))
                                         : 0xfU)),4);
            tracep->chgCData(oldp+108,(vlTOPp->riscv_top__DOT__ctrl_src_alu),4);
            tracep->chgIData(oldp+109,(vlTOPp->riscv_top__DOT__regfile_rs2_out),32);
            tracep->chgIData(oldp+110,(vlTOPp->riscv_top__DOT__immext_out),32);
            tracep->chgIData(oldp+111,(vlTOPp->riscv_top__DOT__mux21_rs1_out),32);
            tracep->chgIData(oldp+112,(vlTOPp->riscv_top__DOT__mux21_rs2_out),32);
            tracep->chgIData(oldp+113,((vlTOPp->riscv_top__DOT__reg_pc_out 
                                        + vlTOPp->riscv_top__DOT__immext_out)),32);
            tracep->chgIData(oldp+114,(vlTOPp->riscv_top__DOT__alu_out),32);
            tracep->chgBit(oldp+115,((0U == vlTOPp->riscv_top__DOT__alu_out)));
            tracep->chgIData(oldp+116,(vlTOPp->riscv_top__DOT__dmem_intf_wr_data),32);
            tracep->chgCData(oldp+117,(vlTOPp->riscv_top__DOT__dmem_intf_byte_sel),4);
            tracep->chgIData(oldp+118,(((0x4000U & vlTOPp->riscv_top__DOT__imem_instr)
                                         ? ((0x2000U 
                                             & vlTOPp->riscv_top__DOT__imem_instr)
                                             ? 0U : 
                                            ((0x1000U 
                                              & vlTOPp->riscv_top__DOT__imem_instr)
                                              ? (0xffffU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                              : (0xffU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                         : ((0x2000U 
                                             & vlTOPp->riscv_top__DOT__imem_instr)
                                             ? ((0x1000U 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)
                                                 ? 0U
                                                 : vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                             : ((0x1000U 
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
                                                    & vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))),32);
            tracep->chgIData(oldp+119,(vlTOPp->riscv_top__DOT__dmem_rd_data),32);
            tracep->chgIData(oldp+120,(((2U & (IData)(vlTOPp->riscv_top__DOT__ctrl_src_mux41))
                                         ? ((1U & (IData)(vlTOPp->riscv_top__DOT__ctrl_src_mux41))
                                             ? vlTOPp->riscv_top__DOT__immext_out
                                             : ((IData)(4U) 
                                                + vlTOPp->riscv_top__DOT__reg_pc_out))
                                         : ((1U & (IData)(vlTOPp->riscv_top__DOT__ctrl_src_mux41))
                                             ? ((0x4000U 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)
                                                 ? 
                                                ((0x2000U 
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
                                                 : 
                                                ((0x2000U 
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
            tracep->chgBit(oldp+121,(((0x63U == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)) 
                                      & ((0x4000U & vlTOPp->riscv_top__DOT__imem_instr)
                                          ? ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__imem_instr)
                                              ? ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__imem_instr)
                                                  ? 
                                                 (0U 
                                                  == vlTOPp->riscv_top__DOT__alu_out)
                                                  : 
                                                 (0U 
                                                  != vlTOPp->riscv_top__DOT__alu_out))
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__imem_instr)
                                                  ? 
                                                 (0U 
                                                  == vlTOPp->riscv_top__DOT__alu_out)
                                                  : 
                                                 (0U 
                                                  != vlTOPp->riscv_top__DOT__alu_out)))
                                          : ((~ (vlTOPp->riscv_top__DOT__imem_instr 
                                                 >> 0xdU)) 
                                             & ((0x1000U 
                                                 & vlTOPp->riscv_top__DOT__imem_instr)
                                                 ? 
                                                (0U 
                                                 != vlTOPp->riscv_top__DOT__alu_out)
                                                 : 
                                                (0U 
                                                 == vlTOPp->riscv_top__DOT__alu_out)))))));
            tracep->chgCData(oldp+122,(vlTOPp->riscv_top__DOT__src_pc),2);
            tracep->chgSData(oldp+123,((0x3fffU & (vlTOPp->riscv_top__DOT__reg_pc_out 
                                                   >> 2U))),14);
            tracep->chgCData(oldp+124,((0x7fU & vlTOPp->riscv_top__DOT__imem_instr)),7);
            tracep->chgCData(oldp+125,((7U & (vlTOPp->riscv_top__DOT__imem_instr 
                                              >> 0xcU))),3);
            tracep->chgBit(oldp+126,((1U & (vlTOPp->riscv_top__DOT__imem_instr 
                                            >> 0x1eU))));
            tracep->chgWData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
            tracep->chgCData(oldp+135,((0x1fU & (vlTOPp->riscv_top__DOT__imem_instr 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+136,((0x1fU & (vlTOPp->riscv_top__DOT__imem_instr 
                                                 >> 0x14U))),5);
            tracep->chgCData(oldp+137,((0x1fU & (vlTOPp->riscv_top__DOT__imem_instr 
                                                 >> 7U))),5);
            tracep->chgWData(oldp+138,(vlTOPp->riscv_top__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),256);
            tracep->chgIData(oldp+146,(vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
            tracep->chgSData(oldp+147,((0x3fffU & (vlTOPp->riscv_top__DOT__alu_out 
                                                   >> 2U))),14);
        }
        tracep->chgIData(oldp+148,(vlTOPp->o_riscv_imem_pc),32);
        tracep->chgIData(oldp+149,(vlTOPp->o_riscv_imem_instr),32);
        tracep->chgIData(oldp+150,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->chgBit(oldp+151,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->chgCData(oldp+152,(vlTOPp->o_riscv_dmem_byte_sel),4);
        tracep->chgIData(oldp+153,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->chgIData(oldp+154,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->chgBit(oldp+155,(vlTOPp->i_clk));
        tracep->chgBit(oldp+156,(vlTOPp->i_rstn));
        tracep->chgIData(oldp+157,(vlTOPp->riscv_top__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__imem_instr 
                                              >> 0xfU))]),32);
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
