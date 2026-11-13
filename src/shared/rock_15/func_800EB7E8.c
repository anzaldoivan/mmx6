#include "common.h"

#define FS(p, T, o) (*(T*)((u8*)(p) + (o)))

s32 func_800179A4(void*, s32);
void func_800EC774(struct X4_VisualObj*);

extern s32 D_8007433C;
extern u8 D_800F61E8[];
extern u8 D_800F61F0[];

void func_800EB7E8(u8* self) {
    u8* parent;
    s8 kind;

    FS(self, u8, 0x04)++;
    FS(self, s8, 0x03) = 1;
    FS(self, s8, 0x5C) = 1;
    FS(self, s8, 0x60) = 6;
    FS(self, s32, 0x50) = (s32)D_800F61E8;
    FS(self, s32, 0x58) = (s32)&D_8007433C;
    FS(self, s32, 0x68) = (s32)D_800F61F0;
    FS(self, s32, 0x54) = (s32)D_800F61E8;
    kind = FS(self, s8, 0x02);
    FS(self, s32, 0x20) = 0;
    FS(self, s32, 0x28) = 0;
    FS(self, s32, 0x24) = 0;
    FS(self, s32, 0x2C) = 0;
    FS(self, u16, 0x42) &= 0x7FFF;
    parent = FS(self, u8*, 0x7C);
    if (kind == 0) {
        if (FS(self, u8, 0x15) == 0) {
            FS(self, s16, 0x0A) = FS(parent, s16, 0x0A) - 0x20;
        } else {
            FS(self, s16, 0x0A) = FS(parent, s16, 0x0A) + 0x20;
        }
        FS(self, s16, 0x0E) = FS(parent, s16, 0x0E) - 8;
    } else if (kind == 1) {
        if (FS(self, u8, 0x15) == 0) {
            FS(self, s16, 0x0A) = FS(parent, s16, 0x0A) - 0x1D;
        } else {
            FS(self, s16, 0x0A) = FS(parent, s16, 0x0A) + 0x1D;
        }
        FS(self, s16, 0x0E) = FS(parent, s16, 0x0E) + 0xE;
    } else {
        if (FS(self, u8, 0x15) == 0) {
            FS(self, s16, 0x0A) = FS(parent, s16, 0x0A) - 0xC;
        } else {
            FS(self, s16, 0x0A) = FS(parent, s16, 0x0A) + 0xC;
        }
        FS(self, s16, 0x0E) = FS(parent, s16, 0x0E) + 0x12;
    }
    func_800179A4(self, 3);
    func_800EC774(self);
    FS(self, s32, 0x84) = 0x10;
    FS(self, s32, 0x8C) = 0;
}
#undef FS
