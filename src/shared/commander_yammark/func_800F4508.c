#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80040488(M2C_UNK);

void func_800F4508(u8* arg0) {
    if (*(s8*)(arg0 + 0x46) == 0) {
        set_animation(arg0, 0);
        func_80040488(0);
        D_800CCEF4 = 1;
        *(s16*)(arg0 + 0x7C) = 3;
        arg0[6] += 1;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
