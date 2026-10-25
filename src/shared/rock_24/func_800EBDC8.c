#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object();
M2C_UNK func_8002EE10(void*);
M2C_UNK func_8002F288(M2C_UNK*);
#define func_8002F288 ((M2C_UNK(*)(void*))func_8002F288)
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((s32(*)(void*))func_80030ECC)
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern s16 D_800970AE;

#define FLAGS self->collision_flags
#define XPOS self->y_pos.i.hi

void func_800EBDC8(struct X4_MainObj* self) {
    s32 r;
    u8 flags;
    s16 f;
    s16 t;
    void* p;
    u16 g;

    self->unk42 &= 0x7FFF;
    if (self->unk6 != 0) {
        self->unk6--;
        return;
    }
    func_80017A04(self);
    move_object(self);
    r = func_80031474(self);
    if (self->unk2 == 0) {
        flags = FLAGS;
        self->on_screen = 1;
        func_8002F288(self);
        func_80030ECC(self);
        if (*(volatile u8*)&FLAGS == 0) {
            func_8002EE10(self);
        }
        f = FLAGS;
        if (flags & 8) {
            if (f & 8) {
                self->y_speed = 0;
                self->gravity = 0;
            }
            f = g = FLAGS;
            if (!(g & 8)) {
                goto set2; // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
            }
        }
        if ((f & 2) || (f & 1)) {
            goto set2; // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
        }
        if (func_8002CBFC(self, 0x20, 0x20) != 0) {
            self->state = 2;
            return;
        }
        goto approach; // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
    } else if (self->unk2 == 1) {
        t = M2C_FIELD(self, s16*, 0x8C);
        self->on_screen = 1;
        if (t != 0) {
            M2C_FIELD(self, s16*, 0x8C)--;
            if (t < 0x28) {
                if (D_800970AE > XPOS + 8) {
                    XPOS += 2;
                } else if (D_800970AE < XPOS - 8) {
                    XPOS -= 2;
                }
            }
        }
        if (func_80030ECC(self) != 0) {
        turn:
            func_80049E50(self);
            goto set2; // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
        }
        if (r < 0 || FLAGS != 0) {
            goto turn; // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
        }
        func_8002EE10(self);
        if (FLAGS != 0) {
            goto turn; // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
        }
        if (func_8002CBFC(self, 0x20, 0x20) != 0) {
            goto set2; // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
        }
    approach:
        func_8002CCB0(self, 0x10, 0x10);
        return;
    } else {
        self->on_screen = 0;
        func_80030ECC(self);
        p = M2C_FIELD(self, void**, 0x7C);
        if (M2C_FIELD(p, s8*, 0x45) == 3 || M2C_FIELD(p, s8*, 4) == 2 ||
            M2C_FIELD(p, s8*, 4) == 3) {
        set2:
            self->state = 2;
            return;
        }
        if (func_8002CBFC(self, 0x20, 0x20) == 1) {
            self->state = 2;
        }
    }
}
#undef func_8002F288
#undef func_80030ECC
