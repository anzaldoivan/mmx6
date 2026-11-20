// rolefeed (3.1 T4): func_800F7024 of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#define M2C_UNK s32

extern M2C_UNK clear_object_slot();
extern s16 D_800F9868;
extern s16 D_800F986A;

void func_800F7024(u8* arg0) {
    s32 kind;

    kind = *(s8*)(arg0 + 2) & 0xF0;
    if (kind == 0x20) {
        D_800F9868--;
    } else if (kind == 0x50 && arg0[0x96] == 1) {
        D_800F986A--;
    }
    ((M2C_UNK(*)())clear_object_slot)(arg0, kind);
}
