#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800133A0();
void func_800139F4(s32);
void func_80016B3C();
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_8001D218();
void func_8001D25C(void);
void func_8001F5A0(void*, s32);
void func_8001FB90(u8* t, s16 arg1);
M2C_UNK func_8002AA74();
void func_8002C1DC();
M2C_UNK func_800660B8(M2C_UNK);
extern M2C_UNK D_800711F4;
extern s32 D_80071200;
extern s32 D_80097420;
extern u16 D_800C4570;

void func_8001FD10(u8* arg0) {
    u8* g = (u8*)&D_80097420;
    s8 v;

    if (*(s8*)(g + 4) != 0) {
        return;
    }
    if (*(s32*)(arg0 + 0x34) == 0) {
        func_8001F5A0(g + 7, 1);
        if (D_800C4570 & 0x40) {
            func_80016C48(0, 0x22, 0);
            if (g[7] == 0) {
                func_800139F4(0x20);
                v = 2;
                goto set;
            }
            *(s32*)(arg0 + 0x34) = 1;
            func_8002AA74();
            g[7] = 1;
            func_8001FB90((u8*)&D_80071200, 0x78);
        }
    } else {
        func_8001F5A0(g + 7, 1);
        if (D_800C4570 & 0x40) {
            func_80016C48(0, 0x22, 0);
            *(s32*)(arg0 + 0x34) = 0;
            if (g[7] == 0) {
                arg0[7] = 0;
                func_800660B8(0);
                func_8001D218();
                func_80016B3C();
                func_8002C1DC();
                func_8001D25C();
                func_800133A0();
                return;
            }
            func_8002AA74();
            g[7] = 0;
            func_8001FB90((u8*)&D_800711F4, 0x78);
            arg0[7] = 1;
            return;
        set:
            arg0[7] = v;
        }
    }
}
