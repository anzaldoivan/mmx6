// rolefeed (3.1 T4): func_800EED40 of src/rock_04/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj g_Player;
extern s32 D_800F6720;
extern s32 D_800F6724;
extern s32 D_800F6728;
extern s32 D_800F6A00;

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;
extern void (*D_800F6CE8[])(void*);

void func_800EED40(struct X4_PlayerObj* arg0) {
    if (g_Player.x_pos.i.hi >= 0x1241) {
        if (g_Player.y_pos.i.hi >= 0x4F1) {
            clear_object_slot();
        }
    }
    D_800F6CE8[arg0->state](arg0);
}
