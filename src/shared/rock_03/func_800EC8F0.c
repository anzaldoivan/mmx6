#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern u8 D_800CCF38;
extern M2C_UNK D_800F7690;
extern void (*D_800F76A8[])(void*);

#define G(type, off) (*(type*)((u8*)self + (off)))

void func_800EC8F0(void* self) {
    s32 r;

    D_800F76A8[G(s8, 5)](self);
    r = check_enemy_hits(self);
    if (r == -2 || r == -0xB || r == -0x37) {
        func_80049E50(self);
        func_800477E4(4, &D_800F7690, self);
        func_8004E654((struct X4_BaseObj*)self, 0x15);
        G(s8, 4) = 2;
        return;
    }
    if (r < 0) {
        func_80049E50(self);
        func_800477E4(4, &D_800F7690, self);
        if (D_800CCF38 >= 2) {
            set_animation(self, 0xF);
        } else {
            set_animation(self, 5);
        }
        G(u8, 0x5C) = 0x20;
        G(s32, 0x54) = 0;
        G(s32, 0x50) = 0;
        G(s8, 5) = 5;
        return;
    }
    func_80030ECC(self);
    if (func_8002CBFC((s32)self, 0x40, 0x40) == 0) {
        func_8002CCB0(self, 0x30, 0x30);
    }
}
#undef G
