#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
s32 func_8002A47C(s32);
struct X4_VisualObj* func_8002C398(void);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
extern u32* D_8007789C[];
extern u32* D_80095098;

#define SCRATCH_20 (*(u8**)0x1F800020)

s32 func_8003CA70(void* arg0, s16 arg1) {
    struct X4_PlayerObj* self = arg0;
    struct X4_VisualObj* obj;
    u8* tbl;
    s32 a;
    s32 b;
    u8 f;
    u16 x;
    register s32 k asm("$4");

    if (func_80030234(self, self->x_pos.i.hi, arg1) == 0x24 &&
        M2C_FIELD(self, s8*, 0xDF) == 0) {
        M2C_FIELD(self, s8*, 0xDF) = 1;
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x41;
            obj->id = 3;
            obj->unk2 = 9;
            obj->bg_offset = self->bg_offset;
            k = 0x8B;
            obj->unk16 = 1;
            obj->animation_table = D_8007789C;
            a = func_8002A47C(k);
            tbl = SCRATCH_20;
            obj->unk3C = tbl + *(s32*)(tbl + a * 4);
            obj->unk40 = D_80095098[func_8002A47C(0x8B)] >> 7;
            a = func_8002A47C(0x8B);
            b = func_8002A47C(0x8B);
            obj->unk42 = (a * 4 + 0x20) % 16 | ((b + 8) / 4 + 0x1E0) << 6;
            f = self->unk15;
            obj->unk15 = f;
            x = self->x_pos.i.hi;
            obj->y_pos.i.hi = arg1 - 8;
            obj->x_pos.i.hi = x;
        }
        func_80016C48(5, 5, self);
    }
}
