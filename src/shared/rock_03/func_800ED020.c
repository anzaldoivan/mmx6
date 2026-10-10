#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);
extern struct X4_PlayerObj D_800970A0;

#define STATE(s) M2C_FIELD(s, u8*, 6)
#define XPOS(s) M2C_FIELD(s, s16*, 0xA)
#define YPOS(s) M2C_FIELD(s, s16*, 0xE)
#define TIMER(s) M2C_FIELD(s, s16*, 0x8C)
#define ABSDIFF(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))

void func_800ED020(void* self) {
    register u16 t asm("$2");

    func_80017A04();
    func_8002D2B0(self);
    t = TIMER(self);
    TIMER(self) = t + 1;
    if ((s16)t < 0x5B) {
        if (D_800970A0.x_pos.i.hi - XPOS(self) >= 0) {
            if (D_800970A0.x_pos.i.hi - XPOS(self) < 8) {
                goto near_x;
            }
        } else if (XPOS(self) - D_800970A0.x_pos.i.hi < 8) {
        near_x:
            if (D_800970A0.y_pos.i.hi - YPOS(self) >= 0) {
                if (D_800970A0.y_pos.i.hi - YPOS(self) < 0x20) {
                    goto next;
                }
            } else if (YPOS(self) - D_800970A0.y_pos.i.hi < 0x20) {
                goto next;
            }
        }
    } else {
    next:
        TIMER(self) = 0;
        STATE(self)++;
    }
}
