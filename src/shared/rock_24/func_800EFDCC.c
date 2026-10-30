#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E98BC[];
extern u8 D_800F7528[];
extern s32 D_800F77E4;
extern M2C_UNK D_800F77EC;
extern s32 D_800F77F0;
extern s32 D_800F77F4;

#define ENG ((u8*)&g_playthrough_state)

void func_800EFDCC(u8* arg0) {
    u8 sp10[4];
    u32 r;
    u8 idx;
    s32 t;
    u8* eng;
    u8* eng2;

    __builtin_memcpy(sp10, D_800E98BC, 4);
    r = random_byte() & 0xF;
    eng = (u8*)&g_playthrough_state;
    arg0[0x87] = 0;
    if (D_800F77EC < sp10[eng[0x8F]] && D_800F77F0 == 0 && D_800F77F4 == 0) {
        if (((s8)eng[0x8C] / 2) < (s8)arg0[0x5C]) {
            if (r < 8) {
                goto zero;
            }
            arg0[0x86] = 1;
        } else if (r < 5) {
        zero:
            arg0[0x86] = 0;
        } else {
            if (r >= 10) {
                arg0[0x86] = 2;
            } else {
                arg0[0x86] = 1;
            }
        }
        D_800F77E4 = 0;
    } else if (eng2 = (u8*)&g_playthrough_state,
               ((s8)eng2[0x8C] / 2) < (s8)arg0[0x5C]) {
        if (D_800F77E4 < 4) {
            goto three;
        }
        goto four;
    } else if (D_800F77E4 < 3) {
    three:
        arg0[0x86] = 3;
    } else {
    four:
        arg0[0x86] = 4;
        D_800F77E4 = 0;
    }
    idx = arg0[0x87]++;
    t = D_800F7528[idx + arg0[0x86] * 6];
    arg0[6] = 0;
    arg0[5] = t;
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}

#undef ENG
