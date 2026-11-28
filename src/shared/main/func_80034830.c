#include "common.h"

extern u8 D_800CF810[];
extern void (*D_80073998[])(u8*);

void func_80034830(void) {
    u8* slot = D_800CF810;

    D_80073998[(s8)slot[4]](slot);
}
