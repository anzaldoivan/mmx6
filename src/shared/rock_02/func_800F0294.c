#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8003D330();
s32 func_80040498();
extern u8 D_800CCF5C;
#define D_800CCF5C (*(s8*)&D_800CCF5C)

void func_800F0294(void* arg0) {
    s32 lim;
    // !FAKE: depin: dropping it breaks the match (54/59)
    register s32 hp asm("$3");

    if (func_80040498() != 0) {
        func_8002CCB0(arg0, 0xA0, 0xA0);
        return;
    }
    hp = M2C_FIELD(arg0, s8*, 0x5C);
    lim = D_800CCF5C;
    if (hp < lim) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            play_sound(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7C) = 3;
        }
        M2C_FIELD(arg0, s8*, 0x5C)++;
        func_8002CCB0(arg0, 0xA0, 0xA0);
        return;
    }
    func_8003D330(lim);
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 5) = 4;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
#undef D_800CCF5C
