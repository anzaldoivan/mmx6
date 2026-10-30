#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
void* enemy_slot_alloc();
s32 random_byte();
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define PL ((struct X4_BaseObj*)&g_Player)
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EF160(void* arg0) {
    s32 flag;
    s32 n;
    s32 r;
    s32 q;
    s32 m;
    void* obj;
    s32 t;
    u16 k;

    flag = 0;
    if (g_playthrough_state.stage == 2) {
        if ((u32)(PL->x_pos.u.hi - 0x1221) < 0x18F && PL->y_pos.i.hi >= 0xE1 &&
            PL->y_pos.i.hi < 0x4F0) {
            flag = g_playthrough_state.checkpoint == 2;
        }
        if ((u32)(PL->x_pos.u.hi - 0x1381) < 0x2AF && PL->y_pos.i.hi >= 0x501 &&
            PL->y_pos.i.hi < 0x6A0 && g_playthrough_state.checkpoint == 3) {
            flag = 1;
        }
    } else if (g_playthrough_state.stage == 8) {
        if ((u32)((u16)D_800970AA - 0x9D1) < 0x6AF) {
            flag = 1;
        }
    } else if (*(u16*)&g_playthrough_state.stage == 0x113) {
        if ((u32)(PL->x_pos.u.hi - 0x141) < 0x71F && PL->y_pos.i.hi < 0x3F0) {
            flag = 1;
        }
    } else if (*(u16*)&g_playthrough_state.stage == 0x116) {
        if ((u32)((u16)D_800970AA - 0x181) < 0x40F) {
            flag = 1;
        }
    }
    if (flag == 0) {
        SB(arg0, 0x82) = 0;
        return;
    }
    if (SB(arg0, 0x82) == 0) {
        SB(arg0, 0x82) = 1;
        func_80012D9C(8);
    }
    k = UH(arg0, 0x7E);
    UH(arg0, 0x7E) = k + 1;
    if (SB(arg0, 0x81) < (s16)k) {
        t = random_byte();
        H(arg0, 0x7E) = 0;
        SB(arg0, 0x81) = (t % 6) * 10 + 20;
        q = random_byte() % 3;
        if (q > 0) {
            n = q;
            do {
                obj = enemy_slot_alloc();
                if (obj != NULL) {
                    UB(obj, 0) = 0x41;
                    UB(obj, 1) = 0x13;
                    UB(obj, 2) = 0;
                    r = random_byte();
                    m = random_byte();
                    UH(obj, 0xA) = background_objects[0].x_pos.u.hi +
                                   (r % 4) * 0x50 + ((m % 3) << 5);
                    UH(obj, 0xE) = background_objects[0].y_pos.u.hi -
                                   (random_byte() % 5) * 0x10;
                    UH(obj, 0x42) = UH(arg0, 0x42) & 0x7FFF;
                    W(obj, 0x30) = W(arg0, 0x30);
                    W(obj, 0x3C) = W(arg0, 0x3C);
                    UH(obj, 0x40) = UH(arg0, 0x40);
                }
                n--;
            } while (n != 0);
        }
    }
    if (g_playthrough_state.stage != 0x16) {
        if (!(D_80097420 & 1)) {
            UB(arg0, 0x80) = 2;
            if (!(random_byte() & 0xF)) {
                UB(arg0, 0x80) = 6;
            }
            background_objects[0].y_pos.u.hi += (s8)UB(arg0, 0x80);
        } else {
            background_objects[0].y_pos.u.hi -= (s8)UB(arg0, 0x80);
        }
        return;
    }
    if (!(D_80097420 & 7)) {
        UB(arg0, 0x80) = 2;
        if (!(random_byte() & 0xF)) {
            UB(arg0, 0x80) = 6;
        }
        func_8002943C(4, SB(arg0, 0x80), 1);
    }
}
