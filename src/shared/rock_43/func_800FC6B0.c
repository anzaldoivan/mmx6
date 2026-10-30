#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;
#define D_800970AA_U (*(u16*)&D_800970AA)

void func_800FC6B0(void* arg0) {
    s16 d;

    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) >= 0xB) {
        d = D_800970AA_U - M2C_FIELD(arg0, u16*, 0xA);
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            if (d < -0x40) {
                // !FAKE: skip to the shared tail, retail branches out of the negative arm
                goto skip;
            }
        } else if (d >= 0x41) {
            // !FAKE: skip to the shared tail from the positive arm
            goto skip;
        }
        play_sound(2, 0x86, arg0);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
skip:
    func_8002CCB0(arg0, 0x40, 0x40);
    func_8002D230(arg0);
}
#undef D_800970AA_U
