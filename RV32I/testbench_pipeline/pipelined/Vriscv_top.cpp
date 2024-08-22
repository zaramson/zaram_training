// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top.h"
#include "Vriscv_top__Syms.h"

//==========

void Vriscv_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv_top::eval\n"); );
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/sonseokjin/zaram_training/RV32I/core/pipelined/riscv_top.v", 16, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vriscv_top::_eval_initial_loop(Vriscv_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/sonseokjin/zaram_training/RV32I/core/pipelined/riscv_top.v", 16, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__2(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__2\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d;
    IData/*31:0*/ __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d;
    // Body
    __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d;
    __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d;
    vlTOPp->__Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d;
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_imm_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm));
        __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall)
                ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d
                : ((0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f))
                    ? 0U : ((IData)(4U) + vlTOPp->o_riscv_imem_pc)));
        __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall)
                ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d
                : ((0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f))
                    ? 0U : vlTOPp->o_riscv_imem_pc));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_m 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_e) 
               & 1U);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_m 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_e;
        vlTOPp->__Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall)
                ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d
                : ((0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f))
                    ? 0U : vlTOPp->o_riscv_imem_instr));
        vlTOPp->o_riscv_imem_pc = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall)
                                    ? vlTOPp->o_riscv_imem_pc
                                    : ((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f))
                                        ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                       [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f]
                                        : 0U));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__alu_ctrl));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_b_e 
            = (((~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)) 
                & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_alu_b)) 
               & 1U);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_a_e 
            = (((~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)) 
                & (0x17U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))) 
               & 1U);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__write_data_m 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be_result;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_addr_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : (0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                 >> 0xfU)));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_addr_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : (0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                 >> 0x14U)));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_data_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers
               [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                          >> 0xfU))]);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_data_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers
               [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                          >> 0x14U))]);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_w 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_m;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_w 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_m) 
               & 1U);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_data_w 
            = ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                    ? 0U : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                             ? (0xffffU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                             : (0xffU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                    ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                        ? 0U : vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                    : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m))
                        ? ((0xffff0000U & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                          >> 0xfU)))) 
                                           << 0x10U)) 
                           | (0xffffU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                        : ((0xffffff00U & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (0xffU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_w 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_m;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_w 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_m;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_w 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_w 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_m;
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_imm_e = 0U;
        __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d = 0U;
        __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_m = 0U;
        vlTOPp->__Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d = 0U;
        vlTOPp->o_riscv_imem_pc = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_b_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_a_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__write_data_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_addr_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_addr_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_data_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_data_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_w = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_w = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_data_w = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_w = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_w = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_w = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_w = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d 
        = __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_d;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_e 
        = ((IData)(vlTOPp->i_rstn) & ((~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)) 
                                      & (0x23U == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_e 
        = ((IData)(vlTOPp->i_rstn) ? ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                                       ? 0U : (((3U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                                                | (0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))
                                                ? (
                                                   (0x4000U 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                     ? 0xfU
                                                     : 
                                                    ((0x1000U 
                                                      & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                      ? 3U
                                                      : 1U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                     ? 0xfU
                                                     : 
                                                    ((0x1000U 
                                                      & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                      ? 3U
                                                      : 1U)))
                                                : 0xfU))
            : 0U);
    vlTOPp->o_riscv_imem_instr = vlTOPp->riscv_top__DOT__u_riscv_imem__DOT__imem_arr
        [(0x3fffU & (vlTOPp->o_riscv_imem_pc >> 2U))];
    vlTOPp->__Vtableidx1 = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP 
        = vlTOPp->__Vtable1_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP
        [vlTOPp->__Vtableidx1];
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_m 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_e;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_m 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_e) 
               & 1U);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e;
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_m = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_w 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_data_w)) 
            << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_w)));
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_m 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_e;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_m 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e;
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_m = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_regfile_rd_data_w__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_w);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_regfile_rd_data_w__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_w 
                   >> 0x20U));
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : (((0x6fU == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                         | (0x67U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))
                         ? 1U : ((0x37U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))
                                  ? 2U : 0U)));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_e 
            = (((~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)) 
                & (3U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))) 
               & 1U);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : (7U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                              >> 0xcU)));
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__immediate);
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_m[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_m[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_m)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_m))));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_m[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_m)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_m))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d 
        = __Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pcplus4_d;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_m[0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_m[1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_rd_m[2U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_m 
        = ((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_m))
            ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_pc4_imm_m__DOT__mux_input_arr
           [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_rd_m]
            : 0U);
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__3\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    // Body
    if (vlTOPp->o_riscv_dmem_wr_en) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i = 4U;
    }
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 0U;
    if (vlTOPp->o_riscv_dmem_wr_en) {
        if ((1U & (IData)(vlTOPp->o_riscv_dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0xffU & vlTOPp->o_riscv_dmem_wr_data);
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                              >> 2U));
        }
        if ((2U & (IData)(vlTOPp->o_riscv_dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0xffU & (vlTOPp->o_riscv_dmem_wr_data 
                            >> 8U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 8U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                              >> 2U));
        }
        if ((4U & (IData)(vlTOPp->o_riscv_dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0xffU & (vlTOPp->o_riscv_dmem_wr_data 
                            >> 0x10U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0x10U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                              >> 2U));
        }
        if ((8U & (IData)(vlTOPp->o_riscv_dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0xffU & (vlTOPp->o_riscv_dmem_wr_data 
                            >> 0x18U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0x18U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                              >> 2U));
        }
    } else {
        __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
            [(0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                         >> 2U))];
        __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 1U;
        __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                          >> 2U));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0))) 
                & vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1))) 
                & vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2))) 
                & vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3))) 
                & vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4] 
            = __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    }
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__4(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__4\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers__v0;
    // Body
    __Vdlyvval__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers__v0 
        = (((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_w) 
            & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_w)))
            ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data_w
            : vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers
           [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_w]);
    __Vdlyvdim0__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers__v0 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_w;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers[__Vdlyvdim0__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers__v0] 
        = __Vdlyvval__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_regfile__DOT__registers__v0;
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__6(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__6\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_riscv_dmem_wr_en = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_wr_en_m;
    vlTOPp->o_riscv_dmem_byte_sel = ((3U >= (3U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m))
                                      ? (0xfU & ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mem_byte_sel_m) 
                                                 << 
                                                 (3U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m)))
                                      : 0U);
    vlTOPp->o_riscv_dmem_wr_data = ((0x1fU >= (0x18U 
                                               & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m 
                                                  << 3U)))
                                     ? (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__write_data_m 
                                        << (0x18U & 
                                            (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m 
                                             << 3U)))
                                     : 0U);
    vlTOPp->o_riscv_dmem_addr = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data_w 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_regfile_rd_data_w__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_w];
    vlTOPp->o_riscv_dmem_rd_data = vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
        [(0x3fffU & (vlTOPp->o_riscv_dmem_addr >> 2U))];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_w 
        = ((IData)(vlTOPp->i_rstn) & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_m));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_w 
        = ((IData)(vlTOPp->i_rstn) ? (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_m)
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_ae[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_data_e;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_ae[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_m)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data_w))));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_ae[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_m)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data_w))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_be[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_data_e;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_be[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_m)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data_w))));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_be[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__for_forward_result_m)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__regfile_rd_data_w))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
        = ((0x1fU >= (0x18U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m 
                               << 3U))) ? (vlTOPp->o_riscv_dmem_rd_data 
                                           >> (0x18U 
                                               & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result_m 
                                                  << 3U)))
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_ae[0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_ae[1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_ae[2U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_be[0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_be[1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_forward_be[2U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_m 
        = ((IData)(vlTOPp->i_rstn) & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_e));
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_m 
            = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_e;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_e 
            = (((~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)) 
                & (~ ((0x23U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
                      | (0x63U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))))) 
               & 1U);
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_e 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e)
                ? 0U : (0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                 >> 7U)));
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_m = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_e = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_e = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae 
        = (((((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_addr_e) 
              == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_m)) 
             & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_m)) 
            & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_addr_e)))
            ? 2U : (((((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_addr_e) 
                       == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_w)) 
                      & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_w)) 
                     & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs1_addr_e)))
                     ? 1U : 0U));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be 
        = (((((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_addr_e) 
              == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_m)) 
             & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_m)) 
            & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_addr_e)))
            ? 2U : (((((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_addr_e) 
                       == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_w)) 
                      & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__reg_wr_en_w)) 
                     & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rs2_addr_e)))
                     ? 1U : 0U));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
        = vlTOPp->__Vdly__riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d;
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_a 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e)) 
            << 0x20U) | (QData)((IData)(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae))
                                          ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_ae__DOT__mux_input_arr
                                         [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_ae]
                                          : 0U))));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be_result 
        = ((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be))
            ? vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_forward_be__DOT__mux_input_arr
           [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be]
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__alu_ctrl 
        = (((0x33U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)) 
            | (0x13U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))
            ? ((0x4000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                ? ((0x2000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                    ? ((0x1000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                        ? 7U : 6U) : ((0x1000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                       ? ((0x40000000U 
                                           & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                           ? 0xdU : 5U)
                                       : 4U)) : ((0x2000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                  ? 
                                                 ((0x1000U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                   ? 3U
                                                   : 2U)
                                                  : 
                                                 ((0x1000U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                                   ? 1U
                                                   : 
                                                  (((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                     >> 0x1eU) 
                                                    & (0x33U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)))
                                                    ? 8U
                                                    : 0U))))
            : ((0x63U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d))
                ? ((0x4000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                    ? ((0x2000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                        ? 3U : 2U) : ((0x2000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                                       ? 0xfU : 8U))
                : 0U));
    vlTOPp->__Vtableidx3 = (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_alu_b 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_alu_b
        [vlTOPp->__Vtableidx3];
    vlTOPp->__Vtableidx4 = ((0x400U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                       >> 0x14U)) | 
                            ((0x380U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                        >> 5U)) | (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR[0U] 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx4][0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR[1U] 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx4][1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR[2U] 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx4][2U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR[3U] 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx4][3U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR[4U] 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx4][4U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR[5U] 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx4][5U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR[6U] 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx4][6U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR[7U] 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_ctrl__DOT__DEBUG_INSTR
        [vlTOPp->__Vtableidx4][7U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall 
        = ((((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                       >> 0xfU)) == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_e)) 
            | ((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                         >> 0x14U)) == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__rd_addr_e))) 
           & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__is_load_e));
    vlTOPp->__Vtableidx2 = (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm 
        = vlTOPp->__Vtable2_riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm
        [vlTOPp->__Vtableidx2];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_a);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_a 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_b 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e)) 
            << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__forward_be_result)));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__immediate 
        = ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm))
            ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm))
                ? 0U : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm))
                         ? (0xfffff000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d)
                         : ((0xfff00000U & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                           >> 0x1fU)))) 
                                            << 0x14U)) 
                            | ((0xff000U & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d) 
                               | ((0x800U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                             >> 9U)) 
                                  | (0x7feU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                               >> 0x14U)))))))
            : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm))
                ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0x800U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                   << 4U)) | ((0x7e0U 
                                               & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                    >> 7U)))))
                    : ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0xfe0U & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                    >> 7U)))))
                : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__src_imm))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       (0xfffU & (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__instr_d 
                                  >> 0x14U))) : 0U)));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_a_e];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_b);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_alu_b 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_alu_b_e];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result 
        = ((8U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
            ? ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                    ? 0U : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                             ? VL_SHIFTRS_III(32,32,5, vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a, 
                                              (0x1fU 
                                               & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b))
                             : 0U)) : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                                        ? 0U : ((1U 
                                                 & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                                                 ? 0U
                                                 : 
                                                (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
                                                 - vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b))))
            : ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                    ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                        ? (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
                           & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b)
                        : (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
                           | vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b))
                    : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                        ? (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
                           >> (0x1fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b))
                        : (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
                           ^ vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b)))
                : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                    ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                        ? ((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
                            < vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b)
                            ? 1U : 0U) : (VL_LTS_III(1,32,32, vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a, vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b)
                                           ? 1U : 0U))
                    : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_ctrl_e))
                        ? (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
                           << (0x1fU & vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b))
                        : (vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_a 
                           + vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_b)))));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f 
        = ((0x63U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e))
            ? (((0x63U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e)) 
                & ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                    ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                        ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                            ? (0U == vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)
                            : (0U != vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result))
                        : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                            ? (0U == vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)
                            : (0U != vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)))
                    : ((~ ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e) 
                           >> 1U)) & ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__func3_e))
                                       ? (0U != vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)
                                       : (0U == vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)))))
                ? 1U : 0U) : ((0x6fU == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e))
                               ? 1U : ((0x67U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__opcode_e))
                                        ? 2U : 0U)));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_pc[0U] 
        = ((IData)(4U) + vlTOPp->o_riscv_imem_pc);
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_pc[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)) 
                    << 0x20U) | (QData)((IData)((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e 
                                                 + vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e)))));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_pc[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__alu_result)) 
                     << 0x20U) | (QData)((IData)((vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__pc_e 
                                                  + vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__imm_ext_e)))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__flush_e 
        = ((0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__src_pc_f)) 
           | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_hazard_unit__DOT__lwstall));
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_pc[0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_pc[1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipeline_cpu__DOT__u_riscv_pipeline_datapath__DOT__mux_concat_pc[2U];
}

void Vriscv_top::_eval(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->i_clk)) & (IData)(vlTOPp->__Vclklast__TOP__i_clk))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__i_rstn = vlTOPp->i_rstn;
}

VL_INLINE_OPT QData Vriscv_top::_change_request(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vriscv_top::_change_request_1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request_1\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vriscv_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_rstn & 0xfeU))) {
        Verilated::overWidthError("i_rstn");}
}
#endif  // VL_DEBUG
