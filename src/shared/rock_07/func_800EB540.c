#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800F86CC[])(void*);

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define BG ((u8*)&background_objects[0])

void func_800EB540(u8* self) {
    u8* bg;
    s32 t;

    D_800F86CC[S8(self, 0x5)](self);
    bg = BG;
    U16(self, 0xA) = U16(self, 0x82) + (U16(bg, 0xA) + U16(bg, 0x5E));
    t = U16(bg, 0xE) + 0x3B8;
    t -= U16(bg, 0x62);
    U16(self, 0xE) = U16(self, 0x86) + t;
}

#undef S8
#undef U16
#undef BG
