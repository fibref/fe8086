#define CPU_C

#include <stdint.h>

#include <cpu.h>


//! @brief This function converts a general/pointer/index register (16 bits) to a pointer of it in the host's memory.
//! @param reg The index of the general/pointer/index register to convert (0-7).
//! @return A pointer of the register in the host's memory.
inline uint16_t* reg2ptr_w(uint8_t reg) {
    return &greg[reg];
}

//! @brief This function converts a general register (8 bits) to a pointer of it in the host's memory.
//! @param reg The index of the general register to convert (0-7).
//! @return A pointer of the register in the host's memory.
inline uint8_t* reg2ptr_b(uint8_t reg) {
    return reg <= 3 ? (uint8_t*)&greg[reg] : (uint8_t*)&greg[reg] - 0x7;
}

uint16_t* instr2ptr_w(uint8_t mod, uint8_t rm, uint16_t disp) {
    if (mod == 0x3)
        return reg2ptr_w(rm);
    uintptr_t addr;
    switch (rm) {
    case 0:
        addr = bx + si;
        break;
    case 1:
        addr = bx + di;
        break;
    case 2:
        addr = bp + si;
        break;
    case 3:
        addr = bp + di;
        break;
    case 4:
        addr = si;
        break;
    case 5:
        addr = di;
        break;
    case 6:
        addr = mod == 0 ? disp : bp;
        break;
    case 7:
        addr = bx;
        break;
    }
    addr += mod == 0 ? 0 : disp;
    return (uint16_t*)addr;
}

uint8_t* instr2ptr_b(uint8_t mod, uint8_t rm, uint16_t disp) {
    if (mod == 0x3)
        return reg2ptr_b(rm);
    uintptr_t addr;
    switch (rm) {
    case 0:
        addr = bx + si;
        break;
    case 1:
        addr = bx + di;
        break;
    case 2:
        addr = bp + si;
        break;
    case 3:
        addr = bp + di;
        break;
    case 4:
        addr = si;
        break;
    case 5:
        addr = di;
        break;
    case 6:
        addr = mod == 0 ? disp : bp;
        break;
    case 7:
        addr = bx;
        break;
    }
    addr += mod == 0 ? 0 : disp;
    return (uint8_t*)addr;
}