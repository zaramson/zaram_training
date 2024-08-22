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
            tracep->chgCData(oldp+64,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m),3);
            tracep->chgIData(oldp+65,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m),32);
            tracep->chgIData(oldp+66,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__write_data_m),32);
            tracep->chgBit(oldp+67,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_m));
            tracep->chgCData(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_m),4);
            tracep->chgIData(oldp+69,((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e 
                                       + vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e)),32);
            tracep->chgIData(oldp+70,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d),32);
            tracep->chgIData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d),32);
            tracep->chgCData(oldp+72,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_imm_e),3);
            tracep->chgCData(oldp+73,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_e),2);
            tracep->chgBit(oldp+74,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_a_e));
            tracep->chgBit(oldp+75,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_b_e));
            tracep->chgBit(oldp+76,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_e));
            tracep->chgCData(oldp+77,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_e),4);
            tracep->chgCData(oldp+78,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e),4);
            tracep->chgIData(oldp+79,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_data_e),32);
            tracep->chgIData(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_data_e),32);
            tracep->chgIData(oldp+81,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e),32);
            tracep->chgCData(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_addr_e),5);
            tracep->chgCData(oldp+83,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_addr_e),5);
            tracep->chgCData(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e),3);
            tracep->chgIData(oldp+85,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e),32);
            tracep->chgIData(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_e),32);
            tracep->chgCData(oldp+87,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e),7);
            tracep->chgBit(oldp+88,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_e));
            tracep->chgCData(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_m),2);
            tracep->chgIData(oldp+90,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_m),32);
            tracep->chgIData(oldp+91,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_m),32);
            tracep->chgBit(oldp+92,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_m));
            tracep->chgIData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_m),32);
            tracep->chgCData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_w),2);
            tracep->chgIData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_w),32);
            tracep->chgIData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_data_w),32);
            tracep->chgIData(oldp+97,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_w),32);
            tracep->chgIData(oldp+98,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_w),32);
            tracep->chgBit(oldp+99,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_w));
            tracep->chgIData(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_w),32);
            tracep->chgWData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_m),96);
            tracep->chgQData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_w),64);
            tracep->chgQData(oldp+106,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
            tracep->chgIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_regfile_rd_data_w__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_regfile_rd_data_w__DOT__mux_input_arr[1]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[0]),32);
            tracep->chgIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[1]),32);
            tracep->chgIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[2]),32);
            tracep->chgIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[3]),32);
            tracep->chgIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[4]),32);
            tracep->chgIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[5]),32);
            tracep->chgIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[6]),32);
            tracep->chgIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[7]),32);
            tracep->chgIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[8]),32);
            tracep->chgIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[9]),32);
            tracep->chgIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[10]),32);
            tracep->chgIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[11]),32);
            tracep->chgIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[12]),32);
            tracep->chgIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[13]),32);
            tracep->chgIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[14]),32);
            tracep->chgIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[15]),32);
            tracep->chgIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[16]),32);
            tracep->chgIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[17]),32);
            tracep->chgIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[18]),32);
            tracep->chgIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[19]),32);
            tracep->chgIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[20]),32);
            tracep->chgIData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[21]),32);
            tracep->chgIData(oldp+135,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[22]),32);
            tracep->chgIData(oldp+136,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[23]),32);
            tracep->chgIData(oldp+137,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[24]),32);
            tracep->chgIData(oldp+138,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[25]),32);
            tracep->chgIData(oldp+139,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[26]),32);
            tracep->chgIData(oldp+140,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[27]),32);
            tracep->chgIData(oldp+141,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[28]),32);
            tracep->chgIData(oldp+142,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[29]),32);
            tracep->chgIData(oldp+143,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[30]),32);
            tracep->chgIData(oldp+144,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgCData(oldp+145,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm),3);
            tracep->chgCData(oldp+146,((((0x6fU == 
                                          (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                                         | (0x67U == 
                                            (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))
                                         ? 1U : ((0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))
                                                  ? 2U
                                                  : 0U))),2);
            tracep->chgBit(oldp+147,((0x17U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))));
            tracep->chgBit(oldp+148,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_alu_b));
            tracep->chgBit(oldp+149,((1U & (~ ((0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                                               | (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))))));
            tracep->chgCData(oldp+150,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__alu_ctrl),4);
            tracep->chgIData(oldp+151,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d),32);
            tracep->chgBit(oldp+152,((0x23U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))));
            tracep->chgCData(oldp+153,((((3U == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                                         | (0x23U == 
                                            (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))
                                         ? ((0x4000U 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                             ? ((0x2000U 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                 ? 0xfU
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                  ? 3U
                                                  : 1U))
                                             : ((0x2000U 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                 ? 0xfU
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                  ? 3U
                                                  : 1U)))
                                         : 0xfU)),4);
            tracep->chgBit(oldp+154,((3U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))));
            tracep->chgIData(oldp+155,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f))
                                         ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                        [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f]
                                         : 0U)),32);
            tracep->chgIData(oldp+156,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__immediate),32);
            tracep->chgIData(oldp+157,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a),32);
            tracep->chgIData(oldp+158,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b),32);
            tracep->chgIData(oldp+159,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result),32);
            tracep->chgBit(oldp+160,((0U == vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)));
            tracep->chgIData(oldp+161,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data_w),32);
            tracep->chgWData(oldp+162,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_pc),96);
            tracep->chgQData(oldp+165,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_a),64);
            tracep->chgQData(oldp+167,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_b),64);
            tracep->chgWData(oldp+169,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_ae),96);
            tracep->chgWData(oldp+172,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_be),96);
            tracep->chgIData(oldp+175,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae))
                                         ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr
                                        [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae]
                                         : 0U)),32);
            tracep->chgIData(oldp+176,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be_result),32);
            tracep->chgBit(oldp+177,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_e));
            tracep->chgCData(oldp+178,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_e),5);
            tracep->chgCData(oldp+179,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f),2);
            tracep->chgBit(oldp+180,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_m));
            tracep->chgCData(oldp+181,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_m),5);
            tracep->chgBit(oldp+182,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_w));
            tracep->chgCData(oldp+183,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_w),5);
            tracep->chgBit(oldp+184,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall));
            tracep->chgBit(oldp+185,((0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f))));
            tracep->chgBit(oldp+186,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e));
            tracep->chgCData(oldp+187,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae),2);
            tracep->chgCData(oldp+188,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be),2);
            tracep->chgIData(oldp+189,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+190,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+191,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
            tracep->chgBit(oldp+192,((1U & (~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall)))));
            tracep->chgCData(oldp+193,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+194,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                 >> 0x14U))),5);
            tracep->chgCData(oldp+195,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                 >> 7U))),5);
            tracep->chgCData(oldp+196,((7U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                              >> 0xcU))),3);
            tracep->chgCData(oldp+197,((0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)),7);
            tracep->chgIData(oldp+198,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+199,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+200,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+201,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+202,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+203,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+204,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+205,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+206,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+207,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1]),32);
            tracep->chgBit(oldp+208,((1U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                            >> 0x1eU))));
            tracep->chgWData(oldp+209,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR),256);
            tracep->chgIData(oldp+217,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        }
        tracep->chgIData(oldp+218,(vlTOPp->o_riscv_imem_pc),32);
        tracep->chgIData(oldp+219,(vlTOPp->o_riscv_imem_instr),32);
        tracep->chgIData(oldp+220,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->chgBit(oldp+221,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->chgCData(oldp+222,(vlTOPp->o_riscv_dmem_byte_sel),4);
        tracep->chgIData(oldp+223,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->chgIData(oldp+224,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->chgBit(oldp+225,(vlTOPp->i_clk));
        tracep->chgBit(oldp+226,(vlTOPp->i_rstn));
        tracep->chgIData(oldp+227,(((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
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
        tracep->chgIData(oldp+228,(((IData)(4U) + vlTOPp->o_riscv_imem_pc)),32);
        tracep->chgIData(oldp+229,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                              >> 0xfU))]),32);
        tracep->chgIData(oldp+230,(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                              >> 0x14U))]),32);
        tracep->chgBit(oldp+231,(((0x63U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e)) 
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
        tracep->chgSData(oldp+232,((0x3fffU & (vlTOPp->o_riscv_imem_pc 
                                               >> 2U))),14);
        tracep->chgSData(oldp+233,((0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                                               >> 2U))),14);
        tracep->chgIData(oldp+234,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
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
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
