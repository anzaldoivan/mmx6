#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002C9B0();
s32 func_8002D2D4();
extern s8 D_800CD30A;
extern u32* D_80095098;
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern s32 D_800EFC50;
extern s32 D_8007497C;

#define START(self)                                                            \
    {                                                                          \
        M2C_FIELD(self, s16*, 0x7C) = (func_8002D2D4() % 3 + 1) * 100 + 200;   \
        M2C_FIELD(self, u8*, 5) = 1;                                           \
        M2C_FIELD(self, u8*, 3) = 0;                                           \
        flag = 1;                                                              \
    }

void func_800EDCB4(void* self) {
    s32 flag = 0;
    s32 a;
    s32 b;

    if (D_800CD30A != 7) {
        func_8002C9B0(self);
        return;
    }
    M2C_FIELD(self, u8*, 0) = 0x41;
    M2C_FIELD(self, u16*, 0x40) =
        D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
    a = func_8002A47C(M2C_FIELD(self, s8*, 1));
    b = func_8002A47C(M2C_FIELD(self, s8*, 1));
    M2C_FIELD(self, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(self, s32*, 0x3C) =
        SPAD20 + ((s32*)SPAD20)[func_8002A47C(M2C_FIELD(self, s8*, 1))];
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        if ((u32)((u16)D_800970AA - 0x141) < 0x8BF) {
            START(self);
        }
        break;
    case 1:
        if ((u32)((u16)D_800970AA - 0xC81) < 0x3BF) {
            START(self);
        }
        break;
    case 2:
        if ((u32)((u16)D_800970AA - 0x4E1) < 0x17F) {
            START(self);
        }
        break;
    case 3:
        if ((u32)((u16)D_800970AA - 0x1361) < 0x92F) {
            START(self);
        }
        break;
    case 4:
        if ((u32)((u16)D_800970AA - 1) < 0x41F) {
            START(self);
        }
        break;
    case 5:
        if ((u32)((u16)g_Player.x_pos.i.hi - 0x141) < 0x71F &&
            g_Player.y_pos.i.hi < 0x430) {
            START(self);
        }
        break;
    case 10:
        ((void (*)(void*, s32))func_800179A4)(self, 0);
        flag = 1;
        M2C_FIELD(self, s16*, 0x7C) = 0x28;
        M2C_FIELD(self, s32*, 0x54) = 0;
        M2C_FIELD(self, s32*, 0x50) = 0;
        M2C_FIELD(self, u8*, 5) = 3;
        M2C_FIELD(self, u8*, 3) = flag;
        break;
    case 11:
        M2C_FIELD(self, s16*, 0x7C) = 0x28;
        ((void (*)(void*, s32))func_800179A4)(self, 2);
        flag = 1;
        M2C_FIELD(self, s32*, 0x54) = 0;
        M2C_FIELD(self, s32*, 0x50) = 0;
        M2C_FIELD(self, u8*, 5) = 3;
        M2C_FIELD(self, u8*, 3) = flag;
        break;
    }
    if (flag) {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(self, u8*, 0x5C) = 4;
        M2C_FIELD(self, u8*, 0x61) = 0;
        M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(p, u8*, 0x14);
        M2C_FIELD(self, void**, 0x30) = &D_800EFC50;
        M2C_FIELD(self, u8*, 0x16) = 4;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, u8*, 0x67) = 0;
        M2C_FIELD(self, void**, 0x58) = &D_8007497C;
        M2C_FIELD(self, u8*, 0x60) = 6;
        M2C_FIELD(self, u8*, 0x15) = (M2C_FIELD(self, s32*, 8) <= p->x_pos.val)
                                     << 6;
        M2C_FIELD(self, u8*, 4) = 1;
        M2C_FIELD(self, u8*, 6) = 0;
    }
}
