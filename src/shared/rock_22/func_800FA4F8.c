#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 random_byte();

void func_800FA4F8(u8* arg0) {
    u8* p;

    func_80017A04();
    p = *(u8**)(arg0 + 0x7C);
    if (*(s8*)(p + 6) == 0 || *(s8*)(p + 4) >= 2) {
        set_animation(arg0, 0x1B);
        *(s32*)(arg0 + 0x50) = 0;
        arg0[6] = 2;
        return;
    }
    if (*(s16*)(arg0 + 0x8C) != 0) {
        (*(s16*)(arg0 + 0x8C))--;
        return;
    }
    *(s16*)(arg0 + 0x8C) = 0x78;
    *(s16*)(arg0 + 0x8E) = ((u8)((u32)random_byte() % 5) + 1) * 10 + 0x3C;
    {
        u32 r = random_byte();
        arg0[6]++;
        *(s16*)(arg0 + 0x8E) = ((u8)(r % 6) + 1) * 10 + 0x1E;
    }
}
