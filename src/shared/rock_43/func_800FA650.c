#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCF5C;
extern s32 D_800FDE30;

void func_800FA650(void* arg0) {
    u32 r;
    s32 d;
    u8* e;
    u8 i;

    r = func_8002D2D4() & 0xF;
    M2C_FIELD(arg0, u8*, 0x87) = 0;
    if (D_800970A0.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA) >= 0) {
        if (D_800970A0.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA) < 0x41) {
            goto near;
        }
        goto far;
    }
    if (M2C_FIELD(arg0, s16*, 0xA) - D_800970A0.x_pos.i.hi < 0x41) {
    near:
        if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 0x10) {
                M2C_FIELD(arg0, u8*, 0x86) = 7;
            }
        } else if (r < 0x10) {
            M2C_FIELD(arg0, u8*, 0x86) = 8;
        }
    } else {
    far:
        d = D_800970A0.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE);
        if (d >= 0) {
            if (d >= 0x30) {
                goto far2;
            }
            goto near2;
        }
        if (M2C_FIELD(arg0, s16*, 0xE) - D_800970A0.y_pos.i.hi >= 0x30) {
        far2:
            e = (u8*)&D_800CCED0;
            if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                if (r < 0x10) {
                    if (e[0x68] == 2) {
                        M2C_FIELD(arg0, u8*, 0x86) = 0xA;
                    } else {
                        M2C_FIELD(arg0, u8*, 0x86) = 9;
                    }
                }
            } else if (r < 8) {
                if (e[0x68] == 2) {
                    M2C_FIELD(arg0, u8*, 0x86) = 0xA;
                } else {
                    M2C_FIELD(arg0, u8*, 0x86) = 9;
                }
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 0xB;
            }
        } else {
        near2:
            e = (u8*)&D_800CCED0;
            if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                if (r < 6) {
                    M2C_FIELD(arg0, u8*, 0x86) = 0;
                } else if (r < 0xC) {
                    M2C_FIELD(arg0, u8*, 0x86) = 1;
                } else if (e[0x68] == 2) {
                    M2C_FIELD(arg0, u8*, 0x86) = 5;
                } else {
                    M2C_FIELD(arg0, u8*, 0x86) = 4;
                }
            } else if (r < 4) {
                M2C_FIELD(arg0, u8*, 0x86) = 2;
            } else if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 3;
            } else if (r < 0xC) {
                if (e[0x68] == 2) {
                    M2C_FIELD(arg0, u8*, 0x86) = 5;
                } else {
                    M2C_FIELD(arg0, u8*, 0x86) = 4;
                }
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 6;
            }
        }
    }
    {
        u8* t = (u8*)&D_800FDE30 + 0x284;
        register u8* q asm("$3") =
            t + (M2C_FIELD(arg0, u8*, 0x87)++ + M2C_FIELD(arg0, u8*, 0x86) * 6);
        M2C_FIELD(arg0, u8*, 5) = *q;
    }
    M2C_FIELD(arg0, s8*, 6) = 0;
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
