#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800CCEDF;
extern s32 D_800FDE30;

void func_800FC28C(void* arg0) {
    if (D_800CCEDF == 0) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
            set_animation(arg0, 2);
            play_sound(2, 0x99, arg0);
            play_sound(2, 0x95, arg0);
            {
                s32 d = *(u16*)((u8*)&D_800FDE30 + 0x45A);
                s32 c = M2C_FIELD(arg0, u8*, 6);
                M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
                M2C_FIELD(arg0, s16*, 0x7C) = 0;
                M2C_FIELD(arg0, u16*, 0x88) = d;
                M2C_FIELD(arg0, u8*, 6) = c + 1;
            }
        }
    }
}
