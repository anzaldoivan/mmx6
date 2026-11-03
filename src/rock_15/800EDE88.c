#define func_80041AB8 func_800EDE88
#define D_80075FD8 D_800F66A0
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800EDEC4(s8* arg0) {
    u8 temp;

    play_sound(2, 0x20, arg0);
    temp = g_Player.facing;
    *(u8*)((s32)&g_Player + 0xCA) = 0;
    func_8003D308(0x14, temp);
    set_animation(arg0, 6);
    arg0[5] = 1;
    *(s16*)(arg0 + 0x7C) = 0x7F;
    *(s16*)(arg0 + 0x7E) = 0x19;
    arg0[0x61] = 0x19;
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    func_8002CCB0(arg0, 0x60, 0x60);
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EDF50);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_15.h"

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CF0C(void*);
extern struct X4_EngineObj g_playthrough_state;

void func_800EE044(void* arg0) {
    F8(arg0, 3) = 0;
    if (S8(D_800F70E0, 0) != 0) {
        if (S8(D_800F70E0, 7) == 0) {
            if (--S16(arg0, 0x7E) == -1) {
                F16(arg0, 0x7E) = 5;
                F16(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        F32(arg0, 0x80) = 0;
        F32(arg0, 0x84) = 0;
        F32(arg0, 0x88) = 0;
        F32(arg0, 0x8C) = 0;
        F32(arg0, 0x90) = 0;
        F32(arg0, 0x94) = 0;
        g_playthrough_state.enable_boss = 0;
        F32(&g_playthrough_state, 0x20) = 0;
        func_8002CF0C(arg0);
        F8(arg0, 0) = 0x41;
        F8(arg0, 1) = 0x3E;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EE11C(void* arg0) {
    ((void (*)())set_animation)(arg0, 0xA);
    ((u8*)arg0)[3] = 1;
    ((u8*)arg0)[5] = ((u8*)arg0)[5] + 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EF164();

void func_800EE158(void* arg0) {
    if (((s8*)arg0)[0x45] == 1) {
        ((void (*)(void*, s32))set_animation)(arg0, 0xC);
        func_800EF164(arg0, 0x10);
        ((u8*)arg0)[5] = ((u8*)arg0)[5] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F637C;
extern M2C_UNK D_800F6380;

void func_800EE1AC(void* arg0) {
    switch (M2C_FIELD(arg0, s8*, 0x45)) {
    case 1:
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F637C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6380;
        return;
    case 2:
        ((void (*)(void*, s32))set_animation)(arg0, 0xD);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 5) += 1;
        return;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF2E8(struct X4_MainObj* self);

void func_800EE230(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_800EF2E8(arg0);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007591C;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0x2000;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EF318();
extern M2C_UNK D_8007433C;

void func_800EE298(void* arg0) {
    s32 v;

    if (M2C_FIELD(arg0, s8*, 0x88) == 1) {
        v = (s32)&D_8007433C;
        M2C_FIELD(arg0, s32*, 0x58) = v;
        M2C_FIELD(arg0, s16*, 0x84) = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0x86) = M2C_FIELD(arg0, s16*, 0xE);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x50000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFB0000;
        }
        v = M2C_FIELD(arg0, u8*, 5);
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 5) = v + 1;
    } else {
        func_800EF318(arg0);
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EF318();

void func_800EE30C(void* arg0) {
    ((void (*)())func_800EF318)();
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        if (M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(arg0, s16*, 0x84) + 0x40) {
            return;
        }
    } else if (M2C_FIELD(arg0, s16*, 0xA) >
               M2C_FIELD(arg0, s16*, 0x84) - 0x40) {
        return;
    }
    M2C_FIELD(arg0, void**, 0x58) = &D_8007591C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0x2000;
    M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) - 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
extern u16 D_800F70DC;

void func_800EE398(void* arg0) {
    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x10) {
        D_800F70DC -= 1;
    }
    clear_object_slot();
}

#define func_8003744C func_800EE3DC
#define D_80073C1C D_800F66AC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE418(struct X4_MainObj* self) {
    play_sound(2, 0x22, self);
    set_animation(self, 1);
    func_800EF2E8(self);
    if (self->unk15 != 0) {
        self->x_speed = 0x4000;
    } else {
        self->x_speed = -0x4000;
    }
    {
        // !FAKE: keeps the counter read ahead of the constant stores
        register s32 t asm("$3") = (u8)self->action_phase + 1;

        self->unk7C = 0x32;
        self->y_speed = 0;
        self->unk7E = 2;
        self->action_phase = t;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object(s32);

#define F(o) (*((u8*)arg0 + (o)))
void func_800EE494(void* arg0) {
    if (*(s8*)((u8*)arg0 + 0x45) == 1) {
        F(6) = F(6) + 1;
        return;
    }
    if ((F(0x15) == 0) && (F(0x70) & 2)) {
        F(0x15) = 0x40;
        *(s32*)((u8*)arg0 + 0x20) = 0x4000;
    } else if ((F(0x15) == 0x40) && (F(0x70) & 1)) {
        F(0x15) = 0;
        *(s32*)((u8*)arg0 + 0x20) = -0x4000;
    }
    move_object(arg0);
}
#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_800ED484(void*);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE538(struct X4_MainObj* self) {
    if (--self->unk7C == -1) {
        // !FAKE: keeps the second call's constant argument in the branch delay slot
        register s32 k asm("$5") = 0x22;
        self->unk7C = 0x32;
        if (--self->unk7E == 0) {
            ((void (*)())func_800ED484)();
            return;
        }
        play_sound(2, k, self);
        set_animation(self, 1);
        func_800EF2E8(self);
        if (self->unk15 != 0) {
            self->x_speed = 0x4000;
        } else {
            self->x_speed = -0x4000;
        }
        self->action_phase--;
    }
}

#define func_8003744C func_800EE5EC
#define D_80073C1C D_800F66B8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EF2E8(struct X4_MainObj* self);
extern u16 D_800F70DC;
#define D_800F70DC (*(s16*)&D_800F70DC)

void func_800EE628(void* arg0) {
    if (D_800CCF38 >= 2) {
        if (D_800F70DC < 2) {
            // !FAKE: both range tests share the call block, as retail does
            goto call;
        }
    } else if (D_800F70DC <= 0) {
        // !FAKE: both range tests share the call block, as retail does
        goto call;
    }
    M2C_FIELD(arg0, u8*, 5) = 6;
    M2C_FIELD(arg0, u8*, 6) = 0;
    return;
call:
    set_animation(arg0, 4);
    func_800EF2E8(arg0);
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
#undef D_800F70DC

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
s32 func_800ED484(void*);                    /* extern */
void func_800EF22C(u8* arg0, u8 arg1);       /* extern */

void func_800EE6BC(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    switch (temp_v1) { /* irregular */
    case 1:
        play_sound(2, 0x23, arg0);
        play_sound(2, 0x86, arg0);
        func_800EF22C(arg0, 0x10);
        return;
    case 2:
        func_800ED484(arg0);
        return;
    }
}

#define func_8003744C func_800EE738
#define D_80073C1C D_800F66C0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE774(struct X4_MainObj* self) {
    u32 r;

    set_animation(self, 2);
    func_800EF2E8(self);
    r = random_byte();
    self->action_phase++;
    self->unk7C = (u8)(r % 3) + 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_800ED484(void*);
void func_800EF0B0(void* arg0, s32 arg1);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE7E4(struct X4_MainObj* self) {
    switch (self->animation_step.fields.event) {
    case 1:
        play_sound(2, 0x85, self);
        func_800EF0B0(self, 0);
        break;
    case 2:
        if (--self->unk7C == 0) {
            func_800ED484(self);
            break;
        }
        func_800EF2E8(self);
        set_animation(self, 2);
        break;
    }
}

#define func_8003744C func_800EE888
#define D_80073C1C D_800F66C8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE8C4(void* arg0) {
    u32 v;

    func_800EF2E8(arg0);
    set_animation(arg0, 3);
    v = random_byte();
    M2C_FIELD(arg0, u8*, 6) += 1;
    M2C_FIELD(arg0, s16*, 0x7C) = (u8)(v % 3) + 3;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_800ED484(void*);
void func_800EF0B0(void* arg0, s32 arg1);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE934(struct X4_MainObj* self) {
    switch (self->animation_step.fields.event) {
    case 1:
        func_800EF0B0(self, 0x10);
        break;
    case 2:
        if (--self->unk7C == 0) {
            func_800ED484(self);
            break;
        }
        func_800EF2E8(self);
        set_animation(self, 3);
        break;
    }
}

#define func_8003744C func_800EE9C8
#define D_80073C1C D_800F66D0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800EEA04(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_15.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();               /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800EEA3C(void* arg0) {
    s8 temp_s1;
    void* temp_v0;

    if (D_800CCEDF == 0) {
        temp_s1 = D_800970A5;
        if (temp_s1 == 0x14) {
            func_8003D308(0x1D, 0x40);
            temp_v0 = alloc_class3_slot();
            if (temp_v0 != NULL) {
                M2C_FIELD(temp_v0, s8*, 0) = 1;
                M2C_FIELD(temp_v0, s8*, 1) = 0x18;
                D_800F70E0 = temp_v0;
            }
            M2C_FIELD(arg0, s16*, 0x7C) = (s16)temp_s1;
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EEAC4(struct X4_MainObj* self) {
    if (self->unk7 == 0) {
        set_animation(self, 5);
        {
            // !FAKE: constant 1 in the first return register keeps the counter load after the flag store
            register s32 one asm("$2") = 1;
            self->on_screen = one;
        }
        self->x_accel = 0;
        self->x_speed = 0;
        self->gravity = 0x3000;
        self->action_phase++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800EEB20(void* self) {
    if (M2C_FIELD(self, u8*, 0x70) & 8) {
        ((void (*)(M2C_UNK, M2C_UNK, void*))play_sound)(2, 0x81, self);
        set_animation(self, 7);
        ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))func_8002943C)(0x1E, 5, 2);
        M2C_FIELD(self, s16*, 0x7C) = 0xB4;
        M2C_FIELD(self, s8*, 6)++;
    } else {
        apply_object_motion(self);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EEB9C(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = t;
    if ((t << 0x10) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 8);
        arg0[6] = arg0[6] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800EEBF0(void* arg0) {
    s8 t = S8(arg0, 0x45);

    if (t == 1) {
        set_animation(arg0, 0);
        {
            struct X4_EngineObj* p = &g_playthrough_state;
            open_text_box(0, 0xFF, F8(p, 0x2E));
            F8(p, 0x2E) = t;
        }
        F8(arg0, 6) += 1;
    }
}

#define func_800F4BA8 func_800EEC64
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800EECA8(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4D48 func_800EECE4
#include "../shared/rock_04/func_800F4D48.c"
#undef func_800F4D48

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();  /* extern */
s32 func_800ED484(void*); /* extern */

void func_800EED68(s32 arg0) {
    func_8003D330();
    func_800ED484(arg0);
}

#define func_8003744C func_800EED94
#define D_80073C1C D_800F66FC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK apply_object_motion(void*);
void func_800EF0B0(void*, s32);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EEDD0(struct X4_MainObj* self) {
    s32 n;
    s32 d;
    s32 e;

    play_sound(2, 0x21, self);
    func_800EF2E8(self);
    set_animation(self, 6);
    func_800EF0B0(self, 0x20);
    func_800EF0B0(self, 0x21);
    func_800EF0B0(self, 0x22);
    n = 0x300000;
    d = 0x70;
    e = 0xF;
    self->gravity = n / d;
    self->y_speed = 0x66DAA;
    self->x_accel = 0;
    if (self->unk15 == 0) {
        self->x_speed = 0x400000 / e;
    } else {
        self->x_speed = -0x400000 / e;
    }
    ((void (*)(void*))apply_object_motion)(self);
    self->action_phase++;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK apply_object_motion(void*);

void func_800EEEAC(u8* arg0) {
    s16 a;
    s16 b;
    s32 d;

    if (arg0[0x15] == 0 && (arg0[0x70] & 1)) {
        arg0[6] += 2;
        return;
    }
    if (arg0[0x15] == 0x40 && (arg0[0x70] & 2)) {
        arg0[6] += 2;
        return;
    }
    a = *(s16*)(arg0 + 0xA);
    b = *(s16*)(arg0 + 0x84);
    d = a - b;
    if (d >= 0) {
        if (d >= 0x30) {
            // !FAKE: keeps the near arm's far test a branch to the shared store block
            goto set;
        }
        // !FAKE: near arm jumps to the call; a fallthrough cross-jumps the slti tests
        goto call;
    }
    if ((b - a) >= 0x30) {
    set:
        *(s32*)(arg0 + 0x28) = 0x2000;
        arg0[6] += 1;
        return;
    }
call:
    apply_object_motion(arg0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK apply_object_motion(void*);

void func_800EEF78(void* arg0) {
    s32 v;

    if (((*((u8*)arg0 + 0x15) == 0) && (*((u8*)arg0 + 0x70) & 1)) ||
        ((*((volatile u8*)arg0 + 0x15) == 0x40) && (*((u8*)arg0 + 0x70) & 2))) {
        *((u8*)arg0 + 6) += 1;
    } else {
        v = *(s32*)((u8*)arg0 + 0x20);
        if (v < 0) {
            v = -v;
        }
        if (v < 0x3000) {
            *((u8*)arg0 + 6) += 1;
        } else {
            ((void (*)(void*))apply_object_motion)(arg0);
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EF014(u8* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 8);
    arg0[6] += 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ED484(void*); /* extern */

void func_800EF048(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s16*, 0x86) = 0x28;
        func_800ED484(arg0);
    }
}

#include "common.h"

void func_800EF078(void) {
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800F636C;
extern M2C_UNK D_800F6370;

void func_800EF080(void* arg0) {
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F636C;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F6370;
    if (M2C_FIELD(arg0, u8*, 0x8C) != 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = NULL;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = NULL;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();

void func_800EF0B0(void* arg0, s32 arg1) {
    u8 b;
    s8* o;

    b = arg1;
    o = func_8002C458();
    if (o != 0) {
        M2C_FIELD(o, s8*, 0x0) = 0x41;
        M2C_FIELD(o, s8*, 0x1) = 0x1F;
        M2C_FIELD(o, u8*, 0x2) = b;
        M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(o, u16*, 0x8) = 0;
        M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(o, u16*, 0xC) = 0;
        M2C_FIELD(o, void**, 0x7C) = arg0;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* find_free_visual_obj(void);

void func_800EF164(void* arg0, s32 arg1) {
    u8 sub;
    void* c;

    sub = arg1;
    c = find_free_visual_obj();
    if (c != 0) {
        M2C_FIELD(c, u8*, 0x0) = 0x41;
        M2C_FIELD(c, u8*, 0x1) = 0x10;
        M2C_FIELD(c, u8*, 0x2) = sub;
        M2C_FIELD(c, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(c, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(c, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(c, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(c, u16*, 0x8) = 0;
        M2C_FIELD(c, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(c, u16*, 0xC) = 0;
        M2C_FIELD(c, void**, 0x50) = arg0;
        M2C_FIELD(c, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(c, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(c, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        if (!(sub & 0xF0)) {
            M2C_FIELD(arg0, u8*, 0x7)++;
        }
    }
}

#include "common.h"

void* enemy_slot_alloc();
extern u16 D_800F70DC;

void func_800EF22C(u8* arg0, u8 arg1) {
    u8* temp_v0;

    temp_v0 = enemy_slot_alloc();
    if (temp_v0 != 0) {
        temp_v0[0] = 0x41;
        temp_v0[1] = 0x3D;
        temp_v0[0x15] = arg0[0x15];
        temp_v0[2] = arg1;
        *(u16*)(temp_v0 + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(temp_v0 + 8) = 0;
        *(u16*)(temp_v0 + 0xE) = *(u16*)(arg0 + 0xE);
        *(u16*)(temp_v0 + 0xC) = 0;
        *(u16*)(temp_v0 + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(temp_v0 + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(temp_v0 + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(temp_v0 + 0x40) = *(u16*)(arg0 + 0x40);
        temp_v0[0x14] = arg0[0x14];
        {
            s32 c = D_800F70DC;
            *(u8**)(temp_v0 + 0x80) = arg0;
            D_800F70DC = c + 1;
        }
    }
}

#define func_80042C18 func_800EF2E8
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EF318(void* self) {
    s32 v;

    M2C_FIELD(self, s32*, 8) += M2C_FIELD(self, s32*, 0x20);
    if (M2C_FIELD(self, u8*, 0x15) != 0) {
        M2C_FIELD(self, s32*, 0x20) += M2C_FIELD(self, s32*, 0x28);
    } else {
        M2C_FIELD(self, s32*, 0x20) -= M2C_FIELD(self, s32*, 0x28);
    }
    v = M2C_FIELD(self, s32*, 0x20);
    if ((v < 0 ? -v : v) > 0x60000) {
        if (M2C_FIELD(self, u8*, 0x15) != 0) {
            M2C_FIELD(self, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(self, s32*, 0x20) = -0x60000;
        }
        M2C_FIELD(self, s32*, 0x28) = 0;
    }
}

#define func_800F7E38 func_800EF394
#define D_800FD2F0 D_800F674C
#include "../shared/rock_11/func_800F7E38.c"
#undef func_800F7E38
#undef D_800FD2F0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800EF404(void* arg0) {
    void* temp_v1;

    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x20) {
        temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
        M2C_FIELD(temp_v1, u8*, 7) = (u8)(M2C_FIELD(temp_v1, u8*, 7) - 1);
    }
    clear_object_slot();
}

#define func_8003744C func_800EF450
#define D_80073C1C D_800F6768
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj g_Player;
extern s32 D_800F672C;
extern s32 D_800F6730;

void func_800EF48C(void* arg0) {
    s32 angle;

    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) -= 0x22;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) += 0x22;
    }
    M2C_FIELD(arg0, s32**, 0x50) = &D_800F672C;
    M2C_FIELD(arg0, s32**, 0x68) = &D_800F6730;
    M2C_FIELD(arg0, s16*, 0xE) -= 0xF;
    angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - g_Player.y_pos.i.hi,
                   g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) << 8;
    M2C_FIELD(arg0, s32*, 0x24) = rsin(angle) << 8;
    M2C_FIELD(arg0, u8*, 0x6)++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32); /* extern */
M2C_UNK func_80049D90();  /* extern */

void func_800EF564(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
        func_80049D90();
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    move_object(arg0);
}

#define func_8003744C func_800EF5B4
#define D_80073C1C D_800F6770
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern s16 D_80097222;

void func_800EF5F0(void* arg0) {
    u8 r;

    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x26;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x26;
    }
    r = (u32)random_byte() % 3;
    switch (r) {
    case 0:
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x50;
        break;
    case 1:
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x70;
        break;
    case 2:
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x80;
        break;
    }
    M2C_FIELD(arg0, u8*, 0x6)++;
}

#include "common.h"
#define M2C_UNK s32

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

void func_800EF6D8(void* arg0) {
    if (--FX(arg0, s16, 0x88) == 0) {
        play_sound(2, 0x88, arg0);
        if (FX(arg0, u8, 0x15) == 0) {
            FX(arg0, s32, 0x20) = 0xFFFA0000;
        } else {
            FX(arg0, s32, 0x20) = 0x60000;
        }
        FX(arg0, s32, 0x24) = 0;
        FX(arg0, u8, 0x6)++;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EF748(void) {
    ((M2C_UNK(*)())move_object)();
}

#define func_8003744C func_800EF768
#define D_80073C1C D_800F6780
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK apply_object_motion(void*); /* extern */
M2C_UNK func_8002EE10();            /* extern */

void func_800EF7A4(void* arg0) {
    if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        M2C_FIELD(arg0, s16*, 0x88) = 0x3C;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    apply_object_motion(arg0);
}

#include "common.h"

void func_800EF80C(u8* arg0) {
    if (--*(s16*)(arg0 + 0x88) == 0) {
        *(s16*)(arg0 + 0x88) = 0x3C;
        arg0[6]++;
    }
}

#define func_800F777C func_800EF840
#include "../shared/rock_07/func_800F777C.c"
#undef func_800F777C

#define func_8003744C func_800EF88C
#define D_80073C1C D_800F6790
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "psyq/libgte.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();

extern s32 D_800F6738;
extern s32 D_800F673C;

#define U8(o) M2C_FIELD(self, u8*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

void func_800EF8C8(void* self) {
    s32 a;
    s32 t;
    s32 u;

    a = (random_byte() * 8) & 0x7FF;
    t = rcos(a) << 4;
    S32(0x20) = t * 4 + t;
    u = rsin(a) << 4;
    S32(0x24) = u * 4 + u;
    PTR(0x50) = &D_800F6738;
    PTR(0x54) = &D_800F673C;
    U8(6)++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(); /* extern */

void func_800EF950(void* arg0) {
    s32 temp_v0;
    s32 temp_v1;

    ((M2C_UNK(*)())move_object)();
    temp_v1 = M2C_FIELD(arg0, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0x8C);
    temp_v0 = M2C_FIELD(arg0, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0x8E);
    if (((temp_v1 * temp_v1) + (temp_v0 * temp_v0)) >= 0x1000) {
        M2C_FIELD(arg0, s16*, 0x88) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_PlayerObj g_Player;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF9C4(void* arg0) {
    s32 ang;
    s32 v;
    s32 px;
    s32 py;

    if (--F(s16, 0x88) == 0) {
        play_sound(2, 0x84, arg0);
        px = g_Player.x_pos.i.hi;
        py = g_Player.y_pos.i.hi;
        ang = ratan2(F(s16, 0xE) - py, px - F(s16, 0xA));
        v = rcos(ang) * 16;
        F(s32, 0x20) = v * 5;
        v = rsin(ang) * 16;
        F(s32, 0x24) = v * 5;
        F(u8, 0x6)++;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EFA78(void) {
    ((M2C_UNK(*)())move_object)();
}

#include "common.h"
#include "mmx6/rock_15.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

extern void (*D_800F67AC[])(void*);

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)

void func_800EFA98(void* self) {
    if (M2C_FIELD(D_800F70E4, s8*, 4) != 1) {
        U8(3) = 0;
        U8(4)++;
        return;
    }
    animate_object(self);
    func_8002CCB0(self, 0x20, 0x20);
    (*(void (**)(void*))((S8(5) << 2) + (s32)D_800F67AC))(self);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EFB20(void) {
    clear_object_slot();
}

#include "common.h"

extern void (*D_800F67B4[])(void*);

void func_800EFB40(u8* arg0) {
    u16 v;

    D_800F67B4[((s8*)arg0)[6]](arg0);
    v = *(u16*)(arg0 + 0x54);
    *(u16*)(arg0 + 0x54) = v - 1;
    if (v & 1) {
        arg0[3] = 0;
    } else {
        arg0[3] = 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBAC(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBC0(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s8*, 3) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBF4(void* arg0) {
    void* temp_a0;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, u8*, 3) = 0U;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    temp_a0 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a0, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a0, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 3) = (u8)M2C_FIELD(temp_a0, u8*, 3);
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800EFC48);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EFC90 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F67C0;
extern M2C_UNK D_800F67C8;
extern M2C_UNK D_800F6884;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EFC90(void* self) {
    s32 n;
    s32 m;
    void* obj;
    u8 c;
    u16 x;
    struct X4_PlayerObj* pl;
    // !FAKE: depin: dropping it breaks the match (136/144)
    register s32 two asm("$18");

    {
        s32 k;
        {
            s8* q = &D_800CCF01;
            two = 2;
            *q = two;
        }
        k = 0x10;
        do {
            F(s8, 0x60) = k;
        } while (0);
    }
    {
        // !FAKE: depin: dropping it breaks the match (137/144)
        register void* a asm("$2") = &D_8007433C;
        F(void*, 0x58) = a;
    }
    pl = &g_Player;
    F(s8, 0x5C) = 0;
    F(s8, 0x61) = 0;
    F(s8, 3) = 0;
    c = pl->bg_offset;
    F(void*, 0x30) = &D_800F6884;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(s8, 0x67) = 0;
    F(u8, 0x16) = 6;
    F(void*, 0x50) = 0;
    F(void*, 0x54) = 0;
    F(s32, 0x68) = 0;
    F(u8, 0x14) = c;
    if (!(F(s8, 2) & 0xF0)) {
        F(u16, 0x40) = 0x140;
        n = func_8002A47C(F(s8, 1));
        m = func_8002A47C(F(s8, 1));
        F(s16, 0x42) = ((n * 4 + 0x20) % 16) | (((m + 8) / 4 + 0x1E0) << 6);
        F(s32, 0x3C) = SPAD20_800EFC90 +
                       *(s32*)(func_8002A47C(F(s8, 1)) * 4 + SPAD20_800EFC90);
        F(s8, 4) = 1;
        F(u16, 0xE) = 0x130;
        F(u16, 0xA) = 0xE90;
        F(s32, 0x68) = 0;
        F(u8, 0x15) = 0;
        F(s8, 5) = two;
        F(void*, 0x50) = &D_800F67C0;
        F(void*, 0x54) = &D_800F67C8;
        func_8003D308(0x14, pl->facing);
        set_animation(self, 0);
    }
    obj = func_8002C458();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0x21;
        M2C_FIELD(obj, u8*, 2) = 0xD;
        M2C_FIELD(obj, s32*, 0x30) = F(s32, 0x30);
        M2C_FIELD(obj, s32*, 0x3C) = F(s32, 0x3C);
        M2C_FIELD(obj, u16*, 0x40) = F(u16, 0x40);
        M2C_FIELD(obj, u8*, 0x15) = F(u8, 0x15);
        M2C_FIELD(obj, u8*, 0x14) = g_Player.bg_offset;
        x = F(u16, 0xA);
        M2C_FIELD(obj, u16*, 0x8) = 0;
        M2C_FIELD(obj, u16*, 0xA) = x;
        x = F(u16, 0xE);
        M2C_FIELD(obj, u16*, 0xC) = 0;
        M2C_FIELD(obj, void**, 0x7C) = self;
        M2C_FIELD(obj, u16*, 0xE) = x;
    }
    F(s8, 0x88) = 0;
    F(s8, 0x89) = 0;
    F(s16, 0x86) = 0;
    F(s8, 0x8A) = 0;
    F(s8, 0x8B) = 0;
    F(s8, 0x8C) = 0;
    F(s8, 0x8D) = 0;
    F(s16, 0x84) = 0;
    F(s8, 6) = 0;
    F(s8, 7) = 0;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK silence_sound(M2C_UNK, M2C_UNK);
M2C_UNK animate_object();
void stop_cd_audio();
s32 func_8002D30C();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_8004A0C0(M2C_UNK, s16, s16, s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800759BC;
extern M2C_UNK D_800F67C0;
extern void (*D_800F6E24[])(void*);

void func_800EFED0(void* arg0) {
    s32 v;
    s32 i;
    s32 x;
    void* p;
    u16 t;

    if (!(M2C_FIELD(arg0, s8*, 2) & 0xF0)) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F67C0;
        ((void (*)())animate_object)();
        if ((u32)(M2C_FIELD(arg0, u8*, 0x47) - 3) < 0xBU) {
            p = &D_800759BC;
        } else {
            p = &D_8007433C;
        }
        M2C_FIELD(arg0, void**, 0x58) = p;
    }
    D_800F6E24[M2C_FIELD(arg0, s8*, 5)](arg0);
    v = check_enemy_hits(arg0);
    if (v < 0) {
        i = 7;
        stop_cd_audio();
        silence_sound(0xFF, 0);
        D_8009711A = 1;
        do {
            x = M2C_FIELD(arg0, s16*, 0xA) + func_8002D30C() % 32;
            ((void (*)(s32, s32, s32, s32))func_8004A0C0)(
                0, x, M2C_FIELD(arg0, s16*, 0xE) + func_8002D30C() % 48, 0xFF);
        } while (--i >= 0);
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (v > 0 && v != 0x7F && M2C_FIELD(arg0, s16*, 0x84) == 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if ((u32)(v - 0x19) < 2U) {
            M2C_FIELD(arg0, s16*, 0x84) = 0xA;
        } else {
            M2C_FIELD(arg0, s16*, 0x84) = 0x1E;
        }
        if (v == 6 || v == 0xF || v == 0x25) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 4;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
    }
    if (M2C_FIELD(arg0, s16*, 0x84) != 0) {
        t = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(arg0, u16*, 0x84) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_800759BC;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    ((void (*)(void*, s32))func_80030ECC)(arg0, v);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
void* alloc_class3_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F0A78(void* arg0);

void func_800F0120(void* arg0) {
    void* p;
    s32 v;
    s8 r;

    if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
        ((void (*)())func_800F0A78)();
        M2C_FIELD(arg0, s32*, 0x8C) = 3;
    }
    if (M2C_FIELD(arg0, s32*, 0x90) == 0) {
        func_80029478(0xA, 4, 2);
        {
            // !FAKE: depin: dropping it breaks the match (80/82)
            register s32 k asm("$2") = 0xA;
            M2C_FIELD(arg0, s32*, 0x90) = k;
        }
    }
    M2C_FIELD(arg0, s32*, 0x90)--;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 5)++;
        p = alloc_class3_slot();
        if (p != 0) {
            M2C_FIELD(p, s8*, 0) = -0x7F;
            M2C_FIELD(p, s8*, 1) = 0x1A;
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
            M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = p;
        }
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x60);
    if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        M2C_FIELD(arg0, s8*, 0x61) -= 5;
        if (M2C_FIELD(arg0, s8*, 0x61) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        r = M2C_FIELD(arg0, s8*, 0x61);
        v = r < 6;
        if (v != 0) {
            v = 5;
        } else {
            v = r;
        }
        M2C_FIELD(arg0, s16*, 0x7E) = v;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
void func_800F1DA8(void*, s32, s32);
extern s8 D_800CCF5C;

void func_800F0268(void* arg0) {
    s32 q;
    s32 hp;

    if (M2C_FIELD(arg0, s16*, 0x7C)++ >= 0x3C) {
        if (M2C_FIELD(arg0, s16*, 0x86) != 0) {
            M2C_FIELD(arg0, s16*, 0x86)--;
        }
        q = D_800CCF5C / 4;
        hp = M2C_FIELD(arg0, s8*, 0x5C);
        if (q >= hp) {
            M2C_FIELD(arg0, s16*, 0x7E) = 5;
        } else if (D_800CCF5C / 2 >= hp) {
            M2C_FIELD(arg0, s16*, 0x7E) = 4;
        } else if (q * 3 >= hp) {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        }
        if (M2C_FIELD(arg0, s8*, 0x8A) == 1) {
            func_800F1DA8(arg0, random_byte() & 1, 0);
        } else {
            func_800F1DA8(arg0, 2, 0);
            M2C_FIELD(arg0, s8*, 0x8A) = 1;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, s8*, 0x8D)++;
        M2C_FIELD(arg0, s8*, 0x6)++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
void func_800F1DA8(void*, s32, s32);
extern u8 D_800F6DF8[];

void func_800F0390(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x86) != 0) {
        M2C_FIELD(arg0, s16*, 0x86)--;
        if (M2C_FIELD(arg0, s8*, 0x8D) < 3) {
            if (M2C_FIELD(arg0, s8*, 0x8A) == 1) {
                if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
                    M2C_FIELD(arg0, s16*, 0x7C)--;
                    return;
                }
                func_800F1DA8(arg0, random_byte() & 1, 0);
                M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            } else {
                if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
                    M2C_FIELD(arg0, s16*, 0x7C)--;
                    return;
                }
                func_800F1DA8(arg0, 2, 0);
                M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
                M2C_FIELD(arg0, s8*, 0x8A) = 1;
            }
            M2C_FIELD(arg0, s8*, 0x8D)++;
        }
    } else {
        s8 t = ++M2C_FIELD(arg0, s8*, 0x89);
        u8 v = D_800F6DF8[t + M2C_FIELD(arg0, s8*, 0x88) * 4];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = v;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern s8 D_800CCF5C;
extern u8 D_800F6DF8[];

void func_800F04A0(void* arg0) {
    u32 r;

    r = random_byte() & 0xF;
    if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
        if (r < 6) {
            M2C_FIELD(arg0, s8*, 0x88) = 0;
            M2C_FIELD(arg0, s8*, 0x8C)++;
        } else {
            if (r < 11) {
                M2C_FIELD(arg0, s8*, 0x88) = 1;
            } else {
                M2C_FIELD(arg0, s8*, 0x88) = 2;
            }
            M2C_FIELD(arg0, s8*, 0x8C) = 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x8C) >= 3 ||
            M2C_FIELD(arg0, s8*, 0x8D) >= 0x28) {
            M2C_FIELD(arg0, s8*, 0x88) = 1;
        }
    } else {
        if (r < 3) {
            M2C_FIELD(arg0, s8*, 0x88) = 0;
            M2C_FIELD(arg0, s8*, 0x8C)++;
        } else {
            if (r < 6) {
                M2C_FIELD(arg0, s8*, 0x88) = 3;
            } else if (r < 9) {
                M2C_FIELD(arg0, s8*, 0x88) = 4;
            } else if (r < 12) {
                M2C_FIELD(arg0, s8*, 0x88) = 5;
            } else {
                M2C_FIELD(arg0, s8*, 0x88) = 6;
            }
            M2C_FIELD(arg0, s8*, 0x8C) = 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x8C) >= 3 ||
            M2C_FIELD(arg0, s8*, 0x8D) >= 0x28) {
            M2C_FIELD(arg0, s8*, 0x88) = 3;
        }
    }
    M2C_FIELD(arg0, s8*, 0x89) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = D_800F6DF8[M2C_FIELD(arg0, s8*, 0x88) * 4];
    M2C_FIELD(arg0, s8*, 0x6) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_80097430;
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800CF854;

void func_800F05F4(u8* arg0) {
    u32 i;
    s32 n;
    u8* p;
    u8* q;
    u8* r;
    u8* e;
    u8 z;

    *(s16*)(arg0 + 0x7C) += 1;
    if ((s16)(*(s16*)(arg0 + 0x7C) % 5) == 0) {
        D_800CF854++;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        if ((u16)D_800CF854 == 0x1F) {
            z = 0;
            for (i = 0; i < 0x50; i++) {
                e = (u8*)g_class4_slots + i * 0xA4;
                if ((s8)e[1] == 8) {
                    p = e;
                    n = 0xA3;
                    do {
                        *p++ = z;
                    } while (n-- != 0);
                }
            }
            q = (u8*)background_objects;
            q[0x57] = 0;
            q[0xAB] = 0;
            *(s16*)(arg0 + 0x7C) = 0x78;
            *(s16*)(arg0 + 0x7E) = 0;
            arg0[6]++;
            r = (u8*)&g_playthrough_state;
            ((void (*)(s32, s32, s32))open_text_box)(1, 0xFF, r[0x2F]);
            r[0x2F] = 1;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002B2F8(s32);
void func_800F08C4(void* arg0);
void func_800F0A78(void* arg0);
extern s16 D_80090D5C;
#include "mmx6/state.h"
#include "mmx6/globals.h"
extern s16 D_80097430;
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800CF854;

void func_800F0744(void* arg0) {
    s16 t;
    s32 c;

    if (M2C_FIELD(arg0, s16*, 0x7E) != 0) {
        if (!(M2C_FIELD(arg0, u16*, 0x7E) & 1)) {
            ((void (*)())func_800F0A78)();
        }
        M2C_FIELD(arg0, s16*, 0x7E)--;
        return;
    }
    if ((u16)D_800CF854 >= 9) {
        if (!(*(u8*)&D_80097420 & 3)) {
            func_800F08C4(arg0);
        }
    }
    t = ++M2C_FIELD(arg0, s16*, 0x7C);
    if ((s16)(t % 5) == 0) {
        if ((u16)D_800CF854 >= 8) {
            func_80029478(0x1E, 8, 1);
        }
        c = (u16)D_800CF854 - 1;
        D_800CF854 = c;
        D_80097430 -= 0x20;
        D_80090D5C -= 0x400;
        D_800C4560 |= 1;
        if ((u16)c == 0) {
            func_8002B2F8(0);
            g_playthrough_state.enable_boss = 1;
            g_playthrough_state.unk25 = 1;
            g_playthrough_state.boss_ptr = arg0;
            M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x7F;
            M2C_FIELD(arg0, s16*, 0x7C) = 2;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
s32 func_8002D30C();
void func_8004A768();
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F6F10[];

void func_800F08C4(void* arg0) {
    s16 x;
    s16 y;
    s32 r;

    x = background_objects[0].x_pos.i.hi;
    y = background_objects[0].y_pos.i.hi;
    {
        s32 t = func_8002D30C();
        r = t - (t / 4) * 4;
    }
    M2C_FIELD(arg0, s32*, 0x94) = r;
    x += 0xA0;
    y += 0x3C;
    switch (r) {
    case 0:
        break;
    case 1:
        x += 0x50;
        break;
    case 2:
        y += 0x3C;
        break;
    case 3:
        x += 0x50;
        y += 0x3C;
        break;
    }
    x += func_8002D30C() % 80;
    y += func_8002D30C() % 60;
    func_8004A768(D_800F6F10[(random_byte() & 3) * 4], (s16)(x - 0x20),
                  (s16)(y - 0x20), (s16)(x + 0x20), (s16)(y + 0x20), 4);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
s32 func_8002D30C();
M2C_UNK func_8004A0C0(M2C_UNK, s16, s16, s32);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F6F20[];

void func_800F0A78(void* arg0) {
    s16 x;
    s16 y;
    s32 r;

    x = background_objects[0].x_pos.i.hi;
    y = background_objects[0].y_pos.i.hi;
    {
        s32 t = func_8002D30C();
        r = t - (t / 4) * 4;
    }
    M2C_FIELD(arg0, s32*, 0x94) = r;
    if (M2C_FIELD(arg0, s8*, 4) == 1) {
        x += 0xA0;
        y += 0xDC;
        switch (r) {
        case 0:
            break;
        case 1:
            x += 0x50;
            break;
        case 2:
            y -= 0x3C;
            break;
        case 3:
            x += 0x50;
            y -= 0x3C;
            break;
        }
        x += func_8002D30C() % 80;
        y -= func_8002D30C() % 60;
    } else {
        switch (r) {
        case 0:
            break;
        case 1:
            x += 0xA0;
            break;
        case 2:
            y += 0x78;
            break;
        case 3:
            x += 0xA0;
            y += 0x78;
            break;
        }
        x += func_8002D30C() % 160;
        y += func_8002D30C() % 120;
    }
    func_8004A0C0(0, x, y, 0xFF);
    if (!(D_80097420.frame_counter & 3)) {
        play_sound(0, D_800F6F20[(random_byte() & 3) * 4], 0);
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
struct X4_VisualObj* find_free_visual_obj(void);
s32 random_byte();

extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F67CC;
extern M2C_UNK D_800F6F38;
extern M2C_UNK D_800F6F48;
extern M2C_UNK D_800F6F58;
extern M2C_UNK D_800F6F68;
extern M2C_UNK D_800F6F6C;
extern M2C_UNK D_800F6F80;

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

#define SPAWN_CHILDREN()                                                       \
    {                                                                          \
        U16(0xA) -= 0x20;                                                      \
        play_sound(2, 0x73, self);                                             \
        for (i = 0; i < 8; i++) {                                              \
            c = find_free_visual_obj();                                        \
            if (c != NULL) {                                                   \
                M2C_FIELD(c, u8*, 0x0) = 0x51;                                 \
                M2C_FIELD(c, u8*, 0x1) = 0x14;                                 \
                M2C_FIELD(c, u8*, 0x2) = i;                                    \
                M2C_FIELD(c, u8*, 0x14) = U8(0x14);                            \
                M2C_FIELD(c, u16*, 0xA) = U16(0xA);                            \
                M2C_FIELD(c, u16*, 0xE) = U16(0xE);                            \
                M2C_FIELD(c, s32*, 0x38) = S32(0x38);                          \
                M2C_FIELD(c, s32*, 0x3C) = S32(0x3C);                          \
                M2C_FIELD(c, u16*, 0x40) = U16(0x40);                          \
                M2C_FIELD(c, u16*, 0x42) = U16(0x42);                          \
                M2C_FIELD(c, u8*, 0x16) = 6;                                   \
                M2C_FIELD(c, void**, 0x50) = self;                             \
                if (i != 0) {                                                  \
                    M2C_FIELD(c, void**, 0x5C) = prev;                         \
                } else {                                                       \
                    M2C_FIELD(c, void**, 0x5C) = self;                         \
                }                                                              \
                prev = c;                                                      \
            }                                                                  \
        }                                                                      \
    }

void func_800F0D08(void* self) {
    struct X4_VisualObj* c;
    void* prev;
    s32 i;
    s32 t;
    s32 dx;
    s32 dy;

    U8(0x16) = 4;
    U8(0x3) = 0;
    PTR(0x58) = &D_800743DC;
    U8(0x67) = 0;
    PTR(0x68) = NULL;
    PTR(0x50) = NULL;
    PTR(0x54) = NULL;
    U8(0x4) = 1;
    U8(0x5) = 0;
    U8(0x6) = 0;
    U8(0x7) = 0;
    S32(0x20) = 0;
    S32(0x24) = 0;
    S32(0x28) = 0;
    S32(0x2C) = 0;
    U16(0x8C) = 0;
    U16(0x8E) = 0;
    U8(0x92) = 0;
    U16(0x90) = 0;
    U16(0x94) = 0;

    if ((U8(0x2) & 0xF) == 0) {
        SPAWN_CHILDREN();
        U8(0x60) = 6;
        U8(0x5C) = 0x10;
        U8(0x7) = 0;
        ((void (*)(void*, s32))set_animation)(self, 0);
        U8(0x16) = 4;
        U8(0x5) = 0;
    } else if ((U8(0x2) & 0xF) == 1) {
        SPAWN_CHILDREN();
        ((void (*)(void*, s32))set_animation)(self, 0);
        U8(0x60) = 6;
        U8(0x5C) = 0x10;
        U8(0x16) = 4;
        U8(0x5) = 3;
    } else if ((U8(0x2) & 0xF) == 2) {
        SPAWN_CHILDREN();
        U8(0x3) = 1;
        ((void (*)(void*, s32))set_animation)(self, 0);
        U8(0x60) = 6;
        U8(0x5C) = 0x30;
        U8(0x16) = 3;
        U8(0x5) = 6;
        U8(0x75) = 1;
        U16(0x90) = ((u32)random_byte() % 19 & 0xFF) * 10 + 0x78;
    } else if ((U8(0x2) & 0xF) == 3) {
        play_sound(2, 0x75, self);
        U8(0x60) = 2;
        dx = g_Player.x_pos.i.hi - S16(0xA);
        dy = g_Player.y_pos.i.hi - S16(0xE);
        t = ratan2(dy, dx);
        S32(0x20) = rcos(t) << 5;
        S32(0x24) = -rsin(t) << 5;
        PTR(0x58) = &D_8007429C;
        U8(0x5C) = 1;
        PTR(0x68) = &D_800F6F38;
        PTR(0x50) = &D_800F6F58;
        PTR(0x54) = &D_800F6F48;
        U8(0x16) = 3;
        U8(0x5) = 5;
        ((void (*)(void*, s32))set_animation)(self, 0xC);
    } else if ((U8(0x2) & 0xF) == 4) {
        ((void (*)(void*, s32))set_animation)(self, 0);
        U8(0x16) = 6;
        U8(0x5) = 7;
        U16(0x8C) = 0x5A;
        U16(0xA) -= 0x18;
        U16(0xE) += 8;
    } else if ((U8(0x2) & 0xF) == 5) {
        U16(0xA) -= 0x10;
        U16(0xE) += 8;
        ((void (*)(void*, s32))set_animation)(self, 1);
        U8(0x16) = 5;
        U8(0x5) = 7;
        U16(0x8C) = 0x5A;
    } else if ((U8(0x2) & 0xF) == 6) {
        U8(0x60) = 0xA;
        ((void (*)(void*, s32))set_animation)(self, 2);
        U8(0x5) = 7;
        U8(0x16) = 5;
        PTR(0x50) = &D_800F6F68;
        U16(0x8C) = 0x78;
        U16(0xA) -= 0x50;
        U16(0xE) += 8;
    } else if ((U8(0x2) & 0xF) == 7) {
        U8(0x60) = 0xA;
        U16(0xA) -= 0x108;
        U16(0xE) += 8;
        ((void (*)(void*, s32))set_animation)(self, 3);
        U8(0x16) = 6;
        U8(0x5) = 7;
        PTR(0x50) = &D_800F6F6C;
        U16(0x8C) = 0x78;
    } else if ((U8(0x2) & 0xF) == 8) {
        U16(0xA) -= 0xA0;
        U16(0xE) += 8;
        ((void (*)(void*, s32))set_animation)(self, 6);
        U8(0x16) = 5;
        U8(0x5) = 7;
        U16(0x8C) = 0x18;
    } else if ((U8(0x2) & 0xF) == 9) {
        U8(0x16) = 6;
        ((void (*)(void*, s32))set_animation)(self, 7);
        U8(0x5) = 8;
        U16(0x8C) = 0xA0;
    } else if ((U8(0x2) & 0xF) == 10) {
        U8(0x16) = 5;
        U8(0x60) = 0xA;
        ((void (*)(void*, s32))set_animation)(self, 8);
        U8(0x5) = 8;
        U8(0x6) = 2;
        PTR(0x50) = &D_800F6F80;
        U16(0x8C) = 0x78;
    } else if ((U8(0x2) & 0xF) == 11) {
        U8(0x16) = 5;
        U8(0x60) = 0xC;
        U16(0xA) -= 0x10;
        U16(0xE) += 0x10;
        ((void (*)(void*, s32))set_animation)(self, 9);
        U8(0x5) = 9;
    } else if ((U8(0x2) & 0xF) == 12) {
        U8(0x60) = 0xC;
        U8(0x16) = 5;
        U16(0xA) -= 0x10;
        U16(0xE) += 0x10;
        ((void (*)(void*, s32))set_animation)(self, 9);
        U8(0x15) = 0x40;
        U8(0x5) = 9;
    } else if ((U8(0x2) & 0xF) == 13) {
        U8(0x3) = 0;
        U8(0x16) = 7;
        PTR(0x54) = &D_800F67CC;
        PTR(0x58) = &D_8007433C;
        U8(0x5) = 0xA;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90();
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_8007433C;
extern s32 D_800970A8;
extern void (*D_800F6F94[])(void*);

void func_800F1444(void* arg0) {
    void* p;
    s32 r;
    s32 c;
    s8 v;
    s8 d;

    p = M2C_FIELD(arg0, void**, 0x7C);
    D_800F6F94[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 4) != 1) {
        return;
    }
    r = check_enemy_hits(arg0);
    v = M2C_FIELD(arg0, s8*, 2);
    if (v < 3) {
        if (v < 2 && M2C_FIELD(p, s8*, 0x8B) != 0) {
            M2C_FIELD(arg0, s8*, 3) = 0;
            func_80049E50(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
            func_8004E654(arg0, 0x11);
            if (M2C_FIELD(p, s8*, 0x8D) != 0) {
                M2C_FIELD(p, u8*, 0x8D)--;
            }
            return;
        }
        if (r < 0 || M2C_FIELD(p, s8*, 5) == 4 || M2C_FIELD(p, s8*, 4) == 2) {
            M2C_FIELD(arg0, s8*, 3) = 0;
            func_80049E50(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
            M2C_FIELD(arg0, s8*, 5) = 0;
            if (M2C_FIELD(p, s8*, 0x8D) != 0) {
                M2C_FIELD(p, u8*, 0x8D)--;
            }
            if (M2C_FIELD(arg0, s8*, 2) == 2) {
                M2C_FIELD(p, s8*, 0x8A) = 0;
            }
            func_8004E654(arg0, 0x11);
            return;
        }
        if (r > 0 && M2C_FIELD(arg0, s8*, 2) == 0 &&
            M2C_FIELD(arg0, s8*, 0x92) == 0 && M2C_FIELD(arg0, s8*, 0x5C) < 8) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, s8*, 0x92) = 0x20;
            if (M2C_FIELD(arg0, s8*, 0x67) == 0) {
                set_animation(arg0, 9);
            } else {
                set_animation(arg0, 0xA);
            }
            if (D_800970A8 > M2C_FIELD(arg0, s32*, 8)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
    } else if (v != 0xD &&
               (M2C_FIELD(p, s8*, 5) == 4 || M2C_FIELD(p, s8*, 4) == 2)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    c = func_80030ECC(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        if (c != 0 || M2C_FIELD(p, s8*, 0x8B) != 0 || r < 0) {
            M2C_FIELD(arg0, s8*, 3) = 0;
            func_80049D90(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
            return;
        }
    }
    if (is_off_screen(arg0, 0xA0, 0xA0) == 0) {
        d = M2C_FIELD(arg0, s8*, 2);
        if (d != 2 && d != 0xD) {
            func_8002CCB0(arg0, 0x80, 0x80);
        }
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s8*, 0x67) = 0;
        return;
    }
    {
        // !FAKE: depin: dropping it breaks the match (181/183)
        register s32 x asm("$2") = M2C_FIELD(arg0, s32*, 0x24);
        // !FAKE: depin: dropping it breaks the match (180/183)
        register s32 e asm("$2");
        if (x < 0) {
            e = -1;
        } else {
            e = 1;
        }
        M2C_FIELD(arg0, s8*, 0x67) = e;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800F3824(struct X4_MainObj*);
extern s16 D_800970AA;

void func_800F1720(void* arg0) {
    s32 d;
    // !FAKE: shift and quotient share the first return register
    register s32 v asm("$2");
    s32 div40;
    s32 div800;
    s32 n;

    animate_object();
    {
        // !FAKE: decremented counter in the first return register
        register s32 c asm("$2") = M2C_FIELD(arg0, u16*, 0x8C) - 1;
        M2C_FIELD(arg0, u16*, 0x8C) = c;
        if ((c << 16) != 0) {
            return;
        }
    }
    {
        ((void (*)(void*, s32))set_animation)(arg0, 8);
        d = D_800970AA - M2C_FIELD(arg0, s16*, 0xA);
        if (d < 0) {
            d = M2C_FIELD(arg0, s16*, 0xA) - D_800970AA;
        }
        n = 0x600000;
        div800 = 800;
        div40 = 40;
        M2C_FIELD(arg0, s32*, 0x2C) = n / div800;
        M2C_FIELD(arg0, s32*, 0x24) = 0x4CCC0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        func_800F3824(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            v = d << 16;
        } else {
            v = -d << 16;
        }
        v = v / div40;
        M2C_FIELD(arg0, s32*, 0x20) = v;
        do {
        } while (0);
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();

extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F6F30[];
extern u16 D_800F700C[][2];

#define U8(o) M2C_FIELD(self, u8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

void func_800F1810(void* self) {
    s16 y;
    s16 x;
    s32 t;
    u16 i;
    s32 dy;

    PTR(0x68) = D_800F6F30;
    if (!(random_byte() & 1)) {
        y = background_objects[0].unk26 +
            ((((u32)random_byte() % 5) & 0xFF) << 5) - 0x20;
        U16(0x8C) = random_byte() & 1;
        if (!(random_byte() & 1)) {
            PTR(0x68) = D_800F6F30 + 1;
            U8(0x6) = 3;
            x = background_objects[0].unk2A + 0x20;
        } else {
            U8(0x6) = 4;
            x = background_objects[0].unk2A + 0xC0;
        }
        t = ratan2(x - S16(0xE), y - S16(0xA));
        S32(0x20) = rcos(t) << 6;
        S32(0x24) = -rsin(t) << 6;
    } else {
        i = ((u32)random_byte() % 15) & 0xFF;
        U16(0x8C) = i;
        y = background_objects[0].unk26 + (D_800F700C[i][0] + 0x20);
        dy = y - S16(0xA);
        x = background_objects[0].unk2A + (D_800F700C[i][1] + 0x30);
        t = ratan2(x - S16(0xE), dy);
        S32(0x20) = rcos(t) << 6;
        S32(0x24) = -rsin(t) << 6;
        {
            s16 m = S16(0x8C) % 3;
            u16 b = background_objects[0].unk26;
            U8(0x6)++;
            U16(0x8C) = b + m * 0x30 + 0x20;
        }
    }
    U8(0x7) = 1;
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

M2C_UNK collide_solid_object();
extern void (*D_800F7060[])(s8*);

void func_800F1A5C(s8* arg0) {
    s8* temp_s1;
    s32 temp_v0;

    temp_s1 = *(s8**)(arg0 + 0x7C);
    D_800F7060[arg0[6]](arg0);
    if (arg0[6] < 3) {
        return;
    }
    if (D_80097185 != 0) {
        return;
    }
    collide_solid_object(arg0);
    if (arg0[6] >= 8) {
        return;
    }
    temp_v0 = (*(u16*)(arg0 + 0x8E))++;
    if ((s16)temp_v0 > 0x1E0) {
        temp_v0 = (*(u16*)(arg0 + 0x8E))++;
        arg0[3] ^= 1;
        if ((s16)temp_v0 > 0x21C) {
            *(s32*)(arg0 + 0x68) = 0;
            *(s32*)(arg0 + 0x54) = 0;
            temp_s1[0x8A] = 0;
        }
        temp_v0 = (*(u16*)(arg0 + 0x8E))++;
        if ((s16)temp_v0 > 0x258) {
            if (temp_s1[0x8D] != 0) {
                temp_s1[0x8D]--;
            }
            arg0[4] = 2;
        }
    } else if (*(s16*)(arg0 + 0x90) == (s16) * (u16*)(arg0 + 0x8E)) {
        arg0[7] = arg0[6];
        arg0[0x93] = 0;
        arg0[6] = 8;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern s16 D_80097222;
extern M2C_UNK D_800F6F44;
extern M2C_UNK D_800F6F64;

void func_800F1B98(void* arg0) {
    s32 temp_v1;

    animate_object();
    move_object((s32)arg0);
    temp_v1 = M2C_FIELD(arg0, u16*, 0x8C);
    {
        // !FAKE: depin: dropping it breaks the match (67/74)
        register s32 t0 asm("$2") = M2C_FIELD(arg0, s16*, 0x8C);
        if (t0 == 0) {
            temp_v1 = D_80097222 + 0x70;
            {
                // !FAKE: depin: dropping it breaks the match (66/74)
                register s32 e asm("$4") = M2C_FIELD(arg0, s16*, 0xE);
                if (e >= temp_v1) {
                    M2C_FIELD(arg0, s8*, 7) = -1;
                    set_animation(arg0, 0x10);
                    M2C_FIELD(arg0, void**, 0x50) = &D_800F6F64;
                    play_sound(2, 0x74, arg0);
                    M2C_FIELD(arg0, void**, 0x54) = &D_800F6F44;
                    M2C_FIELD(arg0, s32*, 0x24) = 0;
                    M2C_FIELD(arg0, s32*, 0x2C) = 0;
                    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
                }
            }
        } else if ((u16)(temp_v1 - 1) < 2U) {
            if (D_8009721E + 0x20 >= M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, s8*, 7) = -1;
                set_animation(arg0, 0x10);
                M2C_FIELD(arg0, void**, 0x50) = &D_800F6F64;
                play_sound(2, 0x74, arg0);
                M2C_FIELD(arg0, u8*, 6) = 5;
            }
        } else if ((u16)(temp_v1 - 3) < 2U) {
            if (D_8009721E + 0xB0 >= M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, s8*, 7) = -1;
                set_animation(arg0, 0x10);
                M2C_FIELD(arg0, void**, 0x50) = &D_800F6F64;
                play_sound(2, 0x74, arg0);
                M2C_FIELD(arg0, u8*, 6) = 5;
            }
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800F6F58;

void func_800F1CC0(void* arg0) {
    s16 x;
    s16 y;
    s32 angle;

    M2C_FIELD(arg0, void**, 0x50) = &D_800F6F58;
    x = background_objects[0].unk26 + 0x30;
    if (background_objects[0].unk2A + 0x80 < D_800970AE) {
        y = background_objects[0].unk2A + 0xB0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
    } else {
        y = background_objects[0].unk2A + 0x60;
        M2C_FIELD(arg0, s16*, 0x8C) = 1;
    }
    angle =
        ratan2(y - M2C_FIELD(arg0, s16*, 0xE), x - M2C_FIELD(arg0, s16*, 0xA));
    {
        s32 a = rcos(angle) * 16;
        M2C_FIELD(arg0, s32*, 0x20) = a * 4 + a;
    }
    {
        s32 b = -rsin(angle) * 16;
        M2C_FIELD(arg0, s32*, 0x24) = b * 4 + b;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F1DA8 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002C458();
extern s32 D_800F6ABC;
extern s32 D_800F6DA4;

void func_800F1DA8(void* arg0, s32 arg1, s32 arg2) {
    u8 id = arg1;
    u8 kind = arg2;
    void* e;

    e = func_8002C458();
    {
        s32 c;
        c = 0x41;
        if (e != 0) {
            M2C_FIELD(e, u8*, 0) = c;
            {
                s32 d;
                d = 0x21;
                M2C_FIELD(e, u8*, 1) = d;
            }
            M2C_FIELD(e, u8*, 2) = id;
            if (kind == 0) {
                M2C_FIELD(e, s16*, 0x40) = 0x140;
                M2C_FIELD(e, s32**, 0x30) = &D_800F6DA4;
                M2C_FIELD(e, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DA8 + SPAD20_800F1DA8[func_8002A47C(0x3E)];
                M2C_FIELD(e, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(e, void**, 0x7C) = arg0;
            } else if (kind == 1) {
                M2C_FIELD(e, s16*, 0x40) = 0x240;
                M2C_FIELD(e, s32**, 0x30) = &D_800F6ABC;
                M2C_FIELD(e, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DA8 +
                    SPAD20_800F1DA8[func_8002A47C(0x3E) + 2];
                M2C_FIELD(e, s16*, 0x42) =
                    (((func_8002A47C(0x3E) + 2) * 4 + 0x20) % 16) |
                    (((func_8002A47C(0x3E) + 2 + 8) / 4 + 0x1E0) << 6);
                M2C_FIELD(e, void**, 0x7C) = M2C_FIELD(arg0, void**, 0x7C);
            } else if (kind == 2) {
                M2C_FIELD(e, s16*, 0x40) = 0x240;
                M2C_FIELD(e, s32**, 0x30) = &D_800F6ABC;
                M2C_FIELD(e, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DA8 +
                    SPAD20_800F1DA8[func_8002A47C(0x3E) + 1];
                M2C_FIELD(e, s16*, 0x42) =
                    (((func_8002A47C(0x3E) + 2) * 4 + 0x20) % 16) |
                    (((func_8002A47C(0x3E) + 2 + 8) / 4 + 0x1E0) << 6);
                M2C_FIELD(e, void**, 0x7C) = arg0;
            } else if (kind == 3) {
                M2C_FIELD(e, s16*, 0x40) = 0x240;
                M2C_FIELD(e, s32**, 0x30) = &D_800F6ABC;
                M2C_FIELD(e, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DA8 +
                    SPAD20_800F1DA8[func_8002A47C(0x3E) + 2];
                M2C_FIELD(e, s16*, 0x42) =
                    (((func_8002A47C(0x3E) + 2) * 4 + 0x20) % 16) |
                    (((func_8002A47C(0x3E) + 2 + 8) / 4 + 0x1E0) << 6);
                M2C_FIELD(e, void**, 0x7C) = arg0;
            }
            M2C_FIELD(e, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(e, u8*, 0x14) = D_800970B4;
            {
                u16 x = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(e, s16*, 0x8) = 0;
                M2C_FIELD(e, s16*, 0xA) = x;
            }
            {
                u16 y = M2C_FIELD(arg0, u16*, 0xE);
                M2C_FIELD(e, s16*, 0xC) = 0;
                M2C_FIELD(e, s16*, 0xE) = y;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern void (*D_800F70D0[])(void*, void*);

void func_800F2014(struct X4_AnimatedObj* arg0) {
    struct X4_AnimatedObj* p;
    s8 v;
    s8 w;

    p = M2C_FIELD(arg0, struct X4_AnimatedObj**, 0x50);
    M2C_FIELD(arg0, u8*, 0x47) = M2C_FIELD(p, u8*, 0x47);
    arg0->unk15 = p->unk15;
    arg0->unk38 = p->unk38;
    arg0->unk3C = p->unk3C;
    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    if (arg0->state == 0) {
        v = p->unk7;
        if (v != 0) {
            if (v > 0) {
                arg0->on_screen = 1;
                M2C_FIELD(arg0, s16*, 0x54) = 3;
                M2C_FIELD(arg0, s16*, 0x56) = 8;
                M2C_FIELD(arg0, s16*, 0x58) = 0xA;
                arg0->x_pos = p->x_pos;
                arg0->y_pos = p->y_pos;
                arg0->state = 1;
                arg0->action = 0;
            } else {
                p->unk7 = 0;
            }
        }
    } else {
        w = p->unk7;
        if (w == 0) {
            arg0->on_screen = 0;
            arg0->state = 0;
        } else if (w == 0xA) {
            arg0->state = w;
        } else {
            D_800F70D0[arg0->action](arg0, p);
        }
    }
    if (p->state == 2 || arg0->state == 0xA) {
        clear_object_slot(arg0);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800F2154);
// clang-format on

#define func_80041AB8 func_800F21B0
#define D_80075FD8 D_800F6E4C
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800F21EC(void* arg0) {
    {
        struct X4_PlayerObj* p = &g_Player;
        ((u8*)p)[0xCA] = 0;
        ((void (*)(s32, s32))func_8003D308)(0x14, p->facing);
    }
    ((void (*)(s32, s32, void*))play_sound)(2, 0x20, arg0);
    ((void (*)(void*, s32))set_animation)(arg0, 3);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x60);
    *(s32*)((u8*)arg0 + 0x80) = 0x78;
    *(s32*)((u8*)arg0 + 0x8C) = 1;
    *(s32*)((u8*)arg0 + 0x90) = 1;
    *(u8*)((u8*)arg0 + 5) = 1;
    *(u16*)((u8*)arg0 + 0x42) &= 0x7FFF;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F0A78(void* arg0);

#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
void func_800F2274(void* arg0) {
    if (--F_S32(arg0, 0x8C) == 0) {
        func_800F0A78(arg0);
        F_S32(arg0, 0x8C) = F_S32(arg0, 0x80) / 40 + 3;
    }
    if (--F_S32(arg0, 0x90) == 0) {
        ((void (*)(s32, s32, s32))func_80029478)(4, 2, 2);
        F_S32(arg0, 0x90) = F_S32(arg0, 0x80) / 10 + 10;
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x60);
    if (D_800970A5 == 0x14) {
        if (--F_S32(arg0, 0x80) == 0) {
            ((void (*)(s32, s32, s32))func_80029478)(0x28, 4, 2);
            F_S32(arg0, 0x8C) = 3;
            F_S32(arg0, 0x90) = 0x27;
            ((void (*)(s32, s32, s32))open_text_box)(2, 0xFF, 0);
            F_U8(arg0, 5)++;
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F0A78(void* arg0);

void func_800F239C(void* arg0) {
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x60);
    if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
        func_800F0A78(arg0);
        M2C_FIELD(arg0, s32*, 0x8C) = 3;
    }
    if (M2C_FIELD(arg0, s32*, 0x90) == 0) {
        func_80029478(0xA, 4, 2);
        {
            // !FAKE: keep the constant in the first return register for the store
            register s32 k asm("$2") = 0xA;
            M2C_FIELD(arg0, s32*, 0x90) = k;
        }
    }
    M2C_FIELD(arg0, s32*, 0x90)--;
    if (D_8008EAFC == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
        M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
        M2C_FIELD(arg0, s8*, 0x61) = 0x19;
        M2C_FIELD(arg0, u8*, 5)++;
        start_pad_vibration(9);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F0A78(void* arg0);
extern struct X4_EngineObj g_playthrough_state;

void func_800F2458(void* arg0) {
    s8* p;

    p = M2C_FIELD(arg0, s8**, 0x80);
    M2C_FIELD(arg0, u8*, 3) = 0;
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
                func_800F0A78(arg0);
                M2C_FIELD(arg0, s32*, 0x8C) = 3;
            }
            if (M2C_FIELD(arg0, s32*, 0x90) == 0) {
                // !FAKE: depin: dropping it breaks the match (69/71)
                register s32 t asm("$2");

                func_80029478(0xA, 4, 2);
                t = 0xA;
                M2C_FIELD(arg0, s32*, 0x90) = t;
            }
            M2C_FIELD(arg0, s32*, 0x90)--;
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        s8* e = (s8*)&g_playthrough_state;

        M2C_FIELD(arg0, void**, 0x80) = 0;
        M2C_FIELD(arg0, s32*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x88) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        M2C_FIELD(arg0, s32*, 0x90) = 0;
        M2C_FIELD(arg0, s32*, 0x94) = 0;
        M2C_FIELD(e, u8*, 0x24) = 0;
        M2C_FIELD(e, s32*, 0x20) = 0;
        M2C_FIELD(e, u8*, 0xF) = 0x10;
        clear_object_slot(arg0);
    }
}

#define func_8003744C func_800F2574
#define D_80073C1C D_800F6E60
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F25B0(u8* arg0) {
    set_animation(arg0, 0);
    *(s32*)(arg0 + 0x24) = 0;
    *(s16*)(arg0 + 0x7C) = 0x3C;
    *(s16*)(arg0 + 0x7E) = 0;
    arg0[6]++;
}

#include "common.h"

extern u8 D_800F6DF8[];

void func_800F25F4(u8* arg0) {
    s32 t;
    u8 v;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        t = arg0[0x89] + 1;
        arg0[0x89] = t;
        v = D_800F6DF8[(s8)t + *(s8*)(arg0 + 0x88) * 4];
        arg0[6] = 0;
        arg0[5] = v;
    }
}

#include "common.h"

void func_800F2650(void) {
}

#define func_8003744C func_800F2658
#define D_80073C1C D_800F6E6C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F2694(u8* arg0) {
    set_animation(arg0, 4);
    *(s16*)(arg0 + 0x86) = 0x12C;
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}

#include "common.h"

s32 random_byte();
void func_800F1DA8(void* arg0, s32 arg1, s32 arg2);

void func_800F26D4(u8* arg0) {
    if (*(s16*)(arg0 + 0x86) != 0) {
        *(s16*)(arg0 + 0x86) = *(s16*)(arg0 + 0x86) - 1;
    }
    if (*(s16*)(arg0 + 0x7C) != 0) {
        *(s16*)(arg0 + 0x7C) = *(s16*)(arg0 + 0x7C) - 1;
        return;
    }
    if (*(s16*)(arg0 + 0x7E) != 0) {
        *(s16*)(arg0 + 0x7C) = 0x1E;
        *(s16*)(arg0 + 0x7E) = *(s16*)(arg0 + 0x7E) - 1;
        func_800F1DA8(arg0, random_byte() & 1, 0);
        arg0[0x8D] = arg0[0x8D] + 1;
        return;
    }
    arg0[6] = arg0[6] + 1;
}

#define func_8003744C func_800F2774
#define D_80073C1C D_800F6E7C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F27B0(void* arg0) {
    ((void (*)(s32, s32, void*))play_sound)(2, (random_byte() & 1) | 0x22,
                                            arg0);
    ((void (*)(void*, s32))set_animation)(arg0, 1);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800F1DA8(void*, s32, s32);         /* extern */

void func_800F2800(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x47) == 0xC) {
        func_800F1DA8(arg0, 4, 2);
        func_800F1DA8(arg0, 5, 2);
        play_sound(2, 0x79, arg0);
        M2C_FIELD(arg0, s8*, 7) = 2;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void func_800F1DA8(void*, s32, s32);              /* extern */

void func_800F286C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        play_sound(2, 0x14, arg0);
        play_sound(2, 0x76, arg0);
        func_800F1DA8(arg0, 6, 2);
        func_800F1DA8(arg0, 7, 2);
        func_80029478(0x78, 2, 2);
        M2C_FIELD(arg0, s8*, 7) = 2;
        M2C_FIELD(arg0, s8*, 0x8B) = 1;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        start_pad_vibration(9);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1DA8(void*, s32, s32);
extern M2C_UNK D_800F67C0;
extern M2C_UNK D_800F67C4;

void func_800F2910(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0xE) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F67C4;
    }
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F67C0;
        func_800F1DA8(arg0, 8, 2);
        M2C_FIELD(arg0, s8*, 7) = 1;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800F2998(s8* arg0) {
    if (arg0[7] == 0) {
        set_animation(arg0, 5);
        play_sound(2, 0x14, arg0);
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F6DF8[];

void func_800F29F0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        s8 t = ++M2C_FIELD(arg0, s8*, 0x89);
        u8 v = D_800F6DF8[t + M2C_FIELD(arg0, s8*, 0x88) * 4];
        M2C_FIELD(arg0, u8*, 0x8B) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = v;
    }
}

#define func_8003744C func_800F2A44
#define D_80073C1C D_800F6E94
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;

void func_800F2A80(void* arg0) {
    s8* e = (s8*)&g_playthrough_state;

    if (M2C_FIELD(e, u8*, 0x68) >= 2) {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        }
    } else {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 >= M2C_FIELD(arg0, s8*, 0x5C)) {
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 1;
        }
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    set_animation(arg0, 1);
    play_sound(2, (random_byte() & 1) | 0x24, arg0);
    M2C_FIELD(arg0, u8*, 6) += 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1DA8(void*, s32, s32); /* extern */
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800F2B50(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x47) == 0xC) {
        if ((background_objects[0].unk26 + 0x80) > D_800970AA) {
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
        } else {
            M2C_FIELD(arg0, s16*, 0x7C) = 1;
        }
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0x40;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xA0;
        }
        M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk2A + 0xC0;
        func_800F1DA8(arg0, 9, 3);
        M2C_FIELD(arg0, s8*, 7) = 1;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void func_800F1DA8(void*, s32, s32);              /* extern */
extern struct X4_BackgroundObj background_objects[3];

void func_800F2C1C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        play_sound(2, 0x76, arg0);
        start_pad_vibration(6);
        M2C_FIELD(arg0, s8*, 0x8B) = 1;
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0x40;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xA0;
        }
        M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk2A + 0x70;
        func_800F1DA8(arg0, 0xA, 3);
        func_80029478(0x78, 2, 2);
        M2C_FIELD(arg0, s16*, 0x8E) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800F1DA8(void*, s32, s32);         /* extern */
extern struct X4_BackgroundObj background_objects[3];

void func_800F2CF0(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x8E);
    M2C_FIELD(arg0, u16*, 0x8E) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x5B) {
        play_sound(2, 0x14, arg0);
        if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0x40;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xA0;
        }
        M2C_FIELD(arg0, s16*, 0xE) = (s16)(background_objects[0].unk2A + 0xC0);
        func_800F1DA8(arg0, 9, 3);
        M2C_FIELD(arg0, s8*, 7) = 1;
        M2C_FIELD(arg0, s16*, 0x8E) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void func_800F1DA8(void*, s32, s32);              /* extern */
extern struct X4_BackgroundObj background_objects[3];

void func_800F2DC0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        play_sound(2, 0x76, arg0);
        ((void (*)(s32))start_pad_vibration)(6);
        if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0x40;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xA0;
        }
        M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk2A + 0x70;
        func_800F1DA8(arg0, 0xA, 3);
        ((void (*)(s32, s32, s32))func_80029478)(0x78, 2, 2);
        M2C_FIELD(arg0, s8*, 7) = 1;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */

void func_800F2E90(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x8E);
    M2C_FIELD(arg0, u16*, 0x8E) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x51) {
        play_sound(2, 0x14, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        M2C_FIELD(arg0, u16*, 0x8E) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

extern u8 D_800F6DF8[];

void func_800F2EFC(u8* arg0) {
    s32 t;
    u8 v;

    if (*(s8*)(arg0 + 0x45) == 1) {
        if (*(s16*)(arg0 + 0x7E) != 0) {
            *(s16*)(arg0 + 0x7C) = 10;
            arg0[6]++;
            return;
        }
        t = arg0[0x89] + 1;
        arg0[0x89] = t;
        v = D_800F6DF8[(s8)t + *(s8*)(arg0 + 0x88) * 4];
        arg0[6] = 0;
        arg0[0x8B] = 0;
        arg0[5] = v;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F2F78(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        set_animation(arg0, 1);
        play_sound(2, (random_byte() & 1) | 0x24, arg0);
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, u16*, 0x7E) -= 1;
    }
}

#define func_8003744C func_800F2FEC
#define D_80073C1C D_800F6EB4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/globals.h"

void func_800F3028(u8* arg0) {
    *(s16*)(arg0 + 0x7C) = 0xA;
    if (D_800CCF38 >= 2) {
        *(s16*)(arg0 + 0x7E) = 4;
    } else {
        *(s16*)(arg0 + 0x7E) = 2;
    }
    arg0[6]++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */

void func_800F3064(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
        return;
    }
    set_animation(arg0, 2);
    play_sound(2, 0x26, arg0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800F1DA8(void*, s32, s32);         /* extern */

void func_800F30C8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x71, arg0);
        func_800F1DA8(arg0, 0xB, 3);
        func_800F1DA8(arg0, 0xC, 3);
        M2C_FIELD(arg0, s16*, 0x8E) = 0;
        M2C_FIELD(arg0, u16*, 0x7E) = (u16)(M2C_FIELD(arg0, u16*, 0x7E) - 1);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F3140(void* arg0) {
    u16 t;

    t = *(u16*)((u8*)arg0 + 0x8E);
    *(u16*)((u8*)arg0 + 0x8E) = t + 1;
    if ((s16)t >= 0x1F) {
        ((void (*)(void*, s32))set_animation)(arg0, 6);
        *(u16*)((u8*)arg0 + 0x8E) = 0;
        ((u8*)arg0)[6]++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3198(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800F6DF8[];

void func_800F31C0(struct X4_MainObj* self) {
    s32 t;
    s32 v;

    if (--self->unk7C == 0) {
        if (self->unk7E != 0) {
            set_animation(self, 2);
            play_sound(2, 0x26, self);
            self->action_phase = 2;
            return;
        }
        M2C_FIELD(self, s8*, 0x8B) = 0;
        t = M2C_FIELD(self, u8*, 0x89) + 1;
        M2C_FIELD(self, u8*, 0x89) = t;
        v = D_800F6DF8[(s8)t + M2C_FIELD(self, s8*, 0x88) * 4];
        self->action_phase = 0;
        self->action = v;
    }
}

#define func_8003744C func_800F326C
#define D_80073C1C D_800F6ECC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B2F8(s32);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CF850;

void func_800F32A8(void* arg0) {
    s32 i;

    if (D_800970A5 == 0x14) {
        func_8002B2F8(0);
        D_80090D56 = 1;
        D_8009742C = 1;
        D_800CF850 = 1;
        D_80090C90[1] = 0xF0000000;
        for (i = 3; i < 15; i++) {
            D_80090C90[i] = -1;
        }
        D_800C4560 |= 1;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}

#define func_800F4BA8 func_800F334C
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800F3390(u8* arg0) {
    u8* temp_v0;

    if (g_Player.action == 0x14) {
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != 0) {
            temp_v0[0] = 1;
            temp_v0[1] = 0x18;
            M2C_FIELD(arg0, u8**, 0x80) = temp_v0;
        }
    }
    if (g_Player.x_pos.i.hi > (D_8009721E + 0x40)) {
        ((void (*)(s32, s32))func_8003D308)(0x1D, 0);
    }
    arg0[6] = arg0[6] + 1;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s16 D_800970AA;

void func_800F342C(void* arg0) {
    if (D_800970AA <= (D_8009721E + 0x40)) {
        func_8003D308(0x14, 0x40);
        ((u8*)arg0)[6]++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F3484(void* arg0) {
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        func_80029478(0x28, 4, 1);
        start_pad_vibration(6);
        play_sound(0, 2, arg0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);             /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F34F4(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x65) {
        func_80029478(0x28, 4, 1);
        start_pad_vibration(6);
        play_sound(0, 2, arg0);
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_80097244;
extern u8 D_800F6EF8[];
extern u8 D_800F6F00[];

void func_800F356C(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x79) {
        func_80027BA0(0, 0xDA0, 0xD0, D_800F6EF8);
        func_80027BA0(0, 0xD80, 0x150, D_800F6F00);
        D_80097244 = 1;
        D_80090C98 = -1;
        D_800C4560 |= 1;
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        play_sound(0, 4, arg0);
        M2C_FIELD(arg0, u16*, 0x7E) = 0x32;
        func_80029478((s8)M2C_FIELD(arg0, u16*, 0x7E), 8, 1);
        start_pad_vibration(3);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800F3644(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003D330();
extern s8 D_800CCF5C;

void func_800F3680(u8* arg0) {
    s8 n;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        play_sound(0, 0xE, 0);
        *(u16*)(arg0 + 0x7C) = 2;
    }
    if (++*(s8*)(arg0 + 0x5C) >= (n = D_800CCF5C)) {
        *(u16*)(arg0 + 0x7C) = 0;
        *(u16*)(arg0 + 0x7E) = 0;
        func_8003D330(n);
        arg0[5] = 9;
        arg0[6] = 0;
    }
}

#define func_8003744C func_800F3710
#define D_80073C1C D_800F6F08
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800F374C(u8* arg0) {
    play_sound(2, 0x14, arg0);
    play_sound(2, 0x21, arg0);
    set_animation(arg0, 3);
    func_80029478(0x3C, 2, 2);
    ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))func_8002943C)(0x3C, 2, 2);
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F37C8(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, s16*, 0x84) = 0x3C;
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, s8*, 7) = 0;
        M2C_FIELD(arg0, s8*, 0x8A) = 0;
        M2C_FIELD(arg0, s8*, 0x8B) = 0;
        M2C_FIELD(arg0, s8*, 0x8C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 9;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

void func_800F381C(void) {
}

#define func_80042C18 func_800F3824
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800F3854);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F38B0(void) {
    clear_object_slot();
}

#include "../shared/rock_15/func_800F38D0.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern s32 D_800F6F30[];

void func_800F3928(void* arg0) {
    u32 r;

    M2C_FIELD(arg0, s32**, 0x68) = D_800F6F30;
    M2C_FIELD(arg0, s32*, 0x20) = 0xFFFC0000;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, u8*, 7) = 1;
    r = random_byte();
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    M2C_FIELD(arg0, s16*, 0x8C) = ((u8)(r % 14) + 1) * 4;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern M2C_UNK D_800F6F40;
extern M2C_UNK D_800F6F50;

void func_800F39B0(void* arg0) {
    animate_object();
    ((void (*)(void*))move_object)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        set_animation(arg0, 1);
        play_sound(2, 0x74, arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800F6F50;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6F40;
        M2C_FIELD(arg0, s8*, 7) = -1;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();

void func_800F3A3C(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        // !FAKE: pin the counter to the second return register so its load schedules first
        register s32 c asm("$3") = M2C_FIELD(arg0, u8*, 0x6);
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFE0000;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x2000;
        M2C_FIELD(arg0, u8*, 0x6) = c + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK animate_object();                    /* extern */
M2C_UNK apply_object_motion(void*);          /* extern */

void func_800F3A90(void* arg0) {
    ((void (*)(void*))animate_object)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x74, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 4);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x14;
        M2C_FIELD(arg0, u8*, 0x7) = 0xA;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        return;
    }
    ((void (*)(void*))apply_object_motion)(arg0);
}

#include "common.h"
#define M2C_UNK s32

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F3B08(void* arg0) {
    ((void (*)())animate_object)();
    if (--F(arg0, s16*, 0x8C) == 0) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 6);
        F(arg0, u8*, 5) = 1;
        F(arg0, u8*, 6) = 0;
    }
}

#define func_800F38D0 func_800F3B5C
#define D_800F6FC0 D_800F6FD4
#include "../shared/rock_15/func_800F38D0.c"
#undef func_800F38D0
#undef D_800F6FC0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 random_byte();
void func_800F3824(struct X4_MainObj*);

void func_800F3BB4(u8* arg0) {
    u8 r;

    animate_object();
    func_800F3824((struct X4_MainObj*)arg0);
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    if (arg0[0x15] == 0) {
        *(s32*)(arg0 + 0x20) = -0x8000;
    } else {
        *(s32*)(arg0 + 0x20) = 0x8000;
    }
    *(s32*)(arg0 + 0x24) = 0;
    r = (u32)random_byte() % 5;
    arg0[6] = arg0[6] + 1;
    *(s16*)(arg0 + 0x8C) = (r << 5) + 0xC0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);
s32 random_byte();
void func_800F3824(struct X4_MainObj*);

void func_800F3C44(u8* arg0) {
    ((void (*)(void*))animate_object)(arg0);
    if (*(s16*)(arg0 + 0x8C) == 0) {
        if (*(s8*)(arg0 + 0x45) == 1) {
            func_800F3824((struct X4_MainObj*)arg0);
            if (random_byte() & 3) {
                ((void (*)(void*, s32))set_animation)(arg0, 7);
                *(s16*)(arg0 + 0x8C) = 0x3C;
                arg0[6] = arg0[6] + 1;
                return;
            }
            ((void (*)(void*, s32))set_animation)(arg0, 5);
            arg0[6] = 5;
        }
    } else {
        *(s16*)(arg0 + 0x8C) = *(s16*)(arg0 + 0x8C) - 1;
        ((void (*)(void*))move_object)(arg0);
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_49_train_soldier.c:train_soldier_jump_crouch, AGPL-3.0; proven shared with X6 by exact signature 7d7e8abd4964 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK animate_object();
void func_800F3CE4(struct X4_MainObj* self) {
    ((void (*)())animate_object)((struct X4_AnimatedObj*)self);
    if (self->animation_step.fields.event != 0) {
        self->action_phase++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK animate_object();                    /* extern */
M2C_UNK apply_object_motion(void*);          /* extern */

void func_800F3D28(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x67);
    if (temp_v1 == 1) {
        if (M2C_FIELD(arg0, s8*, 0x45) < 3) {
            animate_object();
        }
        // !FAKE: goto keeps the ==1 arm's jump to the shared tail call; an else-if chain moved bytes
        goto block_8;
    }
    if (temp_v1 == -1) {
        if (M2C_FIELD(arg0, s8*, 0x45) < 3) {
            animate_object(arg0);
        }
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            play_sound(2, 0x74, arg0);
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
            return;
        }
    }
block_8:
    apply_object_motion(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */

void func_800F3DDC(void* arg0) {
    animate_object();
    set_animation(arg0, 6);
    M2C_FIELD(arg0, s16*, 0x8C) = 0;
    M2C_FIELD(arg0, s8*, 5) = 2;
    M2C_FIELD(arg0, s8*, 6) = 1;
}

#define func_800F38D0 func_800F3E20
#define D_800F6FC0 D_800F6FEC
#include "../shared/rock_15/func_800F38D0.c"
#undef func_800F38D0
#undef D_800F6FC0

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK apply_object_motion(void*);

void func_800F3E78(void* arg0) {
    ((void (*)())animate_object)();
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        play_sound(2, 0x74, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 4);
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 6) += 1;
    } else {
        apply_object_motion(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();

void func_800F3EEC(void* arg0) {
    ((void (*)())animate_object)();
    if (F(arg0, s16*, 0x8C)++ >= 0x79) {
        F(arg0, u16*, 0x8C) = 0;
        F(arg0, u8*, 6) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F3F40(u8* arg0) {
    animate_object();
    ((void (*)(void*, M2C_UNK))set_animation)(arg0, 6);
    arg0[5] = 1;
    arg0[6] = 0;
}

#define func_8003744C func_800F3F7C
#define D_80073C1C D_800F6FF8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);
void func_800F3824(struct X4_MainObj*);
extern M2C_UNK D_800F6F44;
extern M2C_UNK D_800F6F54;

void func_800F3FB8(u8* arg0) {
    animate_object();
    move_object(arg0);
    if (*(s16*)(arg0 + 0xA) <= *(s16*)(arg0 + 0x8C)) {
        func_800F3824((struct X4_MainObj*)arg0);
        set_animation(arg0, 1);
        play_sound(2, 0x74, arg0);
        *(void**)(arg0 + 0x50) = &D_800F6F54;
        *(void**)(arg0 + 0x54) = &D_800F6F44;
        *(s16*)(arg0 + 0x8C) = 0;
        *(s8*)(arg0 + 7) = -1;
        arg0[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F4050(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        set_animation(arg0, 2);
        {
            // !FAKE: pin the constant to the first return register as retail does
            register s32 k asm("$2") = 4;
            M2C_FIELD(arg0, u8*, 0x5) = k;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0xA;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);
void func_800F3824(struct X4_MainObj*);
extern M2C_UNK D_800F6F44;
extern M2C_UNK D_800F6F54;

void func_800F40A8(void* arg0) {
    animate_object();
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 4) {
        func_800F3824(arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800F6F54;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6F44;
        set_animation(arg0, 0xB);
        {
            // !FAKE: constant 4 in the first return register
            register s32 x asm("$2") = 4;
            M2C_FIELD(arg0, u8*, 5) = x;
            M2C_FIELD(arg0, u8*, 6) = x;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        M2C_FIELD(arg0, s8*, 7) = -1;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);
void func_800F3824(struct X4_MainObj*);
extern M2C_UNK D_800F6F44;
extern M2C_UNK D_800F6F54;

void func_800F4134(void* arg0) {
    animate_object();
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        func_800F3824(arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800F6F54;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6F44;
        set_animation(arg0, 0x12);
        play_sound(2, 0x74, arg0);
        {
            // !FAKE: constant 4 in the first return register
            register s32 x asm("$2") = 4;
            M2C_FIELD(arg0, u8*, 5) = x;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        {
            // !FAKE: constant 2 in the second return register
            register s32 y asm("$3") = 2;
            M2C_FIELD(arg0, u8*, 6) = y;
        }
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        M2C_FIELD(arg0, s8*, 7) = -1;
    }
}

#define func_8003744C func_800F41D4
#define D_80073C1C D_800F7048
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800F3824(struct X4_MainObj*);
void func_800F5490(void*);
extern s8 D_800CCF5C;

void func_800F4210(void* arg0) {
    s8* p;

    animate_object();
    func_800F5490(arg0);
    if (D_800CCF5C / 2 < p[0x5C]) {
        if (M2C_FIELD(arg0, s16*, 0x8C)++ < 0x5B) {
            return;
        }
    } else {
        if (M2C_FIELD(arg0, s16*, 0x8C)++ < 0x33) {
            return;
        }
    }
    func_800F3824(arg0);
    set_animation(arg0, 0xE);
    {
        // !FAKE: increment temp in the first return register
        register s32 x asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, u8*, 6) = x;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800F1DA8(void*, s32, s32);

void func_800F42D0(void* arg0) {
    animate_object();
    {
        s8 v = SB(arg0, 0x45);
        if (v == 1) {
            func_800F1DA8(arg0, 3, 1);
        } else if (v == 2) {
            ((void (*)(void*, s32))set_animation)(arg0, 2);
            H(arg0, 0x8C) = 0;
            B(arg0, 0x6)--;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800F3824(struct X4_MainObj*);
extern s8 D_800CCF5C;

void func_800F433C(void* arg0) {
    s8* obj = arg0;
    s8* other;
    s32 c;
    u16 t;
    s32 n;

    ((void (*)())animate_object)();
    if (D_800CCF5C / 2 < other[0x5C]) {
        t = *(u16*)(obj + 0x8C);
        n = t + 1;
        c = (s16)t < 0x5B;
    } else {
        t = *(u16*)(obj + 0x8C);
        n = t + 1;
        c = (s16)t < 0x33;
    }
    *(u16*)(obj + 0x8C) = n;
    if (c == 0) {
        obj[7] = 0xA;
        func_800F3824((struct X4_MainObj*)obj);
        ((void (*)(void*, s32))set_animation)(obj, 0xD);
        ((u8*)obj)[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800F1DA8(void*, s32, s32);

void func_800F43FC(void* arg0) {
    animate_object();
    {
        s8 v = SB(arg0, 0x45);
        if (v == 1) {
            func_800F1DA8(arg0, 3, 1);
        } else if (v == 2) {
            ((void (*)(void*, s32))set_animation)(arg0, 5);
            H(arg0, 0x8C) = 0;
            B(arg0, 0x6)--;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800F3824(struct X4_MainObj*);
extern s8 D_800CCF5C;
extern s32 D_800F6F4C;
extern s32 D_800F6F5C;

void func_800F4468(void* arg0) {
    s8* p;

    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 0x10) {
        M2C_FIELD(arg0, s32**, 0x50) = &D_800F6F5C;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800F6F4C;
        M2C_FIELD(arg0, u16*, 0xE) += 0x10;
    }
    if (D_800CCF5C / 2 < p[0x5C]) {
        if (M2C_FIELD(arg0, s16*, 0x8C)++ < 0x5B) {
            return;
        }
    } else {
        if (M2C_FIELD(arg0, s16*, 0x8C)++ < 0x33) {
            return;
        }
    }
    M2C_FIELD(arg0, u8*, 7) = 0xA;
    func_800F3824(arg0);
    set_animation(arg0, 0xF);
    {
        // !FAKE: increment temp in the first return register
        register s32 x asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, u8*, 6) = x;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800F1DA8(void*, s32, s32);

void func_800F455C(void* arg0) {
    s8 st;

    ((void (*)())animate_object)();
    st = M2C_FIELD(arg0, s8*, 0x45);
    if (st == 1) {
        M2C_FIELD(arg0, u16*, 0xE) -= 0x10;
        func_800F1DA8(arg0, 3, 1);
        M2C_FIELD(arg0, u16*, 0xE) += 0x10;
    } else if (st == 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 0xC);
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 6) -= 1;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F6F34;

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800F45E0(void* arg0) {
    s32 angle;
    u8 r;

    F(void*, 0x68) = &D_800F6F34;
    r = (u32)random_byte() % 5;
    angle = ratan2((s16)(background_objects[0].unk2A + 0x70) - F(s16, 0xE),
                   (s16)(background_objects[0].unk26 + (r << 5) + 0x10) -
                       F(s16, 0xA));
    F(s32, 0x20) = rcos(angle) << 6;
    F(s32, 0x24) = -rsin(angle) << 6;
    F(s16, 0x8C) = 0;
    F(u8, 7) = 1;
    F(u8, 6)++;
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 random_byte();

void func_800F46C0(u8* arg0) {
    ((void (*)(void*))animate_object)(arg0);
    if (*(s8*)(arg0 + 0x45) == 1) {
        arg0[7] = 0xA;
        *(s32*)(arg0 + 0x28) = 0;
        *(s16*)(arg0 + 0x8C) = 0x30;
        *(s16*)(arg0 + 0x8E) = 0;
        arg0[0x92] = 0;
        if (!(random_byte() & 1)) {
            *(s32*)(arg0 + 0x20) = 0x20000;
            arg0[6] = arg0[6] + 1;
        } else {
            *(s32*)(arg0 + 0x20) = -0x20000;
            arg0[6] = arg0[6] + 2;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(s32);

#define B8(o) (*(s8*)(arg0 + (o)))
#define U8(o) (*(u8*)(arg0 + (o)))
#define H16(o) (*(s16*)(arg0 + (o)))
#define W32(o) (*(s32*)(arg0 + (o)))

void func_800F4740(s32 arg0) {
    animate_object();
    {
        // !FAKE: depin: dropping it breaks the match (35/39)
        register s32 t asm("$2") = B8(0x92);
        if (t != 0) {
            B8(0x92) = U8(0x92) - 1;
            return;
        }
    }
    if (H16(0x8C) != 0) {
        H16(0x8C) = H16(0x8C) - 1;
        move_object(arg0);
    }
    if ((U8(0x70) & 1) || (H16(0x8C) == 0)) {
        W32(0x20) = 0xFFFE0000;
        H16(0x8C) = 0x30;
        B8(0x92) = 0x3C;
        U8(0x6) = U8(0x6) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(s32);

void func_800F47DC(void* arg0) {
    ((void (*)())animate_object)(arg0);
    if (*(s8*)((u8*)arg0 + 0x92) != 0) {
        (*(s8*)((u8*)arg0 + 0x92))--;
        return;
    }
    if (*(s16*)((u8*)arg0 + 0x8C) != 0) {
        (*(s16*)((u8*)arg0 + 0x8C))--;
        move_object(arg0);
    }
    if ((*((u8*)arg0 + 0x70) & 2) || (*(s16*)((u8*)arg0 + 0x8C) == 0)) {
        *(s32*)((u8*)arg0 + 0x20) = 0x20000;
        *(s16*)((u8*)arg0 + 0x8C) = 0x30;
        *(s8*)((u8*)arg0 + 0x92) = 0x3C;
        (*((u8*)arg0 + 6))--;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
s32 random_byte();        /* extern */
extern M2C_UNK D_800F6F44;

void func_800F4878(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 7) = 0xA;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F6F44;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 6) =
            (u8)(M2C_FIELD(arg0, u8*, 6) + ((random_byte() & 1) + 1));
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern s16 D_80097222;

void func_800F48E4(void* arg0) {
    animate_object();
    {
        // !FAKE: depin: dropping it breaks the match (32/36)
        register s32 t asm("$2") = M2C_FIELD(arg0, s16*, 0x8C);
        if (t != 0) {
            M2C_FIELD(arg0, s16*, 0x8C) = M2C_FIELD(arg0, u16*, 0x8C) - 1;
            ((void (*)(void*))move_object)(arg0);
            if (M2C_FIELD(arg0, s16*, 0x8C) != 0) {
                return;
            }
        }
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s16*, 0x8C) = 0xC;
    if (M2C_FIELD(arg0, s16*, 0xE) < D_80097222 + 0x78) {
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
    } else {
        M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(s32);

void func_800F4974(u8* arg0) {
    animate_object();
    {
        // !FAKE: call arg set before the zero test, as retail fills the delay slot
        register u8* a0 asm("$4") = arg0;
        if (*(s16*)(arg0 + 0x8C) != 0) {
            *(s16*)(arg0 + 0x8C) = *(s16*)(arg0 + 0x8C) - 1;
            ((void (*)(void*))move_object)(a0);
            if (*(s16*)(arg0 + 0x8C) != 0) {
                return;
            }
        }
    }
    *(s32*)(arg0 + 0x24) = 0;
    *(s16*)(arg0 + 0x8C) = 0x30;
    if (*(s16*)(arg0 + 0xA) < D_8009721E + 0x70) {
        *(s32*)(arg0 + 0x20) = 0x20000;
    } else {
        *(s32*)(arg0 + 0x20) = 0xFFFE0000;
    }
    do {
        arg0[6] = arg0[6] - 1;
    } while (0);
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();

void func_800F4A04(void* arg0) {
    // !FAKE: arm value in v0 as retail
    register s32 var_v0 asm("$2");
    // !FAKE: field value in v0 as retail
    register s32 temp_v0_2 asm("$2");
    u16 temp_v0_3;

    animate_object();
    {
        // !FAKE: load lands in v0 as retail
        register s32 temp_v0 asm("$2");
        temp_v0 = M2C_FIELD(arg0, u8*, 0x93);
        M2C_FIELD(arg0, u8*, 0x93) = temp_v0 + 1;
        if ((s8)temp_v0 >= 0x33) {
            temp_v0_2 = M2C_FIELD(arg0, s32*, 0x20);
            if (temp_v0_2 == 0) {
                temp_v0_2 = M2C_FIELD(arg0, s32*, 0x24);
                if (temp_v0_2 < 0) {
                    M2C_FIELD(arg0, s16*, 0x90) = 0;
                } else {
                    M2C_FIELD(arg0, s16*, 0x90) = 1;
                }
            } else {
                if (temp_v0_2 < 0) {
                    var_v0 = 2;
                } else {
                    var_v0 = 3;
                }
                M2C_FIELD(arg0, s16*, 0x90) = var_v0;
            }
            temp_v0_3 = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, u8*, 0x93) = 0;
            M2C_FIELD(arg0, u16*, 0x94) = temp_v0_3;
            if ((s16)temp_v0_3 >= D_800970AE) {
                set_animation(arg0, 0x13);
            }
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();
extern s32 D_800F6F60[];
extern M2C_UNK D_800F6F64;

void func_800F4AC0(u8* arg0) {
    s8 st;

    animate_object();
    st = arg0[0x45];
    if (st == 2) {
        *(s32**)(arg0 + 0x50) = D_800F6F60;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = -0x1000;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        arg0[6]++;
    } else if (st == 1) {
        *(s32**)(arg0 + 0x50) = &D_800F6F64;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = 0x1000;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        arg0[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800F4B3C(void* arg0) {
    if (M2C_FIELD(arg0, s32*, 0x24) < -0x40000) {
        M2C_FIELD(arg0, s32*, 0x24) = -0x40000;
    }
    if (M2C_FIELD(arg0, s32*, 0x24) > 0x40000) {
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
    }
    apply_object_motion(arg0);
    {
        // !FAKE: velocity read lands in the first return register as in retail
        register s32 vx asm("$2") = M2C_FIELD(arg0, s32*, 0x24);
        if (vx > 0) {
            if (M2C_FIELD(arg0, u8*, 0x70) & 4) {
                play_sound(2, 0x7A, arg0);
                func_80029478(0x1E, 2, 2);
                M2C_FIELD(arg0, u8*, 0x93) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
                M2C_FIELD(arg0, s32*, 0x2C) = 0;
                M2C_FIELD(arg0, u8*, 0x6)++;
            }
        } else if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            play_sound(2, 0x7A, arg0);
            func_80029478(0x1E, 2, 2);
            M2C_FIELD(arg0, u8*, 0x93) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, u8*, 0x6)++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);

void func_800F4C2C(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 0x93) < 0x32) {
        M2C_FIELD(arg0, s8*, 0x93) = (s8)((u8)M2C_FIELD(arg0, s8*, 0x93) + 1);
        return;
    }
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
        // !FAKE: compare operand in v0 as retail
        register s32 a asm("$2") = M2C_FIELD(arg0, s16*, 0xE);
        var_v0 = a < M2C_FIELD(arg0, s16*, 0x94);
    } else {
        var_v0 = M2C_FIELD(arg0, s16*, 0xE) > M2C_FIELD(arg0, s16*, 0x94);
    }
    {
        u16 t = M2C_FIELD(arg0, u16*, 0x94);
        if (var_v0 != 0) {
            M2C_FIELD(arg0, s16*, 0xE) = t;
            M2C_FIELD(arg0, s8*, 0x93) = 0;
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F4CC0(void* arg0) {
    if ((s8)M2C_FIELD(arg0, u8*, 0x93)++ >= 0x33) {
        if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x14);
        }
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();
extern M2C_UNK D_800F6F64;

void func_800F4D28(u8* arg0) {
    s16 mode;
    s32 vy;
    s8 st;

    animate_object();
    st = arg0[0x45];
    if (st == 1) {
        *(s32**)(arg0 + 0x50) = &D_800F6F64;
        arg0[6] = arg0[7];
        mode = *(s16*)(arg0 + 0x90);
        if (mode == 0) {
            vy = 0xFFFD0000;
            // !FAKE: m2c block order, both vertical arms share the store block
            goto vert;
        }
        if (mode == st) {
            vy = 0x30000;
        vert:
            *(s32*)(arg0 + 0x20) = 0;
            *(s32*)(arg0 + 0x24) = vy;
            return;
        }
        {
            // !FAKE: retail keeps the compare constant in the first return register
            register s32 k asm("$2") = 2;
            // !FAKE: depin: dropping it breaks the match (29/32)
            register s32 h asm("$2");
            if (mode == k) {
                h = 0xFFFE0000;
            } else {
                h = 0x20000;
            }
            *(s32*)(arg0 + 0x20) = h;
        }
        *(s32*)(arg0 + 0x24) = 0;
    }
}

#define func_8003744C func_800F4DA8
#define D_80073C1C D_800F7098
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
extern s32 D_800F6F60[];

void func_800F4DE4(void* arg0) {
    u8 t;
    void* p;

    animate_object();
    t = M2C_FIELD(arg0, u8*, 2);
    if ((u32)(t - 6) < 2U && M2C_FIELD(arg0, s8*, 0x45) == 0x10) {
        M2C_FIELD(arg0, s32**, 0x50) = &D_800F6F60[(s8)t];
    }
    p = M2C_FIELD(arg0, void**, 0x7C);
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(p, u8*, 7)--;
    }
}

#include "common.h"

void func_800F4E74(void) {
}

#include "common.h"

void func_800F4E7C(void) {
}

#define func_8003744C func_800F4E84
#define D_80073C1C D_800F70A4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();

void func_800F4EC0(u8* arg0) {
    u8* temp_s1;

    temp_s1 = *(u8**)(arg0 + 0x7C);
    ((void (*)(u8*))animate_object)(arg0);
    if (--*(s16*)(arg0 + 0x8C) == 0x78) {
        arg0[6]++;
        temp_s1[7]--;
    }
}

#include "../shared/rock_15/func_800F4F34.c"

#define func_800F4F34 func_800F4F78
#include "../shared/rock_15/func_800F4F34.c"
#undef func_800F4F34

#define func_8003744C func_800F4FBC
#define D_80073C1C D_800F70B0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F4FF8(void* arg0) {
    animate_object();
    move_object((s32)arg0);
    {
        // !FAKE: retail reads the state field into the first return register
        register s32 st asm("$2") = M2C_FIELD(arg0, s16*, 0x8C);
        if (st == 0) {
            if (M2C_FIELD(arg0, s16*, 0xA) >=
                background_objects[0].unk26 + 0x30) {
                return;
            }
            if (background_objects[0].unk2A + 0xB0 >=
                M2C_FIELD(arg0, s16*, 0xE)) {
                return;
            }
        } else if (M2C_FIELD(arg0, s16*, 0xA) >= D_8009721E + 0x30) {
            return;
        }
    }
    M2C_FIELD(arg0, s16*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
extern s32 D_800F6F84;

void func_800F509C(u8* arg0) {
    u8* temp_s1;
    u16 temp_v0;

    temp_s1 = *(u8**)(arg0 + 0x7C);
    animate_object();
    if (*(s16*)(arg0 + 0x8C) == 0x18) {
        set_animation(arg0, 0xA);
    }
    temp_v0 = *(u16*)(arg0 + 0x8C);
    *(s16*)(arg0 + 0x8C) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0x1F) {
        temp_s1[0x8B] = 1;
        *(s32**)(arg0 + 0x50) = &D_800F6F84;
        *(s32*)(arg0 + 0x24) = 0;
        if (*(s8*)(arg0 + 2) == 0xB) {
            *(s32*)(arg0 + 0x20) = 0x100000;
        } else {
            *(s32*)(arg0 + 0x20) = 0xFFF00000;
        }
        play_sound(2, 0x72, arg0);
        ((void (*)(s32))start_pad_vibration)(6);
        arg0[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F5164(void* arg0) {
    s16 y;

    animate_object();
    move_object((s32)arg0);
    y = M2C_FIELD(arg0, s16*, 0xA);
    if (y < background_objects[0].unk26 - 0x50 ||
        background_objects[0].unk24 + 0x190 < y) {
        M2C_FIELD(arg0, u8*, 0x4) = 2;
    }
}

#include "common.h"

void func_800F51CC(void) {
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(s32);
M2C_UNK func_80049D90(void*);

void func_800F51D4(u8* arg0) {
    animate_object();
    ((void (*)(void*))move_object)(arg0);
    if (arg0[0x70] != 0) {
        func_80049D90(arg0);
        arg0[4] = 2;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F5220(void* arg0, void* arg1) {
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
    if (M2C_FIELD(arg1, s8*, 7) < 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"

void func_800F5288(void* arg0, void* arg1) {
    u8* p;

    if (*(s8*)((u8*)arg1 + 7) > 0) {
        *(s16*)((u8*)arg0 + 0x54) = 3;
        *(s16*)((u8*)arg0 + 0x56) = 8;
        *(s16*)((u8*)arg0 + 0x58) = 0xA;
        *(s32*)((u8*)arg0 + 8) = *(s32*)((u8*)arg1 + 8);
        do {
        } while (0);
        {
            s32 c = *(s32*)((u8*)arg1 + 0xC);
            *(u8*)((u8*)arg0 + 4) = 1;
            *(u8*)((u8*)arg0 + 5) = 0;
            *(s32*)((u8*)arg0 + 0xC) = c;
        }
        return;
    }
    if (*(s16*)((u8*)arg0 + 0x56) != 0) {
        if (--*(s16*)((u8*)arg0 + 0x56) & 1) {
            p = *(u8**)((u8*)arg0 + 0x5C);
            *(s32*)((u8*)arg0 + 8) = *(s32*)(p + 0x18);
            *(s32*)((u8*)arg0 + 0xC) = *(s32*)(p + 0x1C);
        }
    } else {
        *(u8*)((u8*)arg0 + 5) += 1;
    }
}

#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F532C(void* arg0, void* arg1) {
    void* temp_v1;

    if (M2C_FIELD(arg1, s8*, 7) > 0) {
        s32 y;
        M2C_FIELD(arg0, s16*, 0x54) = 3;
        M2C_FIELD(arg0, s16*, 0x56) = 8;
        M2C_FIELD(arg0, s16*, 0x58) = 0xA;
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg1, s32*, 8);
        y = M2C_FIELD(arg1, s32*, 0xC);
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s32*, 0xC) = y;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x58) != 0) {
        s32 y;
        temp_v1 = M2C_FIELD(arg0, void**, 0x5C);
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(temp_v1, s32*, 0x18);
        y = M2C_FIELD(temp_v1, s32*, 0x1C);
        M2C_FIELD(arg0, s16*, 0x58) = M2C_FIELD(arg0, s16*, 0x58) - 1;
        M2C_FIELD(arg0, s32*, 0xC) = y;
        return;
    }
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 7) {
        M2C_FIELD(arg1, s8*, 7) = 0;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F53CC(void* arg0) {
    s32 t;

    ((void (*)())animate_object)();
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 8) - 0x8000;
    } else {
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 8) + 0x8000;
    }
    t = M2C_FIELD(arg0, u8*, 0x92) - 1;
    M2C_FIELD(arg0, u8*, 0x92) = t;
    if ((s8)t == 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_800743DC;
        M2C_FIELD(arg0, u8*, 5) = 2;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        if (M2C_FIELD(arg0, s8*, 0x67) != 0) {
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFE0000;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x2000;
            M2C_FIELD(arg0, u8*, 6) = 0;
            return;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 5);
        M2C_FIELD(arg0, u8*, 6) = 1;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800F70C0;

void func_800F5490(void* arg0) {
    u8 temp_v1;

    if (!(*(u8*)&D_80097420 & 3)) {
        temp_v1 = *(M2C_FIELD(arg0, s8*, 0x93) + (u8*)&D_800F70C0);
        M2C_FIELD(arg0, s8*, 0x93) =
            (s8)(((u8)M2C_FIELD(arg0, s8*, 0x93) + 1) & 0xF);
        M2C_FIELD(arg0, u16*, 0xE) =
            (u16)(M2C_FIELD(arg0, u16*, 0xE) + (s8)temp_v1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_15/nonmatchings/E9860", func_800F54E8);
// clang-format on
