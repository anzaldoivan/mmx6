#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F1DC4 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002BBF4();
s32 func_8002D2D4();
extern s8 D_8008EF48[];
extern u32* D_80095098;
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_800E9A1C[];

void func_800F1DC4(void* arg0, s32 arg1) {
    s16 offs[2][2];
    s32 sel;
    u8 t;
    void* obj;
    s8* p;

    __builtin_memcpy(offs, D_800E9A1C, 8);
    if ((s8)arg1 == 0) {
        sel = 1;
    } else {
        sel = func_8002D2D4() & 1;
    }
    t = M2C_FIELD(arg0, u8*, 0x84);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x84) = --t;
        if (t == 0) {
            obj = func_8002BBF4();
            if (obj != 0) {
                M2C_FIELD(obj, u8*, 0) = 0x41;
                M2C_FIELD(obj, u8*, 1) = 8;
                M2C_FIELD(obj, u8*, 2) = 0;
                M2C_FIELD(obj, s16*, 0xA) =
                    D_800971F8[0].x_pos.i.hi + offs[sel][0];
                M2C_FIELD(obj, s16*, 8) = 0;
                M2C_FIELD(obj, s16*, 0xE) =
                    D_800971F8[0].y_pos.i.hi + offs[sel][1];
                M2C_FIELD(obj, s16*, 0xC) = 0;
                M2C_FIELD(obj, u16*, 0x40) = D_80095098[func_8002A47C(8)] >> 7;
                M2C_FIELD(obj, s16*, 0x42) =
                    ((func_8002A47C(M2C_FIELD(obj, s8*, 1)) * 4 + 0x20) % 16) |
                    (((func_8002A47C(M2C_FIELD(obj, s8*, 1)) + 8) / 4 + 0x1E0)
                     << 6);
                M2C_FIELD(obj, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DC4 +
                    SPAD20_800F1DC4[func_8002A47C(M2C_FIELD(obj, s8*, 1))];
                M2C_FIELD(arg0, u8*, 0x84) = 0;
            }
        }
    } else {
        for (p = D_8008EF48; p < D_8008EF48 + 0x1D40; p += 0x9C) {
            if (p[0] != 0 && p[1] == 8) {
                return;
            }
        }
        M2C_FIELD(arg0, u8*, 0x84) = 0x78;
    }
}
