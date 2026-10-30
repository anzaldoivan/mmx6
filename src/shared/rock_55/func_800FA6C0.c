#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_800EA480(s8* arg0);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

#define BG(t, off) (*(t*)(bg + (off)))

void func_800FA6C0(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        if (D_800CCF08 == 0) {
            s8* bg = (s8*)background_objects;

            BG(s16, 0xB6) = 0x300;
            *(s16*)(arg0 + 0xA) = 0;
        } else {
            s8* bg = (s8*)background_objects;

            BG(s16, 0xB6) = 0x500;
        }
        D_8008EAB0 = 1;
        {
            s8* bg = (s8*)background_objects;

            BG(s8, 0xF4) = 1;
            BG(s8, 0x57) = 0;
            BG(s16, 0xB2) = 0;
        }
        *(s16*)(arg0 + 4) = 0;
        play_sound(0, 1, 0);
        arg0[1] = (u8)arg0[1] + 1;
    }
}
