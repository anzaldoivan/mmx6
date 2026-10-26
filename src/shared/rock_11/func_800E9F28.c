#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object();
void func_800EAB04(void*);
extern s8 D_800970A2;

#define AIM(dir, ang)                                                          \
    func_800179A4(self, (dir));                                                \
    M2C_FIELD(self, s32*, 0x20) = rcos((ang)) << 5;                            \
    M2C_FIELD(self, s32*, 0x24) = rsin((ang)) << 5;                            \
    break;

void func_800E9F28(struct X4_BaseObj* self) {
    if (self->unk15 == 0) {
        if (D_800970A2 == 0) {
            switch (self->unk2) {
            case 16:
                AIM(1, 0x600)
            case 17:
                AIM(2, 0xA00)
            case 18:
                AIM(1, 0x400)
            case 19:
                AIM(2, 0xC00)
            }
        } else {
            switch (self->unk2) {
            case 16:
                AIM(2, 0xA00)
            case 17:
                AIM(1, 0x600)
            case 18:
                AIM(2, 0xC00)
            case 19:
                AIM(1, 0x400)
            }
        }
    } else {
        if (D_800970A2 == 0) {
            switch (self->unk2) {
            case 16:
                AIM(1, 0x200)
            case 17:
                AIM(2, 0xE00)
            case 18:
                AIM(1, 0x400)
            case 19:
                AIM(2, 0xC00)
            }
        } else {
            switch (self->unk2) {
            case 16:
                AIM(2, 0xE00)
            case 17:
                AIM(1, 0x200)
            case 18:
                AIM(2, 0xC00)
            case 19:
                AIM(1, 0x400)
            }
        }
    }
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    func_800EAB04(self);
    ((void (*)(void*))move_object)(self);
    self->unk6++;
}
