#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)
#define SCRATCH_9C (*(s32**)0x1F80009C)

s32 func_8002A47C(s32);
void* func_8002C458();
extern s8 D_800CCEDC;

#define CHILD_TAIL(o, p)                                                       \
    {                                                                          \
        s32 n;                                                                 \
        s32 m;                                                                 \
        s32* tbl;                                                              \
        M2C_FIELD(o, s16*, 0x40) = 0x140;                                      \
        if (D_800CCEDC == 0xC) {                                               \
            M2C_FIELD(o, s16*, 0x42) = 0x7948;                                 \
            tbl = SCRATCH_9C;                                                  \
            M2C_FIELD(o, s32*, 0x3C) = (s32)tbl + *tbl;                        \
        } else {                                                               \
            n = func_8002A47C(M2C_FIELD(p, s8*, 1));                           \
            m = func_8002A47C(M2C_FIELD(p, s8*, 1));                           \
            M2C_FIELD(o, s16*, 0x42) =                                         \
                ((n * 4 + 0x20) % 16) | (((m + 8) / 4 + 0x1E0) << 6);          \
            M2C_FIELD(o, s32*, 0x3C) =                                         \
                SPAD20 +                                                       \
                *(s32*)(func_8002A47C(M2C_FIELD(p, s8*, 1)) * 4 + SPAD20);     \
        }                                                                      \
        M2C_FIELD(o, void**, 0x7C) = M2C_FIELD(p, void**, 0x80);               \
    }

void func_800F6F44(void* arg0, s32 arg1) {
    void* obj;
    u8 sub;
    s32 dir;
    u16 x;
    s32 kind;
    s32 n;
    s32 m;
    s32* tbl;

    sub = arg1;
    obj = func_8002C458();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0x10;
        M2C_FIELD(obj, u8*, 2) = sub;
        dir = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, u8*, 0x15) = dir;
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        x = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(obj, u16*, 0x8) = 0;
        M2C_FIELD(obj, u16*, 0xA) = x;
        kind = sub & 0xF0;
        M2C_FIELD(obj, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(obj, u16*, 0xC) = 0;
        M2C_FIELD(obj, void**, 0x7C) = arg0;
        switch (kind) {
        case 0x00:
            if (dir & 0xFF) {
                M2C_FIELD(obj, u16*, 0xA) = x + 0x10;
            } else {
                M2C_FIELD(obj, u16*, 0xA) = x - 0x10;
            }
            M2C_FIELD(obj, s16*, 0x40) = 0x540;
            dir = D_800CCEDC;
            if (dir == 0xC) {
                M2C_FIELD(obj, s16*, 0x42) = 0x794C;
                tbl = SCRATCH_9C;
                M2C_FIELD(obj, s32*, 0x3C) = (s32)tbl + tbl[1];
                return;
            }
            n = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
            m = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
            M2C_FIELD(obj, s16*, 0x42) =
                (((n + 1) * 4 + 0x20) % 16) | (((m + 9) / 4 + 0x1E0) << 6);
            M2C_FIELD(obj, s32*, 0x3C) =
                SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 +
                                 SPAD20 + 4);
            return;
        case 0x10:
            CHILD_TAIL(obj, arg0);
            break;
        case 0x30:
            CHILD_TAIL(obj, arg0);
            break;
        }
    }
}
