#include "common.h"
#define M2C_UNK s32

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8001750C(M2C_UNK, M2C_UNK);        /* extern */
s32 func_8002A47C(s32);                         /* extern */
void* func_8002C32C();                          /* extern */
struct X4_VisualObj* func_8002C398(void);       /* extern */

void func_800EE344(void* arg0) {
    s32 m;
    u16 b;
    u32 i;
    u8 bits;
    u8 k;
    s32 r;
    void* o;
    u8 c;

    if (M2C_FIELD(arg0, u8*, 0x97) & 2) {
        return;
    }
    m = M2C_FIELD(arg0, u16*, 0x96) & 0xC000;
    if (m == 0x8000) {
        return;
    }
    switch (M2C_FIELD(arg0, u8*, 0x94)) {
    case 0:
        b = M2C_FIELD(arg0, u16*, 0x88) & 0x30;
        if (b != 0) {
            M2C_FIELD(arg0, u8*, 0x94) = 1;
            M2C_FIELD(arg0, u8*, 0x95) = 0x3C;
            M2C_FIELD(arg0, u16*, 0xA6) = b;
        }
        break;
    case 1:
        if (!(M2C_FIELD(arg0, u16*, 0x88) & M2C_FIELD(arg0, u16*, 0xA6))) {
            M2C_FIELD(arg0, u8*, 0x94) = 0;
            M2C_FIELD(arg0, u16*, 0xA6) = 0;
            break;
        }
        if (--M2C_FIELD(arg0, u8*, 0x95) == 0) {
            M2C_FIELD(arg0, u8*, 0x94) = 2;
            if (M2C_FIELD(arg0, s8*, 2) != 0 &&
                (M2C_FIELD(arg0, volatile u16*, 0x96) & 0xC000) == 0x4000) {
                void* o = func_8002C398();
                if (o != NULL) {
                    M2C_FIELD(o, u8*, 0) = 0x41;
                    M2C_FIELD(o, u8*, 1) = 0x16;
                    M2C_FIELD(o, u8*, 2) = 0x10;
                    M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
                    M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
                    M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(o, u16*, 0x42) =
                        M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                    M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
                    M2C_FIELD(o, void**, 0x50) = arg0;
                    M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                }
                func_80016C48(2, 8, 0);
            }
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, u16*, 0x88) & M2C_FIELD(arg0, u16*, 0xA6)) {
            break;
        }
        if (M2C_FIELD(arg0, s8*, 2) != 0 && m == 0x4000) {
            c = M2C_FIELD(arg0, u8*, 5);
            if (c != 3 && c != 6 && c != 9 && c != 0xA && c != 0xB &&
                c != 0xD && c != 0x10 && c != 0x11) {
                bits = M2C_FIELD(arg0, u8*, 0x7F);
                for (i = 0; i < 3; i++, bits >>= 1) {
                    if (bits & 1) {
                        continue;
                    }
                    k = i;
                    if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
                        o = func_8002C32C();
                        if (o != NULL) {
                            M2C_FIELD(o, u8*, 0) = 0x41;
                            M2C_FIELD(o, u8*, 1) = 0x3C;
                            M2C_FIELD(o, u8*, 2) = k;
                            M2C_FIELD(o, u16*, 0xA) =
                                M2C_FIELD(arg0, u16*, 0xA);
                            M2C_FIELD(o, u16*, 0xE) =
                                M2C_FIELD(arg0, u16*, 0xE);
                            M2C_FIELD(o, s32*, 0x30) =
                                M2C_FIELD(arg0, s32*, 0x30);
                            M2C_FIELD(o, u16*, 0x40) =
                                M2C_FIELD(arg0, u16*, 0x40);
                            M2C_FIELD(o, s32*, 0x3C) =
                                M2C_FIELD(arg0, s32*, 0x3C);
                            r = func_8002A47C(0xE1) & 0xFF;
                            M2C_FIELD(o, u16*, 0x42) =
                                ((r * 4 + 0x20) % 16) |
                                (((r + 8) / 4 + 0x1E0) << 6);
                            M2C_FIELD(o, u8*, 0x16) =
                                M2C_FIELD(arg0, u8*, 0x16);
                            M2C_FIELD(o, void**, 0x7C) = arg0;
                            M2C_FIELD(o, u8*, 0x15) =
                                M2C_FIELD(arg0, u8*, 0x15);
                        }
                    }
                    M2C_FIELD(arg0, u8*, 0x7F) |= 1 << i;
                }
                M2C_FIELD(arg0, u8*, 0x7E) = 0x10;
                func_80016C48(2, 6, 0);
                M2C_FIELD(arg0, u8*, 0x94) = 0;
                M2C_FIELD(arg0, u16*, 0xA6) = 0;
                break;
            }
        }
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u16*, 0xA6) = 0;
        func_8001750C(2, 8);
        break;
    }
}
