#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(void*);
s32 func_800FA630(void*, s16, s16);

#define F_S8(o) (*(s8*)((u8*)self + (o)))
#define F_U8(o) (*(u8*)((u8*)self + (o)))
#define F_S16(o) (*(s16*)((u8*)self + (o)))
#define F_S32(o) (*(s32*)((u8*)self + (o)))

void func_800F754C(void* self) {
    if (F_S8(0x7) == 0) {
        if (func_800FA630(self, F_S16(0xA), F_S16(0xE) - 0x10) != 0 ||
            (F_U8(0x70) & 4)) {
            func_800179A4(self, 0xC);
            F_S32(0x50) = 0;
            F_S16(0xE) -= 0x12;
            F_U8(0x6)++;
            return;
        }
        if (F_S32(0x84) == 1) {
            func_800179A4(self, 0xC);
            F_S32(0x50) = 0;
            F_S16(0xE) -= 0x12;
            F_U8(0x6)++;
            return;
        }
    } else if (func_800FA630(self, F_S16(0xA), F_S16(0xE) + 0x10) != 0 ||
               (F_U8(0x70) & 8) || F_S32(0x84) == 1) {
        func_800179A4(self, 0xC);
        F_S32(0x50) = 0;
        F_S16(0xE) += 0x12;
        F_U8(0x6)++;
        return;
    }
    move_object(self);
}
