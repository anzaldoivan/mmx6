#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 random_byte();
extern s8 D_800970A2;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F7BA0[][6];
extern u16* D_800F7DF0;
extern s32 D_800F7E04;
extern s32 D_800F7E08;

void func_800EFD38(void* arg0) {
    u32 r;
    u8 frame;

    {
        struct X4_EngineObj* e = &g_playthrough_state;
        if (M2C_FIELD(arg0, s8*, 0x5C) <
            (s8)((s8)M2C_FIELD(e, u8*, 0x8C) / 3)) {
            D_800F7DF0 = (u16*)&D_800F7E08;
        } else if (M2C_FIELD(arg0, s8*, 0x5C) <
                   (s8)M2C_FIELD(e, u8*, 0x8C) * 2 / 3) {
            D_800F7DF0 = (u16*)&D_800F7E04;
        }
    }
    r = random_byte();
    M2C_FIELD(arg0, u8*, 0x87) = 0;
    r &= 0xF;
    if (D_800970A2 == 0) {
        struct X4_EngineObj* e = &g_playthrough_state;
        if ((s8)M2C_FIELD(e, u8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 2;
            }
        } else if (r < 4) {
            M2C_FIELD(arg0, u8*, 0x86) = 0;
        } else if (r < 12) {
            M2C_FIELD(arg0, u8*, 0x86) = 4;
        } else {
            M2C_FIELD(arg0, u8*, 0x86) = 5;
        }
    } else {
        struct X4_EngineObj* e = &g_playthrough_state;
        if ((s8)M2C_FIELD(e, u8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 1;
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 3;
            }
        } else if (r < 4) {
            M2C_FIELD(arg0, u8*, 0x86) = 1;
        } else if (r < 12) {
            M2C_FIELD(arg0, u8*, 0x86) = 4;
        } else {
            M2C_FIELD(arg0, u8*, 0x86) = 5;
        }
    }
    frame =
        D_800F7BA0[M2C_FIELD(arg0, u8*, 0x86)][M2C_FIELD(arg0, u8*, 0x87)++];
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = frame;
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
