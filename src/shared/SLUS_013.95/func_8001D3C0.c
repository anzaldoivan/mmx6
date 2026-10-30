#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0);
s32 play_str_movie(s32 arg0);
extern s32 D_800CD408;

void func_8001D3C0(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    D_800CD408 = 0x80103000;
    set_resolution(0);
    ((void (*)(s32))play_str_movie)(1);
    M2C_FIELD(arg0, u8*, 0x1) += 1;
}
