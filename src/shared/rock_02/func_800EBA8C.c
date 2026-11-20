#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800FAD30[][4];

s32 func_800179A4(void*, s32);
void func_8002C9B0();
s32 func_8002CBFC();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800EBA8C(struct ObjectHeader* arg0) {
    struct ObjectHeader* parent = M2C_FIELD(arg0, struct ObjectHeader**, 0x50);
    u8 kind;

    M2C_FIELD(arg0, u8*, 0x47) = D_800FAD30[M2C_FIELD(parent, u8*, 0x47)]
                                           [M2C_FIELD(parent, s8*, 0x44) - 1];
    arg0->x_pos = parent->x_pos;
    arg0->y_pos = parent->y_pos;
    if (parent->action == 3) {
        M2C_FIELD(arg0, u8*, 0x47) =
            D_800FAD30[M2C_FIELD(parent, u8*, 0x47)][3];
        if (parent->action_phase == 2) {
            kind = M2C_FIELD(parent, u8*, 0x47);
            if (kind == 0 || kind == 4) {
                func_800179A4(arg0, 4);
            } else if (kind == 1 || kind == 5) {
                func_800179A4(arg0, 5);
            } else if (kind == 2 || kind == 6) {
                func_800179A4(arg0, 6);
            } else if (kind == 3 || kind == 7) {
                func_800179A4(arg0, 7);
            }
            arg0->state++;
        }
    }
    if (func_8002CBFC(arg0, 0x80, 0x80) == 0) {
        func_8002CCB0(arg0, 0x60, 0x60);
    } else {
        func_8002C9B0(arg0);
    }
    if (parent->state == 2) {
        func_8002C9B0(arg0);
    }
}
