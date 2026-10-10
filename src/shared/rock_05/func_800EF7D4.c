#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_800970AE;
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_800F4480;
extern s16 D_800F4484;

void func_800EF7D4(struct X4_MainObj* self) {
    s32 d;

    if (D_800970AE > D_800F4480 + 0x440) {
        D_800971F8[1].y_pos.i.hi = D_800F4484 + 0x900;
        d = self->y_pos.i.hi;
        if (d <= D_800F4480 + 0x3D8) {
            d -= 0x3D8;
            if (d - D_800F4480 >= 0) {
                if (d - D_800F4480 >= 0x11) {
                    goto fa1;
                }
            } else if (D_800F4480 - d >= 0x11) {
            fa1:
                func_800179A4(self, 4);
            }
            self->y_speed = -0x50000;
        } else {
            d -= 0x3D8;
            if (d - D_800F4480 >= 0) {
                if (d - D_800F4480 >= 0x11) {
                    goto fa2;
                }
            } else if (D_800F4480 - d >= 0x11) {
            fa2:
                func_800179A4(self, 3);
            }
            self->y_speed = 0x50000;
        }
        SCRATCH_4C[0x8B] = 1;
    } else {
        D_800971F8[1].y_pos.i.hi = D_800F4484 + 0xBA0;
        d = self->y_pos.i.hi;
        if (d <= D_800F4480 + 0x438) {
            d -= 0x438;
            if (d - D_800F4480 >= 0) {
                if (d - D_800F4480 >= 0x11) {
                    goto fb1;
                }
            } else if (D_800F4480 - d >= 0x11) {
            fb1:
                func_800179A4(self, 4);
            }
            self->y_speed = -0x50000;
        } else {
            d -= 0x438;
            if (d - D_800F4480 >= 0) {
                if (d - D_800F4480 >= 0x11) {
                    goto fb2;
                }
            } else if (D_800F4480 - d >= 0x11) {
            fb2:
                func_800179A4(self, 3);
            }
            self->y_speed = 0x50000;
        }
        SCRATCH_4C[0x8B] = 2;
    }
    D_800971F8[1].unk4C = 1;
    self->unk6++;
}
