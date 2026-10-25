#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F33C0(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (46/51)
    register s32 x asm("$5");
    // !FAKE: depin: dropping it breaks the match (47/51)
    register s32 l asm("$4");

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        x = background_objects[0].unk1E;
        l = x - 0x140;
        if (M2C_FIELD(arg0, s16*, 0xA) >=
            x + (background_objects[0].unk1C - l) / 2) {
            return;
        }
    } else {
        x = background_objects[0].unk1E;
        l = x - 0x140;
        if (x + (background_objects[0].unk1C - l) / 2 >=
            M2C_FIELD(arg0, s16*, 0xA)) {
            return;
        }
    }
    func_80016C48(2, 0x23, arg0);
    func_800179A4(arg0, 7);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    {
        // !FAKE: depin: dropping it breaks the match (48/51)
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, u8*, 6) = t;
    }
}
