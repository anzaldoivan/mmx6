#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;
extern s8 D_800CCEDF;

void func_800F2F5C(void* arg0) {
    if (D_800CCEDF == 0) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
            if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            func_800F0434(arg0, 0x1F);
            func_80017A04(arg0);
            {
                // !FAKE: depin: dropping it breaks the match (43/46)
                register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
                M2C_FIELD(arg0, u16*, 0x7C) = 0;
                M2C_FIELD(arg0, u8*, 6) = t;
            }
        }
    }
}
