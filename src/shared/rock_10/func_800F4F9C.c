#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800F4F9C(void* arg0) {
    s8 state = M2C_FIELD(arg0, s8*, 0x45);
    struct X4_BackgroundObj* bg;
    s16* px;

    if (state == 1) {
        func_80016C48(2, 0x59, arg0);
        func_800179A4(arg0, 0xC);
        px = &D_800970AA;
        bg = background_objects;
        if (*px >= M2C_FIELD(bg, s16*, 0xA) + 0xA0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(bg, u16*, 0xA) + 0x30;
            M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(bg, u16*, 0xE) + 0x90;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(bg, u16*, 0xA) + 0x110;
            M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(bg, u16*, 0xE) + 0x90;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    } else if (state == 2) {
        func_80016C48(2, 0x59, arg0);
    } else if (state == 3) {
        func_80016C48(2, 0x51, arg0);
    }
}
