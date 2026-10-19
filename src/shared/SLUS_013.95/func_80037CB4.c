#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
void func_8003ADB4(void* arg0);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CCBC();

void func_80037CB4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD4) == 0) {
        ((void (*)())func_8003CCBC)();
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            do {
                func_8003ADB4(arg0);
            } while (0);
            M2C_FIELD(arg0, u8*, 0x84) = 0;
        } else {
            func_8003BA04(arg0, 0xB);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s8*, 0x67) = -1;
            M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x100);
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            do {
            } while (0);
            M2C_FIELD(arg0, u8*, 0x84) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x86) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x67) == 0) {
        func_80017A04(arg0);
    }
}
