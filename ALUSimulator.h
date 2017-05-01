#ifndef _ALU_SIMULATOR_H
#define _ALU_SIMULATOR_H

#include <stdio.h>
#include <time.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include "RegisterFile_01.h"

void ALUSimulator( RegisterFile theRegisterFile,
                    uint32_t OpCode,
                    uint32_t Rs, uint32_t Rt, uint32_t Rd,
                    uint32_t ShiftAmt,
                    uint32_t FunctionCode,
                    uint32_t ImmediateValue,
                    uint32_t* Status );




#endif
