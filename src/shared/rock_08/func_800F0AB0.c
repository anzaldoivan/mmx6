#include "common.h"
#define M2C_UNK s32

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_800179A4(void*, s32);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
s32 func_8002D2D4();
extern u8 D_800CCF5F;
extern s16 D_800F6AF8;

void func_800F0AB0(void* self) {
    u8 v;
    register s32 t asm("$2");

    func_80017A04();
    func_8002D2B0((s32)self);
    t = OW(self, 0x20);
    if (t > 0) {
        if (D_800F6AF8 + 0x680 < OH(self, 0xA)) {
            v = OUB(self, 0x47);
            if (v != 4) {
                if (v != 5) {
                    OUB(self, 0x89) = D_800CCF5F + 1;
                    if (!(func_8002D2D4() & 1)) {
                        func_80016C48(2, 0x27, self);
                    } else {
                        func_80016C48(2, 0x28, self);
                    }
                    func_800179A4(self, 3);
                    t = OUB(self, 6) + 1;
                    OUB(self, 6) = t;
                }
            }
        }
    } else {
        if (OH(self, 0xA) < D_800F6AF8 + 0x780) {
            v = OUB(self, 0x47);
            if (v != 4) {
                if (v != 5) {
                    OUB(self, 0x89) = D_800CCF5F + 1;
                    if (!(func_8002D2D4() & 1)) {
                        func_80016C48(2, 0x27, self);
                    } else {
                        func_80016C48(2, 0x28, self);
                    }
                    func_800179A4(self, 3);
                    t = OUB(self, 6) + 1;
                    OUB(self, 6) = t;
                }
            }
        }
    }
}
