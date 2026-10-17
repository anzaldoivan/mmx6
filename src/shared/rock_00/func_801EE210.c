#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_Unk_unk68 D_801F37C0[];
M2C_UNK func_8002C9B0();
#define func_8002C9B0 ((void (*)(struct X4_ObjectHeader * arg0)) func_8002C9B0)

void func_801EE210(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &D_800970A0;
    u8 temp_v0;

    if (D_800970A0.unk5 != 0x23) {
        func_8002C9B0(OBJECT_HEADER(arg0));
        return;
    }
    if (arg0->state == 0) {
        arg0->unk50 = &D_801F37C0;
        arg0->unk64 = 1U;
        arg0->ext.raw[0] = 4U;
        arg0->state++;
    } else {
        temp_v0 = arg0->ext.raw[0];
        if (temp_v0 == 0) {
            arg0->ext.raw[0] = 4U;
            arg0->unk64++;
        } else {
            arg0->ext.raw[0] = temp_v0 - 1;
        }
    }
    arg0->x_pos.val = player->x_pos.val;
    arg0->y_pos.val = player->y_pos.val;
    arg0->unk15 = player->unk15;
}
#undef D_800970A0
#undef func_8002C9B0
