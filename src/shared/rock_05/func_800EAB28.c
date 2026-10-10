#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002BCCC(void*, s32);
void* func_8002C458();
M2C_UNK func_8002C9B0();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern s32 D_800748DC;
extern u32* D_80095098;
extern struct X4_PlayerObj D_800970A0;
extern s16 D_800970AE;
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEED;
extern s32 D_800F3DD8;
extern s32 D_800F3DDC;
extern s32 D_800F3DE0;
extern s32 D_800F3DE4[];
extern s32 D_800F3ED8;

void func_800EAB28(void* self) {
    s8 t;
    s32 i;
    s32 a;
    s32 b;
    register s32 flag asm("$6");
    s32 x;
    void* o;
    void* ob;

    t = M2C_FIELD(self, s8*, 2);
    if ((t == 4 && D_800970AE < 0x950) || (t == 5 && D_800CCEED != 0)) {
        return;
    }
    M2C_FIELD(self, u8*, 0x5C) = 0x20;
    M2C_FIELD(self, u8*, 0x60) = 8;
    M2C_FIELD(self, u8*, 0x61) = 0;
    M2C_FIELD(self, u8*, 0x14) = D_800970A0.bg_offset;
    M2C_FIELD(self, void**, 0x30) = &D_800F3ED8;
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, u8*, 0x15) = 0;
    M2C_FIELD(self, u8*, 0x70) = 0;
    M2C_FIELD(self, u8*, 0x16) = 5;
    M2C_FIELD(self, u8*, 0x8D) = 0;
    M2C_FIELD(self, u8*, 0x8E) = 0;
    if (t >= 4) {
        if (t == 4) {
            if (D_800CCEED >= 3) {
                func_8002C9B0(self);
                return;
            }
            M2C_FIELD(self, u16*, 0x40) =
                D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
            M2C_FIELD(self, void**, 0x3C) =
                (void*)((s32)SCRATCH_20 +
                        SCRATCH_20[func_8002A47C(M2C_FIELD(self, s8*, 1))]);
            M2C_FIELD(self, u16*, 0x42) =
                ((func_8002A47C(M2C_FIELD(self, s8*, 1)) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 8) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(self, u8*, 0x8D) = 1;
            M2C_FIELD(self, s16*, 0xA) = 0x430;
            M2C_FIELD(self, s16*, 0xE) = 0xAC0;
            func_8003D308(0x14, 0);
        } else if (t == 5) {
            if (D_800970A0.x_pos.i.hi < 0x16B &&
                D_800970A0.y_pos.i.hi < 0x1D0) {
                return;
            }
            M2C_FIELD(self, u16*, 0x40) =
                D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
            M2C_FIELD(self, void**, 0x3C) =
                (void*)((s32)SCRATCH_20 +
                        SCRATCH_20[func_8002A47C(M2C_FIELD(self, s8*, 1))]);
            M2C_FIELD(self, u16*, 0x42) =
                ((func_8002A47C(M2C_FIELD(self, s8*, 1)) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 8) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(self, u8*, 0x8D) = 1;
            M2C_FIELD(self, s16*, 0xA) = 0x240;
            M2C_FIELD(self, s16*, 0xE) = 0x248;
            func_8003D308(0x14, 0x40);
        } else if (t == 6) {
            M2C_FIELD(self, s16*, 0xA) = 0xA50;
            M2C_FIELD(self, u8*, 0x8D) = 1;
            M2C_FIELD(self, s16*, 0xE) = 0x900;
            M2C_FIELD(self, u8*, 0x8C) = 0;
            func_8003D308(0x14, 0x40);
        } else if (t == 7) {
            M2C_FIELD(self, s16*, 0xA) = 0xA50;
            M2C_FIELD(self, s16*, 0xE) = 0xB80;
            M2C_FIELD(self, u8*, 0x8D) = 1;
            func_8003D308(0x14, 0x40);
        } else if (t == 8) {
            o = &D_800970A0;
            if (D_800CCEED == 5) {
                func_8002C9B0(self);
                return;
            }
            flag = 0;
            D_800971F8[0].unk28 = D_800971F8[0].unk2A = 0xB00;
            if (((struct X4_PlayerObj*)o)->y_pos.i.hi < 0xAF0) {
                ((struct X4_PlayerObj*)o)->y_pos.i.hi = 0xAF0;
            }
            if (D_800970A0.x_pos.i.hi < 0xB80 &&
                D_800970A0.y_pos.i.hi < 0xB60) {
                flag = 1;
            }
            if (D_800970A0.x_pos.i.hi > 0xBC0 &&
                D_800970A0.x_pos.i.hi < 0xC00 &&
                D_800970A0.y_pos.i.hi < 0xB40) {
                flag = 1;
            }
            if (flag == 0) {
                return;
            }
            M2C_FIELD(self, s16*, 0xA) = 0xBD0;
            M2C_FIELD(self, s16*, 0xE) = D_800971F8[0].unk2A + 0x160;
            D_800971F8[2].unk3 = 1;
            *(s16*)&D_800971F8[2].unk40 = -0x120;
            D_800971F8[2].unk4C = 1;
            func_8003D308(0x14, D_800970A0.unk15);
        } else if (t == 9) {
            if (D_800CCEED == 4) {
                func_8002C9B0(self);
                return;
            }
            D_800971F8[0].unk28 = D_800971F8[0].unk2A = 0x870;
            M2C_FIELD(self, s16*, 0xA) = 0xBD0;
            M2C_FIELD(self, s16*, 0xE) = D_800971F8[0].unk2A + 0x160;
            D_800971F8[2].unk3 = 1;
            *(s16*)&D_800971F8[2].unk40 = -0x120;
            D_800971F8[2].unk4C = 1;
            func_8003D308(0x14, 0x40);
        } else if (t == 10) {
            if (M2C_FIELD(self, u8*, 0x90) == 0) {
                D_800971F8[0].unk2E -= 0x40;
                for (i = 0; i < 4; i++) {
                    o = func_8002C458();
                    if (o != NULL) {
                        M2C_FIELD(o, u8*, 0) = 0x41;
                        M2C_FIELD(o, u8*, 1) = 0x1D;
                        M2C_FIELD(o, u8*, 2) = 7;
                        M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(self, u16*, 0x40);
                        M2C_FIELD(o, u16*, 0x42) =
                            M2C_FIELD(self, u16*, 0x42) & 0x7FFF;
                        M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(self, s32*, 0x3C);
                        M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(self, s32*, 0x30);
                        M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(self, u8*, 0x14);
                        M2C_FIELD(o, s16*, 0xA) = i * 0xA0 + 0xCE0;
                        M2C_FIELD(o, s16*, 0xE) = 0x518;
                    }
                }
                D_800971F8[2].unk3 = 1;
                D_800971F8[2].unk4 = 2;
                *(s16*)&D_800971F8[2].unk40 = -0x8E0;
                D_800971F8[2].unk42 = 0x260;
                D_800971F8[2].unk4C = 1;
                M2C_FIELD(self, s16*, 0xA) = 0xE20;
                M2C_FIELD(self, s16*, 0xE) = D_800971F8[0].unk2A + 0x160;
                M2C_FIELD(self, u8*, 0x90) = 1;
            }
            if (D_800970A0.x_pos.i.hi < 0xD10) {
                return;
            }
            func_8003D308(0x14, 0x40);
        }
        D_800971F8[1].x_pos.i.hi = 0x200 - M2C_FIELD(self, u16*, 0xA);
        D_800971F8[1].y_pos.i.hi = 0x200 - M2C_FIELD(self, u16*, 0xE);
        D_800971F8[1].unk4C = 1;
        for (i = 0; i < 4; i++) {
            ob = func_8002BCCC(self, 0);
            if (ob != NULL) {
                M2C_FIELD(ob, u8*, 0) = 0x41;
                M2C_FIELD(ob, u8*, 1) = M2C_FIELD(self, u8*, 1);
                M2C_FIELD(ob, u8*, 2) = i;
                M2C_FIELD(ob, s32*, 0x10) = 0;
                M2C_FIELD(ob, u16*, 0x40) = M2C_FIELD(self, u16*, 0x40);
                M2C_FIELD(ob, u16*, 0x42) =
                    M2C_FIELD(self, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(ob, s32*, 0x3C) = M2C_FIELD(self, s32*, 0x3C);
                M2C_FIELD(ob, s32*, 0x30) = M2C_FIELD(self, s32*, 0x30);
                M2C_FIELD(ob, u8*, 0x14) = M2C_FIELD(self, u8*, 0x14);
                M2C_FIELD(ob, u16*, 0xA) = M2C_FIELD(self, u16*, 0xA);
                M2C_FIELD(ob, u16*, 0xE) = M2C_FIELD(self, u16*, 0xE);
                M2C_FIELD(ob, void**, 0x80) = self;
            }
            o = func_8002C458();
            if (o != NULL) {
                M2C_FIELD(o, u8*, 0) = 0x41;
                M2C_FIELD(o, u8*, 1) = 0x1D;
                M2C_FIELD(o, u8*, 2) = i;
                M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(self, u16*, 0x40);
                M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(self, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(self, s32*, 0x3C);
                M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(self, s32*, 0x30);
                M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(self, u8*, 0x14);
                M2C_FIELD(o, s32*, 0x8) = M2C_FIELD(self, s32*, 0x8);
                M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(self, s32*, 0xC);
                M2C_FIELD(o, void**, 0x7C) = self;
            }
        }
        D_800971F8[1].unk3 = 1;
        D_800971F8[1].pad51[1] = 0;
        if (M2C_FIELD(self, s8*, 2) < 8) {
            M2C_FIELD(self, void**, 0x68) = &D_800F3DD8;
            M2C_FIELD(self, u8*, 5) = 9;
        } else if (M2C_FIELD(self, s8*, 2) == 10) {
            M2C_FIELD(self, u8*, 5) = 9;
        } else {
            M2C_FIELD(self, void**, 0x68) = 0;
            M2C_FIELD(self, u8*, 5) = 10;
        }
        if (M2C_FIELD(self, s8*, 2) == 4) {
            D_800971F8[1].unk3 = 0;
        }
        M2C_FIELD(self, void**, 0x54) = &D_800F3DE0;
        M2C_FIELD(self, void**, 0x50) = &D_800F3DDC;
        M2C_FIELD(self, void**, 0x58) = &D_8007433C;
        M2C_FIELD(self, u8*, 3) = 0;
        D_800CCED0.character_state.bytes[0] = 0;
    } else {
        M2C_FIELD(self, void**, 0x68) = 0;
        M2C_FIELD(self, void**, 0x50) = 0;
        M2C_FIELD(self, void**, 0x54) = &D_800F3DE4[t];
        M2C_FIELD(self, void**, 0x58) = &D_800748DC;
        ((void (*)(void*, s32))func_800179A4)(self, t);
        M2C_FIELD(self, u8*, 5) = 1;
    }
    M2C_FIELD(self, s16*, 0x7C) = 0;
    M2C_FIELD(self, u8*, 4) = 1;
    M2C_FIELD(self, s16*, 0x7E) = 0;
    M2C_FIELD(self, u8*, 7) = 0;
}
