#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003B114(s32);
extern void (*D_801EE3D0[])(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

M2C_UNK func_801EC4AC(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        F_S8(arg0, 0x8E) = 0;
        func_8003B114((s32)arg0);
        return;
    }
    D_801EE3D0[F_S8(arg0, 0x6)](arg0);
}
