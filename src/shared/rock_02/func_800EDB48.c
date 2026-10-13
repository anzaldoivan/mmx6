#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002EE10(void*);
extern void (*D_800FAEDC[])(void*);

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EDB48(void* arg0) {
    if (W(arg0, 0x84) == 0 && UB(arg0, 0x70) == 0) {
        func_8002EE10(arg0);
    }
    D_800FAEDC[B(arg0, 4)](arg0);
}
