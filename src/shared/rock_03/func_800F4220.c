#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800CCEDF;

void func_800F4220(u8* arg0) {
    u8* obj;
    u8 b;

    if (D_800CCEDF == 0) {
        if (--*(s16*)(arg0 + 0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (**(s8**)(arg0 + 0x80) == 0) {
            obj = func_8002C458();
            if (obj != 0) {
                b = arg0[0];
                obj[1] = 0xF;
                obj[2] = 4;
                *(u8**)(obj + 0x7C) = arg0;
                obj[0] = b;
            }
            *(s32*)(arg0 + 0x24) = 0xFFFF0000;
            func_800179A4(arg0, 0);
            {
                register s32 t asm("$2") = arg0[6] + 1;
                arg0[6] = t;
            }
        }
    }
}
