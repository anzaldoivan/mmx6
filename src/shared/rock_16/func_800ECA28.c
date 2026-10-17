#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002B838();
void func_8002C2B8();
void func_80029B8C(void);
void func_800280F4(void);
M2C_UNK func_80025F34();
M2C_UNK func_80066150(M2C_UNK);
M2C_UNK func_800663FC(M2C_UNK*, M2C_UNK*);
void func_8006645C(M2C_UNK*, M2C_UNK*);

extern s8 D_80097428;
extern M2C_UNK* D_800B91B8;
extern u8 D_800CC868;
extern M2C_UNK D_800F0EE4;
extern u8 D_800F1CB6;
extern u8 D_800F1CB7;

#define SCRATCH_44 (*(M2C_UNK**)0x1F800044)

void func_800ECA28(u8* arg0) {
    u8* p;
    u32 i;

    D_80097428 = 0;
    i = 0;
    p = arg0 + 0x26;
    do {
        p[i] = 0;
        i++;
    } while (i < 0x10);
    arg0[0x1F] = 0;
    arg0[0x24] = 0;
    *(s16*)(arg0 + 8) = 0;
    *(s16*)(arg0 + 0xA) = 0;
    func_8002B838(p);
    func_8002C2B8();
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    D_800F1CB6 = 0;
    D_800F1CB7 = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    D_800CC868 = 0;
    arg0[1] = 1;
    func_8006645C(&D_800F0EE4, D_800B91B8);
    func_80066150(0);
    func_800663FC(&D_800F0EE4, SCRATCH_44);
    func_80066150(0);
}
