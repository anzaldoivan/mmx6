#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80013300(M2C_UNK, M2C_UNK*);
M2C_UNK func_800133A0();
M2C_UNK func_8002B838();
extern s32 D_8001E6E4;
extern u8 D_8006D620;
extern struct X4_EngineObj D_80097420;
extern struct X4_EngineObj D_800CCED0;

void func_800ED7C4(u8* arg0) {
    s8* e = (s8*)&D_80097420;

    if (e[4] == 0) {
        func_8002B838();
        D_8006D620 = e[7];
        if (arg0[0x158] == 0xFF) {
            D_800CCED0.state = 3;
            D_800CCED0.unk1 = 0;
            D_800CCED0.unk2 = 0;
            D_800CCED0.unk3 = 0;
        } else {
            D_800CCED0.state = 0x13;
            D_800CCED0.unk1 = 0;
            D_800CCED0.unk2 = 0;
            D_800CCED0.unk3 = 0;
            ((u8*)&D_800CCED0)[0x1D] = ((u8*)&D_800CCED0)[0x158];
        }
        func_80013300(1, &D_8001E6E4);
        func_800133A0();
    }
}
