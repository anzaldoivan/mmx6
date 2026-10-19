#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;

void func_800F8FB4(void* arg0) {
    void* temp_v1;

    temp_v1 = M2C_FIELD(arg0, void**, 0x80);
    M2C_FIELD(arg0, s8*, 3) = 0;
    if (M2C_FIELD(temp_v1, s8*, 0) != 0) {
        if (M2C_FIELD(temp_v1, s8*, 7) == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        s32 y;
        D_800CCED0.unkF = 0x10;
        D_800CCED0.enable_boss = 0;
        D_800CCED0.boss_ptr = 0;
        y = D_800971F8[0].y_pos.u.hi;
        D_800971F8[0].unk2A = y;
        func_8002C9B0(arg0);
    }
}
