#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern s32 D_800779D8;
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s32 D_801F3964;
extern s32 D_801F3968[];
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8003CF24(s32, s32, s32);
M2C_UNK func_8003D510(M2C_UNK, M2C_UNK, s8, M2C_UNK);
s32 func_801EE34C();
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EEE40(struct X4_WeaponObj* arg0) {
    s8 temp_v1;
    u8* temp_a0;
    u8* temp_v0;
    s32 var_a0;

    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x40);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x74);
    arg0->animation_table = (u32**)&D_800779D8;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->unk16 = 1;
    arg0->unk3C = temp_a0 + var_a0;
    arg0->unk15 = D_800970A0.unk15;
    temp_v1 = arg0->id;
    arg0->unk67 = 1;
    arg0->unk64 = 0;
    if (temp_v1 == 2) {
        if (arg0->unk2 == 0) {
            arg0->unk50 = 0;
            arg0->unk68 = 0;
            M2C_FIELD(arg0, u8*, 0x9D) = 1;
            func_801EE34C(arg0, &D_800970A0, 2);
            func_800179A4(arg0, 0);
            func_80016C48(1, 0x14, arg0);
            M2C_FIELD(arg0, u8*, 0x8D) = 0;
            arg0->state = 1;
            arg0->unk5 = 0;
        } else {
            arg0->state = 3;
        }
        func_8002CCB0(arg0, 0x10, 0x10);
    } else if (temp_v1 == 0x34) {
        func_8002CCB0(arg0, 0x10, 0x10);
        func_800179A4(arg0, arg0->unk2 + 3);
        {
            register s32* t50 asm("$2") = &D_801F3964;
            register s32* t68 asm("$3") = D_801F3968;
            arg0->unk50 = t50;
            arg0->unk68 = (struct X4_Unk_unk68*)t68;
        }
        arg0->state = 2;
    }
    func_8003CF24(7, 1, 1);
    func_8003D510(1, 0x1B, 1, 0);
}
#undef D_800970A0
