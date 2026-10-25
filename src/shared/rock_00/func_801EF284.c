#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern s32 D_800779F4;
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8003CF24(s32, s32, s32);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EF284(struct X4_WeaponObj* arg0) {
    s8 temp_a2;
    u8* temp_a0;
    u8* temp_v0;
    s32 var_a0;

    temp_a2 = arg0->unk2;
    if (temp_a2 == 0) {
        func_80016C48(1, 0x15, arg0);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x168;
        arg0->state++;
        return;
    }
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x34);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x54);
    arg0->animation_table = (u32**)&D_800779F4;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->unk16 = 1;
    arg0->unk64 = 1;
    arg0->unk3C = temp_a0 + var_a0;
    switch (temp_a2) {
    case 1:
        func_800179A4(arg0, 0);
        arg0->y_vel.val = 0x10000;
        break;
    case 2:
        func_800179A4(arg0, 1);
        arg0->y_vel.val = 0x10000;
        break;
    case 3:
        func_800179A4(arg0, 2);
        arg0->x_vel.val = 0x10000;
        break;
    case 4:
        func_800179A4(arg0, 2);
        arg0->unk15 = 0x40;
        arg0->x_vel.val = 0x10000;
        break;
    }
    func_8003CF24(0xA, 1, 1);
    func_80016C48(1, 0x16, arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
    {
        // !FAKE: depin: dropping it breaks the match (13/99)
        register s32 st asm("$2") = (u8)arg0->state;
        arg0->unk5 = 2;
        arg0->state = st + 1;
    }
}
#undef func_800179A4
