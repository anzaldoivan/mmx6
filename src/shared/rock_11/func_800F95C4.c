#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_800FA150(void*, s32);
extern s16 D_800970AA;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800E9B8C[];
extern s8 D_800FD2EC[];
extern u16 D_800FDA7C;
#define D_800FDA7C (*(s16*)&D_800FDA7C)

void func_800F95C4(void* arg0) {
    s8 buf[4];
    s8 t;

    __builtin_memcpy(buf, D_800E9B8C, 4);
    func_800179A4(arg0, 8);
    if (D_800FDA7C <
        (t = D_800FD2EC[(u8)D_800CCED0.player_initial_data[0x46]])) {
        if ((func_8002D2D4() & 0xF) >=
            buf[(u8)D_800CCED0.player_initial_data[0x46]]) {
            func_800FA150(arg0, 1);
        }
    }
    if (*(s16*)((u8*)arg0 + 0xA) < D_800970AA) {
        *((u8*)arg0 + 0x15) = 0x40;
        *(s32*)((u8*)arg0 + 0x20) = 0xFFFB0000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    } else {
        *((u8*)arg0 + 0x15) = 0;
        *(s32*)((u8*)arg0 + 0x20) = 0x50000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    }
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *((u8*)arg0 + 6) += 1;
}
#undef D_800FDA7C
