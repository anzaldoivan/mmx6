// rolefeed (3.1 T4): func_800F2798 of src/rock_05/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

#include "common.h"
#define M2C_UNK s32

extern u16 D_800F447E;
M2C_UNK animate_object();
M2C_UNK apply_object_motion(void*);

void func_800F2798(u8* arg0) {
    s8 state;
    s16 x;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        state = 5;
    } else {
        animate_object(arg0);
        apply_object_motion(arg0);
        x = *(s16*)(arg0 + 0xA);
        if (x < (s16)D_800F447E + 0x1030) {
            *(u16*)(arg0 + 0xA) = D_800F447E + 0x1030;
        } else if ((s16)D_800F447E + 0x1150 < x) {
            *(u16*)(arg0 + 0xA) = D_800F447E + 0x1150;
        }
        if (*(s32*)(arg0 + 0x20) != 0) {
            return;
        }
        if (*(u8*)(arg0 + 0x15) == 0) {
            *(u8*)(arg0 + 0x15) = 0x40;
            *(s32*)(arg0 + 0x20) = 0x40000;
        } else {
            *(u8*)(arg0 + 0x15) = 0;
            *(s32*)(arg0 + 0x20) = 0xFFFC0000;
        }
        state = 3;
        *(s32*)(arg0 + 0x28) = 0;
    }
    *(u8*)(arg0 + 6) = state;
}
