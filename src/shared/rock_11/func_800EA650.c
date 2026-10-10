#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_8002D2B0();
void func_800EAB04(void*);
extern u16 D_80097202;
#define D_80097202 (*(s16*)&D_80097202)
extern u8 D_800FB26C[];

void func_800EA650(void* self) {
    ((void (**)(void*))(D_800FB26C + 0xB7C))[M2C_FIELD(self, s8*, 0x6)](self);
    func_8002D2B0(self);
    {
        register u8* p asm("$2") = SPAD;
        if (p[0x88] == 0) {
            if ((M2C_FIELD(self, u8*, 0x15) == 0 &&
                 M2C_FIELD(self, s16*, 0xA) < D_80097202 + 0xA0) ||
                (M2C_FIELD(self, u8*, 0x15) == 0x40 &&
                 D_80097202 + 0xA0 < M2C_FIELD(self, s16*, 0xA))) {
                SPAD[0x88] = 1;
                func_800EAB04(self);
            }
        }
    }
}
#undef D_80097202
