#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;

void func_800FA7A0(void* arg0) {
    if ((s16)M2C_FIELD(arg0, u16*, 4)++ >= 0x3C) {
        func_8002B54C(&D_800FBC08, &D_800FAA08, 0x900, 0);
        func_8002B3D4(0x60, &D_800FBC08, 0x90);
        background_objects[2].x_pos.u.hi = 0;
        background_objects[2].y_pos.u.hi = 0x100;
        background_objects[2].unk4C = 1;
        if (D_800CCF08 == 0) {
            M2C_FIELD(arg0, u16*, 8) = 0xE0;
            M2C_FIELD(arg0, u16*, 0xA) = 0x1C;
            M2C_FIELD(arg0, u8*, 1) += 2;
        } else {
            background_objects[1].unk3 = 1;
            background_objects[1].x_pos.u.hi = 0x120;
            background_objects[1].y_pos.u.hi = 0x100;
            background_objects[1].unk4C = 1;
            M2C_FIELD(arg0, u16*, 8) = 0x127;
            M2C_FIELD(arg0, u16*, 0xA) = 1;
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}
