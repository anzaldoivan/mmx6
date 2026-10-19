#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
extern struct X4_EngineObj D_800CCED0;

void func_800F9F74(void* arg0) {
    // !FAKE: pin the engine base to the register retail uses
    register u8* e asm("$3");

    e = (u8*)&D_800CCED0;
    if (M2C_FIELD(arg0, s8*, 0x5C) < ((s8)e[0x8C] / 2)) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    } else {
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
    }
    e = (u8*)&D_800CCED0;
    if (e[0x68] >= 2U) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    if (!(func_8002D2D4() & 1)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, u8*, 0x9A) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
