#include "common.h"
#define M2C_UNK s32

void func_800EAA2C();
extern s8 D_800970A2;

#define F7_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F7_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F7_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800EC7F4(void* arg0) {
    if (--F7_S16(arg0, 0x7C) == 0) {
        if (D_800970A2 == 0) {
            switch (F7_S8(arg0, 2)) {
            case 32:
                func_800EAA2C(arg0, 0x10);
                break;
            case 33:
                func_800EAA2C(arg0, 0x11);
                break;
            case 34:
                func_800EAA2C(arg0, 0x12);
                break;
            }
        } else {
            switch (F7_S8(arg0, 2)) {
            case 32:
                func_800EAA2C(arg0, 0x20);
                break;
            case 33:
                func_800EAA2C(arg0, 0x21);
                break;
            case 34:
                func_800EAA2C(arg0, 0x22);
                break;
            }
        }
        F7_U8(arg0, 6)++;
    }
}

#undef F7_S8
#undef F7_U8
#undef F7_S16
