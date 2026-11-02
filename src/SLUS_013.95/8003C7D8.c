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

#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);
extern u32* D_8007789C[];
extern s16 D_80073D6C[][2];

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_8003C964(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8* tbl;
    s32 off;
    u8 f;
    u8 bg;

    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = 1;
        bg = self->bg_offset;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
        obj->unk38 = 0;
        obj->bg_offset = bg;
        tbl = SCRATCH_1C;
        off = *(s32*)(tbl + 4);
        obj->animation_table = D_8007789C;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk3C = tbl + off;
        f = self->unk15;
        obj->unk15 = f;
        if (f == 0) {
            obj->x_pos.i.hi = self->x_pos.i.hi + D_80073D6C[self->unk2][0];
        } else {
            obj->x_pos.i.hi = self->x_pos.i.hi - D_80073D6C[self->unk2][0];
        }
        obj->y_pos.i.hi = self->y_pos.i.hi + D_80073D6C[self->unk2][1];
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2);
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
    s32 k;

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
        play_sound(5, 5, self);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern void (*D_80073CF4[])(u8*);

void func_8003CBE4(u8* arg0) {
    s32 idx;

    if (g_playthrough_state.unk1E != 0) {
        arg0[3] = 1;
        g_playthrough_state.unk1F = 1;
        idx = 0;
        if (g_playthrough_state.stage == 0xC) {
            if (g_playthrough_state.substage == 0) {
                s32 t = (u8)g_playthrough_state.checkpoint - 2;
                idx = (u32)t < 0x10U;
            }
        }
        arg0[4]++;
        D_80073CF4[idx](arg0);
    }
}

#define func_80041AB8 func_8003CC78
#define D_80075FD8 D_80073D20
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

void func_8003CCB4(void) {
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003CCBC);
// clang-format on

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_80073D58;
extern M2C_UNK D_80073D5C;

void func_8003CD00(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD5) < 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x68) = NULL;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_80073D58;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_80073D5C;
}
