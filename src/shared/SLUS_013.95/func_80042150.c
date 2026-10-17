#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_80042B68(void* arg0, u8 arg1);
void func_80042C18(struct X4_MainObj* self);
extern u8 D_800CCF38;

void func_80042150(struct X4_MainObj* self) {
    s16 v;

    if (--self->unk7C == 0) {
        func_80042C18(self);
        func_80016C48(2, 0x42, self);
        func_80042B68(self, 0);
        if (--self->unk7E == 0) {
            self->unk7C = 0x28;
            self->unk6++;
            return;
        }
        switch (D_800CCF38) {
        case 0:
            v = 0x5A;
            break;
        case 1:
            v = 0x3C;
            break;
        case 2:
        default:
            v = 0x1E;
            break;
        }
        self->unk7C = v;
    }
}
