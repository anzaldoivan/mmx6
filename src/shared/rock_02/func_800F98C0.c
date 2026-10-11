#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
struct X4_QuadObj* func_8002C7F0(void);
s32 func_8002D2D4();

void func_800F98C0(void* arg0) {
    s8 state;
    void* parent;
    struct X4_QuadObj* q;
    u8 kind;

    state = M2C_FIELD(arg0, s8*, 0x45);
    parent = M2C_FIELD(arg0, void**, 0x50);
    if (state == 1) {
        M2C_FIELD(arg0, u8*, 0x54) = 0x78;
        M2C_FIELD(parent, u8*, 0x5) = 5;
        M2C_FIELD(arg0, u8*, 0x5)++;
    } else if (state == 2) {
        M2C_FIELD(parent, u16*, 0x42) |= 0x8000;
        kind = M2C_FIELD(arg0, u8*, 0x47);
        if (kind == 0x12 || kind == 0x14 || kind == 0x18) {
            q = func_8002C7F0();
            if (q != 0) {
                q->active = 0x13;
                q->id = 0xF;
                switch (func_8002D2D4() % 3) {
                case 0:
                    M2C_FIELD(q, s32*, 0x38) = 0;
                    break;
                case 1:
                    M2C_FIELD(q, s32*, 0x38) = 0x400;
                    break;
                case 2:
                    if (M2C_FIELD(arg0, u8*, 0x15) == 0x40) {
                        M2C_FIELD(q, s32*, 0x38) = 0xE00;
                    } else {
                        M2C_FIELD(q, s32*, 0x38) = 0x200;
                    }
                    break;
                }
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    q->x_pos.i.hi = M2C_FIELD(arg0, u16*, 0xA) + 0x38;
                } else {
                    q->x_pos.i.hi = M2C_FIELD(arg0, u16*, 0xA) - 0x38;
                }
                func_80016C48(2, 0x68, arg0);
                q->y_pos.i.hi = M2C_FIELD(arg0, u16*, 0xE);
                q->unk36 = 0;
                q->bg_offset = M2C_FIELD(arg0, u8*, 0x14);
                q->unk34 = 0x13;
            }
        }
    }
}
