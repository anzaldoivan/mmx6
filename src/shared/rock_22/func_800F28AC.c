#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_800F2FB8(void*, u8, s32);
s32 func_800F3158(void*);
s32 func_800F3F38(void*);

void func_800F28AC(struct X4_BaseObj* self) {
    u8* sp;

    sp = SPAD;
    if (sp[0x81] < 2) {
        if (F8(self, 0x46) < 0) {
            s16 a;
            s16 b;
            u16 range;
            s32 d;

            a = F16(self, 0xE);
            b = F16(sp, 0x88);
            range = FU16(sp, 0x84);
            d = a - b;
            if (d >= 0) {
                if (range >= d) {
                    goto call0;
                }
                goto far0;
            }
            if (range >= b - a) {
            call0:
                if (func_800F2FB8(self, SPAD[0x80], 0) != 0) {
                    goto far0;
                }
                goto near;
            }
        far0:
            if (func_800F3F38(self) & 1) {
                self->unk6 = 4;
                if (F32(self, 0x24) < 0) {
                    SPAD[0x80] = 1;
                } else {
                    SPAD[0x80] = 0;
                }
                F32(self, 0x20) = 0;
                F32(self, 0x24) = F32(self, 0x24) * 3;
                func_800179A4(self, 6);
            } else if (func_800F3158(self) != 0) {
                self->unk5 = 4;
                self->unk6 = 0;
            } else {
                self->unk6 = 2;
                func_800179A4(self, 6);
            }
        } else if (F8(self, 0x45) != 0) {
            if (sp[0x80] == 0) {
                F16(self, 0xE) = FU16(self, 0xE) - FU16(sp, 0x8A);
            } else {
                F16(self, 0xE) = FU16(self, 0xE) + FU16(sp, 0x8A);
            }
            F8(self, 0x45) = 0;
        }
    } else {
        if (F8(self, 0x46) < 0) {
            s16 a;
            s16 b;
            u16 range;
            s32 d;

            a = F16(self, 0xA);
            b = F16(sp, 0x86);
            range = FU16(sp, 0x84);
            d = a - b;
            if (d >= 0) {
                if (range >= d) {
                    goto call1;
                }
                goto far1;
            }
            if (range >= b - a) {
            call1:
                if (func_800F2FB8(self, SPAD[0x80], 1) != 0) {
                    goto far1;
                }
                goto near;
            }
            if (0) {
            near:
                if (F16(self, 0x7C) >= 0x3C && func_800F3158(self) != 0) {
                    self->unk5 = 4;
                    self->unk6 = 0;
                }
                func_80017A04(self);
                return;
            }
        far1:
            if (func_800F3F38(self) & 2) {
                self->unk6 = 4;
                if (F32(self, 0x20) >= 0) {
                    self->unk15 = 0x40;
                    SPAD[0x80] = 1;
                } else {
                    self->unk15 = 0;
                    SPAD[0x80] = 0;
                }
                F32(self, 0x24) = 0;
                F32(self, 0x20) = F32(self, 0x20) * 3;
                func_800179A4(self, 5);
            } else if (func_800F3158(self) != 0) {
                self->unk5 = 4;
                self->unk6 = 0;
            } else {
                self->unk6 = 2;
                func_800179A4(self, 5);
            }
        } else if (F8(self, 0x45) != 0) {
            if (sp[0x80] == 0) {
                F16(self, 0xA) = FU16(self, 0xA) - FU16(sp, 0x8A);
            } else {
                F16(self, 0xA) = FU16(self, 0xA) + FU16(sp, 0x8A);
            }
            F8(self, 0x45) = 0;
        }
    }
    func_80017A04(self);
}
