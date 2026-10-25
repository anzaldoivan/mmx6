#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80030ECC(void*, s16);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s32 D_8007573C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800970AA;
extern u8 D_800CCF5F;
extern u8 D_800E99AC[];
extern s32 D_800F76A4[];
extern s32 D_800F76A8[];
extern s32 D_800F77D8;
extern s32 D_800F77DC;
extern void* D_800F7800;
extern s8 D_800F7806;
#define D_1F800020 (*(u8**)SP(0x20))
#define func_80030ECC (*(void (*)(void*)) & func_80030ECC)

void func_800F14B8(void* arg0) {
    u8 tbl[4];
    void* child;
    void* q;
    s32 i;
    s16 angle;
    s32 a;
    s32 b;
    s32 c;
    u8* base;

    __builtin_memcpy(tbl, D_800E99AC, 4);
    ((void (*)(void*))func_8002D230)(arg0);
    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    M2C_FIELD(arg0, s8*, 7) = func_80031474(arg0);
    if (M2C_FIELD(arg0, s8*, 7) < 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 1;
        M2C_FIELD(arg0, s8*, 5) = 10;
    } else {
        M2C_FIELD(arg0, u32*, 0x98) += D_800F7806;
        if ((M2C_FIELD(arg0, u32*, 0x98) >= 0x10) &&
            (M2C_FIELD(arg0, s8*, 5) < 11)) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, void**, 0x50) = 0;
            M2C_FIELD(arg0, void**, 0x54) = 0;
            M2C_FIELD(arg0, s16*, 0x88) = 0x3C;
            M2C_FIELD(arg0, s8*, 5) = 0x14;
        }
    }
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 12) {
            M2C_FIELD(arg0, void**, 0x50) = D_800F76A4;
            M2C_FIELD(arg0, void**, 0x54) = D_800F76A8;
            if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            {
                s32 px = g_Player.x_pos.i.hi;
                s32 py;
                M2C_FIELD(arg0, s32*, 0x90) = px;
                py = g_Player.y_pos.i.hi;
                M2C_FIELD(arg0, s32*, 0x94) = py;
                angle = func_80065B74(py - M2C_FIELD(arg0, s16*, 0xE),
                                      px - M2C_FIELD(arg0, s16*, 0xA));
            }
            M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(angle) * 48;
            M2C_FIELD(arg0, s32*, 0x24) = -func_80065944(angle) * 48;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(arg0, u32*, 0x90)) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, u32*, 0x90);
            }
        } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xA) > M2C_FIELD(arg0, u32*, 0x90)) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, u32*, 0x90);
            }
        }
        if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xE) > M2C_FIELD(arg0, u32*, 0x94)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, u32*, 0x94);
            }
        } else if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xE) < M2C_FIELD(arg0, u32*, 0x94)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, u32*, 0x94);
            }
        }
        if ((M2C_FIELD(arg0, s32*, 0x20) == 0) &&
            (M2C_FIELD(arg0, s32*, 0x24) == 0)) {
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(child, u8*, 1) = 0x1A;
                M2C_FIELD(child, u8*, 2) = 0xB;
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
            M2C_FIELD(arg0, s32**, 0x58) = D_8007573C;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s32*, 0x90) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 2:
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 60) {
            {
                void* p = D_800F7800;
                M2C_FIELD(arg0, u16*, 0x40) = 0x140;
                a = func_8002A47C(M2C_FIELD(p, s8*, 1));
            }
            b = func_8002A47C(M2C_FIELD(D_800F7800, s8*, 1));
            c = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            q = D_800F7800;
            M2C_FIELD(arg0, u16*, 0x42) = c;
            b = func_8002A47C(M2C_FIELD(q, s8*, 1));
            base = D_1F800020;
            M2C_FIELD(arg0, u8**, 0x3C) = base + ((s32*)base)[b];
            ((void (*)(void*, s32))func_800179A4)(arg0, 0xF);
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s32*, 0x90) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 3:
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 180) {
            if (M2C_FIELD(arg0, u32*, 0x90) < tbl[D_800CCF5F]) {
                child = func_8002C458();
                if (child != 0) {
                    M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                    M2C_FIELD(child, u8*, 1) = 0x1A;
                    M2C_FIELD(child, u8*, 2) = 0xD;
                    M2C_FIELD(child, void**, 0x7C) = arg0;
                }
                M2C_FIELD(arg0, s32*, 0x90)++;
            }
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
        }
        break;
    case 10:
        if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
            ((void (*)(s32, s32, s32))func_80016C48)(2, 0x8B, (s32)arg0);
            ((void (*)(void*))func_80049E50)(arg0);
            for (i = 0; i < 6; i++) {
                child = func_8002C458();
                if (child != 0) {
                    M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                    M2C_FIELD(child, u8*, 1) = 0x1A;
                    M2C_FIELD(child, u8*, 2) = i + 5;
                    M2C_FIELD(child, u8*, 7) = M2C_FIELD(arg0, u8*, 2);
                    M2C_FIELD(child, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
                    M2C_FIELD(child, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
                    M2C_FIELD(child, void**, 0x7C) = arg0;
                }
            }
            M2C_FIELD(arg0, u8*, 4)++;
        }
        break;
    case 20:
        if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
            M2C_FIELD(arg0, u8*, 3) = 0;
            M2C_FIELD(arg0, u8*, 4)++;
        } else if (M2C_FIELD(arg0, s16*, 0x88) & 1) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        } else {
            M2C_FIELD(arg0, u8*, 3) = 0;
        }
        break;
    }
    if ((M2C_FIELD(arg0, s8*, 5) != 10) || (M2C_FIELD(arg0, s32*, 0x8C) & 1)) {
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
    }
    ((void (*)(void*))func_80017A04)(arg0);
}
#undef func_80030ECC
#undef g_Player
