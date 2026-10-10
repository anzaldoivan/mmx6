#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(void*);
M2C_UNK func_80030ECC();
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(void*, s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800743DC;
extern s32 D_800FC2AC;
extern s32 D_800FC2C4;
extern s32 D_800FC2C8;
extern s32 D_800FC2CC;
extern M2C_UNK D_800FC45C;
extern void (*D_800FC474[])(void*);
extern void* D_800FCFF0;
extern void* D_800FCFF4;
extern void* D_800FCFF8;
extern void* D_800FCFFC;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F006C(void* self) {
    s32 r;
    u8 m;
    void* p;
    void* q;

    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    ((M2C_UNK(*)())func_80017A04)();
    D_800FC474[F(s8, 5)](self);
    if (F(s8, 4) != 2) {
        if (F(u8, 0x8B) == 0) {
            F(void*, 0x50) = D_800FCFF0;
        } else {
            F(void*, 0x50) = D_800FCFF4;
        }
        func_80030ECC(self);
        F(void*, 0x50) = D_800FCFFC;
        func_80030ECC(self);
    }
    if (F(u8, 0x8B) == 0) {
        F(void*, 0x58) = &D_8007433C;
        F(void*, 0x54) = &D_800FC2C4;
        F(void*, 0x68) = &D_800FC2AC;
    } else {
        F(void*, 0x58) = &D_8007433C;
        F(void*, 0x54) = &D_800FC2C8;
        F(void*, 0x68) = &D_800FC2CC;
    }
    r = func_80031474(self);
    if (r < 0 || (q = &D_800743DC, p = D_800FCFF8, F(void*, 0x54) = p,
                  F(void*, 0x58) = q, r = func_80031474(self), r < 0)) {
        if (r != -0x38) {
            func_8004E654(self, 0x14);
        }
        goto dead;
    }
    if (func_8002CBFC(self, 0x60, 0x60) != 0) {
        F(s8, 4) = 4;
        return;
    }
    func_8002CCB0(self, 0x40, 0x40);
    m = F(u8, 0x70);
    if ((m & 0xC) == 0xC || (m & 3) == 3) {
    dead:
        F(void*, 0x68) = 0;
        func_80049E50(self);
        func_800477E4(4, &D_800FC45C, self);
        {
            register s32 a asm("$2") = 0x20;
            s32 b = 6;
            F(s16, 0x7E) = b;
            F(s16, 0x7C) = a;
        }
        F(s8, 3) = 0;
        F(s8, 4) = 2;
        return;
    }
    func_8002F288(self);
}
