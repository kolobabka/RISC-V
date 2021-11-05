#include "common.h"
//-------------------------------------------------------------------------
//--------------------------------ARITHMETIC-------------------------------
//-------------------------------------------------------------------------
char ImplAdd  (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] + state->Registors[numRs2];
    state->pc += 4;
    return 0;
} 
//-------------------------------------------------------------------------
char ImplAddI (State* state, ImmValue imm,  const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] + imm;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSub  (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] - state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
//------------------------------LOGICAL OPERS------------------------------
//-------------------------------------------------------------------------
char ImplAnd  (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] & state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplAndI  (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {
    
    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] & imm;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplOr    (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] | state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplOrI   (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {
    
    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] | imm;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplXor   (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] ^ state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplXorI   (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {
    
    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] ^ imm;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
//----------------------------COMPARISON OPERS-----------------------------
//-------------------------------------------------------------------------
char ImplSltI (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    if ((SignedRegValue) (state->Registors[numRs1]) < (SignedRegValue)imm)
        state->Registors[numRd] = 1;
    else    
        state->Registors[numRd] = 0;    

    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSltIU (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    if ((state->Registors[numRs1]) < (RegValue) imm)
        state->Registors[numRd] = 1;
    else    
        state->Registors[numRd] = 0;      

    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
//---------------------------------SHIFTS----------------------------------
//-------------------------------------------------------------------------
char ImplSllI (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] << imm;    
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSrlI (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] >> imm;    
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSraI (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = (RegValue)((SignedRegValue) state->Registors[numRs1] >> imm);     
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
//-----------------------------MEMORY OPERS--------------------------------
//-------------------------------------------------------------------------
char ImplLb    (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = (RegValue) ((OneByte)(state->Memory.buffer[state->Registors[numRs1] + imm]));
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplLh    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = (RegValue) ((TwoBytes)(state->Memory.buffer[state->Registors[numRs1] + imm]));
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplLw    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = (RegValue) ((FourBytes)(state->Memory.buffer[state->Registors[numRs1] + imm]));
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSb    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2) { 

    ZERO_POINTER

    state->Memory.buffer[state->Registors[numRs1] + imm] = (OneByte) state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSh    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2) { 

    ZERO_POINTER

    state->Memory.buffer[state->Registors[numRs1] + imm] = (TwoBytes) state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSw   (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2) { 

    ZERO_POINTER

    state->Memory.buffer[state->Registors[numRs1] + imm] = (FourBytes) state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
//---------------------------------LUI-------------------------------------
//-------------------------------------------------------------------------
char ImplLui   (State* state, ImmValue  imm,   const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = imm << 12;
    state->pc += 4;
    return 0;
}

//-------------------------------------------------------------------------
//--------------------------UNCONDITIONAL JUMPS----------------------------
//-------------------------------------------------------------------------
char ImplJal   (State* state, ImmValue  imm,   const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->pc + 4;
    state->pc += imm;
    return 0;
}
//-------------------------------------------------------------------------
char ImplJalR  (State* state, ImmValue  imm,  const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->pc + 4;
    state->pc = ((state->Registors[numRs1] + imm) >> 1) << 1;
    state->pc = state->pc & ~(1u << 0);
    return 0;
}
//-------------------------------------------------------------------------
//                         ###___Conditional jumps___###
//-------------------------------------------------------------------------
char ImplBeq   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (state->Registors[numRs1] == state->Registors[numRs2]) {
        state->pc += imm;
        return 0;
    }
    
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
char ImplBne   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (state->Registors[numRs1] != state->Registors[numRs2]) {
        state->pc += imm;
        return 0;
    }
    
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplBlt   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if ((SignedRegValue) state->Registors[numRs1] < (SignedRegValue) state->Registors[numRs2]) {
        state->pc += imm;
        return 0;
    }
    
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
char ImplBge   (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if ((SignedRegValue) state->Registors[numRs1] >= (SignedRegValue) state->Registors[numRs2]) {
        state->pc += imm;
        return 0;
    }

    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplBltU   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (state->Registors[numRs1] < state->Registors[numRs2]) {
        state->pc += imm;
        return 0;
    }
    
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
char ImplBgeU   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (state->Registors[numRs1] >= state->Registors[numRs2]) {
        state->pc += imm;
        return 0;
    }
    
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
// char DumpInstructions (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRs2, ) {

    
//     return 0;
// }
//-------------------------------------------------------------------------