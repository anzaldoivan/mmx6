#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern u8 D_800F7BA0[][6];
extern s16 D_800F7E10;
extern s16 D_800F7E40[][4];

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F174C(void* arg0) {
    s16 ang;
    u8 idx;

    if (H(arg0, 0x7C) == 0x5A) {
        play_sound(2, 0x2A, arg0);
    }
    if (!(H(arg0, 0x7C) & 7)) {
        if (g_Player.x_pos.i.hi > H(arg0, 0xA)) {
            UB(arg0, 0x15) = 0x40;
        } else {
            UB(arg0, 0x15) = 0;
        }
        ang = ratan2(g_Player.y_pos.i.hi - H(arg0, 0xE),
                     g_Player.x_pos.i.hi - H(arg0, 0xA));
        W(arg0, 0x20) = rcos(ang) << 5;
        W(arg0, 0x24) = -rsin(ang) << 5;
    }
    D_800F7E40[H(arg0, 0x8E)][0] = H(arg0, 0xA);
    D_800F7E40[H(arg0, 0x8E)][1] = H(arg0, 0xE);
    D_800F7E40[H(arg0, 0x8E)][2] = UB(arg0, 0x15);
    if (++H(arg0, 0x8E) == 0xD2) {
        H(arg0, 0x8E) = 0;
    }
    if (++H(arg0, 0x7C) == 0x1F4 || D_800F7E10 == 0) {
        set_animation(arg0, 0);
        idx = UB(arg0, 0x87)++;
        W(arg0, 0x20) = 0;
        W(arg0, 0x24) = 0;
        UB(arg0, 0x5) = D_800F7BA0[UB(arg0, 0x86)][idx];
        UB(arg0, 0x6) = 0;
    }
}
