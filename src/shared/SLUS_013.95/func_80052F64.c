#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_8007A124[];
extern s16 D_8007A154[][16][4];
extern u8 D_80097428;
extern u16 D_800C4570;
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);

#define P14E (D_800970A0.pad4B[0x14E - 0x4B])
#define EH(b, i) (*(u16*)((u8*)(b) + 0x9E + (i) * 2))

static inline s32 bit_test(s32 n) {
    u8 k = D_8007A124[D_800CCED0.substage + D_800CCED0.stage * 2];
    u16 m = 1 << n;
    return EH(&D_800CCED0, k) & m;
}

static inline void bit_set(s32 n) {
    u8 k = D_8007A124[D_800CCED0.substage + D_800CCED0.stage * 2];
    u16 m = 1 << n;
    EH(&D_800CCED0, k) |= m;
}

void func_80052F64(u8* arg0) {
    struct X4_EngineObj* e = &D_800CCED0;
    u8 st;
    u8 sub;
    s32 t;
    s32 n;
    s8 i;
    struct X4_PlayerObj* pp;

    if (D_800970A0.hp == 0) {
        return;
    }
    sub = e->substage;
    st = e->stage;
    if (bit_test(arg0[2] & 0xF)) {
        arg0[4] = 2;
        return;
    }
    if (D_80097428 != 0) {
        arg0[4] = 2;
        return;
    }
    t = D_800970A0.nova_strike_active == 2;
    if (D_800970A0.nova_strike_active == 1 && (arg0[2] & 0x80)) {
        t = 1;
    }
    if (t != 0) {
        P14E = 0;
        return;
    }
    pp = &D_800970A0;
#define TB (D_8007A124[(s8)sub + ((s8)st << 1)])
    if (pp->x_pos.i.hi > D_8007A154[TB][(n = arg0[2] & 0xF, i = n)][0] &&
        pp->x_pos.i.hi < D_8007A154[TB][i][1] &&
        pp->y_pos.i.hi > D_8007A154[TB][i][2] &&
        pp->y_pos.i.hi < D_8007A154[TB][i][3]) {
        if (!(arg0[2] & 0xF0) ||
            !((u8)D_800970A0.action < 2 || D_800970A0.hp == -0x80 ||
              D_800970A0.hp == 0 || D_800970A0.ride_animation != 0)) {
            if (arg0[2] & 0xF0) {
                if (!(D_800C4570 & 0x100)) {
                    P14E = n;
                    if (i == 0) {
                        P14E = 0xF;
                    }
                    if (arg0[0x16] == 0) {
                        func_80016C48(0, 0x2A, 0);
                        arg0[0x16] = 1;
                    }
                    return;
                }
                *(s16*)(arg0 + 0x14) = 0;
                D_800CCED0.unk10 = 2;
            } else {
                func_8003D308(0x14, D_800970A0.facing);
                *(s16*)(arg0 + 0x14) = 1;
            }
            if (bit_test(arg0[2] & 0xF)) {
                arg0[4] = 2;
            } else {
                bit_set(arg0[2] & 0xF);
                arg0[4]++;
            }
        }
    } else {
        arg0[0x16] = 0;
    }
    t = arg0[2] & 0xF;
    if (t == 0) {
        if (P14E == 0xF) {
            P14E = 0;
        }
    } else if (P14E == t) {
        P14E = 0;
    }
}
