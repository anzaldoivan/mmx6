#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800F1DA8(void*, s32, s32);            /* extern */
extern struct X4_BackgroundObj background_objects[3];

void func_800F2CF0(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x8E);
    M2C_FIELD(arg0, u16*, 0x8E) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x5B) {
        func_80016C48(2, 0x14, arg0);
        if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0x40;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xA0;
        }
        M2C_FIELD(arg0, s16*, 0xE) = (s16)(background_objects[0].unk2A + 0xC0);
        func_800F1DA8(arg0, 9, 3);
        M2C_FIELD(arg0, s8*, 7) = 1;
        M2C_FIELD(arg0, s16*, 0x8E) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}
