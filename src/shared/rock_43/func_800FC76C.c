#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern s32 D_800FDE30;

void func_800FC76C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        // !FAKE: depin: dropping it breaks the match (28/37)
        register s32 i asm("$3");
        s32 t;
        set_animation(arg0, 0);
        t = (s32)((u8*)&D_800FDE30 + 0x284);
        i = M2C_FIELD(arg0, u8*, 0x87)++;
        i = i + M2C_FIELD(arg0, u8*, 0x86) * 6 + t;
        M2C_FIELD(arg0, u8*, 5) = *(u8*)i;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
    animate_object(arg0);
    apply_object_motion(arg0);
}
