#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D5D0(void*);
M2C_UNK func_8003B114(s32);
M2C_UNK func_8003C4EC();
M2C_UNK func_801EC678();
extern s8 D_800CCEEC;

void func_801EC5F4(void* arg0) {
    s32 var_v0;
    u8 temp_v1;

    var_v0 = func_801EC678() != 0;
    temp_v1 = M2C_FIELD(arg0, u8*, 0xE1);
    if (temp_v1 == 0) {
        var_v0 = 1;
    }
    if (var_v0 != 0) {
        if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
            M2C_FIELD(arg0, s8*, 0x7A) = 0;
        }
        M2C_FIELD(arg0, s8*, 0xE0) = 0;
        D_800CCEEC = 0;
        func_8003C4EC(arg0);
        func_8003B114((s32)arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 0xE1) = temp_v1 - 1;
    func_8002D5D0(arg0);
}
