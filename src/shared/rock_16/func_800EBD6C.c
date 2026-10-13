#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80027BA0(s32, s32, s32, void*);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEF9;
extern u8 D_800F0E2C[];
extern u8 D_800F0E44[];

#define PAIR_EBD6C(y, tbl, off)                                                \
    {                                                                          \
        u8* p = tbl;                                                           \
        func_80027BA0(0, 0x270, y, p + off);                                   \
        func_80027BA0(0, 0x870, y, p + off);                                   \
    }

void func_800EBD6C(struct X4_EngineObj* arg0) {
    if (arg0->unk5F & 0x10) {
        if (D_800CCEF9 != 0) {
            PAIR_EBD6C(0x20, D_800F0E2C, 8);
            D_800971F8[0].unk4C = 1;
            PAIR_EBD6C(0x50, D_800F0E44, 0);
            D_800971F8[0].unk4C = 1;
        } else {
            PAIR_EBD6C(0x20, D_800F0E2C, 0);
            D_800971F8[0].unk4C = 1;
            PAIR_EBD6C(0x50, D_800F0E44, 8);
            D_800971F8[0].unk4C = 1;
        }
    }
}

#undef PAIR_EBD6C
