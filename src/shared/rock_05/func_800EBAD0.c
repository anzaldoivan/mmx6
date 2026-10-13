#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern void (*D_800F3F9C[])(void*);

void func_800EBAD0(void* arg0) {
    void* s2;
    void* s3;

    D_800F3F9C[M2C_FIELD(arg0, s8*, 6)](arg0);
    s2 = M2C_FIELD(arg0, void**, 0x84);
    s3 = M2C_FIELD(arg0, void**, 0x88);
    if (D_800970A0.nova_strike_active == 0) {
        if (D_800971F8[0].unk2A > 0x3B0) {
            if (!(D_80097420 & 3)) {
                D_800971F8[0].unk2A--;
                D_800971F8[0].unk28--;
                M2C_FIELD(arg0, s16*, 0xE)--;
            }
        } else {
            func_80016C48(5, 3, arg0);
        }
    }
    if (D_800970A0.y_pos.i.hi < D_800971F8[0].unk2A - 0x10) {
        D_800970A0.y_pos.i.hi = D_800971F8[0].unk2A - 0x10;
    }
    M2C_FIELD(s2, s16*, 0x90) = D_800971F8[0].unk2A + 0xC0;
    M2C_FIELD(s3, s16*, 0x90) = D_800971F8[0].unk2A + 0xC0;
}
