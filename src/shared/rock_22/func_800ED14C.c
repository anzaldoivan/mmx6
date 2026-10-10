#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj D_800970A0;
extern s16 D_800970AA;

#define STATE(s) M2C_FIELD(s, s8*, 6)
#define XPOS(s) M2C_FIELD(s, s16*, 0xA)
#define DIR(s) M2C_FIELD(s, u8*, 0x15)
#define TIMER(s) M2C_FIELD(s, s16*, 0x7C)
#define ABSDIFF(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))

void func_800ED14C(void* self) {
    void* child;

    TIMER(self)++;
    switch (STATE(self)) {
    case 0:
        if (D_800970AA > XPOS(self)) {
            DIR(self) = 0x40;
        } else {
            DIR(self) = 0;
        }
        if (DIR(self) == 0) {
            ((void (*)(void*, s32))func_800179A4)(self, 0x18);
        } else {
            ((void (*)(void*, s32))func_800179A4)(self, 6);
        }
        TIMER(self) = 0;
        STATE(self)++;
        break;
    case 1:
        if (ABSDIFF(D_800970A0.x_pos.i.hi, XPOS(self)) < 0x61) {
            child = func_8002C458();
            if (child != NULL) {
                M2C_FIELD(child, u8*, 0) = M2C_FIELD(self, u8*, 0);
                M2C_FIELD(child, u8*, 1) = 5;
                M2C_FIELD(child, u8*, 2) = 1;
                M2C_FIELD(child, void**, 0x7C) = self;
            }
            if (D_800970A0.x_pos.i.hi > XPOS(self)) {
                DIR(self) = 0x40;
            } else {
                DIR(self) = 0;
            }
            if (DIR(self) == 0) {
                ((void (*)(void*, s32))func_800179A4)(self, 0x1A);
            } else {
                ((void (*)(void*, s32))func_800179A4)(self, 8);
            }
            TIMER(self) = 0;
            STATE(self) = 3;
        } else if (TIMER(self) % 200 == 0) {
            if (D_800970A0.x_pos.i.hi > XPOS(self)) {
                DIR(self) = 0x40;
            } else {
                DIR(self) = 0;
            }
            if (DIR(self) == 0) {
                ((void (*)(void*, s32))func_800179A4)(self, 0x19);
            } else {
                ((void (*)(void*, s32))func_800179A4)(self, 7);
            }
            STATE(self)++;
        }
        break;
    case 2:
        if (ABSDIFF(D_800970A0.x_pos.i.hi, XPOS(self)) < 0x61) {
            child = func_8002C458();
            if (child != NULL) {
                M2C_FIELD(child, u8*, 0) = M2C_FIELD(self, u8*, 0);
                M2C_FIELD(child, u8*, 1) = 5;
                M2C_FIELD(child, u8*, 2) = 1;
                M2C_FIELD(child, void**, 0x7C) = self;
            }
            if (D_800970A0.x_pos.i.hi > XPOS(self)) {
                DIR(self) = 0x40;
            } else {
                DIR(self) = 0;
            }
            if (DIR(self) == 0) {
                ((void (*)(void*, s32))func_800179A4)(self, 0x1A);
            } else {
                ((void (*)(void*, s32))func_800179A4)(self, 8);
            }
            TIMER(self) = 0;
            STATE(self) = 3;
        } else if (M2C_FIELD(self, s8*, 0x46) == 0) {
            STATE(self) = 0;
        }
        break;
    case 3:
        if (TIMER(self) == 0x5A) {
            if (D_800970AA > XPOS(self)) {
                DIR(self) = 0x40;
            } else {
                DIR(self) = 0;
            }
            if (DIR(self) == 0) {
                ((void (*)(void*, s32))func_800179A4)(self, 0x18);
            } else {
                ((void (*)(void*, s32))func_800179A4)(self, 6);
            }
            TIMER(self) = 0;
            STATE(self)++;
        }
        break;
    case 4:
        if (TIMER(self) == 0x28) {
            STATE(self) = 0;
        }
        break;
    }
}
