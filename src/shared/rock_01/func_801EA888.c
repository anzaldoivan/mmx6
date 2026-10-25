#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* func_8002C398(void);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern struct X4_PlayerObj g_Player;
extern s8 D_8009742C;
extern s8 D_800CF850;
extern s32 D_801EF974[];

void func_801EA888(u8* arg0) {
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 kind;
    struct X4_PlayerObj* player;
    u8* obj;

    if (++arg0[0xE1] >= 2) {
        arg0[0xE1] = 0;
        for (i = 0; i < 16; i++) {
            D_80090C90[i + 16] = D_801EF974[i];
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
                // !FAKE: pin the halfword constant to the first return register
                register s32 x asm("$2") = 0x80;
                // !FAKE: pin the shifted counter to the second return register
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
                // !FAKE: pin the halfword constant to the first return register
                register s32 x asm("$2") = 0x180;
                // !FAKE: pin the shifted counter to the second return register
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
        arg0[6]++;
    }
}
