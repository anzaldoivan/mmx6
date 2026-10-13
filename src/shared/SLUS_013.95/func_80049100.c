#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002C9B0();
s32 func_8002CB50(struct X4_BaseObj*);
M2C_UNK func_80049748();
extern u32* D_8007789C[];
extern struct X4_PlayerObj D_800970A0;

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_80049100(struct X4_VisualObj* arg0) {
    s32 var_v1;
    u8* p;
    s32 off;

    if (D_800970A0.unk5 == 0x14) {
        ((void (*)())func_8002C9B0)();
        return;
    }
    if (arg0->state == 0) {
        arg0->on_screen = 1;
        arg0->unk38 = 0;
        p = SCRATCH_1C;
        off = *(s32*)(p + 4);
        arg0->animation_table = D_8007789C;
        arg0->unk40 = 0;
        arg0->unk42 = 0x7802;
        arg0->unk16 = 3;
        arg0->unk3C = p += off;
        ((void (*)())func_80049748)(arg0, &D_800970A0, p, off);
        ((void (*)())func_800179A4)(arg0, 2);
        arg0->state++;
    } else {
        ((void (*)())func_80017A04)(arg0);
        ((void (*)())func_80049748)(arg0, &D_800970A0);
        var_v1 = 0;
        if (D_800970A0.dash_momentum > 0) {
            if (D_800970A0.unk17 != 0x10) {
                var_v1 = D_800970A0.unk17 != 0x80;
            }
        } else if (D_800970A0.unk17 != 0x55 && D_800970A0.unk17 != 0x12 &&
                   D_800970A0.unk17 != 0xAB && D_800970A0.unk17 != 0xAC &&
                   D_800970A0.unk17 != 0xAD && D_800970A0.unk17 != 0xA9) {
            var_v1 = 1;
        }
        if (arg0->animation_step.fields.relative_step < 0) {
            var_v1 = 1;
        }
        if (var_v1 != 0) {
            ((void (*)())func_8002C9B0)(arg0);
            return;
        }
    }
    ((s32 (*)())func_8002CB50)(arg0);
}
