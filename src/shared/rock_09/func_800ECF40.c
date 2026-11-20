// rolefeed (3.1 T4): func_800ECF40 of src/rock_09/E9860.c
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK collide_solid_object();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);
extern struct X4_PlayerObj g_Player;
extern u8 D_800F4BF0[];

void func_800ECF40(void* arg0) {
    struct X4_PlayerObj* p;

    func_80032B34(arg0);
    func_80032BE8(arg0);
    p = &g_Player;
    if (p->nova_strike_active != 2) {
        ((void (**)(void*))(D_800F4BF0 + 0x14B0))[M2C_FIELD(arg0, s8*, 6)](
            arg0);
    }
    animate_object(arg0);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x40);
    if (((u8*)p)[0xE5] == 0) {
        collide_solid_object(arg0);
    }
    func_8003208C(arg0);
    func_80031F4C(arg0);
}
