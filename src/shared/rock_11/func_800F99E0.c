// rolefeed (3.1 T4): func_800F99E0 of src/rock_11/E9860.c
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
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void* alloc_class3_slot();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern s8* D_800FDA74;

void func_800F99E0(u8* arg0) {
    s8 s;
    s8* p;

    if (g_playthrough_state.unkF == 0) {
        s = D_800970A5;
        if (s == 0x14) {
            if (g_playthrough_state.stage != 0xC) {
                func_8003D308(0x1D, 0x40);
            }
            p = alloc_class3_slot();
            if (p != 0) {
                p[0] = 1;
                p[1] = 0x18;
                D_800FDA74 = p;
            }
            *(s16*)(arg0 + 0x7C) = s;
            arg0[6]++;
        }
    }
}
