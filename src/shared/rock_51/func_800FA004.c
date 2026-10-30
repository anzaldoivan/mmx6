#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800E9F7C(void);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_80097424;
extern s8 D_800CCF08;

void func_800FA004(u8* arg0) {
    s16 temp_v1;

    if (D_80097424 == 0) {
        temp_v1 = *(s16*)(arg0 + 4);
        if (temp_v1 >= 0x78) {
            D_8008EAB0 = 1;
            background_objects[2].x_pos.i.hi = 0;
            background_objects[2].y_pos.i.hi = 0x100;
            background_objects[2].unk4C = 1;
            if (D_800CCF08 == 0) {
                *(s16*)(arg0 + 8) = 0xB5;
                *(s16*)(arg0 + 0xA) = 0x20;
                arg0[1] += 2;
            } else {
                background_objects[1].unk3 = 1;
                background_objects[1].x_pos.i.hi = 0x120;
                background_objects[1].y_pos.i.hi = 0x100;
                background_objects[1].unk4C = 1;
                *(s16*)(arg0 + 8) = 0xFC;
                *(s16*)(arg0 + 0xA) = 7;
                arg0[1] += 1;
            }
            play_sound(0, 4, 0);
            return;
        }
        if (temp_v1 == 0) {
            func_800E9F7C();
        }
        *(s16*)(arg0 + 4) += 1;
    }
}
