#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCF08;
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;

void func_800FA7A0(void* arg0) {
    if ((s16)M2C_FIELD(arg0, u16*, 4)++ >= 0x3C) {
        func_8002B54C(&D_800FBC08, &D_800FAA08, 0x900, 0);
        func_8002B3D4(0x60, &D_800FBC08, 0x90);
        D_800971F8[2].x_pos.u.hi = 0;
        D_800971F8[2].y_pos.u.hi = 0x100;
        D_800971F8[2].unk4C = 1;
        if (D_800CCF08 == 0) {
            M2C_FIELD(arg0, u16*, 8) = 0xE0;
            M2C_FIELD(arg0, u16*, 0xA) = 0x1C;
            M2C_FIELD(arg0, u8*, 1) += 2;
        } else {
            D_800971F8[1].unk3 = 1;
            D_800971F8[1].x_pos.u.hi = 0x120;
            D_800971F8[1].y_pos.u.hi = 0x100;
            D_800971F8[1].unk4C = 1;
            M2C_FIELD(arg0, u16*, 8) = 0x127;
            M2C_FIELD(arg0, u16*, 0xA) = 1;
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}
