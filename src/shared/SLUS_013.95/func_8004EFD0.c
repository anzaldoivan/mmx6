#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_8004EFD0(struct X4_MainObj* self) {
    s8 state;

    state = S8(self, 6);
    if (state == 0) {
        F8(self, 0x7F) = 0x82;
        if (F8(self, 0x84) == 0) {
            if (F8(self, 0x7E) == 0) {
                if (F8(self, 0x82) == 0) {
                    func_800179A4(self, 1);
                } else {
                    func_800179A4(self, 0xC);
                }
            } else if (F8(self, 0x82) == 0) {
                func_800179A4(self, 6);
            } else {
                func_800179A4(self, 0xF);
            }
        } else if (F8(self, 0x82) == 0) {
            func_800179A4(self, 0x18);
        } else {
            func_800179A4(self, 0x1F);
        }
        F8(self, 6)++;
    } else if (state == 1) {
        if (--F8(self, 0x7F) == 0) {
            func_80016C48(2, 0x41, self);
            F8(self, 0x83) = state;
            F8(self, 0x7F) = 0x3C;
            F8(self, 6)++;
        }
    } else if (state == 2) {
        if (--F8(self, 0x7F) == 0) {
            F8(self, 0x83) = 0;
            F8(self, 6) = 0;
            F8(self, 5)++;
        }
    }
}
