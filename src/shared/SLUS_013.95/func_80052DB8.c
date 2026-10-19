#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14();
s32 func_8002CAB4(struct X4_BaseObj*);
extern s16 D_800970AA;
extern s16 D_800970AE;
extern s8 D_800CCEED;

void func_80052DB8(void* arg0) {
    s32 t;
    u8 b;

    if (func_8002CAB4(arg0) == 0) {
        b = M2C_FIELD(arg0, u8*, 2);
        if (M2C_FIELD(arg0, s8*, 2) & 0x80) {
            t = M2C_FIELD(arg0, s16*, 0xE) > D_800970AE;
        } else {
            t = M2C_FIELD(arg0, s16*, 0xA) > D_800970AA;
        }
        if (t == 0) {
            D_800CCEED = b & 0x7F;
            ((void (*)())func_8002CA14)(arg0, b);
        }
    } else {
        ((void (*)())func_8002CA14)(arg0);
    }
}
