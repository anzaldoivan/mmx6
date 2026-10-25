#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_1C_W (*(s32*)0x1F80001C)

M2C_UNK func_800139A0(s8);
void func_800139A0_2p(s32, void*); /* link-only second name */
void* func_8002C530();
extern u8 D_80071088;

void func_8001CC1C(void* arg0) {
    u8* obj;
    s32 c80;
    s32 one;
    s32 t;
    s32 k;
    // !FAKE: depin: dropping it breaks the match (75/80)
    register s32 one1 asm("$3");

    if (--M2C_FIELD(arg0, s16*, 4) == 0) {
        c80 = 0x80;
        obj = func_8002C530();
        one1 = 1;
        if (obj != 0) {
            k = 0x15;
            obj[1] = k;
            k = -1;
            obj[0x14] = k;
            obj[0] = one1;
            obj[0x47] = 0;
            obj[2] = one1;
            M2C_FIELD(obj, s16*, 0xA) = c80;
            M2C_FIELD(obj, s16*, 0xE) = c80;
            obj[3] = one1;
            M2C_FIELD(obj, s32*, 0x38) = 0;
            t = SCRATCH_1C_W;
            M2C_FIELD(obj, s32*, 0x30) = 0;
            M2C_FIELD(obj, s16*, 0x40) = 0x1880;
            M2C_FIELD(obj, s16*, 0x42) = 0x7807;
            obj[0x15] = 0;
            obj[0x16] = 0;
            M2C_FIELD(obj, s32*, 0x3C) = t;
        }
        one = 1;
        obj = func_8002C530();
        if (obj != 0) {
            k = 0x15;
            obj[1] = k;
            k = 0x180;
            M2C_FIELD(obj, s16*, 0xA) = k;
            k = -1;
            obj[0x14] = k;
            obj[0] = one;
            obj[0x47] = one;
            obj[2] = one;
            M2C_FIELD(obj, s16*, 0xE) = c80;
            obj[3] = one;
            M2C_FIELD(obj, s32*, 0x38) = 0;
            t = SCRATCH_1C_W;
            M2C_FIELD(obj, s32*, 0x30) = 0;
            M2C_FIELD(obj, s16*, 0x40) = 0x1880;
            M2C_FIELD(obj, s16*, 0x42) = 0x7807;
            obj[0x15] = 0;
            obj[0x16] = 0;
            M2C_FIELD(obj, s32*, 0x3C) = t;
        }
        M2C_FIELD(arg0, s16*, 4) = 0x258;
        func_800139A0_2p(8, obj);
        M2C_FIELD(arg0, u8*, 1) += 1;
        D_80071088 = one;
    }
}
