#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC (*(void (*)(void*)) & func_80030ECC)
extern s32 D_800F76C8;
extern s32 D_800F77D8;
extern s32 D_800F77DC;
extern s16 D_800F77F8;
extern s16 D_800F77FA;
extern s16 D_800F77FC;

void func_800F4240(void* arg0) {
    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        D_800F77F8 = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (M2C_FIELD(arg0, s32*, 0x8C) == 5) {
            func_80012D9C(3);
        }
        if (M2C_FIELD(arg0, s32*, 0x8C) == 0xA) {
            D_800F77F8 = 1;
            D_800F77FA = ((struct X4_ObjectHeader*)arg0)->x_pos.u.hi;
            D_800F77FC = ((struct X4_ObjectHeader*)arg0)->y_pos.u.hi;
            M2C_FIELD(arg0, s32**, 0x50) = &D_800F76C8;
            M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s32*, 0x8C) == 0x34) {
            D_800F77F8 = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        }
        break;
    }
    M2C_FIELD(arg0, s32*, 0x8C) = M2C_FIELD(arg0, s32*, 0x8C) + 1;
    func_8002CCB0(arg0, 0x20, 0xC0);
    func_80017A04(arg0);
    func_8002D230(arg0);
}
#undef func_80030ECC
