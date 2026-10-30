#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK clear_object_slot();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);
extern s32 D_8007798C;
extern struct X4_PlayerObj g_Player;
extern s32 D_801EE3E8;
extern s32 D_801EE3FC;

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801EDCC8(u8* arg0) {
    struct X4_PlayerObj* pl;
    u8* tbl;
    u8* sc;
    s32 v;
    s32 a;
    s32 b;
    s32 t;
    s8 state;

    pl = &g_Player;
    state = SB(arg0, 4);
    if (state == 0) {
        W(arg0, 0x68) = (s32)&D_801EE3E8;
        W(arg0, 0x50) = (s32)&D_801EE3FC;
        sc = SCRATCH_1C;
        t = W(sc, 0x30);
        W(arg0, 0x30) = (s32)&D_8007798C;
        H(arg0, 0x40) = 0;
        H(arg0, 0x42) = 0x7802;
        B(arg0, 0x16) = 1;
        W(arg0, 0x3C) = (s32)(sc + t);
        if (B(arg0, 0x15) == 0) {
            H(arg0, 0xA) = UH(pl, 0xA) - 0x30;
            if (W(pl, 0xEC) & 0x100) {
                W(arg0, 0x20) = 0xFFF34000;
            } else {
                W(arg0, 0x20) = 0xFFF74000;
            }
        } else {
            H(arg0, 0xA) = UH(pl, 0xA) + 0x30;
            v = 0x80000;
            if (W(pl, 0xEC) & 0x100) {
                v = 0xC0000;
            }
            W(arg0, 0x20) = v | 0xC000;
        }
        H(arg0, 0xE) = UH(pl, 0xE) - 6;
        W(arg0, 0x24) = 0;
        set_animation(arg0, 0);
        W(arg0, 0x84) = H(arg0, 0xA);
        B(arg0, 4)++;
        // !FAKE: shared tail call block placed last, as retail lays it out
        goto tail;
    } else if (state == 1) {
        if (B(arg0, 0x15) == 0) {
            v = UH(pl, 0xA) - 0x30;
        } else {
            v = UH(pl, 0xA) + 0x30;
        }
        H(arg0, 0xA) = v;
        H(arg0, 0xE) = UH(pl, 0xE) - 6;
        ((void (*)())func_80017A04)(arg0);
        if (SB(arg0, 0x45) & 0x80) {
            B(arg0, 4)++;
        }
        // !FAKE: shared tail call block placed last, as retail lays it out
        goto tail;
    } else if (state == 2) {
        if (func_8002CBFC(arg0, 0x10, 0x10) != 0 || SB(arg0, 0x98) != 0) {
            // !FAKE: shared dead-path call block before the tail, as retail lays it out
            goto dead;
        }
        W(arg0, 0x68) = (s32)(&D_801EE3E8 + (B(arg0, 0x45) & 0x7F));
        if (B(arg0, 0x70) != 0 || (func_8002EE10(arg0), B(arg0, 0x70) != 0)) {
            func_800383F8(arg0);
            // !FAKE: shared dead-path call block before the tail, as retail lays it out
            goto dead;
        }
        ((void (*)())func_80017A04)(arg0);
        W(arg0, 0x68) = (s32)(&D_801EE3E8 + (B(arg0, 0x45) & 0x7F));
        move_object(arg0);
        if (pl->unk5 == 0x11) {
            // !FAKE: shared dead-path call block before the tail, as retail lays it out
            goto dead;
        }
        a = H(arg0, 0xA);
        b = W(arg0, 0x84);
        v = b - a;
        if (v >= 0) {
            if (v >= 0xA0) {
                // !FAKE: asymmetric range test keeps the two compares from cross-jumping
                goto inc;
            }
            // !FAKE: shared tail call block placed last, as retail lays it out
            goto tail;
        }
        if (a - b < 0xA0) {
            // !FAKE: shared tail call block placed last, as retail lays it out
            goto tail;
        }
    inc:
        B(arg0, 4)++;
        set_animation(arg0, 1);
        W(arg0, 0x68) = 0;
        W(arg0, 0x50) = 0;
        return;
    } else {
        func_80017A04(arg0);
        if (func_8002CBFC(arg0, 0x10, 0x10) != 0 || SB(arg0, 0x46) == 0) {
            // !FAKE: shared dead-path call block before the tail, as retail lays it out
            goto dead;
        }
        // !FAKE: shared tail call block placed last, as retail lays it out
        goto tail;
    }
dead:
    clear_object_slot(arg0);
    return;
tail:
    func_8002CCB0(arg0, 0x10, 0x10);
}
