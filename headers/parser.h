#ifndef INTERPRET_H__
#define INTERPRET_H__

#include "implement.h"

typedef int32_t        Command;
typedef uint32_t       Opcode;
typedef int64_t        FileSize;
typedef unsigned char* Mask;

typedef enum Opcodes {

    Op1  = 0b0110011,    //add, sub, xor, or, and
    Op2  = 0b0010011,    //addi, slti, sltiu, xori, ori, andi, slli, srli, srai
    Op3  = 0b0000011,    //lb, lh, lw
    Op4  = 0b0100011,    //sb, sh, sw
    Op5  = 0b0110111,    //lui
    Op6  = 0b1101111,    //jal
    Op7  = 0b1100111,    //jalr
    Op8  = 0b1100011     //beq, bne, blt, bge, bltu, bgeu
    
} Opcodes;

char StartProgramm   (const char* fileName);
char StartParsing    (const FileSize bufferSize, State* state);

#endif