#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800F04CC(void*);

extern u8 D_800E9860[];
extern M2C_UNK D_8007433C;
extern s32 D_80074FBC;
extern u8 D_8008EAFC;
extern s8 D_800970A2;
extern s8 D_8009711A;
extern u8 D_800CCF38;
extern void (*D_800F4358[])(void*);
extern u16 D_800F447E;
extern s32 D_800F4490;

#define B(p, o) M2C_FIELD(p, s8*, o)
#define UB(p, o) M2C_FIELD(p, u8*, o)

void func_800EEC40(void* self) {
    X4_RECT offs = *(X4_RECT*)(D_800E9860 + 0x50);
    u8* spad;
    u8* p;
    u8* obj;
    s32 i;
    s32 r;
    s8 st;

    if (D_800CCF38 >= 2) {
        spad = SPAD;
        if (UB(spad, 0x8B) == 2 && B(self, 5) != 3 && B(spad, 0x88) != 3 &&
            B(self, 5) != 8) {
            for (i = 0; i < 4; i++) {
                p = SPAD + 0x90;
                p += i;
                if (--*p == 0) {
                    obj = func_8002C458();
                    if (obj != NULL) {
                        UB(obj, 0) = 0x41;
                        UB(obj, 1) = 0x12;
                        UB(obj, 2) = 5;
                        UB(obj, 0x14) = UB(self, 0x14);
                        M2C_FIELD(obj, s16*, 0xA) =
                            ((s16*)&offs)[i] + D_800F447E;
                        UB(obj, 0x15) = UB(self, 0x15);
                        M2C_FIELD(obj, void**, 0x7C) = self;
                        play_sound(2, 0x19, self);
                    }
                    (SPAD + i)[0x90] = ((random_byte() & 3) + 1) * 30;
                }
            }
        }
    }
    if (B(self, 0x45) == 0x11 && D_8008EAFC == 0) {
        play_sound(2, 0xB, self);
    }
    func_800F04CC(self);
    D_800F4358[B(self, 5)](self);
    if (B(self, 5) != 2) {
        D_800F4490++;
    }
    func_80030ECC(self);
    r = check_enemy_hits(self);
    if (r < 0) {
        D_8009711A = 1;
        B(self, 4) = 2;
        B(self, 5) = 0;
        B(self, 6) = 0;
        play_sound(2, 0x20, self);
        return;
    }
    if (UB(SPAD, 0x86) == 0) {
        if (r != 0 && r != 0x7F) {
            st = B(self, 5);
            if (st == 8) {
                M2C_FIELD(self, void**, 0x58) = &D_8007433C;
                if ((u32)(r - 0x19) < 2) {
                    UB(SPAD, 0x86) = 2;
                } else {
                    UB(SPAD, 0x86) = 30;
                }
            } else if (D_800970A2 != 0) {
                if (st != 0xB) {
                    M2C_FIELD(self, void**, 0x58) = &D_8007433C;
                    obj = func_8002C458();
                    if (obj != NULL) {
                        UB(obj, 0) = 0x41;
                        UB(obj, 1) = 0x12;
                        UB(obj, 2) = 6;
                        M2C_FIELD(obj, s32*, 8) = M2C_FIELD(self, s32*, 8);
                        M2C_FIELD(obj, s32*, 0xC) = M2C_FIELD(self, s32*, 0xC);
                        UB(obj, 0x15) = UB(self, 0x15);
                        UB(obj, 0x16) = UB(self, 0x16);
                        M2C_FIELD(obj, void**, 0x7C) = self;
                        UB(obj, 7) = 30;
                    }
                    B(self, 3) = 0;
                    B(SPAD, 0x88) = B(self, 5);
                    B(self, 5) = 0xB;
                }
            } else if (r == 6 || r == 0xF) {
                if (st != 0xB) {
                    M2C_FIELD(self, void**, 0x58) = &D_8007433C;
                    obj = func_8002C458();
                    if (obj != NULL) {
                        UB(obj, 0) = 0x41;
                        UB(obj, 1) = 0x12;
                        UB(obj, 2) = 6;
                        M2C_FIELD(obj, s32*, 8) = M2C_FIELD(self, s32*, 8);
                        M2C_FIELD(obj, s32*, 0xC) = M2C_FIELD(self, s32*, 0xC);
                        UB(obj, 0x15) = UB(self, 0x15);
                        UB(obj, 0x16) = UB(self, 0x16);
                        M2C_FIELD(obj, void**, 0x7C) = self;
                        UB(obj, 7) = 90;
                    }
                    B(self, 3) = 0;
                    B(SPAD, 0x88) = B(self, 5);
                    B(self, 5) = 0xB;
                    play_sound(2, 0x21, self);
                }
            } else {
                M2C_FIELD(self, void**, 0x58) = &D_8007433C;
                M2C_FIELD(self, u16*, 0x42) |= 0x8000;
                UB(SPAD, 0x86) = 30;
            }
        }
    } else if (--UB(SPAD, 0x86) == 0) {
        M2C_FIELD(self, void**, 0x58) = &D_80074FBC;
        M2C_FIELD(self, u16*, 0x42) &= 0x7FFF;
    } else if (!(UB(SPAD, 0x86) & 1)) {
        M2C_FIELD(self, u16*, 0x42) |= 0x8000;
    } else {
        M2C_FIELD(self, u16*, 0x42) &= 0x7FFF;
    }
    if (B(self, 3) != 0) {
        func_8002CCB0(self, 0x80, 0x80);
    }
}
