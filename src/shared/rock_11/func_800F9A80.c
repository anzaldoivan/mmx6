// rolefeed (3.1 T4): func_800F9A80 of src/rock_11/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"
#define M2C_UNK s32

s32 random_byte();
void func_800F9F7C(void* arg0, M2C_UNK arg1, M2C_UNK arg2);
extern s16 D_800FDA80;

void func_800F9A80(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == -1) {
        *(s16*)(arg0 + 0x7C) = 2;
        if (--*(s16*)(arg0 + 0x7E) == 0) {
            arg0[6]++;
            return;
        }
        {
            s16* p = &D_800FDA80;
            s32 v = random_byte() + 0xFF;
            *p += v;
            func_800F9F7C(arg0, 0, *p);
        }
    }
}
