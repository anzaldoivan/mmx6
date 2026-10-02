#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004D598(void* arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_a0 = M2C_FIELD(arg0, s32*, 0x3C);
    temp_t1 = M2C_FIELD(arg0, s32*, 0x54);
    temp_a1 = -temp_a0;
    temp_v1 = M2C_FIELD(arg0, s32*, 0x50);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x40);
    temp_t2 = M2C_FIELD(arg0, s32*, 0x4C);
    temp_v0_2 = -temp_v0;
    temp_a2 = (s32)(temp_t1 * temp_a1 * 0x10) >> 0x10;
    temp_a1_2 = (s32)(temp_v1 * temp_a1 * 0x10) >> 0x10;
    temp_a3 = (s32)(temp_v1 * temp_v0 * 0x10) >> 0x10;
    temp_t0 = (s32)(temp_t2 * temp_v0 * 0x10) >> 0x10;
    temp_t1_2 = (s32)(temp_t1 * temp_a0 * 0x10) >> 0x10;
    temp_a0_2 = (s32)(temp_v1 * temp_a0 * 0x10) >> 0x10;
    temp_v1_2 = (s32)(temp_v1 * temp_v0_2 * 0x10) >> 0x10;
    temp_t2_2 = (s32)(temp_t2 * temp_v0_2 * 0x10) >> 0x10;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, s16*, 0x16) = (s16)temp_v1_2;
        M2C_FIELD(arg0, s16*, 0x1A) = (s16)temp_t2_2;
        M2C_FIELD(arg0, s16*, 0x1E) = (s16)temp_a2;
        M2C_FIELD(arg0, s16*, 0x22) = (s16)temp_a1_2;
        M2C_FIELD(arg0, s16*, 0x26) = (s16)temp_a2;
        M2C_FIELD(arg0, s16*, 0x2A) = (s16)temp_a1_2;
        M2C_FIELD(arg0, s16*, 0x2E) = (s16)temp_a3;
        M2C_FIELD(arg0, s16*, 0x32) = (s16)temp_t0;
        return;
    }
    M2C_FIELD(arg0, s16*, 0x16) = (s16)temp_a3;
    M2C_FIELD(arg0, s16*, 0x1A) = (s16)temp_t0;
    M2C_FIELD(arg0, s16*, 0x1E) = (s16)temp_t1_2;
    M2C_FIELD(arg0, s16*, 0x22) = (s16)temp_a0_2;
    M2C_FIELD(arg0, s16*, 0x26) = (s16)temp_t1_2;
    M2C_FIELD(arg0, s16*, 0x2A) = (s16)temp_a0_2;
    M2C_FIELD(arg0, s16*, 0x2E) = (s16)temp_v1_2;
    M2C_FIELD(arg0, s16*, 0x32) = (s16)temp_t2_2;
}
