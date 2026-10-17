#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern s8 D_800FD51D;

void func_800F4BB8(void* arg0) {
    s32 sub;

    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    switch (M2C_FIELD(arg0, s8*, 0x2) & 0xF0) {
    case 0:
        sub = M2C_FIELD(arg0, u8*, 0x2) & 0xF;
        switch (sub) {
        case 0:
            func_80016C48(2, 0x32, arg0);
            M2C_FIELD(arg0, u8*, 0x0) = 0x11;
            M2C_FIELD(arg0, s16*, 0x34) = 0x1F;
            M2C_FIELD(arg0, s8*, 0x37) = -1;
            M2C_FIELD(arg0, u8*, 0x5) = 0;
            break;
        case 1:
            M2C_FIELD(arg0, u8*, 0x5) = sub;
            break;
        }
        break;
    case 0x10: {
        s32 c7;
        s32 c13;

        sub = M2C_FIELD(arg0, u8*, 0x2) & 0xF;
        c7 = 7;
        c13 = 0x13;
        do {
        } while (0);
        sub += 0x14;
        M2C_FIELD(arg0, s16*, 0x34) = sub;
        M2C_FIELD(arg0, u8*, 0x36) = c7;
        M2C_FIELD(arg0, u8*, 0x0) = c13;
        M2C_FIELD(arg0, s16*, 0x48) = 0x1E;
        M2C_FIELD(arg0, s8*, 0x37) = -1;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        break;
    }
    }
    if (D_800FD51D != 0) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4)++;
    }
}
