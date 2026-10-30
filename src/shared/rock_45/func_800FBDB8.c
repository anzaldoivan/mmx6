#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800FBDB8(void* arg0) {
    s16 d;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x35, arg0);
        d = D_800970AA - M2C_FIELD(arg0, s16*, 0xA);
        if (d < 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = (d << 16) / 40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s32*, 0x20) = (d << 16) / 40;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x1999;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}
