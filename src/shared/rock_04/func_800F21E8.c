#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(void*);
s32 func_8002D2D4();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F5360(void*, s32);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800F21E8(void* arg0) {
    move_object(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (79/81)
        register s32 f asm("$2") = UB(arg0, 0x15);
        if (f == 0) {
            if (UB(arg0, 0x70) & 2) {
                goto hit;
            }
            if (SH(arg0, 0xA) <= SH(arg0, 0x84)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) - ((func_8002D2D4() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x12);
            }
        } else {
            if (UB(arg0, 0x70) & 1) {
            hit:
                func_80016C48(2, 0x12, arg0);
                func_80012D9C(8);
                func_800179A4(arg0, 0xB);
                {
                    // !FAKE: depin: dropping it breaks the match (78/81)
                    register s32 c asm("$2") = UB(arg0, 6);
                    UB(arg0, 6) = c + 1;
                }
                return;
            }
            if (SH(arg0, 0xA) >= SH(arg0, 0x84)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) + ((func_8002D2D4() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x12);
            }
        }
    }
    if (--SH(arg0, 0x7C) == 0) {
        UH(arg0, 0x7C) = 8;
        func_800F5360(arg0, 1);
    }
}
