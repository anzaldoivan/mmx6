// rolefeed (3.1 T4): func_800F71A4 of src/rock_02/E9860.c

#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F71A4(u8* arg0) {
    s32 t;

    func_800F82C0();
    animate_object(arg0);
    if ((s8)arg0[2] == 1) {
        if ((*(s16*)(arg0 + 0x7C))++ < 0x42) {
            return;
        }
        play_sound(2, 0x1D, arg0);
        t = arg0[6];
        *(s16*)(arg0 + 0x7C) = 0;
    } else {
        play_sound(2, 0x1D, arg0);
        t = arg0[6];
        *(s16*)(arg0 + 0x7C) = 0x3A;
    }
    t--;
    arg0[6] = t;
}
