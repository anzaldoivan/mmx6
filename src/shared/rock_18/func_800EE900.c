// rolefeed (3.1 T4): func_800EE900 of src/rock_18/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_800139A0(M2C_UNK);
M2C_UNK reset_level();
void func_800EA3F0(s32, s32, s32, s32);
void func_800EA470(s32, s32, s32, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"

#include "common.h"
#include "mmx6/x4.h"

void func_800EFBFC(void*, u8, s16, s16);
extern s16 D_800F0E98[];

#define PART(c, n, dx, dy)                                                     \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0E98[(n)] + (dx),        \
                  self->y_pos.i.hi + D_800F0E98[(n) + 1] + (dy))

void func_800EE900(struct X4_BaseObj* self) {
    PART(0x49, 4, 0, 0);
    PART(0x4A, 10, 0, 0);
    PART(0x92, 0, 0x74, 4);
    PART(0x92, 2, 0x74, 4);
    PART(0x92, 6, 0x74, 4);
    PART(0x92, 8, 0x74, 4);
    PART(0x92, 12, 0x74, 4);
    PART(0x92, 14, 0x74, 4);
    self->state = 2;
}
