#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 random_byte();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E98C0[];

// str 0x800E98C0 sha1=1319e42db8e4d96764593c2726f8a8f863f48283 = "printable byte run: data, not text"
void func_800F0098(void* arg0) {
    u8 tbl[4];
    s32 r;
    s32 a;
    s32 b;
    s16 angle;
    u16 px;
    u16 py;

    __builtin_memcpy(tbl, D_800E98C0, 4);
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        r = random_byte() & 0xF;
        if (r < 3) {
            ((void (*)(s32, s32, s32))play_sound)(2, 0x22, (s32)arg0);
        } else if (r < 6) {
            ((void (*)(s32, s32, s32))play_sound)(2, 0x23, (s32)arg0);
        }
        if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u16*, 0x40) = 0x140;
        a = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        b = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        M2C_FIELD(arg0, u16*, 0x42) =
            ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, u16*, 0x88) = px = g_Player.x_pos.i.hi;
        M2C_FIELD(arg0, u16*, 0x8A) = py = g_Player.y_pos.i.hi;
        angle = ratan2((s16)py - M2C_FIELD(arg0, s16*, 0xE),
                       (s16)px - M2C_FIELD(arg0, s16*, 0xA));
        {
            u8* e;
            s32 c;
            c = rcos(angle);
            e = (u8*)&g_playthrough_state;
            M2C_FIELD(arg0, s32*, 0x20) = c * tbl[e[0x8F]];
            M2C_FIELD(arg0, s32*, 0x24) = -rsin(angle) * tbl[e[0x8F]];
        }
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
#undef g_Player
