#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800F168C(void* arg0) {
    u8* sp;
    u8 t;

    sp = SPAD4C;
    t = sp[0x8B];
    if (t != 0) {
        sp[0x8B] = t - 1;
        if (!(SPAD4C[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        }
        sp = SPAD4C;
        if (sp[0x8B] == 0) {
            sp[0x8B] = 0x78;
        }
    }
    ((void (*)(void*))func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        ((void (*)(void*))move_object)(arg0);
        if (background_objects[0].unk22 - 0x40 >= M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk22 - 0x40;
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s16*, 0xA) =
                    background_objects[0].unk1C + 0x100;
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else {
                M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk1E + 0x40;
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            SPAD4C[0x8B] = 0x78;
        }
    }
}
