#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_801F2950(void* arg0) {
    // !FAKE: pin the incremented counter to the first return register
    register s32 temp_v0 asm("$2");

    func_80017A04((struct X4_AnimatedObj*)arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
    temp_v0 = F_U16(arg0, 0x8E) + 1;
    F_U16(arg0, 0x8E) = temp_v0;
    if ((F_S8(arg0, 0x46) == 0) || ((s16)temp_v0 >= 0xA)) {
        F_S8(arg0, 0x3) = 0;
        F_S8(arg0, 0x4) = 3;
    }
}
