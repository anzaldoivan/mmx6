#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_80025FD8();
void* func_8002BCCC(void*, s32);
M2C_UNK func_8003D308(M2C_UNK, u8);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;

void func_800F6254(void* arg0) {
    s32 i;
    void* p;
    u8 v;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
        background_objects[0].unk26 = background_objects[0].unk24;
    }
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        u8* e = (u8*)&D_800CCED0;
        e[0x8C] = 0x74;
        func_80025FD8();
        v = e[0x8F];
        if (v == 0) {
            e[0x8C] += 4;
        } else if (v == 1) {
            e[0x8C] += 6;
        } else if (v == 2) {
            e[0x8C] += 8;
        } else {
            e[0x8C] += 9;
        }
        i = 0;
        do {
            p = func_8002BCCC(arg0, 0);
            if (p != 0) {
                M2C_FIELD(p, u8*, 0) = 0x41;
                M2C_FIELD(p, u8*, 1) = 0x3C;
                M2C_FIELD(p, u8*, 2) = i + 1;
                M2C_FIELD(p, u16*, 0xA) = 0x2080;
                if (i == 0) {
                    M2C_FIELD(p, u16*, 0xE) = 0x60;
                    M2C_FIELD(p, u16*, 0x7C) = 0;
                } else {
                    M2C_FIELD(p, u16*, 0xE) = 0x120;
                    M2C_FIELD(p, u16*, 0x7C) = 0x3C;
                }
                {
                    u8* e2 = (u8*)&D_800CCED0;
                    s32 t = (s8)e2[0x8C];
                    M2C_FIELD(p, void**, 0x84) = arg0;
                    M2C_FIELD(p, s8*, 0x5C) = t / 2;
                }
            }
            i++;
        } while (i < 2);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        if (!(D_80097420 & 0x3F)) {
            func_80016C48(2, 0x69, arg0);
        }
        {
            u8* e3 = (u8*)&D_800CCED0;
            e3[0x24] = 1;
            e3[0x25] = 0;
            *(void**)(e3 + 0x20) = arg0;
        }
    }
}
