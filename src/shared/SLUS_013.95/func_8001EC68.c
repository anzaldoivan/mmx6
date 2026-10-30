#include "common.h"
#include "psyq/libgpu.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_str_movie(s32); /* extern */
extern M2C_UNK D_8007119C;
extern M2C_UNK D_800711A4;

void func_8001EC68(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 1) == 0) {
        MoveImage(&D_8007119C, 0x240, 0);
        DrawSync(0);
        if ((M2C_FIELD(arg0, s8*, 0xC) == 0xB) &&
            (M2C_FIELD(arg0, s8*, 0x38) != 0)) {
            play_str_movie(8);
        }
        if (M2C_FIELD(arg0, s8*, 0xC) == 0xC) {
            if (M2C_FIELD(arg0, s8*, 0x38) != 0) {
                play_str_movie(9);
            }
        }
        MoveImage(&D_800711A4, 0x140, 0xB0);
        DrawSync(0);
        M2C_FIELD(arg0, s8*, 1) = (s8)((u8)M2C_FIELD(arg0, s8*, 1) + 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    M2C_FIELD(arg0, s8*, 0) = 8;
    M2C_FIELD(arg0, s8*, 1) = 0;
}
