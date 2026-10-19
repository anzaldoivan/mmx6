#include "common.h"

extern s32 D_80078454[];

void func_8004D008(u8* arg0) {
    ((void (**)(u8*))D_80078454)[(s8)arg0[2]](arg0);
    arg0[3] = 1;
}
