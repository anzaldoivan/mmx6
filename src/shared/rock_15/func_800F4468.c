#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F3824(struct X4_MainObj*);
extern s8 D_800CCF5C;
extern s32 D_800F6F4C;
extern s32 D_800F6F5C;

void func_800F4468(void* arg0) {
    s8* p;

    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) == 0x10) {
        M2C_FIELD(arg0, s32**, 0x50) = &D_800F6F5C;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800F6F4C;
        M2C_FIELD(arg0, u16*, 0xE) += 0x10;
    }
    if (D_800CCF5C / 2 < p[0x5C]) {
        if (M2C_FIELD(arg0, s16*, 0x8C)++ < 0x5B) {
            return;
        }
    } else {
        if (M2C_FIELD(arg0, s16*, 0x8C)++ < 0x33) {
            return;
        }
    }
    M2C_FIELD(arg0, u8*, 7) = 0xA;
    func_800F3824(arg0);
    set_animation(arg0, 0xF);
    {
        // !FAKE: increment temp in the first return register
        register s32 x asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, u8*, 6) = x;
    }
}
