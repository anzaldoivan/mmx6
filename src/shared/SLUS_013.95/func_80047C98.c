#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* alloc_sprite_slot();
s32 random_byte();
extern u32* D_80095098;

void func_80047C98(u8 count, u8* src, void* parent, s32 kind, s32 arg4) {
    void* obj;
    s32 a;
    s32 b;
    u8 t;

    while (count != 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0x0) = 0x41;
            M2C_FIELD(obj, u8*, 0x1) = 3;
            M2C_FIELD(obj, u8*, 0x2) = 1;
            M2C_FIELD(obj, u8*, 0x15) = random_byte() & 0x40;
            M2C_FIELD(obj, u8*, 0x4) = 0;
            M2C_FIELD(obj, u8*, 0x5) = 0;
            M2C_FIELD(obj, u8*, 0x6) = 0;
            M2C_FIELD(obj, s32*, 0x8) =
                M2C_FIELD(parent, s32*, 0x8) + ((random_byte() & 3) << 16);
            M2C_FIELD(obj, s32*, 0xC) =
                M2C_FIELD(parent, s32*, 0xC) + ((random_byte() & 3) << 16);
            t = *src++;
            M2C_FIELD(obj, void**, 0x54) = parent;
            M2C_FIELD(obj, s32*, 0x30) = arg4;
            M2C_FIELD(obj, u8*, 0x58) = t;
            a = func_8002A47C(kind);
            b = func_8002A47C(kind);
            M2C_FIELD(obj, s16*, 0x42) =
                ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            M2C_FIELD(obj, u16*, 0x40) = D_80095098[func_8002A47C(kind)] >> 7;
            M2C_FIELD(obj, s32*, 0x3C) =
                (s32)SCRATCH_20 + SCRATCH_20[func_8002A47C(kind)];
        }
        count--;
    }
}
