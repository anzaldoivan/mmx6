#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern void (*D_801F398C[])(void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_80049E50(void*);

void func_801EEFC0(struct X4_WeaponObj* arg0) {
    s8 temp_v1;
    register s32 t asm("$4");

    if (func_8002CBFC((struct X4_BaseObj*)arg0, 0x10, 0x10) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        D_801F398C[arg0->unk5](arg0);
        temp_v1 = arg0->unk5;
        if (temp_v1 == 2) {
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x98) != 0) {
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            M2C_FIELD(arg0, u8*, 0x4) = 3;
            return;
        }
        if (temp_v1 == 0) {
            return;
        }
        t = M2C_FIELD(arg0, u8*, 0x8C);
        if (((t & 0xC) == 0xC) || ((t & 3) == 3)) {
            func_80049E50(arg0);
            goto block_11;
        }
        if ((t & 0xFF) == 8) {
            func_800179A4(arg0, 2);
            {
                register s32 c1 asm("$2") = 1;
                M2C_FIELD(arg0, u8*, 0x75) = c1;
            }
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, u8*, 0x9D) = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s16*, 0x88) = 0xB4;
            arg0->unk5 = 2;
            return;
        }
        {
            register s32 m asm("$2") = t & 7;
            if (m != 0) {
                func_80049E50(arg0);
                M2C_FIELD(arg0, u8*, 0x75) = 0;
                M2C_FIELD(arg0, u8*, 0x3) = 0;
                M2C_FIELD(arg0, u8*, 0x4) = 3;
            }
        }
        return;
    }
block_11:
    M2C_FIELD(arg0, u8*, 0x75) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 3;
}
