#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1DA8(void*, s32, s32); /* extern */
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800F2B50(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x47) == 0xC) {
        if ((background_objects[0].unk26 + 0x80) > D_800970AA) {
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
        } else {
            M2C_FIELD(arg0, s16*, 0x7C) = 1;
        }
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0x40;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xA0;
        }
        M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk2A + 0xC0;
        func_800F1DA8(arg0, 9, 3);
        M2C_FIELD(arg0, s8*, 7) = 1;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}
