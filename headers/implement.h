#ifndef EXEC_H__
#define EXEC_H__

#include "physmemory.h"

typedef uint32_t    PhysAddr;
typedef uint32_t    VirtAddr;
typedef int32_t     SignedRegValue;
typedef uint32_t    RegValue;
typedef int32_t     ImmValue;
typedef uint8_t     const RegNumber;

typedef uint32_t    ProgCounter;

typedef struct State {

    PhysMemory  Memory;
    RegValue    Registers[32];
    ProgCounter pc;
} State; 

//-------------------------------------------------------------------------
//                         ###___Arithmetical___###
//-------------------------------------------------------------------------
char ImplAdd  (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd);
char ImplAddI (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplSub  (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd);
//-------------------------------------------------------------------------
//                           ###___Logical___###
//-------------------------------------------------------------------------
char ImplAnd   (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd);
char ImplAndI  (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplOr    (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd);
char ImplOrI   (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplXor   (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd);
char ImplXorI  (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
//-------------------------------------------------------------------------
//                         ###___Comparison___###
//-------------------------------------------------------------------------
char ImplSltI  (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplSltIU (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd); 
//-------------------------------------------------------------------------
//                          ###___Shifts___###
//-------------------------------------------------------------------------
char ImplSllI  (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplSrlI  (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplSraI  (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
//-------------------------------------------------------------------------
//                          ###___Memory___###
//-------------------------------------------------------------------------
char ImplLb    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplLh    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplLw    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd);
char ImplSb    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2);
char ImplSh    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2);
char ImplSw    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2);
//-------------------------------------------------------------------------
//                           ###___LUI___###
//-------------------------------------------------------------------------
char ImplLui   (State* state, ImmValue  imm,   const RegNumber numRd);
//-------------------------------------------------------------------------
//                      ###___Unconditional jumps___###
//-------------------------------------------------------------------------
char ImplJal   (State* state, ImmValue  imm,   const RegNumber numRd);
char ImplJalR  (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRd);
//-------------------------------------------------------------------------
//                       ###___Conditional jumps___###
//-------------------------------------------------------------------------
char ImplBeq   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2);
char ImplBne   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2);
char ImplBlt   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2);
char ImplBge   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2);
char ImplBltU  (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2);
char ImplBgeU  (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2);
//-------------------------------------------------------------------------
//                        ###___Dump functions___###
//-------------------------------------------------------------------------
char DumpInstructionsRType (State* state, const RegNumber numRs1, const RegNumber numRs2, 
                            const RegNumber numRd, const char* instruction, const char* function); 
char DumpInstructionsIType (State* state, const ImmValue imm, const RegNumber numRs1, 
                            const RegNumber numRd, const char* instruction, const char* function);
char DumpInstructionsBType (State* state, const ImmValue imm, const RegNumber numRs1, 
                            const RegNumber numRs2, const char* instruction, const char* function);
char DumpInstructionsUType (State* state, const ImmValue imm, const RegNumber numRsD, 
                            const char* instruction, const char* function);
//-------------------------------------------------------------------------
//                       ###___Checking for zero___###
//-------------------------------------------------------------------------
#define ZERO_POINTER                    \
                        if (!state)     \
                            return 1;

#define ZERO_RD         \
                        if (!numRd) \
                            return 1; 
#endif