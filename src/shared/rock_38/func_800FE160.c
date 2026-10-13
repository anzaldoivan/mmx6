#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_800FA070(s8* self, u32 arg1);
extern M2C_UNK D_800FE82C;

void func_800FE160(void* arg0) {
    u8* p;

    p = (u8*)&D_800FE82C + 0x470;
    func_80027BA0(0, 0x22F0, 0x290, p);
    func_80027BA0(0, 0x2480, 0x290, p + 0x10);
    func_800FA070(arg0, 0x21);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x6)++;
    func_8002CCB0(arg0, 0x80, 0x80);
    func_8002D230(arg0);
}
