#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 func_8002D2D4();
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern u16 D_800F447E; /* TU spelling (func_800EEC40) */
#define D_800F447E_S16 (*(s16*)&D_800F447E)
extern s16 D_800F4480;

#define SPAWN3(self)                                                           \
    {                                                                          \
        M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s8*, 7) = 1;                  \
        for (i = 0; i < 3; i++) {                                              \
            r[i] = (u8)((u32)func_8002D2D4() % 11);                            \
        }                                                                      \
        if (r[0] == r[1]) {                                                    \
            r[1] = (r[0] + 5) % 11;                                            \
        }                                                                      \
        if (r[2] == r[0] || r[2] == r[1]) {                                    \
            r[2] = (r[0] + 1) % 11;                                            \
            if (r[2] == r[1]) {                                                \
                r[2] = (r[2] + 5) % 11;                                        \
            }                                                                  \
        }                                                                      \
        for (i = 0; i < 3; i++) {                                              \
            struct X4_BaseObj* child = func_8002C458();                        \
            if (child != NULL) {                                               \
                child->active = 0x41;                                          \
                child->id = 0x12;                                              \
                child->unk2 = 2;                                               \
                child->bg_offset = self->bg_offset;                            \
                child->x_pos.i.hi = self->x_pos.i.hi;                          \
                child->y_pos.i.hi = self->y_pos.i.hi;                          \
                child->unk15 = self->unk15;                                    \
                M2C_FIELD(child, void**, 0x7C) =                               \
                    M2C_FIELD(self, void**, 0x7C);                             \
                child->unk7 = r[i] + 1;                                        \
            }                                                                  \
        }                                                                      \
    }

void func_800F0EE4(struct X4_BaseObj* self) {
    s32 r[3];
    s32 i;

    func_80017A04();
    func_8002D230(self);
    if (self->x_pos.i.hi < D_800F447E_S16 + 0x1030) {
        self->x_pos.i.hi = D_800F447E_S16 + 0x1030;
    } else if (self->x_pos.i.hi > D_800F447E_S16 + 0x1150) {
        self->x_pos.i.hi = D_800F447E_S16 + 0x1150;
    }
    if (func_80031474(self) < 0) {
        func_80049E50(self);
        SPAWN3(self)
        goto tail;
    }
    if (self->y_pos.i.hi > D_800F4480 + 0x430) {
        SPAWN3(self)
    tail:
        func_80016C48(2, 0xD, self);
        ((void (*)(s32))func_80012D9C)(5);
        self->state = 2;
        return;
    }
    if (func_8002CBFC(self, 0x60, 0x60) == 0) {
        func_8002CCB0(self, 0x30, 0x30);
        return;
    }
    self->state = 2;
    M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s8*, 7) = 1;
}
