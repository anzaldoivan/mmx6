#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;

void func_80051C68(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_VisualObj* obj;

    if (arg0->unk72 & 8) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        player = &D_800970A0;
        func_8003D308(0x18, player->unk15);
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0x24;
            obj->unk2 = 0;
            obj->bg_offset = arg0->bg_offset;
            obj->unk50 = arg0;
        }
        {
            s32 x = arg0->x_pos.val;
            player->item_step = 1;
            D_800CCED0.unk16 = 1;
            D_800CCED0.unk12 = 1;
            D_800CCED0.unk13 = 1;
            D_800CCED0.unk17 = 1;
            player->x_pos.val = x;
        }
        arg0->unk5++;
    }
}
