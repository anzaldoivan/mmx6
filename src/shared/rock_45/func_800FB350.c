#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);        /* extern */
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEDF;

void func_800FB350(void* arg0) {
    if (D_800CCEDF == 0) {
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0x28) {
            M2C_FIELD(arg0, s32*, 0x94) = background_objects[0].unk26;
            background_objects[0].unk26 = background_objects[0].unk24 - 0x10;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
            func_80016C48(2, 0x47, arg0);
            func_800179A4(arg0, 0);
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFF80000;
            {
                // !FAKE: puts the byte increment in the first return register
                register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
                M2C_FIELD(arg0, u8*, 6) = t;
            }
        }
    }
}
