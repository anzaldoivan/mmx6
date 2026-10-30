#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_80097424;
extern s8 D_800CCF08;

void func_800FA1E8(u8* arg0) {
    if (D_80097424 == 0) {
        background_objects[2].unk3 = 1;
        background_objects[2].x_pos.val = 0;
        background_objects[2].y_pos.val = 0;
        if (D_800CCF08 == 0) {
            *(s16*)(arg0 + 8) = 0x1AF;
            *(s16*)(arg0 + 0xA) = 9;
        } else {
            *(s16*)(arg0 + 8) = 0x1C4;
            *(s16*)(arg0 + 0xA) = 9;
        }
        *(s16*)(arg0 + 4) = 0;
        play_sound(0, 5, 0);
        arg0[1]++;
    }
}
