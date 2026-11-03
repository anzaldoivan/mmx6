#include "common.h"

#define M2C_UNK s32

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(s32);

void func_800F2F24(s8* arg0) {
    animate_object();
    ((void (*)(void*))apply_object_motion)(arg0);
    if ((*(u8*)(arg0 + 0x70) & 8) && (*(s32*)(arg0 + 0x24) < 0)) {
        start_pad_vibration(5);
        func_80029478(0x14, 2, 2);
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = 0;
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[6] = 4;
    }
}
