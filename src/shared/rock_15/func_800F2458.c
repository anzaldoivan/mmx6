#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002C9B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F0A78(void* arg0);
extern struct X4_EngineObj D_800CCED0;

void func_800F2458(void* arg0) {
    s8* p;

    p = M2C_FIELD(arg0, s8**, 0x80);
    M2C_FIELD(arg0, u8*, 3) = 0;
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
                func_800F0A78(arg0);
                M2C_FIELD(arg0, s32*, 0x8C) = 3;
            }
            if (M2C_FIELD(arg0, s32*, 0x90) == 0) {
                // !FAKE: depin: dropping it breaks the match (69/71)
                register s32 t asm("$2");

                func_80029478(0xA, 4, 2);
                t = 0xA;
                M2C_FIELD(arg0, s32*, 0x90) = t;
            }
            M2C_FIELD(arg0, s32*, 0x90)--;
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        s8* e = (s8*)&D_800CCED0;

        M2C_FIELD(arg0, void**, 0x80) = 0;
        M2C_FIELD(arg0, s32*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x88) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        M2C_FIELD(arg0, s32*, 0x90) = 0;
        M2C_FIELD(arg0, s32*, 0x94) = 0;
        M2C_FIELD(e, u8*, 0x24) = 0;
        M2C_FIELD(e, s32*, 0x20) = 0;
        M2C_FIELD(e, u8*, 0xF) = 0x10;
        func_8002C9B0(arg0);
    }
}
