#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_80073D50;
extern s32 D_80073D54;

void set_pose_size(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD5) < 0) {
        M2C_FIELD(arg0, s32**, 0x68) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        M2C_FIELD(arg0, s32**, 0x68) = &D_80073D50;
        return;
    }
    M2C_FIELD(arg0, s32**, 0x68) = &D_80073D54;
}
