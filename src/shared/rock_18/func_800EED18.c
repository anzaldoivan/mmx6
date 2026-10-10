#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBFC(void*, u8, s16, s16);
extern s32 D_800CCF64;
extern s16 D_800F0ED8[];

#define DIGIT(self, c, i)                                                      \
    func_800EFBFC((self), (c),                                                 \
                  M2C_FIELD(self, s16*, 0xA) + D_800F0ED8[(i) * 2],            \
                  M2C_FIELD(self, s16*, 0xE) + D_800F0ED8[(i) * 2 + 1])

void func_800EED18(void* self) {
    s32 h;
    s32 t;
    s32 o;

    if (D_800CCF64 >= 999) {
        DIGIT(self, 0x48, 0);
        DIGIT(self, 0x48, 1);
        DIGIT(self, 0x48, 2);
    } else if (D_800CCF64 <= 0) {
        DIGIT(self, 0x3F, 2);
    } else {
        h = D_800CCF64 / 100;
        t = D_800CCF64 - h * 100;
        o = D_800CCF64 % 10;
        t /= 10;
        if (h != 0) {
            DIGIT(self, h + 0x3F, 0);
        }
        if (t != 0 || h != 0) {
            DIGIT(self, t + 0x3F, 1);
        }
        DIGIT(self, o + 0x3F, 2);
    }
    M2C_FIELD(self, u8*, 4) = 2;
}
