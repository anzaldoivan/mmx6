#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* func_8002C398(void);
s32 func_8002D30C();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern M2C_UNK D_800F58EC;

#define SPAWN()                                                                \
    {                                                                          \
        o = func_8002C398();                                                   \
        if (o != 0) {                                                          \
            M2C_FIELD(o, u8*, 0) = 0x21;                                       \
            M2C_FIELD(o, u8*, 1) = 4;                                          \
            M2C_FIELD(o, u8*, 2) = 0;                                          \
            M2C_FIELD(o, u8*, 4) = 0;                                          \
            M2C_FIELD(o, u8*, 5) = 0;                                          \
            M2C_FIELD(o, u8*, 6) = 0;                                          \
            t = func_8002D30C() % 32 - 0x10;                                   \
            M2C_FIELD(o, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + t;          \
            t = func_8002D30C() % 48 - 0x18;                                   \
            r = M2C_FIELD(arg0, u16*, 0xE);                                    \
            M2C_FIELD(o, u8*, 0x15) = 0;                                       \
            M2C_FIELD(o, u8*, 0x14) = 0;                                       \
            M2C_FIELD(o, u8*, 0x16) = 1;                                       \
            r += t;                                                            \
            M2C_FIELD(o, s16*, 0xE) = r;                                       \
        }                                                                      \
    }

void func_800ECF44(void* arg0) {
    void* o;
    s32 r;
    s32 t;

    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C)--;
        if (!(M2C_FIELD(arg0, u8*, 0x7C) & 7)) {
            SPAWN();
            if (!(M2C_FIELD(arg0, u8*, 0x7C) & 0x1F)) {
                func_800477E4(3, &D_800F58EC, arg0);
            }
        }
    } else {
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        SPAWN();
        func_800477E4(3, &D_800F58EC, arg0);
    }
}
