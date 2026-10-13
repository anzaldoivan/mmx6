#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);
extern s16 D_8009721E;
extern s16 D_80097222;
extern M2C_UNK D_800F6F44;
extern M2C_UNK D_800F6F64;

void func_800F1B98(void* arg0) {
    s32 temp_v1;

    func_80017A04();
    func_8002D2B0((s32)arg0);
    temp_v1 = M2C_FIELD(arg0, u16*, 0x8C);
    {
        register s32 t0 asm("$2") = M2C_FIELD(arg0, s16*, 0x8C);
        if (t0 == 0) {
            temp_v1 = D_80097222 + 0x70;
            {
                register s32 e asm("$4") = M2C_FIELD(arg0, s16*, 0xE);
                if (e >= temp_v1) {
                    M2C_FIELD(arg0, s8*, 7) = -1;
                    func_800179A4(arg0, 0x10);
                    M2C_FIELD(arg0, void**, 0x50) = &D_800F6F64;
                    func_80016C48(2, 0x74, arg0);
                    M2C_FIELD(arg0, void**, 0x54) = &D_800F6F44;
                    M2C_FIELD(arg0, s32*, 0x24) = 0;
                    M2C_FIELD(arg0, s32*, 0x2C) = 0;
                    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
                }
            }
        } else if ((u16)(temp_v1 - 1) < 2U) {
            if (D_8009721E + 0x20 >= M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, s8*, 7) = -1;
                func_800179A4(arg0, 0x10);
                M2C_FIELD(arg0, void**, 0x50) = &D_800F6F64;
                func_80016C48(2, 0x74, arg0);
                M2C_FIELD(arg0, u8*, 6) = 5;
            }
        } else if ((u16)(temp_v1 - 3) < 2U) {
            if (D_8009721E + 0xB0 >= M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, s8*, 7) = -1;
                func_800179A4(arg0, 0x10);
                M2C_FIELD(arg0, void**, 0x50) = &D_800F6F64;
                func_80016C48(2, 0x74, arg0);
                M2C_FIELD(arg0, u8*, 6) = 5;
            }
        }
    }
}
