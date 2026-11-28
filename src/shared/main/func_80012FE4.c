#include "common.h"
#include "psyq/libetc.h"

#define SCRATCH74 (*(s32*)0x1F800074)

void func_80012FE4(void) {
    SCRATCH74 = VSync(1);
}
