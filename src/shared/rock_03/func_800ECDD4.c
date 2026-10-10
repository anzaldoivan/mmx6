#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj D_800970A0;
extern u8 D_800CCF38;
extern M2C_UNK D_800F76EC;
extern M2C_UNK D_800F76F0;
extern M2C_UNK D_800F76F4;
extern M2C_UNK D_800F76F8;
extern M2C_UNK D_800F76FC;

void func_800ECDD4(void* arg0) {
    s32 angle;
    s32 vel;
    register s32 t asm("$2");
    struct X4_PlayerObj* pl;
    s32 sel;

    M2C_FIELD(arg0, u8*, 0x16) = 5;
    sel = M2C_FIELD(arg0, s8*, 0x2);
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, s16*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) += 1;
    if (sel == 0) {
        u8 dir0;
        s32 x0;
        func_800179A4(arg0, 7);
        func_80016C48(2, 0x3E, arg0);
        dir0 = M2C_FIELD(arg0, u8*, 0x15);
        x0 = 0xFFFD0000;
        if (dir0 != 0) {
            x0 = 0x30000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = x0;
        x0 = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (dir0 != 0) {
            x0 += 0x10;
        } else {
            x0 -= 0x10;
        }
        M2C_FIELD(arg0, s16*, 0xA) = x0;
        x0 = 6;
        M2C_FIELD(arg0, u8*, 0x60) = x0;
        M2C_FIELD(arg0, void**, 0x68) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F76EC;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F76F0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, u8*, 0x5) = 0;
    } else if (sel == 1) {
        u8 dir1;
        s32 x1;
        s32 nx1;
        s32 px;
        s32 m;
        func_800179A4(arg0, 7);
        func_80016C48(2, 0x3E, arg0);
        pl = &D_800970A0;
        px = M2C_FIELD(pl, s16*, 0xA);
        angle =
            func_80065B74(M2C_FIELD(pl, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                          px - M2C_FIELD(arg0, s16*, 0xA));
        t = func_80065A14(angle);
        nx1 = t * 16;
        M2C_FIELD(arg0, s32*, 0x20) = (t << 6) + nx1;
        t = -func_80065944(angle);
        nx1 = t << 4;
        t = (t << 6) + nx1;
        M2C_FIELD(arg0, s32*, 0x24) = t;
        {
            register s32 d asm("$2");
            d = M2C_FIELD(arg0, u8*, 0x15);
            x1 = M2C_FIELD(arg0, s16*, 0xA);
            if (d == 0) {
                d = x1 - 0x10;
            } else {
                d = x1 + 0x10;
            }
            M2C_FIELD(arg0, s16*, 0xA) = d;
            d = 6;
            M2C_FIELD(arg0, u8*, 0x60) = d;
        }
        M2C_FIELD(arg0, void**, 0x50) = &D_800F76EC;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F76F0;
        M2C_FIELD(arg0, void**, 0x68) = 0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        {
            register s32 st asm("$3") = 1;
            M2C_FIELD(arg0, u8*, 0x5) = st;
        }
    } else if (sel == 2) {
        u8 dir2;
        s32 x2;
        s32 nx2;
        func_800179A4(arg0, 6);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        nx2 = 0xFFFE8000;
        M2C_FIELD(arg0, s32*, 0x24) = nx2;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
        }
        nx2 = M2C_FIELD(arg0, u8*, 0x15);
        x2 = M2C_FIELD(arg0, s16*, 0xA);
        if (nx2 == 0) {
            nx2 = x2 - 0x20;
        } else {
            nx2 = x2 + 0x20;
        }
        M2C_FIELD(arg0, s16*, 0xA) = nx2;
        M2C_FIELD(arg0, u8*, 0x5C) = 3;
        M2C_FIELD(arg0, u8*, 0x60) = 3;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F76FC;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F76F8;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F76F4;
        M2C_FIELD(arg0, void**, 0x58) = D_800741FC;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x10;
    }
}
