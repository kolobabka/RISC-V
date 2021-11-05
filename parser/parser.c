#include "../common.h"

static char CommandRecognizer (const Mask command, State *state);

static FileSize SizeText (const char* textName)
{

  struct stat size;
 	stat (textName, &size);

  return (FileSize) size.st_size;
}

static char ReadCommands (const char* fileName, const FileSize fileSize, State* state) {

    if (IS_NULL (fileName))
        return 1;
    if (IS_NULL (state))
        return 1;

    int input = open (fileName, O_RDONLY);
    if (PerrorCheck (input))
        return -1;

    int error = read (input, state->Memory.buffer, (FileSize)fileSize);
    if (PerrorCheck (error))
        return 1;

    error = close (input);
    if (PerrorCheck (error))
        return 1;
} 

char StartProgramm (const char* fileName) {

    if (IS_NULL (fileName))
        return 1;
    State state = {};
    FileSize fileSize = SizeText (fileName);
    if (fileSize > PHYS_MEM_SIZE) {

        printf ("Too little memory for these commands\n");
        return 1;
    }
    if (ReadCommands (fileName, fileSize, &state))
        return 1;
        
    if (StartParsing (fileSize, &state))
        return 1;    
    
    printf ("State.Registors[12] = %u\n", state.Registors[12]);
    return 0;
}

char StartParsing (const FileSize bufferSize, State *state) {

    if (IS_NULL (state))
        return 1;

    for (state->pc; state->pc < bufferSize; state->pc)
        if (CommandRecognizer ((Mask) state->Memory.buffer + state->pc, state))
            return 1;

    return 0;
}

static Command RecognizeBits (const Mask command, const int start, const int end) {
    

    if (IS_NULL (command))
        return 1;
    Command res = 0;

    for (int i = start; i <= end; i++)
        res |= ((command [3 - i / 8] >> (i % 8)) & 1) << (i - start);

    return res;

}

static int ExtendedImm (ImmValue imm, char startBit) {

    char highestBit = (imm & (1 << startBit)) >> startBit;

    int extendedImm = imm;

    for (int i = startBit + 1; i < 32; i++)
        extendedImm ^= (highestBit << i);

    return extendedImm;
}

static int RecognizeCommand1   (const ImmValue funct3, const RegNumber rs2, const RegNumber rs1,
                                const ImmValue funct7, const RegNumber rd, State* state) { //add, sub, xor, or, and

    
    switch (funct7) {
                    

        case 0b000: { //add, xor, or, add

            if (funct3 == 0)
                return ImplAdd (state, rs1, rs2, rd);
            else if (funct3 == 4) 
                return ImplXor (state, rs1, rs2, rd);
            else if (funct3 == 6) 
                return ImplOr  (state, rs1, rs2, rd);
            else if (funct3 == 7) 
                return ImplAnd (state, rs1, rs2, rd);
            
            return -1;
        }
        case 0b100000: //sub
            return ImplSub  (state, rs1, rs2, rd);
    }
    return -1;
}

static int ShiftRecognizer (const ImmValue funct7, const ImmValue shamt, const RegNumber rs1,
                            const ImmValue funct3, const RegNumber rd, State* state) {

    if (funct3 == 0b001) //slli
        return ImplSllI (state, shamt, rs1, rd);
    else if (funct3 == 0b101) { //srli or srai

    if (funct7 == 0)//srli 
        return ImplSrlI (state, shamt, rs1, rd);
    else if (funct7 == 32) //srai
        return ImplSraI (state, shamt, rs1, rd);
    }
    return -1;

}

static int ArithmeticRecognizer   (const ImmValue imm, const RegNumber rs1, 
                                   const ImmValue funct3, const RegNumber rd, State* state) {
    
    switch (funct3) {

        case 0b000:
            printf ("addi\n");
            return ImplAddI     (state, imm, rs1, rd);
        case 0b010:
            return ImplSltI     (state, imm, rs1, rd);
        case 0b011:
            return ImplSltIU    (state, imm, rs1, rd);
        case 0b100:
            return ImplXorI     (state, imm, rs1, rd);
        case 0b110:
            return ImplOrI      (state, imm, rs1, rd);
        case 0b111:
            return ImplAddI     (state, imm, rs1, rd);
        default:
            printf ("Unexpected middle constant in function %s\n", __func__);
            return 1;
    }
}

static int RecognizeCommand2 (const Mask command, const RegNumber rs1,
                              const ImmValue funct3, const RegNumber rd, State* state) {

    if (funct3 == 0b101 || funct3 == 0b001) { //slli, srli, srai //TODO Maybe extend, function is wrong and so on :( 

        ImmValue shamt       = RecognizeBits (command, 20, 24);
        ImmValue funct7  = RecognizeBits (command, 25, 31);

        return ShiftRecognizer (funct7, shamt, rs1, funct3, rd, state);
    }

    ImmValue imm = RecognizeBits (command, 20, 31);

    imm = ExtendedImm (imm, 11);
    return ArithmeticRecognizer (imm, rs1, funct3, rd, state);
}

static int RecognizeCommand3   (const ImmValue imm, const RegNumber rs1, const ImmValue funct3, 
                                const RegNumber rd, State* state) {

    switch (funct3) {

        case 0b000:
            return ImplLb (state, imm, rs1, rd);
        case 0b001:
            return ImplLh (state, imm, rs1, rd);
        case 0b010:
            return ImplLw (state, imm, rs1, rd);

    }
    return -1;
}

static int RecognizeCommand4 (const ImmValue imm, const RegNumber rs2, const RegNumber rs1,
                              const ImmValue funct3, State* state) {

    switch (funct3) { //!TODO

        case 0b000:
            return ImplSb (state, imm, rs1, rs2);
        case 0b001:
            return ImplSh (state, imm, rs1, rs2);
        case 0b010:
            return ImplSw (state, imm, rs1, rs2);

    }
    return -1;
}

static int BranchOpsHandle (State *state, const ImmValue imm, const RegNumber rs2, const RegNumber rs1,
                            const ImmValue funct3) {

    switch (funct3) { //!TODO

        case 0b000:
            printf ("beq\n");//return beq (...);
            return ImplBeq (state, imm, rs1, rs2);
        case 0b001:
            printf ("bne\n");//return bne (...);
            return ImplBne (state, imm, rs1, rs2);
        case 0b100:
            printf ("blt\n");//return blt (...);
            return ImplBlt (state, imm, rs1, rs2);
        case 0b101:
            printf ("bge\n");//return bge (...);
            return ImplBge (state, imm, rs1, rs2);
        case 0b110:
            printf ("bltu\n");//return bltu (...);
            return ImplBltU (state, imm, rs1, rs2);
        case 0b111:
            printf ("bgeu\n");//return bgeu (...);
            return ImplBgeU (state, imm, rs1, rs2);
    }
    return -1;
}

static char CommandRecognizer (const Mask command, State *state) {

    Opcode opcode = RecognizeBits (command, 0, 6);
    printf ("opcode = %d\n", opcode);

    switch (opcode) {

        case Op1: { //add, sub, xor, or, and

            printf ("I'm here!\n");
            
            RegNumber rd         = RecognizeBits (command, 7, 11);
            ImmValue funct3      = RecognizeBits (command, 12, 14);
            RegNumber rs1        = RecognizeBits (command, 15, 19);
            RegNumber rs2        = RecognizeBits (command, 20, 24);
            ImmValue funct7      = RecognizeBits (command, 25, 31);

            return RecognizeCommand1 (funct3, rs2, rs1, funct7, rd, state);
        }
        case Op2: {   //addi, slti, sltiu, xori, ori, andi, slli, srli, srai

            RegNumber rd         = RecognizeBits (command, 7, 11);
            ImmValue funct3      = RecognizeBits (command, 12, 14);
            RegNumber rs1        = RecognizeBits (command, 15, 19);

            return RecognizeCommand2 (command, rs1, funct3, rd, state);
        }
        case Op3: {    //lb, lh, lw

            RegNumber rd         = RecognizeBits (command, 7, 11);
            ImmValue funct3      = RecognizeBits (command, 12, 14);
            RegNumber rs1        = RecognizeBits (command, 15, 19);
            ImmValue imm         = RecognizeBits (command, 20, 31);

            imm = ExtendedImm (imm, 11);
            return RecognizeCommand3 (imm, rs1, funct3, rd, state);
        }
        case Op4: {   //sb, sh, sw

            ImmValue funct3      = RecognizeBits (command, 12, 14);
            RegNumber rs1        = RecognizeBits (command, 15, 19);
            RegNumber rs2        = RecognizeBits (command, 20, 24);

            ImmValue imm = 0;

            imm |=  RecognizeBits (command, 7, 11) | RecognizeBits (command, 25, 31)  << 5; 
            imm = ExtendedImm (imm, 11);
            return RecognizeCommand4 (imm, rs2, rs1, funct3, state);
        }
        case Op5: { //lui

            RegNumber rd          = RecognizeBits (command, 7, 11);
            ImmValue imm          = RecognizeBits (command, 12, 31);
            imm = ExtendedImm (imm, 19);
            return ImplLui (state, imm, rd);
        }
        case Op6: { //jal

            for (int i = 0; i < 32; i++) {

                printf ("%d ", (command [i / 8] >> (i % 8)) & 1);

            }
            printf ("\n");

            RegNumber rd          = RecognizeBits (command, 7, 11);
            ImmValue imm          = 0;
            imm                   |= (RecognizeBits (command, 21, 30) << 1) + (RecognizeBits (command, 20, 20)  << 11) + 
                                     (RecognizeBits (command, 12, 19)  << 12) + (RecognizeBits (command, 31, 31)  << 20);
            printf ("imm before extend = %u\n", imm);
            imm = ExtendedImm (imm, 19);
            //imm -= 1552386;
            return ImplJal (state, imm, rd);
        }
        case Op7: { //jalr

            RegNumber rd          = RecognizeBits (command, 7, 11);
            RegNumber rs1         = RecognizeBits (command, 15, 19);
            ImmValue imm          = RecognizeBits (command, 20, 31);
            imm = ExtendedImm (imm, 11);
            return ImplJalR (state, imm, rs1, rd);
        }
        case Op8: { //beq, bne, blt, bge, bltu, bgeu //TODO ...really TODO...
            
            ImmValue imm          = 0;
            ImmValue funct3       = RecognizeBits (command, 12, 14);
            RegNumber rs1         = RecognizeBits (command, 15, 19);
            RegNumber rs2         = RecognizeBits (command, 20, 24);

            imm                  |= (RecognizeBits (command, 8, 11) << 1) | (RecognizeBits (command, 25, 30)  << 5) | 
                                    (RecognizeBits (command, 7, 7)  << 11) | (RecognizeBits (command, 31, 31)  << 12);

            imm = ExtendedImm (imm, 11);
            return BranchOpsHandle (state, imm, rs2, rs1, funct3); //TODO:  
        }
        default:
            printf ("Unknown opcode %d\n", opcode);
            return 1;

    }

    return 0;

}

