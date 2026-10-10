#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002C9B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F54B8(s32, void*);
extern struct X4_EngineObj D_800CCED0;
extern u32 D_800F7840;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F18C4(void* arg0) {
    void* parent;

    parent = P(arg0, 0x80);
    UB(arg0, 3) = 0;
    if (SB(parent, 0) != 0) {
        if (SB(parent, 7) == 0) {
            if ((s16)--UH(arg0, 0x7E) == -1) {
                UH(arg0, 0x7E) = 5;
                UH(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        P(arg0, 0x80) = NULL;
        W(arg0, 0x84) = 0;
        W(arg0, 0x88) = 0;
        W(arg0, 0x8C) = 0;
        W(arg0, 0x90) = 0;
        W(arg0, 0x94) = 0;
        D_800CCED0.enable_boss = 0;
        D_800CCED0.boss_ptr = NULL;
        if (D_800CCED0.stage != 0xC) {
            if (D_800F7840 < 0x1519) {
                func_800F54B8(0x10, &D_800CCED0);
            } else {
                func_800F54B8(0x11, &D_800CCED0);
            }
        } else {
            D_800CCED0.unkF = -0x80;
            D_800CCED0.character_state.bytes[D_800CCED0.checkpoint + 6] = 1;
            D_800CCED0.checkpoint += 8;
        }
        func_8002C9B0(arg0);
    }
}
