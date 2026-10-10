#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj D_800970A0;
extern s32 D_800EF6F0;

#define E9DB0_U8(s, o) M2C_FIELD(s, u8*, o)
#define E9DB0_S8(s, o) M2C_FIELD(s, s8*, o)
#define E9DB0_S16(s, o) M2C_FIELD(s, s16*, o)
#define E9DB0_ABS(v) ((v) < 0 ? -(v) : (v))

void func_800E9DB0(void* self) {
    void* parent;
    void* p;

    parent = M2C_FIELD(self, void**, 0x80);
    if (E9DB0_S8(self, 2) == 4 && E9DB0_S8(self, 7) == 0) {
        E9DB0_S16(self, 0xE) = E9DB0_S16(parent, 0xE) - 0x27;
        if (E9DB0_S16(self, 0xE) >= 0x521 && E9DB0_S8(parent, 6) == 6) {
            M2C_FIELD(self, void**, 0x68) = &D_800EF6F0;
        }
    }
    if (D_800970A0.x_pos.i.hi > E9DB0_S16(self, 0xA)) {
        E9DB0_U8(self, 0x15) = 0x40;
    } else {
        E9DB0_U8(self, 0x15) = 0;
    }
    E9DB0_S16(self, 0x7C)++;
    switch (E9DB0_S8(self, 6)) {
    case 1:
        if (E9DB0_ABS(D_800970A0.x_pos.i.hi - E9DB0_S16(self, 0xA)) <= 0x80) {
            goto spawn;
        }
        if ((s16)(E9DB0_S16(self, 0x7C) % 200) == 0) {
            ((void (*)(void*, s32))func_800179A4)(self, 1);
            E9DB0_S8(self, 6)++;
        }
        break;
    case 2:
        if (D_800970A0.x_pos.i.hi - E9DB0_S16(self, 0xA) >= 0) {
            if (D_800970A0.x_pos.i.hi - E9DB0_S16(self, 0xA) <= 0x80) {
                goto spawn;
            }
        } else if (E9DB0_S16(self, 0xA) - D_800970A0.x_pos.i.hi <= 0x80) {
        spawn:
            p = func_8002C458();
            if (p != NULL) {
                M2C_FIELD(p, u8*, 0) = E9DB0_U8(self, 0);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 0;
                M2C_FIELD(p, void**, 0x7C) = self;
            }
            ((void (*)(void*, s32))func_800179A4)(self, 2);
            E9DB0_S16(self, 0x7C) = 0;
            E9DB0_U8(self, 6) = 3;
            break;
        }
        if (E9DB0_S8(self, 0x46) == 0) {
            E9DB0_U8(self, 6) = 0;
        }
        break;
    case 3:
        if (E9DB0_S16(self, 0x7C) != 0x5A) {
            break;
        }
    case 0:
        ((void (*)(void*, s32))func_800179A4)(self, 0);
        E9DB0_S16(self, 0x7C) = 0;
        E9DB0_S8(self, 6)++;
        break;
    case 4:
        if (E9DB0_S16(self, 0x7C) == 0x28) {
            E9DB0_U8(self, 6) = 0;
        }
        break;
    }
}

#undef E9DB0_U8
#undef E9DB0_S8
#undef E9DB0_S16
#undef E9DB0_ABS
