#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800E9F7C(void);
s32 func_800EA480(s8* arg0);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA418(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_8008EAB0 = 1;
        background_objects[0].unk3 = 0;
        background_objects[1].unk3 = 0;
        background_objects[2].x_pos.u.hi = 0;
        background_objects[2].y_pos.u.hi = 0x100;
        background_objects[2].unk4C = 1;
        *(s16*)(arg0 + 4) = 0;
        if (D_800CCF08 != 0) {
            func_800E9F7C();
            play_sound(0, 8, 0);
        }
        arg0[1]++;
    }
}
