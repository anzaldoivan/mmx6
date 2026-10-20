#include "common.h"
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);

void func_801ECCDC(void* arg0) {
    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[0x45] & 0x80) {
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}
