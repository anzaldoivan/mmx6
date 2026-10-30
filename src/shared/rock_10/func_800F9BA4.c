#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800FC748;
extern M2C_UNK D_800FC74C;
extern M2C_UNK D_800FC750;
extern M2C_UNK D_800FC754;

void func_800F9BA4(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        switch (M2C_FIELD(arg0, s8*, 0x2)) {
        case 0x10:
            set_animation(arg0, 0x18);
            {
                // !FAKE: depin: dropping it breaks the match (22/59)
                register s32* a asm("$2") = &D_800FC748;
                // !FAKE: depin: dropping it breaks the match (29/59)
                register s32* b asm("$3") = &D_800FC74C;
                M2C_FIELD(arg0, s32**, 0x50) = a;
                M2C_FIELD(arg0, s32**, 0x54) = b;
            }
            break;
        case 0x12:
            set_animation(arg0, 0x18);
            {
                // !FAKE: depin: dropping it breaks the match (39/59)
                register s32* a asm("$2") = &D_800FC748;
                // !FAKE: depin: dropping it breaks the match (38/59)
                register s32* b asm("$3") = &D_800FC74C;
                M2C_FIELD(arg0, s32**, 0x50) = a;
                M2C_FIELD(arg0, s32**, 0x54) = b;
            }
            break;
        case 0x11:
        case 0x13:
            set_animation(arg0, 0x19);
            {
                // !FAKE: depin: dropping it breaks the match (55/59)
                register s32* a asm("$2") = &D_800FC750;
                // !FAKE: depin: dropping it breaks the match (30/59)
                register s32* b asm("$3") = &D_800FC754;
                M2C_FIELD(arg0, s32**, 0x50) = a;
                M2C_FIELD(arg0, s32**, 0x54) = b;
            }
            break;
        }
        M2C_FIELD(arg0, u8*, 0x5) = 2;
    }
}
