#include "common.h"
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);

void func_801F3640(u8* arg0) {
    func_80017A04(ANIMATED_OBJECT(arg0));
    if (*(s8*)(arg0 + 0x46) == 0) {
        arg0[4] = 3;
    }
}
