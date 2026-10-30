#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_EffectObj* alloc_class3_slot(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800970A5;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F6AF8;

void func_800F2A88(void* arg0) {
    s32 temp_v1;
    u8* temp_v0;

    if ((g_playthrough_state.unkF == 0) && (D_800970A5 == 0x14)) {
        if (g_playthrough_state.stage != 0xC) {
            M2C_FIELD(arg0, s16*, 0x7C) = 0x64;
        } else {
            background_objects[0].unk2A = 0xD0;
            M2C_FIELD(arg0, s16*, 0x7C) = 0xA;
        }
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, u8*, 0x86) = background_objects[0].unk48;
        background_objects[0].unk48 = 1;
        background_objects[0].unk47 = 2;
        temp_v1 = (u16)D_800F6AF8 + 0x660;
        background_objects[0].unk26 = temp_v1;
        background_objects[0].unk24 = temp_v1;
        temp_v0 = (u8*)alloc_class3_slot();
        if (temp_v0 != 0) {
            temp_v0[0] = 1;
            temp_v0[1] = 0x18;
            M2C_FIELD(arg0, void**, 0x8C) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
