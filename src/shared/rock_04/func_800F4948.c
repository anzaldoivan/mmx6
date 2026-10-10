#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
struct X4_EffectObj* func_8002C3F8(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern struct X4_EngineObj D_800CCED0;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F4948(void* arg0) {
    s8 t;
    void* obj;

    if (D_800CCED0.unkF == 0) {
        t = D_800970A5;
        if (t == 0x14) {
            if (D_800CCED0.stage != 0xC) {
                func_8003D308(0x1D, 0x40);
            }
            obj = func_8002C3F8();
            if (obj != 0) {
                F8(obj, 0) = 1;
                F8(obj, 1) = 0x18;
                F32(arg0, 0x80) = obj;
            }
            F16(arg0, 0x7C) = t;
            F8(arg0, 6)++;
        }
    }
}
#undef F8
#undef F16
#undef F32
