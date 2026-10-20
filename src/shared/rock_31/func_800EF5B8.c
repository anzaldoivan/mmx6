#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D380(void*, void*);
#define M2C_UNK s32
extern M2C_UNK D_800970A0;

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800EF5B8(void* arg0) {
    if (--F(s16, 0x7E) == 0) {
        if (F(u8, 0x15) == 0) {
            F(s16, 0xA) -= 6;
        } else {
            F(s16, 0xA) += 6;
        }
        F(u8, 0x81) = func_8002D380(arg0, &D_800970A0);
        if (F(u8, 0x15) == 0) {
            F(s16, 0xA) += 6;
        } else {
            F(s16, 0xA) -= 6;
        }
        F(u8, 0x6)++;
    }
}
#undef F
