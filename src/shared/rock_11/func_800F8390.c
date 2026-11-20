// rolefeed (3.1 T4): func_800F8390 of src/rock_11/E9860.c
#include "common.h"
#include "mmx6/rock_11.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 check_enemy_hits(void*);
s32 func_800FA664(u8* arg0);
extern s32 D_800FD44C;

void func_800F8390(void* arg0) {
    s32 temp_v0;
    s8 temp_s1;

    temp_s1 = M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 4);
    if (temp_s1 != 1) {
        M2C_FIELD(arg0, s8*, 4) = 6;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    animate_object(arg0);
    (*(void (**)(void*))((M2C_FIELD(arg0, s8*, 5) << 2) + (s32)&D_800FD44C))(
        arg0);
    temp_v0 = check_enemy_hits(arg0);
    if (temp_v0 > 0) {
        if ((D_800970A2 != 0) || (temp_v0 == temp_s1)) {
            M2C_FIELD(arg0, s8*, 0x8A) = temp_s1;
        }
        M2C_FIELD(arg0, s8*, 0x5C) = 0x32;
    }
    if (func_800FA664(arg0) != 0) {
        M2C_FIELD(arg0, s8*, 0x8A) = 1;
    }
}
