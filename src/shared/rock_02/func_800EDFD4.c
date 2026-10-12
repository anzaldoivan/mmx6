#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002BBF4();
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_8004A768();

void func_800EDFD4(void* arg0) {
    void* p;
    s32 x;
    s32 v;

    M2C_FIELD(arg0, s16*, 0x7C) = M2C_FIELD(arg0, s16*, 0x7C) + 1;
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0x14) {
        func_80029478(0x14, 2, 2);
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) < 0x1E &&
        !(M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
        x = M2C_FIELD(arg0, s16*, 0xA);
        func_8004A768(0x20, x - 0x64, 0x190, x + 0x64, 0x1A0, 8);
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0x78) {
        p = func_8002BBF4();
        if (p != 0) {
            u8 t;
            M2C_FIELD(p, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
            t = M2C_FIELD(arg0, u8*, 1);
            M2C_FIELD(p, u8*, 2) = 1;
            M2C_FIELD(p, void**, 0x80) = arg0;
            M2C_FIELD(p, u8*, 1) = t;
        }
    }
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        if (M2C_FIELD(arg0, s8*, 7) == 1) {
            v = *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20 +
                        4);
            M2C_FIELD(arg0, s32*, 0x3C) = SPAD20 + v;
            func_800179A4(arg0, 9);
            {
                register s32 n asm("$2") = M2C_FIELD(arg0, u8*, 7) + 1;
                M2C_FIELD(arg0, u8*, 7) = n;
            }
        } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            p = func_8002C458();
            if (p != 0) {
                u8 t = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(p, u8*, 1) = 1;
                M2C_FIELD(p, u8*, 2) = 4;
                M2C_FIELD(p, void**, 0x7C) = arg0;
                M2C_FIELD(p, u8*, 0) = t;
            }
            func_80016C48(2, 4, arg0);
            M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
