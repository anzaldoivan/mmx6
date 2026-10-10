#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CD40C;
extern M2C_UNK D_800ED240;
extern M2C_UNK D_800ED440;
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern M2C_UNK D_800F1E40;
extern M2C_UNK D_800F2040;
extern s16 D_800F2240;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800E9864(u8* arg0) {
    if ((u8)D_800CD40C == 2) {
        {
            u8* s = (u8*)SPAD28;
            __builtin_memcpy((u8*)&D_800ED240, s + 0xC00, 0x20);
            __builtin_memcpy((u8*)&D_800ED640, s + 0xE00, 0x200);
        }
        __builtin_memcpy((u8*)&D_800EFA40, (u8*)(SPAD28 + 0x1000), 0x200);
        __builtin_memcpy((u8*)&D_800F1E40, (u8*)(SPAD28 + 0xC20), 0x20);
        D_800F2240 = 0x60;
        D_800F2242 = 0x60;
        D_800F2244 = 0x60;
        func_8002B410(&D_800ED440, &D_800ED240, 0x10, 0x60, 0x60);
        func_8002B3D4(0x60, &D_800ED440, 1);
        func_8002B410(&D_800EE840, &D_800ED640, 0x100, D_800F2242, 0x60);
        func_8002B3D4(0x70, &D_800EE840, 0x10);
        func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, D_800F2244, 0x60);
        func_8002B3D4(0x80, &D_800F0C40, 0x10);
        func_8002B410(&D_800F2040, &D_800F1E40, 0x10, D_800F2240, 0x60);
        func_8002B3D4(0x61, &D_800F2040, 1);
        D_800971F8[0].x_pos.u.hi = 0;
        D_800971F8[0].y_pos.u.hi = 0;
        D_800971F8[0].unk4C = 1;
        D_800971F8[1].x_pos.u.hi = 0x200;
        D_800971F8[1].y_pos.u.hi = 0;
        D_800971F8[1].unk4C = 1;
        D_800971F8[2].x_pos.u.hi = 0x400;
        D_800971F8[2].y_pos.u.hi = 0;
        D_800971F8[2].unk4C = 1;
        D_800971F8[0].unk3 = 1;
        D_800971F8[1].unk3 = 1;
        D_800971F8[2].unk3 = 1;
        arg0[1]++;
    }
}
