#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern struct X4_EngineObj D_800CCED0;

void func_800F472C(struct X4_PlayerObj* arg0) {
    if (arg0->unk70 & 8) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x5C, arg0);
        ((void (*)(void*, s32))func_800179A4)(arg0, 7);
        {
            struct X4_EngineObj* e = &D_800CCED0;
            if (e->stage != 0xC) {
                ((void (*)(s32, s32, s32))func_80021760)(
                    0, 0xFF, (u8)e->character_state.bytes[8]);
                e->character_state.bytes[8] = 1;
            }
        }
        arg0->unk6++;
        return;
    }
    func_8002D230(arg0);
}
