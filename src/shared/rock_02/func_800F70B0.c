#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F70B0(void* arg0) {
    func_800179A4(arg0, 2);
    {
        register s32 t asm("$4") = D_800971F8[0].unk1E - 0x140;
        if (D_800971F8[0].unk1E + (D_800971F8[0].unk1C - t) / 2 <
            *(s16*)((u8*)arg0 + 0xA)) {
            *(s32*)((u8*)arg0 + 0x20) = 0xFFFC0000;
        } else {
            *(s32*)((u8*)arg0 + 0x20) = 0x40000;
        }
    }
    ((u8*)arg0)[7] = 0;
    *(s32*)((u8*)arg0 + 0x24) = 0;
    ((u8*)arg0)[6] += 1;
}
