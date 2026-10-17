#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EB14C(void* arg0) {
    s16 x;
    s32 d;

    if (M2C_FIELD(arg0, s8*, 2) != 0) {
        x = M2C_FIELD(arg0, s16*, 0xA);
        d = x - D_800970AA;
        if (d >= 0) {
            if (d < 0x70) {
                // !FAKE: shared store block, against cross-jumping of the two range tests
                goto store;
            }
        } else if ((D_800970AA - x) < 0x70) {
        store:
            M2C_FIELD(arg0, u8*, 5) = 2;
        }
    }
}
