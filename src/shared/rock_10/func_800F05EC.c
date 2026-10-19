#include "common.h"

s32 func_800F09A0();
extern s16 D_800970AA;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F05EC(void* arg0) {
    s32 var_v0;

    if ((D_800970AA - H(arg0, 0xA)) < 0xBC) {
        var_v0 = func_800F09A0(arg0);
        if (var_v0 == 0) {
            var_v0 = 5;
        } else {
            var_v0 = 4;
        }
        UB(arg0, 5) = var_v0;
        UB(arg0, 6) = 0;
    }
}
