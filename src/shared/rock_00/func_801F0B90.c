#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern void (*D_801F3A28[])(struct X4_WeaponObj*);

void func_801F0B90(struct X4_WeaponObj* arg0) {
    s32 var_a1;
    struct X4_PlayerObj* player = &D_800970A0;

    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    var_a1 = M2C_FIELD(player, s8*, 0xD3) != 0;
    if (M2C_FIELD(player, s8*, 0xD4) != 0) {
        var_a1 = 1;
    }
    if (M2C_FIELD(player, s8*, 0x93) != 5) {
        var_a1 = 1;
    }
    if (M2C_FIELD(player, s8*, 0x96) == 0xE) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 2;
    }
    D_801F3A28[arg0->state](arg0);
}
#undef D_800970A0
