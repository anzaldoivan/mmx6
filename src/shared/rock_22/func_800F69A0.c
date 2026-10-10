#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();
M2C_UNK func_8002D2B0(s32);
s32 func_8002D2D4();
extern u16 D_800FD59A;

#define SPAWN_HEAD(kind)                                                       \
    c->active = 0x41;                                                          \
    c->id = 0x1E;                                                              \
    c->unk2 = kind;                                                            \
    c->unk42 = arg0->unk42 & 0x7FFF;                                           \
    c->animation_table = (u32**)arg0->animation_table;                         \
    c->unk3C = (void*)arg0->sprite_frames;                                     \
    c->unk40 = arg0->unk40;                                                    \
    c->bg_offset = arg0->bg_offset;

void func_800F69A0(struct X4_MainObj* arg0) {
    struct X4_ShotObj* c;
    s32 state;
    s32 n;
    s32 i;
    s8 k;

    ((void (*)())func_80017A04)();
    if (arg0->unk7C != 0) {
        ((void (*)(void*))func_8002D2B0)(arg0);
        arg0->unk7C--;
        return;
    }
    state = arg0->unk7E;
    switch (state) {
    case 0:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(7)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi - 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
        }
        n = (u8)((u32)func_8002D2D4() % 3) + 1;
        for (i = 0; i < n; i++) {
            c = func_8002C458();
            if (c != 0) {
                SPAWN_HEAD(0)
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi - 0x20;
                c->unk7C = (void*)arg0;
            }
        }
        func_80016C48(2, 0x6F, arg0);
        M2C_FIELD(arg0, u8*, 0x93) = 0xB4;
        arg0->unk7C = (u8)((u32)func_8002D2D4() % 6) + 2;
        arg0->unk6++;
        break;
    case 1:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(1)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
            c->x_vel.val = -0x20000;
            c->y_vel.val = 0;
        }
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(1)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
            c->x_vel.val = 0x20000;
            c->y_vel.val = 0;
        }
        arg0->unk7C = 0x5A;
        M2C_FIELD(arg0, u8*, 0x93)--;
        arg0->unk6++;
        break;
    case 2:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(8)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
        }
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(2)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x20;
            c->unk7C = (void*)arg0;
        }
        M2C_FIELD(arg0, u8*, 0x93) = 0;
        arg0->unk7C = 0x12C;
        arg0->unk6++;
        break;
    case 3:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(3)
            k = M2C_FIELD(arg0, s8*, 0x45);
            if (k == 0) {
                c->x_pos.i.hi = arg0->x_pos.i.hi + 0x10;
                c->y_pos.i.hi = arg0->y_pos.i.hi;
            } else if (k == 1) {
                c->x_pos.i.hi = arg0->x_pos.i.hi - 0x10;
                c->y_pos.i.hi = arg0->y_pos.i.hi;
            } else if (k == 2) {
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi - 0x10;
            } else if (k == 3) {
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            }
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
        }
        M2C_FIELD(arg0, u8*, 0x93)--;
        arg0->unk7C = D_800FD59A;
        arg0->unk6++;
        break;
    }
}
