#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s8**)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();

void func_800F2438(void* arg0) {
    void* child;

    func_80017A04(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 8) {
        child = func_8002C458();
        if (child != 0) {
            M2C_FIELD(child, u8*, 0) = 0x41;
            M2C_FIELD(child, u8*, 1) = 0x15;
            M2C_FIELD(child, u8*, 2) = 0;
            if (M2C_FIELD(arg0, u8*, 0x47) == 0x19) {
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    M2C_FIELD(child, u16*, 0xA) =
                        M2C_FIELD(arg0, u16*, 0xA) + 0x38;
                } else {
                    M2C_FIELD(child, u16*, 0xA) =
                        M2C_FIELD(arg0, u16*, 0xA) - 0x38;
                }
            } else if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(child, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) + 0x2C;
            } else {
                M2C_FIELD(child, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) - 0x2C;
            }
            M2C_FIELD(child, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) - 8;
            {
                // !FAKE: depin: dropping it breaks the match (80/83)
                register s32 t asm("$2") = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(child, u16*, 0x42) = t;
            }
            {
                // !FAKE: depin: dropping it breaks the match (81/83)
                register s32 u asm("$3") = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(child, s32*, 0x30) = u;
            }
            M2C_FIELD(child, s8**, 0x3C) =
                SPAD20 + M2C_FIELD(func_8002A47C(0x37) * 4 + SPAD20, s32*, 4);
            M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(child, void**, 0x7C) = arg0;
            func_80016C48(2, 0x1C, arg0);
        }
    } else if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
