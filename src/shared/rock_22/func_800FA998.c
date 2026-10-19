#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80031DA8();
M2C_UNK func_8003208C();
extern u8 D_80097185;
extern s32 D_800FC948;
extern s32 D_800FC950;

void func_800FA998(s32* arg0) {
    s32* self;
    u8* temp_s1;

    self = arg0;
    temp_s1 = (u8*)self[0x7C / 4];
    self[0x8 / 4] = *(s32*)(temp_s1 + 8);
    self[0xC / 4] = *(s32*)(temp_s1 + 0xC);
    func_8003208C();
    if (D_80097185 == 0) {
        func_80031DA8(self);
    }
    if (((s8*)temp_s1)[3] == 0) {
        self[0x54 / 4] = 0;
        self[0x68 / 4] = 0;
        return;
    }
    self[0x54 / 4] = (s32)&D_800FC950;
    self[0x68 / 4] = (s32)&D_800FC948;
}
