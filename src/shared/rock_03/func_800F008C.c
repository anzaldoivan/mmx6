#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002BBF4();
void* func_8002C458();
extern s16 D_800F7DCA;
extern s16 D_800F7DCC;
extern s16 D_800F7DCE;
extern s16 D_800F7DD0;
extern u16* D_800F7DF0;
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;
extern s16 D_800F7E10;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F008C(void* arg0) {
    s32 i;
    void* p;
    void* q;

    if (UB(arg0, 0x15) != 0) {
        if (W(arg0, 0x20) < 0 && H(arg0, 0xA) < D_800F7DCA) {
            H(arg0, 0xA) = D_800F7DCA;
            W(arg0, 0x20) = 0;
        } else if (W(arg0, 0x20) > 0 && H(arg0, 0xA) > D_800F7DCA) {
            H(arg0, 0xA) = D_800F7DCA;
            W(arg0, 0x20) = 0;
        }
    } else {
        if (W(arg0, 0x20) < 0 && H(arg0, 0xA) < D_800F7DCC) {
            H(arg0, 0xA) = D_800F7DCC;
            W(arg0, 0x20) = 0;
        } else if (W(arg0, 0x20) > 0 && H(arg0, 0xA) > D_800F7DCC) {
            H(arg0, 0xA) = D_800F7DCC;
            W(arg0, 0x20) = 0;
        }
    }
    if (H(arg0, 0x7E) == 0) {
        if (W(arg0, 0x24) > 0 && H(arg0, 0xE) < D_800F7DCE) {
            H(arg0, 0xE) = D_800F7DCE;
            W(arg0, 0x24) = 0;
        } else if (W(arg0, 0x24) < 0 && H(arg0, 0xE) > D_800F7DCE) {
            H(arg0, 0xE) = D_800F7DCE;
            W(arg0, 0x24) = 0;
        }
    } else {
        if (W(arg0, 0x24) > 0 && H(arg0, 0xE) < D_800F7DD0) {
            H(arg0, 0xE) = D_800F7DD0;
            W(arg0, 0x24) = 0;
        } else if (W(arg0, 0x24) < 0 && H(arg0, 0xE) > D_800F7DD0) {
            H(arg0, 0xE) = D_800F7DD0;
            W(arg0, 0x24) = 0;
        }
    }
    if (W(arg0, 0x20) == 0 && W(arg0, 0x24) == 0) {
        D_800F7E0E = 0;
        D_800F7E0C = *D_800F7DF0 - D_800F7E10;
        for (i = 0; i < D_800F7E0C; i++) {
            p = func_8002BBF4();
            if (p != 0) {
                UB(p, 0x0) = UB(arg0, 0x0);
                UB(p, 0x1) = UB(arg0, 0x1);
                UB(p, 0x2) = 1;
                UB(p, 0x5) = 1;
                P(p, 0x80) = arg0;
            }
        }
        if (D_800F7E0C != 0) {
            func_800179A4(arg0, 5);
            func_80016C48(2, 0x22, arg0);
            q = func_8002C458();
            if (q != 0) {
                UB(q, 0x0) = UB(arg0, 0x0);
                UB(q, 0x1) = 0xF;
                UB(q, 0x2) = 5;
                P(q, 0x7C) = arg0;
            }
        }
        UB(arg0, 0x6)++;
    }
}
