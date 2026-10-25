#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEF7;
extern u8 D_800F4BF0[];

void func_800ED510(void* arg0) {
    u32 v;

    if (D_800CCEF7 != 0) {
        M2C_FIELD(arg0, u16*, 0x16) = 0;
        M2C_FIELD(arg0, u16*, 0x18) = 0;
    }
    ((void (**)(void*))(D_800F4BF0 + 0x14BC))[M2C_FIELD(arg0, s8*, 4)](arg0);
    if (M2C_FIELD(arg0, u16*, 0x1E) != 0) {
        M2C_FIELD(arg0, u16*, 0x14)++;
        v = M2C_FIELD(arg0, u16*, 0x14);
        if (!(v & 3)) {
            if ((v >> 2) >= 5) {
                M2C_FIELD(arg0, u16*, 0x14) = 0;
            }
            {
                u8* p = (u8*)background_objects;
                u32 t = M2C_FIELD(arg0, u16*, 0x14);
                M2C_FIELD(p, u8*, 0xA0) = 1;
                M2C_FIELD(p, s16*, 0x62) = (t >> 2) << 8;
            }
        }
    }
}
