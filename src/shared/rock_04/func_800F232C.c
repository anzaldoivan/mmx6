#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80025FD8();
s32 func_8002B2F8(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s8 D_8009742C;
extern u8 D_800C4560;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CF850;
extern u8 D_800E9B2C[];

void func_800F232C(void* arg0) {
    u8 buf[4];
    s32 i;

    __builtin_memcpy(buf, D_800E9B2C, 4);
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        D_800CCED0.enable_boss = 1;
        D_800CCED0.unk25 = 0;
        D_800CCED0.boss_ptr = arg0;
        func_80025FD8();
        {
            // !FAKE: depin: dropping it breaks the match (73/78)
            register s32 k asm("$3") = M2C_FIELD(&D_800CCED0, u8*, 0x8F);
            M2C_FIELD(&D_800CCED0, s8*, 0x8C) = buf[k] + 0x30;
        }
        func_8002B2F8(0);
        D_80090D56 = 1;
        D_8009742C = 1;
        D_800CF850 = 1;
        D_80090C90[1] = 0xF0000000;
        for (i = 3; i < 15; i++) {
            D_80090C90[i] = -1;
        }
        D_800C4560 |= 1;
        M2C_FIELD(arg0, u16*, 0x7C) = 3;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}
