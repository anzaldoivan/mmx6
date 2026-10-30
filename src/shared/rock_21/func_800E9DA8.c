#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800E9DA8(u8* arg0) {
    func_8002B410(&D_800EE840, &D_800ED640, 0x100, ++D_800F2242, 0x60);
    load_palette(0x70, &D_800EE840, 0x10);
    func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, --D_800F2244, 0x60);
    load_palette(0x80, &D_800F0C40, 0x10);
    if (D_800F2244 == 0) {
        __builtin_memcpy((u8*)&D_800ED640, (u8*)(SPAD28 + 0x1200), 0x200);
        func_8002B410(&D_800EE840, &D_800ED640, 0x100, D_800F2242, 0x60);
        load_palette(0x90, &D_800EE840, 0x10);
        background_objects[1].x_pos.u.hi = 0x600;
        background_objects[1].unk4C = 1;
        arg0[1]++;
    }
}
