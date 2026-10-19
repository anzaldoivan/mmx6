#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800133A0(); /* extern */
M2C_UNK func_8001D25C(); /* extern */
extern struct X4_EngineObj D_80097420;

void func_800EFAE0(s8* arg0) {
    u8* p = (u8*)&D_80097420;

    if (*(s8*)(p + 4) == 0) {
        if (p[7] == 0) {
            func_8001D25C();
            func_800133A0();
            return;
        }
        arg0[1] = 5;
        arg0[2] = 2;
    }
}
