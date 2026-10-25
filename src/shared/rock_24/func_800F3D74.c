#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80030ECC(void*, s16);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800970AA;
extern s32 D_800F76C0[];
extern s32 D_800F76C4[];
extern s32 D_800F77D8;
extern s32 D_800F77DC;
extern void* D_800F7800;
#define D_1F800020 (*(u8**)SP(0x20))

void func_800F3D74(void* arg0) {
    s32 a;
    s32 b;
    // !FAKE: depin: dropping it breaks the match (189/194)
    register s32 t asm("$3");
    u8* base;
    u8 st;
    s32 c;
    void* q;

    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    if ((func_80031474(arg0) < 0) ||
        (((s32(*)(void*))func_80030ECC)(arg0) != 0)) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x1E) {
            {
                void* p = D_800F7800;
                M2C_FIELD(arg0, u16*, 0x40) = 0x540;
                a = func_8002A47C(M2C_FIELD(p, s8*, 1));
            }
            b = func_8002A47C(M2C_FIELD(D_800F7800, s8*, 1));
            c = (((a + 1) * 4 + 0x20) % 16) | (((b + 9) / 4 + 0x1E0) << 6);
            q = D_800F7800;
            M2C_FIELD(arg0, u16*, 0x42) = c;
            b = func_8002A47C(M2C_FIELD(q, s8*, 1));
            base = D_1F800020;
            M2C_FIELD(arg0, u8**, 0x3C) = base + ((s32*)base)[b + 1];
            func_800179A4(arg0, 0x20);
            {
                // !FAKE: depin: dropping it breaks the match (190/194)
                register void* t0 asm("$2") = D_800F76C0;
                // !FAKE: depin: dropping it breaks the match (188/194)
                register void* t1 asm("$3") = D_800F76C4;
                M2C_FIELD(arg0, void**, 0x50) = t0;
                M2C_FIELD(arg0, void**, 0x54) = t1;
            }
            if (M2C_FIELD(arg0, s16*, 0xA) < D_800970AA) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
                M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
            }
            M2C_FIELD(arg0, s8*, 6) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s16*, 0xE) < g_Player.y_pos.i.hi) {
            M2C_FIELD(arg0, s16*, 0xE)++;
        } else if (g_Player.y_pos.i.hi < M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE)--;
        }
        st = M2C_FIELD(arg0, u8*, 6);
        switch (M2C_FIELD(arg0, s8*, 6)) {
        case 0:
            if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
                t = M2C_FIELD(arg0, s16*, 0xA);
                t = t < g_Player.x_pos.i.hi;
            } else {
                t = M2C_FIELD(arg0, s16*, 0xA) > g_Player.x_pos.i.hi;
            }
            if (t != 0) {
                M2C_FIELD(arg0, s32*, 0x8C) = 0;
                M2C_FIELD(arg0, u8*, 6) = st + 1;
            }
            break;
        case 1:
            if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x1E) {
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    M2C_FIELD(arg0, u8*, 0x15) = 0;
                } else {
                    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                }
                M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
                M2C_FIELD(arg0, u8*, 6)--;
            }
            break;
        }
        break;
    }
    if ((M2C_FIELD(arg0, s8*, 5) > 0) || (M2C_FIELD(arg0, s32*, 0x8C) & 1)) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}
#undef g_Player
