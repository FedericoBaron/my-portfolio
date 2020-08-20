// Federico Baron, Brady Hill, Nathaniel Lyra
// CDA Project Spring 2019

#include "spimcore.h"

/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
    ALUControl = (int)ALUControl;

    // switch cases for all different values of ALUControl
    switch(ALUControl)
    {
        // Z = A + B
        case 0: 
            *ALUresult = A+B;
            break;
        // Z = A - B
        case 1:
            *ALUresult = A-B;
            break;

        // A < B, Z = 1 otherwise Z = 0
        case 2: 
            if((signed)A < (signed)B)
                *ALUresult = 1;
            else
                *ALUresult = 0;

        // A < B, Z = 1 otherwise Z = 0 (unsigned)
        case 3: 
            if(A < B)
                *ALUresult = 1;
            else
                *ALUresult = 0;
            break;

        // Z = A AND B
        case 4:
            *ALUresult = A & B;
            break;

        // Z = A OR B
        case 5: 
            *ALUresult = A | B;
            break;

        // shift left by 16 bits
        case 6: 
            *ALUresult = B << 16;
            break;

        // Z = NOT A
        case 7:
            *ALUresult = ~A;
            break;   
    }

    // if result 0 Assign 0 to be 1
    if (*ALUresult == 0)
        *Zero = 1;
    // otherwise zero is 0 
    else
        *Zero = 0;
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{ 
    if (PC % 4 != 0)
        return 1;

    *instruction = Mem[PC >> 2];

    return 0;
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    // bit masking
    *op = (instruction >> 26) & 0x0000003F; // [31-26]
    *r1 = (instruction >> 21) & 0x0000001F; // [25-21]
    *r2 = (instruction >> 16) & 0x0000001F; // [20-16]
    *r3 = (instruction >> 11) & 0x0000001F; // [15-11]
    *funct = (instruction) & 0x0000003F;    // [5-0]
    *offset = (instruction) & 0x0000FFFF;   // [15-0]
    *jsec = (instruction) & 0x03FFFFFF;     // [25-0]
}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{
    switch (op)
    {
        // R-type: (add, sub, slt, sltu, and, or)
        case (0x0):
            controls->RegDst = 1;
            controls->Jump = 0;
            controls->Branch = 0;
            controls->MemRead = 0;
            controls->MemtoReg = 0;
            controls->ALUOp = 7;
            controls->MemWrite = 0;
            controls->ALUSrc = 0;
            controls->RegWrite = 1;
            break;

        // addi
        case (0x8):
            controls->RegDst = 0;
            controls->Jump = 0;
            controls->Branch = 0;
            controls->MemRead = 0;
            controls->MemtoReg = 0;
            controls->ALUOp = 0;
            controls->MemWrite = 0;
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // slti:
        case (0xa):
            controls->RegDst = 0;
            controls->Jump = 0;
            controls->Branch = 0;
            controls->MemRead = 0;
            controls->MemtoReg = 0;
            controls->ALUOp = 2;
            controls->MemWrite = 0;
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // sltiu:
        case (0xb):
            controls->RegDst = 0;
            controls->Jump = 0;
            controls->Branch = 0;
            controls->MemRead = 0;
            controls->MemtoReg = 0;
            controls->ALUOp = 3;
            controls->MemWrite = 0;
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // store word (sw):
        case (0x2b):
            controls->RegDst = 2;
            controls->Jump = 0;
            controls->Branch = 0;
            controls->MemRead = 0;
            controls->MemtoReg = 2;
            controls->ALUOp = 0;
            controls->MemWrite = 1;
            controls->ALUSrc = 1;
            controls->RegWrite = 0;
            break;

        // load word (lw):
        case (0x23):
            controls->RegDst = 0;
            controls->Jump = 0;
            controls->Branch = 0;
            controls->MemRead = 1;
            controls->MemtoReg = 1;
            controls->ALUOp = 0;
            controls->MemWrite = 0;
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // load upper immediate (lui):
        case (0xF):
            controls->RegDst = 0;
            controls->Jump = 0;
            controls->Branch = 0;
            controls->MemRead = 0;
            controls->MemtoReg = 0;
            controls->ALUOp = 6;
            controls->MemWrite = 0;
            controls->ALUSrc = 1;
            controls->RegWrite = 1;
            break;

        // beq:
        case (0x4):
            controls->RegDst = 2;
            controls->Jump = 0;
            controls->Branch = 1;
            controls->MemRead = 0;
            controls->MemtoReg = 2;
            controls->ALUOp = 1;
            controls->MemWrite = 0;
            controls->ALUSrc = 0;
            controls->RegWrite = 0;
            break;

        // jump:
        case (0x2):
            controls->RegDst = 0;
            controls->Jump = 1;
            controls->Branch = 0;
            controls->MemRead = 0;
            controls->MemtoReg = 0;
            controls->ALUOp = 0;
            controls->MemWrite = 0;
            controls->ALUSrc = 0;
            controls->RegWrite = 0;
            break;

        default:
            return 1;
    }

    return 0;
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    // fill data1 and data2 with the values from register array (registers 1 and 2)
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    /*
    basically this function adds a certain number of bits (offset) to the most significant digit of the 
    to-be extended value. 1s are added if the offset MSD is 1 otherwise nothing happens.
    */
    unsigned blep = offset >> 15;

    // check MSD of offset 
    if (blep == 1)
        /* 
        this adds the appropraite number of bits 
        (up to 16 more: 0xFFFF0000 == 0b11111111111111110000000000000000) 
        */
        *extended_value = offset | 0xFFFF0000;
    else
        *extended_value = offset & 0x0000FFFF; 
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

    // Check for halt condition if illegal instruction was passed in.
    if (ALUOp > 7 || ALUOp < 0)
        return 1;

    // Update data2
    if (ALUSrc == 1) 
        data2 = extended_value;

    // Check for Rtype
    if (ALUOp == 7)
    {
        switch (funct)
        {
            // add
            case(0x20):
                ALUOp = 0;
                break;

            // subtract
            case(0x22):
                ALUOp = 1;
                break;

            // slt
            case(0x2A):
                ALUOp = 2;
                break;

            // sltu
            case(0x2B):
                ALUOp = 3;
                break;
            // and
            case(0x24):
                ALUOp = 4;
                break;

            // or
            case(0x25):
                ALUOp = 5;
                break;

            // shift left by 16
            case(0x4):
                ALUOp = 6;
                break;

            // nor
            case(0x27):
                ALUOp = 7;
                break;

            default: 
                return 1;
        }
        ALU(data1, data2, ALUOp, ALUresult, Zero);
    }
    // Itype
    else
    {
        ALU(data1, data2, ALUOp, ALUresult, Zero);
    }

    return 0; 
}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned *memdata, unsigned *Mem)
{    
    // halt condition
    if((MemWrite == 1 || MemRead == 1) && ALUresult % 4 != 0)
        return 1;
     
    if(MemRead == 1)
        *memdata = Mem[ALUresult >> 2];   

    if(MemWrite == 1)
        Mem[ALUresult >> 2] = data2;
    
    return 0;
}

/* Write Register */
/* 10 Points */
void write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned *Reg)
{
    if (RegWrite == 1)
    {
        if (MemtoReg == 1)
        {
            // if its 1 it goes to r3
            if (RegDst == 1)
            {
                Reg[r3] = memdata;
            }
            // otherwise it goes to r2
            else
            {
                Reg[r2] = memdata;
            }
        }

        if (MemtoReg == 0)
        {
            // if its 1 it goes to r3
            if (RegDst == 1)
            {
                Reg[r3] = ALUresult;
            }
            // otherwise it goes to r2
            else
            {
                Reg[r2] = ALUresult;
            }
        }
    }
}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned *PC)
{
    // increment PC by 4.
    *PC += 4;
    
    // left shift bits of jsec by 2 and use upper 4 bits of PC if jump is 1.
    if (Jump == 1)
        *PC = (*PC & 0xF0000000) | (jsec << 2);

    // left shift extended_value by 2 and add it to PC if we either branch or zero is 1.
    else if (Branch == 1 && Zero == 1)
        *PC += extended_value << 2;
}
