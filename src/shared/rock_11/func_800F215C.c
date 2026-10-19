#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009716C;
extern void (*D_800FCBE8[])(void*);

void func_800F215C(void* arg0) {
    if (D_8009716C == 0) {
        D_800FCBE8[M2C_FIELD(arg0, s8*, 0x4)](arg0);
        if (M2C_FIELD(arg0, s8*, 0x45) == -1) {
            M2C_FIELD(arg0, s8*, 0x3) = 0;
        }
    }
}
