#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u32* D_8007789C[];
extern u8 D_80077C0C[][3];
extern struct X4_PlayerObj D_800970A0;
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800499A0(void*);
s32 func_801EE434(void);

void func_80049270(struct X4_VisualObj* arg0) {
    register s32 idx asm("$17");
    s8 kind;

    kind = arg0->unk2;
    arg0->on_screen = 1;
    if (kind == 9) {
        idx = 0;
    } else if (kind == 18) {
        idx = 1;
    } else if (kind == 20) {
        idx = 2;
    } else if (kind == 0) {
        idx = 3;
    } else if (kind == 19) {
        idx = 2;
    } else if (kind == 45) {
        idx = 3;
    }
    arg0->unk3C =
        (void*)((s8*)SP_SPRITE_FRAMES + SP_SPRITE_FRAMES[D_80077C0C[idx][0]]);
    arg0->animation_table = D_8007789C;
    arg0->unk40 = 0;
    arg0->unk42 = 0x7802;
    if (idx == 3) {
        if (arg0->unk2 == 0) {
            arg0->unk42 = func_801EE434();
            {
                struct X4_PlayerObj* player = &D_800970A0;
                if (*(s32*)((u8*)player + 0xEC) & 0x40000) {
                    arg0->unk42 = 0x7844;
                }
            }
        }
    }
    arg0->unk16 = 0;
    {
        struct X4_PlayerObj* player = &D_800970A0;
        arg0->unk15 = player->unk15;
    }
    arg0->unk5C.value = 0;
    func_800499A0(arg0);
    arg0->x_pos.i.lo = 0;
    arg0->y_pos.i.lo = 0;
    func_800179A4(arg0, D_80077C0C[idx][1]);
    func_80016C48(1, D_80077C0C[idx][2], arg0);
    arg0->state++;
    func_8002CCB0(arg0, 0x40, 0x20);
}
