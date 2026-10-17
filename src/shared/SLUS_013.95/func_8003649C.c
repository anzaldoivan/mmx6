#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80017A04();
M2C_UNK func_8002D5D0(void*);
u8 func_80030304(struct X4_PlayerObj*, s16, s16);
M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003F508(void*, M2C_UNK);

void func_8003649C(void* arg0) {
    u8* p;

    if (M2C_FIELD(arg0, u8*, 0x89) & 4) {
        if (M2C_FIELD(arg0, u8*, 0x70) & 4) {
            p = M2C_FIELD(arg0, u8**, 0x68);
            if ((((s32(*)())func_80030304)(arg0, M2C_FIELD(arg0, s16*, 0xA),
                                           M2C_FIELD(arg0, s16*, 0xE) +
                                               M2C_FIELD(p, s8*, 1) - p[3] -
                                               8) &
                 0xFF) == 0x39) {
                func_8003AFF4((s32)arg0);
                return;
            }
        }
        func_80016C48(1, 4, arg0);
        func_8003BA04(arg0, 0x53);
        M2C_FIELD(arg0, u8*, 6) = 2;
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            M2C_FIELD(arg0, u8*, 7) = 0x78;
            return;
        }
        M2C_FIELD(arg0, s8*, 7) = -0x4C;
        return;
    }
    M2C_FIELD(arg0, u8*, 7) += 1;
    func_8002D5D0(arg0);
    func_80017A04(arg0);
    func_8003F508(arg0, 0xA);
    if (((M2C_FIELD(arg0, s32*, 0x24) * M2C_FIELD(arg0, s8*, 7)) >> 0x10) >=
        0x90) {
        M2C_FIELD(arg0, u8*, 7) = 5;
        M2C_FIELD(arg0, u8*, 6) += 1;
        func_8003BA04(arg0, 0xB);
    }
}
