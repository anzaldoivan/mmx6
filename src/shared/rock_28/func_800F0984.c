#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002C9B0();
s32 func_80030234();
void func_800F04C0();
void func_800F0754(void);
void func_800F089C();

extern M2C_UNK D_800970A0;
extern s16 D_80097202;
extern struct X4_ObjectHeader D_80097420;
#define D_80097420 (*(u32*)&D_80097420)
#define P ((struct X4_PlayerObj*)&D_800970A0)
extern struct X4_RideArmorObj D_800CD340;
extern u16 D_800E3142;
extern u16 D_800F35EC;

void func_800F0984(struct X4_PlayerObj* self) {
    struct X4_PlayerObj* pl;
    struct X4_RideArmorObj* ra;

    if (self->state == 0) {
        register s32 t asm("$4") = D_800E3142;
        D_800F35EC = t;
        func_800F04C0(t);
        func_800F089C();
        self->state++;
    }
    pl = (struct X4_PlayerObj*)&D_800970A0;
    if (pl->nova_strike_active == 2) {
        return;
    }
    if (pl->unk5 == 0x14) {
        if (self->bg_offset != 0) {
            func_80016C48(5, 3, 0);
            self->bg_offset = 0;
        }
        return;
    }
    if (D_80097202 >= 0xAC0) {
        func_80016C48(5, 3, 0);
        ((M2C_UNK(*)())func_8002C9B0)(self);
        return;
    }
    if (self->bg_offset == 0 || *(s16*)((u8*)pl + 0x14C) != 0) {
        func_80016C48(5, 6, 0);
        self->bg_offset = 1;
    }
    func_800F0754();
    if (D_80097420 == D_80097420 / 5 * 5) {
        D_800F35EC++;
        func_800F089C(P);
    }
    if (P->unk5 != 0x14 && pl->state == 1 && pl->hp != 0) {
        if (P->unk68 != 0) {
            if (func_80030234(
                    pl, pl->x_pos.i.hi,
                    (s16)(pl->unk68->unk1 + (pl->y_pos.i.hi + pl->unk68->unk3)),
                    pl->unk68) == 0x3A) {
                pl->x_pos.i.hi--;
            }
        }
        ra = &D_800CD340;
        if (ra->unk68 != 0 && !(ra->unk70 & 2) &&
            func_80030234(ra, ra->x_pos.i.hi,
                          (s16)(ra->unk68->unk1 +
                                (ra->y_pos.i.hi + ra->unk68->unk3))) == 0x3A) {
            ra->x_pos.i.hi--;
        }
    }
}
#undef D_80097420
#undef P
