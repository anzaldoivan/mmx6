#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_8002C9B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;

void func_800F1F50(void* arg0) {
    s8* p;

    M2C_FIELD(arg0, s8*, 3) = 0;
    p = M2C_FIELD(SPAD4C, s8**, 0x80);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        if (D_800CCED0.stage != 0xC) {
            D_800CCED0.unkF = 0x10;
        } else {
            D_800CCED0.unkF = -0x80;
            D_800CCED0.character_state.bytes[D_800CCED0.checkpoint + 6] = 1;
            D_800CCED0.checkpoint += 9;
        }
        {
            register s32 t3 asm("$5");
            D_800CCED0.enable_boss = 0;
            D_800CCED0.boss_ptr = 0;
            t3 = D_800971F8[0].y_pos.u.hi;
            D_800971F8[0].unk2A = t3;
            func_8002C9B0(arg0, t3);
        }
    }
}
