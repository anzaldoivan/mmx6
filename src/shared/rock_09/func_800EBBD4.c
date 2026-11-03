#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800EBBD4(void* arg0) {
    switch (SB(*(void**)((u8*)arg0 + 0x80), 7)) {
    case 3:
        if (B(arg0, 0x17) != 2) {
            set_animation(arg0, 2);
        }
        break;
    case 2:
        if (B(arg0, 0x17) != 3) {
            set_animation(arg0, 3);
        }
        break;
    case 1:
        if (B(arg0, 0x17) != 4) {
            set_animation(arg0, 4);
        }
        break;
    case 0:
        B(arg0, 4) = 2;
        return;
    }
    if (is_off_screen(arg0, 0x30, 0x40) == 0) {
        func_8002CCB0(arg0, 0x30, 0x40);
    }
    apply_object_motion(arg0);
    animate_object(arg0);
}
