#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002EE10(void*);
extern s32 D_800FCA84;

void func_800FC7D8(void* arg0) {
    s8 s;

    if (M2C_FIELD(arg0, s32*, 0x84) == 0 && M2C_FIELD(arg0, u8*, 0x70) == 0) {
        func_8002EE10(arg0);
    }
    s = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 3) = 0;
    switch (s) {
    case 0 ... 3:
        ((void (**)(void*))((u8*)&D_800FCA84 + 0x3AC))[M2C_FIELD(arg0, s8*, 4)](
            arg0);
        break;
    case 4:
        ((void (**)(void*))((u8*)&D_800FCA84 + 0x3B8))[M2C_FIELD(arg0, s8*, 4)](
            arg0);
        break;
    }
}
