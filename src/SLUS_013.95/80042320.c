#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230();

void func_80042320(void* arg0) {
    s8 v;
    // !FAKE: pins the 0xE value to the first return register as retail allocates it
    register s32 e asm("$2");

    func_8002D230(arg0);
    e = *(s16*)((u8*)arg0 + 0xE);
    if (*(s16*)((u8*)arg0 + 0x86) <= e) {
        *(s16*)((u8*)arg0 + 0xE) = *(s16*)((u8*)arg0 + 0x86);
        v = *(s8*)((u8*)arg0 + 0x2);
        if (v == 0x31) {
            // !FAKE: keeps the two equality tests from folding into a range test
            goto set_b4;
        }
        if (v == 0x32) {
        set_b4:
            *(s16*)((u8*)arg0 + 0x7C) = 0xB4;
            *(u8*)((u8*)arg0 + 0x6) = 3;
        } else {
            *(s16*)((u8*)arg0 + 0x7C) = 0x3C;
            *(u8*)((u8*)arg0 + 0x6) = *(u8*)((u8*)arg0 + 0x6) + 1;
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
#include "mmx6/state.h"

void func_800423A0(void* arg0) {
    s16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16*, 0x86) +
              (rsin((D_80097420.frame_counter & 0x7F) << 5) >> 9);
    M2C_FIELD(arg0, s16*, 0xE) = temp_v1;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        set_animation(arg0, 7);
        {
            // !FAKE: constants live in the first return register as retail
            register s32 c asm("$2") = 4;
            M2C_FIELD(arg0, s16*, 0x8A) = c;
            c = 0xB4;
            M2C_FIELD(arg0, u16*, 0x7C) = c;
        }
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80042A9C(struct X4_MainObj* self, s32 arg1);
void func_80042C18(struct X4_MainObj* self);

void func_80042420(struct X4_MainObj* self) {
    s16 y;

    y = M2C_FIELD(self, u16*, 0x86) +
        (rsin((D_80097420.frame_counter & 0x7F) << 5) >> 9);
    self->y_pos.i.hi = y;
    if (--self->unk7C == 0) {
        if ((self->unk2 & 0xF0) == 0x30) {
            self->unk7C = 0x1E;
            self->unk6 = 6;
            return;
        }
        M2C_FIELD(self, u8*, 0x8E) = 0;
        self->attack_box = 0;
        self->hurt_box = 0;
        self->on_screen = 0;
        func_80042C18(self);
        self->unk7 = 0;
        func_80042A9C(self, 0);
        func_80042A9C(self, 1);
        self->unk6++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_80042C18(struct X4_MainObj* self);

#define F24E0_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F24E0_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F24E0_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800424E0(void* arg0) {
    F24E0_U8(arg0, 3) = 0;
    if (F24E0_S8(arg0, 7) == 0) {
        func_80042C18(arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        F24E0_S16(arg0, 0x7C) = 0x1E;
        F24E0_U8(arg0, 6) = F24E0_U8(arg0, 6) + 1;
    }
}

#undef F24E0_S8
#undef F24E0_U8
#undef F24E0_S16

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800429D4();
extern s32 D_80075EDC;
extern s32 D_80075EE4;
extern u8 D_800CCF38;

void func_80042538(void* self) {
    if (M2C_FIELD(self, u16*, 0x7C) & 1) {
        M2C_FIELD(self, u8*, 0x3) = 0;
    } else {
        M2C_FIELD(self, u8*, 0x3) = 1;
    }
    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        M2C_FIELD(self, u8*, 0x8F) = 0;
        M2C_FIELD(self, u8*, 0x2) = (M2C_FIELD(self, u8*, 0x2) & 0xF0) + 2;
        ((void (*)(void*))func_800429D4)(self);
        M2C_FIELD(self, u8*, 0x60) = 4;
        M2C_FIELD(self, u8*, 0x5C) = 10;
        switch (D_800CCF38) {
        case 0:
            M2C_FIELD(self, u8*, 0x5C) = 2;
            break;
        case 1:
            break;
        case 2:
        default:
            M2C_FIELD(self, u8*, 0x5C) += 8;
            break;
        }
        M2C_FIELD(self, void**, 0x50) = &D_80075EDC;
        M2C_FIELD(self, void**, 0x54) = &D_80075EE4;
        M2C_FIELD(self, s32*, 0x68) = 0;
    }
}

#include "common.h"

void func_8004260C(u8* arg0) {
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[3] = 0;
    } else {
        arg0[3] = 1;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[3] = 0;
        arg0[4] = 2;
    }
}

#define func_8003744C func_80042658
#define D_80073C1C D_80076094
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_80041F6C func_80042694
#include "../shared/animation/func_80041F6C.c"
#undef func_80041F6C

#define func_80041FB0 func_800426D8
#include "../shared/SLUS_013.95/func_80041FB0.c"
#undef func_80041FB0

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800429D4();
void func_80042D98(s8* arg0);

void func_8004270C(void* arg0) {
    s8 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_s1 == 1) {
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        func_80042D98(arg0);
        if (M2C_FIELD(arg0, s32*, 0x80) == 0) {
            M2C_FIELD(arg0, u8*, 0x8F) = 0;
            func_800429D4(arg0);
            return;
        }
        M2C_FIELD(arg0, u8*, 0x8D) = temp_s1;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2);
void func_80042A9C(struct X4_MainObj* self, s32 arg1);

void func_80042780(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1 == 1) {
        M2C_FIELD(arg0, u8*, 0x7) = temp_v1;
        play_sound(2, 0x3F, arg0);
        func_80042A9C(arg0, 0x10);
        M2C_FIELD(arg0, u16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}

#include "common.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);

void func_800427E0(s8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        play_sound(2, 0x40, arg0);
        *(u16*)(arg0 + 0x7C) = 0x5A;
        arg0[6]++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004283C(void* arg0) {
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    } else {
        M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 2;
    }
}

#define func_8003744C func_8004289C
#define D_80073C1C D_800760B4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;
extern s16 D_80097206;

void func_800428D8(void* arg0) {
    u16 y = D_80097206;
    u16 x;
    // !FAKE: pin the field-6 byte to the first return register (regalloc swap)
    register s32 b asm("$2");

    M2C_FIELD(arg0, u8*, 0x3) = 1;
    M2C_FIELD(arg0, s16*, 0xE) = y - 0x20;
    x = D_800970AA;
    {
        // !FAKE: pin the 0x7E constant to the first return register (regalloc swap)
        register s32 k asm("$2") = 0x5A;
        M2C_FIELD(arg0, s16*, 0x7E) = k;
    }
    b = M2C_FIELD(arg0, u8*, 0x6);
    M2C_FIELD(arg0, s16*, 0x7C) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, u8*, 0x7) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = b + 1;
    M2C_FIELD(arg0, s16*, 0xA) = x;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
M2C_UNK func_8002D230();
s32 play_sound(s32, s32, void*);

void func_8004292C(struct X4_BaseObj* self) {
    struct X4_EngineObj* e;
    u16* p;

    ((void (*)(void*))func_8002D230)(self);
    if (self->y_pos.i.hi >= g_Player.y_pos.i.hi) {
        u8* b;
        s32 i;
        e = &g_playthrough_state;
        i = g_Player.unk2 * 2;
        b = (u8*)e + 0xD2;
        p = (u16*)(i + b);
        *p += *(u16*)((u8*)self + 0x8A);
        play_sound(0, 0x29, self);
        e->unkF = 0x10;
        self->on_screen = 0;
        self->unk6++;
    }
}

void func_800429C4(void) {
}

void func_800429CC(void) {
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void func_80042D98(s8* arg0);
extern u8 D_80075EBC[][8];

M2C_UNK func_800429D4(s8* arg0) {
    arg0[6] = 0;
    if ((arg0[2] & 0xF0) == 0x20) {
        func_80042D98(arg0);
        if (*(s32*)(arg0 + 0x80) != 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            arg0[5] = 6;
            arg0[6] = 3;
            return;
        }
    }
    if (D_80075EBC[(u8)arg0[2] & 0xF][(u8)arg0[0x8F]] == 8) {
        arg0[0x8F] = 0;
    }
    arg0[5] = D_80075EBC[(u8)arg0[2] & 0xF][(u8)arg0[0x8F]];
    arg0[0x8F]++;
}

#include "common.h"
#include "mmx6/x4.h"

void* alloc_sprite_slot(); /* extern */

void func_80042A9C(struct X4_MainObj* self, s32 arg1) {
    u8 kind;
    struct X4_MainObj* obj;

    kind = arg1;
    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0xB;
        obj->unk2 = kind;
        obj->unk15 = self->unk15;
        obj->unk40 = self->unk40;
        obj->unk42 = self->unk42 & 0x7FFF;
        obj->animation_table = self->animation_table;
        obj->sprite_frames = self->sprite_frames;
        obj->bg_offset = self->bg_offset;
        obj->x_pos.u.hi = self->x_pos.u.hi;
        obj->x_pos.u.lo = 0;
        obj->y_pos.u.hi = self->y_pos.u.hi;
        obj->y_pos.u.lo = 0;
        obj->attack_box = self;
        if (!(kind & 0xF0)) {
            self->unk7++;
        }
    }
}

#include "common.h"

void* func_8002C458();

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_80042B68(void* arg0, u8 arg1) {
    u8* obj;
    u8 t;

    obj = func_8002C458();
    if (obj != 0) {
        B(obj, 0) = 0x41;
        B(obj, 1) = 0xC;
        t = B(arg0, 0x15);
        *(void**)(obj + 0x7C) = arg0;
        B(obj, 2) = arg1;
        B(obj, 0x15) = t;
        H(obj, 0xA) = H(arg0, 0xA);
        H(obj, 8) = 0;
        H(obj, 0xE) = H(arg0, 0xE);
        H(obj, 0xC) = 0;
        H(obj, 0x42) = H(arg0, 0x42) & 0x7FFF;
        W(obj, 0x30) = W(arg0, 0x30);
        W(obj, 0x3C) = W(arg0, 0x3C);
        H(obj, 0x40) = H(arg0, 0x40);
        B(obj, 0x14) = B(arg0, 0x14);
    }
}

#include "../shared/commander_yammark/func_80042C18.c"

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_StageObjectRecord* D_8007349C[][2];
extern struct X4_EngineObj g_playthrough_state;

s32 func_80042C48(struct X4_BaseObj* self) {
    struct X4_StageObjectRecord* rec;
    u16 i;

    rec = D_8007349C[g_playthrough_state.stage][g_playthrough_state.substage];
    i = 0;
    while (rec->object_type != 0xF) {
        if (rec->id == 0xF) {
            if (self->backref == rec) {
                return i;
            }
            i++;
            if (i >= 0x100) {
                return 0;
            }
        }
        rec++;
    }
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80075FE8[];
extern struct X4_EngineObj g_playthrough_state;

s32 func_80042CE8(void* arg0) {
    u16 id;
    u8* p;

    id = *(u16*)((s8*)arg0 + 0x88);
    p = (id >> 3) +
        (D_80075FE8[g_playthrough_state.substage +
                    g_playthrough_state.stage * 2]
         << 5) +
        ((u8*)&g_playthrough_state + 0x178);
    return ((*p >> (id & 7)) & 1) ^ 1;
}
