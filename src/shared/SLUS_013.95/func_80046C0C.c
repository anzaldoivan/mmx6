#include "common.h"
#include "mmx6/x4.h"

extern u8 D_8006D5F7;
extern u8 D_8007360C[];
s32 func_8002CB50(struct X4_BaseObj*);

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_80046C0C(struct X4_MainObj* arg0) {
    if (D_8006D5F7 & D_8007360C[arg0->unk2]) {
        F8(arg0, 0x47) = 0xA;
    } else {
        F8(arg0, 0x47) = 0xB;
    }
    func_8002CB50((struct X4_BaseObj*)arg0);
}
