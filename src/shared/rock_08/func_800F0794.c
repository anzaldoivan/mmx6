#include "common.h"
#include "mmx6/x4.h"

#define OB(p, o) (*(s8*)((u8*)(p) + (o)))
#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))
#define OP(p, o) (*(void**)((u8*)(p) + (o)))

void* func_8002C458();
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;
#define ENG(o) (((u8*)&g_playthrough_state)[o])

void func_800F0794(void* self) {
    void* child;
    s32 v;
    s32 t;
    // !FAKE: depin: dropping it breaks the match (107/136)
    register s32 one asm("$17");
    // !FAKE: depin: dropping it breaks the match (128/136)
    register s32 e1 asm("$3");
    u8* e3;

    if (--OH(self, 0x7C) == 0) {
        child = func_8002C458();
        if (child != 0) {
            OUB(child, 0) = 0x41;
            OUB(child, 1) = 0xE;
            {
                u8 b = OUB(self, 0x88);
                OUB(self, 0x9A) = b;
                OUB(child, 2) = b;
            }
            OUB(child, 0x14) = OUB(self, 0x14);
            OW(child, 8) = OW(self, 8);
            OW(child, 0xC) = OW(self, 0xC);
            {
                u8 d = OUB(self, 0x15);
                OP(child, 0x7C) = self;
                OUB(child, 7) = 0;
                OUB(child, 0x15) = d;
            }
            one = 1;
            e1 = (s32)&g_playthrough_state;
            if (((u8*)e1)[0x68] >= 2) {
                s32 c = OB(self, 0x88);
                if (c == one) {
                    if (!(random_byte() & 0xF)) {
                        OUB(child, 7) = one;
                        OUB(self, 0x8B) = one;
                    }
                } else {
                    if (c == 2) {
                        t = (u32)(random_byte() & 0xF) < 2;
                    } else if (c == 3) {
                        t = (u32)(random_byte() & 0xF) < 3;
                    } else {
                        t = (u32)(random_byte() & 0xF) < 4;
                    }
                    if (t) {
                        OUB(child, 7) = one;
                        OUB(self, 0x8B) = one;
                    }
                }
            }
        }
        e1 = (s32)&g_playthrough_state;
        v = (s8)((u8*)e1)[0x8C] / 2;
        if (OB(self, 0x5C) < v) {
            if ((u32)(random_byte() & 0xF) < 9) {
                OUB(self, 5) = 4;
            } else {
                OUB(self, 5) = 0xB;
            }
            if (OB(self, 0x8A) == 0) {
                e3 = (u8*)&g_playthrough_state;
                if (e3[0x68] >= 2) {
                    s32 g = OB(self, 0x88);
                    if (g == 3) {
                        goto zero;
                    }
                    if (g == 4) {
                        OUB(self, 0x87) = 3;
                    }
                } else {
                    s32 h = OB(self, 0x88);
                    if (h == 3) {
                    zero:
                        OUB(self, 0x87) = 0;
                    } else if (h == 4) {
                        OUB(self, 0x87) = h;
                    }
                }
                OUB(self, 0x8A) = 1;
            }
        } else {
            OUB(self, 5) = 4;
        }
        OUB(self, 6) = 0;
    }
}
