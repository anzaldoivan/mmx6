#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK move_object(s32);

void func_800F48EC(void* arg0) {
    void* parent;
    void* p;
    s32 base;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)();
    move_object((s32)arg0);
    if (M2C_FIELD(parent, s8*, 5) == 0x11) {
        if (M2C_FIELD(arg0, s8*, 2) == 9) {
            p = func_8002C458();
            if (p != 0 && (u8)(M2C_FIELD(arg0, u8*, 0x8D) % 20) == 0) {
                M2C_FIELD(p, s8*, 0) = 0x41;
                M2C_FIELD(p, s8*, 1) = 0x15;
                M2C_FIELD(p, s8*, 2) = 0;
                if (M2C_FIELD(parent, u8*, 0x15) == 0) {
                    M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x18;
                } else {
                    M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x18;
                }
                M2C_FIELD(p, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                base = func_8002A47C(0x37);
                M2C_FIELD(p, s32*, 0x3C) =
                    SPAD20 + *(s32*)(base * 4 + SPAD20 + 4);
                M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
                M2C_FIELD(p, void**, 0x7C) = parent;
                play_sound(2, 0x1C, parent);
            }
        }
        if ((u8)++M2C_FIELD(arg0, u8*, 0x8D) >= 0x4D) {
            M2C_FIELD(arg0, u8*, 0x8D) = 0x28;
            play_sound(2, 0x80, arg0);
            M2C_FIELD(arg0, u8*, 6) = 6;
        }
    } else {
        if ((u8)--M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            play_sound(2, 0x7F, arg0);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}
