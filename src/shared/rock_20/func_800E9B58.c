#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u16 D_800C4570;
extern s8 D_800CCEF8;
extern u16 D_800F36B0[];
extern u16 D_800F48EC;
#define D_800F48EC (*(s16*)&D_800F48EC)
extern s16 D_800F48EE;
extern s16 D_800F48F0;

void func_800E9B58(struct X4_EngineObj* arg0) {
    extern u8 D_800CCED0[];
    u8* e;

    if (D_800C4570 & 0x8FF) {
        func_80016C48(0, 0x22, 0);
        D_800CCEF8 = D_800F48F0;
        arg0->unk2++;
        return;
    }
    if (--D_800F48EC == 0) {
        e = (u8*)&D_800CCED0;
        e[0x28]++;
        if ((s8)e[0x28] >= D_800F48F0) {
            arg0->unk2++;
            e[0x28] = D_800F48F0;
            return;
        }
        D_800F48EE++;
        D_800F48EC = D_800F36B0[D_800F48EE];
    }
}
#undef D_800F48EC
