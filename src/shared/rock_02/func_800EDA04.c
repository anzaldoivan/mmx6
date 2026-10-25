#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();

M2C_UNK move_object(s32);
void func_800EDA04(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (26/30)
    register s32 t asm("$2");
    ((M2C_UNK(*)())func_80017A04)();
    t = *(s16*)(arg0 + 0x7C);
    if (t != 0) {
        *(s16*)(arg0 + 0x7C) = *(s16*)(arg0 + 0x7C) - 1;
        return;
    }
    ((M2C_UNK(*)())move_object)(arg0);
    if (--*(s16*)(arg0 + 0x7E) == 0) {
        *(s16*)(arg0 + 0x7C) = 0x28;
        *(s16*)(arg0 + 0x7E) = 0x20;
        *(s32*)(arg0 + 0x24) = -*(s32*)(arg0 + 0x24);
    }
}
