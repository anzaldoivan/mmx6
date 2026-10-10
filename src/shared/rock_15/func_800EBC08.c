#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C530();
s32 func_8002D2D4();

extern struct X4_PlayerObj D_800970A0;

void func_800EBC08(u8* self) {
    u8* obj;
    s32 d;
    s32 py;
    s32 sy;

    if (self[0x8D] != 0) {
        if (self[0x8D] == 0x21) {
            self[0x93] = 1;
        }
        self[0x8D]--;
        py = D_800970A0.y_pos.i.hi;
        sy = M2C_FIELD(self, s16*, 0xE) + 8;
        d = py - sy;
        if (d >= 0) {
            if (d < 3) {
                M2C_FIELD(self, s32*, 0x24) = 0;
            } else {
                goto far;
            }
        } else if (sy - py >= 3) {
        far:
            if (D_800970A0.y_pos.i.hi - 8 >= M2C_FIELD(self, s16*, 0xE)) {
                M2C_FIELD(self, s32*, 0x24) = 0xFFFE0000;
            } else {
                M2C_FIELD(self, s32*, 0x24) = 0x20000;
            }
        } else {
            goto zero;
        }
    } else {
    zero:
        M2C_FIELD(self, s32*, 0x24) = 0;
    }
    if (self[0x8E] != 0) {
        self[0x8E]--;
    } else if (self[0x91] != 0) {
        obj = func_8002C530();
        if (obj != 0) {
            obj[0] = 0x21;
            obj[1] = 0x19;
            obj[2] = 0;
            obj[0x15] = func_8002D2D4() & 0x40;
            obj[0x54] = 0;
            if (self[0x15] == 0) {
                M2C_FIELD(obj, s16*, 0xA) = M2C_FIELD(self, s16*, 0xA) + 0x10;
            } else {
                M2C_FIELD(obj, s16*, 0xA) = M2C_FIELD(self, s16*, 0xA) - 0x10;
            }
            M2C_FIELD(obj, s16*, 0xE) = M2C_FIELD(self, s16*, 0xE);
            M2C_FIELD(obj, s32*, 0x20) = 0;
            M2C_FIELD(obj, s32*, 0x24) = 0;
            obj[7] = 1;
            obj[0x16] = 7;
        }
        self[0x8E] = 1;
    }
}
