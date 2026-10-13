#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002BBF4();
extern M2C_UNK D_8007433C;
extern struct X4_EngineObj D_800CCED0;

void func_800FA864(void* arg0) {
    void* e;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 4) {
        M2C_FIELD(arg0, u16*, 0xE) -= 2;
    } else {
        M2C_FIELD(arg0, u16*, 0xE) += 2;
    }
    if (M2C_FIELD(arg0, s32*, 0x84) != 0) {
        struct X4_EngineObj* g = &D_800CCED0;
        u8 n = M2C_FIELD(g, u8*, 0x33);
        if (M2C_FIELD(g, s8*, 0x33) < 3) {
            M2C_FIELD(g, u8*, 0x33) = n + 1;
            e = func_8002BBF4(n);
            if (e != 0) {
                M2C_FIELD(e, u8*, 0) = 0x41;
                M2C_FIELD(e, u8*, 1) = 0xF;
                M2C_FIELD(e, u8*, 2) = 0x32;
                M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
                M2C_FIELD(e, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            }
            goto block_8;
        }
    }
    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) == 0x50) {
    block_8:
        if (M2C_FIELD(arg0, u8*, 0x88) < 0xF) {
            M2C_FIELD(arg0, u8*, 0x88) = 0x1E;
        }
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
        }
        M2C_FIELD(arg0, s32*, 0x2C) = 0x10000;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
