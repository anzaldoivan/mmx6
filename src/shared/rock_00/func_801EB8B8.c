#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_80039984(void*);
s32 func_8003A3DC(void*);
M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003B054(void*);
extern void (*D_801F3730[])(s8*);

void func_801EB8B8(s8* p) {
    if (((u8*)p)[0x89] & 8) {
        func_8003B054(p);
        return;
    }
    if (p[0xD3] != 0) {
        func_8003AFF4((s32)p);
        return;
    }
    if ((func_80039984(p) == 0) && (func_8003A3DC(p) == 0)) {
        func_80017A04((struct X4_AnimatedObj*)p);
        D_801F3730[p[6]](p);
    }
}
