#include "common.h"
#include "mmx6/x4.h"

s32 func_8002E47C(struct X4_PlayerObj* a, struct X4_PlayerObj* b);
s32 func_80032208(struct X4_MainObj* self, struct X4_PlayerObj* tgt);
void func_80032C88(void*, void*);
extern u8 g_projectiles[];
extern s8 D_800950A0[];

#define W8(p, o) (*(s8*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define W32(p, o) (*(u32*)((u8*)(p) + (o)))

void func_8003208C(void* a0) {
    u8* arg0 = a0;
    // !FAKE: depin: dropping it breaks the match (71/95)
    register s32 bit asm("$17");
    u8* p;
    u32 i;

    bit = 1;
    if (S32(arg0, 0x68) != 0) {
        i = 0;
        p = g_projectiles;
        do {
            if (W8(p, 0) != 0 && W8(p, 0x9D) != 0) {
                func_80032208(arg0, (void*)p);
                if (W32(arg0, 0x90) & bit) {
                    func_80032C88(arg0, p);
                }
                if (func_8002E47C(arg0, (void*)p) == 8) {
                    W32(arg0, 0x90) |= bit;
                } else {
                    W32(arg0, 0x90) &= ~bit;
                }
            } else {
                W32(arg0, 0x90) &= ~bit;
            }
            p += 0xA0;
            i++;
            bit <<= 1;
        } while (i < 0x20);
        bit = 1;
        i = 0;
        p = (u8*)D_800950A0;
        do {
            if (W8(p, 0) != 0 && W8(p, 0x9D) != 0) {
                func_80032208(arg0, (void*)p);
                if (W32(arg0, 0x94) & bit) {
                    func_80032C88(arg0, p);
                }
                if (func_8002E47C(arg0, (void*)p) == 8) {
                    W32(arg0, 0x94) |= bit;
                } else {
                    W32(arg0, 0x94) &= ~bit;
                }
            } else {
                W32(arg0, 0x94) &= ~bit;
            }
            p += 0xA0;
            i++;
            bit <<= 1;
        } while (i < 0x20);
    }
}
