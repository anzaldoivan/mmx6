// rolefeed (3.1 T4): func_800EB670 of src/rock_04/E9860.c
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
#define M2C_UNK s32

M2C_UNK func_8002EE10(void*);

extern void (*D_800F6ACC[])(void*);
extern void (*D_800F6AD8[])(void*);
extern void (*D_800F6AE4[])(void*);

void func_800EB670(u8* self) {
    if (*(s32*)(self + 0x84) == 0 && self[0x70] == 0) {
        func_8002EE10(self);
    }
    self[3] = 0;
    switch ((s8)self[2]) {
    case 0:
        D_800F6ACC[(s8)self[4]](self);
        break;
    case 1:
        D_800F6AD8[(s8)self[4]](self);
        break;
    case 2:
        D_800F6AE4[(s8)self[4]](self);
        break;
    }
}
