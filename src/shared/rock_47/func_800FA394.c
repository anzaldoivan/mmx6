#include "common.h"
#include "mmx6/x4.h"

void func_800E9F7C(void);
s32 func_800EA480(s8* arg0);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];

void func_800FA394(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_8008EAB0 = 1;
        func_800E9F7C();
        {
            // !FAKE: table base in the second return register
            register struct X4_BackgroundObj* bg asm("$3") = background_objects;
            bg[2].y_pos.u.hi = 0x200;
            bg[2].unk4C = 1;
        }
        *(s16*)(arg0 + 8) = 0x33;
        *(s16*)(arg0 + 0xA) = 2;
        arg0[1]++;
    }
}
