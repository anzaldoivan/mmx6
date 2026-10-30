#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(s8);
void stop_cd_audio();
s32 func_8002B2F8(s32);
void reset_level(void);
void* alloc_sprite_slot();
extern u8 D_800710E0[];
extern s8 D_80097426;
extern s32 D_800E3130[];

void func_8001DA20(void* arg0) {
    u8* obj;
    u8 i;

    D_80097426 = 0;
    stop_cd_audio();
    func_8002B2F8(0);
    i = 0;
    reset_level();
    do {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x13;
            obj[2] = D_800710E0[i];
        }
        i++;
    } while (i < 6);
    ((void (*)(s8))func_800139A0)(8);
    M2C_FIELD(arg0, s16*, 4) = 0;
    M2C_FIELD(arg0, u8*, 1) += 1;
    D_800E3130[0] = 0;
    D_800E3130[1] = 0;
}
