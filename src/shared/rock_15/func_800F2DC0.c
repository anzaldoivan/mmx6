#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);                   /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);   /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void func_800F1DA8(void*, s32, s32);              /* extern */
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F2DC0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        func_80016C48(2, 0x76, arg0);
        ((void (*)(s32))func_80012D9C)(6);
        if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
            M2C_FIELD(arg0, s16*, 0xA) = D_800971F8[0].unk26 + 0x40;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = D_800971F8[0].unk26 + 0xA0;
        }
        M2C_FIELD(arg0, s16*, 0xE) = D_800971F8[0].unk2A + 0x70;
        func_800F1DA8(arg0, 0xA, 3);
        ((void (*)(s32, s32, s32))func_80029478)(0x78, 2, 2);
        M2C_FIELD(arg0, s8*, 7) = 1;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}
