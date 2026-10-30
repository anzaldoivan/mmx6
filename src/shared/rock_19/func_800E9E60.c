#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK reset_level();
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_80097424;

void func_800E9E60(u8* arg0) {
    if (D_80097424 == 0) {
        func_8001D218();
        {
            // !FAKE: retail keeps the background table base in the second return register
            register struct X4_BackgroundObj* bg asm("$3") = background_objects;
            bg[0].unk3 = 0;
            bg[1].unk3 = 0;
            bg[2].unk3 = 0;
        }
        reset_level();
        {
            s32 f = arg0[0x66];
            if (f == 0) {
                arg0[0xC] = 0;
                arg0[0xD] = 0;
                arg0[0x1D] = 0;
                arg0[0] = 7;
            }
        }
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}
