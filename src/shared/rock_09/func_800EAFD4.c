#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

s32 func_8002D2D4();
extern u8 D_800F4BF0[];

void func_800EAFD4(void* arg0) {
    // !FAKE: keeps the speed constant in the argument register for the store and the call
    register s32 speed asm("$4");
    u8* p;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        speed = 0x3C000;
        p = D_800F4BF0 + 0xFB0;
        M2C_FIELD(arg0, void**, 0x50) = p;
        p = 0;
        M2C_FIELD(arg0, void**, 0x54) = D_800F4BF0 + 0xFB4;
        M2C_FIELD(arg0, s32*, 0x24) = speed;
        do {
            M2C_FIELD(SPAD, s16*, 0x82) = func_8002D2D4(speed) & 0x1F;
        } while (0);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
