#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002EE10(void*);

extern void (*D_80100BAC[])(void*);
extern void (*D_80100BB8[])(void*);
extern void (*D_80100BC4[])(void*);
extern void (*D_80100BD0[])(void*);
extern void (*D_80100BDC[])(void*);
extern void (*D_80100BE8[])(void*);

void func_800FE398(u8* self) {
    if (*(s32*)(self + 0x84) == 0 && self[0x70] == 0) {
        func_8002EE10(self);
    }
    self[3] = 0;
    switch ((s8)self[2]) {
    case 0:
    case 1:
        D_80100BAC[(s8)self[4]](self);
        break;
    case 2:
        D_80100BB8[(s8)self[4]](self);
        break;
    case 3:
        D_80100BC4[(s8)self[4]](self);
        break;
    case 4:
        D_80100BD0[(s8)self[4]](self);
        break;
    case 5:
        D_80100BDC[(s8)self[4]](self);
        break;
    case 6:
        D_80100BE8[(s8)self[4]](self);
        break;
    }
}
