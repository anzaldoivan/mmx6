#include "common.h"
#include "psyq/libgpu.h"

extern u16 D_800C456C[];
extern s32 D_800EA760[];

void func_800133A0();
void func_800139F4(s32);
s32 func_80016C48(s32, s32, void*);
void func_8001D218();
void func_8001D25C(void);
void func_800E9864(u8* arg0);
void func_800E9958(s32);

#define F38 (*(s8*)&arg0[0x38])

void func_800E9A50(u8* arg0) {
    s8 old;
    s8 t;

    old = F38;
    if (D_800C456C[2] & 0x8000) {
        F38 = 0;
    }
    if (D_800C456C[2] & 0x2000) {
        F38 = 1;
    }
    if (old != F38) {
        s32* p;
        func_80016C48(5, 0, 0);
        p = D_800EA760;
        p[0] = 0;
        p[1] = 0;
    } else if (old == 0) {
        func_800E9864(0);
    } else {
        func_800E9958(old);
    }
    if (F38 == 0) {
        arg0[0x5F] = 1;
        arg0[0x5E] = 1;
    } else {
        arg0[0x5F] = 0x10;
        arg0[0x5E] = 5;
    }
    if (D_800C456C[2] & 0x840) {
        arg0[1]++;
        func_800139F4(8);
        func_80016C48(5, 1, 0);
        t = F38;
        if (D_800EA760[t] == 0xB) {
            if (t == 0) {
                arg0[0x5F] = 8;
                arg0[0x5E] = 4;
                return;
            }
            arg0[0x5F] = 0x31;
        }
    } else if (D_800C456C[2] & 0x10) {
        SetDispMask(0);
        func_8001D218();
        func_8001D25C();
        func_800133A0();
    }
}
#undef F38
