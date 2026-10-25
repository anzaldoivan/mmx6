#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80097202;
#define D_80097202 (*(s16*)&D_80097202)
extern s16 D_80097206;

s32 func_8002D654(void* arg0, void* arg1) {
#define H0 M2C_FIELD(arg0, u8**, 0x50)
#define H1 M2C_FIELD(arg1, u8**, 0x54)
    u8 w0;
    u8 w1;
    s32 sum;
    s32 x0;
    s32 x1;
    s32 d;

    if (M2C_FIELD(arg1, s8*, 0x61) != 0) {
        return 0;
    }
    if (H0 == 0) {
        return 0;
    }
    if (H1 == 0) {
        return 0;
    }
    w0 = H0[2];
    w1 = H1[2];
    {
        s32 a = *(volatile u8*)&H0[2];
        s32 b = *(volatile u8*)&H1[2];
        sum = a;
        sum += b;
    }
    if (M2C_FIELD(arg0, s8*, 0x14) < 0) {
        if (M2C_FIELD(arg0, u8*, 0x15) & 0x40) {
            x0 = M2C_FIELD(arg0, s16*, 0xA) - (s8)H0[0] + D_80097202;
        } else {
            x0 = M2C_FIELD(arg0, s16*, 0xA) + (s8)H0[0] + D_80097202;
        }
    } else {
        if (M2C_FIELD(arg0, u8*, 0x15) & 0x40) {
            x0 = M2C_FIELD(arg0, s16*, 0xA) - (s8)H0[0];
        } else {
            x0 = M2C_FIELD(arg0, s16*, 0xA) + (s8)H0[0];
        }
    }
    if (M2C_FIELD(arg1, u8*, 0x15) & 0x40) {
        x1 = M2C_FIELD(arg1, s16*, 0xA) - (s8)H1[0];
    } else {
        x1 = M2C_FIELD(arg1, s16*, 0xA) + (s8)H1[0];
    }
    d = x1 - x0;
    if (d < 0) {
        d = x0 - x1;
    }
    if (x1 < x0) {
        if (M2C_FIELD(arg0, u8*, 0x15) & 0x40) {
            if (M2C_FIELD(arg1, u8*, 0x15) & 0x40) {
                if (d >= w0) {
                    return 0;
                }
            } else {
                if (d >= sum) {
                    return 0;
                }
            }
        } else {
            if (M2C_FIELD(arg1, u8*, 0x15) & 0x40) {
                return 0;
            }
            if (d >= w1) {
                return 0;
            }
        }
    } else {
        if (M2C_FIELD(arg0, u8*, 0x15) & 0x40) {
            if (!(M2C_FIELD(arg1, u8*, 0x15) & 0x40)) {
                return 0;
            }
            if (d >= w1) {
                return 0;
            }
        } else if (M2C_FIELD(arg1, u8*, 0x15) & 0x40) {
            if (d >= sum) {
                return 0;
            }
        } else {
            if (d >= w0) {
                return 0;
            }
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x14) < 0) {
        x0 = M2C_FIELD(arg0, s16*, 0xE) + (s8)H0[1] + D_80097206;
    } else {
        x0 = M2C_FIELD(arg0, s16*, 0xE) + (s8)H0[1];
    }
    x1 = M2C_FIELD(arg1, s16*, 0xE) + (s8)H1[1];
    d = x1 - x0;
    if (d < 0) {
        d = x0 - x1;
    }
    if (x1 < x0) {
        if (d >= H1[3]) {
            return 0;
        }
    } else {
        if (d >= H0[3]) {
            return 0;
        }
    }
    return 1;
}
#undef D_80097202
