#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(s8);
void func_8001D218(void);
void func_8001FE74(void);
void* alloc_sprite_slot();
extern u8 D_800711C8;
extern s8 D_80097427;

void func_8001F1C8(void* arg0) {
    u8* p;
    u8* obj;
    u8 i;
    s32 one;

    func_8001D218();
    D_80097427 = 1;
    M2C_FIELD(arg0, u8*, 0x1F) = 0;
    M2C_FIELD(arg0, u8*, 0x24) = 0;
    ((void (*)(s8))func_800139A0)(8);
    p = &D_800711C8;
    i = 0;
    one = 1;
    if (*p != 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = one;
            obj[1] = 0x20;
            M2C_FIELD(obj, u8**, 0x50) = p;
            p++;
            M2C_FIELD(obj, s16*, 0xA) = D_800711C8;
            obj[0x55] = one;
        }
    } else {
        p++;
    }
    while (*p != 0xFF) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x1F;
            obj[2] = *p++;
            obj[7] = i++;
            M2C_FIELD(obj, s16*, 0xE) = *p++;
            M2C_FIELD(obj, s16*, 0xA) = *p++;
            obj[0x55] = one;
        }
    }
    func_8001FE74();
    M2C_FIELD(arg0, s16*, 8) = p[1];
    M2C_FIELD(arg0, u8*, 1) += 1;
}
