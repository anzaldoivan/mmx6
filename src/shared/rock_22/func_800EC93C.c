#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj D_800970A0;
extern s32 D_800FB7A0;

#define EC93C_U8(s, o) M2C_FIELD(s, u8*, o)
#define EC93C_S8(s, o) M2C_FIELD(s, s8*, o)
#define EC93C_S16(s, o) M2C_FIELD(s, s16*, o)
#define EC93C_ABS(v) ((v) < 0 ? -(v) : (v))

void func_800EC93C(void* self) {
    void* parent;
    void* p;

    parent = M2C_FIELD(self, void**, 0x80);
    if (EC93C_S8(self, 2) == 4 && EC93C_S8(self, 7) == 0) {
        EC93C_S16(self, 0xE) = EC93C_S16(parent, 0xE) - 0x27;
        if (EC93C_S16(self, 0xE) >= 0x521 && EC93C_S8(parent, 6) == 6) {
            M2C_FIELD(self, void**, 0x68) = &D_800FB7A0;
        }
    }
    if (D_800970A0.x_pos.i.hi > EC93C_S16(self, 0xA)) {
        EC93C_U8(self, 0x15) = 0x40;
    } else {
        EC93C_U8(self, 0x15) = 0;
    }
    EC93C_S16(self, 0x7C)++;
    switch (EC93C_S8(self, 6)) {
    case 1:
        if (EC93C_ABS(D_800970A0.x_pos.i.hi - EC93C_S16(self, 0xA)) <= 0x80) {
            goto spawn;
        }
        if ((s16)(EC93C_S16(self, 0x7C) % 200) == 0) {
            ((void (*)(void*, s32))func_800179A4)(self, 1);
            EC93C_S8(self, 6)++;
        }
        break;
    case 2:
        if (D_800970A0.x_pos.i.hi - EC93C_S16(self, 0xA) >= 0) {
            if (D_800970A0.x_pos.i.hi - EC93C_S16(self, 0xA) <= 0x80) {
                goto spawn;
            }
        } else if (EC93C_S16(self, 0xA) - D_800970A0.x_pos.i.hi <= 0x80) {
        spawn:
            p = func_8002C458();
            if (p != 0) {
                M2C_FIELD(p, u8*, 0) = EC93C_U8(self, 0);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 0;
                M2C_FIELD(p, void**, 0x7C) = self;
            }
            ((void (*)(void*, s32))func_800179A4)(self, 2);
            EC93C_S16(self, 0x7C) = 0;
            EC93C_U8(self, 6) = 3;
            break;
        }
        if (EC93C_S8(self, 0x46) == 0) {
            EC93C_U8(self, 6) = 0;
        }
        break;
    case 3:
        if (EC93C_S16(self, 0x7C) != 0x5A) {
            break;
        }
    case 0:
        ((void (*)(void*, s32))func_800179A4)(self, 0);
        EC93C_S16(self, 0x7C) = 0;
        EC93C_S8(self, 6)++;
        break;
    case 4:
        if (EC93C_S16(self, 0x7C) == 0x28) {
            EC93C_U8(self, 6) = 0;
        }
        break;
    }
}

#undef EC93C_U8
#undef EC93C_S8
#undef EC93C_S16
#undef EC93C_ABS
