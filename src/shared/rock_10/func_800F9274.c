#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_800F74D8(void* arg0, s16 arg1, s16 arg2, u8 arg3);
void func_800F765C(void* arg0, u8 arg1);
extern M2C_UNK D_80074E7C;

void func_800F9274(void* arg0) {
    s8 s = M2C_FIELD(arg0, s8*, 0x45);

    if (s == 2) {
        func_800F74D8(arg0, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE), 0x10);
    } else if (s == 3) {
        if (func_8002D2D4() & 1) {
            func_80016C48(2, 0x26, arg0);
        } else {
            func_80016C48(2, 0x27, arg0);
        }
        M2C_FIELD(arg0, u8*, 7) = 1;
        func_800F765C(arg0, 0x30);
        func_800F765C(arg0, 0x31);
        func_800F765C(arg0, 0x32);
        func_800F765C(arg0, 0x33);
    } else if (s == 1) {
        M2C_FIELD(arg0, void**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        func_800179A4(arg0, 0x11);
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        {
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
