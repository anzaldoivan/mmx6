#include "common.h"
#define M2C_UNK s32

s32 func_8002D2D4();
void func_800F9F7C(void* arg0, M2C_UNK arg1, M2C_UNK arg2);
extern s16 D_800FDA80;

void func_800F9A80(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == -1) {
        *(s16*)(arg0 + 0x7C) = 2;
        if (--*(s16*)(arg0 + 0x7E) == 0) {
            arg0[6]++;
            return;
        }
        {
            s16* p = &D_800FDA80;
            s32 v = func_8002D2D4() + 0xFF;
            *p += v;
            func_800F9F7C(arg0, 0, *p);
        }
    }
}
