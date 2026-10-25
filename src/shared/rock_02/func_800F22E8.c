#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80017A04();
M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj D_800CCED0;

void func_800F22E8(void* arg0) {
    void* p;
    s8 k;

    move_object((s32)arg0);
    ((void (*)(void*))func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) > background_objects[0].unk2A + 0x60) {
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x15;
            M2C_FIELD(p, u8*, 2) = 3;
            M2C_FIELD(p, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(p, s16*, 0xE) = background_objects[0].unk22 + 0xC0;
            M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(p, s32*, 0x3C) =
                SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 +
                                 SPAD20 + 4);
            M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
            M2C_FIELD(p, void**, 0x7C) = arg0;
        }
        k = M2C_FIELD(arg0, s8*, 2);
        if (k == 0) {
            func_80021760(4, 0xFF, 0);
        } else {
            if (k == 1) {
                u8* e = (u8*)&D_800CCED0;
                func_80021760(1, 0xFF, e[0x2E]);
                e[0x2E] = 1;
            } else {
                u8* e = (u8*)&D_800CCED0;
                func_80021760(0, 0xFF, e[0x2E]);
                e[0x2E] = 1;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
