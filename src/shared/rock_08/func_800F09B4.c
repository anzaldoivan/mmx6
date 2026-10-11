#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_800179A4(void*, s32);
M2C_UNK func_80017A04();
M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
s32 func_8002D2D4();
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800F6AF0;
extern s16 D_800F6AF8;

void func_800F09B4(void* arg0) {
    struct X4_EngineObj* e;
    u8 t;

    if (D_800F6AF0 == 0) {
        func_80016C48(2, 0x34, arg0);
        func_80016C48(2, 0x22, arg0);
        D_800F6AF0 = (func_8002D2D4() & 3) | 0x28;
    } else {
        D_800F6AF0 = D_800F6AF0 - 1;
    }
    func_80017A04(arg0);
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xA) < D_800F6AF8 + 0x760) {
        t = M2C_FIELD(arg0, u8*, 0x47);
        if (t == 4) {
            return;
        }
        if (t != 5) {
            e = &D_800CCED0;
            if (M2C_FIELD(e, s8*, 0xC) != 0xC) {
                ((void (*)(s32, s32, s32))func_80021760)(
                    0, 0xFF, M2C_FIELD(e, u8*, 0x2E));
                M2C_FIELD(e, u8*, 0x2E) = 1;
            }
            ((void (*)(void*, s32))func_800179A4)(arg0, 0);
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}
