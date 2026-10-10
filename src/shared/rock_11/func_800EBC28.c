#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_8002D2B0(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EBC28(struct X4_BaseObj* self) {
    u8 flags;
    s32 i;
    s16 x;

    flags = M2C_FIELD(self, u8*, 0x70);
    if (flags & 1) {
        M2C_FIELD(self, s32*, 0x20) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0xFFFC8000;
        self->unk5 = 8;
        self->unk15 = 0x40;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 4)) {
            M2C_FIELD(self, s32*, 0x20) = 0;
            do {
                if (self->unk15 != 0) {
                    x = self->x_pos.u.hi - (s8)SPAD[0x86] - SPAD[0x88];
                } else {
                    x = self->x_pos.u.hi + (s8)SPAD[0x86] - SPAD[0x88];
                }
                if (func_80030CCC(
                        self, x - i,
                        (s16)(self->y_pos.u.hi + (s8)SPAD[0x87] - SPAD[0x89]) -
                            1,
                        x) &
                    0xFF) {
                    if (i != 0) {
                        SPAD[0x88] += i - 1;
                    }
                    M2C_FIELD(self, s32*, 0x24) = 0x38000;
                    self->unk5 = 0xA;
                    SPAD[0x8A] |= 1;
                    self->unk15 = 0;
                    break;
                }
                if ((u8)i == 4) {
                    self->unk5 = 2;
                    M2C_FIELD(self, s32*, 0x28) = 0;
                    M2C_FIELD(self, s32*, 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
                i++;
            } while (i < 5);
            func_800EC7A0(self);
        } else if (SPAD[0x8A] & 1) {
            SPAD[0x88] = D_800FB26C[0xCCA];
            SPAD[0x8A] &= 0xFE;
        }
    }
    func_8002D2B0(self);
}
