#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern struct X4_PlayerObj g_Player;
extern s32 D_80097420;

void func_800EB1A0(void* arg0) {
    s32 angle;

    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (58/62)
        register s32 c asm("$2") = M2C_FIELD(arg0, s16*, 0x80);
        if (c != 0) {
            M2C_FIELD(arg0, s16*, 0x80)--;
        } else {
            struct X4_PlayerObj* p = &g_Player;
            M2C_FIELD(arg0, s16*, 0x82) = M2C_FIELD(p, s16*, 0xA);
            M2C_FIELD(arg0, s16*, 0x84) = M2C_FIELD(p, s16*, 0xE);
            M2C_FIELD(arg0, s16*, 0x82) = M2C_FIELD(p, s16*, 0xA);
            M2C_FIELD(arg0, s16*, 0x84) = M2C_FIELD(p, s16*, 0xE);
            angle = ratan2(
                M2C_FIELD(arg0, s16*, 0x84) - M2C_FIELD(arg0, s16*, 0xE),
                M2C_FIELD(arg0, s16*, 0x82) - M2C_FIELD(arg0, s16*, 0xA));
            M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) << 5;
            M2C_FIELD(arg0, s32*, 0x24) = -rsin(angle) << 5;
            M2C_FIELD(arg0, s8*, 7) = 2;
        }
    }
    if (M2C_FIELD(arg0, s8*, 3) != 0 && !(D_80097420 & 0x1F)) {
        func_80016C48(2, 0xD, arg0);
    }
}
