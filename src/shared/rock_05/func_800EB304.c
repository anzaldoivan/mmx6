#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800E9860[];
extern void (*D_800F3F2C[])(void*);

void func_800EB304(void* self) {
    s16 offs[4][2];
    void* parent;
    s32 r;

    __builtin_memcpy(offs, D_800E9860 + 0x1C, 0x10);
    parent = M2C_FIELD(self, void**, 0x80);
    D_800F3F2C[M2C_FIELD(self, s8*, 5)](self);
    r = func_80031474(self);
    if (M2C_FIELD(self, s8*, 2) >= 4) {
        if ((u32)(M2C_FIELD(self, u8*, 5) - 9) >= 2) {
            M2C_FIELD(self, u8*, 0x5C) = 0;
        }
        if (M2C_FIELD(self, s8*, 7) >= 4) {
            M2C_FIELD(self, s16*, 0x7E) = 0;
            M2C_FIELD(self, s8*, 5) = 8;
            M2C_FIELD(self, s8*, 6) = 0;
            M2C_FIELD(self, s8*, 7) = 0;
            M2C_FIELD(self, s32*, 0x54) = 0;
            M2C_FIELD(self, s32*, 0x50) = 0;
        }
        func_80030ECC(self);
        func_8002F288(self);
        if (func_8002CBFC(self, 0x80, 0x80) == 0) {
            func_8002CCB0(self, 0x60, 0x60);
        }
        background_objects[1].unk3 = M2C_FIELD(self, u8*, 3);
        M2C_FIELD(self, u8*, 3) = 0;
        background_objects[1].x_pos.i.hi = 0x200 - M2C_FIELD(self, s16*, 0xA);
        background_objects[1].y_pos.i.hi = 0x200 - M2C_FIELD(self, s16*, 0xE);
        background_objects[1].unk4C = 1;
        return;
    }
    if ((u32)(M2C_FIELD(parent, u8*, 5) - 9) >= 2) {
        M2C_FIELD(parent, u8*, 0x5C) += M2C_FIELD(self, u8*, 0x5C);
        if (M2C_FIELD(parent, s8*, 0x5C) == -0x80) {
            M2C_FIELD(parent, u8*, 0x5C) = 0x7F;
        }
    }
    if (r < 0) {
        func_80049E50(self);
        M2C_FIELD(self, s8*, 4) = 2;
        M2C_FIELD(parent, u8*, 7)++;
        return;
    }
    if (func_8002CBFC(self, 0x40, 0x40) == 0) {
        func_8002CCB0(self, 0x20, 0x20);
    }
    M2C_FIELD(self, s16*, 0xA) =
        M2C_FIELD(parent, s16*, 0xA) + offs[M2C_FIELD(self, s8*, 2)][0];
    M2C_FIELD(self, s16*, 0xE) =
        M2C_FIELD(parent, s16*, 0xE) + offs[M2C_FIELD(self, s8*, 2)][1];
}
