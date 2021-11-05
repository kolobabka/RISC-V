#include "../common.h"
//-------------------------------------------------------------------------
//--------------------------------ARITHMETIC-------------------------------
//-------------------------------------------------------------------------
char ImplAdd  (State* state, RegNumber numRs1, RegNumber numRs2, RegNumber numRd) {

    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] + state->Registors[numRs2];
    state->pc += 4;
    return 0;
} 
//-------------------------------------------------------------------------
char ImplAddI (State* state, ImmValue imm,  RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] + imm;
    state->pc += 4;
    printf ("***addi = %u\n", state->Registors[numRd]);
    printf ("num = %d\n", numRd);
    return 0;
}
//-------------------------------------------------------------------------
char ImplSub  (State* state, RegNumber numRs1, RegNumber numRs2, RegNumber numRd) {

    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] - state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
//------------------------------LOGICAL OPERS------------------------------
//-------------------------------------------------------------------------
char ImplAnd  (State* state, RegNumber numRs1, RegNumber numRs2, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] & state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplAndI  (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRd) {
    
    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] & imm;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplOr    (State* state, RegNumber numRs1, RegNumber numRs2, RegNumber numRd) {

    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] | state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplOrI   (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRd) {
    
    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] | imm;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplXor   (State* state, RegNumber numRs1, RegNumber numRs2, RegNumber numRd) {

    ZERO_POINTER
    
    state->Registors[numRd] = state->Registors[numRs1] ^ state->Registors[numRs2];
    state->pc += 4;
    printf ("***xor = %u\n", state->Registors[numRd]);
    printf ("num = %d\n", numRd);
    printf ("PC = %d\n", state->pc);
    return 0;
}
//-------------------------------------------------------------------------
char ImplXorI   (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRd) {
    
    ZERO_POINTER

    
    state->Registors[numRd] = state->Registors[numRs1] ^ imm;
    state->pc += 4;
    printf ("***xorI = %u\n", state->Registors[numRd]);
    printf ("num = %d\n", numRd);
    return 0;
}
//-------------------------------------------------------------------------
//----------------------------COMPARISON OPERS-----------------------------
//-------------------------------------------------------------------------
char ImplSltI (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    if ((SignedRegValue) (state->Registors[numRs1]) < (SignedRegValue)imm)
        state->Registors[numRd] = 1;
    else    
        state->Registors[numRd] = 0;    

    state->pc += 4;
    printf ("***SLTI = %u\n", state->Registors[numRd]);
    printf ("num = %d\n", numRd);
    return 0;
}
//-------------------------------------------------------------------------
char ImplSltIU (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    if ((state->Registors[numRs1]) < imm)
        state->Registors[numRd] = 1;
    else    
        state->Registors[numRd] = 0;      
    state->pc += 4;
    printf ("***SLTIU = %u\n", state->Registors[numRd]);
    printf ("num = %d\n", numRd);
    return 0;
}
//-------------------------------------------------------------------------
//---------------------------------SHIFTS----------------------------------
//-------------------------------------------------------------------------
char ImplSllI (State* state, ImmValue  imm, RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] << imm;    
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSrlI (State* state, ImmValue  imm, RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->Registors[numRs1] >> imm;    
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSraI (State* state, ImmValue  imm, RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = (RegValue)((SignedRegValue) state->Registors[numRs1] >> imm);     
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
//-----------------------------MEMORY OPERS--------------------------------
//-------------------------------------------------------------------------
char ImplLb    (State* state, ImmValue  imm, RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = (RegValue) ((OneByte)(state->Memory.buffer[state->Registors[numRs1] + imm]));
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplLh    (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = (RegValue) ((TwoBytes)(state->Memory.buffer[state->Registors[numRs1] + imm]));
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplLw    (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = (RegValue) ((FourBytes)(state->Memory.buffer[state->Registors[numRs1] + imm]));
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSb    (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRs2) { 

    ZERO_POINTER

    state->Memory.buffer[state->Registors[numRs1] + imm] = (OneByte) state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSh    (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRs2) { 

    ZERO_POINTER

    state->Memory.buffer[state->Registors[numRs1] + imm] = (TwoBytes) state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSw   (State* state, ImmValue  imm,    RegNumber numRs1, RegNumber numRs2) { 

    ZERO_POINTER

    state->Memory.buffer[state->Registors[numRs1] + imm] = (FourBytes) state->Registors[numRs2];
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
//---------------------------------LUI-------------------------------------
//-------------------------------------------------------------------------
char ImplLui   (State* state, ImmValue  imm,   RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = imm << 12;
    state->pc += 4;
    return 0;
}

//-------------------------------------------------------------------------
//--------------------------UNCONDITIONAL JUMPS----------------------------
//-------------------------------------------------------------------------
char ImplJal   (State* state, ImmValue  imm,   RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->pc + sizeof (RegValue);
    state->pc += imm << 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplJalR  (State* state, ImmValue  imm,  RegNumber numRs1, RegNumber numRd) {

    ZERO_POINTER

    state->Registors[numRd] = state->pc + sizeof (RegValue);
    state->pc = (state->Registors[numRs1] + imm) << 1;
    state->pc = state->pc & ~(1u << 0);
    return 0;
}
//-------------------------------------------------------------------------
//                         ###___Conditional jumps___###
//-------------------------------------------------------------------------
char ImplBeq   (State* state, ImmValue  imm,   RegNumber numRs1, RegNumber numRs2) {

    ZERO_POINTER

    if (state->Registors[numRs1] == state->Registors[numRs2])
        state->pc += imm;
    
    state->pc += 4; // ????????
    return 0;
}
//-------------------------------------------------------------------------
char ImplBne   (State* state, ImmValue  imm,   RegNumber numRs1, RegNumber numRs2) {

    ZERO_POINTER

    if (state->Registors[numRs1] != state->Registors[numRs2])
        state->pc += imm;
    
    state->pc += 4; // ????????
    return 0;
}
//-------------------------------------------------------------------------
char ImplBlt   (State* state, ImmValue  imm,   RegNumber numRs1, RegNumber numRs2) {

    ZERO_POINTER

    if ((SignedRegValue) state->Registors[numRs1] < (SignedRegValue) state->Registors[numRs2])
        state->pc += imm;
    
    state->pc += 4; // ????????
    return 0;
}
//-------------------------------------------------------------------------
char ImplBge   (State* state, ImmValue  imm,   RegNumber numRs1, RegNumber numRs2) {

    ZERO_POINTER

    if ((SignedRegValue) state->Registors[numRs1] >= (SignedRegValue) state->Registors[numRs2])
        state->pc += imm;
    
    state->pc += 4; // ????????
    return 0;
}
//-------------------------------------------------------------------------
char ImplBltU   (State* state, ImmValue  imm,   RegNumber numRs1, RegNumber numRs2) {

    ZERO_POINTER

    if (state->Registors[numRs1] < state->Registors[numRs2])
        state->pc += imm;
    
    state->pc += 4; // ????????
    return 0;
}
//-------------------------------------------------------------------------
char ImplBgeU   (State* state, ImmValue  imm,   RegNumber numRs1, RegNumber numRs2) {

    ZERO_POINTER

    if (state->Registors[numRs1] >= state->Registors[numRs2])
        state->pc += imm;
    
    state->pc += 4; // ????????
    return 0;
}

