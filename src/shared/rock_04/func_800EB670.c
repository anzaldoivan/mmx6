#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002EE10(void*);

extern void (*D_800F6ACC[])(void*);
extern void (*D_800F6AD8[])(void*);
extern void (*D_800F6AE4[])(void*);

void func_800EB670(u8* self) {
    if (*(s32*)(self + 0x84) == 0 && self[0x70] == 0) {
        func_8002EE10(self);
    }
    self[3] = 0;
    switch ((s8)self[2]) {
    case 0:
        D_800F6ACC[(s8)self[4]](self);
        break;
    case 1:
        D_800F6AD8[(s8)self[4]](self);
        break;
    case 2:
        D_800F6AE4[(s8)self[4]](self);
        break;
    }
}
