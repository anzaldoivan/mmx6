// rolefeed (3.1 T4): func_800F1604 of src/rock_05/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
void move_object();
extern s32 D_800F4144;
extern s16 D_800F4480;

void func_800F1604(void* arg0) {
    ((void (*)(void*))move_object)(arg0);
    ((void (*)())animate_object)(arg0);
    if ((D_800F4480 + 0x420) < ((s16*)arg0)[7]) {
        ((s32**)arg0)[0x68 / 4] = &D_800F4144;
    }
    if (((u8*)arg0)[0x70] & 8) {
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}
