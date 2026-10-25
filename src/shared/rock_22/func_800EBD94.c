#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003D308(M2C_UNK, u8);

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800FB750[])(struct X4_MainObj*);

void func_800EBD94(struct X4_MainObj* arg0) {
    struct X4_PlayerObj* pl;

    D_800FB750[arg0->unk6](arg0);
    if (M2C_FIELD(arg0, s8*, 0x80) == 0) {
        if (g_Player.x_pos.i.hi >= 0x1AF1) {
            M2C_FIELD(arg0, s8*, 0x80) = 1;
            background_objects[0].unk2E -= 0x10;
        }
    }
    pl = &g_Player;
    if (pl->x_pos.i.hi >= 0x1B41 && pl->y_pos.i.hi >= 0x241 && arg0->unk6 < 9) {
        arg0->unk6 = 9;
        arg0->unk7C = 0;
        func_80016C48(5, 1, arg0);
        func_80012D9C(4);
        func_8003D308(0x14, pl->unk15);
    }
}
