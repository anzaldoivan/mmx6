#include "common.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_80097214;
extern s16 D_80097216;

void func_800F32B8(u8* arg0) {
    u8* sp = SPAD;
    // !FAKE: depin: dropping it breaks the match (59/66)
    register s32 t asm("$2");

    if (*(s8*)(sp + 0x89) == 0) {
        *(s8*)(sp + 0x89) = 0x78;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    t = *(u16*)(arg0 + 0x7C) + 1;
    *(s16*)(arg0 + 0x7C) = t;
    if ((s16)t == 6) {
        set_animation(arg0, 0x15);
    }
    if (arg0[0x15] == 0) {
        if ((D_80097216 + 0x40) >= *(s16*)(arg0 + 0xA)) {
            *(s16*)(arg0 + 0xA) = D_80097216 + 0x40;
            func_8002943C(0x28, 2, 2);
            play_sound(2, 0x1B, arg0);
            *(s16*)(arg0 + 0x7C) = 0;
            arg0[6]++;
        }
    } else if (*(s16*)(arg0 + 0xA) >= (D_80097214 + 0x100)) {
        *(s16*)(arg0 + 0xA) = D_80097214 + 0x100;
        func_8002943C(0x28, 2, 2);
        play_sound(2, 0x1B, arg0);
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[6]++;
    }
}
