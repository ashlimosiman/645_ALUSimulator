#include "ALUSimulator.h"

void ALUSimulator(RegisterFile theRegisterFile, uint32_t OpCode, uint32_t Rs, uint32_t Rt, uint32_t Rd, uint32_t ShiftAmt, uint32_t FunctionCode, uint32_t ImmediateValue, uint32_t* Status )
{
     switch(OpCode)
     {
          case 0:
               switch(FunctionCode)
               {
                    case 0://SLL and NOOP
                         Rd = Rt << ShiftAmt;
                         break;
                    case 2://SRL
                         Rd = Rt >> ShiftAmt;
                         break;
                    case 3://SRA
                         Rd = (signed)Rt >> ShiftAmt;
                         break;
                    case 4://SLLV
                         Rd = Rt << Rs;
                         break;
                    case 6://SRLV
                         Rd = Rt >> Rs;
                         break;
                    case 32://ADD
                         Rd = Rs + Rt;
                         if(Rs>0&&(Rd<Rs||Rd<Rt))//overflow case
                         {
                              unsigned int myStatus=12;
                              Status=&myStatus;

                         }
                         break;
                    case 33://ADDU
                         Rd = Rs + Rt;
                         break;
                    case 34://SUB
                         Rd = Rs - Rt;
                         if((signed)Rs<0&&(Rd>Rs||Rd>Rt))//negaitve overflow case
                         {
                              unsigned int myStatus=12;
                              Status=&myStatus;
                         }
                         break;
                    case 35://SUBU
                         Rd = Rs - Rt;
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
                         break;
                    case 43://SLTU
                         if((unsigned)Rs < (unsigned)Rt)
                         {
                              Rd = 1;
                         }
                         else
                         {
                              Rd = 0;
                         }
                         break;
               }//end of "functionCode" switch
               break;

          case 8://ADDI
               Rd=Rs+ImmediateValue;
               if(Rs>0&&(Rd<Rs||Rd<ImmediateValue))//overflow case
               {
                    unsigned int myStatus=12;
                    Status=&myStatus;

               }
               else if((signed)Rs<0&&(Rd>Rs||Rd>ImmediateValue))//negaitve overflow case
               {
                    unsigned int myStatus=12;
                    Status=&myStatus;
               }
               break;
          case 9://ADDIU
               Rd=Rs+ImmediateValue;
               break;
          case 10://SLTI
               if(Rs < ImmediateValue)
               {
                    Rd = 1;
               }
               else
               {
                    Rd = 0;
               }
               break;
          case 11://SLTIU
               if((unsigned)Rs < (unsigned)ImmediateValue)
               {
                    Rd = 1;
               }
               else
               {
                    Rd = 0;
               }
               break;
     }//end of "opCode" switch

     //provided by Minden
     printf( ">>ALU: Opcode: %02X; Rs: %02X; Rt: %02X; Rd: %02X;\n",
				OpCode,
				Rs,
				Rt,
				Rd );

	printf( ">>>>ALU: ShiftAmt: %02X; FunctionCode: %02X; ImmediateValue: %04X;\n",
				ShiftAmt,
				FunctionCode,
				ImmediateValue );
}//end of method
