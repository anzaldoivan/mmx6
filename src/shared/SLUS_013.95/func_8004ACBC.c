#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CB50();
s32 random_byte();
extern M2C_UNK D_80077E34;
extern u8 D_800970B4;
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_8004ACBC(void* arg0) {
    u8* sp;

    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s32*, 0x38) = 0;
    sp = SCRATCH_1C;
    {
        s32 off = *(s32*)(sp + 8);
        M2C_FIELD(arg0, void**, 0x30) = &D_80077E34;
        M2C_FIELD(arg0, u8**, 0x3C) = sp + off;
    }
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    M2C_FIELD(arg0, s16*, 0x40) = 0;
    if (M2C_FIELD(arg0, s8*, 0x5C) != 2) {
        M2C_FIELD(arg0, s16*, 0x42) = 0x7805;
    } else {
        M2C_FIELD(arg0, s16*, 0x42) = 0x7806;
    }
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, s8*, 0x16) = 1;
    }
    set_animation(arg0, M2C_FIELD(arg0, s8*, 0x5C));
    {
        // !FAKE: pin the incremented byte to the first return register
        register s32 n asm("$2") = M2C_FIELD(arg0, u8*, 4) + 1;
        M2C_FIELD(arg0, u8*, 4) = n;
    }
    M2C_FIELD(arg0, s8*, 7) = random_byte() & 1;
    func_8002CB50(arg0);
}
