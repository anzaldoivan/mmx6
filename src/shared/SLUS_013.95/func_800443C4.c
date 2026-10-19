#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);     /* extern */
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2); /* extern */
M2C_UNK func_8002D2B0(void*);                   /* extern */
M2C_UNK func_8002EE10(void*);                   /* extern */
void func_800383F8(void*);                      /* extern */
void func_80044590(void* arg0);                 /* extern */
extern s8 D_800970A2;

void func_800443C4(void* arg0) {
    s8 temp_s0;

    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x98) != 0) {
            func_80044590(arg0);
            return;
        }
        func_80017A04(arg0);
        func_8002D2B0(arg0);
        {
            // !FAKE: first flag read lands in the first return register
            register s32 flag asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
            if ((flag != 0) ||
                (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
                if (D_800970A2 != 0) {
                    temp_s0 = M2C_FIELD(arg0, s8*, 1);
                    M2C_FIELD(arg0, s8*, 1) = 0x3A;
                    func_800383F8(arg0);
                    M2C_FIELD(arg0, s8*, 1) = temp_s0;
                } else {
                    func_800383F8(arg0);
                }
                func_80044590(arg0);
            }
        }
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    func_80044590(arg0);
}
