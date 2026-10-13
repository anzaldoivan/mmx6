#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80012D9C(s32);
void func_800186A8();
void func_8002C0DC(s32, s32);
struct X4_QuadObj* func_8002C7F0(void);
void func_80049E50(struct X4_MainObj* self);
extern s8 D_800CCEEB;

void func_800538BC(void* arg0) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;
    u16 temp_v0_4;

    temp_v0 = ((void* (*)())func_8002C7F0)();
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, s8*, 0) = 1;
        M2C_FIELD(temp_v0, s8*, 1) = 4;
        M2C_FIELD(temp_v0, u16*, 8) = (u16)M2C_FIELD(arg0, u16*, 0x1C);
        M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_2 = ((void* (*)())func_8002C7F0)(temp_v0);
    if (temp_v0_2 != 0) {
        M2C_FIELD(temp_v0_2, s8*, 0) = 1;
        M2C_FIELD(temp_v0_2, s8*, 1) = 4;
        M2C_FIELD(temp_v0_2, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0x555) & 0xFFF);
        M2C_FIELD(temp_v0_2, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_2, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_3 = ((void* (*)())func_8002C7F0)(temp_v0_2);
    if (temp_v0_3 != 0) {
        M2C_FIELD(temp_v0_3, s8*, 0) = 1;
        M2C_FIELD(temp_v0_3, s8*, 1) = 4;
        M2C_FIELD(temp_v0_3, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0xAAA) & 0xFFF);
        M2C_FIELD(temp_v0_3, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_3, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    func_8002C0DC(0x82, 0);
    temp_v0_4 = M2C_FIELD(arg0, u16*, 0x14);
    if (temp_v0_4 != 0) {
        M2C_FIELD(arg0, u16*, 0x14) = (u16)(temp_v0_4 - 1);
        func_80049E50(arg0);
        return;
    }
    M2C_FIELD(arg0, u16*, 0x14) = 0x64;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    if (M2C_FIELD(arg0, s8*, 2) != 1) {
        ((s32(*)())func_800186A8)();
        D_800CCEEB = 0;
    }
    func_80012D9C(0xA);
}
