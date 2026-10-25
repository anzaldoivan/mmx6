#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230(s32);
s32 func_8002D2D4();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);

extern M2C_UNK D_800F5D38;
extern M2C_UNK D_800F5D3C;

void func_800EF7B4(struct X4_MainObj* self) {
    func_8002D230(self);
    {
        // !FAKE: depin: dropping it breaks the match (39/42)
        register s32 y asm("$2") = self->y_speed;
        s32 k = -0x20000;
        if (y < k) {
            self->y_speed = k;
        }
    }
    if (self->collision_flags & 8) {
        func_80016C48(2, 0x52, self);
        func_80049E50(self);
        if (func_8002D2D4() & 1) {
            func_800477E4(2, &D_800F5D38, self);
        } else {
            func_800477E4(2, &D_800F5D3C, self);
        }
        self->state = 2;
    }
}
