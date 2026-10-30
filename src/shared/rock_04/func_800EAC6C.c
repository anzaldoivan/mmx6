#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;

#define STATE(s) M2C_FIELD(s, s8*, 6)
#define XPOS(s) M2C_FIELD(s, s16*, 0xA)
#define DIR(s) M2C_FIELD(s, u8*, 0x15)
#define TIMER(s) M2C_FIELD(s, s16*, 0x7C)
#define ABSDIFF(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))

void func_800EAC6C(void* self) {
    void* child;
    u8 id;

    TIMER(self)++;
    switch (STATE(self)) {
    case 0:
        if (D_800970AA > XPOS(self)) {
            DIR(self) = 0x40;
        } else {
            DIR(self) = 0;
        }
        if (DIR(self) == 0) {
            ((void (*)(void*, s32))set_animation)(self, 0x1B);
        } else {
            ((void (*)(void*, s32))set_animation)(self, 9);
        }
        TIMER(self) = 0;
        STATE(self)++;
        break;
    case 1:
        if (ABSDIFF(g_Player.x_pos.i.hi, XPOS(self)) < 0xB5) {
            if (g_Player.x_pos.i.hi > XPOS(self)) {
                DIR(self) = 0x40;
            } else {
                DIR(self) = 0;
            }
            if (DIR(self) == 0) {
                ((void (*)(void*, s32))set_animation)(self, 0x1D);
            } else {
                ((void (*)(void*, s32))set_animation)(self, 0xB);
            }
            TIMER(self) = 0;
            STATE(self) = 3;
        } else if (TIMER(self) % 200 == 0) {
            if (g_Player.x_pos.i.hi > XPOS(self)) {
                DIR(self) = 0x40;
            } else {
                DIR(self) = 0;
            }
            if (DIR(self) == 0) {
                ((void (*)(void*, s32))set_animation)(self, 0x1C);
            } else {
                ((void (*)(void*, s32))set_animation)(self, 0xA);
            }
            STATE(self)++;
        }
        break;
    case 2:
        if (ABSDIFF(g_Player.x_pos.i.hi, XPOS(self)) < 0xB5) {
            if (g_Player.x_pos.i.hi > XPOS(self)) {
                DIR(self) = 0x40;
            } else {
                DIR(self) = 0;
            }
            if (DIR(self) == 0) {
                ((void (*)(void*, s32))set_animation)(self, 0x1D);
            } else {
                ((void (*)(void*, s32))set_animation)(self, 0xB);
            }
            TIMER(self) = 0;
            STATE(self) = 3;
        } else if (M2C_FIELD(self, s8*, 0x46) == 0) {
            STATE(self) = 0;
        }
        break;
    case 3:
        if (TIMER(self) == 0xC) {
            child = func_8002C458();
            if (child != NULL) {
                id = M2C_FIELD(self, u8*, 0);
                M2C_FIELD(child, s8*, 1) = 5;
                M2C_FIELD(child, s8*, 2) = 2;
                M2C_FIELD(child, void**, 0x7C) = self;
                M2C_FIELD(child, u8*, 0) = id;
            }
        } else if (TIMER(self) == 0x5A) {
            STATE(self) = 0;
        }
        break;
    }
}
