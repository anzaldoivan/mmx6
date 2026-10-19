#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK func_8002B838();
void func_800E9FB4();
void func_800E9FDC(void);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_80097424;

void func_800FA63C(s8* arg0) {
    s32 i;
    s8* p;

    if (D_80097424 == 0) {
        func_800E9FB4();
        func_800E9FDC();
        func_8001D218();
        D_800971F8[0].unk3 = 0;
        D_800971F8[1].unk3 = 0;
        D_800971F8[2].unk3 = 0;
        func_8002B838();
        i = 0xF;
        p = arg0 + 0x35;
        do {
            *p = 0;
            i--;
            p--;
        } while (i >= 0);
        *arg0 = 0x15;
    }
}
