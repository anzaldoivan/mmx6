#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800FDE30;

void func_800FA52C(struct X4_MainObj* self) {
    s16 t;

    if (M2C_FIELD(self, u8*, 0x70) & 8) {
        M2C_FIELD(self, s32*, 0x24) = 0;
    }
    t = self->unk7C;
    if (t < 0x10) {
        register s32 a asm("$5") = M2C_FIELD(self, u16*, 0x88);
        register s32 w asm("$2") = *(u16*)((u8*)&D_800FDE30 + 0x2E4 + t * 2);
        a = a + w;
        M2C_FIELD(self, u16*, 0xA) = a;
        ((void (*)(void*, s32))func_80017A04)(self, a);
        func_8002D230(self);
        func_8002CCB0(self, 0x40, 0x40);
    } else {
        func_800179A4(self, 0);
        {
            register s32 c asm("$2") = M2C_FIELD(self, u16*, 0x88);
            M2C_FIELD(self, u16*, 0xA) = c;
        }
        {
            register s32 k asm("$3") = self->unk7C;
            if (k == 0x6E) {
                u8* e = (u8*)&D_800CCED0;
                func_80021760(0, 0xFF, M2C_FIELD(e, s8*, 0x2E));
                M2C_FIELD(e, s8*, 0x2E) = 1;
                self->unk7C = 0;
                self->unk6++;
            }
        }
        func_80017A04(self);
        func_8002D230(self);
        {
            register s32 m asm("$2") = self->unk7C & 1;
            if (!m) {
                func_8002CCB0(self, 0x40, 0x40);
            }
        }
    }
    self->unk7C++;
}
