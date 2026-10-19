#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_8003D9F8(void* arg0);

void func_8003D954(u8* arg0) {
    if (--((s8*)arg0)[0xD7] == 0) {
        D_800CCED0.unk12 = 0;
        D_800CCED0.unk13 = 0;
        D_800CCED0.unk14 = 0;
        D_800CCED0.unk15 = 0;
        D_800CCED0.unk16 = 0;
        D_800CCED0.unk17 = 0;
        D_800CCED0.unk18 = 0;
        D_800CCED0.unk19 = 0;
        D_800CCED0.unk1A = 0;
        arg0[3] = 0;
        func_80016C48(3, 0x10, arg0);
        func_80016C48(3, 0xE, arg0);
        arg0[0xD7] = 0;
        arg0[0xD6] = 0;
        arg0[5]++;
        func_8003D9F8(arg0);
    }
}
