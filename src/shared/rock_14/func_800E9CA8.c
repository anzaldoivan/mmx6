#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern u8 D_800ED718[];
extern M2C_UNK D_800ED6F8;

void func_800E9CA8(struct X4_BaseObj* self) {
    u8 flags;
    s32 dir;

    {
        // !FAKE: depin: dropping it breaks the match (106/108)
        register s32 x asm("$2") = M2C_FIELD(self, s32*, 0x8);
        s32 y = M2C_FIELD(self, s32*, 0xC);
        M2C_FIELD(self, s32*, 0x18) = x;
        M2C_FIELD(self, s32*, 0x1C) = y;
    }
    {
        u8* tbl = D_800ED718;
        void* fn = ((void**)tbl)[self->unk5];
        ((void (*)(struct X4_BaseObj*))fn)(self);
    }
    func_80017A04(self);
    func_80030ECC(self);
    if (func_80031474(self) < 0) {
        func_80049E50(self);
        func_800477E4(3, &D_800ED6F8, self);
        func_8004E654(self, 0x12);
        self->state = 2;
        return;
    }
    if (func_8002CBFC(self, 0xA0, 0x78) == 0) {
        func_8002CCB0(self, 0x20, 0x20);
        if (self->on_screen != 0) {
            if (M2C_FIELD(SPAD, s16*, 0x84) != 0) {
                if (M2C_FIELD(SPAD, u16*, 0x84) & 1) {
                    self->on_screen = 1;
                } else {
                    self->on_screen = 0;
                }
                M2C_FIELD(SPAD, u16*, 0x84) -= 1;
            }
        }
    } else {
        self->state = 3;
        return;
    }
    flags = M2C_FIELD(self, u8*, 0x70);
    if ((flags & 0xC) == 0xC || (flags & 3) == 3) {
        func_80049E50(self);
        M2C_FIELD(self, s32*, 0x20) = 0;
        func_800477E4(3, &D_800ED6F8, self);
        self->state = 2;
        return;
    }
    if (flags & 8) {
        M2C_FIELD(self, s8*, 0x67) = 0;
    } else {
        dir = M2C_FIELD(self, s32*, 0x24);
        if (dir < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        M2C_FIELD(self, s8*, 0x67) = dir;
    }
    func_8002F288((M2C_UNK*)self);
}
