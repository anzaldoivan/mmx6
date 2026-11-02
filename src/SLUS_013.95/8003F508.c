#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BB94(void*, M2C_UNK, s8);

M2C_UNK func_8003F508(void* arg0, M2C_UNK arg1) {
    u8* p = arg0;
    s32 var_a1;
    s8 temp_s0;

    if (*(s8*)(p + 2) == 0) {
        var_a1 = arg1 + 0x70;
        if (*(s8*)(p + 0x90) != 0) {
            temp_s0 = *(s8*)(p + 0x44);
            func_8003BB94(arg0, arg1, p[0x45] & 0x3F);
            *(s8*)(p + 0x44) = temp_s0;
        } else if (*(s8*)(p + 0x8E) != 0 && p[0x17] != var_a1) {
            temp_s0 = *(s8*)(p + 0x44);
            func_8003BB94(p, var_a1, p[0x45] & 0x3F);
            *(s8*)(p + 0x44) = temp_s0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void silence_sound(u8, u8);
void func_8003C4EC(struct X4_PlayerObj* self);
void func_8003CE30(void* arg0);
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF99;

M2C_UNK func_8003F58C(void) {
    struct X4_PlayerObj* pl = &g_Player;

    if (!(D_800CCF99 & 1) || (pl->weapon != 0)) {
        if (!(pl->input.buttons.held & 0x10)) {
            pl->charge_state[0] = 0;
            pl->charge_timer = 0;
        }
        if (!(pl->input.buttons.held & 0x20)) {
            pl->charge_state[1] = 0;
            pl->special_charge_timer = 0;
        }
        if (!(*(s32*)&pl->charge_state[1] & 0xFFFF00)) {
            silence_sound(1, 7);
            func_8003CE30(pl);
            pl->charge_state[0] = 0;
            pl->charge_state[1] = 0;
            pl->charge_timer = 0;
            pl->special_charge_timer = 0;
            func_8003C4EC(pl);
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 check_giga_attack(void* self);
void func_8003E614(void* arg0);
M2C_UNK start_player_attack(void*, M2C_UNK);
extern s8 D_80073E00[];

s32 func_8003F644(void* arg0) {
    s8* p = arg0;
    s8 idx;

    if (p[0xD3] != 0) {
        return 0;
    }
    if (p[2] != 0) {
        return 0;
    }
    if (check_giga_attack(arg0) != 0) {
        return 1;
    }
    func_8003E614(arg0);
    if (p[0x8F] == 0) {
        return 0;
    }
    idx = p[0x96];
    if (D_80073E00[idx] == 0) {
        return 0;
    }
    p[0x8C] = 0;
    if (idx == 5 || idx == 14) {
        func_8003BA04(arg0, 0x6C);
    }
    start_player_attack(arg0, 0);
    return 1;
}

#include "common.h"
#define M2C_UNK s32

void func_8003E614(void* arg0);

M2C_UNK func_8003F700(void* arg0) {
    s8* p = arg0;

    if (p[0xD3] != 0) {
        return 0;
    }
    if (p[2] != 0) {
        return 0;
    }
    return ((s32(*)(void*))func_8003E614)(arg0);
}
