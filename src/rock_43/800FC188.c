#include "common.h"

void func_800FC188(void) {
}

#define func_8003744C func_800FC190
#define D_80073C1C D_800FE174
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();
void* func_8002C458();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern s8 D_8009723F;

void func_800FC1CC(void* arg0) {
    void* p;

    if (D_800970A5 == 0x14) {
        D_8009723F = 2;
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        p = alloc_class3_slot();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 1;
            M2C_FIELD(p, u8*, 1) = 0x18;
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
            M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = p;
        }
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = 0;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800CCEDF;
extern s32 D_800FDE30;

void func_800FC28C(void* arg0) {
    if (D_800CCEDF == 0) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
            set_animation(arg0, 2);
            play_sound(2, 0x99, arg0);
            play_sound(2, 0x95, arg0);
            {
                s32 d = *(u16*)((u8*)&D_800FDE30 + 0x45A);
                s32 c = M2C_FIELD(arg0, u8*, 6);
                M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
                M2C_FIELD(arg0, s16*, 0x7C) = 0;
                M2C_FIELD(arg0, u16*, 0x88) = d;
                M2C_FIELD(arg0, u8*, 6) = c + 1;
            }
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
M2C_UNK func_80040488(M2C_UNK);                 /* extern */
extern u8 D_8008EAFC;
extern s8 D_800CCEF4;

void func_800FC340(void* arg0) {
    if (D_8008EAFC == 0) {
        func_80040488(0);
        D_800CCEF4 = 1;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}

#define func_800F4588 func_800FC3B0
#include "../shared/commander_yammark/func_800F4588.c"
#undef func_800F4588

#define func_800F4674 func_800FC49C
#define D_800F7C30 D_800FE188
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "common.h"

void func_800FC500(void) {
}

#define func_8003744C func_800FC508
#define D_80073C1C D_800FE18C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800FC544(void* arg0) {
    s32 g;

    ((void (*)(void*, s32))set_animation)(arg0, 1);
    g = D_800970AA;
    if (M2C_FIELD(arg0, s16*, 0xA) < g) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    func_8002D230(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
void player_spawn_dash_spark(void* arg0);
extern s16 D_800970AA;

void func_800FC5C8(struct X4_MainObj* self) {
    if (M2C_FIELD(self, s8*, 0x45) == 1) {
        s32 d;

        M2C_FIELD(self, s8*, 0x45) = 0;
        d = D_800970AA;
        if (self->x_pos.i.hi < d) {
            self->unk15 = 0x40;
        } else {
            self->unk15 = 0;
        }
        if (self->unk15 == 0) {
            self->x_speed = 0xFFFBE000;
        } else {
            self->x_speed = 0x42000;
        }
        play_sound(2, 0x85, self);
        play_sound(2, 0x97, self);
        player_spawn_dash_spark(self);
    }
    if (M2C_FIELD(self, s8*, 0x45) == 2) {
        self->unk6++;
    }
    func_8002CCB0(self, 0x40, 0x40);
    func_80017A04(self);
    func_8002D230(self);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;
#define D_800970AA_U (*(u16*)&D_800970AA)

void func_800FC6B0(void* arg0) {
    s16 d;

    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) >= 0xB) {
        d = D_800970AA_U - M2C_FIELD(arg0, u16*, 0xA);
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            if (d < -0x40) {
                // !FAKE: skip to the shared tail, retail branches out of the negative arm
                goto skip;
            }
        } else if (d >= 0x41) {
            // !FAKE: skip to the shared tail from the positive arm
            goto skip;
        }
        play_sound(2, 0x86, arg0);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
skip:
    func_8002CCB0(arg0, 0x40, 0x40);
    func_8002D230(arg0);
}
#undef D_800970AA_U

#include "../shared/rock_43/func_800FC76C.c"

#define func_8003744C func_800FC800
#define D_80073C1C D_800FE19C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_43/func_800FC83C.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
extern s32 D_800FDE30;

void func_800FC8BC(void* arg0) {
    ((void (**)(void*))((u8*)&D_800FDE30 + 0x374))[M2C_FIELD(arg0, s8*, 6)](
        arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    func_8002D230(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

void func_800FC920(void* arg0) {
    ((void (*)(void*, M2C_UNK))set_animation)(arg0, 3);
    {
        s32 g = D_800970AA;
        if (M2C_FIELD(arg0, s16*, 0xA) < g) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern s16 D_800970AA;

void func_800FC980(void* arg0) {
    s8 t;
    void* p;

    t = M2C_FIELD(arg0, s8*, 0x45);
    if (t == 1) {
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = t;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = 3;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x28) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 3);
        {
            s32 g = D_800970AA;
            if (M2C_FIELD(arg0, s16*, 0xA) < g) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern s16 D_800970AA;

void func_800FCA6C(void* arg0) {
    s8 t;
    void* p;

    t = M2C_FIELD(arg0, s8*, 0x45);
    if (t == 1) {
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = t;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = 3;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x28) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 4);
        {
            s32 g = D_800970AA;
            if (M2C_FIELD(arg0, s16*, 0xA) < g) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern s32 D_800FDE30;

void func_800FCB58(void* arg0) {
    void* p;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, u8*, 0x45) = 0;
        play_sound(2, 0x87, arg0);
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = 4;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 0);
        {
            u8* t = (u8*)&D_800FDE30 + 0x284;
            u8* q = t + (M2C_FIELD(arg0, u8*, 0x87)++ +
                         M2C_FIELD(arg0, u8*, 0x86) * 6);
            M2C_FIELD(arg0, u8*, 5) = *q;
        }
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

#define func_8003744C func_800FCC18
#define D_80073C1C D_800FE1B4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800FCC54(void* arg0) {
    s32 g;

    ((void (*)(void*, s32))set_animation)(arg0, 3);
    g = D_800970AA;
    if (M2C_FIELD(arg0, s16*, 0xA) < g) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    func_8002D230(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */

void func_800FCCD0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    func_8002D230(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800FCD30(void* arg0) {
    void* p;

    if ((s16)(M2C_FIELD(arg0, s16*, 0x7C) % 6) == 0) {
        s32 g = D_800970AA;
        if (M2C_FIELD(arg0, s16*, 0xA) < g) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = 2;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = 3;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x30) {
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
    func_8002D230(arg0);
}

#define func_800FC76C func_800FCE54
#include "../shared/rock_43/func_800FC76C.c"
#undef func_800FC76C

#define func_800F4674 func_800FCEE8
#define D_800F7C30 D_800FE1C4
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

void func_800FCF4C(void* self) {
    s32 g;

    set_animation(self, 5);
    play_sound(2, 0x98, self);
    g = D_800970AA;
    if (M2C_FIELD(self, s16*, 0xA) < g) {
        M2C_FIELD(self, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(self, u8*, 0x15) = 0;
    }
    M2C_FIELD(self, u8*, 6) = M2C_FIELD(self, u8*, 6) + 1;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
void* func_8002C458();
extern s32 D_800FDE30;

void func_800FCFB8(void* arg0) {
    s32 i;
    void* e;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x8E, arg0);
        func_80012D9C(3);
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        M2C_FIELD(arg0, s8*, 7) = 0;
        for (i = 0; i < 8; i++) {
            e = func_8002C458();
            if (e != 0) {
                s32 v = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(e, u8*, 1) = 0x13;
                M2C_FIELD(e, u8*, 2) = 6;
                M2C_FIELD(e, void**, 0x7C) = arg0;
                M2C_FIELD(e, u8*, 0) = v;
            }
        }
        func_80029478(0x10, 6, 3);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 0);
        {
            u8* t = (u8*)&D_800FDE30 + 0x284;
            u8* q = t + (M2C_FIELD(arg0, u8*, 0x87)++ +
                         M2C_FIELD(arg0, u8*, 0x86) * 6);
            s32 r = *q;
            M2C_FIELD(arg0, s8*, 6) = 0;
            M2C_FIELD(arg0, u8*, 5) = r;
        }
    }
}

#define func_800F4674 func_800FD0BC
#define D_800F7C30 D_800FE1CC
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

void func_800FD120(void* arg0) {
    s32 g;

    ((void (*)(void*, M2C_UNK))set_animation)(arg0, 6);
    g = D_800970AA;
    if (M2C_FIELD(arg0, s16*, 0xA) < g) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, u8*, 6)++;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern s8 D_800CCF5C;
extern s32 D_800FDE30;

void func_800FD17C(void* arg0) {
    void* p;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x87, arg0);
        if (M2C_FIELD(arg0, s8*, 0x5C) < D_800CCF5C / 2) {
            M2C_FIELD(arg0, u8*, 0x45) = 0;
            p = func_8002C458();
            if (p != 0) {
                u8 b = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(p, u8*, 1) = 0x13;
                M2C_FIELD(p, u8*, 2) = 5;
                M2C_FIELD(p, void**, 0x7C) = arg0;
                M2C_FIELD(p, u8*, 0) = b;
            }
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 0);
        {
            u8* t = (u8*)&D_800FDE30 + 0x284;
            u8* q = t + (M2C_FIELD(arg0, u8*, 0x87)++ +
                         M2C_FIELD(arg0, u8*, 0x86) * 6);
            M2C_FIELD(arg0, u8*, 5) = *q;
        }
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

#define func_8003744C func_800FD264
#define D_80073C1C D_800FE1D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800FC83C func_800FD2A0
#include "../shared/rock_43/func_800FC83C.c"
#undef func_800FC83C

#include "common.h"

extern s32 D_800FDE30;

void func_800FD320(u8* arg0) {
    if (arg0[0x84] < 15) {
        arg0[0x84] = 30;
    }
    ((void (**)(u8*))((u8*)&D_800FDE30 + 0x3B0))[(s8)arg0[6]](arg0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800FD374(void* arg0) {
    play_sound(2, 0x94, arg0);
    set_animation(arg0, 8);
    M2C_FIELD(arg0, s16*, 0x7C) = -0x28;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s16*, 0x8A) = 1;
    {
        // !FAKE: byte read held in $3 so it schedules before the field stores
        register s32 c asm("$3");
        c = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = c + 1;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
    func_8002D230(arg0);
}

#define func_80041AB8 func_800FD3EC
#define D_80075FD8 D_800FE1E8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern u8 D_800970B5;

void func_800FD428(void* arg0) {
    // !FAKE: pin the halfword read to the register retail keeps it in
    register s32 t asm("$3") = M2C_FIELD(arg0, u16*, 0x42);

    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, u8*, 0x9A) = 0;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, u8*, 0x61) = 0x19;
    M2C_FIELD(arg0, u16*, 0x42) = t & 0x7FFF;
    set_animation(arg0, 8);
    play_sound(2, 0x94, arg0);
    M2C_FIELD(arg0, u8*, 0x5) += 1;
    func_8003D308(0x14, D_800970B5);
    func_8002CCB0(arg0, 0x40, 0x40);
}

#define func_800F5564 func_800FD4B0
#include "../shared/commander_yammark/func_800F5564.c"
#undef func_800F5564

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800FD5B0(void* arg0) {
    s8* p = M2C_FIELD(arg0, s8**, 0x80);

    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, u16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x40, 0x40);
        }
    } else {
        struct X4_EngineObj* e = &g_playthrough_state;

        if (M2C_FIELD(e, u8*, 0x8F) == 3) {
            M2C_FIELD(e, u8*, 0x5F) |= 0x20;
        }
        M2C_FIELD(e, u8*, 0xF) = 0x10;
        clear_object_slot(arg0, e);
    }
}

#include "common.h"

extern s32 D_800FDE30;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800FD664(void* arg0) {
    u8* src = *(u8**)((u8*)&D_800FDE30 + 0x468);
    s32 t;

    F16(arg0, 0x40) = F16(src, 0x40);
    F16(arg0, 0x42) = F16(src, 0x42) & 0x7FFF;
    F32(arg0, 0x30) = F32(src, 0x30);
    t = F32(src, 0x3C);
    F8(arg0, 0x14) = 0;
    F8(arg0, 0x16) = 3;
    F8(arg0, 0x67) = 0;
    F8(arg0, 0x3) = 0;
    F32(arg0, 0x68) = 0;
    F32(arg0, 0x50) = 0;
    F32(arg0, 0x54) = 0;
    F32(arg0, 0x58) = 0;
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x24) = 0;
    F32(arg0, 0x28) = 0;
    F32(arg0, 0x2C) = 0;
    F8(arg0, 0x5C) = 0;
    F8(arg0, 0x60) = 0;
    F8(arg0, 0x5) = 0;
    F8(arg0, 0x4)++;
    F32(arg0, 0x3C) = t;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FD6F0(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FD710(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern s32 D_800FDE30;
extern s32 D_800FE294;

void func_800FD730(void* arg0) {
    if ((M2C_FIELD(&D_800FDE30, s32*, 0x460) != 0) || (D_800FE294 != 0)) {
        M2C_FIELD(arg0, u8*, 4) += 1;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 4) += 1;
    }
    func_8002CCB0(arg0, 0x30, 0x20);
    func_80017A04(arg0);
    move_object(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FD7C4(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern s32 D_800FDE30;
extern s32 D_800FE294;

void func_800FD7E4(void* arg0) {
    if ((M2C_FIELD(&D_800FDE30, s32*, 0x460) != 0) || (D_800FE294 != 0)) {
        M2C_FIELD(arg0, u8*, 4) += 1;
        return;
    }
    check_enemy_hits(arg0);
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 10) {
            M2C_FIELD(arg0, u8*, 0x16) = 4;
            M2C_FIELD(arg0, u8*, 5) += 1;
        }
        break;
    case 1:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 100) {
            M2C_FIELD(arg0, u8*, 4) += 1;
        }
        break;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    func_80017A04(arg0);
    move_object(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FD8D4(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FD8F4(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800FDE30;

void func_800FD914(void* arg0) {
    void* p = M2C_FIELD(&D_800FDE30, void**, 0x468);
    void* q;
    s32 t;
    u8 b;

    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 3;
    q = M2C_FIELD(&D_800FDE30, void**, 0x468);
    M2C_FIELD(arg0, s32*, 0x3C) = t;
    b = M2C_FIELD(q, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = b;
    set_animation(arg0, 0xE);
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    play_sound(2, 0x8D, arg0);
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 4) += 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern s32 D_800FDE30;
extern s32 D_800FE294;

void func_800FD9D8(void* arg0) {
    if ((M2C_FIELD(&D_800FDE30, s32*, 0x460) != 0) || (D_800FE294 != 0)) {
        M2C_FIELD(arg0, u8*, 4) += 1;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 4) += 1;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    func_80017A04(arg0);
    move_object(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FDA6C(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FDA8C(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern s32 D_800FE290;
extern s32 D_800FE294;

void func_800FDAAC(struct X4_MainObj* self) {
    if (D_800FE290 != 0 || D_800FE294 != 0) {
        self->state++;
        return;
    }
    if (++M2C_FIELD(self, s32*, 0x8C) == 0x12) {
        self->state++;
    }
    func_8002CCB0(self, 0x20, 0x20);
    func_80017A04(self);
    move_object(self);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FDB44(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800FDE30;

void func_800FDB64(void* a) {
    void* p = M2C_FIELD(a, void**, 0x50);

    M2C_FIELD(a, u8*, 0x47) = M2C_FIELD(p, u8*, 0x47);
    M2C_FIELD(a, u8*, 0x15) = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(a, s32*, 0x38) = M2C_FIELD(p, s32*, 0x38);
    M2C_FIELD(a, s32*, 0x3C) = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(a, s32*, 0x18) = M2C_FIELD(a, s32*, 0x8);
    M2C_FIELD(a, s32*, 0x1C) = M2C_FIELD(a, s32*, 0xC);
    if (M2C_FIELD(a, s8*, 0x4) == 0) {
        if (M2C_FIELD(p, s8*, 0x9A) != 0) {
            if (M2C_FIELD(p, s8*, 0x9A) > 0) {
                M2C_FIELD(a, u8*, 0x3) = 1;
                M2C_FIELD(a, s16*, 0x54) = 3;
                M2C_FIELD(a, s16*, 0x56) = 8;
                M2C_FIELD(a, s16*, 0x58) = (5 - M2C_FIELD(a, s8*, 0x2)) * 2;
                M2C_FIELD(a, s32*, 0x8) = M2C_FIELD(p, s32*, 0x8);
                M2C_FIELD(a, s32*, 0xC) = M2C_FIELD(p, s32*, 0xC);
                M2C_FIELD(a, s8*, 0x4) = 1;
                M2C_FIELD(a, s8*, 0x5) = 0;
            } else {
                M2C_FIELD(p, s8*, 0x9A) = 0;
            }
        }
    } else if (M2C_FIELD(p, s8*, 0x9A) == 0) {
        M2C_FIELD(a, u8*, 0x3) = 0;
        M2C_FIELD(a, s8*, 0x4) = 0;
    } else {
        ((void (**)(void*, void*))((u8*)&D_800FDE30 +
                                   0x448))[M2C_FIELD(a, s8*, 0x5)](a, p);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FDC6C(void* arg0, struct PlayerObj* arg1) {
    void* temp_a0;

    if (M2C_FIELD(arg0, s16*, 0x54) != 0) {
        M2C_FIELD(arg0, s16*, 0x54) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x54) - 1);
    } else {
        temp_a0 = M2C_FIELD(arg0, void**, 0x5C);
        M2C_FIELD(arg0, s16*, 0x54) = 3;
        M2C_FIELD(arg0, s32*, 8) = (s32)M2C_FIELD(temp_a0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = (s32)M2C_FIELD(temp_a0, s32*, 0x1C);
    }
    if (arg1->shot_cycle < 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"

void func_800FDCD4(u8* a0, u8* a1) {
    if (*(s8*)(a1 + 0x9A) > 0) {
        *(s16*)(a0 + 0x54) = 3;
        *(s16*)(a0 + 0x56) = 8;
        *(s16*)(a0 + 0x58) = (5 - *(s8*)(a0 + 2)) * 2;
        *(s32*)(a0 + 0x8) = *(s32*)(a1 + 0x8);
        *(s32*)(a0 + 0xC) = *(s32*)(a1 + 0xC);
        *(u8*)(a0 + 4) = 1;
        *(u8*)(a0 + 5) = 0;
    } else if (*(s16*)(a0 + 0x56) != 0) {
        (*(s16*)(a0 + 0x56))--;
        if (*(s16*)(a0 + 0x56) & 1) {
            u8* p = *(u8**)(a0 + 0x5C);
            *(s32*)(a0 + 0x8) = *(s32*)(p + 0x18);
            *(s32*)(a0 + 0xC) = *(s32*)(p + 0x1C);
        }
    } else {
        (*(u8*)(a0 + 5))++;
    }
}

#include "common.h"

void func_800FDD84(u8* a0, u8* a1) {
    s32* p;

    if (*(s8*)(a1 + 0x9A) > 0) {
        *(s16*)(a0 + 0x54) = 3;
        *(s16*)(a0 + 0x56) = 8;
        *(s16*)(a0 + 0x58) = (5 - *(s8*)(a0 + 2)) * 2;
        *(s32*)(a0 + 8) = *(s32*)(a1 + 8);
        *(s32*)(a0 + 0xC) = *(s32*)(a1 + 0xC);
        a0[4] = 1;
        a0[5] = 0;
        return;
    }
    if (*(s16*)(a0 + 0x58) != 0) {
        p = *(s32**)(a0 + 0x5C);
        *(s32*)(a0 + 8) = p[6];
        *(s32*)(a0 + 0xC) = p[7];
        *(s16*)(a0 + 0x58) -= 1;
    } else {
        a0[3] = 0;
        a0[4] = 0;
        if (*(s8*)(a0 + 2) == 2) {
            a1[0x9A] = 0;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_43/nonmatchings/FA000", D_800FDE30);
// clang-format on
