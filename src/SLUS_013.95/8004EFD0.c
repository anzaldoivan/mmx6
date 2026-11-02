#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK set_animation(void*, M2C_UNK);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_8004EFD0(struct X4_MainObj* self) {
    s8 state;

    state = S8(self, 6);
    if (state == 0) {
        F8(self, 0x7F) = 0x82;
        if (F8(self, 0x84) == 0) {
            if (F8(self, 0x7E) == 0) {
                if (F8(self, 0x82) == 0) {
                    set_animation(self, 1);
                } else {
                    set_animation(self, 0xC);
                }
            } else if (F8(self, 0x82) == 0) {
                set_animation(self, 6);
            } else {
                set_animation(self, 0xF);
            }
        } else if (F8(self, 0x82) == 0) {
            set_animation(self, 0x18);
        } else {
            set_animation(self, 0x1F);
        }
        F8(self, 6)++;
    } else if (state == 1) {
        if (--F8(self, 0x7F) == 0) {
            play_sound(2, 0x41, self);
            F8(self, 0x83) = state;
            F8(self, 0x7F) = 0x3C;
            F8(self, 6)++;
        }
    } else if (state == 2) {
        if (--F8(self, 0x7F) == 0) {
            F8(self, 0x83) = 0;
            F8(self, 6) = 0;
            F8(self, 5)++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK set_animation(void*, M2C_UNK);
void func_8004FFF8(void*, s32);
extern s32 D_800970A8;
extern s8 D_80097174;

void func_8004F144(void* arg0) {
    s8 state = M2C_FIELD(arg0, s8*, 0x45);

    if (state == 1) {
        if (D_80097174 == 0) {
            play_sound(2, 0x2E, arg0);
            if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
                func_8004FFF8(arg0, 0);
                func_8004FFF8(arg0, 1);
            } else {
                func_8004FFF8(arg0, 0x10);
            }
        }
    } else if (state == 2) {
        if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
            if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
                M2C_FIELD(arg0, u8*, 0x82) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x82) = 0x40;
            }
        } else {
            if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
                M2C_FIELD(arg0, u8*, 0x82) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x82) = 0x40;
            }
        }
        if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
            if (M2C_FIELD(arg0, u8*, 0x7E) == 0) {
                if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                    set_animation(arg0, 0x13);
                } else {
                    set_animation(arg0, 0x14);
                }
            } else if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                set_animation(arg0, 0x15);
            } else {
                set_animation(arg0, 0x16);
            }
            M2C_FIELD(arg0, u8*, 0x81) = 0x3C;
        } else {
            if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                set_animation(arg0, 0x1C);
            } else {
                set_animation(arg0, 0x23);
            }
            M2C_FIELD(arg0, u8*, 0x81) = 0x14;
        }
        M2C_FIELD(arg0, u8*, 5) -= 1;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);                              /* extern */
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2); /* extern */
extern u8 D_80011674[8][4];
extern s32 D_80078CC0;
extern s32 D_80078CC4;
extern s32 D_80078CC8;
extern s16 D_800970AA;
extern u8 D_800CCF38;

void func_8004F2EC(void* arg0) {
    u8 tbl[8][4];
    s8 state;
    u32 idx;
    s16 a;

    __builtin_memcpy(tbl, D_80011674, sizeof(tbl));
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    state = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x50) = 0;
    M2C_FIELD(arg0, void**, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    idx = M2C_FIELD(arg0, u8*, 0x88) >> 4;
    if (state == 0) {
        M2C_FIELD(arg0, u8*, 0x16) = 1;
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) += (s8)tbl[idx][0];
            M2C_FIELD(arg0, s16*, 0xE) += (s8)tbl[idx][1];
        } else {
            M2C_FIELD(arg0, s16*, 0xA) += (s8)tbl[idx][2];
            M2C_FIELD(arg0, s16*, 0xE) += (s8)tbl[idx][3];
        }
    } else if (state == 1) {
        M2C_FIELD(arg0, u8*, 0x16) = state;
        ((void (*)(void*, s32))set_animation)(arg0, 4);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x40000;
            a = M2C_FIELD(arg0, s16*, 0xA) + (s8)tbl[idx][0] - 0x14;
            M2C_FIELD(arg0, s16*, 0xE) =
                M2C_FIELD(arg0, s16*, 0xE) + (s8)tbl[idx][1];
            M2C_FIELD(arg0, s16*, 0xA) = a;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x40000;
            a = M2C_FIELD(arg0, s16*, 0xA) + (s8)tbl[idx][2] + 0x14;
            M2C_FIELD(arg0, s16*, 0xE) =
                M2C_FIELD(arg0, s16*, 0xE) + (s8)tbl[idx][3];
            M2C_FIELD(arg0, s16*, 0xA) = a;
        }
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x20) *= 2;
        }
        M2C_FIELD(arg0, s16*, 0x88) = 6;
    } else {
        ((void (*)(void*, s32))set_animation)(arg0, 0x1B);
        M2C_FIELD(arg0, void**, 0x68) = &D_80078CC0;
        M2C_FIELD(arg0, void**, 0x50) = &D_80078CC4;
        M2C_FIELD(arg0, void**, 0x54) = &D_80078CC8;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) -= 0x1C;
            M2C_FIELD(arg0, s16*, 0xE) -= 0x18;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) += 0x1C;
            M2C_FIELD(arg0, s16*, 0xE) -= 0x18;
        }
        M2C_FIELD(arg0, s32*, 0x20) =
            ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) << 16) / 70;
        M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x1800;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 0x5C) = 2;
        M2C_FIELD(arg0, u8*, 0x60) = 3;
    }
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (func_8002CBFC(arg0, 0x20, 0x20) == 1) {
        M2C_FIELD(arg0, u8*, 4)++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
M2C_UNK func_8002D230(struct X4_MainObj* self);
M2C_UNK move_object(void*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90_r(
    void*); /* link-only second name (PROVIDEd): the call needs the int return */
#define func_80049D90 func_80049D90_r
M2C_UNK func_8004A2B4(M2C_UNK, M2C_UNK, void*, M2C_UNK, M2C_UNK);
extern s32 D_80078CB8;
extern s32 D_80078CBC;

void func_80049E50(struct X4_MainObj* self);
void func_8004F624(u8* arg0) {
    s8 t;
    // !FAKE: depin: dropping it breaks the match (130/132)
    register s32 f asm("$2");

    ((M2C_UNK(*)())func_80017A04)();
    func_8002CCB0(arg0, 0x10, 0x10);
    t = *(s8*)(arg0 + 2);
    if (t == 0) {
        if (*(s8*)(arg0 + 0x45) == 1) {
            arg0[3] = 0;
            arg0[4]++;
            return;
        }
    } else if (t == 1) {
        if (*(s8*)(arg0 + 5) == 0) {
            arg0[3] = 0;
            if (--*(s16*)(arg0 + 0x88) == 0) {
                *(s32**)(arg0 + 0x50) = &D_80078CB8;
                *(s32**)(arg0 + 0x68) = &D_80078CBC;
                arg0[3] = 1;
                arg0[5]++;
            }
            goto tail;
        }
        move_object(arg0);
        f = arg0[0x70];
        if (f == 0) {
            func_8002EE10(arg0);
            if (arg0[0x70] == 0) {
                goto tail;
            }
        }
        func_80049D90(arg0);
        arg0[3] = 0;
        arg0[4]++;
        return;
    } else if (t == 16) {
        if (++*(s8*)(arg0 + 6) == 8) {
            func_8004A2B4(0, 0, arg0, 0, 1);
            arg0[6] = 0;
        }
        if (arg0[0x70] != 0 || (func_8002EE10(arg0), arg0[0x70] != 0) ||
            check_enemy_hits(arg0) < 0 || func_80030ECC(arg0) != 0) {
            ((M2C_UNK(*)())func_80049E50)(arg0);
            arg0[4] = 2;
            return;
        }
        ((M2C_UNK(*)())func_80017A04)(arg0);
        func_8002D230(arg0);
        if (func_8002CBFC(arg0, 0x10, 0x10) == 0) {
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
        goto inc;
    }
tail:
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x20, 0x20) == 1) {
    inc:
        arg0[4]++;
    }
}
#undef func_80049D90

#define func_80048DC8 func_8004F834
#define D_80077BC0 D_80078C7C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

void func_8004EC30(u8*);
#define func_8004EC30 ((void (*)())func_8004EC30)

void func_8004F880(void) {
    func_8004EC30();
}
#undef func_8004EC30

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004F8A0(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_8004FE8C();               /* extern */

void func_8004F8C0(void* arg0) {
    func_8004FE8C();
    if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x7E) == 0) {
            if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                set_animation(arg0, 9);
            } else {
                set_animation(arg0, 0x11);
            }
        } else if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
            set_animation(arg0, 0xA);
        } else {
            set_animation(arg0, 0x12);
        }
    } else if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
        set_animation(arg0, 0x19);
    } else {
        set_animation(arg0, 0x20);
    }
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s8*, 4) = 4;
    M2C_FIELD(arg0, s8*, 0x81) = 0x50;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
s32 func_8004FE8C(void*);              /* extern */

void func_8004F9A0(void* arg0) {
    u8 temp_v0;

    ((M2C_UNK(*)())func_80017A04)();
    if (func_8004FE8C(arg0) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
            if (M2C_FIELD(arg0, u8*, 0x7E) == 0) {
                if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                    set_animation(arg0, 9);
                } else {
                    set_animation(arg0, 0x11);
                }
            } else if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                set_animation(arg0, 0xA);
            } else {
                set_animation(arg0, 0x12);
            }
        } else if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
            set_animation(arg0, 0x19);
        } else {
            set_animation(arg0, 0x20);
        }
    }
    temp_v0 = M2C_FIELD(arg0, u8*, 0x81);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x81) = (u8)(temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s8*, 4) = 5;
    if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
        set_animation(arg0, 8);
        return;
    }
    set_animation(arg0, 0x1D);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                                            /* extern */
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2); /* extern */
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);    /* extern */
M2C_UNK move_object(void*);                                         /* extern */

M2C_UNK clear_object_slot();
void func_8004FAD0(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        move_object(arg0);
    }
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    ((M2C_UNK(*)())clear_object_slot)(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_8004FB40(void) {
    func_8002CA54();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CAB4(struct X4_BaseObj*);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_80049E50(struct X4_MainObj*);
void set_reploid_status(u8, s32);
void func_8004FF7C(void*, s32);
extern s32 D_80078CA0[];

void func_8004FB60(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    (*(void (**)(u8*))((((s8)arg0[5]) << 2) + (s32)D_80078CA0))(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_8004FF7C(arg0, 0x31);
        set_reploid_status(arg0[2], 3);
        arg0[3] = 0;
        func_80049E50((struct X4_MainObj*)arg0);
        {
            // !FAKE: keeps the first arm's state store out of the cross-jump
            register s32 st asm("$3") = 8;
            arg0[4] = st;
        }
    } else {
        func_80030ECC(arg0);
        if (func_8002CAB4((struct X4_BaseObj*)arg0) == 0) {
            func_8002CCB0(arg0, 0x20, 0x20);
            if (arg0[0x83] != 0) {
                *(u16*)(arg0 + 0x42) |= 0x8000;
            }
        } else {
            set_reploid_status(arg0[2], 4);
            arg0[4] = 8;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
extern s32 D_80078908;
extern s32 D_8007890C;
extern s32 D_80078914;
extern s32 D_80078918;

void func_8004FC40(u8* arg0) {
    arg0[0x5C] = 0xD;
    arg0[0x60] = 6;
    if (arg0[0x84] == 0) {
        arg0[0x81] = 0x3C;
        *(s32**)(arg0 + 0x54) = &D_8007890C;
        *(s32**)(arg0 + 0x50) = &D_80078908;
        if (arg0[0x7E] == 0) {
            if (arg0[0x82] == 0) {
                set_animation(arg0, 0x13);
            } else {
                set_animation(arg0, 0x14);
            }
        } else if (arg0[0x82] == 0) {
            set_animation(arg0, 0x15);
        } else {
            set_animation(arg0, 0x16);
        }
    } else {
        arg0[0x81] = 0x14;
        *(s32**)(arg0 + 0x54) = &D_80078918;
        *(s32**)(arg0 + 0x50) = &D_80078914;
        if (arg0[0x82] == 0) {
            set_animation(arg0, 0x1C);
        } else {
            set_animation(arg0, 0x23);
        }
    }
    arg0[5]++;
}
#undef set_animation

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_8004FD58(u8* arg0) {
    if (--arg0[0x81] == 0) {
        if (arg0[0x84] == 0) {
            if (arg0[0x7E] == 0) {
                if (arg0[0x82] == 0) {
                    set_animation(arg0, 2);
                } else {
                    set_animation(arg0, 0xD);
                }
            } else if (arg0[0x82] == 0) {
                set_animation(arg0, 7);
            } else {
                set_animation(arg0, 0x10);
            }
        } else if (arg0[0x82] == 0) {
            set_animation(arg0, 0x1A);
        } else {
            set_animation(arg0, 0x21);
        }
        arg0[5]++;
    }
}

void func_8004FE50(void) {
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8004FE58);
// clang-format on

#include "common.h"

extern s32 D_800970A8;

s32 func_8004FE8C(void* arg0) {
    u8* p = (u8*)arg0;

    if (p[0x82] == 0) {
        s32 f = *(s32*)(p + 8);
        if (D_800970A8 < f) {
            p[0x82] = 0;
            return 0;
        }
        p[0x82] = 0x40;
        return 1;
    } else {
        s32 f = *(s32*)(p + 8);
        if (D_800970A8 < f) {
            p[0x82] = 0;
            return 1;
        }
        p[0x82] = 0x40;
        return 0;
    }
}
