#include "common.h"
#define M2C_UNK s32
void* alloc_class3_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FS8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F47A0(void* arg0) {
    void* obj;
    s32 t;

    if (--*(s16*)((u8*)arg0 + 0x7C) == 0) {
        obj = alloc_class3_slot();
        if (obj != 0) {
            F8(obj, 0) = 1;
            F8(obj, 1) = 0x1A;
            F16(obj, 0xA) = F16(arg0, 0xA);
            F16(obj, 0xE) = F16(arg0, 0xE);
            F32(arg0, 0x80) = obj;
        }
        F8(arg0, 5)++;
    }
    if (--*(s16*)((u8*)arg0 + 0x7E) == -1) {
        F16(arg0, 0x42) ^= 0x8000;
        FS8(arg0, 0x61) -= 5;
        if (FS8(arg0, 0x61) >= 0x1A) {
            FS8(arg0, 0x61) = 0;
        }
        t = FS8(arg0, 0x61);
        {
            s32 v;
            v = t < 6;
            if (v == 0) {
                v = t;
            } else {
                v = 5;
            }
            *(s16*)((u8*)arg0 + 0x7E) = v;
        }
    }
    func_8002CCB0(arg0, 0x80, 0x80);
}
#undef F8
#undef FS8
#undef F16
#undef F32
