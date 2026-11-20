// rolefeed (3.1 T4): func_800F9DD0 of src/rock_11/E9860.c
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

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800FCEDC;
extern M2C_UNK D_800FCEE0;

void func_800F9DD0(void* arg0) {
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FCEDC;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FCEE0;
    if (M2C_FIELD(arg0, u8*, 0x8A) != 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = NULL;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = NULL;
    }
}
