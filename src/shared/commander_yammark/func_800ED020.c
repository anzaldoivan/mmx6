#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
extern struct X4_PlayerObj g_Player;

#define STATE(s) M2C_FIELD(s, u8*, 6)
#define XPOS(s) M2C_FIELD(s, s16*, 0xA)
#define YPOS(s) M2C_FIELD(s, s16*, 0xE)
#define TIMER(s) M2C_FIELD(s, s16*, 0x8C)
#define ABSDIFF(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))

void func_800ED020(void* self) {
    // !FAKE: depin: dropping it breaks the match (46/53)
    register u16 t asm("$2");

    func_80017A04();
    move_object(self);
    t = TIMER(self);
    TIMER(self) = t + 1;
    if ((s16)t < 0x5B) {
        if (g_Player.x_pos.i.hi - XPOS(self) >= 0) {
            if (g_Player.x_pos.i.hi - XPOS(self) < 8) {
                goto near_x;
            }
        } else if (XPOS(self) - g_Player.x_pos.i.hi < 8) {
        near_x:
            if (g_Player.y_pos.i.hi - YPOS(self) >= 0) {
                if (g_Player.y_pos.i.hi - YPOS(self) < 0x20) {
                    goto next;
                }
            } else if (YPOS(self) - g_Player.y_pos.i.hi < 0x20) {
                goto next;
            }
        }
    } else {
    next:
        TIMER(self) = 0;
        STATE(self)++;
    }
}
