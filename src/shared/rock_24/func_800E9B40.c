#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CDF0();
void func_8003F000(void* arg0);
M2C_UNK func_8003F3DC(void*);
extern s8 D_800CCEDF;

void func_800E9B40(void* arg0) {
    s8 state = M2C_FIELD(arg0, s8*, 6);

    if (state == 0) {
        func_8003BA04(arg0, 0x51);
        func_8003CDF0(arg0);
        func_8003F3DC(arg0);
        func_8003F000(arg0);
        // !FAKE: shared counter increment block
        goto inc;
    }
    if (state == 1) {
        ((void (*)())func_80017A04)(arg0);
        if (D_800CCEDF != 0) {
        inc:
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    } else {
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 5) = 0;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
