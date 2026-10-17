#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(M2C_UNK);
void func_80020C40(void);
M2C_UNK func_8003DF58(void*);
M2C_UNK func_8003F0BC(void*);
M2C_UNK func_8003F480();
M2C_UNK func_8003F58C();
M2C_UNK func_801ECBE8();

extern struct X4_PlayerObj D_800970A0;
extern u8 D_800C4560;
extern u8 D_800E4430;
#define D_800E4430 (*(s8*)&D_800E4430)

void func_80034CD0(u8* arg0) {
    struct X4_PlayerObj* pl;

    pl = &D_800970A0;
    if (*(void**)(arg0 + 0x38) == 0) {
        if (pl->unk2 == 0) {
            func_8003F58C();
            if (D_800E4430 != pl->weapon) {
                *(s16*)((u8*)pl + 0x14C) = 2;
                func_8003F480(pl);
            }
            func_8003DF58(pl);
            if (D_800E4430 != pl->weapon) {
                func_8003F0BC(pl);
            }
        } else if (pl->weapon == 4) {
            func_801ECBE8(pl);
        }
        D_800C4560 |= 1;
        func_80020C40();
        {
            struct X4_PlayerObj* p = &D_800970A0;
            *(s16*)((u8*)p + 0x14C) = 0;
        }
        func_800139A0(0x20);
    }
    arg0[5] = 3;
}
#undef D_800E4430
