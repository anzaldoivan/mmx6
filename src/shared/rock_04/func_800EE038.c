#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C4C4();
s32 func_8002D2D4();
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EE038(void* arg0) {
    struct X4_PlayerObj* q;
    struct X4_PlayerObj* p;
    void* e;
    s32 r;

    q = &D_800970A0;
    if (M2C_FIELD(q, s8*, 0xE0) != 2) {
        if (M2C_FIELD(arg0, s8*, 5) < 0x10) {
            if ((s16)(M2C_FIELD(arg0, s16*, 0x18) % 144) == 0) {
                e = func_8002C4C4();
                if (e != 0) {
                    M2C_FIELD(e, u8*, 0) = 0x41;
                    M2C_FIELD(e, u8*, 1) = 7;
                    r = func_8002D2D4();
                    M2C_FIELD(e, s16*, 0xA) = 0x16F8;
                    M2C_FIELD(e, s16*, 0xE) = 0x138;
                    M2C_FIELD(e, void**, 0x7C) = arg0;
                    M2C_FIELD(e, s8*, 2) = r % 5 + 1;
                }
                M2C_FIELD(arg0, s8*, 5)++;
            }
        }
        M2C_FIELD(arg0, s16*, 0x18)++;
    }
    p = &D_800970A0;
    if (M2C_FIELD(arg0, s8*, 0x1A) == 0 && D_800971F8[0].unk20 < 0x431) {
        D_800971F8[0].unk2C += 0x30;
        M2C_FIELD(arg0, s8*, 0x1A)++;
    }
    if (p->x_pos.i.hi > 0x1680 && p->y_pos.i.hi < 0x1C0 &&
        M2C_FIELD(arg0, s8*, 0x1A) == 1) {
        D_800971F8[0].unk2C -= 0x30;
        M2C_FIELD(arg0, s8*, 0x1A)++;
    }
}
