#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF5F;
extern u8 D_800FA000[];

void func_800FA454(void* arg0) {
    u8 tbl[4];

    __builtin_memcpy(tbl, D_800FA000 + 0x10, 4);
    if (M2C_FIELD(arg0, s8*, 0x7) == 0 &&
        M2C_FIELD(arg0, s16*, 0x7E) == tbl[D_800CCF5F]) {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) == 0x32) {
        if (M2C_FIELD(arg0, s16*, 0x7E) < tbl[D_800CCF5F]) {
            void* e;
            if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            e = func_8002C458();
            if (e != 0) {
                s8 v;
                M2C_FIELD(e, u8*, 0) = 0x41;
                M2C_FIELD(e, u8*, 1) = 0x22;
                v = 3;
                if (g_Player.unk2 == 0) {
                    v = 2;
                }
                M2C_FIELD(e, s8*, 2) = v;
                M2C_FIELD(e, void**, 0x7C) = arg0;
            }
            M2C_FIELD(arg0, s16*, 0x7E)++;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
    }
}
