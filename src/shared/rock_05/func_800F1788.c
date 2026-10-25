#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                        /* extern */
M2C_UNK func_8003D330();                        /* extern */
extern s8 D_80097240;
extern s8 D_800CCF5C;
extern s32 D_800F4148;
extern u8 D_800F448C;

void func_800F1788(void* arg0) {
    s8 state;

    func_80017A04();
    state = M2C_FIELD(arg0, s8*, 0x45);
    if (state != 0) {
        if (state == 2) {
            func_80016C48(2, 0xA, arg0);
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_80016C48(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7C) = 2;
        }
        if ((s8)++M2C_FIELD(arg0, u8*, 0x5C) == D_800CCF5C) {
            // !FAKE: depin: dropping it breaks the match (33/50)
            register s32 v asm("$4") = D_800F448C;
            D_80097240 = v;
            func_8003D330(v);
            M2C_FIELD(arg0, s32**, 0x68) = &D_800F4148;
            M2C_FIELD(arg0, u8*, 6) = 0;
            M2C_FIELD(arg0, u8*, 5) = 3;
        }
    }
}
