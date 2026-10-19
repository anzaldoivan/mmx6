#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002B36C(M2C_UNK);
void* func_8002C530();
extern s8 D_80097424;

void func_800E9D54(u8* arg0) {
    s32 i;
    u8* p;
    u8* a;
    u8* self;

    self = arg0;
    if (D_80097424 != 0) {
        return;
    }
    a = arg0;
    i = 0;
    do {
        p = func_8002C530(a);
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x1C;
            p[2] = i;
        }
        i++;
        a = 0;
    } while (i < 2);
    self[2] = 0;
    self[1]++;
    func_8002B36C(0);
    *(s16*)(self + 4) = 2;
}
