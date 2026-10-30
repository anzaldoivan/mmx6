#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001FE74(void);
void* alloc_sprite_slot();

u8 func_8001F65C(u8* arg0, s32 arg1) {
    u8* p;
    u8* obj;
    u8 i;
    u8 b;

    p = arg0;
    i = 0;
    b = arg1;
    if (*p != 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x20;
            M2C_FIELD(obj, u8**, 0x50) = p;
            M2C_FIELD(obj, s16*, 0xA) = *p++;
            obj[0x55] = b;
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
            obj[0x55] = b;
        }
    }
    func_8001FE74();
    return p[1];
}
