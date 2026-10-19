#include "common.h"
#include "mmx6/x4.h"

extern s8 D_800950A0[];

s32 func_8002DCF4(void*, void*);
void func_800312DC(struct X4_MainObj* arg0, struct X4_MainObj* arg1, s16* arg2,
                   s16* arg3);
s32 func_800315CC(void* arg0, void* arg1);

s32 func_80032B34(struct X4_PlayerObj* arg0) {
    s8* p;
    s32 r;

    for (p = D_800950A0; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (p[0] == 0) {
            continue;
        }
        if (func_8002DCF4(p, arg0) == 0) {
            continue;
        }
        func_800312DC((struct X4_MainObj*)arg0, (struct X4_MainObj*)p,
                      (s16*)(p + 0x80), (s16*)(p + 0x82));
        r = func_800315CC(arg0, p);
        if (r == 0x7E) {
            return 0;
        }
        if (r != 0) {
            return r;
        }
    }
    arg0->unk65 = 0;
    return 0;
}
