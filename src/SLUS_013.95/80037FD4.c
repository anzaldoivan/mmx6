#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
s32 func_8002CFB0(void* arg);          /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_8003CDF0();               /* extern */
M2C_UNK func_8003D10C(void*);          /* extern */

void func_80037FD4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        ((M2C_UNK(*)())func_80017A04)();
        func_8002CFB0(arg0);
        if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            func_8003BA04(arg0, 0xB);
            M2C_FIELD(arg0, s8*, 0x67) = -1;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else {
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            func_8003CDF0(arg0);
            func_8003D10C(arg0);
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            M2C_FIELD(arg0, s8*, 0xD0) = -1;
            M2C_FIELD(arg0, s8*, 5) = 0x14;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        ((M2C_UNK(*)())func_80017A04)(arg0);
        func_8002CFB0(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80017A04();
void func_8003AD18(void* arg0);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003D330();

void func_8003809C(void* arg0) {
    u8* p = arg0;

    ((void (*)())func_80017A04)();
    if (*(s8*)(p + 6) == 0) {
        if (p[0xE2] == 4) {
            ((void (*)(void*, s32))func_8003BA04)(p, 0x27);
            p[6]++;
        }
    } else {
        if (*(s8*)(p + 0x45) & 0x80) {
            p[0x45] = 0;
            ((void (*)(s32, s32, void*))play_sound)(0, 0x21, 0);
        }
        if (*(s8*)(p + 0x46) == 0) {
            ((void (*)())func_8003D330)();
            func_8003AD18(p);
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void func_8003B954(struct X4_PlayerObj* self);
M2C_UNK func_8003BA04(void*, M2C_UNK);
extern u8 D_800CD40C;

void func_80038144(void* arg0) {
    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if (D_800CD40C == 0) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0x27);
            M2C_FIELD(arg0, u8*, 6)++;
        }
    } else {
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            M2C_FIELD(arg0, u8*, 0x45) = 0;
            play_sound(0, 0x21, 0);
        }
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            func_8003BA04(arg0, 0x28);
            func_8003B954(arg0);
        }
    }
}

#include "common.h"

#define M2C_UNK s32
M2C_UNK func_8003AFF4(s32);
extern void (*D_80073C58[])(void*);

void func_800381F0(void* arg0) {
    if (*((s8*)arg0 + 0xD3) != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    D_80073C58[*((s8*)arg0 + 6)](arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
#include "mmx6/state.h"

void func_80038248(void* arg0) {
    if (D_80097420.frame_counter & 1) {
        ((M2C_UNK(*)())func_80017A04)();
    }
    if ((M2C_FIELD(arg0, s8*, 7) == 0) || (--M2C_FIELD(arg0, s8*, 7) == 0)) {
        M2C_FIELD(arg0, s8*, 0x67) = -1;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 5) = 7;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x100);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_800382C8(u8* arg0) {
    ((void (*)())func_80017A04)();
    if (*(s8*)(arg0 + 0x46) == 0) {
        arg0[6]++;
        func_8003BA04(arg0, 0x54);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80017A04();                    /* extern */
M2C_UNK func_8003D26C(void*);               /* extern */

void func_80038310(void* arg0) {
    u8 temp_v1;

    ((M2C_UNK(*)())func_80017A04)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
    if (temp_v1 & 0x40) {
        M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0x3F);
        func_8003D26C(arg0);
    }
    if ((s8)M2C_FIELD(arg0, u8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, u8*, 0x45) = (u8)(M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
        play_sound(1, 5, arg0);
        M2C_FIELD(arg0, s8*, 0x8C) = 1;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80039FFC(void*);
M2C_UNK func_8003B30C(void*);
M2C_UNK func_8003D26C(void*);

void func_80038390(void* arg0) {
    u8 v;

    ((M2C_UNK(*)())func_80017A04)();
    if (func_80039FFC(arg0) != 0) {
        ((void (*)(void*))func_8003B30C)(arg0);
        M2C_FIELD(arg0, u8*, 5) = 0xD;
        return;
    }
    v = M2C_FIELD(arg0, u8*, 0x45);
    if (v & 0x40) {
        M2C_FIELD(arg0, u8*, 0x45) = v & 0x3F;
        func_8003D26C(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
struct X4_VisualObj* func_8002C398(void);
extern u32* D_8007789C[];

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_PTR(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800383F8(void* arg0) {
    struct X4_VisualObj* self = arg0;
    struct X4_VisualObj* obj;
    u8* tbl;
    u8* p;
    s32 off;

    if (self->id == 0x3A) {
        play_sound(1, 9, self);
    } else if ((u8)(self->id - 0x38) >= 2) {
        play_sound(1, 0xC, self);
    }
    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        if (self->id == 0x12 || self->id == 0x14 || self->id == 0x2E) {
            obj->unk2 = 4;
        } else {
            obj->unk2 = 3;
        }
        obj->bg_offset = self->bg_offset;
        tbl = SCRATCH_1C;
        off = *(s32*)(tbl + 4);
        obj->animation_table = D_8007789C;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk3C = tbl + off;
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->y_pos.i.hi = self->y_pos.i.hi;
        obj->unk15 = self->unk15 ^ 0x40;
        if ((u8)(self->id - 0x38) < 2) {
            obj->unk2 = 0xC;
        }
        if (self->id == 0x3A) {
            obj->unk2 = 0xC;
            p = F_PTR(self, 0x68);
            if (p != 0) {
                if (self->unk15 != 0) {
                    obj->x_pos.i.hi -= (s8)*p;
                } else {
                    obj->x_pos.i.hi += (s8)*p;
                }
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32

void silence_sound(u8, u8);
M2C_UNK func_8002D5D0(void*);
s32 func_8002FE30(void*);
M2C_UNK func_8003CD9C();

#define FLD(o, t) (*(t*)((u8*)arg0 + (o)))

#define TURN(s)                                                                \
    {                                                                          \
        u16 f;                                                                 \
        s32 r;                                                                 \
        silence_sound(1, 5);                                                   \
        func_8003CD9C(arg0);                                                   \
        f = FLD(0x7C, u16);                                                    \
        s = 0;                                                                 \
        if (f & 3) {                                                           \
            if (f & 2) {                                                       \
                s = 1;                                                         \
                FLD(0x20, s32) = -FLD(0x124, s32);                             \
            } else {                                                           \
                s = 2;                                                         \
                FLD(0x20, s32) = FLD(0x124, s32);                              \
            }                                                                  \
            func_8002D5D0(arg0);                                               \
            r = (u8)(func_8002FE30(arg0) - 0x25) >= 0xB;                       \
            FLD(0x8, s32) = FLD(0x18, s32);                                    \
            if (r) {                                                           \
                s = 0;                                                         \
            } else {                                                           \
                func_8002D5D0(arg0);                                           \
            }                                                                  \
        }                                                                      \
    }

s32 func_80038594(void* arg0) {
    s32 c;
    // !FAKE: depin: dropping it breaks the match (120/125)
    register s32 m asm("$4");
    s32 s;
    s32 w;
    s32 r;
    u16 f;
    s32 t;

    t = --FLD(0x85, s8);
    if (t == 0) {
        c = 1;
    } else {
        f = FLD(0x7C, u16);
        if (!(f & 0x103)) {
            c = 1;
        } else {
            m = 1;
            if (FLD(0x15, u8) != 0) {
                m = 2;
            }
            c = (f & m) != 0;
        }
    }
    if (c) {
        TURN(s);
        return s;
    }
    w = 2;
    if (FLD(0x15, u8) == 0) {
        w = 1;
        FLD(0x20, s32) = -FLD(0x12C, s32);
    } else {
        FLD(0x20, s32) = FLD(0x12C, s32);
    }
    func_8002D5D0(arg0);
    r = (u8)(func_8002FE30(arg0) - 0x25) >= 0xB;
    FLD(0x8, s32) = FLD(0x18, s32);
    if (r) {
        w = 0;
    } else {
        func_8002D5D0(arg0);
    }
    if (w == 0) {
        TURN(s);
        return s;
    }
    return w;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void silence_sound(u8, u8);   /* extern */
M2C_UNK func_8002D5D0(void*); /* extern */
s32 func_8002FE30(void*);     /* extern */
M2C_UNK func_8003CD9C();      /* extern */

static inline s32 func_80038788_turn(void* arg0) {
    s32 res;
    s32 bad;
    u16 flags;

    silence_sound(1, 5);
    func_8003CD9C(arg0);
    flags = M2C_FIELD(arg0, u16*, 0x7C);
    res = 0;
    if (flags & 0xC) {
        res = 1;
        if (flags & 4) {
            M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x128);
        } else {
            res = 2;
            M2C_FIELD(arg0, s32*, 0x24) = -M2C_FIELD(arg0, s32*, 0x128);
        }
        func_8002D5D0(arg0);
        bad = func_8002FE30(arg0) != 0x2E;
        if (M2C_FIELD(arg0, s32*, 0x24) < 0 &&
            (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
            bad = 1;
        }
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
        if (bad) {
            res = 0;
        } else {
            func_8002D5D0(arg0);
        }
    }
    return res;
}

s32 func_80038788(void* arg0) {
    s32 res;
    s32 go;
    s32 mask;
    s32 bad;

    if (--M2C_FIELD(arg0, s8*, 0x85) != 0) {
        mask = 4;
        if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
            mask = 8;
        }
        go = (M2C_FIELD(arg0, u16*, 0x7C) & mask) == 0;
    } else {
        go = 1;
    }
    if (go) {
        return func_80038788_turn(arg0);
    }
    res = 2;
    if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
        res = 1;
    }
    func_8002D5D0(arg0);
    bad = func_8002FE30(arg0) != 0x2E;
    if (M2C_FIELD(arg0, s32*, 0x24) < 0 && (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
        bad = 1;
    }
    M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    if (bad) {
        res = 0;
    } else {
        func_8002D5D0(arg0);
    }
    if (res == 0) {
        res = func_80038788_turn(arg0);
        return res;
    }
    return res;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);              /* extern */
M2C_UNK func_8002D5D0(void*);              /* extern */
s32 func_8002FE30(void*);                  /* extern */
s32 func_80038788(void* arg0);             /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);     /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */

void func_800389B4(void* arg0) {
    s32 var_a2;
    s32 var_s1;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    // !FAKE: depin: dropping it breaks the match (68/125)
    register s32 var_v0 asm("$2");
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
        var_a2 = func_80038788(arg0);
    } else {
        temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
        var_s1 = 0;
        if (temp_v1 & 0xC) {
            var_s1 = 1;
            if (temp_v1 & 4) {
                M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x128);
            } else {
                var_s1 = 2;
                M2C_FIELD(arg0, s32*, 0x24) = -M2C_FIELD(arg0, s32*, 0x128);
            }
            func_8002D5D0(arg0);
            var_a0 = func_8002FE30(arg0) != 0x2E;
            if (M2C_FIELD(arg0, s32*, 0x24) < 0 &&
                (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
                var_a0 = 1;
            }
            M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
            if (var_a0 != 0) {
                var_s1 = 0;
            } else {
                func_8002D5D0(arg0);
            }
        }
        var_a2 = var_s1;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            func_8003BA04(arg0, var_a2 + 0x91);
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0) {
            var_v0 = var_a2 - 0x6F;
            var_a1 = var_v0 & 0xFF;
            var_v1 = M2C_FIELD(arg0, u8*, 0x17);
        } else {
            var_v0 = M2C_FIELD(arg0, u8*, 0x17);
            var_a1 = 0x91;
            var_v1 = var_v0;
            if (var_v0 != var_a1) {
                var_v0 = var_a2 - 0x60;
                var_a1 = var_v0 & 0xFF;
            }
        }
    } else {
        var_v0 = var_a2 - 0x60;
        var_a1 = var_v0 & 0xFF;
        var_v1 = M2C_FIELD(arg0, u8*, 0x17);
    }
    if (var_a1 != var_v1) {
        if (var_a1 == 0xA0) {
            if (M2C_FIELD(arg0, s8*, 2) == 0) {
                func_8003BB94(arg0, 0xA0, 2);
            } else {
                func_8003BB94(arg0, 0xA0, 3);
            }
        } else {
            func_8003BA04(arg0, var_a1);
        }
    } else {
        func_80017A04(arg0);
    }
    if ((M2C_FIELD(arg0, s8*, 0x46) == 0) &&
        (M2C_FIELD(arg0, s8*, 0x8E) == 0)) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003BB94(arg0, 0xA0, 2);
        } else {
            func_8003BB94(arg0, 0xA0, 3);
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_8002D5D0(void*);               /* extern */
s32 func_8002FE30(void*);                   /* extern */

s32 func_80038BA8(void* arg0) {
    s32 var_a0;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x87) == 0 &&
        !(M2C_FIELD(arg0, u16*, 0x80) & 0x100)) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 4) {
        M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x130);
    } else {
        M2C_FIELD(arg0, s32*, 0x24) = -M2C_FIELD(arg0, s32*, 0x130);
    }
    func_8002D5D0(arg0);
    var_a0 = func_8002FE30(arg0) != 0x2E;
    if (M2C_FIELD(arg0, s32*, 0x24) < 0 && (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
        var_a0 = 1;
    }
    M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    if (var_a0 != 0) {
        return 0;
    }
    M2C_FIELD(arg0, s8*, 0x84) = 1;
    M2C_FIELD(arg0, s8*, 0x86) = 1;
    if (M2C_FIELD(arg0, s32*, 0xEC) & 0x10) {
        M2C_FIELD(arg0, s8*, 0x85) = 0xF;
    } else {
        M2C_FIELD(arg0, s8*, 0x85) = 0x1E;
    }
    M2C_FIELD(arg0, s8*, 0x8C) = 1;
    play_sound(1, 5, arg0);
    return 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);              /* extern */
M2C_UNK func_8002D5D0(void*);              /* extern */
s32 func_8002FE30(void*);                  /* extern */
s32 func_80038594(void*);                  /* extern */
s32 func_800397F8(void*, s32);             /* extern */
s32 func_8003A814(void*, s32);             /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);     /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */

void func_80038CD0(void* arg0) {
    s32 var_s2;
    // !FAKE: depin: dropping it breaks the match (110/165)
    register s32 var_s0 asm("$16");
    s32 temp_s3;
    s32 temp_v0;
    u16 temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
        var_s2 = func_80038594(arg0);
    } else {
        temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
        var_s0 = 0;
        if (temp_v1 & 3) {
            var_s0 = 1;
            if (temp_v1 & 2) {
                M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x124);
            } else {
                var_s0 = 2;
                M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x124);
            }
            func_8002D5D0(arg0);
            temp_v0 = (u8)(func_8002FE30(arg0) - 0x25) >= 0xB;
            M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
            if (temp_v0) {
                var_s0 = 0;
            } else {
                func_8002D5D0(arg0);
            }
        }
        var_s2 = var_s0;
    }
    if (var_s2 != 0) {
        func_800397F8(arg0, func_8002FE30(arg0));
    }
    temp_s3 = func_8002FE30(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            func_8003BA04(arg0, func_8003A814(arg0, temp_s3) + 0x97);
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0) {
            var_s0 = 0x97;
            if (var_s2 != 0) {
                var_s0 = 0x9A;
            }
            var_s0 = (var_s0 + func_8003A814(arg0, temp_s3)) & 0xFF;
            goto block_27;
        }
        if (var_s2 != 0) {
            var_s0 = (func_8003A814(arg0, temp_s3) - 0x5A) & 0xFF;
            goto block_27;
        }
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x69) & 0xFF;
        if (M2C_FIELD(arg0, u8*, 0x17) == var_s0) {
            goto block_27;
        }
        goto block_25;
    }
    if (var_s2 != 0) {
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5A) & 0xFF;
    } else {
    block_25:
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5D) & 0xFF;
    }
block_27:
    if (var_s0 != M2C_FIELD(arg0, u8*, 0x17)) {
        if ((u8)(var_s0 + 0x5D) < 3U) {
            if (M2C_FIELD(arg0, s8*, 2) == 0) {
                func_8003BB94(arg0, var_s0, 2);
            } else {
                func_8003BB94(arg0, var_s0, 3);
            }
        } else {
            func_8003BA04(arg0, var_s0);
        }
    } else {
        func_80017A04(arg0);
    }
    if ((M2C_FIELD(arg0, s8*, 0x46) == 0) &&
        (M2C_FIELD(arg0, s8*, 0x8E) == 0)) {
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5D) & 0xFF;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003BB94(arg0, var_s0, 2);
        } else {
            func_8003BB94(arg0, var_s0, 3);
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_8002D5D0(void*);               /* extern */
s32 func_8002FE30(void*);                   /* extern */

s32 func_80038F64(void* arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x87) == 0 &&
        !(M2C_FIELD(arg0, u16*, 0x80) & 0x100)) {
        return 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x12C);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x12C);
    }
    func_8002D5D0(arg0);
    temp_v0 = (u8)(func_8002FE30(arg0) - 0x25) >= 0xB;
    M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
    if (temp_v0) {
        return 0;
    }
    M2C_FIELD(arg0, s8*, 0x84) = 1;
    M2C_FIELD(arg0, s8*, 0x86) = 1;
    if (M2C_FIELD(arg0, s32*, 0xEC) & 0x10) {
        M2C_FIELD(arg0, s8*, 0x85) = 0xF;
    } else {
        M2C_FIELD(arg0, s8*, 0x85) = 0x1E;
    }
    M2C_FIELD(arg0, s8*, 0x8C) = 1;
    play_sound(1, 5, arg0);
    return 1;
}
