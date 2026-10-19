#include "common.h"

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define PP(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F3154(void* arg0) {
    s32 t;

    UB(arg0, 0x47) = UB(PP(arg0, 0x80), 0x47);
    t = UH(arg0, 0x7C);
    do {
    } while (0);
    UB(arg0, 3) = 1;
    if (t & 1) {
        if (--SH(arg0, 0x7C) == 0) {
            UB(arg0, 3) = 0;
            UB(arg0, 4) = 5;
        }
    } else {
        if (--SH(arg0, 0x7C) == 0) {
            UB(arg0, 3) = 0;
            UB(arg0, 4) = 5;
        }
    }
}
