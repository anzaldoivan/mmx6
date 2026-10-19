#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F5164(void* arg0) {
    s16 y;

    func_80017A04();
    func_8002D2B0((s32)arg0);
    y = M2C_FIELD(arg0, s16*, 0xA);
    if (y < D_800971F8[0].unk26 - 0x50 || D_800971F8[0].unk24 + 0x190 < y) {
        M2C_FIELD(arg0, u8*, 0x4) = 2;
    }
}
