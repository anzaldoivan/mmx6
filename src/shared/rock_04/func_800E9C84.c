#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_800F69F8;
extern M2C_UNK D_800F6A94;

void func_800E9C84(struct X4_BaseObj* self) {
    u8 flags;
    s8* p;

    if (func_80031474(self) < 0) {
        goto die;
    }
    flags = M2C_FIELD(self, u8*, 0x70);
    if ((flags & 0xC) == 0xC || (flags & 3) == 3) {
        func_80049E50(self);
        func_800477E4(5, &D_800F69F8, self);
        goto set2;
    }
    func_80030ECC(self);
    if ((u8)(M2C_FIELD(self, u8*, 2) - 4) < 2) {
        func_8002CCB0(self, 0x40, 0x30);
        p = M2C_FIELD(self, s8**, 0x80);
        if (p[4] == 4 && self->unk7 == 0) {
        die:
            func_80049E50(self);
            func_800477E4(5, &D_800F69F8, self);
            func_8004E654(self, 0x11);
        set2: {
            // !FAKE: depin: dropping it breaks the match (91/94)
            register s32 st asm("$3") = 2;
            self->state = st;
        }
            return;
        }
        if (p[4] == 2) {
            self->unk7 = 1;
            M2C_FIELD(self, u8*, 2) -= 2;
        }
    } else {
        if (func_8002CBFC(self, 0x40, 0x30) != 0) {
            self->state = 3;
            return;
        }
        func_8002CCB0(self, 0x40, 0x30);
    }
    func_8002D230(self);
    func_80017A04(self);
    {
        // !FAKE: depin: dropping it breaks the match (88/94)
        register s32* tbl asm("$2") = &D_800F6A94;
        // !FAKE: depin: dropping it breaks the match (92/94)
        register void* fn asm("$5") = ((void**)tbl)[self->unk5];
        ((void (*)(struct X4_BaseObj*))fn)(self);
    }
}
