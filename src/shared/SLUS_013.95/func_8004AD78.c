#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002C9B0();
s32 func_8002CB50(struct X4_BaseObj*);
#define func_8002C9B0 ((M2C_UNK(*)(u8*))func_8002C9B0)
#define func_8002CB50 func_8002CB50
M2C_UNK move_object(void*);
extern s32 D_80097420;

void func_8004AD78() {
    // !FAKE: depin: dropping it breaks the match (39/41)
    register u8* a0 asm("$4");
    u8* arg0 = a0;
    u8 temp_v1;

    move_object(arg0);
    ((void (*)(u8*))func_80017A04)(arg0);
    if (*(s8*)(arg0 + 0x46) == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        arg0[0x5C] = 0;
        func_8002C9B0(arg0);
        return;
    }
    temp_v1 = arg0[0x5C];
    arg0[3] = 0;
    if (!(temp_v1 & 3) || (temp_v1 & 1)) {
        if ((D_80097420 & 1) == *(s8*)(arg0 + 7)) {
            func_8002CB50(arg0);
        }
    } else {
        func_8002CB50(arg0);
    }
}

#undef func_8002C9B0
#undef func_8002CB50
