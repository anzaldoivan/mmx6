#include "common.h"
#include "mmx6/x4.h"

s32 func_8002A47C(s32);
struct X4_VisualObj* func_8002C398(void);
s32 func_8002FF70();
extern s16 D_80073D68[];
extern u32* D_8007789C[];
extern u32* D_80095098;

#define SCRATCH_20 (*(u8**)0x1F800020)

void func_8003C7D8(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8* tbl;
    s32 a;
    s32 b;
    u8 f;
    s32 k;
    u8 bg;

    if (func_8002FF70() == 0x24) {
        obj = func_8002C398();
        k = 0x8B;
        if (obj != 0) {
            obj->active = 0x41;
            obj->id = 3;
            obj->unk2 = 8;
            bg = self->bg_offset;
            obj->unk16 = 1;
            obj->animation_table = D_8007789C;
            obj->bg_offset = bg;
            a = func_8002A47C(k);
            tbl = SCRATCH_20;
            obj->unk3C = tbl + *(s32*)(tbl + a * 4);
            obj->unk40 = D_80095098[func_8002A47C(0x8B)] >> 7;
            a = func_8002A47C(0x8B);
            b = func_8002A47C(0x8B);
            obj->unk42 = (a * 4 + 0x20) % 16 | ((b + 8) / 4 + 0x1E0) << 6;
            f = self->unk15;
            obj->unk15 = f;
            if (f == 0) {
                obj->x_pos.i.hi = self->x_pos.i.hi + D_80073D68[self->unk2];
            } else {
                obj->x_pos.i.hi = self->x_pos.i.hi - D_80073D68[self->unk2];
            }
            obj->y_pos.i.hi = self->y_pos.i.hi;
        }
    }
}
