#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK player_spawn_weapon(M2C_UNK, s8, M2C_UNK, void*);
struct X4_VisualObj* func_8002C398(void);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_8009742C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern s8 D_801F4DD8;
extern u8 D_801F4DD9;
extern s32 D_801F4DE8[];

void func_801EA2B8(u8* arg0) {
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 kind;
    struct X4_PlayerObj* player;
    u16 t;
    u8* obj;

    if (--arg0[0xE1] == 0) {
        arg0[0xE1] = (func_8002D2D4() % 3) + 3;
        player_spawn_weapon(1, 0x31, D_801F4DD8, 0);
        D_801F4DD8 ^= 1;
    }
    if ((s8)++arg0[7] >= 0x79) {
        arg0[6]++;
        if (arg0[0x17] >= 0xB1) {
            func_8003BA04(arg0, 0xB3);
        } else {
            func_8003BA04(arg0, 0xB0);
        }
    }
    if (++D_801F4DD9 == 2) {
        for (i = 0; i < 16; i++) {
            D_80090C90[i + 16] = D_801F4DE8[i];
        }
        {
            s8* p0 = &D_80090D56;
            s8* p1 = &D_8009742C;
            s8* p2 = &D_800CF850;
            p0[1] = 1;
            p1[1] = 1;
            p2[1] = 1;
        }
        player = &g_Player;
        kind = 0;
        if (player->unk2 != 0) {
            a = 0x53;
            b = 0x54;
        } else {
            a = 0x55;
            b = 0x56;
        }
        j = 0;
        do {
            j++;
            obj = (u8*)func_8002C398();
            if (obj != 0) {
                // !FAKE: depin: dropping it breaks the match (3/186)
                register s32 x asm("$2") = 0x80;
                // !FAKE: depin: dropping it breaks the match (177/186)
                register s32 y asm("$3") = j << 6;
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = a;
                M2C_FIELD(obj, s16*, 0xA) = x;
                M2C_FIELD(obj, s16*, 0xE) = y;
                obj[5] = player->unk5;
            }
            obj = (u8*)func_8002C398();
            if (obj != 0) {
                // !FAKE: depin: dropping it breaks the match (3/186)
                register s32 x asm("$2") = 0x180;
                // !FAKE: depin: dropping it breaks the match (177/186)
                register s32 y asm("$3") = j << 6;
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = b;
                M2C_FIELD(obj, s16*, 0xA) = x;
                M2C_FIELD(obj, s16*, 0xE) = y;
                obj[5] = player->unk5;
            }
        } while (j < 5);
    }
    if (((s8*)arg0)[7] >= 0x73) {
        u16* q0 = (u16*)&D_800CF854;
        t = q0[1];
        if (t != 0) {
            u16* q1;
            u16* q2;
            q0[1] = t - 8;
            q1 = (u16*)&D_80097430;
            q2 = (u16*)&D_80090D5C;
            q1[1] -= 0x100;
            q2[1] -= 0x2000;
            if ((u16)(t - 8) < 8) {
                q2[1] = 0;
                q1[1] = 0;
                q0[1] = 0;
                arg0[0xE4] &= 0xFE;
                D_800C4560 |= 1;
            }
        }
    }
}
#undef g_Player
