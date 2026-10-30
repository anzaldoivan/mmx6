#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
extern s16 D_800970AA;
extern u8 D_800CCF38;

void func_800EE468(void* arg0) {
    s32 cnt;
    void* obj;

    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    cnt = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    M2C_FIELD(arg0, u16*, 0x7C) = cnt;
    if (D_800CCF38 == 2) {
        if ((s16)cnt == 0x18 || (s16)cnt == 0x54) {
            play_sound(2, 6, arg0);
            obj = func_8002C458();
            if (obj != 0) {
                u8 kind = M2C_FIELD(arg0, u8*, 0x0);
                M2C_FIELD(obj, u8*, 0x1) = 1;
                M2C_FIELD(obj, u8*, 0x2) = 1;
                M2C_FIELD(obj, void**, 0x7C) = arg0;
                M2C_FIELD(obj, u8*, 0x0) = kind;
            }
        }
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0xDC) {
            M2C_FIELD(arg0, u8*, 0x5) = 5;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        }
    } else {
        if ((s16)cnt == 0x18) {
            play_sound(2, 6, arg0);
            obj = func_8002C458();
            if (obj != 0) {
                u8 kind = M2C_FIELD(arg0, u8*, 0x0);
                M2C_FIELD(obj, u8*, 0x1) = 1;
                M2C_FIELD(obj, u8*, 0x2) = 1;
                M2C_FIELD(obj, void**, 0x7C) = arg0;
                M2C_FIELD(obj, u8*, 0x0) = kind;
            }
        }
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0xA0) {
            M2C_FIELD(arg0, u8*, 0x5) = 5;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        }
    }
}
