#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EF590 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC (*(M2C_UNK(*)(void*)) & func_80030ECC)
s32 check_enemy_hits(void*);
extern s32 D_8007573C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;
extern void (*D_800F75FC[])(void*);
extern s32 D_800F77D8;
extern s32 D_800F77DC;
extern s32 D_800F77E8;
extern s16 D_800F7804;
extern s8 D_800F7806;
extern u16 D_800F7808;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EF590(void* self) {
    s8 hp;
    u8 t;
    s32 r;

    D_800F7804 = 0;
    hp = F(s8, 0x5C);
    r = check_enemy_hits(self);
    D_800F7806 = 0;
    if (r > 0) {
        D_800F7806 = hp - F(u8, 0x5C);
        F(s8, 0x5C) = hp;
    }
    if (D_800F77DC != 0) {
        if (F(s8, 0x5) != 8) {
            if ((F(s8, 0x5C) -= 4) <= 0) {
                F(u16, 0x40) = 0x140;
                F(s16, 0x42) =
                    ((func_8002A47C(F(s8, 1)) * 4 + 0x20) % 16) |
                    (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
                F(u8*, 0x3C) = (u8*)SPAD20_800EF590 +
                               SPAD20_800EF590[func_8002A47C(F(s8, 1))];
                set_animation(self, 7);
                F(s8, 0x4) = 2;
                F(s8, 0x5C) = 0;
                F(s32, 0x20) = 0;
                F(s32, 0x24) = 0;
                F(s32, 0x28) = 0;
                F(s32, 0x2C) = 0;
                F(s8, 0x5) = 0;
                F(s8, 0x6) = 0;
                F(u16, 0x42) &= 0x7FFF;
                {
                    // !FAKE: depin: dropping it breaks the match (159/164)
                    register s32 one asm("$3") = 1;
                    D_800F77D8 = one;
                    g_Player.spike_immune = one;
                }
                g_Player.unk68 = 0;
                func_8002CCB0(self, 0x30, 0x40);
                return;
            }
            F(s8, 0x5) = 8;
            F(s8, 0x6) = 0;
        }
    } else if (F(s8, 0x5) != 8) {
        func_80030ECC(self);
    }
    t = F(u8, 0x84);
    if (t != 0) {
        F(u8, 0x84) = t + 0xFF;
        if (t & 2) {
            F(u16, 0x42) |= 0x8000;
        } else {
            F(u16, 0x42) &= 0x7FFF;
        }
        if (F(u8, 0x84) == 0) {
            F(s32*, 0x58) = D_8007573C;
            F(u16, 0x42) &= 0x7FFF;
        }
    }
    if (D_800F77E8 & (s16)D_800F7808++ & 1) {
        g_playthrough_state.unk10 = 1;
        g_playthrough_state.unk11 = 1;
        g_playthrough_state.unk13 = 1;
    } else {
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk13 = 0;
    }
    D_800F75FC[F(s8, 0x5)](self);
}

#undef F
#undef g_Player
#undef func_80030ECC
#undef SPAD20_800EF590
