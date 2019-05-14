#ifndef CAPSTONE_PPC_H
#define CAPSTONE_PPC_H

/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013-2014 */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(_MSC_VER) || !defined(_KERNEL_MODE)
#include <stdint.h>
#endif

#include "platform.h"

#ifdef _MSC_VER
#pragma warning(disable:4201)
#endif

//> PPC branch codes for some branch instructions
typedef enum ppc_bc {
    PPC_BC_INVALID  = 0,
    PPC_BC_LT       = (0 << 5) | 12,
    PPC_BC_LE       = (1 << 5) |  4,
    PPC_BC_EQ       = (2 << 5) | 12,
    PPC_BC_GE       = (0 << 5) |  4,
    PPC_BC_GT       = (1 << 5) | 12,
    PPC_BC_NE       = (2 << 5) |  4,
    PPC_BC_UN       = (3 << 5) | 12,
    PPC_BC_NU       = (3 << 5) |  4,

    // extra conditions
    PPC_BC_SO = (4 << 5) | 12,	// summary overflow
    PPC_BC_NS = (4 << 5) | 4,	// not summary overflow
} ppc_bc;

//> PPC branch hint for some branch instructions
typedef enum ppc_bh {
    PPC_BH_INVALID = 0,	// no hint
    PPC_BH_PLUS,	// PLUS hint
    PPC_BH_MINUS,	// MINUS hint
} ppc_bh;

//> PPC registers
typedef enum ppc_reg {
    PPC_REG_INVALID = 0,

    PPC_REG_CARRY,
    PPC_REG_CC,
    PPC_REG_CR0,
    PPC_REG_CR1,
    PPC_REG_CR2,
    PPC_REG_CR3,
    PPC_REG_CR4,
    PPC_REG_CR5,
    PPC_REG_CR6,
    PPC_REG_CR7,
    PPC_REG_CTR,
    PPC_REG_F0,
    PPC_REG_F1,
    PPC_REG_F2,
    PPC_REG_F3,
    PPC_REG_F4,
    PPC_REG_F5,
    PPC_REG_F6,
    PPC_REG_F7,
    PPC_REG_F8,
    PPC_REG_F9,
    PPC_REG_F10,
    PPC_REG_F11,
    PPC_REG_F12,
    PPC_REG_F13,
    PPC_REG_F14,
    PPC_REG_F15,
    PPC_REG_F16,
    PPC_REG_F17,
    PPC_REG_F18,
    PPC_REG_F19,
    PPC_REG_F20,
    PPC_REG_F21,
    PPC_REG_F22,
    PPC_REG_F23,
    PPC_REG_F24,
    PPC_REG_F25,
    PPC_REG_F26,
    PPC_REG_F27,
    PPC_REG_F28,
    PPC_REG_F29,
    PPC_REG_F30,
    PPC_REG_F31,
    PPC_REG_LR,
    PPC_REG_R0,
    PPC_REG_R1,
    PPC_REG_R2,
    PPC_REG_R3,
    PPC_REG_R4,
    PPC_REG_R5,
    PPC_REG_R6,
    PPC_REG_R7,
    PPC_REG_R8,
    PPC_REG_R9,
    PPC_REG_R10,
    PPC_REG_R11,
    PPC_REG_R12,
    PPC_REG_R13,
    PPC_REG_R14,
    PPC_REG_R15,
    PPC_REG_R16,
    PPC_REG_R17,
    PPC_REG_R18,
    PPC_REG_R19,
    PPC_REG_R20,
    PPC_REG_R21,
    PPC_REG_R22,
    PPC_REG_R23,
    PPC_REG_R24,
    PPC_REG_R25,
    PPC_REG_R26,
    PPC_REG_R27,
    PPC_REG_R28,
    PPC_REG_R29,
    PPC_REG_R30,
    PPC_REG_R31,
    PPC_REG_V0,
    PPC_REG_V1,
    PPC_REG_V2,
    PPC_REG_V3,
    PPC_REG_V4,
    PPC_REG_V5,
    PPC_REG_V6,
    PPC_REG_V7,
    PPC_REG_V8,
    PPC_REG_V9,
    PPC_REG_V10,
    PPC_REG_V11,
    PPC_REG_V12,
    PPC_REG_V13,
    PPC_REG_V14,
    PPC_REG_V15,
    PPC_REG_V16,
    PPC_REG_V17,
    PPC_REG_V18,
    PPC_REG_V19,
    PPC_REG_V20,
    PPC_REG_V21,
    PPC_REG_V22,
    PPC_REG_V23,
    PPC_REG_V24,
    PPC_REG_V25,
    PPC_REG_V26,
    PPC_REG_V27,
    PPC_REG_V28,
    PPC_REG_V29,
    PPC_REG_V30,
    PPC_REG_V31,
    PPC_REG_VRSAVE,
    PPC_REG_VS0,
    PPC_REG_VS1,
    PPC_REG_VS2,
    PPC_REG_VS3,
    PPC_REG_VS4,
    PPC_REG_VS5,
    PPC_REG_VS6,
    PPC_REG_VS7,
    PPC_REG_VS8,
    PPC_REG_VS9,
    PPC_REG_VS10,
    PPC_REG_VS11,
    PPC_REG_VS12,
    PPC_REG_VS13,
    PPC_REG_VS14,
    PPC_REG_VS15,
    PPC_REG_VS16,
    PPC_REG_VS17,
    PPC_REG_VS18,
    PPC_REG_VS19,
    PPC_REG_VS20,
    PPC_REG_VS21,
    PPC_REG_VS22,
    PPC_REG_VS23,
    PPC_REG_VS24,
    PPC_REG_VS25,
    PPC_REG_VS26,
    PPC_REG_VS27,
    PPC_REG_VS28,
    PPC_REG_VS29,
    PPC_REG_VS30,
    PPC_REG_VS31,
    PPC_REG_VS32,
    PPC_REG_VS33,
    PPC_REG_VS34,
    PPC_REG_VS35,
    PPC_REG_VS36,
    PPC_REG_VS37,
    PPC_REG_VS38,
    PPC_REG_VS39,
    PPC_REG_VS40,
    PPC_REG_VS41,
    PPC_REG_VS42,
    PPC_REG_VS43,
    PPC_REG_VS44,
    PPC_REG_VS45,
    PPC_REG_VS46,
    PPC_REG_VS47,
    PPC_REG_VS48,
    PPC_REG_VS49,
    PPC_REG_VS50,
    PPC_REG_VS51,
    PPC_REG_VS52,
    PPC_REG_VS53,
    PPC_REG_VS54,
    PPC_REG_VS55,
    PPC_REG_VS56,
    PPC_REG_VS57,
    PPC_REG_VS58,
    PPC_REG_VS59,
    PPC_REG_VS60,
    PPC_REG_VS61,
    PPC_REG_VS62,
    PPC_REG_VS63,

    // extra registers for PPCMapping.c
    PPC_REG_RM,
    PPC_REG_CTR8,
    PPC_REG_LR8,
    PPC_REG_CR1EQ,

    PPC_REG_ENDING,   // <-- mark the end of the list of registers
} ppc_reg;

//> Operand type for instruction's operands
typedef enum ppc_op_type {
    PPC_OP_INVALID = 0, // = CS_OP_INVALID (Uninitialized).
    PPC_OP_REG, // = CS_OP_REG (Register operand).
    PPC_OP_IMM, // = CS_OP_IMM (Immediate operand).
    PPC_OP_MEM, // = CS_OP_MEM (Memory operand).
    PPC_OP_CRX = 64,	// Condition Register field
} ppc_op_type;

// Instruction's operand referring to memory
// This is associated with PPC_OP_MEM operand type above
typedef struct ppc_op_mem {
    ppc_reg base;	// base register
    int32_t disp;	// displacement/offset value
} ppc_op_mem;

typedef struct ppc_op_crx {
    unsigned int scale;
    ppc_reg reg;
    ppc_bc cond;
} ppc_op_crx;

// Instruction operand
typedef struct cs_ppc_op {
    ppc_op_type type;	// operand type
    union {
        ppc_reg reg;	// register value for REG operand
        int32_t imm;		// immediate value for IMM operand
        ppc_op_mem mem;		// base/disp value for MEM operand
        ppc_op_crx crx;		// operand with condition register
    };
} cs_ppc_op;

// Instruction structure
typedef struct cs_ppc {
    // branch code for branch instructions
    ppc_bc bc;

    // branch hint for branch instructions
    ppc_bh bh;

    // if update_cr0 = True, then this 'dot' insn updates CR0
    bool update_cr0;

    // Number of operands of this instruction,
    // or 0 when instruction has no operand.
    uint8_t op_count;
    cs_ppc_op operands[8]; // operands for this instruction.
} cs_ppc;


//> PPC instruction
typedef enum ppc_insn {
    PPC_INS_INVALID = 0,

    PPC_INS_ADD,
    PPC_INS_ADDC,
    PPC_INS_ADDE,
    PPC_INS_ADDI,
    PPC_INS_ADDIC,
    PPC_INS_ADDIS,
    PPC_INS_ADDME,
    PPC_INS_ADDZE,
    PPC_INS_AND,
    PPC_INS_ANDC,
    PPC_INS_ANDIS,
    PPC_INS_ANDI,
    PPC_INS_B,
    PPC_INS_BA,
    PPC_INS_BC,
    PPC_INS_BCCTR,
    PPC_INS_BCCTRL,
    PPC_INS_BCL,
    PPC_INS_BCLR,
    PPC_INS_BCLRL,
    PPC_INS_BCTR,
    PPC_INS_BCTRL,
    PPC_INS_BDNZ,
    PPC_INS_BDNZA,
    PPC_INS_BDNZL,
    PPC_INS_BDNZLA,
    PPC_INS_BDNZLR,
    PPC_INS_BDNZLRL,
    PPC_INS_BDZ,
    PPC_INS_BDZA,
    PPC_INS_BDZL,
    PPC_INS_BDZLA,
    PPC_INS_BDZLR,
    PPC_INS_BDZLRL,
    PPC_INS_BL,
    PPC_INS_BLA,
    PPC_INS_BLR,
    PPC_INS_BLRL,
    PPC_INS_BRINC,
    PPC_INS_CMPD,
    PPC_INS_CMPDI,
    PPC_INS_CMPLD,
    PPC_INS_CMPLDI,
    PPC_INS_CMPLW,
    PPC_INS_CMPLWI,
    PPC_INS_CMPW,
    PPC_INS_CMPWI,
    PPC_INS_CNTLZD,
    PPC_INS_CNTLZW,
    PPC_INS_CREQV,
    PPC_INS_CRXOR,
    PPC_INS_CRAND,
    PPC_INS_CRANDC,
    PPC_INS_CRNAND,
    PPC_INS_CRNOR,
    PPC_INS_CROR,
    PPC_INS_CRORC,
    PPC_INS_DCBA,
    PPC_INS_DCBF,
    PPC_INS_DCBI,
    PPC_INS_DCBST,
    PPC_INS_DCBT,
    PPC_INS_DCBTST,
    PPC_INS_DCBZ,
    PPC_INS_DCBZL,
    PPC_INS_DCCCI,
    PPC_INS_DIVD,
    PPC_INS_DIVDU,
    PPC_INS_DIVW,
    PPC_INS_DIVWU,
    PPC_INS_DSS,
    PPC_INS_DSSALL,
    PPC_INS_DST,
    PPC_INS_DSTST,
    PPC_INS_DSTSTT,
    PPC_INS_DSTT,
    PPC_INS_EIEIO,
    PPC_INS_EQV,
    PPC_INS_EVABS,
    PPC_INS_EVADDIW,
    PPC_INS_EVADDSMIAAW,
    PPC_INS_EVADDSSIAAW,
    PPC_INS_EVADDUMIAAW,
    PPC_INS_EVADDUSIAAW,
    PPC_INS_EVADDW,
    PPC_INS_EVAND,
    PPC_INS_EVANDC,
    PPC_INS_EVCMPEQ,
    PPC_INS_EVCMPGTS,
    PPC_INS_EVCMPGTU,
    PPC_INS_EVCMPLTS,
    PPC_INS_EVCMPLTU,
    PPC_INS_EVCNTLSW,
    PPC_INS_EVCNTLZW,
    PPC_INS_EVDIVWS,
    PPC_INS_EVDIVWU,
    PPC_INS_EVEQV,
    PPC_INS_EVEXTSB,
    PPC_INS_EVEXTSH,
    PPC_INS_EVLDD,
    PPC_INS_EVLDDX,
    PPC_INS_EVLDH,
    PPC_INS_EVLDHX,
    PPC_INS_EVLDW,
    PPC_INS_EVLDWX,
    PPC_INS_EVLHHESPLAT,
    PPC_INS_EVLHHESPLATX,
    PPC_INS_EVLHHOSSPLAT,
    PPC_INS_EVLHHOSSPLATX,
    PPC_INS_EVLHHOUSPLAT,
    PPC_INS_EVLHHOUSPLATX,
    PPC_INS_EVLWHE,
    PPC_INS_EVLWHEX,
    PPC_INS_EVLWHOS,
    PPC_INS_EVLWHOSX,
    PPC_INS_EVLWHOU,
    PPC_INS_EVLWHOUX,
    PPC_INS_EVLWHSPLAT,
    PPC_INS_EVLWHSPLATX,
    PPC_INS_EVLWWSPLAT,
    PPC_INS_EVLWWSPLATX,
    PPC_INS_EVMERGEHI,
    PPC_INS_EVMERGEHILO,
    PPC_INS_EVMERGELO,
    PPC_INS_EVMERGELOHI,
    PPC_INS_EVMHEGSMFAA,
    PPC_INS_EVMHEGSMFAN,
    PPC_INS_EVMHEGSMIAA,
    PPC_INS_EVMHEGSMIAN,
    PPC_INS_EVMHEGUMIAA,
    PPC_INS_EVMHEGUMIAN,
    PPC_INS_EVMHESMF,
    PPC_INS_EVMHESMFA,
    PPC_INS_EVMHESMFAAW,
    PPC_INS_EVMHESMFANW,
    PPC_INS_EVMHESMI,
    PPC_INS_EVMHESMIA,
    PPC_INS_EVMHESMIAAW,
    PPC_INS_EVMHESMIANW,
    PPC_INS_EVMHESSF,
    PPC_INS_EVMHESSFA,
    PPC_INS_EVMHESSFAAW,
    PPC_INS_EVMHESSFANW,
    PPC_INS_EVMHESSIAAW,
    PPC_INS_EVMHESSIANW,
    PPC_INS_EVMHEUMI,
    PPC_INS_EVMHEUMIA,
    PPC_INS_EVMHEUMIAAW,
    PPC_INS_EVMHEUMIANW,
    PPC_INS_EVMHEUSIAAW,
    PPC_INS_EVMHEUSIANW,
    PPC_INS_EVMHOGSMFAA,
    PPC_INS_EVMHOGSMFAN,
    PPC_INS_EVMHOGSMIAA,
    PPC_INS_EVMHOGSMIAN,
    PPC_INS_EVMHOGUMIAA,
    PPC_INS_EVMHOGUMIAN,
    PPC_INS_EVMHOSMF,
    PPC_INS_EVMHOSMFA,
    PPC_INS_EVMHOSMFAAW,
    PPC_INS_EVMHOSMFANW,
    PPC_INS_EVMHOSMI,
    PPC_INS_EVMHOSMIA,
    PPC_INS_EVMHOSMIAAW,
    PPC_INS_EVMHOSMIANW,
    PPC_INS_EVMHOSSF,
    PPC_INS_EVMHOSSFA,
    PPC_INS_EVMHOSSFAAW,
    PPC_INS_EVMHOSSFANW,
    PPC_INS_EVMHOSSIAAW,
    PPC_INS_EVMHOSSIANW,
    PPC_INS_EVMHOUMI,
    PPC_INS_EVMHOUMIA,
    PPC_INS_EVMHOUMIAAW,
    PPC_INS_EVMHOUMIANW,
    PPC_INS_EVMHOUSIAAW,
    PPC_INS_EVMHOUSIANW,
    PPC_INS_EVMRA,
    PPC_INS_EVMWHSMF,
    PPC_INS_EVMWHSMFA,
    PPC_INS_EVMWHSMI,
    PPC_INS_EVMWHSMIA,
    PPC_INS_EVMWHSSF,
    PPC_INS_EVMWHSSFA,
    PPC_INS_EVMWHUMI,
    PPC_INS_EVMWHUMIA,
    PPC_INS_EVMWLSMIAAW,
    PPC_INS_EVMWLSMIANW,
    PPC_INS_EVMWLSSIAAW,
    PPC_INS_EVMWLSSIANW,
    PPC_INS_EVMWLUMI,
    PPC_INS_EVMWLUMIA,
    PPC_INS_EVMWLUMIAAW,
    PPC_INS_EVMWLUMIANW,
    PPC_INS_EVMWLUSIAAW,
    PPC_INS_EVMWLUSIANW,
    PPC_INS_EVMWSMF,
    PPC_INS_EVMWSMFA,
    PPC_INS_EVMWSMFAA,
    PPC_INS_EVMWSMFAN,
    PPC_INS_EVMWSMI,
    PPC_INS_EVMWSMIA,
    PPC_INS_EVMWSMIAA,
    PPC_INS_EVMWSMIAN,
    PPC_INS_EVMWSSF,
    PPC_INS_EVMWSSFA,
    PPC_INS_EVMWSSFAA,
    PPC_INS_EVMWSSFAN,
    PPC_INS_EVMWUMI,
    PPC_INS_EVMWUMIA,
    PPC_INS_EVMWUMIAA,
    PPC_INS_EVMWUMIAN,
    PPC_INS_EVNAND,
    PPC_INS_EVNEG,
    PPC_INS_EVNOR,
    PPC_INS_EVOR,
    PPC_INS_EVORC,
    PPC_INS_EVRLW,
    PPC_INS_EVRLWI,
    PPC_INS_EVRNDW,
    PPC_INS_EVSLW,
    PPC_INS_EVSLWI,
    PPC_INS_EVSPLATFI,
    PPC_INS_EVSPLATI,
    PPC_INS_EVSRWIS,
    PPC_INS_EVSRWIU,
    PPC_INS_EVSRWS,
    PPC_INS_EVSRWU,
    PPC_INS_EVSTDD,
    PPC_INS_EVSTDDX,
    PPC_INS_EVSTDH,
    PPC_INS_EVSTDHX,
    PPC_INS_EVSTDW,
    PPC_INS_EVSTDWX,
    PPC_INS_EVSTWHE,
    PPC_INS_EVSTWHEX,
    PPC_INS_EVSTWHO,
    PPC_INS_EVSTWHOX,
    PPC_INS_EVSTWWE,
    PPC_INS_EVSTWWEX,
    PPC_INS_EVSTWWO,
    PPC_INS_EVSTWWOX,
    PPC_INS_EVSUBFSMIAAW,
    PPC_INS_EVSUBFSSIAAW,
    PPC_INS_EVSUBFUMIAAW,
    PPC_INS_EVSUBFUSIAAW,
    PPC_INS_EVSUBFW,
    PPC_INS_EVSUBIFW,
    PPC_INS_EVXOR,
    PPC_INS_EXTSB,
    PPC_INS_EXTSH,
    PPC_INS_EXTSW,
    PPC_INS_FABS,
    PPC_INS_FADD,
    PPC_INS_FADDS,
    PPC_INS_FCFID,
    PPC_INS_FCFIDS,
    PPC_INS_FCFIDU,
    PPC_INS_FCFIDUS,
    PPC_INS_FCMPU,
    PPC_INS_FCPSGN,
    PPC_INS_FCTID,
    PPC_INS_FCTIDUZ,
    PPC_INS_FCTIDZ,
    PPC_INS_FCTIW,
    PPC_INS_FCTIWUZ,
    PPC_INS_FCTIWZ,
    PPC_INS_FDIV,
    PPC_INS_FDIVS,
    PPC_INS_FMADD,
    PPC_INS_FMADDS,
    PPC_INS_FMR,
    PPC_INS_FMSUB,
    PPC_INS_FMSUBS,
    PPC_INS_FMUL,
    PPC_INS_FMULS,
    PPC_INS_FNABS,
    PPC_INS_FNEG,
    PPC_INS_FNMADD,
    PPC_INS_FNMADDS,
    PPC_INS_FNMSUB,
    PPC_INS_FNMSUBS,
    PPC_INS_FRE,
    PPC_INS_FRES,
    PPC_INS_FRIM,
    PPC_INS_FRIN,
    PPC_INS_FRIP,
    PPC_INS_FRIZ,
    PPC_INS_FRSP,
    PPC_INS_FRSQRTE,
    PPC_INS_FRSQRTES,
    PPC_INS_FSEL,
    PPC_INS_FSQRT,
    PPC_INS_FSQRTS,
    PPC_INS_FSUB,
    PPC_INS_FSUBS,
    PPC_INS_ICBI,
    PPC_INS_ICCCI,
    PPC_INS_ISEL,
    PPC_INS_ISYNC,
    PPC_INS_LA,
    PPC_INS_LBZ,
    PPC_INS_LBZU,
    PPC_INS_LBZUX,
    PPC_INS_LBZX,
    PPC_INS_LD,
    PPC_INS_LDARX,
    PPC_INS_LDBRX,
    PPC_INS_LDU,
    PPC_INS_LDUX,
    PPC_INS_LDX,
    PPC_INS_LFD,
    PPC_INS_LFDU,
    PPC_INS_LFDUX,
    PPC_INS_LFDX,
    PPC_INS_LFIWAX,
    PPC_INS_LFIWZX,
    PPC_INS_LFS,
    PPC_INS_LFSU,
    PPC_INS_LFSUX,
    PPC_INS_LFSX,
    PPC_INS_LHA,
    PPC_INS_LHAU,
    PPC_INS_LHAUX,
    PPC_INS_LHAX,
    PPC_INS_LHBRX,
    PPC_INS_LHZ,
    PPC_INS_LHZU,
    PPC_INS_LHZUX,
    PPC_INS_LHZX,
    PPC_INS_LI,
    PPC_INS_LIS,
    PPC_INS_LMW,
    PPC_INS_LSWI,
    PPC_INS_LVEBX,
    PPC_INS_LVEHX,
    PPC_INS_LVEWX,
    PPC_INS_LVSL,
    PPC_INS_LVSR,
    PPC_INS_LVX,
    PPC_INS_LVXL,
    PPC_INS_LWA,
    PPC_INS_LWARX,
    PPC_INS_LWAUX,
    PPC_INS_LWAX,
    PPC_INS_LWBRX,
    PPC_INS_LWZ,
    PPC_INS_LWZU,
    PPC_INS_LWZUX,
    PPC_INS_LWZX,
    PPC_INS_LXSDX,
    PPC_INS_LXVD2X,
    PPC_INS_LXVDSX,
    PPC_INS_LXVW4X,
    PPC_INS_MBAR,
    PPC_INS_MCRF,
    PPC_INS_MFCR,
    PPC_INS_MFCTR,
    PPC_INS_MFDCR,
    PPC_INS_MFFS,
    PPC_INS_MFLR,
    PPC_INS_MFMSR,
    PPC_INS_MFOCRF,
    PPC_INS_MFSPR,
    PPC_INS_MFSR,
    PPC_INS_MFSRIN,
    PPC_INS_MFTB,
    PPC_INS_MFVSCR,
    PPC_INS_MSYNC,
    PPC_INS_MTCRF,
    PPC_INS_MTCTR,
    PPC_INS_MTDCR,
    PPC_INS_MTFSB0,
    PPC_INS_MTFSB1,
    PPC_INS_MTFSF,
    PPC_INS_MTLR,
    PPC_INS_MTMSR,
    PPC_INS_MTMSRD,
    PPC_INS_MTOCRF,
    PPC_INS_MTSPR,
    PPC_INS_MTSR,
    PPC_INS_MTSRIN,
    PPC_INS_MTVSCR,
    PPC_INS_MULHD,
    PPC_INS_MULHDU,
    PPC_INS_MULHW,
    PPC_INS_MULHWU,
    PPC_INS_MULLD,
    PPC_INS_MULLI,
    PPC_INS_MULLW,
    PPC_INS_NAND,
    PPC_INS_NEG,
    PPC_INS_NOP,
    PPC_INS_ORI,
    PPC_INS_NOR,
    PPC_INS_OR,
    PPC_INS_ORC,
    PPC_INS_ORIS,
    PPC_INS_POPCNTD,
    PPC_INS_POPCNTW,
    PPC_INS_RFCI,
    PPC_INS_RFDI,
    PPC_INS_RFI,
    PPC_INS_RFID,
    PPC_INS_RFMCI,
    PPC_INS_RLDCL,
    PPC_INS_RLDCR,
    PPC_INS_RLDIC,
    PPC_INS_RLDICL,
    PPC_INS_RLDICR,
    PPC_INS_RLDIMI,
    PPC_INS_RLWIMI,
    PPC_INS_RLWINM,
    PPC_INS_RLWNM,
    PPC_INS_SC,
    PPC_INS_SLBIA,
    PPC_INS_SLBIE,
    PPC_INS_SLBMFEE,
    PPC_INS_SLBMTE,
    PPC_INS_SLD,
    PPC_INS_SLW,
    PPC_INS_SRAD,
    PPC_INS_SRADI,
    PPC_INS_SRAW,
    PPC_INS_SRAWI,
    PPC_INS_SRD,
    PPC_INS_SRW,
    PPC_INS_STB,
    PPC_INS_STBU,
    PPC_INS_STBUX,
    PPC_INS_STBX,
    PPC_INS_STD,
    PPC_INS_STDBRX,
    PPC_INS_STDCX,
    PPC_INS_STDU,
    PPC_INS_STDUX,
    PPC_INS_STDX,
    PPC_INS_STFD,
    PPC_INS_STFDU,
    PPC_INS_STFDUX,
    PPC_INS_STFDX,
    PPC_INS_STFIWX,
    PPC_INS_STFS,
    PPC_INS_STFSU,
    PPC_INS_STFSUX,
    PPC_INS_STFSX,
    PPC_INS_STH,
    PPC_INS_STHBRX,
    PPC_INS_STHU,
    PPC_INS_STHUX,
    PPC_INS_STHX,
    PPC_INS_STMW,
    PPC_INS_STSWI,
    PPC_INS_STVEBX,
    PPC_INS_STVEHX,
    PPC_INS_STVEWX,
    PPC_INS_STVX,
    PPC_INS_STVXL,
    PPC_INS_STW,
    PPC_INS_STWBRX,
    PPC_INS_STWCX,
    PPC_INS_STWU,
    PPC_INS_STWUX,
    PPC_INS_STWX,
    PPC_INS_STXSDX,
    PPC_INS_STXVD2X,
    PPC_INS_STXVW4X,
    PPC_INS_SUBF,
    PPC_INS_SUBFC,
    PPC_INS_SUBFE,
    PPC_INS_SUBFIC,
    PPC_INS_SUBFME,
    PPC_INS_SUBFZE,
    PPC_INS_SYNC,
    PPC_INS_TD,
    PPC_INS_TDI,
    PPC_INS_TLBIA,
    PPC_INS_TLBIE,
    PPC_INS_TLBIEL,
    PPC_INS_TLBIVAX,
    PPC_INS_TLBLD,
    PPC_INS_TLBLI,
    PPC_INS_TLBRE,
    PPC_INS_TLBSX,
    PPC_INS_TLBSYNC,
    PPC_INS_TLBWE,
    PPC_INS_TRAP,
    PPC_INS_TW,
    PPC_INS_TWI,
    PPC_INS_VADDCUW,
    PPC_INS_VADDFP,
    PPC_INS_VADDSBS,
    PPC_INS_VADDSHS,
    PPC_INS_VADDSWS,
    PPC_INS_VADDUBM,
    PPC_INS_VADDUBS,
    PPC_INS_VADDUHM,
    PPC_INS_VADDUHS,
    PPC_INS_VADDUWM,
    PPC_INS_VADDUWS,
    PPC_INS_VAND,
    PPC_INS_VANDC,
    PPC_INS_VAVGSB,
    PPC_INS_VAVGSH,
    PPC_INS_VAVGSW,
    PPC_INS_VAVGUB,
    PPC_INS_VAVGUH,
    PPC_INS_VAVGUW,
    PPC_INS_VCFSX,
    PPC_INS_VCFUX,
    PPC_INS_VCMPBFP,
    PPC_INS_VCMPEQFP,
    PPC_INS_VCMPEQUB,
    PPC_INS_VCMPEQUH,
    PPC_INS_VCMPEQUW,
    PPC_INS_VCMPGEFP,
    PPC_INS_VCMPGTFP,
    PPC_INS_VCMPGTSB,
    PPC_INS_VCMPGTSH,
    PPC_INS_VCMPGTSW,
    PPC_INS_VCMPGTUB,
    PPC_INS_VCMPGTUH,
    PPC_INS_VCMPGTUW,
    PPC_INS_VCTSXS,
    PPC_INS_VCTUXS,
    PPC_INS_VEXPTEFP,
    PPC_INS_VLOGEFP,
    PPC_INS_VMADDFP,
    PPC_INS_VMAXFP,
    PPC_INS_VMAXSB,
    PPC_INS_VMAXSH,
    PPC_INS_VMAXSW,
    PPC_INS_VMAXUB,
    PPC_INS_VMAXUH,
    PPC_INS_VMAXUW,
    PPC_INS_VMHADDSHS,
    PPC_INS_VMHRADDSHS,
    PPC_INS_VMINFP,
    PPC_INS_VMINSB,
    PPC_INS_VMINSH,
    PPC_INS_VMINSW,
    PPC_INS_VMINUB,
    PPC_INS_VMINUH,
    PPC_INS_VMINUW,
    PPC_INS_VMLADDUHM,
    PPC_INS_VMRGHB,
    PPC_INS_VMRGHH,
    PPC_INS_VMRGHW,
    PPC_INS_VMRGLB,
    PPC_INS_VMRGLH,
    PPC_INS_VMRGLW,
    PPC_INS_VMSUMMBM,
    PPC_INS_VMSUMSHM,
    PPC_INS_VMSUMSHS,
    PPC_INS_VMSUMUBM,
    PPC_INS_VMSUMUHM,
    PPC_INS_VMSUMUHS,
    PPC_INS_VMULESB,
    PPC_INS_VMULESH,
    PPC_INS_VMULEUB,
    PPC_INS_VMULEUH,
    PPC_INS_VMULOSB,
    PPC_INS_VMULOSH,
    PPC_INS_VMULOUB,
    PPC_INS_VMULOUH,
    PPC_INS_VNMSUBFP,
    PPC_INS_VNOR,
    PPC_INS_VOR,
    PPC_INS_VPERM,
    PPC_INS_VPKPX,
    PPC_INS_VPKSHSS,
    PPC_INS_VPKSHUS,
    PPC_INS_VPKSWSS,
    PPC_INS_VPKSWUS,
    PPC_INS_VPKUHUM,
    PPC_INS_VPKUHUS,
    PPC_INS_VPKUWUM,
    PPC_INS_VPKUWUS,
    PPC_INS_VREFP,
    PPC_INS_VRFIM,
    PPC_INS_VRFIN,
    PPC_INS_VRFIP,
    PPC_INS_VRFIZ,
    PPC_INS_VRLB,
    PPC_INS_VRLH,
    PPC_INS_VRLW,
    PPC_INS_VRSQRTEFP,
    PPC_INS_VSEL,
    PPC_INS_VSL,
    PPC_INS_VSLB,
    PPC_INS_VSLDOI,
    PPC_INS_VSLH,
    PPC_INS_VSLO,
    PPC_INS_VSLW,
    PPC_INS_VSPLTB,
    PPC_INS_VSPLTH,
    PPC_INS_VSPLTISB,
    PPC_INS_VSPLTISH,
    PPC_INS_VSPLTISW,
    PPC_INS_VSPLTW,
    PPC_INS_VSR,
    PPC_INS_VSRAB,
    PPC_INS_VSRAH,
    PPC_INS_VSRAW,
    PPC_INS_VSRB,
    PPC_INS_VSRH,
    PPC_INS_VSRO,
    PPC_INS_VSRW,
    PPC_INS_VSUBCUW,
    PPC_INS_VSUBFP,
    PPC_INS_VSUBSBS,
    PPC_INS_VSUBSHS,
    PPC_INS_VSUBSWS,
    PPC_INS_VSUBUBM,
    PPC_INS_VSUBUBS,
    PPC_INS_VSUBUHM,
    PPC_INS_VSUBUHS,
    PPC_INS_VSUBUWM,
    PPC_INS_VSUBUWS,
    PPC_INS_VSUM2SWS,
    PPC_INS_VSUM4SBS,
    PPC_INS_VSUM4SHS,
    PPC_INS_VSUM4UBS,
    PPC_INS_VSUMSWS,
    PPC_INS_VUPKHPX,
    PPC_INS_VUPKHSB,
    PPC_INS_VUPKHSH,
    PPC_INS_VUPKLPX,
    PPC_INS_VUPKLSB,
    PPC_INS_VUPKLSH,
    PPC_INS_VXOR,
    PPC_INS_WAIT,
    PPC_INS_WRTEE,
    PPC_INS_WRTEEI,
    PPC_INS_XOR,
    PPC_INS_XORI,
    PPC_INS_XORIS,
    PPC_INS_XSABSDP,
    PPC_INS_XSADDDP,
    PPC_INS_XSCMPODP,
    PPC_INS_XSCMPUDP,
    PPC_INS_XSCPSGNDP,
    PPC_INS_XSCVDPSP,
    PPC_INS_XSCVDPSXDS,
    PPC_INS_XSCVDPSXWS,
    PPC_INS_XSCVDPUXDS,
    PPC_INS_XSCVDPUXWS,
    PPC_INS_XSCVSPDP,
    PPC_INS_XSCVSXDDP,
    PPC_INS_XSCVUXDDP,
    PPC_INS_XSDIVDP,
    PPC_INS_XSMADDADP,
    PPC_INS_XSMADDMDP,
    PPC_INS_XSMAXDP,
    PPC_INS_XSMINDP,
    PPC_INS_XSMSUBADP,
    PPC_INS_XSMSUBMDP,
    PPC_INS_XSMULDP,
    PPC_INS_XSNABSDP,
    PPC_INS_XSNEGDP,
    PPC_INS_XSNMADDADP,
    PPC_INS_XSNMADDMDP,
    PPC_INS_XSNMSUBADP,
    PPC_INS_XSNMSUBMDP,
    PPC_INS_XSRDPI,
    PPC_INS_XSRDPIC,
    PPC_INS_XSRDPIM,
    PPC_INS_XSRDPIP,
    PPC_INS_XSRDPIZ,
    PPC_INS_XSREDP,
    PPC_INS_XSRSQRTEDP,
    PPC_INS_XSSQRTDP,
    PPC_INS_XSSUBDP,
    PPC_INS_XSTDIVDP,
    PPC_INS_XSTSQRTDP,
    PPC_INS_XVABSDP,
    PPC_INS_XVABSSP,
    PPC_INS_XVADDDP,
    PPC_INS_XVADDSP,
    PPC_INS_XVCMPEQDP,
    PPC_INS_XVCMPEQSP,
    PPC_INS_XVCMPGEDP,
    PPC_INS_XVCMPGESP,
    PPC_INS_XVCMPGTDP,
    PPC_INS_XVCMPGTSP,
    PPC_INS_XVCPSGNDP,
    PPC_INS_XVCPSGNSP,
    PPC_INS_XVCVDPSP,
    PPC_INS_XVCVDPSXDS,
    PPC_INS_XVCVDPSXWS,
    PPC_INS_XVCVDPUXDS,
    PPC_INS_XVCVDPUXWS,
    PPC_INS_XVCVSPDP,
    PPC_INS_XVCVSPSXDS,
    PPC_INS_XVCVSPSXWS,
    PPC_INS_XVCVSPUXDS,
    PPC_INS_XVCVSPUXWS,
    PPC_INS_XVCVSXDDP,
    PPC_INS_XVCVSXDSP,
    PPC_INS_XVCVSXWDP,
    PPC_INS_XVCVSXWSP,
    PPC_INS_XVCVUXDDP,
    PPC_INS_XVCVUXDSP,
    PPC_INS_XVCVUXWDP,
    PPC_INS_XVCVUXWSP,
    PPC_INS_XVDIVDP,
    PPC_INS_XVDIVSP,
    PPC_INS_XVMADDADP,
    PPC_INS_XVMADDASP,
    PPC_INS_XVMADDMDP,
    PPC_INS_XVMADDMSP,
    PPC_INS_XVMAXDP,
    PPC_INS_XVMAXSP,
    PPC_INS_XVMINDP,
    PPC_INS_XVMINSP,
    PPC_INS_XVMSUBADP,
    PPC_INS_XVMSUBASP,
    PPC_INS_XVMSUBMDP,
    PPC_INS_XVMSUBMSP,
    PPC_INS_XVMULDP,
    PPC_INS_XVMULSP,
    PPC_INS_XVNABSDP,
    PPC_INS_XVNABSSP,
    PPC_INS_XVNEGDP,
    PPC_INS_XVNEGSP,
    PPC_INS_XVNMADDADP,
    PPC_INS_XVNMADDASP,
    PPC_INS_XVNMADDMDP,
    PPC_INS_XVNMADDMSP,
    PPC_INS_XVNMSUBADP,
    PPC_INS_XVNMSUBASP,
    PPC_INS_XVNMSUBMDP,
    PPC_INS_XVNMSUBMSP,
    PPC_INS_XVRDPI,
    PPC_INS_XVRDPIC,
    PPC_INS_XVRDPIM,
    PPC_INS_XVRDPIP,
    PPC_INS_XVRDPIZ,
    PPC_INS_XVREDP,
    PPC_INS_XVRESP,
    PPC_INS_XVRSPI,
    PPC_INS_XVRSPIC,
    PPC_INS_XVRSPIM,
    PPC_INS_XVRSPIP,
    PPC_INS_XVRSPIZ,
    PPC_INS_XVRSQRTEDP,
    PPC_INS_XVRSQRTESP,
    PPC_INS_XVSQRTDP,
    PPC_INS_XVSQRTSP,
    PPC_INS_XVSUBDP,
    PPC_INS_XVSUBSP,
    PPC_INS_XVTDIVDP,
    PPC_INS_XVTDIVSP,
    PPC_INS_XVTSQRTDP,
    PPC_INS_XVTSQRTSP,
    PPC_INS_XXLAND,
    PPC_INS_XXLANDC,
    PPC_INS_XXLNOR,
    PPC_INS_XXLOR,
    PPC_INS_XXLXOR,
    PPC_INS_XXMRGHW,
    PPC_INS_XXMRGLW,
    PPC_INS_XXPERMDI,
    PPC_INS_XXSEL,
    PPC_INS_XXSLDWI,
    PPC_INS_XXSPLTW,
    PPC_INS_BCA,
    PPC_INS_BCLA,

    // extra & alias instructions
    PPC_INS_SLWI,
    PPC_INS_SRWI,
    PPC_INS_SLDI,

    PPC_INS_BTA,
    PPC_INS_CRSET,
    PPC_INS_CRNOT,
    PPC_INS_CRMOVE,
    PPC_INS_CRCLR,
    PPC_INS_MFBR0,
    PPC_INS_MFBR1,
    PPC_INS_MFBR2,
    PPC_INS_MFBR3,
    PPC_INS_MFBR4,
    PPC_INS_MFBR5,
    PPC_INS_MFBR6,
    PPC_INS_MFBR7,
    PPC_INS_MFXER,
    PPC_INS_MFRTCU,
    PPC_INS_MFRTCL,
    PPC_INS_MFDSCR,
    PPC_INS_MFDSISR,
    PPC_INS_MFDAR,
    PPC_INS_MFSRR2,
    PPC_INS_MFSRR3,
    PPC_INS_MFCFAR,
    PPC_INS_MFAMR,
    PPC_INS_MFPID,
    PPC_INS_MFTBLO,
    PPC_INS_MFTBHI,
    PPC_INS_MFDBATU,
    PPC_INS_MFDBATL,
    PPC_INS_MFIBATU,
    PPC_INS_MFIBATL,
    PPC_INS_MFDCCR,
    PPC_INS_MFICCR,
    PPC_INS_MFDEAR,
    PPC_INS_MFESR,
    PPC_INS_MFSPEFSCR,
    PPC_INS_MFTCR,
    PPC_INS_MFASR,
    PPC_INS_MFPVR,
    PPC_INS_MFTBU,
    PPC_INS_MTCR,
    PPC_INS_MTBR0,
    PPC_INS_MTBR1,
    PPC_INS_MTBR2,
    PPC_INS_MTBR3,
    PPC_INS_MTBR4,
    PPC_INS_MTBR5,
    PPC_INS_MTBR6,
    PPC_INS_MTBR7,
    PPC_INS_MTXER,
    PPC_INS_MTDSCR,
    PPC_INS_MTDSISR,
    PPC_INS_MTDAR,
    PPC_INS_MTSRR2,
    PPC_INS_MTSRR3,
    PPC_INS_MTCFAR,
    PPC_INS_MTAMR,
    PPC_INS_MTPID,
    PPC_INS_MTTBL,
    PPC_INS_MTTBU,
    PPC_INS_MTTBLO,
    PPC_INS_MTTBHI,
    PPC_INS_MTDBATU,
    PPC_INS_MTDBATL,
    PPC_INS_MTIBATU,
    PPC_INS_MTIBATL,
    PPC_INS_MTDCCR,
    PPC_INS_MTICCR,
    PPC_INS_MTDEAR,
    PPC_INS_MTESR,
    PPC_INS_MTSPEFSCR,
    PPC_INS_MTTCR,
    PPC_INS_NOT,
    PPC_INS_MR,
    PPC_INS_ROTLD,
    PPC_INS_ROTLDI,
    PPC_INS_CLRLDI,
    PPC_INS_ROTLWI,
    PPC_INS_CLRLWI,
    PPC_INS_ROTLW,
    PPC_INS_SUB,
    PPC_INS_SUBC,
    PPC_INS_LWSYNC,
    PPC_INS_PTESYNC,
    PPC_INS_TDLT,
    PPC_INS_TDEQ,
    PPC_INS_TDGT,
    PPC_INS_TDNE,
    PPC_INS_TDLLT,
    PPC_INS_TDLGT,
    PPC_INS_TDU,
    PPC_INS_TDLTI,
    PPC_INS_TDEQI,
    PPC_INS_TDGTI,
    PPC_INS_TDNEI,
    PPC_INS_TDLLTI,
    PPC_INS_TDLGTI,
    PPC_INS_TDUI,
    PPC_INS_TLBREHI,
    PPC_INS_TLBRELO,
    PPC_INS_TLBWEHI,
    PPC_INS_TLBWELO,
    PPC_INS_TWLT,
    PPC_INS_TWEQ,
    PPC_INS_TWGT,
    PPC_INS_TWNE,
    PPC_INS_TWLLT,
    PPC_INS_TWLGT,
    PPC_INS_TWU,
    PPC_INS_TWLTI,
    PPC_INS_TWEQI,
    PPC_INS_TWGTI,
    PPC_INS_TWNEI,
    PPC_INS_TWLLTI,
    PPC_INS_TWLGTI,
    PPC_INS_TWUI,
    PPC_INS_WAITRSV,
    PPC_INS_WAITIMPL,
    PPC_INS_XNOP,
    PPC_INS_XVMOVDP,
    PPC_INS_XVMOVSP,
    PPC_INS_XXSPLTD,
    PPC_INS_XXMRGHD,
    PPC_INS_XXMRGLD,
    PPC_INS_XXSWAPD,
    PPC_INS_BT,
    PPC_INS_BF,
    PPC_INS_BDNZT,
    PPC_INS_BDNZF,
    PPC_INS_BDZF,
    PPC_INS_BDZT,
    PPC_INS_BFA,
    PPC_INS_BDNZTA,
    PPC_INS_BDNZFA,
    PPC_INS_BDZTA,
    PPC_INS_BDZFA,
    PPC_INS_BTCTR,
    PPC_INS_BFCTR,
    PPC_INS_BTCTRL,
    PPC_INS_BFCTRL,
    PPC_INS_BTL,
    PPC_INS_BFL,
    PPC_INS_BDNZTL,
    PPC_INS_BDNZFL,
    PPC_INS_BDZTL,
    PPC_INS_BDZFL,
    PPC_INS_BTLA,
    PPC_INS_BFLA,
    PPC_INS_BDNZTLA,
    PPC_INS_BDNZFLA,
    PPC_INS_BDZTLA,
    PPC_INS_BDZFLA,
    PPC_INS_BTLR,
    PPC_INS_BFLR,
    PPC_INS_BDNZTLR,
    PPC_INS_BDZTLR,
    PPC_INS_BDZFLR,
    PPC_INS_BTLRL,
    PPC_INS_BFLRL,
    PPC_INS_BDNZTLRL,
    PPC_INS_BDNZFLRL,
    PPC_INS_BDZTLRL,
    PPC_INS_BDZFLRL,

    PPC_INS_ENDING,   // <-- mark the end of the list of instructions
} ppc_insn;

//> Group of PPC instructions
typedef enum ppc_insn_group {
    PPC_GRP_INVALID = 0, // = CS_GRP_INVALID

    //> Generic groups
    // all jump instructions (conditional+direct+indirect jumps)
    PPC_GRP_JUMP,	// = CS_GRP_JUMP

    //> Architecture-specific groups
    PPC_GRP_ALTIVEC = 128,
    PPC_GRP_MODE32,
    PPC_GRP_MODE64,
    PPC_GRP_BOOKE,
    PPC_GRP_NOTBOOKE,
    PPC_GRP_SPE,
    PPC_GRP_VSX,
    PPC_GRP_E500,
    PPC_GRP_PPC4XX,
    PPC_GRP_PPC6XX,

    PPC_GRP_ENDING,   // <-- mark the end of the list of groups
} ppc_insn_group;

#ifdef __cplusplus
}
#endif

#endif
