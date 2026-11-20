// rolefeed (3.1 T4): func_800F6D4C of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();
extern s16 D_800F986A;

void func_800F6D4C(void* arg0, s32 arg1) {
    void* obj;
    s16 ang;
    u16 cnt;
    s32 t;

    ang = arg1;
    obj = func_8002C458();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0x0) = 0x41;
        M2C_FIELD(obj, u8*, 0x1) = 0x16;
        M2C_FIELD(obj, u8*, 0x2) = 0x50;
        M2C_FIELD(obj, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(obj, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(obj, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(obj, s32*, 0x84) = ang;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(obj, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x24;
        } else {
            M2C_FIELD(obj, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x24;
        }
        M2C_FIELD(obj, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE) - 0xC;
        M2C_FIELD(obj, s16*, 0x8) = 0;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        t = M2C_FIELD(arg0, s32*, 0x80);
        cnt = D_800F986A;
        M2C_FIELD(obj, void**, 0x8C) = arg0;
        M2C_FIELD(obj, s32*, 0x7C) = t;
        D_800F986A = cnt + 1;
    }
}
