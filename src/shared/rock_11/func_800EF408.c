#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern u8 D_800E9884[];

#define F(type, off) M2C_FIELD(arg0, type*, off)

// str 0x800E9884 sha1=cc02398329fa039d76fae5aa30b17ad91bc6c29c = "rising byte ramp: a table, not text"
void func_800EF408(void* arg0) {
    s8 a[16];
    s32 angle;
    s32 v;
    s32 t;
    s32 x;
    s32 y;
    s32 d;

    __builtin_memcpy(a, D_800E9884, 16);
    switch (F(u8, 0x2) & 0xF) {
    case 1:
        x = 0x120;
        y = 0x60;
        break;
    case 2:
        x = 0x20;
        y = 0x20;
        break;
    case 3:
        x = 0x50;
        y = 0xB0;
        break;
    }
    angle = ratan2(F(s16, 0xE) - y, x - F(s16, 0xA));
    v = rcos(angle) * 16;
    F(s32, 0x20) = v * 2 + v;
    v = rsin(angle) * 16;
    F(s32, 0x24) = v * 2 + v;
    move_object(arg0);
    t = F(s16, 0xA);
    d = x - t;
    if (d >= 0) {
        if (d < 4) {
            goto L1;
        }
        return;
    }
    if (t - x < 4) {
    L1:
        t = F(s16, 0xE);
        d = y - t;
        if (d >= 0) {
            if (d < 4) {
                goto L2;
            }
            return;
        }
        if (t - y < 4) {
        L2:
            F(s16, 0xA) = x;
            F(s16, 0xE) = y;
            F(u8, 0x6)++;
        }
    }
}
