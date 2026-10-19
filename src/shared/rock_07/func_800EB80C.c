#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80025FD8();
extern s8 D_800970A5;
extern s8 D_80097298;
extern struct X4_EngineObj D_800CCED0;

void func_800EB80C(void* arg0) {
    if (D_800970A5 == 0x14) {
        D_80097298 = 1;
        D_800CCED0.enable_boss = 1;
        D_800CCED0.unk25 = 0;
        D_800CCED0.boss_ptr = arg0;
        M2C_FIELD(&D_800CCED0, s8*, 0x8C) = 0x30;
        func_80025FD8(0);
        {
            // !FAKE: pin the increment temp to the register retail uses
            register s32 t asm("$3") = M2C_FIELD(arg0, u8*, 0x6) + 1;
            M2C_FIELD(arg0, u8*, 0x6) = t;
        }
    }
}
