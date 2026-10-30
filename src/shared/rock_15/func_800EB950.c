#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002EE10();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800F61F8[];

void func_800EB950(void* arg0) {
    s32 t;
    s32 v;
    s16 x;
    s32 y;
    s32 c;
    s32 b;
    s32 a;

    func_80017A04();
    ((void (*)(void*))func_8002D230)(arg0);
    b = M2C_FIELD(arg0, s32*, 0x84) - 1;
    M2C_FIELD(arg0, s32*, 0x84) = b;
    if (b == 0 && M2C_FIELD(arg0, u8*, 0x17) != 4) {
        t = M2C_FIELD(arg0, u8*, 0x15) & 0x40;
        x = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s32*, 0x20) = D_800F61F8[t != 0];
        M2C_FIELD(arg0, s32*, 0x28) = 0x600;
        if (t != 0) {
            M2C_FIELD(arg0, s16*, 0xA) = x + 0x10;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = x - 0x10;
        }
        set_animation(arg0, 4);
    }
    v = M2C_FIELD(arg0, s32*, 0x20);
    if ((v < 0 ? -v : v) > 0x30000) {
        M2C_FIELD(arg0, s32*, 0x28) = 0;
    }
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        goto block_17;
    }
    ((void (*)(void*))func_80030ECC)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
        func_80049E50(arg0);
        b = 2;
        goto block_18;
    }
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
block_17:
    v = 1;
    M2C_FIELD(arg0, s32*, 0x8C) = v;
    b = M2C_FIELD(arg0, u8*, 4) + 1;
block_18:
    M2C_FIELD(arg0, u8*, 4) = b;
}
