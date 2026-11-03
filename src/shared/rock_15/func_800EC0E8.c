#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800EC0E8(void* arg0) {
    s32 var_v0;
    s8 temp_s1;

    ((void (*)())animate_object)();
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            // !FAKE: depin: dropping it breaks the match (46/53)
            register s32 t asm("$2") = M2C_FIELD(arg0, s32*, 0x84) + 1;
            M2C_FIELD(arg0, s32*, 0x84) = t;
            var_v0 = t < D_800CCF08 + 3;
        } else {
            var_v0 = M2C_FIELD(arg0, s32*, 0x84) + 1;
            M2C_FIELD(arg0, s32*, 0x84) = var_v0;
            var_v0 = var_v0 < 4;
        }
        if (var_v0 == 0) {
            temp_s1 = M2C_FIELD(arg0, s8*, 2);
            if (temp_s1 == 2) {
                set_animation(arg0, 0);
                M2C_FIELD(arg0, u8*, 5) = temp_s1;
                M2C_FIELD(arg0, u16*, 0x7C) = 0x78;
            } else {
                M2C_FIELD(arg0, u8*, 5) = 4;
                M2C_FIELD(arg0, u16*, 0x7C) = 0x14;
            }
            M2C_FIELD(arg0, s32*, 0x84) = 0;
        }
    }
}
