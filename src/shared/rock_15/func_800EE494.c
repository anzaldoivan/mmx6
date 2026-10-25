#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object(s32);

#define F(o) (*((u8*)arg0 + (o)))
void func_800EE494(void* arg0) {
    if (*(s8*)((u8*)arg0 + 0x45) == 1) {
        F(6) = F(6) + 1;
        return;
    }
    if ((F(0x15) == 0) && (F(0x70) & 2)) {
        F(0x15) = 0x40;
        *(s32*)((u8*)arg0 + 0x20) = 0x4000;
    } else if ((F(0x15) == 0x40) && (F(0x70) & 1)) {
        F(0x15) = 0;
        *(s32*)((u8*)arg0 + 0x20) = -0x4000;
    }
    move_object(arg0);
}
#undef F
