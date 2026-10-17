#include "common.h"

#define M2C_UNK s32

void func_8004EC30(u8*);
#define func_8004EC30 ((void (*)())func_8004EC30)

void func_8004F880(void) {
    func_8004EC30();
}
#undef func_8004EC30
