// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80039C40);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003B9AC(void*);
extern u8 D_800CCF99;

s32 func_80039C9C(void* arg0) {
    if (((s8*)arg0)[0xD3] != 0) {
        return 0;
    }
    if (!(D_800CCF99 & 8)) {
        return 0;
    }
    if (!(*(u16*)((u8*)arg0 + 0x7C) & 8)) {
        return 0;
    }
    func_8003B9AC(arg0);
    return 1;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039CFC(void* arg0) {
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    if (!(temp_v1 & 3)) {
        return 0;
    }
    if (temp_v1 & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        if (M2C_FIELD(arg0, u8*, 0x89) & 1) {
            return 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0xF0);
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        if (M2C_FIELD(arg0, u8*, 0x89) & 2) {
            return 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0xF0);
    }
    return 1;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039D7C(void* arg0) {
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    if (!(temp_v1 & 3)) {
        return 0;
    }
    if (temp_v1 & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        if (M2C_FIELD(arg0, u8*, 0x89) & 1) {
            return 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0xF4);
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        if (M2C_FIELD(arg0, u8*, 0x89) & 2) {
            return 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0xF4);
    }
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003CCBC();
M2C_UNK func_8003CDBC();

void func_80039DFC(void* arg0) {
    s8* p = (s8*)arg0;
    s8 temp_v1;

    temp_v1 = p[5];
    if (temp_v1 == 0) {
        return;
    }
    if (temp_v1 == 1) {
        return;
    }
    if ((p[0x67] == 0) && (p[0xA4] <= 0) && (p[0xD5] >= 0) && (p[0xD4] == 0) &&
        !(((u8*)p)[0x89] & 8)) {
        if (p[2] != 0) {
            func_8003CDBC();
        }
        func_8003AFF4((s32)arg0);
        func_8003CCBC(arg0);
    }
}
