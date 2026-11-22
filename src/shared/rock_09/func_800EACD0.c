// rolefeed (3.1 T4): func_800EACD0 of src/rock_09/E9860.c
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern u8 D_800F4BF0[];
extern M2C_UNK D_800F5C50;

void func_800EACD0(s8* arg0) {
    s8 v;

    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    animate_object();
    ((void (**)(s8*))(D_800F4BF0 + 0x1078))[arg0[5]](arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_800477E4(5, &D_800F5C50, arg0);
        func_80049E50(arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x13);
        v = 2;
        arg0[4] = v;
        return;
    }
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    v = 3;
    arg0[4] = v;
}
