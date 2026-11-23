/* Adapted from sozud/mmx4 @29b62af src/main/misc/misc_17_death_orb.c:death_orb_fly, AGPL-3.0; proven shared with X6 by exact signature 2c7ffbc6b879 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
void func_80017A04(struct X4_AnimatedObj*);
void func_8002C9B0(struct X4_ObjectHeader* arg0);
void func_8002D2B0(struct X4_MovingObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);

void func_80047FB8(struct X4_MiscObj* self) {
    if ((self->unk2 & 0x80) &&
        (func_8002CBFC(BASE_OBJECT(self), 0x80000, 0x80000) == 1)) {
        func_8002C9B0(OBJECT_HEADER(self));
        return;
    }

    func_80017A04(ANIMATED_OBJECT(self));
    func_8002D2B0(MOVING_OBJECT(self));
    func_8002CCB0(BASE_OBJECT(self), 0x80000, 0x80000);
}
