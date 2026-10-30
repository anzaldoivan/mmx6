#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK end_dash(s32);

void func_801EBC58(struct X4_MainObj* self) {
    struct X4_VisualObj* v;

    func_80017A04((struct X4_AnimatedObj*)self);
    if (self->unk6 == 0 && (self->animation_step.fields.event & 0x80)) {
        v = func_8002C398();
        if (v != 0) {
            v->active = 9;
            v->id = 0x17;
            v->unk2 = 0;
            v->animation_step.fields.frame_index = 3;
        }
        self->unk6++;
    }
    if (self->animation_step.fields.relative_step == 0) {
        end_dash((s32)self);
    }
}
