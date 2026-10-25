#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
extern void (*D_801F3AE0[])(void*);

void func_801F2758(void* arg0) {
    s8* p = (s8*)&g_Player;
    s32 var_a1;

    var_a1 = p[0xD3] != 0;
    if (p[0xD4] != 0) {
        var_a1 = 1;
    }
    if (p[0x93] != 8) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
    D_801F3AE0[M2C_FIELD(arg0, s8*, 4)](arg0);
}
