#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern void (*D_801F397C[])(struct X4_WeaponObj*);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80031DA8();

void func_801EECE8(struct X4_WeaponObj* arg0) {
    s32 var_a0;
    u8 temp_s0;
    s32 temp_s1;
    struct X4_PlayerObj* player = &D_800970A0;

    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    var_a0 = M2C_FIELD(player, s8*, 0xD3) != 0;
    if (M2C_FIELD(player, s8*, 0xD4) != 0) {
        var_a0 = 1;
    }
    if (M2C_FIELD(player, s8*, 0x93) != 2) {
        var_a0 = 1;
    }
    if (M2C_FIELD(player, s8*, 0x96) == 0xB) {
        var_a0 = 1;
    }
    if (var_a0 != 0) {
        arg0->state = 3;
    }
    M2C_FIELD(arg0, u8*, 0x8C) = arg0->unk70 | arg0->unk71;
    D_801F397C[arg0->state](arg0);
    if (arg0->id == 2) {
        if (arg0->unk75 != 0 && M2C_FIELD(player, u8*, 0xE5) == 0) {
            temp_s1 = M2C_FIELD(player, u8*, 0x72);
            M2C_FIELD(player, u8*, 0x72) = 8;
            temp_s0 = arg0->unk72;
            func_80031DA8(arg0);
            temp_s1 |= arg0->unk72 & 8;
            M2C_FIELD(player, u8*, 0x72) = temp_s1;
            if ((temp_s0 & 8) && !(arg0->unk72 & 8)) {
                M2C_FIELD(player, u8*, 0x72) = temp_s1 | 8;
            }
        }
        func_8002F288((M2C_UNK*)arg0);
        arg0->unk71 = 0;
    }
}
#undef D_800970A0
