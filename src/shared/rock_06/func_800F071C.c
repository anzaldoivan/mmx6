#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                     /* extern */
s32 func_8002A47C(s32);                      /* extern */
void* func_8002C32C();                       /* extern */
extern s8 D_800970FC;

void func_800F071C(void* arg0) {
    s32 f;
    u32 i;
    u8 bits;
    void* o;
    s32 r;
    s32 x;
    u8 n;

    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
            play_sound(2, 0x25, 0);
            f = 1;
        } else {
            goto clear;
        }
    } else {
        f = 1;
        if (D_800970FC != -0x80) {
        clear:
            f = 0;
        }
    }
    if (f != 0) {
        M2C_FIELD(arg0, u8*, 5) = 0xB;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        if (!(M2C_FIELD(arg0, u8*, 0xA8) & 8)) {
            M2C_FIELD(arg0, u8*, 5) = 0xC;
            M2C_FIELD(arg0, u8*, 6) = 0;
        } else {
            if (M2C_FIELD(arg0, u16*, 0x88) & 2) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else if (M2C_FIELD(arg0, u16*, 0x88) & 1) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            if (!(M2C_FIELD(arg0, u8*, 0x97) & 0x10)) {
                i = 0;
                if (M2C_FIELD(arg0, u8*, 0x94) == 0) {
                    bits = M2C_FIELD(arg0, u8*, 0x7F);
                    M2C_FIELD(arg0, u8*, 6) = 5;
                    do {
                        if (!(bits & 1)) {
                            n = i;
                            if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
                                o = func_8002C32C();
                                if (o != 0) {
                                    M2C_FIELD(o, u8*, 0) = 0x41;
                                    M2C_FIELD(o, u8*, 1) = 0x3C;
                                    M2C_FIELD(o, u8*, 2) = n;
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
                                    x = r * 4 + 0x20;
                                    M2C_FIELD(o, u16*, 0x42) =
                                        (x - ((x / 16) & 0x7F) * 16) |
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
                        i++;
                        bits >>= 1;
                    } while (i < 3);
                    M2C_FIELD(arg0, u8*, 0x7E) = 0x10;
                    play_sound(2, 6, 0);
                }
            }
        }
        func_80017A04(arg0);
        return;
    }
    func_80017A04(arg0);
}
