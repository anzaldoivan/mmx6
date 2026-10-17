#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F7938(void* self) {
    void* other;
    s16 mode;
    s32 c;

    other = F(void*, 0x84);
    func_80017A04(self);
    {
        // !FAKE: depin: dropping it breaks the match (61/65)
        register s32 a asm("$2") = F(u16, 0xA);
        s32 b = F(u16, 0xE);
        F(u16, 0x94) = a;
        F(u16, 0x96) = b;
    }
    mode = M2C_FIELD(other, s16*, 0x7C);
    if (mode == 0) {
        c = F(u8, 6);
        F(s32, 0x24) = 0xFFFF0000;
        F(s32, 0x20) = 0;
        F(s32, 0x28) = 0;
        F(s32, 0x2C) = 0x4000;
        F(u8, 6) = c + 1;
    } else if (mode == 1) {
        c = F(u8, 6);
        F(s32, 0x24) = 0x10000;
        F(s32, 0x20) = 0;
        F(s32, 0x28) = 0;
        F(s32, 0x2C) = -0x4000;
        F(u8, 6) = c + 1;
    } else if (mode == 2) {
        F(u8, 6)++;
        F(s32, 0x20) = 0x10000;
        F(s32, 0x28) = -0x4000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
    } else if (mode == 3) {
        F(u8, 6)++;
        F(s32, 0x20) = 0xFFFF0000;
        F(s32, 0x28) = 0x4000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
    } else if (mode == 4) {
        // !FAKE: goto: mode 4 jumps into mode 5 arm; arms stay unmerged (no cross-jump)
        goto nine;
    } else if (mode == 5) {
    nine:
        F(u8, 5) = 9;
        F(u8, 6) = 0;
    }
}
