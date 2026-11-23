// rolefeed (3.1 T4): func_800F28AC of src/rock_05/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void move_object();
s32 random_byte();
void func_800F2B4C();
extern s32 D_800F4144;
extern s16 D_800F4480;

void func_800F28AC(struct X4_BaseObj* self) {
    ((void (*)())func_800F2B4C)();
    ((void (*)(void*))animate_object)(self);
    ((void (*)(void*))move_object)(self);
    if (F16(self, 0xE) < D_800F4480 + 0x3E0) {
        FP(self, 0x68) = &D_800F4144;
    }
    if (FU8(self, 0x70) & 4) {
        if (!(random_byte() & 3)) {
            SPAD[0x89]++;
            self->action = 4;
            self->action_phase = 0;
            return;
        }
        self->action_phase++;
        ((void (*)(void*, s32))set_animation)(self, 0);
        F16(self, 0x7C) = 0x3C;
    }
}
