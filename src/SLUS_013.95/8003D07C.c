#include "common.h"
#include "mmx6/x4.h"

s32 scale_damage(u8* arg0, s8 arg1);
extern struct X4_PlayerObj g_Player;
extern s8 D_800CCEEC;

void func_8003D07C(s8 arg0) {
    struct X4_PlayerObj* p = &g_Player;

    *((s8*)p + 0xCA) = -1;
    if (p->hp & 0x7F) {
        if (arg0 != 0) {
            p->hp -= scale_damage((u8*)p, arg0);
        }
        if (p->hp > 0) {
            p->hp |= 0x80;
            return;
        }
        *((s8*)p + 0xCA) = 0;
        D_800CCEEC = 1;
        p->hp = -0x80;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003BA04(void*, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

M2C_UNK func_8003D10C(void* arg0) {
    u8* p = arg0;
    s32 t;
    s32 i = *(s8*)(p + 2);
    u8* e = (u8*)&g_playthrough_state;
    t = (s8)(e - -i)[0x5B] / 3;
    if (*(s8*)(p + 0x5C) >= (s8)t) {
        func_8003BA04(p, 5);
    } else {
        func_8003BA04(p, 6);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CFB0(); /* extern */

void func_8003D18C(void* arg0) {
    s32 var_v0;
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        ((M2C_UNK(*)())func_8002CFB0)();
        return;
    }
    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    if (temp_v1 & 3) {
        if (temp_v1 & 1) {
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            if (!(M2C_FIELD(arg0, u8*, 0x89) & 1)) {
                if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
                    M2C_FIELD(arg0, s32*, 0x20) =
                        (s32)M2C_FIELD(arg0, s32*, 0x108);
                } else {
                    M2C_FIELD(arg0, s32*, 0x20) =
                        (s32)M2C_FIELD(arg0, s32*, 0xF4);
                }
            } else {
                goto block_13;
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x15) = 0;
            if (!(M2C_FIELD(arg0, u8*, 0x89) & 2)) {
                if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
                    var_v0 = -M2C_FIELD(arg0, s32*, 0x108);
                } else {
                    var_v0 = -M2C_FIELD(arg0, s32*, 0xF4);
                }
                M2C_FIELD(arg0, s32*, 0x20) = var_v0;
            } else {
                goto block_13;
            }
        }
    } else {
    block_13:
        M2C_FIELD(arg0, s32*, 0x20) = 0;
    }
    ((M2C_UNK(*)())func_8002CFB0)();
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003D26C);
// clang-format on
