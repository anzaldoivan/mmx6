#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
void func_8002D2B0(struct X4_MovingObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801EE684(void* arg0) {
    if (func_8002CBFC(arg0, 0x20, 0x14) == 0 && B(arg0, 0x98) == 0) {
        func_80017A04(arg0);
        func_8002D2B0(arg0);
        func_8002CCB0(arg0, 0x20, 0x14);
        {
            // !FAKE: first flag read lands in the first return register
            register s32 f asm("$2") = UB(arg0, 0x70);
            if (f == 0 && (func_8002EE10(arg0), UB(arg0, 0x70) == 0)) {
                return;
            }
        }
        func_800383F8(arg0);
    }
    UB(arg0, 3) = 0;
    UB(arg0, 4) = 3;
    W(arg0, 0x50) = 0;
    W(arg0, 0x68) = 0;
}
