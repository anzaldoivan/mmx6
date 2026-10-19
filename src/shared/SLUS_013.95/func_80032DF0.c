#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
M2C_UNK func_80022928();
M2C_UNK func_80025FB0();

extern u8 D_80073970[];
extern u8 D_8007397C[];
extern u8 D_80073988[];
extern u8 D_80073990[];
extern struct X4_PlayerObj D_800970A0;
extern s8 D_80097424;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800E4430;

void func_80032DF0(u8* arg0) {
    struct X4_PlayerObj* pl;
    u8* p;
    s32 i;
    u32 j;
    s32 n;
    s32 k;

    pl = &D_800970A0;
    if (D_80097424 != 0) {
        func_80025FB0();
        return;
    }
    func_800139A0(0x20);
    arg0[5] = 2;
    arg0[0x14] = 0;
    if (pl->unk2 == 0) {
        arg0[0x16] = 1;
        i = 1;
        p = arg0 + 0x16;
        for (; i < 9; i++) {
            if (((u8*)pl)[0xC9] & D_80073988[D_80073970[i]]) {
                p[i] = 1;
            } else {
                p[i] = 0;
            }
        }
        if (((u8*)pl)[0xE7] != 0) {
            arg0[0x1F] = 1;
        } else {
            arg0[0x1F] = 0;
        }
    } else {
        arg0[0x16] = 2;
        i = 1;
        p = arg0 + 0x16;
        for (; i < 9; i++) {
            k = D_80073970[i];
            k = D_80073990[k];
            if (((u8*)pl)[0xC9] & D_80073988[k]) {
                p[i] = 1;
            } else {
                p[i] = 0;
            }
        }
        arg0[0x1F] = 0;
    }
    arg0[0x20] = 0;
    arg0[0x21] = 0;
    {
        u8* e = (u8*)&D_800CCED0;
        if (*(u16*)(e + 0x6A) & 0x3000) {
            if (*(u16*)(e + 0x6A) & 0x1000) {
                arg0[0x20] = 1;
                e[0x63] |= 0x80;
            }
            if (*(u16*)(e + 0x6A) & 0x2000) {
                arg0[0x21] = 1;
                e[0x64] |= 0x80;
            }
        }
    }
    {
        u8* e = (u8*)&D_800CCED0;
        if (*(u16*)(e + 0x6A) & 0x4000) {
            arg0[0x22] = 1;
        } else {
            arg0[0x22] = 0;
        }
    }
    arg0[0x23] = 1;
    arg0[0x24] = 1;
    arg0[0x25] = 1;
    {
        u8* e = (u8*)&D_800CCED0;
        if ((u32)(e[0xC] - 1) < 8) {
            if ((e[0x60] >> ((s8)e[0xC] - 1)) & 1) {
                arg0[0x26] = 1;
            } else {
                arg0[0x26] = 0;
            }
        }
    }
    if (D_800970A0.unk2 == 0) {
        for (i = 0; i < 8; i++) {
            if (pl->weapon == D_8007397C[i]) {
                break;
            }
        }
        arg0[0x14] = i;
    } else {
        if (pl->weapon != 0) {
            if (pl->weapon == 1) {
                arg0[0x14] = 2;
            } else if (pl->weapon == 2) {
                arg0[0x14] = 4;
            } else if (pl->weapon == 3) {
                arg0[0x14] = 1;
            } else if (pl->weapon == 4) {
                arg0[0x14] = 7;
            } else {
                arg0[0x14] = 8;
            }
        } else {
            u8* q = arg0 + 0x16;
            for (j = 0; j < 0x11; j++) {
                if (q[j] != 0) {
                    arg0[0x14] = j;
                    break;
                }
            }
        }
    }
    {
        u8* e = (u8*)&D_800CCED0;
        if (*(u16*)(e + 0x6A) & 0x8000) {
            arg0[0x27] = 1;
        } else {
            arg0[0x27] = 0;
        }
    }
    n = 0;
    arg0[0x28] = 0;
    arg0[0x29] = 0;
    arg0[0x2A] = 0;
    arg0[0x2B] = 0;
    arg0[0x2D] = 0;
    for (i = 0; i < 0x18; i++) {
        if (*(s32*)((u8*)pl + 0xEC) & (4 << i)) {
            if ((u32)(i - 10) < 6) {
                arg0[0x2D] = i - 9;
            } else {
                u8* q = arg0 + 0x16;
                q[n + 0x12] = i + 1;
                n++;
            }
        }
        if (n >= 4) {
            n = 3;
        }
    }
    {
        u8* e = (u8*)&D_800CCED0;
        e -= -pl->unk2;
        arg0[0x2C] = e[0x8D];
    }
    D_800E4430 = D_800970A0.weapon;
    *(s32*)(arg0 + 0x30) = 0;
    *(s32*)(arg0 + 0x34) = 0;
    *(s32*)(arg0 + 0x38) = 0;
    func_80022928(0, 0);
}
