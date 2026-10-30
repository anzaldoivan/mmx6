#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u8 D_8008EAFC;
extern s32 g_Player;
extern s8 D_800CCEF6;

#define PL ((u8*)&g_Player)
#define F_S8(p, o) (*(s8*)((p) + (o)))
#define F_S16(p, o) (*(s16*)((p) + (o)))

void func_800EE1D4(u8* arg0) {
    u8* pl;
    s8 hp;
    s8 v;

    if (D_800CCEF6 == 0) {
        arg0[4]++;
        return;
    }
    pl = PL;
    if (F_S16(pl, 0x14C) != 0) {
        play_sound(5, 4, 0);
    }
    if (F_S8(pl, 0x5C) != 0 && F_S8(pl, 0xE0) == 0) {
        if (++*(u16*)(arg0 + 0x16) >= 0xB4) {
            *(u16*)(arg0 + 0x16) = 0;
            hp = F_S8(pl, 0x5C);
            v = F_S8(pl, 0x5C) & 0x7F;
            F_S8(pl, 0x5C) = v;
            if (D_8008EAFC == 0) {
                if (v < 2) {
                    F_S8(pl, 0x5C) = -0x80;
                } else {
                    F_S8(pl, 0x5C) = v - 1;
                }
            }
            if (hp < 0) {
                u8* q = PL;
                F_S8(q, 0x5C) |= 0x80;
            }
        }
        if (++*(u16*)(arg0 + 0x18) >= 0x33) {
            u8* q = PL;
            *(u16*)(arg0 + 0x18) = 0;
            F_S8(q, 0xE8) = 1;
        }
    }
}
#undef PL
#undef F_S8
#undef F_S16
