#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_8009721E;

void func_800F4FF8(void* arg0) {
    func_80017A04();
    move_object((s32)arg0);
    {
        // !FAKE: retail reads the state field into the first return register
        register s32 st asm("$2") = M2C_FIELD(arg0, s16*, 0x8C);
        if (st == 0) {
            if (M2C_FIELD(arg0, s16*, 0xA) >=
                background_objects[0].unk26 + 0x30) {
                return;
            }
            if (background_objects[0].unk2A + 0xB0 >=
                M2C_FIELD(arg0, s16*, 0xE)) {
                return;
            }
        } else if (M2C_FIELD(arg0, s16*, 0xA) >= D_8009721E + 0x30) {
            return;
        }
    }
    M2C_FIELD(arg0, s16*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
