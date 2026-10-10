#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8001750C(M2C_UNK, M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK func_8002C9B0();
s32 func_8002CAB4(void*);
M2C_UNK func_8002CD6C(void*);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_8003CCBC();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
void func_800EE344(void*);
void func_800EE6C0(void* self);
void func_800EE828(void);
void func_800F1C80(void* arg0);
s32 func_800F1DA8(void*, s32, s32);

extern M2C_UNK D_800970A0;
#define F1EC4_PL (*(struct X4_PlayerObj*)&D_800970A0)
extern u16 D_80097202;
extern s8 D_800CCEDF;
extern s8 D_800CCEF6;
extern M2C_UNK D_800F3A3C;
extern void (*D_800F3A74[])(void*);
extern void (*D_800F3AAC[])(void*);

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PL_D5 M2C_FIELD(pl, s8*, 0xD5)

void func_800F1EC4(void* self) {
    struct X4_VisualObj* v;
    u8* p;

    S8(0x3) = 0;
    if (func_8002CAB4(self) != 0) {
        return;
    }
    {
        struct X4_PlayerObj* pl = &F1EC4_PL;
        if (PL_D5 != 0 && (U8(0xA8) & 1) &&
            (S16(0xA) - (s16)D_80097202) < 0x20) {
            pl->hp = -0x80;
            S8(0x5C) = -0x80;
            S8(0x3) = 0;
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_80049EBC(self, 0, 0x20, 0x20);
            func_8002C9B0(self);
            D_800CCEF6 = 0;
            U8(0xA8) = 0;
            return;
        }
    }
    if (S8(0x5C) < 0) {
        if (S8(0x5C) == -0x80) {
            if (!(U8(0x97) & 0x80)) {
                U8(0x97) |= 0x80;
                U8(0x92) = 0x1E;
                U8(0x91) = 0x1E;
                U8(0x8C) = 0;
            }
            S8(0x5C) = 0x20;
        }
        S16(0xA4) = 0x400;
        U8(0x8C) = 0x79;
        v = func_8002C398();
        if (v != NULL) {
            v->active = S8(0x0);
            v->id = 0xC;
            v->unk2 = 8;
            v->x_pos.val = S32(0x8);
            v->y_pos.val = S32(0xC);
            v->animation_table = M2C_FIELD(self, u32***, 0x30);
            v->unk40 = U16(0x40);
            v->unk3C = M2C_FIELD(self, void**, 0x3C);
            v->unk42 = U16(0x42) & 0x7FFF;
            v->unk16 = U8(0x16);
            v->unk15 = U8(0x15);
            v->unk50 = self;
        }
        U8(0x93) = 1;
        U8(0x85) = 1;
        U8(0x97) |= 2;
    }
    if (U8(0x8C) != 0) {
        if (--U8(0x8C) == 0 && (U8(0x97) & 1)) {
            F1EC4_PL.on_screen = 1;
        }
    }
    if ((U8(0x97) & 0x41) == 0x41 || (D_800CCEDF != 0 && (U8(0x97) & 0x40))) {
        U8(0x97) ^= 1;
        S8(0x5) = 0xB;
        S8(0x6) = 0;
    }
    func_800EE6C0(self);
    ((void (*)(void*))func_800EE828)(self);
    func_800EE344(self);
    if (U8(0x8D) == 0) {
        if (S8(0x2) == 0) {
            D_800F3A74[S8(0x5)](self);
        } else {
            if (U8(0x7E) != 0) {
                U8(0x7E)--;
            }
            D_800F3AAC[S8(0x5)](self);
        }
        func_800F1C80(self);
        func_8002F288(self);
        if (U8(0x97) & 0x40) {
            F1EC4_PL.x_pos.val = S32(0x8);
            F1EC4_PL.y_pos.val = S32(0xC);
            F1EC4_PL.unk15 = U8(0x15);
            if ((U8(0x97) & 0x40) && U8(0x8C) != 0) {
                if (!(U8(0x8C) & 3)) {
                    U16(0x42) |= 0x8000;
                } else {
                    U16(0x42) &= 0x7FFF;
                }
            }
        }
        p = &U8(0x88);
        if (U8(0x97) & 0x80) {
            U16(0x42) &= 0x7FFF;
            if ((p[0xA] = U8(0x92) - 1) == 0) {
                U8(0x92) = U8(0x91);
                U16(0x42) |= 0x8000;
                if ((p[0x9] = U8(0x91) - 1) == 0) {
                    U8(0x8D) = 1;
                    U16(0x42) &= 0x7FFF;
                }
            }
        }
        func_8002CD6C(self);
    }
    switch (U8(0x8D)) {
    case 1: {
        struct X4_PlayerObj* pl = &F1EC4_PL;
        U8(0x8D) = 2;
        U8(0x8C) = 0xFF;
        PL_D5 = 0;
        U8(0x97) ^= 0x40;
        func_8003CCBC(pl);
        U8(0x90) = 0x1E;
        U8(0x97) |= 4;
        func_800477E4(7, &D_800F3A3C, self);
        break;
    }
    case 2:
        if (--S8(0x90) == 0) {
            S8(0x4) = 2;
            S8(0x3) = 0;
            func_80049E50(self);
            func_8001750C(2, 8);
        } else {
            func_80049EBC(self, 0, 0x1F, 0x1F);
        }
        break;
    default:
        if (U8(0x8C) == 0) {
            U8(0x85) = 0;
            U16(0x42) &= 0x7FFF;
        }
        break;
    }
    ((void (*)(void*))func_800F1DA8)(self);
}
