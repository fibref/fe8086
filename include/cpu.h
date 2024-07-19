#ifndef CPU_H
#define CPU_H

#define EXTERN extern
#ifdef CPU_C
    #undef EXTERN
    #define EXTERN
#endif

#include <stdint.h>

//! @brief This array contains ax, cx, dx, bx, sp, bp, si, and di (in the order listed).
EXTERN uint16_t greg[8];
EXTERN uint16_t cs, ds, ss, es;
EXTERN uint16_t ip;
EXTERN uint16_t flags;

#define ax greg[0]
#define cx greg[1]
#define dx greg[2]
#define bx greg[3]
#define sp greg[4]
#define bp greg[5]
#define si greg[6]
#define di greg[7]

#define al 0[(uint8_t*)greg]
#define ah 1[(uint8_t*)greg]
#define cl 2[(uint8_t*)greg]
#define ch 3[(uint8_t*)greg]
#define dl 4[(uint8_t*)greg]
#define dh 5[(uint8_t*)greg]
#define bl 6[(uint8_t*)greg]
#define bh 7[(uint8_t*)greg]


//! @brief This function converts a general/pointer/index register (16 bits) to a pointer of it in the host's memory.
//! @param reg The index of the general/pointer/index register to convert (0-7).
//! @return A pointer of the register in the host's memory.
uint16_t* reg2ptr_w(uint8_t reg);

//! @brief This function converts a general register (8 bits) to a pointer of it in the host's memory.
//! @param reg The index of the general register to convert (0-7).
//! @return A pointer of the register in the host's memory.
uint8_t* reg2ptr_b(uint8_t reg);

uint16_t* instr2ptr_w(uint8_t mod, uint8_t rm, uint16_t disp);

uint8_t* instr2ptr_b(uint8_t mod, uint8_t rm, uint16_t disp);

#endif /* CPU_H */