#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
void func_8003CF54(struct X4_PlayerObj*, s32);
extern u8 D_800CCF2F;

#define PAL_BUF (*(u8**)0x1F800024)
#define PAL_BUF_B ((u8*)((struct X4_PlayerObj*)0x1F800000)->y_vel.val)
#define PLAYER_FLAGS_EC(p) (*(s32*)((u8*)(p) + 0xEC))

void func_8003C4EC(struct X4_PlayerObj* self) {
    s32 flags;
    s32 load;

    if (self->unk2 == 0) {
        s8 weapon = self->weapon;
        if (weapon == 0) {
            func_8003CF54(self, 0);
        } else {
            load = 1;
            if (weapon == 2) {
                load = 0;
            } else if (weapon == 3) {
                load = 0;
            } else if (weapon == 4) {
                load = 0;
            } else if (weapon == 5) {
                load = 0;
            } else if (weapon == 7) {
                load = 0;
            }
            if (load != 0) {
                load_palette(1, (s32*)(PAL_BUF + ((self->weapon << 7) - 0x20)),
                             1);
            }
            load_palette(0, (s32*)(PAL_BUF + (self->weapon << 7)), 1);
            load_palette(0x13, (s32*)(PAL_BUF_B + ((self->weapon << 7) | 0x20)),
                         1);
        }
        flags = PLAYER_FLAGS_EC(self);
        if (flags & 0x80) {
            load_palette(0x14, (s32*)(PAL_BUF + 0x9E0), 1);
            return;
        }
        if (flags & 0x100) {
            load_palette(0x14, (s32*)(PAL_BUF + 0x9C0), 1);
            return;
        }
        if (flags & 0x40000) {
            load_palette(0x14, (s32*)(PAL_BUF + 0x9A0), 1);
        }
    } else {
        if (D_800CCF2F & 0x20) {
            load_palette(0, (s32*)(PAL_BUF + 0x1A0), 1);
            load_palette(0xD, (s32*)(PAL_BUF_B + 0x9A0), 3);
            return;
        }
        load_palette(0, (s32*)PAL_BUF, 1);
    }
}
#undef PAL_BUF
#undef PAL_BUF_B
#undef PLAYER_FLAGS_EC
