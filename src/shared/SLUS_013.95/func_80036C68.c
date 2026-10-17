#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CFB0(void* arg);
M2C_UNK func_8003AFF4(s32);
void func_8003D394(void* arg0);
s32 func_8003E174(void*);
M2C_UNK func_8003F508(void*, M2C_UNK);

void func_80036C68(void* arg0) {
    s32 var_a1;
    s32 var_v0;
    u8 temp_a0;
    u8 temp_v0;
    s32 t4;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        ((void (*)())func_8003AFF4)();
        return;
    }
    if (func_8003E174(arg0) == 0) {
        temp_a0 = M2C_FIELD(arg0, u8*, 0x89);
        t4 = temp_a0 & 4;
        var_a1 = t4 != 0;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_v0 = temp_a0 & 2;
        } else {
            var_v0 = temp_a0 & 1;
        }
        if (var_v0 != 0) {
            var_a1 = 1;
        }
        if (var_a1 != 0) {
            func_8003AFF4((s32)arg0);
            return;
        }
        ((void (*)())func_80017A04)(arg0);
        func_8002CFB0(arg0);
        func_8003D394(arg0);
        if (--M2C_FIELD(arg0, s8*, 0x8A) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            return;
        }
        func_8003F508(arg0, 0xE);
    }
}
