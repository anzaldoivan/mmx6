#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
s32 func_8002D2D4();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);

extern s32 D_8007429C;
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800743DC;
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F67CC;
extern M2C_UNK D_800F6F38;
extern M2C_UNK D_800F6F48;
extern M2C_UNK D_800F6F58;
extern M2C_UNK D_800F6F68;
extern M2C_UNK D_800F6F6C;
extern M2C_UNK D_800F6F80;

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

#define SPAWN_CHILDREN()                                                       \
    {                                                                          \
        U16(0xA) -= 0x20;                                                      \
        func_80016C48(2, 0x73, self);                                          \
        for (i = 0; i < 8; i++) {                                              \
            c = func_8002C398();                                               \
            if (c != NULL) {                                                   \
                M2C_FIELD(c, u8*, 0x0) = 0x51;                                 \
                M2C_FIELD(c, u8*, 0x1) = 0x14;                                 \
                M2C_FIELD(c, u8*, 0x2) = i;                                    \
                M2C_FIELD(c, u8*, 0x14) = U8(0x14);                            \
                M2C_FIELD(c, u16*, 0xA) = U16(0xA);                            \
                M2C_FIELD(c, u16*, 0xE) = U16(0xE);                            \
                M2C_FIELD(c, s32*, 0x38) = S32(0x38);                          \
                M2C_FIELD(c, s32*, 0x3C) = S32(0x3C);                          \
                M2C_FIELD(c, u16*, 0x40) = U16(0x40);                          \
                M2C_FIELD(c, u16*, 0x42) = U16(0x42);                          \
                M2C_FIELD(c, u8*, 0x16) = 6;                                   \
                M2C_FIELD(c, void**, 0x50) = self;                             \
                if (i != 0) {                                                  \
                    M2C_FIELD(c, void**, 0x5C) = prev;                         \
                } else {                                                       \
                    M2C_FIELD(c, void**, 0x5C) = self;                         \
                }                                                              \
                prev = c;                                                      \
            }                                                                  \
        }                                                                      \
    }

void func_800F0D08(void* self) {
    struct X4_VisualObj* c;
    void* prev;
    s32 i;
    s32 t;
    s32 dx;
    s32 dy;

    U8(0x16) = 4;
    U8(0x3) = 0;
    PTR(0x58) = &D_800743DC;
    U8(0x67) = 0;
    PTR(0x68) = NULL;
    PTR(0x50) = NULL;
    PTR(0x54) = NULL;
    U8(0x4) = 1;
    U8(0x5) = 0;
    U8(0x6) = 0;
    U8(0x7) = 0;
    S32(0x20) = 0;
    S32(0x24) = 0;
    S32(0x28) = 0;
    S32(0x2C) = 0;
    U16(0x8C) = 0;
    U16(0x8E) = 0;
    U8(0x92) = 0;
    U16(0x90) = 0;
    U16(0x94) = 0;

    if ((U8(0x2) & 0xF) == 0) {
        SPAWN_CHILDREN();
        U8(0x60) = 6;
        U8(0x5C) = 0x10;
        U8(0x7) = 0;
        ((void (*)(void*, s32))func_800179A4)(self, 0);
        U8(0x16) = 4;
        U8(0x5) = 0;
    } else if ((U8(0x2) & 0xF) == 1) {
        SPAWN_CHILDREN();
        ((void (*)(void*, s32))func_800179A4)(self, 0);
        U8(0x60) = 6;
        U8(0x5C) = 0x10;
        U8(0x16) = 4;
        U8(0x5) = 3;
    } else if ((U8(0x2) & 0xF) == 2) {
        SPAWN_CHILDREN();
        U8(0x3) = 1;
        ((void (*)(void*, s32))func_800179A4)(self, 0);
        U8(0x60) = 6;
        U8(0x5C) = 0x30;
        U8(0x16) = 3;
        U8(0x5) = 6;
        U8(0x75) = 1;
        U16(0x90) = ((u32)func_8002D2D4() % 19 & 0xFF) * 10 + 0x78;
    } else if ((U8(0x2) & 0xF) == 3) {
        func_80016C48(2, 0x75, self);
        U8(0x60) = 2;
        dx = g_Player.x_pos.i.hi - S16(0xA);
        dy = g_Player.y_pos.i.hi - S16(0xE);
        t = func_80065B74(dy, dx);
        S32(0x20) = func_80065A14(t) << 5;
        S32(0x24) = -func_80065944(t) << 5;
        PTR(0x58) = &D_8007429C;
        U8(0x5C) = 1;
        PTR(0x68) = &D_800F6F38;
        PTR(0x50) = &D_800F6F58;
        PTR(0x54) = &D_800F6F48;
        U8(0x16) = 3;
        U8(0x5) = 5;
        ((void (*)(void*, s32))func_800179A4)(self, 0xC);
    } else if ((U8(0x2) & 0xF) == 4) {
        ((void (*)(void*, s32))func_800179A4)(self, 0);
        U8(0x16) = 6;
        U8(0x5) = 7;
        U16(0x8C) = 0x5A;
        U16(0xA) -= 0x18;
        U16(0xE) += 8;
    } else if ((U8(0x2) & 0xF) == 5) {
        U16(0xA) -= 0x10;
        U16(0xE) += 8;
        ((void (*)(void*, s32))func_800179A4)(self, 1);
        U8(0x16) = 5;
        U8(0x5) = 7;
        U16(0x8C) = 0x5A;
    } else if ((U8(0x2) & 0xF) == 6) {
        U8(0x60) = 0xA;
        ((void (*)(void*, s32))func_800179A4)(self, 2);
        U8(0x5) = 7;
        U8(0x16) = 5;
        PTR(0x50) = &D_800F6F68;
        U16(0x8C) = 0x78;
        U16(0xA) -= 0x50;
        U16(0xE) += 8;
    } else if ((U8(0x2) & 0xF) == 7) {
        U8(0x60) = 0xA;
        U16(0xA) -= 0x108;
        U16(0xE) += 8;
        ((void (*)(void*, s32))func_800179A4)(self, 3);
        U8(0x16) = 6;
        U8(0x5) = 7;
        PTR(0x50) = &D_800F6F6C;
        U16(0x8C) = 0x78;
    } else if ((U8(0x2) & 0xF) == 8) {
        U16(0xA) -= 0xA0;
        U16(0xE) += 8;
        ((void (*)(void*, s32))func_800179A4)(self, 6);
        U8(0x16) = 5;
        U8(0x5) = 7;
        U16(0x8C) = 0x18;
    } else if ((U8(0x2) & 0xF) == 9) {
        U8(0x16) = 6;
        ((void (*)(void*, s32))func_800179A4)(self, 7);
        U8(0x5) = 8;
        U16(0x8C) = 0xA0;
    } else if ((U8(0x2) & 0xF) == 10) {
        U8(0x16) = 5;
        U8(0x60) = 0xA;
        ((void (*)(void*, s32))func_800179A4)(self, 8);
        U8(0x5) = 8;
        U8(0x6) = 2;
        PTR(0x50) = &D_800F6F80;
        U16(0x8C) = 0x78;
    } else if ((U8(0x2) & 0xF) == 11) {
        U8(0x16) = 5;
        U8(0x60) = 0xC;
        U16(0xA) -= 0x10;
        U16(0xE) += 0x10;
        ((void (*)(void*, s32))func_800179A4)(self, 9);
        U8(0x5) = 9;
    } else if ((U8(0x2) & 0xF) == 12) {
        U8(0x60) = 0xC;
        U8(0x16) = 5;
        U16(0xA) -= 0x10;
        U16(0xE) += 0x10;
        ((void (*)(void*, s32))func_800179A4)(self, 9);
        U8(0x15) = 0x40;
        U8(0x5) = 9;
    } else if ((U8(0x2) & 0xF) == 13) {
        U8(0x3) = 0;
        U8(0x16) = 7;
        PTR(0x54) = &D_800F67CC;
        PTR(0x58) = &D_8007433C;
        U8(0x5) = 0xA;
    }
}
