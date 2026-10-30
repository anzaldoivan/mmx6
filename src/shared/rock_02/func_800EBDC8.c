#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern s32 D_8009719C;

void func_800EBDC8(void* arg0) {
    s32 temp_v0;
    // !FAKE: depin: dropping it breaks the match (51/54)
    register s32 flag asm("$2");

    func_80017A04();
    flag = M2C_FIELD(arg0, u8*, 0x70) & 8;
    if (flag != 0) {
        play_sound(2, 4, arg0);
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = -0xC00;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        return;
    }
    M2C_FIELD(arg0, s32*, 0x8) += M2C_FIELD(arg0, s32*, 0x20);
    M2C_FIELD(arg0, s32*, 0xC) =
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg0, s32*, 0x24);
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) =
            M2C_FIELD(arg0, s32*, 0x20) + M2C_FIELD(arg0, s32*, 0x28);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) =
            M2C_FIELD(arg0, s32*, 0x20) - M2C_FIELD(arg0, s32*, 0x28);
    }
    temp_v0 = M2C_FIELD(arg0, s32*, 0x24) - M2C_FIELD(arg0, s32*, 0x2C);
    M2C_FIELD(arg0, s32*, 0x24) = temp_v0;
    if (temp_v0 < D_8009719C) {
        M2C_FIELD(arg0, s32*, 0x24) = D_8009719C;
    }
}
