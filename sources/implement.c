#include "common.h"
//-------------------------------------------------------------------------
//--------------------------------ARITHMETIC-------------------------------
//-------------------------------------------------------------------------
char ImplAdd  (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD
    
    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "ADD (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] + state->Registers[numRs2];
    state->pc += 4;

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "ADD (after implementation)", __func__))
        return 1;
    return 0;
} 
//-------------------------------------------------------------------------
char ImplAddI (State* state, ImmValue imm,  const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "ADDI (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] + imm;
    state->pc += 4;

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "ADDI (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSub  (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "SUB (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] - state->Registers[numRs2];
    state->pc += 4;

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "SUB (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
//------------------------------LOGICAL OPERS------------------------------
//-------------------------------------------------------------------------
char ImplAnd  (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "AND (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] & state->Registers[numRs2];
    state->pc += 4;

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "AND (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplAndI  (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {
    
    ZERO_POINTER
    ZERO_RD
    if (DumpInstructionsIType (state, imm, numRs1, numRd, "ANDI (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] & imm;
    state->pc += 4;

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "ANDI (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplOr    (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "Or (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] | state->Registers[numRs2];
    state->pc += 4;

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "Or (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplOrI   (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {
    
    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "ORI (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] | imm;
    state->pc += 4;

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "ORI (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplXor   (State* state, const RegNumber numRs1, const RegNumber numRs2, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "Xor (before implementation)", __func__))
        return 1;
    
    state->Registers[numRd] = state->Registers[numRs1] ^ state->Registers[numRs2];
    state->pc += 4;

    if (DumpInstructionsRType (state, numRs1, numRs2, numRd, "Xor (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplXorI   (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {
    
    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "XORI (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] ^ imm;
    state->pc += 4;

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "XORI (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
//----------------------------COMPARISON OPERS-----------------------------
//-------------------------------------------------------------------------
char ImplSltI (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SLTI (before implementation)", __func__))
        return 1;

    if ((SignedRegValue) (state->Registers[numRs1]) < (SignedRegValue)imm)
        state->Registers[numRd] = 1;
    else    
        state->Registers[numRd] = 0;    

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SLTI (after implementation)", __func__))
        return 1;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSltIU (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SLTIU (before implementation)", __func__))
        return 1;

    if ((state->Registers[numRs1]) < (RegValue) imm)
        state->Registers[numRd] = 1;
    else    
        state->Registers[numRd] = 0;      

    state->pc += 4;
    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SLTIU (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
//---------------------------------SHIFTS----------------------------------
//-------------------------------------------------------------------------
char ImplSllI (State* state, ImmValue  imm,     const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SLL (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] << imm;    
    state->pc += 4;

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SLL (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSrlI (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SRLI (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->Registers[numRs1] >> imm;    
    state->pc += 4;

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SRLI (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSraI (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SRAI (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = (RegValue)((SignedRegValue) state->Registers[numRs1] >> imm);     
    state->pc += 4;
    if (DumpInstructionsIType (state, imm, numRs1, numRd, "SRAI (after implementation)", __func__))
        return 1; 
    return 0;
}
//-------------------------------------------------------------------------
//-----------------------------MEMORY OPERS--------------------------------
//-------------------------------------------------------------------------
char ImplLb    (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "LB (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = (RegValue) ((OneByte)(state->Memory.buffer[state->Registers[numRs1] + imm]));
    state->pc += 4;
    if (DumpInstructionsIType (state, imm, numRs1, numRd, "LB (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplLh    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "LH (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = (RegValue) ((TwoBytes)(state->Memory.buffer[state->Registers[numRs1] + imm]));
    state->pc += 4;
    if (DumpInstructionsIType (state, imm, numRs1, numRd, "LH (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplLw    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD
    if (DumpInstructionsIType (state, imm, numRs1, numRd, "LW (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = (RegValue) ((FourBytes)(state->Memory.buffer[state->Registers[numRs1] + imm]));
    state->pc += 4;
    if (DumpInstructionsIType (state, imm, numRs1, numRd, "LW (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSb    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2) { 

    ZERO_POINTER

    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "SB (before implementation)", __func__))
        return 1;

    state->Memory.buffer[state->Registers[numRs1] + imm] = (OneByte) state->Registers[numRs2];
    state->pc += 4; 
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "SB (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSh    (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2) { 

    ZERO_POINTER

    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "SH (before implementation)", __func__))
        return 1;

    state->Memory.buffer[state->Registers[numRs1] + imm] = (TwoBytes) state->Registers[numRs2];
    state->pc += 4;
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "SH (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplSw   (State* state, ImmValue  imm,    const RegNumber numRs1, const RegNumber numRs2) { 

    ZERO_POINTER

    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "SW (before implementation)", __func__))
        return 1;

    state->Memory.buffer[state->Registers[numRs1] + imm] = (FourBytes) state->Registers[numRs2];
    state->pc += 4;
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "SW (before implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
//---------------------------------LUI-------------------------------------
//-------------------------------------------------------------------------
char ImplLui   (State* state, ImmValue  imm,   const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsUType (state, imm, numRd, "LUI (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = imm << 12;
    state->pc += 4;
    if (DumpInstructionsUType (state, imm, numRd, "LUI (after implementation)", __func__))
        return 1;
    return 0;
}

//-------------------------------------------------------------------------
//--------------------------UNCONDITIONAL JUMPS----------------------------
//-------------------------------------------------------------------------
char ImplJal   (State* state, ImmValue  imm,   const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsUType (state, imm, numRd, "JAL (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->pc + 4;
    state->pc += imm;
    if (DumpInstructionsUType (state, imm, numRd, "JAL (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
char ImplJalR  (State* state, ImmValue  imm,  const RegNumber numRs1, const RegNumber numRd) {

    ZERO_POINTER
    ZERO_RD

    if (DumpInstructionsIType (state, imm, numRs1, numRd, "JalR (before implementation)", __func__))
        return 1;

    state->Registers[numRd] = state->pc + 4;
    state->pc = ((state->Registers[numRs1] + imm) >> 1) << 1;
    state->pc = state->pc & ~(1u << 0);
    if (DumpInstructionsIType (state, imm, numRs1, numRd, "JalR (after implementation)", __func__))
        return 1;
    return 0;
}
//-------------------------------------------------------------------------
//                         ###___Conditional jumps___###
//-------------------------------------------------------------------------
char ImplBeq   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BEQ (before implementation)", __func__))
        return 1;

    if (state->Registers[numRs1] == state->Registers[numRs2]) {
        state->pc += imm;
        return 0;
    }
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BEQ (after implementation)", __func__))
        return 1;
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
char ImplBne   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BNE (before implementation)", __func__))
        return 1;

    if (state->Registers[numRs1] != state->Registers[numRs2]) {
        state->pc += imm;
        return 0;
    }
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BNE (after implementation)", __func__))
        return 1;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplBlt   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BLT (before implementation)", __func__))
        return 1;

    if ((SignedRegValue) state->Registers[numRs1] < (SignedRegValue) state->Registers[numRs2]) {
        state->pc += imm;
        return 0;
    }
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BLT (after implementation)", __func__))
        return 1;
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
char ImplBge   (State* state, ImmValue  imm, const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BGE (before implementation)", __func__))
        return 1;

    if ((SignedRegValue) state->Registers[numRs1] >= (SignedRegValue) state->Registers[numRs2]) {
        state->pc += imm;
        return 0;
    }
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BGE (after implementation)", __func__))
        return 1;
    state->pc += 4;
    return 0;
}
//-------------------------------------------------------------------------
char ImplBltU   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER
    
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BLTU (before implementation)", __func__))
        return 1;

    if (state->Registers[numRs1] < state->Registers[numRs2]) {
        state->pc += imm;
        return 0;
    }
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BLTU (after implementation)", __func__))
        return 1;
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
char ImplBgeU   (State* state, ImmValue  imm,   const RegNumber numRs1, const RegNumber numRs2) {

    ZERO_POINTER

    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BGEU (before implementation)", __func__))
        return 1;

    if (state->Registers[numRs1] >= state->Registers[numRs2]) {
        state->pc += imm;
        return 0;
    }
    if (DumpInstructionsBType(state, imm, numRs1, numRs2, "BGEU (after implementation)", __func__))
        return 1;
    state->pc += 4; 
    return 0;
}
//-------------------------------------------------------------------------
//                        ###___Dump functions___###
//-------------------------------------------------------------------------
char DumpInstructionsRType (State* state, const RegNumber numRs1, const RegNumber numRs2, 
                       const RegNumber numRd, const char* instruction, const char* function) {
    
    ZERO_POINTER
    printf ("\n\t\t\t#############################################################\n\t"
             "\t\tInstruction: %s in function %s\n"
            "\t\t\t#############################################################\n", instruction, function);

    printf ("$\t***Rs1-number = %u;\t Rs1-value = %d\n"
            "$\t***Rs2-number = %u;\t Rs2-value = %d\n"
            "$\t***Rd-number  = %u;\t Rd-value  = %d\n", 
            numRs1, state->Registers[numRs1], numRs2, state->Registers[numRs2], numRd, state->Registers[numRd]);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}
//-------------------------------------------------------------------------
char DumpInstructionsIType (State* state, const ImmValue imm, const RegNumber numRs1, 
                            const RegNumber numRd, const char* instruction, const char* function) {

    ZERO_POINTER
    printf ("\n\t\t\t#############################################################\n\t"
             "\t\tInstruction: %s in function %s\n"
            "\t\t\t#############################################################\n", instruction, function);

    printf ("$\t***Imm-value  = %d\n"
            "$\t***Rs1-number = %u;\t Rs1-value = %d\n"
            "$\t***Rd-number  = %u;\t Rd-value  = %d\n", 
            imm, numRs1, state->Registers[numRs1], numRd, state->Registers[numRd]);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}
//-------------------------------------------------------------------------
char DumpInstructionsBType (State* state, const ImmValue imm, const RegNumber numRs1, 
                            const RegNumber numRs2, const char* instruction, const char* function) {

    ZERO_POINTER
    printf ("\n\t\t\t#############################################################\n\t"
             "\t\tInstruction: %s in function %s\n"
            "\t\t\t#############################################################\n", instruction, function);

    printf ("$\t***Imm-value  = %d\n"
            "$\t***Rs1-number = %u;\t Rs1-value = %d\n"
            "$\t***Rs2-number = %u;\t Rs2-value = %d\n", 
            imm, numRs1, state->Registers[numRs1], numRs2, state->Registers[numRs2]);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}
//-------------------------------------------------------------------------
char DumpInstructionsUType (State* state, const ImmValue imm, const RegNumber numRd, 
                            const char* instruction, const char* function) {

    ZERO_POINTER
    printf ("\n\t\t\t#############################################################\n\t"
             "\t\tInstruction: %s in function %s\n"
            "\t\t\t#############################################################\n", instruction, function);

    printf ("$\t***Imm-value  = %d\n"
            "$\t***Rd-number  = %u;\t Rd-value  = %d\n", 
            imm, numRd, state->Registers[numRd]);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}
//-------------------------------------------------------------------------

