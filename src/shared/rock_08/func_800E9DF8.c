#include "common.h"
#include "mmx6/x4.h"

void func_800328B0();
extern struct X4_PlayerObj D_800970A0;
extern u16 D_800F4C7C[];

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(u16**)((u8*)(p) + (o)))

void func_800E9DF8(void* self) {
    u16* r = P(self, 0x3C);
    u16 a = UH(self, 0x40);
    u16 v = UH(self, 0x42);
    u16 x = r[0];
    u16 w = r[2];
    u16 y = r[1];
    u16 h = r[3];
    s16 x0, x1, y0, y1;
    s32 i;

    UH(self, 0x40) = a + v;
    x0 = x - w;
    x1 = x + w;
    y0 = y - h;
    y1 = y + h;
    if ((u16)(UH(self, 0x40) + 0x80) > 0x100) {
        s32 t = (s16)v;
        H(self, 0x42) = -t;
    }
    if (D_800970A0.x_pos.i.hi < x0 || x1 < D_800970A0.x_pos.i.hi ||
        D_800970A0.y_pos.i.hi < y0 || y1 < D_800970A0.y_pos.i.hi) {
        if (--W(self, 0x38) < 0) {
            W(self, 0x38) = 0;
            H(self, 0x34) = 0;
            return;
        }
    } else {
        if (++W(self, 0x38) >= 0x40) {
            W(self, 0x38) = 0x3F;
        }
    }
    i = SB(self, 2);
    if (i >= 0x40) {
        H(self, 0x1A) = -0xEF;
        H(self, 0x1E) = 0x100;
        H(self, 0x22) = -0xEF;
        H(self, 0x26) = 0x100;
        H(self, 0x2A) = 0;
        H(self, 0x2E) = 0;
        H(self, 0x32) = 0;
        H(self, 0x16) = UH(self, 0x40) + 0x78;
    } else if (i >= 0x30) {
        H(self, 0x16) = -0x100;
        H(self, 0x1A) = -0xEF;
        H(self, 0x22) = -0xEF;
        H(self, 0x26) = 0;
        H(self, 0x2A) = 0;
        H(self, 0x2E) = -0x100;
        H(self, 0x32) = 0;
        H(self, 0x1E) = UH(self, 0x40) - 0x78;
    } else if (i >= 0x20) {
        H(self, 0x16) = 0;
        H(self, 0x1A) = 0;
        H(self, 0x1E) = 0x100;
        H(self, 0x22) = 0;
        H(self, 0x26) = 0x100;
        H(self, 0x2A) = 0xEF;
        H(self, 0x2E) = UH(self, 0x40) + 0x78;
        H(self, 0x32) = 0xEF;
    } else if (i >= 0x10) {
        H(self, 0x16) = -0x100;
        H(self, 0x1A) = 0;
        H(self, 0x1E) = 0;
        H(self, 0x22) = 0;
        H(self, 0x2A) = 0xEF;
        H(self, 0x2E) = -0x100;
        H(self, 0x32) = 0xEF;
        H(self, 0x26) = UH(self, 0x40) - 0x78;
    }
    UH(self, 0x34) = D_800F4C7C[W(self, 0x38) / 4];
    func_800328B0(self);
}
