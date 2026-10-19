#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
void func_80017A04(struct X4_AnimatedObj*);
void func_8002D2B0(struct X4_MovingObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049D90(void*);

#define F818_B(p, o) (*(s8*)((u8*)(p) + (o)))
#define F818_UB(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801EF818(void* arg0) {
    if (func_8002CBFC(arg0, 0x10, 0x10) == 0) {
        F818_UB(arg0, 3) = 1;
        func_80017A04(arg0);
        func_8002D2B0(arg0);
        if (F818_B(arg0, 0x98) == 0) {
            if (F818_UB(arg0, 0x70) == 0 &&
                (func_8002EE10(arg0), F818_UB(arg0, 0x70) == 0)) {
                return;
            }
            func_80049D90(arg0);
        }
    }
    F818_UB(arg0, 3) = 0;
    F818_UB(arg0, 4) = 3;
}

#undef F818_B
#undef F818_UB
