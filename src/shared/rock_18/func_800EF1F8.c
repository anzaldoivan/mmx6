#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBFC(void*, u8, s16, s16);
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800F0EF0[];

#define DIGIT(c, n)                                                            \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0EF0[(n) * 2],           \
                  self->y_pos.i.hi + D_800F0EF0[(n) * 2 + 1])

void func_800EF1F8(struct X4_BaseObj* self) {
    u8* e = (u8*)&D_800CCED0;
    s32 v;
    s32 th;
    s32 h;
    s32 t;
    s32 o;

    v = ((s16*)&D_800CCED0)[M2C_FIELD(e, s8*, 0x38) + 0xD2 / 2] -
        M2C_FIELD(e, s16*, 0xD6);
    if (v >= 9999) {
        DIGIT(0x48, 0);
        DIGIT(0x48, 1);
        DIGIT(0x48, 2);
        DIGIT(0x48, 3);
    } else if (v <= 0) {
        DIGIT(0x3F, 3);
    } else {
        th = v / 1000;
        h = v % 1000;
        h /= 100;
        t = v % 1000 - h * 100;
        o = v % 10;
        t /= 10;
        if (th != 0) {
            DIGIT(th + 0x3F, 0);
        }
        if (h != 0 || th != 0) {
            DIGIT(h + 0x3F, 1);
        }
        if (t != 0 || h != 0 || th != 0) {
            DIGIT(t + 0x3F, 2);
        }
        DIGIT(o + 0x3F, 3);
    }
    self->state = 2;
}

#undef DIGIT
#undef M2C_FIELD
