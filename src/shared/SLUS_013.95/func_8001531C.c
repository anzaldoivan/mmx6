#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

int func_800617A4(X4_CdlLOC* p);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*);
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
int func_80064CB4(void* madr, int size);

extern s32 D_80010038[4];
extern u8** D_8006E27C[];
extern u8 D_8009509C;
extern s32 D_8009B798;
extern M2C_UNK* D_800B91B8;
extern s32 D_800E01A8;
extern s32 D_800E01B0;
extern s32 D_800E01B4;
extern s32* D_800E01B8;
extern u32 D_800E01BC;
extern s32 D_800E01C4;
extern u8 D_800E01CD;
extern s32 D_800E01D0;
extern u8* D_800E0368;
extern s32 D_800E036C;
extern u8* D_800E0370;
extern s32 D_800E0374;
extern X4_CdlLOC D_800E0388;
extern s32 D_800E0D40[];

#define STEP()                                                                 \
    D_800E01C4--;                                                              \
    D_800E01BC = *D_800E01B8++;                                                \
    D_800E01A8 = *D_800E01B8++;                                                \
    if ((D_800E01BC >> 16) == 0) {                                             \
        D_800E036C = D_800E01A8;                                               \
    }                                                                          \
    D_800E01CD = ret;

void func_8001531C(void) {
    s32 tbl[4];
    register s32 ret asm("$19");
    register s32 stop asm("$18");

    __builtin_memcpy(tbl, D_80010038, sizeof(tbl));
    if (D_8009509C == (stop = 0x80)) {
        return;
    }
    ret = func_80064894(1, 0);
    if (ret != 1) {
        goto fail;
    }
    if (D_800E01D0 == 0) {
        D_800E01B8 = D_800E0D40;
        func_80064CB4(&D_800E0388, 3);
        if (func_800617A4(&D_800E0388) != D_800E01B4) {
        fail:
            func_800648B4(0);
            func_80064B44(9, 0, 0);
            D_8009509C = stop;
        } else {
            func_80064CB4(D_800E01B8, 0x200);
            D_800E01C4 = *D_800E01B8++;
            D_800E01B0 = *D_800E01B8++;
            D_800E01BC = *D_800E01B8++;
            D_800E01A8 = *D_800E01B8++;
            D_800E01CD = ret;
            D_800E0368 = D_800E0370;
            D_800E01D0++;
            D_800E036C = D_800E01A8;
        }
    } else {
        ((void (*)(void))tbl[D_800E01BC >> 16])();
        if (D_800E01A8 == 0) {
            if ((D_800E01BC >> 16) == 0) {
                *D_8006E27C[D_800E01BC] = D_800E0368;
                D_800E0368 += D_800E036C;
            }
            STEP();
            if (D_800E01A8 == 0 && D_800E01C4 != 0) {
                STEP();
            }
        }
        D_800E01D0++;
        if (D_800E01C4 == 0) {
            func_800648B4(0);
            D_8009509C = 0;
            while (func_800648D4(9, 0, 0) == 0) {
            }
            D_8009509C = 2;
            D_800B91B8 = (M2C_UNK*)D_800E0368;
            D_8009B798 = D_800E0374;
        }
    }
}
