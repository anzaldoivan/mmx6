#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_800911A8[];
void func_80020AA8(struct X4_AnimatedObj* arg0);

M2C_UNK func_80020D74(void) {
    u8* p = D_800911A8;

    func_80020AA8((struct X4_AnimatedObj*)p);
    p += 0x50;
    func_80020AA8((struct X4_AnimatedObj*)p);
    p += 0x50;
    if (*(s8*)p != 0) {
        func_80020AA8((struct X4_AnimatedObj*)p);
    }
}
