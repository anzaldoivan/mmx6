// rolefeed (3.1 T4): func_800EB5F8 of src/rock_09/E9860.c
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002F288();
void func_800EB914(void*);
void func_800EBA90(void*);
void func_800EBD14(void*);
extern u8 D_800F4BF0[];

void func_800EB5F8(void* arg0) {
    switch (M2C_FIELD(arg0, s8*, 2)) {
    case 1:
    case 2:
    case 3:
    case 4:
        func_800EB914(arg0);
        return;
    case 5:
        func_800EBA90(arg0);
        return;
    case 6:
        func_800EBD14(arg0);
        return;
    }
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    ((void (**)(void*))(D_800F4BF0 + 0x11F4))[M2C_FIELD(arg0, s8*, 4)](arg0);
    func_8002F288(arg0);
}
