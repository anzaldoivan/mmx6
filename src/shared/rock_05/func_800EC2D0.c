#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);

extern s16 D_800970AA;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern u16 D_800F3F0C[];
extern void (*D_800F4014[])(void*);

void func_800EC2D0(void* self) {
    void* parent;
    s32 r;

    parent = M2C_FIELD(self, void**, 0x7C);
    r = func_80031474(self);
    D_800F4014[M2C_FIELD(self, s8*, 5)](self);
    if (M2C_FIELD(self, s8*, 5) == 1) {
        if (func_80030ECC(self) != 0) {
            ((void (*)(void*))func_80049E50)(self);
            goto set;
        }
        if (M2C_FIELD(self, u8*, 0x70) != 0) {
            func_80049E50(self);
            goto set;
        }
        if (r < 0) {
            ((long long (*)(void*))func_80049E50)(self);
            goto set;
        }
        if (func_8002CBFC(self, 0x60, 0x60) == 0) {
            func_8002CCB0(self, 0x40, 0x40);
            return;
        }
        goto set;
    } else if (M2C_FIELD(self, s8*, 5) == 0) {
        if (M2C_FIELD(parent, s8*, 4) == 3) {
        set:
            M2C_FIELD(self, s8*, 4) = 2;
        }
    } else {
        if (M2C_FIELD(self, s8*, 2) == 6) {
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(self, u16*, 0x90);
            if (M2C_FIELD(self, s16*, 0xA) == 0xB80) {
                if ((u32)D_80097420 % 10 == 0) {
                    M2C_FIELD(self, u8*, 0x92) =
                        (M2C_FIELD(self, u8*, 0x92) + 1) & 3;
                    D_800971F8[2].unk40 =
                        D_800F3F0C[M2C_FIELD(self, u8*, 0x92)] - 0xB20;
                }
                D_800971F8[2].unk4C = 1;
            }
        } else {
            if (M2C_FIELD(self, s16*, 0xA) == 0xCE0) {
                if ((u32)D_80097420 % 10 == 0) {
                    M2C_FIELD(self, u8*, 0x92) =
                        (M2C_FIELD(self, u8*, 0x92) + 1) & 3;
                    D_800971F8[2].unk40 =
                        D_800F3F0C[M2C_FIELD(self, u8*, 0x92)] - 0xCA0;
                }
                D_800971F8[2].unk4C = 1;
            }
            if (D_800970AA > 0xEF0) {
                D_800971F8[0].unk2E += 0x40;
                M2C_FIELD(self, s8*, 4) = 2;
                return;
            }
        }
        func_80030ECC(self);
    }
}
