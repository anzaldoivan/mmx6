#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);
extern s32 D_800FCA84;

void func_800FB414(void* arg0) {
    if ((M2C_FIELD(arg0, void**, 0x68) == 0) &&
        (M2C_FIELD(arg0, s16*, 0xE) >= 0x12C)) {
        M2C_FIELD(arg0, void**, 0x68) = &D_800FCA84;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (is_text_box_seen(2) == 0) {
            open_text_box(2, 0xFF, 0);
            set_text_box_seen(2);
        }
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        {
            // !FAKE: puts the byte increment in the first return register
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
    func_80017A04(arg0);
    move_object(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
