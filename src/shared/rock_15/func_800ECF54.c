#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
void func_800EF080(void* arg0);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007591C;
extern s8 D_8009711A;
extern s8 D_800CCF5C;
extern void (*D_800F6680[])(void*);

void func_800ECF54(void* arg0) {
    s32 r;
    u16 t;

    func_80017A04();
    {
        s32 i = M2C_FIELD(arg0, s8*, 5) * 4;
        (*(void (**)(void*))((s8*)D_800F6680 + i))(arg0);
    }
    func_800EF080(arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            D_8009711A = 1;
            M2C_FIELD(arg0, s8*, 4) = 2;
            M2C_FIELD(arg0, s8*, 5) = 0;
            return;
        }
        func_80049E50(arg0);
        M2C_FIELD(arg0, s8*, 4) = 4;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if ((u32)(r - 0x19) < 2) {
            M2C_FIELD(arg0, s16*, 0x86) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x86) = 0x1E;
        }
        if (r == 5 || r == 0xE || r == 0x24 ||
            ((D_800CCF5C - M2C_FIELD(arg0, s8*, 0x5C)) % 6 == 0 &&
             !(random_byte() & 3))) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, s16*, 0x86) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 3;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
    }
    t = M2C_FIELD(arg0, u16*, 0x86);
    if (M2C_FIELD(arg0, s16*, 0x86) != 0) {
        M2C_FIELD(arg0, s16*, 0x86) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x86) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007591C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}
