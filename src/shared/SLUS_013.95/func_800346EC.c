#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80013008(void);
M2C_UNK func_8001750C(M2C_UNK, M2C_UNK);
void func_800186A8();
M2C_UNK func_80025FB0();

extern s32 D_8008EC0C;
extern s8 D_80097424;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCED1;
extern s8 D_800E3140;
extern u8 D_800E3141;

void func_800346EC(u8* self) {
    if (D_80097424 == 0) {
        if (*(s32*)(self + 0x38) == 0) {
            D_800CCED1 = 0;
            self[4] = 0;
            self[5] = 0;
        } else {
            s8* e = (s8*)&D_800CCED0;
            D_800E3140 = 2;
            e[0x10] = 0;
            e[0x11] = 0;
            e[0x12] = 0;
            e[0x13] = 0;
            e[0x14] = 0;
            e[0x15] = 0;
            e[0x16] = 0;
            e[0x17] = 0;
            D_8008EC0C = 0;
            D_800E3141 = e[0xC];
            self[4] = 0;
            self[5] = 0;
            func_8001750C(0xFF, 0);
            func_800186A8();
            func_80013008();
            D_8008EC0C = 0;
            D_800CCED0.state = 0xB;
            e[1] = 0;
            e[2] = 0;
            if ((u8)e[0x66] < 3U) {
                s8* q = e + 0xD2;
                if (*(s16*)(q + e[0x38] * 2) >= 0xBB8) {
                    D_800CCED0.state = 0x13;
                    e[0x1D] = 5;
                    e[1] = 0;
                    e[2] = 0;
                    e[3] = 0;
                }
            }
        }
    }
    if (*(s32*)(self + 0x38) == 0) {
        func_80025FB0();
    }
}
