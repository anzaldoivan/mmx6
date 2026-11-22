#include "common.h"
#define M2C_UNK s32

#define F7BC_W(o) (*(s32*)((u8*)arg0 + (o)))
#define F7BC_UB(o) (*(u8*)((u8*)arg0 + (o)))
#define F7BC_SET(v)                                                            \
    { *((u8*)arg0 + arg1 + 0x94) = (v); }

void func_8003F7BC(void* arg0, M2C_UNK arg1, M2C_UNK arg2) {
    u8 t;

    if (F7BC_W(0x144) != 6) {
        if (!(F7BC_W(0xEC) & 0x80000)) {
            s8* b = (s8*)arg0 + 0x9B;
            s8 v = b[arg1];
            if (v == 0) {
                return;
            }
            if (v == 1) {
                F7BC_SET(9);
                return;
            }
        }
        t = F7BC_UB(0xE7);
        if (t == 4) {
            F7BC_SET(0x14);
            return;
        }
        if (t == 1) {
            F7BC_SET(0x13);
            return;
        }
        if (t == 3) {
            F7BC_SET(0x2B);
            return;
        }
    }
    F7BC_SET(0x12);
}

#undef F7BC_W
#undef F7BC_UB
#undef F7BC_SET
