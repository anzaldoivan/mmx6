#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800EEBF0(void* arg0) {
    s8 t = S8(arg0, 0x45);

    if (t == 1) {
        set_animation(arg0, 0);
        {
            struct X4_EngineObj* p = &g_playthrough_state;
            open_text_box(0, 0xFF, F8(p, 0x2E));
            F8(p, 0x2E) = t;
        }
        F8(arg0, 6) += 1;
    }
}
