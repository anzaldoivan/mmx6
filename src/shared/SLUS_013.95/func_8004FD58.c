#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_8004FD58(u8* arg0) {
    if (--arg0[0x81] == 0) {
        if (arg0[0x84] == 0) {
            if (arg0[0x7E] == 0) {
                if (arg0[0x82] == 0) {
                    set_animation(arg0, 2);
                } else {
                    set_animation(arg0, 0xD);
                }
            } else if (arg0[0x82] == 0) {
                set_animation(arg0, 7);
            } else {
                set_animation(arg0, 0x10);
            }
        } else if (arg0[0x82] == 0) {
            set_animation(arg0, 0x1A);
        } else {
            set_animation(arg0, 0x21);
        }
        arg0[5]++;
    }
}
