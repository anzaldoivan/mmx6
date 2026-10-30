#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

void func_800F5A1C(void* arg0) {
    s32 var_v1;
    struct X4_BackgroundObj* bg;

    if (SB(arg0, 0x45) == 1) {
        set_animation(arg0, 4);
        {
            // !FAKE: depin: dropping it breaks the match (33/35)
            register s32 f asm("$2") = B(arg0, 0x15);
            if (f == 0) {
                bg = background_objects;
                var_v1 = (u16)bg->unk26 + 0x30;
            } else {
                bg = background_objects;
                var_v1 = (u16)bg->unk26 + 0x130;
            }
            H(arg0, 0x84) = var_v1;
            {
                // !FAKE: depin: dropping it breaks the match (32/35)
                register s32 t asm("$4") = (u16)bg->unk2A + 0x50;
                H(arg0, 0x86) = t;
            }
        }
        do {
            B(arg0, 0x6)++;
        } while (0);
    }
}
