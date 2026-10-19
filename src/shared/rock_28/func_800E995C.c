#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
extern M2C_UNK D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800E995C(void* arg0) {
    struct X4_BackgroundObj* bg = &D_800971F8[0];

    if (bg->x_pos.i.hi >= M2C_FIELD(arg0, s16*, 0x14)) {
        struct X4_PlayerObj* pl = &D_800970A0;

        M2C_FIELD(pl, s32*, 0xF4) -= 0x8000;
        ((M2C_UNK(*)())func_8002C9B0)();
        return;
    }
    bg->x_pos.val += 0x8000;
    bg->unk1C = bg->x_pos.i.hi;
    bg->unk1E = bg->x_pos.i.hi;
    bg->unk24 = bg->x_pos.i.hi;
    bg->unk26 = bg->x_pos.i.hi;
}
