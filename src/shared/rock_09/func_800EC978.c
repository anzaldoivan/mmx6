// rolefeed (3.1 T4): func_800EC978 of src/rock_09/E9860.c
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

// clang-format on

#include "common.h"

#define M2C_UNK s32
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
extern u8 D_800F4BF0[];

void func_800EC978(void* arg0) {
    *(u8**)((u8*)arg0 + 0x50) = D_800F4BF0 + 0x1314;
    set_animation(arg0, 3);
    ((void (*)())animate_object)(arg0);
    *(s32*)((u8*)arg0 + 0x88) = 1;
    *(s16*)((u8*)arg0 + 0x7C) = 0x12C;
    *((u8*)arg0 + 6) += 1;
}
