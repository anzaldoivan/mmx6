#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F1DA8 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002C458();
extern u8 D_800970B4;
extern s32 D_800F6ABC;
extern s32 D_800F6DA4;

void func_800F1DA8(void* arg0, s32 arg1, s32 arg2) {
    u8 id = arg1;
    u8 kind = arg2;
    void* e;

    e = func_8002C458();
    {
        register s32 c asm("$2");
        c = 0x41;
        if (e != 0) {
            M2C_FIELD(e, u8*, 0) = c;
            {
                register s32 d asm("$3");
                d = 0x21;
                M2C_FIELD(e, u8*, 1) = d;
            }
            M2C_FIELD(e, u8*, 2) = id;
            if (kind == 0) {
                M2C_FIELD(e, s16*, 0x40) = 0x140;
                M2C_FIELD(e, s32**, 0x30) = &D_800F6DA4;
                M2C_FIELD(e, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DA8 + SPAD20_800F1DA8[func_8002A47C(0x3E)];
                M2C_FIELD(e, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(e, void**, 0x7C) = arg0;
            } else if (kind == 1) {
                M2C_FIELD(e, s16*, 0x40) = 0x240;
                M2C_FIELD(e, s32**, 0x30) = &D_800F6ABC;
                M2C_FIELD(e, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DA8 +
                    SPAD20_800F1DA8[func_8002A47C(0x3E) + 2];
                M2C_FIELD(e, s16*, 0x42) =
                    (((func_8002A47C(0x3E) + 2) * 4 + 0x20) % 16) |
                    (((func_8002A47C(0x3E) + 2 + 8) / 4 + 0x1E0) << 6);
                M2C_FIELD(e, void**, 0x7C) = M2C_FIELD(arg0, void**, 0x7C);
            } else if (kind == 2) {
                M2C_FIELD(e, s16*, 0x40) = 0x240;
                M2C_FIELD(e, s32**, 0x30) = &D_800F6ABC;
                M2C_FIELD(e, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DA8 +
                    SPAD20_800F1DA8[func_8002A47C(0x3E) + 1];
                M2C_FIELD(e, s16*, 0x42) =
                    (((func_8002A47C(0x3E) + 2) * 4 + 0x20) % 16) |
                    (((func_8002A47C(0x3E) + 2 + 8) / 4 + 0x1E0) << 6);
                M2C_FIELD(e, void**, 0x7C) = arg0;
            } else if (kind == 3) {
                M2C_FIELD(e, s16*, 0x40) = 0x240;
                M2C_FIELD(e, s32**, 0x30) = &D_800F6ABC;
                M2C_FIELD(e, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DA8 +
                    SPAD20_800F1DA8[func_8002A47C(0x3E) + 2];
                M2C_FIELD(e, s16*, 0x42) =
                    (((func_8002A47C(0x3E) + 2) * 4 + 0x20) % 16) |
                    (((func_8002A47C(0x3E) + 2 + 8) / 4 + 0x1E0) << 6);
                M2C_FIELD(e, void**, 0x7C) = arg0;
            }
            M2C_FIELD(e, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(e, u8*, 0x14) = D_800970B4;
            {
                u16 x = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(e, s16*, 0x8) = 0;
                M2C_FIELD(e, s16*, 0xA) = x;
            }
            {
                u16 y = M2C_FIELD(arg0, u16*, 0xE);
                M2C_FIELD(e, s16*, 0xC) = 0;
                M2C_FIELD(e, s16*, 0xE) = y;
            }
        }
    }
}
