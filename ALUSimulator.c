#include "ALUSimulator.h"

void ALUSimulator(RegisterFile theRegisterFile, uint32_t OpCode, uint32_t Rs, uint32_t Rt, uint32_t Rd, uint32_t ShiftAmt, uint32_t FunctionCode, uint32_t ImmediateValue, uint32_t* Status )
{
     if(!opCode)
     {
          switch(FunctionCode)
          {
               case 0://SLL and NOOP
                    Rd = Rt << ShiftAmt;
                    break;
               case 2://SRL
                    Rd = Rt >> ShiftAmt;
                    break;
               case 3://SRA
                    Rd = signed(Rt) >> ShiftAmt;
                    break;
               case 4://SLLV
                    Rd = Rt << Rs;
                    break;
               case 6://SRLV
                    Rd = Rt >> Rs;
               case 16://MFHI

               case 18://MFLO

               case 24://MULT

               case 25://MULTU

               case 26://DIV

               case 27://DIVU

               case 32://ADD
                    Rd = Rs + Rt;
                    break;
               case 33://ADDU
                    Rd = Rs + Rt;//should be different from ADD?
                    break;
               case 34://SUB
                    Rd = Rs - Rt;
                    break;
               case 35://SUBU
                    Rd = Rs - Rt;//should be different from SUB?
                    break;
               case 36://AND
                    Rd = Rs & Rt;
                    break;
               case 37://OR
                    Rd = Rs | Rt;
                    break;
               case 38://XOR
                    Rd = Rs ^ Rt;
                    break;
               case 42://SLT
                    if(Rs < Rt)
                    {
                         Rd = 1;
                    }
                    else
                    {
                         Rd = 0;
                    }
               case 43://SLTU
                    if(Rd < Rt)//should be different from SLT?
                    {
                         Rd = 1;
                    }
                    else
                    {
                         Rd = 0;
                    }
          }//end of switch
     }//end of "opCode" if
     else
     {
          //ADDI
          //ADDIU
          //SLTI
          //SLTIU
     }
}//end of method
