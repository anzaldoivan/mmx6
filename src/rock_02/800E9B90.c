#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800E9B90(void) {
    if (D_800970AA > 0x800) {
        background_objects[1].unk4 = 2;
        background_objects[1].unk40 = 0;
        background_objects[1].unk42 = 0;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4 = 2;
        background_objects[2].unk40 = 0;
        background_objects[2].unk42 = 0;
        background_objects[2].unk4C = 1;
        return;
    }
    if (background_objects[1].unk4 == 2) {
        background_objects[1].unk4 = 1;
        background_objects[1].unk40 = 0;
        background_objects[1].unk42 = 0x230;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4 = 3;
        background_objects[2].unk40 = 0;
        background_objects[2].unk42 = 0x280;
        background_objects[2].unk4C = 1;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800E9C20);
// clang-format on

#define func_80048DC8 func_800E9D80
#define D_80077BC0 D_800FA98C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8002F288();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK collide_solid_object();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
void func_80032BE8(struct X4_PlayerObj*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800FA980;

void func_800E9DCC(void* arg0) {
    s32 v;

    v = M2C_FIELD(arg0, s8*, 0x5C);
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    if (check_enemy_hits(arg0) < 0) {
        for (v = 4; v >= 0; v--) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
        func_800477E4(3, &D_800FA980, arg0);
        func_80049E50(arg0);
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x5C) != v) {
        M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
    }
    func_80032BE8(arg0);
    func_8003208C(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x40, 0x40);
    } else {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
    func_8002F288(arg0);
    collide_solid_object(arg0);
    func_80031F4C(arg0);
    func_80030ECC(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800E9EDC(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002C9D4(); /* extern */

void func_800E9EFC(void) {
    func_8002C9D4();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FAA5C;
extern u8 D_800FAA98[];
extern u8 D_800FAAA0[];
extern u8 D_800FAAA8[];

void func_800E9F1C(struct X4_MainObj* arg0) {
    switch (arg0->unk2) {
    case 1:
        func_80027BA0(0, 0x1220, 0x370, D_800FAA98);
        break;
    case 2:
        func_80027BA0(0, 0x1300, 0x370, D_800FAAA0);
        break;
    case 3:
        func_80027BA0(0, 0x1340, 0x370, D_800FAAA8);
        break;
    }
    background_objects[0].unk4C = 1;
    arg0->y_pos.u.hi += 0x20;
    func_80049EBC(arg0, 1, 0x40, 0x20);
    func_80049EBC(arg0, 1, 0x40, 0x20);
    func_80049EBC(arg0, 1, 0x40, 0x20);
    func_80049EBC(arg0, 1, 0x40, 0x20);
    ((void (*)(s32, s32*, void*))func_800477E4)(6, &D_800FAA5C, arg0);
    arg0->y_pos.u.hi -= 0x20;
    if (background_objects[0].unk20 == background_objects[0].y_pos.i.hi) {
        func_80029478(8, 4, 2);
    }
    arg0->unk7C = 0x3C;
    arg0->unk6++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FAA5C;

#define SPAD (*(u8**)0x1F80004C)

void func_800EA09C(struct X4_MainObj* arg0) {
    if (!(arg0->unk7C & 7)) {
        arg0->y_pos.u.hi += 0x20;
        func_80049EBC(arg0, 1, 0x40, 0x20);
        func_80049EBC(arg0, 1, 0x40, 0x20);
        func_80049EBC(arg0, 1, 0x40, 0x20);
        arg0->y_pos.u.hi -= 0x20;
    }
    if (!(arg0->unk7C & 0xF)) {
        arg0->y_pos.u.hi += 0x20;
        ((void (*)(s32, s32*, void*))func_800477E4)(6, &D_800FAA5C, arg0);
        arg0->y_pos.u.hi -= 0x20;
        if (background_objects[0].unk20 == background_objects[0].y_pos.i.hi) {
            func_80029478(0xC, 1, 2);
        }
    }
    if (arg0->unk7C == 0x1E) {
        SPAD[0x83] = 1;
    }
    if (--arg0->unk7C == 0) {
        SPAD[0x82] = 1;
        arg0->unk5 = 5;
        arg0->unk6 = 0;
    }
}

#undef SPAD

#include "../shared/d1000/func_800EA1D8.c"

#define func_80041AB8 func_800EA224
#define D_80075FD8 D_800FAAC8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EA8E0(void*, s32);
extern M2C_UNK D_8007433C;
extern u8 D_800970B4;
extern M2C_UNK D_800FA99C;
extern M2C_UNK D_800FA9A0;
extern M2C_UNK D_800FA9A4;
extern M2C_UNK D_800FAA34;

void func_800EA260(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(SPAD4C, u16*, 0x80) = M2C_FIELD(arg0, u16*, 0xE);
    M2C_FIELD(SPAD4C, u8*, 0x82) = 1;
    M2C_FIELD(SPAD4C, u8*, 0x83) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, void**, 0x30) = &D_800FAA34;
    M2C_FIELD(arg0, u8*, 0x16) = 0x21;
    M2C_FIELD(arg0, void**, 0x68) = &D_800FA99C;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FA9A4;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FA9A0;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    set_animation(arg0, 0);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x5) = 2;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    func_800EA8E0(arg0, 0);
    func_800EA8E0(arg0, 1);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern void (*D_800FAA70[])(void*);

void func_800EA370(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    func_80017A04();
    D_800FAA70[M2C_FIELD(arg0, s8*, 5)](arg0);
    check_enemy_hits(arg0);
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x50, 0xA0) == 0) {
        func_8002CCB0(arg0, 0x30, 0x40);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = 2;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA40C(void) {
    func_8002CA54();
}

#define func_8003744C func_800EA42C
#define D_80073C1C D_800FAA88
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800CCF38;

void func_800EA468(u8* arg0) {
    set_animation(arg0, 0);
    if (D_800CCF38 >= 2) {
        *(s16*)(arg0 + 0x7C) = 0x2D;
    } else {
        *(s16*)(arg0 + 0x7C) = 0x5A;
    }
    arg0[6]++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_800CCF38;

#define SPAD (*(u8**)0x1F80004C)

void func_800EA4BC(struct X4_MainObj* arg0) {
    // !FAKE: pin the arm constant to the first return register (regalloc swap with the field read)
    register s32 n asm("$2");
    s32 v;
    if (D_800CCF38 >= 2) {
        v = arg0->unk7C;
        n = 0xF;
    } else {
        v = arg0->unk7C;
        n = 0x1E;
    }
    if (v == n) {
        SPAD[0x83] = 2;
    }
    if (--arg0->unk7C == 0) {
        arg0->unk5 = 3;
        arg0->unk6 = 0;
    }
}

#undef SPAD

#define func_8003744C func_800EA52C
#define D_80073C1C D_800FAA90
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800EA568(u8* arg0) {
    play_sound(2, 1, arg0);
    *(s32*)(arg0 + 0x24) = 0x1000;
    *(s32*)(arg0 + 0x2C) = 0x2000;
    set_animation(arg0, 3);
    SPAD4C[0x82] = 2;
    arg0[6]++;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_8002D230();

void func_800EA5D0(void* arg0) {
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            SPAD4C[0x82] = 0;
            SPAD4C[0x83] = 0;
            M2C_FIELD(arg0, u8*, 5) = 4;
            M2C_FIELD(arg0, u8*, 6) = 0;
            return;
        }
        SPAD4C[0x82] = 0;
        SPAD4C[0x83] = 0;
        M2C_FIELD(arg0, u8*, 5) = 4;
        M2C_FIELD(arg0, u8*, 6) = 2;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) >= M2C_FIELD(SPAD4C, s16*, 0x80) + 0x80) {
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(SPAD4C, u16*, 0x80) + 0x80;
        SPAD4C[0x82] = 0;
        SPAD4C[0x83] = 0;
        M2C_FIELD(arg0, u8*, 5) = 4;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

#define func_8003744C func_800EA6B8
#define D_80073C1C D_800FAAB0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EA6F4(void* arg0) {
    play_sound(2, 2, arg0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

void func_800EA738(struct X4_MainObj* self) {
    if (self->unk7C == 0x1E) {
        SPAD[0x83] = 1;
    }
    if (--self->unk7C == 0) {
        SPAD[0x82] = 1;
        self->unk5 = 5;
        self->unk6 = 0;
    }
}

#undef SPAD

#define func_8003744C func_800EA798
#define D_80073C1C D_800FAAC0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

#define SPAD4C_800EA7D4 (*(u8**)0x1F80004C)

void func_800EA7D4(void* arg0) {
    u8* p = arg0;
    ((void (*)(s32, s32, void*))play_sound)(2, 3, p);
    ((void (*)(void*, s32))set_animation)(p, 6);
    *(s32*)(p + 0x24) = 0x8000;
    *(s32*)(p + 0x2C) = 0;
    SPAD4C_800EA7D4[0x82] = 1;
    *(s16*)(p + 0x7C) = 0x3C;
    p[6]++;
}

#undef SPAD4C_800EA7D4

#include "common.h"
#define M2C_UNK s32
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230();

#define A840_SPAD (*(u8**)0x1F80004C)
#define A840_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define A840_UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define A840_UB(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800EA840(void* arg0) {
    func_8002D230(arg0);
    if (A840_H(arg0, 0xE) <= A840_H(A840_SPAD, 0x80)) {
        A840_UH(arg0, 0xE) = A840_UH(A840_SPAD, 0x80);
        A840_UB(A840_SPAD, 0x83) = 0;
        A840_UB(arg0, 5) = 2;
        A840_UB(arg0, 6) = 0;
        return;
    }
    if (--A840_H(arg0, 0x7C) == 0) {
        A840_UH(arg0, 0x7C) = 0x3C;
        play_sound(2, 3, arg0);
    }
}

#undef A840_SPAD
#undef A840_H
#undef A840_UH
#undef A840_UB

#include "common.h"

void func_800EA8D8(void) {
}

#include "common.h"
#include "mmx6/x4.h"

void* alloc_sprite_slot();

void func_800EA8E0(void* arg0, s32 arg1) {
    struct X4_MainObj* self = arg0;
    struct X4_MainObj* child;
    u8 v = arg1;

    child = alloc_sprite_slot();
    if (child != 0) {
        child->active = 0x41;
        child->id = 0;
        child->unk2 = v;
        child->unk15 = self->unk15;
        child->unk40 = self->unk40;
        child->unk42 = self->unk42 & 0x7FFF;
        child->animation_table = self->animation_table;
        child->sprite_frames = self->sprite_frames;
        child->bg_offset = self->bg_offset;
        do {
        } while (0);
        {
            s32 t = self->x_pos.u.hi;
            child->x_pos.u.lo = 0;
            child->x_pos.u.hi = t;
        }
        {
            s32 t = self->y_pos.u.hi;
            child->y_pos.u.lo = 0;
            child->attack_box = arg0;
            child->y_pos.u.hi = t;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define A990_SP64 (*(u8**)(0x1F800064))

M2C_UNK set_animation(void*, M2C_UNK);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EA990(void* arg0) {
    s8 temp_s1;

    F(u8, 0x15) = 0;
    *(s16*)(A990_SP64 + 0x56) = 0;
    temp_s1 = F(s8, 0x2);
    switch (temp_s1) {
    case 0:
        F(u8, 0x16) = 0x20;
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        F(u8, 0x3) = 1;
        F(u8, 0x5) = 0;
        break;
    case 1:
        F(u8, 0x16) = 0x20;
        ((void (*)(void*, s32))set_animation)(arg0, 2);
        F(u8, 0x3) = 0;
        F(u8, 0x5) = temp_s1;
        break;
    }
    F(s32, 0x20) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x4) = 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern void (*D_800FAAD4[])(s8*);

#define AA40_SP64 (*(u8**)(0x1F800064))
#define AA40_P(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800EAA40(s8* arg0) {
    if (((s8*)AA40_P(arg0, 0x50))[4] == 2) {
        arg0[3] = 0;
        ((u8*)arg0)[4]++;
        return;
    }
    func_80017A04(arg0);
    D_800FAAD4[arg0[5]](arg0);
    *(s16*)(arg0 + 0xE) =
        *(s16*)(AA40_P(arg0, 0x50) + 0xE) + *(s16*)(AA40_SP64 + 0x56);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EAAD8(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

#define AAF8_SP64 (*(u8**)(0x1F800064))
#define AAF8_UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define AAF8_P(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800EAAF8(u8* arg0) {
    u8 mode;

    mode = AAF8_UB(AAF8_P(arg0, 0x50), 0x82);
    if (AAF8_UB(AAF8_SP64, 0x54) != mode) {
        switch (mode) {
        case 0:
            AAF8_UB(arg0, 3) = 0;
            break;
        case 1:
            AAF8_UB(arg0, 0x16) = 0x22;
            AAF8_UB(arg0, 3) = mode;
            set_animation(arg0, 1);
            break;
        case 2:
            AAF8_UB(arg0, 0x16) = 0x20;
            AAF8_UB(arg0, 3) = 1;
            set_animation(arg0, 4);
            break;
        }
    }
    AAF8_UB(AAF8_SP64, 0x54) = mode;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

#define ABB0_SP64 (*(u8**)(0x1F800064))
#define ABB0_UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define ABB0_SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define ABB0_P(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800EABB0(u8* arg0) {
    u8* obj;
    u8 mode;

    obj = ABB0_P(arg0, 0x50);
    mode = ABB0_UB(obj, 0x83);
    if (ABB0_UB(obj, 0x47) == 0x17) {
        ABB0_SH(ABB0_SP64, 0x56) = -1;
    } else {
        ABB0_SH(ABB0_SP64, 0x56) = 0;
    }
    if (ABB0_UB(ABB0_SP64, 0x54) != mode) {
        switch (mode) {
        case 0:
            ABB0_UB(arg0, 3) = 0;
            break;
        case 1:
            ABB0_UB(arg0, 3) = mode;
            set_animation(arg0, 5);
            break;
        case 2:
            ABB0_UB(arg0, 3) = 1;
            set_animation(arg0, 2);
            break;
        }
    }
    ABB0_UB(ABB0_SP64, 0x54) = mode;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(void*, s8);
void func_800EB1F4();
extern s32 D_800970A8;
extern M2C_UNK D_800FAB44;
extern void (*D_800FAB58[])(void*);

void func_800EAC8C(void* arg0) {
    u8 temp_a0;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800FAB58[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 2) != 0 && M2C_FIELD(arg0, u8*, 0x47) == 0) {
        if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
    }
    func_800EB1F4(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_8004E654(arg0, 0x15);
        func_80049E50(arg0);
        func_800477E4(4, &D_800FAB44, arg0);
        func_8004E654(arg0, 0xE);
        goto block_10;
    }
    temp_a0 = M2C_FIELD(arg0, u8*, 0x70);
    if ((temp_a0 & 0xC) == 0xC || (temp_a0 & 3) == 3) {
        func_8004E654(arg0, 0x15);
        func_80049E50(arg0);
        func_800477E4(4, &D_800FAB44, arg0);
    block_10:
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 3;
}

#include "../shared/rock_02/func_800EAE0C.c"

#define func_800EA1D8 func_800EAFB0
#define D_800FAA64 D_800FAB48
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800743DC;
extern M2C_UNK g_Player;
extern u8 D_800CCF38;
extern M2C_UNK D_800FAADC;
extern M2C_UNK D_800FAAE0;
extern M2C_UNK D_800FAAE4;
extern M2C_UNK D_800FAB24;

void func_800EAFFC(void* arg0) {
    s32 x;
    s32 y;
    u8 b;
    u8* pl;

    M2C_FIELD(arg0, u8*, 0x5C) = 0xC;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, void**, 0x58) = &D_800743DC;
    pl = (u8*)&g_Player;
    b = M2C_FIELD(pl, u8*, 0x14);
    x = M2C_FIELD(arg0, s32*, 8);
    y = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    M2C_FIELD(arg0, s32*, 0x18) = x;
    M2C_FIELD(arg0, s32*, 0x1C) = y;
    if (M2C_FIELD(pl, s32*, 8) < x) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, void**, 0x30) = &D_800FAB24;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, void**, 0x68) = &D_800FAADC;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FAAE4;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FAAE0;
    set_animation(arg0, 0);
    {
        // !FAKE: depin: dropping it breaks the match (64/68)
        register s32 one asm("$2") = 1;
        M2C_FIELD(arg0, u8*, 5) = one;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 1;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 6) = 0;
    if (D_800CCF38 >= 2) {
        M2C_FIELD(arg0, u8*, 2) = 1;
    }
}

#include "../shared/rock_02/func_800EB10C.c"

#include "../shared/rock_02/func_800EB14C.c"

#include "../shared/rock_02/func_800EB1A0.c"

#define func_800EBC8C func_800EB1F4
#include "../shared/rock_28/func_800EBC8C.c"
#undef func_800EBC8C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern u8 D_800CCF38;
extern M2C_UNK D_800FAB68;
extern M2C_UNK D_800FAB6C;

void func_800EB23C(void* arg0) {
    s32 vx;
    u8 dir;
    s32 x;

    vx = 0xFFFE0000;
    dir = M2C_FIELD(arg0, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (dir != 0) {
        vx = 0x20000;
    }
    x = M2C_FIELD(arg0, s16*, 0xA);
    M2C_FIELD(arg0, s32*, 0x20) = vx;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (dir != 0) {
        x += 0x10;
    } else {
        x -= 0x10;
    }
    M2C_FIELD(arg0, s16*, 0xA) = x;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, void**, 0x68) = &D_800FAB6C;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FAB68;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FAB68;
    {
        // !FAKE: depin: dropping it breaks the match (57/65)
        register s32 one asm("$4") = 1;
        M2C_FIELD(arg0, u8*, 0x5C) = one;
        M2C_FIELD(arg0, u8*, 0x60) = one;
    }
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, s16*, 0xE) -= 0xC;
    M2C_FIELD(arg0, s16*, 0x42) &= 0x7FFF;
    if (D_800CCF38 >= 2) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        set_animation(arg0, 7);
    } else {
        M2C_FIELD(arg0, void**, 0x58) = D_800741FC;
        set_animation(arg0, 6);
    }
    M2C_FIELD(arg0, u8*, 4) += 1;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

void func_800EB340(void* arg0) {
    func_80017A04();
    ((void (*)(void*))move_object)(arg0);
    if (func_80030ECC(arg0) != 0) {
    block_1:
        func_80049E50(arg0);
    } else {
        if (check_enemy_hits(arg0) < 0) {
            goto block_1;
        }
        if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
            goto block_1;
        }
        func_8002EE10(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
            goto block_1;
        }
        if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
    }
    M2C_FIELD(arg0, u8*, 4) = 2;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB3F4(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800EB414
#define D_80075FD8 D_800FAB70
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void* alloc_sprite_slot();
extern s32 D_8007447C;
extern u8 D_800970B4;
extern s32 D_800FAB7C;
extern s32 D_800FAB80;
extern s32 D_800FAB84;
extern s32 D_800FACD4;

void func_800EB450(struct X4_MainObj* arg0) {
    struct X4_MainObj* child;
    u8 v;

    arg0->unk7C = 0;
    arg0->hp = 0x20;
    arg0->invincibility_timer = 0;
    v = D_800970B4;
    arg0->animation_table = (void*)&D_800FACD4;
    arg0->unk16 = 6;
    arg0->terrain_box = (void*)&D_800FAB7C;
    arg0->bg_offset = v;
    arg0->hurt_box = &D_800FAB84;
    arg0->attack_box = &D_800FAB80;
    arg0->air_state = 0;
    arg0->collision_data = &D_8007447C;
    arg0->contact_damage = 4;
    arg0->unk5 = 2;
    arg0->unk15 = 0;
    arg0->x_speed = 0;
    arg0->x_accel = -0xC00;
    arg0->unk18.val = arg0->x_pos.val;
    arg0->y_speed = 0;
    arg0->gravity = 0x2000;
    arg0->state = 1;
    arg0->unk6 = 0;
    arg0->unk1C.val = arg0->y_pos.val;
    if (arg0->unk2 == 0) {
        arg0->unk7 = 0;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 2, v);
    } else {
        arg0->unk7 = 0x40;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0, v);
    }
    arg0->ext.raw[0] = arg0->animation_step.fields.frame_index;
    child = alloc_sprite_slot();
    if (child != 0) {
        child->active = 0x41;
        child->id = 2;
        child->unk2 = arg0->animation_step.fields.frame_index;
        child->unk40 = arg0->unk40;
        child->unk42 = arg0->unk42 & 0x7FFF;
        child->animation_table = arg0->animation_table;
        child->sprite_frames = arg0->sprite_frames;
        child->bg_offset = arg0->bg_offset;
        child->x_pos.val = arg0->x_pos.val;
        child->y_pos.u.hi = arg0->y_pos.u.hi;
        child->unk15 = arg0->unk15;
        child->attack_box = arg0;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
void func_8004E654(void*, s8);
void func_800EBF28(void* arg0);
extern M2C_UNK D_800FAD00;
extern void (*D_800FAD14[])(void*);

void func_800EB5E4(void* arg0) {
    s32 i;
    s32 lim;
    s32 over;

    M2C_FIELD(arg0, s32*, 0x80) = M2C_FIELD(arg0, u8*, 0x47);
    func_800EBF28(arg0);
    D_800FAD14[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        lim = 0xC000;
        over = M2C_FIELD(arg0, s32*, 0x20) > lim;
    } else {
        lim = -0xC000;
        over = M2C_FIELD(arg0, s32*, 0x20) < lim;
    }
    if (over) {
        M2C_FIELD(arg0, s32*, 0x20) = lim;
    }
    if (check_enemy_hits(arg0) < 0) {
        for (i = 0; i < 5; i++) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
        goto block_13;
    }
    if ((M2C_FIELD(arg0, u8*, 0x70) & 0xC) == 0xC) {
        for (i = 0; i < 5; i++) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
    block_13:
        func_800477E4(3, &D_800FAD00, arg0);
        func_8004E654(arg0, 0x14);
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x80, 0x80) == 0) {
        func_8002CCB0(arg0, 0x60, 0x60);
    } else {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s8*, 0x67) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
        M2C_FIELD(arg0, s8*, 0x67) = -1;
    } else {
        M2C_FIELD(arg0, s8*, 0x67) = 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EB78C(u8* arg0) {
    s32 n;
    s32 i;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[5] = 2;
        arg0[6] = 0;
        if (*(s8*)(arg0 + 7) == 0) {
            *(s32*)(arg0 + 0x28) = 0xC00;
            set_animation(arg0, 0);
            arg0[7] = 0x40;
            switch (arg0[0x80]) {
            case 0:
                n = 4;
                break;
            case 1:
                n = 8;
                break;
            case 2:
                n = 0xC;
                break;
            case 3:
                n = 0x10;
                break;
            case 4:
                n = 0x14;
                break;
            case 5:
                n = 0x18;
                break;
            case 6:
                n = 0x1C;
                break;
            case 7:
                n = 0;
                break;
            }
            for (i = 0; i < n; i++) {
                func_80017A04(arg0);
            }
        } else {
            *(s32*)(arg0 + 0x28) = -0xC00;
            set_animation(arg0, 2);
            arg0[7] = 0;
            switch (arg0[0x80]) {
            case 0:
                n = 0;
                break;
            case 1:
                n = 0x1C;
                break;
            case 2:
                n = 0x18;
                break;
            case 3:
                n = 0x14;
                break;
            case 4:
                n = 0x10;
                break;
            case 5:
                n = 0xC;
                break;
            case 6:
                n = 8;
                break;
            case 7:
                n = 4;
                break;
            }
            for (i = 0; i < n; i++) {
                func_80017A04(arg0);
            }
        }
    }
}

#include "../shared/rock_02/func_800EB924.c"

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800EBA8C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002F288();
void func_800EBF68(void* arg0);
extern void (*D_800FAD04[])(void*);

void func_800EBC24(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    D_800FAD04[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
    func_800EBF68(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EBC98(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EBCB8(void) {
    func_8002CA54();
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern s32 D_8009719C;

void func_800EBCD8(void* arg0) {
    s32 temp_v0;
    s32 var_v0;

    M2C_FIELD(arg0, s32*, 0x8) += M2C_FIELD(arg0, s32*, 0x20);
    M2C_FIELD(arg0, s32*, 0xC) =
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg0, s32*, 0x24);
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) += M2C_FIELD(arg0, s32*, 0x28);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) -= M2C_FIELD(arg0, s32*, 0x28);
    }
    temp_v0 = M2C_FIELD(arg0, s32*, 0x24) - M2C_FIELD(arg0, s32*, 0x2C);
    M2C_FIELD(arg0, s32*, 0x24) = temp_v0;
    if (temp_v0 < D_8009719C) {
        M2C_FIELD(arg0, s32*, 0x24) = D_8009719C;
    }
    func_80017A04(arg0);
    var_v0 = M2C_FIELD(arg0, s8*, 7);
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
    } else {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
    }
    if (var_v0 != 0) {
        play_sound(2, 4, arg0);
        M2C_FIELD(arg0, s16*, 0x8) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern s32 D_8009719C;

void func_800EBDC8(void* arg0) {
    s32 temp_v0;
    // !FAKE: depin: dropping it breaks the match (51/54)
    register s32 flag asm("$2");

    func_80017A04();
    flag = M2C_FIELD(arg0, u8*, 0x70) & 8;
    if (flag != 0) {
        play_sound(2, 4, arg0);
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = -0xC00;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        return;
    }
    M2C_FIELD(arg0, s32*, 0x8) += M2C_FIELD(arg0, s32*, 0x20);
    M2C_FIELD(arg0, s32*, 0xC) =
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg0, s32*, 0x24);
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) =
            M2C_FIELD(arg0, s32*, 0x20) + M2C_FIELD(arg0, s32*, 0x28);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) =
            M2C_FIELD(arg0, s32*, 0x20) - M2C_FIELD(arg0, s32*, 0x28);
    }
    temp_v0 = M2C_FIELD(arg0, s32*, 0x24) - M2C_FIELD(arg0, s32*, 0x2C);
    M2C_FIELD(arg0, s32*, 0x24) = temp_v0;
    if (temp_v0 < D_8009719C) {
        M2C_FIELD(arg0, s32*, 0x24) = D_8009719C;
    }
}

#define func_8003744C func_800EBEA0
#define D_80073C1C D_800FAD24
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EBEDC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "../shared/rock_02/func_800EBEF4.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EBF28(void* arg0) {
    if ((M2C_FIELD(arg0, s8*, 0x67) == 0) &&
        !(M2C_FIELD(arg0, u8*, 0x70) & 8)) {
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = -1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EB924(void*, void*); /* extern */
extern M2C_UNK D_80090C88;

void func_800EBF68(void* arg0) {
    u32 var_s0;

    var_s0 = arg0 + 0x9C;
    if (var_s0 < (u32)&D_80090C88) {
        do {
            if ((M2C_FIELD(var_s0, s8*, 0) != 0) &&
                (M2C_FIELD(arg0, s8*, 1) == M2C_FIELD(var_s0, s8*, 1))) {
                func_800EB924((void*)var_s0, arg0);
            }
            var_s0 += 0x9C;
        } while (var_s0 < (u32)&D_80090C88);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EBA8C(); /* extern */
M2C_UNK func_800EC044(); /* extern */
M2C_UNK func_800EC084(); /* extern */

void func_800EBFEC(struct ObjectHeader* arg0) {
    s8 temp_v1;

    temp_v1 = arg0->state;
    if (temp_v1 == 0) {
        func_800EC044();
        return;
    }
    if (temp_v1 == 1) {
        func_800EBA8C();
        return;
    }
    func_800EC084();
}

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800EC044);

INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800EC084);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern M2C_UNK D_800FADC4;
extern M2C_UNK D_800FADF8;
extern M2C_UNK D_800FAE00;

void func_800EC11C(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (96/103)
    register s32 t asm("$5") = D_800970B4;
    // !FAKE: depin: dropping it breaks the match (95/103)
    register void* q asm("$3") = &D_800FADF8;

    M2C_FIELD(arg0, void**, 0x30) = &D_800FADC4;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FAE00;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x54) = q;
    M2C_FIELD(arg0, void**, 0x58) = &D_800743DC;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 5;
    M2C_FIELD(arg0, u8*, 0x60) = 3;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = t;
    SPAD4C[0x81] = random_byte() & 3;
    SPAD4C[0x89] = 0;
    if (M2C_FIELD(arg0, s8*, 2) & 0x80) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, u8*, 0x67) = 1;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        set_animation(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 3;
    }
    if ((M2C_FIELD(arg0, u8*, 2) & 0xF) == 1) {
        M2C_FIELD(arg0, u8*, 0x4) = 3;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        set_animation(arg0, 1);
        SPAD4C[0x8A] = M2C_FIELD(arg0, u8*, 0x6);
        SPAD4C[0x8B] = M2C_FIELD(arg0, u8*, 0x7C);
        *(u16*)(SPAD4C + 0x8E) = M2C_FIELD(arg0, u16*, 0xE);
        *(s32*)(SPAD4C + 0x90) = M2C_FIELD(arg0, s32*, 0x24);
        *(s32*)(SPAD4C + 0x94) = M2C_FIELD(arg0, s32*, 0x2C);
        M2C_FIELD(arg0, u8*, 0x5) = 7;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002D380(void*, void*);
extern M2C_UNK g_Player;
extern u8 D_800FAE14[];

void func_800EC2B8(void* arg0) {
    void* g;

    if (--((s8*)SPAD4C)[0x80] != 0) {
        return;
    }
    g = &g_Player;
    if (M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA) > 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    SPAD4C[0x85] = func_8002D380(arg0, g);
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        SPAD4C[0x85] = D_800FAE14[(s8)SPAD4C[0x85]];
    }
    switch ((s8)SPAD4C[0x85] & 0xFE) {
    case 2:
    case 4:
    case 6:
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    case 10:
    case 12:
    case 14:
        if ((s8)SPAD4C[0x85] >= 10) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        set_animation(arg0, 4);
        break;
    case 8:
        set_animation(arg0, 2);
        break;
    case 18:
    case 20:
    case 22:
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    case 26:
    case 28:
    case 30:
        if ((s8)SPAD4C[0x85] >= 0x1A) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
        set_animation(arg0, 5);
        break;
    case 24:
        set_animation(arg0, 3);
        break;
    case 0:
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        break;
    case 16:
        set_animation(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        break;
    }
    M2C_FIELD(arg0, u8*, 6)++;
}

#include "../shared/rock_02/func_800EC484.c"

#include "../shared/rock_02/func_800EC640.c"

#include "common.h"
#define M2C_UNK s32

#define SELF ((u8*)arg0)
#define SPAD4C (*(u8**)0x1F80004C)

extern s16 D_800970AA;
extern s16 D_800FAE04[];

void func_800EC784(void* arg0) {
    u8* p;
    s16 lim;
    s16 y;
    s16 x;
    s32 d;
    s8 st;
    u8 c;

    if (*(s8*)(SELF + 0x67) == 0) {
        st = *(s8*)(SELF + 5);
        if (st != 4) {
            if (st != 5) {
                p = SPAD4C;
                lim = D_800FAE04[*(s8*)(p + 0x81)];
                if (*(s8*)(SELF + 2) == 3) {
                    c = p[0x89];
                    if (c == 0) {
                        SELF[5] = 4;
                        SELF[6] = 0;
                        return;
                    }
                    p[0x89] = c - 1;
                    return;
                }
                x = D_800970AA;
                y = *(s16*)(SELF + 0xA);
                d = x - y;
                if (d >= 0) {
                    if (lim >= d) {
                        goto store;
                    }
                    return;
                }
                if (lim < y - x) {
                    return;
                }
            store:
                SELF[5] = 4;
                SELF[6] = 0;
            }
        }
    }
}
#undef SELF

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800EC848);

INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800EC9C8);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern s32 D_800FAEC0[];
extern s32 D_800FAEC8[];
extern s8 D_800FAECC[];

void func_800ECA60(void* self) {
    void* parent;

    M2C_FIELD(self, s8*, 3) = 1;
    M2C_FIELD(self, void**, 0x68) = D_800FAEC8;
    M2C_FIELD(self, void**, 0x54) = D_800FAEC0;
    M2C_FIELD(self, void**, 0x50) = D_800FAEC0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, s8*, 0x67) = 0;
    M2C_FIELD(self, s8*, 0x16) = 1;
    M2C_FIELD(self, void**, 0x58) = D_800741FC;
    M2C_FIELD(self, u8*, 4)++;
    parent = M2C_FIELD(self, void**, 0x7C);
    M2C_FIELD(self, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(self, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(self, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    M2C_FIELD(self, u8*, 0x15) = M2C_FIELD(parent, u8*, 0x15);
    M2C_FIELD(self, u8*, 0x14) = M2C_FIELD(parent, u8*, 0x14);
    M2C_FIELD(self, s8*, 0x60) = 3;
    M2C_FIELD(self, s8*, 0x5C) = 1;
    M2C_FIELD(self, s32*, 0x20) *= 2;
    M2C_FIELD(self, s32*, 0x24) *= 2;
    switch (M2C_FIELD(self, s8*, 2) & 0xFE) {
    case 2:
    case 4:
    case 6:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[6];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[7];
        break;
    case 10:
    case 12:
    case 14:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[4];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[5];
        break;
    case 8:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[8];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[9];
        break;
    case 18:
    case 20:
    case 22:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[12];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[13];
        break;
    case 26:
    case 28:
    case 30:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[14];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[15];
        break;
    case 24:
        M2C_FIELD(self, s16*, 0xA) += D_800FAECC[10];
        M2C_FIELD(self, s16*, 0xE) += D_800FAECC[11];
        break;
    default:
        if (M2C_FIELD(self, u8*, 0x15) & 0x40) {
            M2C_FIELD(self, s16*, 0xA) += D_800FAECC[2];
            M2C_FIELD(self, s16*, 0xE) += D_800FAECC[3];
        } else {
            M2C_FIELD(self, s16*, 0xA) += D_800FAECC[0];
            M2C_FIELD(self, s16*, 0xE) += D_800FAECC[1];
        }
        break;
    }
    set_animation(self, 6);
}

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800ECCF0);
// clang-format on

#define func_80041AB8 func_800ECF3C
#define D_80075FD8 D_800FAE34
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
s32 func_8002CAB4(struct X4_BaseObj*);
M2C_UNK func_8002CB50();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(void*, s8);
void func_800EC784(void*);
extern s32 D_800970A8;
extern M2C_UNK D_800FAE0C;
extern void (*D_800FAE48[])(void*);

void func_800ECF78(void* arg0) {
    s8 v;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        func_8004E654(arg0, 0x12);
        func_800477E4(5, &D_800FAE0C, arg0);
        v = 2;
        goto end;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
    }
    func_800EC784(arg0);
    if (SPAD[0x89] < 0x3C) {
        D_800FAE48[M2C_FIELD(arg0, s8*, 5)](arg0);
    } else {
        func_80017A04(arg0);
    }
    func_80030ECC(arg0);
    if (func_8002CAB4(arg0) != 0) {
        v = 4;
        goto end;
    }
    func_8002CB50(arg0);
    return;
end:
    M2C_FIELD(arg0, u8*, 4) = v;
}

#include "../shared/rock_02/func_800ED09C.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800ED174(void* arg0) {
    if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) >= 0xB0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 3;
    }
}

#include "common.h"

void func_800ED1B4(void) {
}

#define func_8003744C func_800ED1BC
#define D_80073C1C D_800FAE68
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800ED1F8.c"

#include "../shared/rock_02/func_800ED25C.c"

#define func_8003744C func_800ED2B8
#define D_80073C1C D_800FAE70
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800ED2F4.c"

#include "../shared/rock_02/func_800ED370.c"

#include "../shared/rock_02/func_800ED3D4.c"

#include "../shared/rock_02/func_800ED420.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED470(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/rock_02/func_800ED498.c"

#include "../shared/rock_02/func_800ED520.c"

#define func_800ED3D4 func_800ED590
#define D_800FAE78 D_800FAE90
#include "../shared/rock_02/func_800ED3D4.c"
#undef func_800ED3D4
#undef D_800FAE78

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002D380(void*, void*);
void func_800EC848(void*);
extern M2C_UNK g_Player;

void func_800ED5DC(void* arg0) {
    void* g;

    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 6)++;
    set_animation(arg0, 1);
    g = &g_Player;
    {
        // !FAKE: depin: dropping it breaks the match (36/40)
        register u8** b asm("$2") = &SPAD4C;
        s32 k = 0x14;
        // !FAKE: depin: dropping it breaks the match (38/40)
        register u8* p asm("$5") = *b;
        u8* q;
        p[0x80] = k;
        q = *b;
        q[0x82] = 0;
    }
    if (M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA) > 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    SPAD4C[0x85] = func_8002D380(arg0, g);
    func_800EC848(arg0);
}

#include "../shared/rock_02/func_800ED67C.c"

/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_48_sentry_drone.c:sentry_drone_spread_repeat, AGPL-3.0; proven shared with X6 by exact signature be9839e079dd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800EC9C8(struct X4_MainObj*);

void func_800ED7B8(struct X4_MainObj* self) {
    if (SP_CUR_MAIN_OBJ->ext.main_48.unk82 < 9) {
        func_800EC9C8(self);
        self->unk6 -= 2;
    } else {
        self->unk6++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED818(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED82C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x67) = -1;
    M2C_FIELD(arg0, s8*, 5) = 6;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800ED844
#define D_80073C1C D_800FAEA8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800ED880.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();  /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800ED8C0(s32 arg0) {
    func_80017A04();
    move_object(arg0);
}

#include "../shared/rock_02/func_800ED8EC.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04(void*);          /* extern */
extern s16 D_800970AA;

void func_800ED980(void* arg0) {
    if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) > 0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    }
    set_animation(arg0, 1);
    func_80017A04(arg0);
    M2C_FIELD(arg0, s16*, 0x7E) = 0x20;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFE0000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "../shared/rock_02/func_800EDA04.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();      /* extern */
M2C_UNK func_8002D230(void*); /* extern */

void func_800EDA7C(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_8002D230(arg0);
    if (M2C_FIELD(arg0, s32*, 0x24) == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/rock_02/func_800EDAD4.c"

#include "../shared/rock_02/func_800EDB48.c"

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
s32 func_8002D654(s8*, u8*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK g_Player;

void func_800EDBB4(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    move_object((s32)arg0);
    if (func_80030ECC(arg0) == 0) {
        if (check_enemy_hits(arg0) < 0) {
        block_2:
            func_80049E50(arg0);
        } else if (func_8002D654((s8*)arg0, (u8*)&g_Player) == 0) {
            if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
                goto block_2;
            }
            if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
                func_8002CCB0(arg0, 0x10, 0x10);
                return;
            }
        }
    }
    M2C_FIELD(arg0, u8*, 4)++;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDC6C(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EDC8C(void) {
}

#define func_80048DC8 func_800EDC94
#define D_80077BC0 D_800FAEFC
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "../shared/rock_02/func_800EDCE0.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDD40(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern M2C_UNK D_8007433C;
extern s32 D_80074B5C;
extern s8 D_8009711A;
extern s32 D_800FB1A4;
extern s32 D_800FBC70;

void func_800EDD60(void* arg0) {
    s32 r;
    u8 t;

    r = check_enemy_hits(arg0);
    if (r < 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        D_800FBC70 = 1;
        D_8009711A = 1;
        func_8002CCB0(arg0, 0x64, 0x64);
        return;
    }
    M2C_FIELD(arg0, u8*, 0x88) |= func_80030ECC(arg0);
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, u8*, 0x84) = ((u32)(r - 0x19) < 2) ? 2 : 0x1E;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    }
    if (M2C_FIELD(arg0, s8*, 5) == 0x63) {
        M2C_FIELD(arg0, u8*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s8*, 5) = 0xA;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
    t = M2C_FIELD(arg0, u8*, 0x84);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x84) = t + 0xFF;
        if (t & 8) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_80074B5C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    ((void (**)(void*)) & D_800FB1A4)[M2C_FIELD(arg0, s8*, 5)](arg0);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
extern s32 D_800FAF08;

void func_800EDED4(void* arg0) {
    if (M2C_FIELD(arg0, void**, 0x68) == 0 &&
        M2C_FIELD(arg0, s16*, 0xE) >= 0x120) {
        M2C_FIELD(arg0, void**, 0x68) = &D_800FAF08;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        play_sound(2, 5, arg0);
        func_80012D9C(3);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        {
            s32 idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
            s32 base = SPAD20;
            // !FAKE: depin: dropping it breaks the match (35/64)
            register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);
            M2C_FIELD(arg0, s32*, 0x3C) = base + off;
            ((void (*)(void*, s32, s32))set_animation)(arg0, 8, off);
        }
        func_80029478(0x14, 4, 2);
        {
            // !FAKE: depin: dropping it breaks the match (61/64)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 7) = 0;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
    M2C_FIELD(arg0, s32*, 0x24) -= M2C_FIELD(arg0, s32*, 0x2C);
    func_80017A04(arg0);
    ((void (*)(void*))move_object)(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
void* enemy_slot_alloc();
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_8004A768();

void func_800EDFD4(void* arg0) {
    void* p;
    s32 x;
    s32 v;

    M2C_FIELD(arg0, s16*, 0x7C) = M2C_FIELD(arg0, s16*, 0x7C) + 1;
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0x14) {
        func_80029478(0x14, 2, 2);
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) < 0x1E &&
        !(M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
        x = M2C_FIELD(arg0, s16*, 0xA);
        func_8004A768(0x20, x - 0x64, 0x190, x + 0x64, 0x1A0, 8);
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0x78) {
        p = enemy_slot_alloc();
        if (p != 0) {
            u8 t;
            M2C_FIELD(p, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
            t = M2C_FIELD(arg0, u8*, 1);
            M2C_FIELD(p, u8*, 2) = 1;
            M2C_FIELD(p, void**, 0x80) = arg0;
            M2C_FIELD(p, u8*, 1) = t;
        }
    }
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        if (M2C_FIELD(arg0, s8*, 7) == 1) {
            v = *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20 +
                        4);
            M2C_FIELD(arg0, s32*, 0x3C) = SPAD20 + v;
            set_animation(arg0, 9);
            {
                // !FAKE: depin: dropping it breaks the match (106/109)
                register s32 n asm("$2") = M2C_FIELD(arg0, u8*, 7) + 1;
                M2C_FIELD(arg0, u8*, 7) = n;
            }
        } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            p = func_8002C458();
            if (p != 0) {
                u8 t = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(p, u8*, 1) = 1;
                M2C_FIELD(p, u8*, 2) = 4;
                M2C_FIELD(p, void**, 0x7C) = arg0;
                M2C_FIELD(p, u8*, 0) = t;
            }
            play_sound(2, 4, arg0);
            M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 random_byte();
extern s16 D_800970AA;
extern u8 D_800CCF5C;
#define D_800CCF5C (*(s8*)&D_800CCF5C)

void func_800EE188(void* arg0) {
    u32 r;

    r = random_byte() & 0xF;
    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x3C) {
        if (M2C_FIELD(arg0, s8*, 6) == 0) {
            if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                if (r < 8) {
                    M2C_FIELD(arg0, u8*, 5) = 9;
                } else {
                    M2C_FIELD(arg0, u8*, 5) = 8;
                }
            } else if (r < 6) {
                M2C_FIELD(arg0, u8*, 5) = 9;
            } else {
                M2C_FIELD(arg0, u8*, 5) = 7;
            }
        } else {
            if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                if (r < 8) {
                    M2C_FIELD(arg0, u8*, 5) = 5;
                } else {
                    M2C_FIELD(arg0, u8*, 5) = 8;
                }
            } else if (r < 6) {
                M2C_FIELD(arg0, u8*, 5) = 8;
            } else {
                M2C_FIELD(arg0, u8*, 5) = 7;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
#undef D_800CCF5C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;

void func_800EE2C4(void* arg0) {
    s32 g = D_800970AA;
    s32 x = M2C_FIELD(arg0, s16*, 0xA);
    s32 v;

    if ((g - x >= 0 ? g - x : x - g) < 0x3D) {
        v = 6;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
    } else {
        if (++M2C_FIELD(arg0, s16*, 0x7C) != 0x78) {
            return;
        }
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        set_animation(arg0, 0);
        v = 4;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    M2C_FIELD(arg0, u8*, 5) = v;
    M2C_FIELD(arg0, u8*, 6) = 0;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800EE390(void* arg0) {
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x5A ||
        M2C_FIELD(arg0, u8*, 0x88) != 0) {
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
        M2C_FIELD(arg0, u8*, 6)++;
    } else if (M2C_FIELD(arg0, s16*, 0x7C) == 0x3C) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    } else if (M2C_FIELD(arg0, s16*, 0x7C) < 0x3C &&
               !(*(volatile s16*)((s8*)arg0 + 0x7C) & 1)) {
        M2C_FIELD(arg0, s32*, 0x24) = -M2C_FIELD(arg0, s32*, 0x24);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
extern s16 D_800970AA;
extern u8 D_800CCF38;

void func_800EE468(void* arg0) {
    s32 cnt;
    void* obj;

    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    cnt = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    M2C_FIELD(arg0, u16*, 0x7C) = cnt;
    if (D_800CCF38 == 2) {
        if ((s16)cnt == 0x18 || (s16)cnt == 0x54) {
            play_sound(2, 6, arg0);
            obj = func_8002C458();
            if (obj != 0) {
                u8 kind = M2C_FIELD(arg0, u8*, 0x0);
                M2C_FIELD(obj, u8*, 0x1) = 1;
                M2C_FIELD(obj, u8*, 0x2) = 1;
                M2C_FIELD(obj, void**, 0x7C) = arg0;
                M2C_FIELD(obj, u8*, 0x0) = kind;
            }
        }
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0xDC) {
            M2C_FIELD(arg0, u8*, 0x5) = 5;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        }
    } else {
        if ((s16)cnt == 0x18) {
            play_sound(2, 6, arg0);
            obj = func_8002C458();
            if (obj != 0) {
                u8 kind = M2C_FIELD(arg0, u8*, 0x0);
                M2C_FIELD(obj, u8*, 0x1) = 1;
                M2C_FIELD(obj, u8*, 0x2) = 1;
                M2C_FIELD(obj, void**, 0x7C) = arg0;
                M2C_FIELD(obj, u8*, 0x0) = kind;
            }
        }
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0xA0) {
            M2C_FIELD(arg0, u8*, 0x5) = 5;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EE58C(void* arg0) {
    s16 v;
    s16 w;

    if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0xB4) {
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        set_animation(arg0, 4);
        play_sound(2, 4, arg0);
        M2C_FIELD(arg0, s32*, 0x28) = 0x10000;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) < g_Player.y_pos.i.hi) {
        M2C_FIELD(arg0, s16*, 0xE) = v = M2C_FIELD(arg0, s16*, 0xE) + 2;
        if (g_Player.y_pos.i.hi < v) {
            M2C_FIELD(arg0, s16*, 0xE) = g_Player.y_pos.i.hi;
        }
    } else if (g_Player.y_pos.i.hi < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, s16*, 0xE) = w = M2C_FIELD(arg0, s16*, 0xE) - 2;
        if (w < g_Player.y_pos.i.hi) {
            M2C_FIELD(arg0, s16*, 0xE) = g_Player.y_pos.i.hi;
        }
    }
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s8 D_8009711A;
extern s32 D_800FBC70;

void func_800EE6D0(void* arg0) {
    s8 state;

    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x41) {
        M2C_FIELD(arg0, u8*, 0x5C) -= 8;
        if ((s8)M2C_FIELD(arg0, u8*, 0x5C) <= 0) {
            M2C_FIELD(arg0, u8*, 4) = 2;
            M2C_FIELD(arg0, u8*, 0x5C) = 0;
            M2C_FIELD(arg0, u8*, 5) = 0;
            M2C_FIELD(arg0, u8*, 6) = 0;
            D_800FBC70 = 1;
            D_8009711A = 1;
            func_8002CCB0(arg0, 0xA0, 0xA0);
            return;
        }
    }
    state = M2C_FIELD(arg0, s8*, 7);
    if (state != 0) {
        if (state == 1) {
            s32 idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
            s32 base = SPAD20;
            // !FAKE: depin: dropping it breaks the match (46/73)
            register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);
            M2C_FIELD(arg0, s32*, 0x3C) = base + off;
            ((void (*)(void*, s32, s32))set_animation)(arg0, 9, off);
            M2C_FIELD(arg0, u8*, 7)++;
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            play_sound(2, 4, arg0);
            M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_800970A8;
extern s8 D_80097244;
extern u8 D_800FB218[];

void func_800EE7F4(void* arg0) {
    s32 base;
    s32 t;

    func_80027BA0(0, 0x17B0, 0xD0, D_800FB218);
    func_80027BA0(0, 0x1930, 0xD0, D_800FB218 + 0x10);
    D_80097244 = 1;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, u8*, 0x61) = 0x19;
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    t = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    base = SPAD20;
    t = *(s32*)(t * 4 + base);
    M2C_FIELD(arg0, s32*, 0x3C) = base + t;
    set_animation(arg0, 0);
    M2C_FIELD(arg0, s32*, 0x24) = -0x4000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    {
        // !FAKE: depin: dropping it breaks the match (59/68)
        register s32 c asm("$2") = M2C_FIELD(arg0, u8*, 5) + 1;
        M2C_FIELD(arg0, u8*, 5) = c;
    }
    {
        s32 g = D_800970A8;
        if (M2C_FIELD(arg0, s32*, 8) < g) {
            func_8003D308(0x14, 0);
        } else {
            func_8003D308(0x14, 0x40);
        }
    }
    func_8002CCB0(arg0, 0xA0, 0xA0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800EE904(void* arg0) {
    struct X4_BackgroundObj* bg;
    s32 lim;
    s32 lim2;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 4) >= 4) {
        M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1F) {
        ((void (*)(void*))move_object)(arg0);
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) == 0) {
        if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
            M2C_FIELD(arg0, s16*, 0x7E) = 5;
            M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        }
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    M2C_FIELD(arg0, s8*, 5)++;
    {
        s32 idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        s32 base = SPAD20;
        // !FAKE: depin: dropping it breaks the match (59/145)
        register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0xB, off);
    }
    bg = background_objects;
    if (bg->unk1E + 0xC8 < M2C_FIELD(arg0, s16*, 0xA)) {
        func_8003D308(0x14, 0x40);
        g_Player.x_pos.i.hi = M2C_FIELD(arg0, u16*, 0xA) - 0xA0;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        lim = g_Player.x_pos.i.hi - 0x30;
        if (lim < bg->unk26) {
            bg->unk24 = bg->unk26;
        } else if (bg->unk24 < lim) {
            bg->unk26 = bg->unk24;
        } else {
            bg->unk24 = bg->unk26 = g_Player.x_pos.i.hi - 0x30;
        }
        background_objects[0].unk4C = 1;
    } else {
        func_8003D308(0x14, 0);
        g_Player.x_pos.i.hi = M2C_FIELD(arg0, u16*, 0xA) + 0xA0;
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        lim2 = g_Player.x_pos.i.hi - 0x100;
        if (lim2 < bg->unk26) {
            bg->unk24 = bg->unk26;
        } else if (bg->unk24 < lim2) {
            bg->unk26 = bg->unk24;
        } else {
            bg->unk24 = bg->unk26 = g_Player.x_pos.i.hi - 0x100;
        }
        background_objects[0].unk4C = 1;
    }
    M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].y_pos.i.hi + 0xA0;
    g_playthrough_state.enable_boss = 0;
    g_playthrough_state.boss_ptr = 0;
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_800FAF14;
extern s32 D_80074B5C;

void func_800EEB48(void* arg0) {
    void* parent;
    void* p;
    struct X4_PlayerObj* pl;
    s32 b;

    parent = M2C_FIELD(arg0, void**, 0x80);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    pl = &g_Player;
    b = M2C_FIELD(pl, u8*, 0x14);
    {
        // !FAKE: depin: dropping it breaks the match (81/89)
        register s32 t asm("$2") = 3;
        M2C_FIELD(arg0, u8*, 0x16) = t;
    }
    M2C_FIELD(arg0, void**, 0x54) = &D_800FAF14;
    M2C_FIELD(arg0, void**, 0x58) = &D_80074B5C;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, u8*, 0x62) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u16*, 0xA) = 0x18E0;
    M2C_FIELD(arg0, u16*, 0xE) = 0x100;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    {
        s32 k = 0x18E0;
        if (k < pl->x_pos.i.hi) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x84) = 0;
    {
        s32 idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        s32 base = SPAD20;
        // !FAKE: depin: dropping it breaks the match (60/89)
        register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0xF, off);
    }
    play_sound(2, 9, arg0);
    p = func_8002C458();
    if (p != 0) {
        u8 o = M2C_FIELD(arg0, u8*, 0);
        M2C_FIELD(p, s8*, 1) = 1;
        M2C_FIELD(p, s8*, 2) = 5;
        M2C_FIELD(p, void**, 0x7C) = arg0;
        M2C_FIELD(p, u8*, 0) = o;
    }
    M2C_FIELD(arg0, u16*, 0x7E) = 0;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 4)++;
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 check_enemy_hits(void*);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_800FBC70;

#define SET_ANIM(obj, id)                                                      \
    {                                                                          \
        s32 idx = func_8002A47C(M2C_FIELD(obj, s8*, 1));                       \
        s32 base = SPAD20;                                                     \
        register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);              \
        M2C_FIELD(obj, s32*, 0x3C) = base + off;                               \
        ((void (*)(void*, s32, s32))set_animation)(obj, id, off);              \
    }

#define SPAWN(obj, kind)                                                       \
    {                                                                          \
        p = func_8002C458();                                                   \
        if (p != 0) {                                                          \
            u8 o = M2C_FIELD(obj, u8*, 0);                                     \
            M2C_FIELD(p, s8*, 1) = 1;                                          \
            M2C_FIELD(p, s8*, 2) = kind;                                       \
            M2C_FIELD(p, void**, 0x7C) = obj;                                  \
            M2C_FIELD(p, u8*, 0) = o;                                          \
        }                                                                      \
    }

void func_800EECAC(void* arg0) {
    void* parent;
    s32 timer;
    void* p;
    s32 r;

    if (D_800FBC70 != 0) {
        play_sound(2, 0x14, arg0);
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    parent = M2C_FIELD(arg0, void**, 0x80);
    if (M2C_FIELD(parent, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(parent, s16*, 0xA) - 0x3E;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(parent, s16*, 0xA) + 0x3E;
    }
    M2C_FIELD(arg0, s32*, 0x24) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s16*, 0xE) - 0x3C;
    if (M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(arg0, s32*, 0x20)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    timer = M2C_FIELD(arg0, u16*, 0x7E) + 1;
    M2C_FIELD(arg0, u16*, 0x7E) = timer;

    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        switch (M2C_FIELD(arg0, s8*, 6)) {
        case 0:
            if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                // !FAKE: depin: macro pin; drop breaks match (82/400)
                SET_ANIM(arg0, 0xC);
                play_sound(2, 7, arg0);
                M2C_FIELD(arg0, s16*, 0x7C) = 0;
                M2C_FIELD(arg0, s8*, 6)++;
            }
            break;
        case 1:
            if ((s16)((s16)timer % 6) == 0) {
                SPAWN(arg0, 0);
            }
            if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x64) {
                M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) = 1;
                M2C_FIELD(arg0, s8*, 6)++;
            }
            break;
        case 2:
            if ((s16)((s16)timer % 6) == 0) {
                SPAWN(arg0, 0);
            }
            if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 5) == 4) {
                M2C_FIELD(arg0, s8*, 6) = 0;
                M2C_FIELD(arg0, s8*, 5)++;
            }
            break;
        }
        goto tail;
    case 1:
        if ((s16)((s16)timer % 6) == 0) {
            SPAWN(arg0, 0);
        }
        switch (M2C_FIELD(arg0, s8*, 6)) {
        case 0:
            if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 5) == 8) {
                M2C_FIELD(arg0, s16*, 0x7C) = 0;
                M2C_FIELD(arg0, s8*, 6)++;
            }
            break;
        case 1:
            if (g_Player.unk2 == 0) {
                if (M2C_FIELD(arg0, s16*, 0x7C) == 0 ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 8 ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 0x10 ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 0x18) {
                    SPAWN(arg0, 2);
                    play_sound(2, 8, arg0);
                } else if (M2C_FIELD(arg0, s16*, 0x7C) == 0x7C) {
                    M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) = 1;
                    M2C_FIELD(arg0, s8*, 6)--;
                }
            } else {
                if (M2C_FIELD(arg0, s16*, 0x7C) == 0 ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 0x3C ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 0x78) {
                    SPAWN(arg0, 2);
                    play_sound(2, 8, arg0);
                } else if (M2C_FIELD(arg0, s16*, 0x7C) == 0xDC) {
                    M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) = 1;
                    M2C_FIELD(arg0, s8*, 6)--;
                }
            }
            M2C_FIELD(arg0, s16*, 0x7C)++;
            break;
        }
        M2C_FIELD(arg0, u8*, 0x5C) = 0x7F;
        r = check_enemy_hits(arg0);
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        if (g_Player.unk2 == 0) {
            if (!((r >= 0x13 && r < 0x17) || r == 0x33 || r == 0x34)) {
                goto tail;
            }
        } else if (r <= 0) {
            goto tail;
        }
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 5) = 0x63;
        // !FAKE: depin: macro pin; drop breaks match (82/400)
        SET_ANIM(arg0, 0x10);
        play_sound(2, 9, arg0);
        play_sound(2, 0x14, arg0);
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 5)++;
        goto tail;
    case 2:
        switch (M2C_FIELD(arg0, s8*, 6)) {
        case 0:
            if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                M2C_FIELD(arg0, s16*, 0x7C) = 0;
                M2C_FIELD(arg0, s8*, 6)++;
            }
        tail:
            func_80017A04(arg0);
            func_8002CCB0(arg0, 0x20, 0x20);
            return;
        case 1:
            if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x3C) {
                if (g_Player.x_pos.i.hi < 0x1878) {
                    M2C_FIELD(arg0, s16*, 0xA) = 0x18E0;
                } else {
                    M2C_FIELD(arg0, s16*, 0xA) = 0x1810;
                }
                M2C_FIELD(arg0, s16*, 0xE) = 0x100;
                if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
                    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                } else {
                    M2C_FIELD(arg0, u8*, 0x15) = 0;
                }
                // !FAKE: depin: macro pin; drop breaks match (82/400)
                SET_ANIM(arg0, 0xF);
                play_sound(2, 9, arg0);
                M2C_FIELD(arg0, s8*, 5) = 0;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
            return;
        default:
            return;
        }
        return;
    default:
        return;
    }
}
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800EF2EC);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern void* D_800FBC78;

void func_800EF3F8(void* arg0) {
    void* p;
    struct ObjectHeader* d;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    d = D_800FBC78;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, s32*, 0x3C) =
        SPAD20 + *(s32*)(func_8002A47C(d->id) * 4 + SPAD20 + 4);
    ((void (*)(void*, s32))set_animation)(arg0, 0x12);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, u16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA) - 0xA;
    } else {
        M2C_FIELD(arg0, u16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA) + 0xA;
    }
    M2C_FIELD(arg0, u16*, 0xE) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xE);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0xC);
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s32 D_800FBC70;
extern s32 D_800FBC74;

void func_800EF528(void* arg0) {
    s32 ang;
    s32 dx;
    s32 dy;
    s32 t;
    s32 dist;
    s32 spd;
    struct MainObj* p;

    if (D_800FBC70 != 0) {
        goto fail;
    }
    if (D_800FBC74 != 0) {
        goto fail;
    }
    {
        struct MainObj* q = M2C_FIELD(arg0, void**, 0x7C);
        M2C_FIELD(arg0, s32*, 0x20) += 8;
        ang =
            (s16)ratan2(q->y_speed - M2C_FIELD(arg0, s16*, 0x2E),
                        q->x_speed - M2C_FIELD(arg0, s16*, 0x2A));
        p = M2C_FIELD(arg0, void**, 0x7C);
        dx = M2C_FIELD(arg0, s16*, 0x2A) - p->x_speed;
        t = p->x_speed - M2C_FIELD(arg0, s16*, 0x2A);
        if (t >= 0) {
            dx = t;
        }
        {
            s32 u;
            dy = M2C_FIELD(arg0, s16*, 0x2E) - p->y_speed;
            u = p->y_speed - M2C_FIELD(arg0, s16*, 0x2E);
            if (u >= 0) {
                dy = u;
            }
        }
        dist = dx * dx + dy * dy;
        M2C_FIELD(arg0, s32*, 0x8) =
            M2C_FIELD(arg0, s32*, 0x28) +
            ((rcos(ang) * M2C_FIELD(arg0, s32*, 0x20)) << 4);
        M2C_FIELD(arg0, s32*, 0xC) =
            M2C_FIELD(arg0, s32*, 0x2C) +
            ((rsin(ang) * M2C_FIELD(arg0, s32*, 0x20)) << 4);
        spd = M2C_FIELD(arg0, s32*, 0x20);
        if ((u32)(spd * spd) < (u32)(dist - 0x40)) {
            goto ok;
        }
    }
fail:
    M2C_FIELD(arg0, u8*, 0x4) = 2;
    return;
ok:
    if (++M2C_FIELD(arg0, s8*, 0x6) == 0x64) {
        M2C_FIELD(arg0, u8*, 0x4) = 2;
    }
    func_8002CCB0(arg0, 0x10, 0x10);
    ((void (*)(void*))func_80017A04)(arg0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EF6B8 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;
extern s32 D_800FB28C;
extern void* D_800FBC78;

void func_800EF6B8(void* arg0) {
    void* p;
    s32 base;
    s32 idx;
    struct ObjectHeader* g;
    s32* f;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    f = &D_800FB28C;
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    g = D_800FBC78;
    M2C_FIELD(arg0, s32**, 0x68) = f;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    idx = func_8002A47C(g->id);
    base = SPAD20_800EF6B8;
    M2C_FIELD(arg0, s32*, 0x3C) = base + *(s32*)(idx * 4 + base + 4);
    set_animation(arg0, 0x13);
    {
        // !FAKE: depin: dropping it breaks the match (81/83)
        register s32 c asm("$2") = M2C_FIELD(arg0, u8*, 0x15);
        if (c == 0) {
            M2C_FIELD(arg0, s16*, 0xA) =
                M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA) - 0x38;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) =
                M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA) + 0x38;
        }
    }
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xE) - 0x18;
    M2C_FIELD(arg0, s32*, 0x20) = (D_800970AA - M2C_FIELD(arg0, s16*, 0xA))
                                  << 11;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x4000;
    M2C_FIELD(arg0, u8*, 0x60) = 6;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80030ECC(void*);
extern s32 D_800FB290;
extern s32 D_800FBC70;
extern s32 D_800FBC74;
extern void* D_800FBC78;

#define SET_ANIM2(obj, id, src)                                                \
    {                                                                          \
        s32 idx = func_8002A47C(M2C_FIELD(src, s8*, 1));                       \
        s32 base = SPAD20;                                                     \
        register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);              \
        M2C_FIELD(obj, s32*, 0x3C) = base + off;                               \
        ((void (*)(void*, s32, s32))set_animation)(obj, id, off);              \
    }

#define SET_ANIM(obj, id) SET_ANIM2(obj, id, D_800FBC78)

void func_800EF804(void* arg0) {
    void* p;
    void* q;

    if (D_800FBC70 != 0 || D_800FBC74 != 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            play_sound(2, 0, arg0);
            func_80012D9C(5);
            {
                s32 t = M2C_FIELD(arg0, u16*, 0xE);
                q = D_800FBC78;
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s32*, 0x2C) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = t - 0x4E;
            }
            // !FAKE: depin: macro pin; drop breaks match (59/150)
            SET_ANIM2(arg0, 0x14, q);
            p = func_8002C458();
            if (p != 0) {
                u8 o = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(p, s8*, 1) = 1;
                M2C_FIELD(p, s8*, 2) = 3;
                M2C_FIELD(p, void**, 0x7C) = arg0;
                M2C_FIELD(p, u8*, 0) = o;
            }
            M2C_FIELD(arg0, s8*, 5)++;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            // !FAKE: depin: macro pin; drop breaks match (59/150)
            SET_ANIM(arg0, 0x15);
            M2C_FIELD(arg0, void**, 0x50) = &D_800FB290;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s8*, 5)++;
        }
        break;
    case 2:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x32) {
            // !FAKE: depin: macro pin; drop breaks match (59/150)
            SET_ANIM(arg0, 0x16);
            M2C_FIELD(arg0, void**, 0x50) = 0;
            M2C_FIELD(arg0, s8*, 5)++;
        }
        break;
    case 3:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            M2C_FIELD(arg0, s8*, 4) = 2;
        }
        break;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_8007429C;
extern M2C_UNK g_Player;
extern s32 D_800FB294;
extern s32 D_800FB298;
extern s32 D_800FB29C;
extern void* D_800FBC78;

void func_800EFA5C(void* arg0) {
    void* p;
    s32 ang;
    s32 t;
    // !FAKE: depin: dropping it breaks the match (13/104)
    register u8 dir asm("$6");

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t = M2C_FIELD(p, u16*, 0x42);
    M2C_FIELD(arg0, u8*, 0x16) = 2;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u16*, 0x42) = t & 0x7FFF;
    dir = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(arg0, void**, 0x68) = &D_800FB294;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FB298;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FB29C;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = dir;
    {
        void* a58 = &D_8007429C;
        struct ObjectHeader* q = D_800FBC78;
        s32 idx;
        s32 base;
        // !FAKE: depin: dropping it breaks the match (47/104)
        register s32 off asm("$6");
        M2C_FIELD(arg0, void**, 0x58) = a58;
        idx = func_8002A47C(q->id);
        base = SPAD20;
        off = *(s32*)(idx * 4 + base + 4);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0xE, off);
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s16*, 0xA) - 0xA;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s16*, 0xA) + 0xA;
    }
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s16*, 0xE);
    {
        u8* g = (u8*)&g_Player;
        ang = (s16)ratan2(M2C_FIELD(g, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                          M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 5;
    M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) << 5;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern void* D_800FBC78;

void func_800EFBFC(void* arg0) {
    void* p;
    struct ObjectHeader* d;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 3;
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    d = D_800FBC78;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, s32*, 0x3C) =
        SPAD20 + *(s32*)(func_8002A47C(d->id) * 4 + SPAD20 + 4);
    ((void (*)(void*, s32))set_animation)(arg0, 0x17);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, u16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA);
    } else {
        M2C_FIELD(arg0, u16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA);
    }
    M2C_FIELD(arg0, u16*, 0xE) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xE) + 0x5C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern void* D_800FBC78;

void func_800EFD00(void* arg0) {
    void* p;
    struct ObjectHeader* d;
    s32 r;
    s32 t;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    d = D_800FBC78;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    r = ((s32(*)())func_8002A47C)(d->id, p);
    t = SPAD20;
    {
        // !FAKE: table word lands in the second argument register as retail does
        register s32 x asm("$5") = *(s32*)(r * 4 + t + 4);
        M2C_FIELD(arg0, s32*, 0x3C) = t + x;
    }
    ((void (*)(void*, s32))set_animation)(arg0, 0xA);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern void* D_800FBC78;

void func_800EFDDC(void* arg0) {
    void* p;
    struct ObjectHeader* d;
    void* q;
    s32 e;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 2;
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    d = D_800FBC78;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, s32*, 0x3C) =
        SPAD20 + *(s32*)(func_8002A47C(d->id) * 4 + SPAD20 + 4);
    ((void (*)(void*, s32))set_animation)(arg0, 0x11);
    q = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(q, u16*, 0xA);
    e = M2C_FIELD(q, u16*, 0xE);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    M2C_FIELD(arg0, u16*, 0xE) = e;
}
