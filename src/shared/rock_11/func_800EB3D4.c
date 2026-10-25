#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EB3D4(struct X4_BaseObj* self) {
    s32 i;
    s16 x;
    u8 flags;

    flags = *((u8*)self + 0x70);
    if (flags & 2) {
        *(s32*)((u8*)self + 0x20) = 0;
        *(s32*)((u8*)self + 0x24) = 0xFFFC8000;
        self->unk5 = 4;
        self->unk15 = 0;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 4)) {
            *(s32*)((u8*)self + 0x20) = 0;
            for (; i < 5; i++) {
                if (self->unk15 != 0) {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi - (s8)sp[0x86] + sp[0x88];
                } else {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi + (s8)sp[0x86] + sp[0x88];
                }
                {
                    u8* sp = SPAD;
                    if (func_80030CCC(
                            self, x + i,
                            (s16)(self->y_pos.i.hi + (s8)sp[0x87] - sp[0x89]) -
                                1,
                            x) &
                        0xFF) {
                        u8* p = SPAD;
                        u8* q;
                        p[0x88] += i;
                        *(s32*)((u8*)self + 0x24) = 0x38000;
                        self->unk5 = 6;
                        q = SPAD;
                        q[0x8A] |= 1;
                        self->unk15 = 0x40;
                        break;
                    }
                }
                if ((i & 0xFF) == 4) {
                    self->unk5 = 2;
                    *(s32*)((u8*)self + 0x28) = 0;
                    *(s32*)((u8*)self + 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
            }
            func_800EC7A0(self);
        } else {
            u8* p = SPAD;
            if (p[0x8A] & 1) {
                u8* q;
                p[0x88] = D_800FB26C[0xCCA];
                q = SPAD;
                q[0x8A] &= 0xFE;
            }
        }
    }
    move_object(self);
}
