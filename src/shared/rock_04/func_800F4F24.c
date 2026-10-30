#include "common.h"

s32 random_byte();
extern u8 D_800F6FB0[];
extern u8 D_800F7030[];

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F4F24(void* arg0) {
    s8 kind;
    s8 r;
    // !FAKE: depin: dropping it breaks the match (27/43)
    register u8* tbl asm("$2");

    if (--H(arg0, 0x7C) == 0) {
        H(arg0, 0x88) = 0x28;
        UB(arg0, 6) = 0;
        r = random_byte() & 0xF;
        kind = SB(arg0, 0x8A);
        UB(arg0, 0x8B) = r;
        UB(arg0, 0x8C) = 0;
        switch (kind) {
        case -1:
        case 0:
            tbl = D_800F6FB0;
            goto set;
        case 1:
            tbl = D_800F7030;
        set: {
            // !FAKE: depin: dropping it breaks the match (41/43)
            register s32 b asm("$4") = tbl[r * 8];
            UB(arg0, 5) = b;
        } break;
        }
        UB(arg0, 0x8C)++;
    }
}
