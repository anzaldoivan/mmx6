#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F1CF9;

void func_800EDD90(void* arg0) {
    s8 v;
    s8 r;

    if (D_800F1CF9 != 0) {
        v = D_800CCED0.character_state.bytes[1];
        if (v == 8) {
            if (((u8*)&D_800CCED0)[0x66] == 3) {
                r = 8;
            } else if (((u8*)&D_800CCED0)[0x66] == 4) {
                r = 9;
            } else {
                r = 0xA;
            }
        } else {
            r = v;
        }
        ((void (*)(void*, s32, s8))func_800179D0)(arg0, 3, r);
        func_8002CB50(arg0);
        return;
    }
    ((u8*)arg0)[3] = 0;
}
