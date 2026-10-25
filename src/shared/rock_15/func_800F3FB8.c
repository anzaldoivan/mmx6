#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
void func_800F3824(struct X4_MainObj*);
extern M2C_UNK D_800F6F44;
extern M2C_UNK D_800F6F54;

void func_800F3FB8(u8* arg0) {
    func_80017A04();
    move_object(arg0);
    if (*(s16*)(arg0 + 0xA) <= *(s16*)(arg0 + 0x8C)) {
        func_800F3824((struct X4_MainObj*)arg0);
        func_800179A4(arg0, 1);
        func_80016C48(2, 0x74, arg0);
        *(void**)(arg0 + 0x50) = &D_800F6F54;
        *(void**)(arg0 + 0x54) = &D_800F6F44;
        *(s16*)(arg0 + 0x8C) = 0;
        *(s8*)(arg0 + 7) = -1;
        arg0[6]++;
    }
}
