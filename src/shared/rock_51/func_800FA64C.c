#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800FAA08;
extern M2C_UNK D_800FBC08;
extern s16 D_800FCE08;

void func_800FA64C(void* arg0) {
    D_800FCE08 += 1;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        &D_800FBC08, &D_800FAA08, 0x900, D_800FCE08);
    func_8002B3D4(0x60, &D_800FBC08, 0x90);
    if (D_800FCE08 >= 0x20) {
        s8* bg = (s8*)background_objects;

        M2C_FIELD(bg, s16*, 0xB2) = 0;
        M2C_FIELD(bg, s16*, 0xB6) = 0x200;
        M2C_FIELD(bg, u8*, 0xF4) = 1;
        M2C_FIELD(bg, u8*, 0x57) = 0;
        M2C_FIELD(arg0, u16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}
