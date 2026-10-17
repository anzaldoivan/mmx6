#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_800FCA84;

void func_800FC1FC(void* arg0) {
    s16 d;
    u16 x;

    if (M2C_FIELD(arg0, u8*, 0x88) < 0xF) {
        M2C_FIELD(arg0, u8*, 0x88) = 0x1E;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        func_800179A4(arg0, 5);
        func_80016C48(2, 0x35, arg0);
        x = M2C_FIELD(arg0, u16*, 0xA);
        if (M2C_FIELD(arg0, s16*, 0xA) < *(s16*)((u8*)&D_800FCA84 + 0x3CC)) {
            do {
            } while (0);
            {
                s32 t = *(u16*)((u8*)&D_800FCA84 + 0x3CA);
                d = t - x;
            }
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            do {
            } while (0);
            {
                s32 t = *(u16*)((u8*)&D_800FCA84 + 0x3C8);
                d = t - x;
            }
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x2666;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
        M2C_FIELD(arg0, s32*, 0x20) = (d << 16) / 42;
    }
}
