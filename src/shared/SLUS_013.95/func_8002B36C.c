#include "common.h"

extern s32 D_80090C90[][16];
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_8002B36C(s32 arg0) {
    s32 i;
    s32 v;
    s32 t;

    v = -1;
    t = arg0 * 2;
    *(s16*)((u8*)&D_80090D5C + t) = 0;
    *(s16*)((u8*)&D_80097430 + t) = 0;
    *(s16*)((u8*)&D_800CF854 + t) = 0;
    for (i = 15; i >= 0; i--) {
        D_80090C90[arg0][i] = v;
    }
}
