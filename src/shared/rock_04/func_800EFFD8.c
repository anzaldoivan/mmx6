#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002A47C(s32);
void* func_8002BBF4();
s32 func_8002D2D4();
extern s8 D_8008EF48[];
extern u32* D_80095098;
extern struct X4_PlayerObj D_800970A0;
extern s16 D_800970AE;
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800F6E08[];
extern u16 D_800F6E0C[];

void func_800EFFD8(struct X4_BaseObj* self) {
    s8* ent;
    s8* flag;
    s8* flags;
    s8* base;
    struct X4_PlayerObj* obj;
    s32 i;
    s32 n6;
    s32 n45;
    s32 a;
    s32 b;
    s16 x;
    s32 r;
    s32 q;
    s32 y;

    if (D_800CCED0.checkpoint < 3) {
        n6 = 0;
        n45 = 0;
        flags = (s8*)self + 0x16;
        base = D_8008EF48;
        for (i = 0; i < 0x30; i++) {
            ent = base + i * 0x9C;
            if (ent[0] != 0 && ent[1] == 0x11) {
                if (ent[2] == 6 && ent[7] >= 7) {
                    n6 = (n6 + 1) & 0xFF;
                    if (self->unk5 == 0) {
                        func_80016C48(5, 9, 0);
                        func_80012D9C(5);
                        self->unk5 = 1;
                    }
                } else if ((u32)((u8)ent[2] - 4) < 2U) {
                    n45 = (n45 + 1) & 0xFF;
                    if (self->unk6 == 0) {
                        if (self->unk7 == 0) {
                            func_80016C48(5, 8, 0);
                            self->unk6 = 1;
                            self->unk7 = -0x10;
                        }
                    }
                }
            }
        }
        if (D_800CCED0.checkpoint > 0) {
            if (D_800970AE > 0x270) {
                func_80016C48(5, 3, 0);
            }
            if (n6 == 0 && self->unk5 == 0) {
                func_80016C48(5, 3, 0);
                self->unk5 = 0;
            }
        }
        if (self->unk7 != 0) {
            self->unk7--;
        }
        if (n6 == 0 && self->unk6 == 0) {
            func_80016C48(5, 3, 0);
            self->unk5 = 0;
        } else if (n45 == 0 && self->unk5 == 0) {
            if (self->unk7 == 0) {
                func_80016C48(5, 3, 0);
                self->unk6 = 0;
            }
        }
        if (self->unk7 != 0) {
            self->unk7--;
        }
        for (i = 0; i < 0xF; i++) {
            if (flags[i] != 0) {
                continue;
            }
            x = D_800970A0.x_pos.i.hi;
            if (D_800F6E08[i * 4] < x && x < D_800F6E08[i * 4] + 0x60) {
                if (i == 12 && D_800970A0.y_pos.i.hi < 0x1C0) {
                    break;
                }
                if (i == 13 && D_800970A0.y_pos.i.hi < 0x2B0) {
                    break;
                }
                if (i == 14 && D_800970A0.y_pos.i.hi < 0x350) {
                    break;
                }
                if (i == 15 && D_800970A0.y_pos.i.hi < 0x3D0) {
                    break;
                }
                obj = func_8002BBF4();
                if (obj != NULL) {
                    obj->active = 0x41;
                    obj->id = 0x11;
                    obj->unk2 = ((u8*)D_800F6E08)[i * 8 + 6];
                    obj->unk40 = D_80095098[func_8002A47C(0x11)] >> 7;
                    a = func_8002A47C(obj->id);
                    b = func_8002A47C(obj->id);
                    obj->unk42 =
                        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
                    obj->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(obj->id)];
                    obj->x_pos.i.hi = M2C_FIELD(&D_800F6E08[i * 4], u16*, 2);
                    if (obj->unk2 == 2) {
                        func_80016C48(5, 9, 0);
                        ((void (*)(s32))func_80012D9C)(5);
                        M2C_FIELD(obj, s16*, 0x7E) = 0xB4;
                        q = func_8002D2D4();
                        obj->y_pos.i.hi =
                            D_800F6E0C[i * 4] + (r = (q & 0x1F) - 0x10);
                    } else if (obj->unk2 != 3) {
                        func_80012D9C(5);
                        func_80016C48(5, 8, 0);
                        M2C_FIELD(obj, s16*, 0x7E) = 0x168;
                        if (M2C_FIELD(self, s16*, 0x14) < 0x1E0) {
                            M2C_FIELD(self, s16*, 0x14) = 0x1E0;
                        }
                        q = func_8002D2D4();
                        y = D_800F6E0C[i * 4];
                        r = (q & 0x1F) - 0x10;
                        obj->y_pos.i.hi = y + r;
                    } else {
                        obj->y_pos.i.hi = D_800F6E0C[i * 4];
                    }
                }
                flags[i] = 1;
            }
        }
    }
}
