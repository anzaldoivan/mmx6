#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
void* func_8002C3F8();

void func_80053578(u8* arg0) {
    u8* temp_v0;

    if (((u32)((u8)D_800CCED0.stage - 1) < 8U) &&
        ((D_800CCED0.unk60 >> (D_800CCED0.stage - 1)) & 1)) {
        D_800CCED0.unkF = 1;
        return;
    }
    temp_v0 = ((u8 * (*)()) func_8002C3F8)();
    if (temp_v0 != 0) {
        temp_v0[0] = 1;
        temp_v0[1] = 4;
        *(u8**)(arg0 + 0x14) = temp_v0;
    }
    *(s16*)(arg0 + 0x18) = 0;
    arg0[0x1A] = 5;
    arg0[0x1B] = 0;
    arg0[0x1C] = 0;
    arg0[4]++;
}
