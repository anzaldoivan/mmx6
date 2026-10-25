#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F5164(void* arg0) {
    s16 y;

    func_80017A04();
    move_object((s32)arg0);
    y = M2C_FIELD(arg0, s16*, 0xA);
    if (y < background_objects[0].unk26 - 0x50 ||
        background_objects[0].unk24 + 0x190 < y) {
        M2C_FIELD(arg0, u8*, 0x4) = 2;
    }
}
