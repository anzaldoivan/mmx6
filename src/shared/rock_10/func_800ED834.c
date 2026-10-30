#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
struct X4_MiscObj* alloc_sprite_slot(void);
void set_velocity_from_angle(void*, s32);

#define SPAD (*(u8**)0x1F80004C)

void func_800ED834(void* arg0) {
    u8* child;
    u8* child2;

    child = func_8002C458();
    if (child != 0) {
        play_sound(2, 0, arg0);
        child[0] = 0x41;
        child[1] = 4;
        M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
        M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
        child[2] = SPAD[0x85];
        M2C_FIELD(child, void**, 0x7C) = arg0;
        M2C_FIELD(child, s32*, 0x84) = 0;
        set_velocity_from_angle(child, (s8)SPAD[0x85] & 0xFE);
        SPAD[0x80] = 8;
        M2C_FIELD(arg0, u8*, 6) += 1;
        SPAD[0x82] += 1;
    }
    child2 = alloc_sprite_slot();
    if (child2 != 0) {
        child2[0] = 0x41;
        child2[1] = 6;
        M2C_FIELD(child2, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
        M2C_FIELD(child2, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
        child2[2] = SPAD[0x85];
        M2C_FIELD(child2, void**, 0x50) = arg0;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        SPAD[0x89] = 0x5A;
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 6) = SPAD[0x8A];
        M2C_FIELD(arg0, s16*, 0x7C) = (s8)SPAD[0x8B];
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(SPAD, u16*, 0x8E);
        M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(SPAD, s32*, 0x90);
        M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(SPAD, s32*, 0x94);
    }
}
