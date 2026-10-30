#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK end_dash(s32);
extern void (*D_801EE3C4[])(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

M2C_UNK func_801EC440(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        F_S8(arg0, 0x8E) = 0;
        end_dash((s32)arg0);
    } else {
        ((void (*)())func_80017A04)(arg0);
        D_801EE3C4[F_S8(arg0, 0x6)](arg0);
    }
}
