#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s8 func_80014D50();
X4_CdlCB func_800648B4(X4_CdlCB func);
extern u16 D_8006E2EC[][2];
extern u8 D_8008EC08;
extern u8 D_8009509C;
extern u16 D_800CF988[];
extern u16 D_800CF98A[];
#define X_ D_800CF988[0]
#define Y_ D_800CF98A[0]
extern u16 D_800CF98C;
extern union X4_CdSectorBuffer D_800CF998;
extern u8 D_800DF999;
extern u8* D_800E01AC;
extern u32 D_800E01BC;
extern u8 D_800E01CD;
extern u16 D_800E01D4;
extern u16 D_800E01D6;
extern struct X4_CdCompletionSlot D_800E01E8[16];

void func_8001574C(void) {
    u16 t;
    u16* p;

    D_800E01D6++;
    if (D_800E01D6 - D_800E01D4 >= 0x20) {
        goto fail;
    }
    if (D_800E01CD != 0) {
        D_800E01CD = 0;
        p = D_8006E2EC[(u8)D_800E01BC];
        X_ = p[0];
        t = p[1];
        Y_ = t;
        D_800CF98C = t & 0x100;
    }
    D_800E01AC = D_800CF998.sectors[D_800DF999];
    if (func_80014D50() == -1) {
    fail:
        func_800648B4(0);
        CdControlB(9, 0, 0);
        D_8009509C = 0x80;
        return;
    }
    D_8008EC08 = 1;
    D_800E01E8[D_800DF999].pending = 1;
    D_800E01E8[D_800DF999].callback = 1;
    D_800E01E8[D_800DF999].callback_arg = (X_ << 16) | Y_;
    D_800DF999++;
    if (D_800DF999 == 0x20) {
        D_800DF999 = 0;
    }
    switch ((D_800E01BC & 0xFF00) >> 8) {
    case 0:
        if (Y_ == D_800CF98C + 0xF0) {
            X_ += 0x40;
            Y_ = D_800CF98C;
        } else {
            Y_ += 0x10;
        }
        break;
    case 2:
        if (Y_ == 0xF0) {
            Y_ = 0xB0;
            X_ += 0x40;
        } else {
            Y_ += 0x10;
        }
        break;
    case 3:
        if (Y_ == D_800CF98C + 0x10) {
            X_ -= 0x40;
            Y_ = D_800CF98C + 0xA0;
        } else {
            Y_ -= 0x10;
        }
        break;
    case 1:
    case 4:
        if (Y_ == D_800CF98C + 0xA0) {
            Y_ = 0x10;
            X_ += 0x40;
        } else {
            Y_ += 0x10;
        }
        break;
    case 5:
        if (Y_ == D_800CF98C) {
            Y_ = D_800CF98C + 0xF0;
            X_ -= 0x40;
        } else {
            Y_ -= 0x10;
        }
        break;
    case 6:
        X_ += 0x40;
        Y_ = D_800CF98C;
        break;
    }
}
#undef X_
#undef Y_
