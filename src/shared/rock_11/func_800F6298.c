#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_800FA72C(M2C_UNK, void*);
extern struct X4_EngineObj g_playthrough_state;
extern s8* D_800FDA74;
extern u32 D_800FDA84;

void func_800F6298(void* arg0) {
    struct X4_EngineObj* eng;

    M2C_FIELD(arg0, u8*, 0x3) = 0;
    if (D_800FDA74[0] != 0) {
        if (D_800FDA74[7] == 0) {
            if ((s16)--M2C_FIELD(arg0, u16*, 0x7E) == -1) {
                M2C_FIELD(arg0, u16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        eng = &g_playthrough_state;
        M2C_FIELD(arg0, s32*, 0x80) = 0;
        M2C_FIELD(arg0, s32*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x88) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        M2C_FIELD(arg0, s32*, 0x90) = 0;
        M2C_FIELD(arg0, s32*, 0x94) = 0;
        eng->enable_boss = 0;
        eng->boss_ptr = 0;
        if (eng->stage != 0xC) {
            if (D_800FDA84 < 0x1519) {
                func_800FA72C(0x10, eng);
            } else {
                func_800FA72C(0x11, eng);
            }
        } else {
            eng->unkF = -0x80;
            M2C_FIELD(eng, u8*, eng->checkpoint + 0x2C) = 1;
            eng->checkpoint += 8;
        }
        clear_object_slot(arg0);
    }
}
