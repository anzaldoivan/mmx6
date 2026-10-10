#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC();
s32 func_80031474(void*);
extern void (*D_800FCDE4[])(void*);

#define G(type, off) (*(type*)((u8*)self + (off)))
#define P(type, off) (*(type*)((u8*)p + (off)))

void func_800F5990(void* self) {
    void* p = G(void*, 0x80);

    if (P(s8, 4) != 1 || P(s8, 7) == 0) {
        G(s8, 4) = 7;
        G(s8, 3) = 0;
        return;
    }
    G(s32, 0x18) = G(s32, 0x8);
    G(s32, 0x1C) = G(s32, 0xC);
    switch (G(s8, 2)) {
    case 16:
        G(u16, 0xA) = P(u16, 0xA);
        G(u16, 0xE) = P(u16, 0xE) - 0x26;
        break;
    case 17:
        G(u16, 0xA) = P(u16, 0xA) - 0x26;
        G(u16, 0xE) = P(u16, 0xE);
        break;
    case 18:
        G(u16, 0xA) = P(u16, 0xA);
        G(u16, 0xE) = P(u16, 0xE) + 0x26;
        break;
    case 19:
        G(u16, 0xA) = P(u16, 0xA) + 0x26;
        G(u16, 0xE) = P(u16, 0xE);
        break;
    }
    func_80017A04(self);
    (*(void (**)(void*))((G(s8, 5) << 2) + (s32)D_800FCDE4))(self);
    G(u8, 0x88) = 0;
    if (func_80031474(self) != 0) {
        G(u8, 0x88) = 1;
    }
    func_80030ECC(self);
}

#undef G
#undef P
