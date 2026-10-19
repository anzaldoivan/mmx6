#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CB50(struct X4_BaseObj*);
extern s32 D_80097420;

void func_80046A60(void* self, s32 arg1, u8* p) {
    if (M2C_FIELD(self, s8*, 0x2) == -1) {
        p = (u8*)&D_80097420;
        if (M2C_FIELD(self, u8*, 0x54) != p[7]) {
            M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(self, u8**, 0x50)[p[7] * 2];
            M2C_FIELD(self, u8*, 0x54) = p[7];
        }
    }
    ((s32(*)())func_8002CB50)(self, self, p);
}
