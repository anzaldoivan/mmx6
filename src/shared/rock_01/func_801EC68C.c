#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80039C40(void*);
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);
M2C_UNK func_8003CCBC();
void func_8003CD00(void* arg0);
M2C_UNK func_801ECD54(void*, M2C_UNK);

void func_801EC68C(void* arg0) {
    func_8003CCBC(arg0);
    if (M2C_FIELD(arg0, s8*, 0x6) == 0) {
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    } else {
        func_80017A04(arg0);
        func_801ECD54(arg0, 0x25);
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        if (func_80039C40(arg0) != 0) {
            return;
        }
        M2C_FIELD(arg0, u8*, 0x8E) = 1;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        ((void (*)())func_8003BB94)(arg0, 0x51, 2);
        M2C_FIELD(arg0, u8*, 0x5) = 0x1A;
        M2C_FIELD(arg0, u8*, 0x6) = 1;
    }
    func_8003CD00(arg0);
}
