// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800E9BD8);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EA03C);
// clang-format on

#define func_800F0CF4 func_800EA39C
#define g_Player g_Player
#include "../shared/rock_07/func_800F0CF4.c"
#undef func_800F0CF4
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA750(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x1C) = 0;
    M2C_FIELD(arg0, s8*, 0x1E) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* enemy_slot_alloc();
M2C_UNK func_8003D308(M2C_UNK, u8);

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_8009728E;
extern u8 D_800FB6F8[];

void func_800EA770(struct X4_PlayerObj* self) {
    struct X4_AnimatedObj* obj;
    s32 i;
    s32 n;
    u8 b;
    struct X4_PlayerObj* pl;

    if (self->character == 0) {
        struct X4_BackgroundObj* bg = background_objects;

        *(s16*)&bg[1].unk40 = -0x1540;
        *(s16*)&bg[1].unk42 = -0x50;
        bg[1].unk4 = 2;
        bg[1].unk3 = 0;
        bg[1].unk4C = 1;
        i = 0;
        do {
            obj = enemy_slot_alloc();
            n = i + 1;
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 0x1D;
                obj->unk2 = 0xA;
                obj->x_pos.i.hi = n * 0xA0 + 0x1520;
                obj->y_pos.u.hi = self->y_pos.u.hi;
            }
            i = n;
        } while (i < 5);
        self->action = 2;
        func_8003D308(0x14, g_Player.facing);
    } else if (self->character == 1) {
        struct X4_BackgroundObj* bg = background_objects;

        *(s16*)&bg[1].unk40 = -0x17C0;
        *(s16*)&bg[1].unk42 = -0x50;
        bg[1].unk4 = 2;
        bg[1].unk3 = 0;
        bg[1].unk4C = 1;
        i = 0;
        do {
            obj = enemy_slot_alloc();
            n = i + 1;
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 0x1D;
                obj->unk2 = 0xA;
                obj->x_pos.i.hi = n * 0xB0 + 0x1790;
                obj->y_pos.u.hi = self->y_pos.u.hi;
            }
            i = n;
        } while (i < 5);
        self->action = 3;
    } else if (self->character == 2) {
        struct X4_BackgroundObj* bg = background_objects;

        *(s16*)&bg[1].unk40 = -0x1B70;
        *(s16*)&bg[1].unk42 = -0x50;
        bg[1].unk4 = 2;
        bg[1].unk3 = 0;
        bg[1].unk4C = 1;
        i = 0;
        do {
            obj = enemy_slot_alloc();
            n = i + 1;
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 0x1D;
                obj->unk2 = 0xA;
                obj->x_pos.i.hi = n * 0xA0 + 0x1B50;
                obj->y_pos.u.hi = self->y_pos.u.hi;
            }
            i = n;
        } while (i < 5);
        self->action = 4;
    } else if (self->character == 10) {
        self->unk60 = 0x7F;
        self->y_pos.u.hi = 0x2F8 - D_8009728E;
        self->unk50 = D_800FB6F8;
        self->action = 5;
    }
    pl = &g_Player;
    self->invincibility_timer = 0;
    b = M2C_FIELD(pl, u8*, 0x14);
    {
        // !FAKE: depin: dropping it breaks the match (163/175)
        register s32 c asm("$2") = 5;
        self->unk16 = c;
    }
    self->x_vel.val = 0;
    self->y_vel.val = 0;
    self->facing = 0;
    self->collision_flags = 0;
    self->input.buttons.held = 0;
    self->input.buttons.previous = 0;
    self->state = 1;
    self->action_phase = 0;
    self->action_timer = 0;
    M2C_FIELD(self, u8*, 0x80) = 0;
    M2C_FIELD(self, u8*, 0x14) = b;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_80030ECC(void*);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"
extern u16 D_800FB700[];
extern void (*D_800FB714[])(struct X4_MainObj*);

#define F81(p) (((u8*)(p))[0x81])

void func_800EAA2C(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    if (D_80097174 == 0) {
        D_800FB714[arg0->action](arg0);
        func_80030ECC(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EAB68(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    if (!(D_80097420.frame_counter & 1)) {
        background_objects[1].unk42++;
    }
    if (--arg0->unk7E == 0) {
        func_8002943C(0xA, 2, 2);
        arg0->unk7E = 0xA;
    }
    if ((s16)background_objects[1].unk42 >= -0x1F) {
        *(s16*)&background_objects[1].unk42 = -0x20;
        arg0->action_phase++;
        play_sound(5, 3, arg0);
        arg0->unk7C = 0;
    }
}

#include "../shared/rock_22/func_800EACFC.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EAE40(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    if ((s16)arg0->unk7C++ > 0x3C) {
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        play_sound(5, 1, arg0);
        ((void (*)(s32))start_pad_vibration)(4);
        arg0->action_phase++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EAF94(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    background_objects[1].unk42++;
    if (--arg0->unk7E == 0) {
        func_8002943C(0xA, 2, 2);
        arg0->unk7E = 0xA;
    }
    if ((s16)background_objects[1].unk42 >= 0x60) {
        background_objects[1].unk42 = 0x60;
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        arg0->action_phase++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EB104(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    background_objects[1].unk42--;
    if (--arg0->unk7E == 0) {
        func_8002943C(0xA, 2, 2);
        arg0->unk7E = 0xA;
    }
    if ((s16)background_objects[1].unk42 < -0x1F) {
        *(s16*)&background_objects[1].unk42 = -0x20;
        arg0->unk7C = 0;
        arg0->action_phase++;
        play_sound(5, 3, arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EB27C(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    if ((s16)arg0->unk7C++ > 0xB4) {
        arg0->unk7C = 0;
        arg0->action_phase++;
        func_8002943C(0x3C, 3, 2);
    }
}
#undef F81

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK start_pad_vibration(M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EB3B8(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    if ((s16)arg0->unk7C++ >= 0x3D) {
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        arg0->action_phase = 5;
        play_sound(5, 1, arg0);
        start_pad_vibration(4);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EB4FC(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    if (!(D_80097420.frame_counter & 1)) {
        background_objects[1].unk42++;
    }
    if (--arg0->unk7E == 0) {
        func_8002943C(0xA, 2, 2);
        arg0->unk7E = 0xA;
    }
    if ((s16)background_objects[1].unk42 >= -0x1F) {
        *(s16*)&background_objects[1].unk42 = -0x20;
        arg0->unk7C = 0;
        arg0->action_phase++;
        play_sound(5, 3, arg0);
    }
}

#define func_800EACFC func_800EB690
#define D_80097420 D_80097420
#include "../shared/rock_22/func_800EACFC.c"
#undef func_800EACFC
#undef D_80097420

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EB7D4(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    if ((s16)arg0->unk7C++ > 0x3C) {
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        arg0->action_phase++;
        play_sound(5, 1, arg0);
        start_pad_vibration(4);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EB91C(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
    background_objects[1].unk42++;
    if (--arg0->unk7E == 0) {
        func_8002943C(0xA, 2, 2);
        arg0->unk7E = 0xA;
    }
    if ((s16)background_objects[1].unk42 >= 0xE0) {
        background_objects[1].unk42 = 0xE0;
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        arg0->action_phase++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_800EBA8C(struct X4_MainObj* arg0) {
    struct X4_PlayerObj* pl = &g_Player;
    struct X4_BackgroundObj* bg = background_objects;

    if (pl->y_pos.i.hi < bg[0].unk2A - 0x10) {
        pl->y_pos.i.hi = bg[0].unk2A - 0x10;
    }
    if (bg[0].unk2A >= 0x1B1) {
        if (!(D_80097420.frame_counter & 1)) {
            bg[1].unk42++;
        }
        if (!(D_80097420.frame_counter & 3)) {
            bg[0].unk2A--;
            bg[0].unk28--;
        }
    } else if (!(D_80097420.frame_counter & 3)) {
        if ((s16)bg[1].unk42 < 0x1E0) {
            bg[1].unk42++;
        }
        bg[0].unk2A--;
        bg[0].unk28--;
    }
    if (--arg0->unk7E == 0) {
        func_8002943C(0xA, 2, 2);
        arg0->unk7E = 0xA;
    }
    if (background_objects[0].unk2A <= 0) {
        background_objects[0].unk2A = 0;
        background_objects[0].unk28 = 0;
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        play_sound(5, 3, arg0);
        arg0->action_phase++;
    }
}

#define func_80048DC8 func_800EBBF8
#define D_80077BC0 D_800FB708
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EBC44(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EBC64(void) {
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s16 D_800970AA;
extern void (*D_800FB72C[])(void*);

void func_800EBC6C(s8* arg0) {
    D_800FB72C[arg0[6]](arg0);
    if (D_800970AA >= 0x1681) {
        arg0[4] = 2;
        play_sound(5, 3, arg0);
        D_8009724F = 0;
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EBCE4(void* arg0) {
    if (D_800970A5 == 0x14) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

void func_800EBD14(u8* arg0) {
    s16 t;

    t = (*(s16*)(arg0 + 0x7C))++;
    if (t >= 0x65) {
        D_8009724F = 1;
        *(u16*)(arg0 + 0x7C) = 0;
        *(u16*)(arg0 + 0x7E) = 1;
        ((void (*)(s32, s32, void*))play_sound)(5, 1, arg0);
        ((void (*)(s32))start_pad_vibration)(4);
        arg0[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003D308(M2C_UNK, u8);

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800FB750[])(struct X4_MainObj*);

void func_800EBD94(struct X4_MainObj* arg0) {
    struct X4_PlayerObj* pl;

    D_800FB750[arg0->action_phase](arg0);
    if (M2C_FIELD(arg0, s8*, 0x80) == 0) {
        if (g_Player.x_pos.i.hi >= 0x1AF1) {
            M2C_FIELD(arg0, s8*, 0x80) = 1;
            background_objects[0].unk2E -= 0x10;
        }
    }
    pl = &g_Player;
    if (pl->x_pos.i.hi >= 0x1B41 && pl->y_pos.i.hi >= 0x241 &&
        arg0->action_phase < 9) {
        arg0->action_phase = 9;
        arg0->unk7C = 0;
        play_sound(5, 1, arg0);
        start_pad_vibration(4);
        func_8003D308(0x14, pl->facing);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_8003D308(M2C_UNK, u8);
extern struct X4_PlayerObj g_Player;

void func_800EBE94(struct X4_MainObj* arg0) {
    if (g_Player.x_pos.i.hi >= 0x17F1) {
        D_8009721E = 0x17C0;
        func_8003D308(0x14, g_Player.facing);
        arg0->action_phase++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800EBEF4(struct X4_MainObj* arg0) {
    if ((D_800970A5 == 0x14) &&
        (background_objects[0].unk26 == background_objects[0].unk1E)) {
        background_objects[1].unk3 = 1;
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        arg0->action_phase++;
        play_sound(5, 1, arg0);
        ((void (*)(s32))start_pad_vibration)(4);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

void func_800EBF6C(void* arg0) {
    s32 temp_v0;

    if (!(D_80097420.frame_counter & 1)) {
        background_objects[1].unk42 = background_objects[1].unk42 - 1;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 0x7E) - 1;
    M2C_FIELD(arg0, u16*, 0x7E) = temp_v0;
    if ((temp_v0 << 0x10) == 0) {
        func_8002943C(0xA, 2, 2);
        M2C_FIELD(arg0, u16*, 0x7E) = 0xA;
    }
    if ((s16)background_objects[1].unk42 < -0x1F) {
        *(s16*)&background_objects[1].unk42 = -0x20;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        play_sound(5, 3, arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800EC02C(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0xB5) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_8002943C(0x3C, 3, 2);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);        /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC084(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, s16*, 0x7E) = 0xA;
        M2C_FIELD(arg0, s8*, 6) = 5;
        play_sound(5, 1, arg0);
        start_pad_vibration(4);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D330();
extern struct X4_BackgroundObj background_objects[3];

void func_800EC0E8(struct X4_MainObj* arg0) {
    if ((s16)background_objects[1].unk42 >= -0x4F) {
        background_objects[1].unk42--;
        if (arg0->unk7C == 0) {
            func_8002943C(0xA, 2, 2);
            arg0->unk7C = 0xA;
        } else {
            arg0->unk7C--;
        }
        return;
    }
    play_sound(5, 3, arg0);
    func_8003D330();
    background_objects[0].unk26 = 0x1AD0;
    background_objects[0].unk24 = 0x1CC0;
    background_objects[1].unk3 = 0;
    background_objects[0].unk2E += 0x10;
    arg0->state = 2;
}

#define func_8003744C func_800EC1A4
#define D_80073C1C D_800FB778
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, u8);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_800EC1E0(void* arg0) {
    if (g_Player.x_pos.i.hi >= 0x1C21) {
        background_objects[0].unk26 = 0x1B70;
        background_objects[0].unk2A = 0x1E0;
        background_objects[0].unk28 = 0x1E0;
        func_8003D308(0x14, g_Player.facing);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);        /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC250(void* arg0) {
    if (D_800970A5 == 0x14) {
        D_8009724F = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0xA;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        play_sound(5, 1, arg0);
        start_pad_vibration(4);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

void func_800EC2B4(void* arg0) {
    if (!(D_80097420.frame_counter & 1)) {
        struct X4_BackgroundObj* bg = background_objects;
        M2C_FIELD(bg, u16*, 0x96) = M2C_FIELD(bg, u16*, 0x96) + 1;
    }
    M2C_FIELD(arg0, s16*, 0x7E) = M2C_FIELD(arg0, s16*, 0x7E) - 1;
    if (M2C_FIELD(arg0, s16*, 0x7E) == 0) {
        func_8002943C(0xA, 2, 2);
        M2C_FIELD(arg0, s16*, 0x7E) = 0xA;
    }
    {
        struct X4_BackgroundObj* bg = background_objects;
        if (M2C_FIELD(bg, s16*, 0x96) >= -0x1F) {
            play_sound(5, 3, arg0);
            M2C_FIELD(bg, s16*, 0x96) = -0x20;
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8003D330();                          /* extern */

void func_800EC370(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_8002943C(0x3C, 3, 2);
        func_8003D330();
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);        /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC3D0(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, s16*, 0x7E) = 0xA;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        play_sound(5, 1, arg0);
        start_pad_vibration(4);
    }
}

#include "common.h"

void func_800EC438(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800EC440(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0xB5) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_8002943C(0x3C, 3, 2);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC498(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0U;
        M2C_FIELD(arg0, s16*, 0x7E) = 0xA;
        M2C_FIELD(arg0, s8*, 6) = 5;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D330();
extern struct X4_BackgroundObj background_objects[3];

void func_800EC4D4(void* arg0) {
    struct X4_BackgroundObj* bg = background_objects;

    if (M2C_FIELD(bg, s16*, 0x96) >= -0x4F) {
        M2C_FIELD(bg, s16*, 0x96) = M2C_FIELD(bg, s16*, 0x96) - 1;
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_8002943C(0xA, 2, 2);
            M2C_FIELD(arg0, s16*, 0x7C) = 0xA;
            return;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = M2C_FIELD(arg0, s16*, 0x7C) - 1;
        return;
    }
    func_8003D330();
    M2C_FIELD(bg, s16*, 0x24) = 0x1C00;
    M2C_FIELD(bg, u8*, 0x57) = 0;
    M2C_FIELD(arg0, u8*, 4) = 2;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_8009728E;

void func_800EC56C(void* arg0) {
    M2C_FIELD(arg0, s16*, 0xE) = (s16)(0x2F8 - D_8009728E);
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800FB700[];

#define F81(p) (((u8*)(p))[0x81])

void func_800EC584(struct X4_MainObj* arg0) {
    u32 t = D_80097420.frame_counter;

    if (t == t / 10 * 10) {
        F81(arg0) = (F81(arg0) + 1) & 3;
        if (arg0->unk2 == 0) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1540;
        } else if (arg0->unk2 == 1) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x17C0;
        } else if (arg0->unk2 == 2) {
            background_objects[1].unk40 = D_800FB700[F81(arg0)] - 0x1B70;
        }
        background_objects[1].unk4C = 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj g_Player;
extern s32 D_800FB7A0;
extern s32 D_800FB7A4;
extern s32 D_800FB7A8;
extern s32 D_800FBA80;

void func_800EC670(void* self) {
    u8 t;
    s32 v;

    M2C_FIELD(self, void**, 0x30) = &D_800FBA80;
    t = g_Player.bg_offset;
    M2C_FIELD(self, u8*, 0x16) = 5;
    M2C_FIELD(self, void**, 0x68) = &D_800FB7A0;
    M2C_FIELD(self, void**, 0x50) = &D_800FB7A4;
    M2C_FIELD(self, void**, 0x54) = &D_800FB7A8;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0x40000;
    M2C_FIELD(self, u8*, 0x5C) = 12;
    M2C_FIELD(self, u8*, 3) = 0;
    M2C_FIELD(self, u8*, 0x61) = 0;
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, u8*, 0x14) = t;
    switch (M2C_FIELD(self, s8*, 2)) {
    case 0:
        if (g_Player.character == 0) {
            M2C_FIELD(self, u8*, 5) = 6;
        } else {
            M2C_FIELD(self, u8*, 5) = 4;
        }
        break;
    case 1:
        if (g_Player.character == 0) {
            M2C_FIELD(self, u8*, 5) = 7;
        } else {
            M2C_FIELD(self, u8*, 5) = 5;
        }
        break;
    case 2:
        M2C_FIELD(self, u8*, 5) = 2;
        break;
    case 3:
        M2C_FIELD(self, u8*, 5) = 3;
        break;
    case 4:
        v = 2;
        M2C_FIELD(self, u8*, 5) = v;
        M2C_FIELD(self, u8*, 7) = 0;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        break;
    case 5:
        v = 3;
        M2C_FIELD(self, u8*, 5) = v;
        M2C_FIELD(self, u8*, 7) = 0;
        M2C_FIELD(self, s32*, 0x68) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        break;
    }
    M2C_FIELD(self, u8*, 6) = 0;
    M2C_FIELD(self, u8*, 4)++;
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EC7C4);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern struct X4_PlayerObj g_Player;
extern s32 D_800FB7A0;

#define EC93C_U8(s, o) M2C_FIELD(s, u8*, o)
#define EC93C_S8(s, o) M2C_FIELD(s, s8*, o)
#define EC93C_S16(s, o) M2C_FIELD(s, s16*, o)
#define EC93C_ABS(v) ((v) < 0 ? -(v) : (v))

void func_800EC93C(void* self) {
    void* parent;
    void* p;

    parent = M2C_FIELD(self, void**, 0x80);
    if (EC93C_S8(self, 2) == 4 && EC93C_S8(self, 7) == 0) {
        EC93C_S16(self, 0xE) = EC93C_S16(parent, 0xE) - 0x27;
        if (EC93C_S16(self, 0xE) >= 0x521 && EC93C_S8(parent, 6) == 6) {
            M2C_FIELD(self, void**, 0x68) = &D_800FB7A0;
        }
    }
    if (g_Player.x_pos.i.hi > EC93C_S16(self, 0xA)) {
        EC93C_U8(self, 0x15) = 0x40;
    } else {
        EC93C_U8(self, 0x15) = 0;
    }
    EC93C_S16(self, 0x7C)++;
    switch (EC93C_S8(self, 6)) {
    case 1:
        if (EC93C_ABS(g_Player.x_pos.i.hi - EC93C_S16(self, 0xA)) <= 0x80) {
            p = func_8002C458();
            if (p != 0) {
                M2C_FIELD(p, u8*, 0) = EC93C_U8(self, 0);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 0;
                M2C_FIELD(p, void**, 0x7C) = self;
            }
            ((void (*)(void*, s32))set_animation)(self, 2);
            EC93C_S16(self, 0x7C) = 0;
            EC93C_U8(self, 6) = 3;
            break;
        }
        if ((s16)(EC93C_S16(self, 0x7C) % 200) == 0) {
            ((void (*)(void*, s32))set_animation)(self, 1);
            EC93C_S8(self, 6)++;
        }
        break;
    case 2:
        if (g_Player.x_pos.i.hi - EC93C_S16(self, 0xA) >= 0
                ? g_Player.x_pos.i.hi - EC93C_S16(self, 0xA) <= 0x80
                : EC93C_S16(self, 0xA) - g_Player.x_pos.i.hi <= 0x80) {
            p = func_8002C458();
            if (p != 0) {
                M2C_FIELD(p, u8*, 0) = EC93C_U8(self, 0);
                M2C_FIELD(p, u8*, 1) = 5;
                M2C_FIELD(p, u8*, 2) = 0;
                M2C_FIELD(p, void**, 0x7C) = self;
            }
            ((void (*)(void*, s32))set_animation)(self, 2);
            EC93C_S16(self, 0x7C) = 0;
            EC93C_U8(self, 6) = 3;
            break;
        }
        if (EC93C_S8(self, 0x46) == 0) {
            EC93C_U8(self, 6) = 0;
        }
        break;
    case 3:
        if (EC93C_S16(self, 0x7C) != 0x5A) {
            break;
        }
    case 0:
        ((void (*)(void*, s32))set_animation)(self, 0);
        EC93C_S16(self, 0x7C) = 0;
        EC93C_S8(self, 6)++;
        break;
    case 4:
        if (EC93C_S16(self, 0x7C) == 0x28) {
            EC93C_U8(self, 6) = 0;
        }
        break;
    }
}

#undef EC93C_U8
#undef EC93C_S8
#undef EC93C_S16
#undef EC93C_ABS

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800ECB88);
// clang-format on

#define func_800EA2A8 func_800ECDE8
#include "../shared/rock_04/func_800EA2A8.c"
#undef func_800EA2A8

#include "../shared/rock_22/func_800ED14C.c"

#define func_800EA970 func_800ED4B0
#include "../shared/rock_04/func_800EA970.c"
#undef func_800EA970

#define func_800EAC6C func_800ED7AC
#include "../shared/rock_04/func_800EAC6C.c"
#undef func_800EAC6C

#define func_800EAF68 func_800EDAA8
#define D_800F6AB4 D_800FBB34
#include "../shared/rock_04/func_800EAF68.c"
#undef func_800EAF68
#undef D_800F6AB4

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EDC50);
// clang-format on

#define func_800EB29C func_800EDDDC
#include "../shared/rock_04/func_800EB29C.c"
#undef func_800EB29C

// clang-format off
#include "../shared/rock_22/func_800EDF08.c"
// clang-format on

#define func_800EB5A0 func_800EE0E0
#define D_800F6A84 D_800FBB04
#include "../shared/rock_04/func_800EB5A0.c"
#undef func_800EB5A0
#undef D_800F6A84

#include "common.h"

void func_800EE140(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
M2C_UNK func_8002CA14();     /* extern */
M2C_UNK func_8002CA54();     /* extern */

void func_800EE148(void* arg0) {
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 4) < 2U) {
        clear_object_slot();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EE1B0);
// clang-format on

#define func_800EB750 func_800EE290
#include "../shared/rock_04/func_800EB750.c"
#undef func_800EB750

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE360(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE380(void) {
    clear_object_slot();
}

#define func_800EB860 func_800EE3A0
#include "../shared/rock_04/func_800EB860.c"
#undef func_800EB860

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE48C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EE4AC);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EE610);
// clang-format on

#define func_80041AB8 func_800EE7A4
#define D_80075FD8 D_800FBC1C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*, void*); /* extern */
M2C_UNK func_8002CA54(void*, void*); /* extern */
extern u16 D_800CCEDC;

void func_800EE7E0(struct ObjectHeader* arg0) {
    if ((D_800CCEDC == 2) || (arg0->state == 3)) {
        func_8002CA54(arg0, arg0);
        return;
    }
    func_8002CA14(arg0, arg0);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EE834(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

// clang-format off
#define func_801EB968 func_800EE840
#define D_801F3738 D_800FBC58
#define animate_object func_800EEF78
#include "../shared/rock_00/func_801EB968.c"
#undef func_801EB968
#undef D_801F3738
#undef animate_object
// clang-format on

#define func_800EC380 func_800EE888
#include "../shared/rock_09/func_800EC380.c"
#undef func_800EC380

#define func_800EC3B8 func_800EE8C0
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK move_object();
s32 func_8002D354(void* arg0, s32 arg1, s32 arg2);
void set_velocity_from_angle(void*, s32);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EE8C0(struct X4_MainObj* self) {
    struct X4_PlayerObj* pl;
    s32 v;
    s32 dx;

    animate_object();
    move_object(self);
    pl = &g_Player;
    set_velocity_from_angle(
        self,
        func_8002D354(self, pl->x_pos.val, pl->y_pos.val + 0xFFB00000) & 0xFF);
    v = self->x_speed + self->x_speed / 2;
    self->x_speed = v;
    v = (v < 0 ? -v : v) + 0x20000;
    dx = pl->x_pos.val - self->x_pos.val;
    if (dx < 0) {
        dx = self->x_pos.val - pl->x_pos.val;
    }
    if (v >= dx || --self->unk7C == 0) {
        self->action = 3;
        self->action_phase = 0;
    }
}
#undef g_Player
#undef func_800EC3B8
#undef g_Player

#define func_8003744C func_800EE994
#define D_80073C1C D_800FBC60
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EE9D0);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EEA20);
// clang-format on

#define func_800EC574 func_800EEA7C
#include "../shared/rock_09/func_800EC574.c"
#undef func_800EC574

#define func_8003744C func_800EEACC
#define D_80073C1C D_800FBC6C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EEB08);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800EEB64(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#define func_8003744C func_800EEB90
#define D_80073C1C D_800FBC74
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EEBCC);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800EEC38(s32 arg0) {
    animate_object();
    move_object(arg0);
}

#define func_8003744C func_800EEC64
#define D_80073C1C D_800FBC7C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EECA0);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EED9C(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
}

#define func_800EC8C0 func_800EEDC8
#include "../shared/rock_09/func_800EC8C0.c"
#undef func_800EC8C0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object();    /* extern */

void func_800EEE00(struct MainObj* arg0) {
    arg0->x_speed = 0;
    arg0->y_speed = 0x20000;
    ((M2C_UNK(*)())move_object)();
    animate_object(arg0);
}

// clang-format off
#define func_801EB968 func_800EEE38
#define D_801F3738 D_800FBC88
#define animate_object func_800EEF78
#include "../shared/rock_00/func_801EB968.c"
#undef func_801EB968
#undef D_801F3738
#undef animate_object

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EEE80);
// clang-format on

#define func_800EC9D0 func_800EEED8
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object();
s32 func_8002D354(void* arg0, s32 arg1, s32 arg2);
void set_velocity_from_angle(void*, s32);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EEED8(struct X4_MainObj* self) {
    ((void (*)())animate_object)();
    if (--self->unk7C == 0) {
        self->action = 8;
        self->action_phase = 0;
    }
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, s32*, 0x90) + 1;
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, u8*, 0x90) & 3;
    if (M2C_FIELD(self, u8*, 0x90) == 0) {
        set_velocity_from_angle(
            self,
            func_8002D354(self, g_Player.x_pos.val, g_Player.y_pos.val) & 0xFF);
    }
    move_object(self);
}
#undef g_Player
#undef func_800EC9D0
#undef g_Player

#define func_800F32A8 func_800EEF78
#include "../shared/rock_08/func_800F32A8.c"
#undef func_800F32A8

#define func_800ECAA0 func_800EEFA8
#include "../shared/rock_09/func_800ECAA0.c"
#undef func_800ECAA0

#define func_80041AB8 func_800EF050
#define D_80075FD8 D_800FBC98
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EF08C);
// clang-format on

#define func_800ECC10 func_800EF118
#include "../shared/rock_09/func_800ECC10.c"
#undef func_800ECC10

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF200(void) {
    clear_object_slot();
}

#include "common.h"

void func_800EF220(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EF228);
// clang-format on

#include "common.h"

#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 check_enemy_hits(void*);
s32 func_800EFAEC(u8* arg0);
extern s32 D_8007451C;
extern s32 D_800745BC;
extern s32 D_800FBCAC[];
extern u8 D_800FBEA4[][8][4];
extern void (*D_800FC28C[])(u8*);

void func_800EF5B8(u8* arg0) {

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    animate_object();
    D_800FC28C[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    func_8002CCB0(arg0, 0x10, 0x10);
    M2C_FIELD(arg0, u8*, 0x5C) = 0x7F;
    if (check_enemy_hits(arg0) != 0) {
        M2C_FIELD(arg0, u8*, 0x8B) = 0x21;
        M2C_FIELD(arg0, s32**, 0x58) = &D_800745BC;
        if ((M2C_FIELD(arg0, s8*, 0x2) & 0xF0) == 0x40) {
            if (M2C_FIELD(arg0, u8*, 0x89) == 1) {
                M2C_FIELD(arg0, u8*, 0x8C) = M2C_FIELD(arg0, u8*, 0x89);
                M2C_FIELD(arg0, u8*, 0x89) = 0;
            }
            play_sound(2, 0x4E, arg0);
            M2C_FIELD(arg0, u8*, 0x87) = (M2C_FIELD(arg0, u8*, 0x87) + 1) & 7;
            M2C_FIELD(arg0, u8*, 0x88) =
                D_800FBEA4[M2C_FIELD(arg0, u8*, 0x2) & 0xF]
                          [M2C_FIELD(arg0, u8*, 0x87)][0];
            M2C_FIELD(arg0, s32**, 0x54) =
                &D_800FBCAC[M2C_FIELD(arg0, u8*, 0x88)];
            set_animation(arg0, M2C_FIELD(arg0, u8*, 0x88) + 0x10);
        }
    }
    if (func_800EFAEC(arg0) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x89) == 0) {
            M2C_FIELD(arg0, u8*, 0x8C) = 1;
        }
    } else {
        M2C_FIELD(arg0, u8*, 0x89) = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x8B) != 0) {
        if (--M2C_FIELD(arg0, u8*, 0x8B) == 0) {
            M2C_FIELD(arg0, s32**, 0x58) = &D_8007451C;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EF73C);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EF8B4);
// clang-format on

#include "common.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

s32 func_8002D654(s8*, u8*);
extern s8 D_800950A0[];
extern u8 D_800FC004[][8];
extern s16 D_800FC084[][3];

s32 func_800EFAEC(u8* arg0) {
    s8* p;
    s16 dx;
    s16 dy;
    s32 t;
    u8 idx;
    // !FAKE: depin: dropping it breaks the match (113/118)
    register s32 sub asm("$4");
    // !FAKE: depin: dropping it breaks the match (114/118)
    register s32 k asm("$2");

    for (p = D_800950A0; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (p[0] == 0 || p[1] != 0x4F) {
            continue;
        }
        if (M2C_FIELD(arg0, u16*, 0x84) == M2C_FIELD(p, u16*, 0x8C)) {
            continue;
        }
        if (func_8002D654(p, arg0) == 0) {
            continue;
        }
        if (M2C_FIELD(p, s8*, 0x98) != 0) {
            return 0;
        }
        if (M2C_FIELD(arg0, u8*, 0x8A) == 0) {
            dy = 0;
            t = M2C_FIELD(arg0, s8*, 2) & 0xF0;
            sub = M2C_FIELD(arg0, u8*, 2);
            dx = 0;
            if (t == 0x30 || t == 0x40) {
                idx = D_800FC004[M2C_FIELD(arg0, u8*, 0x88)]
                                [M2C_FIELD(p, s32*, 0x84)];
                if (idx != 0xFF) {
                    dx = D_800FC084[idx][1];
                    dy = D_800FC084[idx][2];
                } else {
                    dx = 0;
                }
            } else if (t == 0x30) {
                dx = 0;
            } else if (t == 0x50) {
                dx = 0x1E;
                k = (sub & 0xF) - 4;
                if ((u32)k < 2) {
                    dy = -8;
                } else {
                    dx = -8;
                    dy = -0x1E;
                }
            }
            M2C_FIELD(p, s8*, 0x98) = 2;
            M2C_FIELD(p, s16*, 0xA) = dx + M2C_FIELD(arg0, s16*, 0xA);
            M2C_FIELD(p, s16*, 0xE) = dy + M2C_FIELD(arg0, s16*, 0xE);
        } else {
            M2C_FIELD(p, s8*, 0x98) = 1;
            M2C_FIELD(arg0, u8*, 0x8A) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x86) = M2C_FIELD(p, u8*, 0x84);
        return 1;
    }
    return 0;
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EFCC4);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800EFE94);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F0014);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();
M2C_UNK move_object(s32);
M2C_UNK func_80030ECC();
void func_800F20BC(void* arg0);
s32 func_800F2100(void* arg0);
s32 func_800F2158(void* arg0);
extern u8 D_800FBFE4[][2];
extern u8 D_800FBFF4[][2];

void func_800F01DC(void* arg0) {
    void* parent;
    void* m1;
    void* m2;
    void* m3;
    void* m4;
    void* m5;
    void* m6;
    void* m7;
    void* m8;
    void* m9;
    u16 i;
    u16 t;
    s32 r;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    parent = M2C_FIELD(arg0, void**, 0x7C);
    if (func_800F2158(arg0) == 0) {
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        M2C_FIELD(arg0, u8*, 0x4)++;
        m7 = alloc_sprite_slot();
        if (m7 != 0) {
            do {
                M2C_FIELD(m7, u8*, 0x0) = 0x41;
                M2C_FIELD(m7, u8*, 0x1) = 7;
                M2C_FIELD(m7, u8*, 0x2) = 1;
                M2C_FIELD(m7, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                M2C_FIELD(m7, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(m7, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(m7, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(m7, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(m7, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            } while (0);
            t = M2C_FIELD(arg0, u16*, 0x92);
            M2C_FIELD(m7, u16*, 0x8) = 0;
            M2C_FIELD(m7, u16*, 0xA) = t;
            M2C_FIELD(m7, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x94);
            M2C_FIELD(m7, u16*, 0xC) = 0;
            M2C_FIELD(m7, void**, 0x50) = arg0;
            M2C_FIELD(m7, u8*, 0x16) = 5;
            i = M2C_FIELD(arg0, u16*, 0x84);
            M2C_FIELD(m7, u16*, 0x54) = i;
            M2C_FIELD(m7, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x96);
            M2C_FIELD(m7, u8*, 0x47) =
                D_800FBFF4[(s16)i][0] + M2C_FIELD(m7, u8*, 0x56);
            M2C_FIELD(m7, u8*, 0x15) = D_800FBFF4[(s16)i][1];
            M2C_FIELD(m7, u8*, 0x0) = 0x51;
        }
        m8 = alloc_sprite_slot();
        if (m8 != 0) {
            do {
                M2C_FIELD(m8, u8*, 0x0) = 0x41;
                M2C_FIELD(m8, u8*, 0x1) = 7;
                M2C_FIELD(m8, u8*, 0x2) = 0;
                M2C_FIELD(m8, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                M2C_FIELD(m8, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(m8, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(m8, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(m8, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(m8, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            } while (0);
            M2C_FIELD(m8, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x92);
            M2C_FIELD(m8, u16*, 0x8) = M2C_FIELD(arg0, u16*, 0x94);
            M2C_FIELD(m8, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(m8, u16*, 0xC) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(m8, void**, 0x50) = arg0;
            M2C_FIELD(m8, u8*, 0x16) = 6;
            M2C_FIELD(m8, u16*, 0x54) = M2C_FIELD(arg0, u16*, 0x84);
            M2C_FIELD(m8, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
            M2C_FIELD(m8, u8*, 0x0) = 0x51;
        }
        m9 = alloc_sprite_slot();
        if (m9 != 0) {
            do {
                M2C_FIELD(m9, u8*, 0x0) = 0x41;
                M2C_FIELD(m9, u8*, 0x1) = 7;
                M2C_FIELD(m9, u8*, 0x2) = 1;
                M2C_FIELD(m9, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                M2C_FIELD(m9, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(m9, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(m9, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(m9, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(m9, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            } while (0);
            t = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(m9, u16*, 0x8) = 0;
            M2C_FIELD(m9, u16*, 0xA) = t;
            M2C_FIELD(m9, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(m9, u16*, 0xC) = 0;
            M2C_FIELD(m9, void**, 0x50) = arg0;
            M2C_FIELD(m9, u8*, 0x16) = 4;
            i = M2C_FIELD(arg0, u16*, 0x84);
            M2C_FIELD(m9, u16*, 0x54) = i;
            M2C_FIELD(m9, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
            M2C_FIELD(m9, u8*, 0x47) =
                D_800FBFE4[(s16)i][0] + M2C_FIELD(m9, u8*, 0x56);
            M2C_FIELD(m9, u8*, 0x15) = D_800FBFE4[(s16)i][1];
            M2C_FIELD(m9, u8*, 0x0) = 0x51;
        }
        return;
    }
    func_800F20BC(arg0);
    func_80030ECC(arg0);
    r = M2C_FIELD(arg0, u16*, 0x8A);
    if (M2C_FIELD(arg0, s16*, 0x8A) != 0) {
        r--;
        M2C_FIELD(arg0, u16*, 0x8A) = r;
        if ((s16)r == 0) {
            M2C_FIELD(parent, u8*, 0x89) = 2;
            M2C_FIELD(arg0, u8*, 0x5) = 0;
            M2C_FIELD(arg0, u8*, 0x4)++;
            m1 = alloc_sprite_slot();
            if (m1 != 0) {
                do {
                    M2C_FIELD(m1, u8*, 0x0) = 0x41;
                    M2C_FIELD(m1, u8*, 0x1) = 7;
                    M2C_FIELD(m1, u8*, 0x2) = 1;
                    M2C_FIELD(m1, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                    M2C_FIELD(m1, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(m1, u16*, 0x42) =
                        M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                    M2C_FIELD(m1, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(m1, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(m1, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
                } while (0);
                t = M2C_FIELD(arg0, u16*, 0x92);
                M2C_FIELD(m1, u16*, 0x8) = 0;
                M2C_FIELD(m1, u16*, 0xA) = t;
                M2C_FIELD(m1, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x94);
                M2C_FIELD(m1, u16*, 0xC) = 0;
                M2C_FIELD(m1, void**, 0x50) = arg0;
                M2C_FIELD(m1, u8*, 0x16) = 5;
                i = M2C_FIELD(arg0, u16*, 0x84);
                M2C_FIELD(m1, u16*, 0x54) = i;
                M2C_FIELD(m1, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x96);
                M2C_FIELD(m1, u8*, 0x47) =
                    D_800FBFF4[(s16)i][0] + M2C_FIELD(m1, u8*, 0x56);
                M2C_FIELD(m1, u8*, 0x15) = D_800FBFF4[(s16)i][1];
                M2C_FIELD(m1, u8*, 0x0) = 0x51;
            }
            m2 = alloc_sprite_slot();
            if (m2 != 0) {
                do {
                    M2C_FIELD(m2, u8*, 0x0) = 0x41;
                    M2C_FIELD(m2, u8*, 0x1) = 7;
                    M2C_FIELD(m2, u8*, 0x2) = 0;
                    M2C_FIELD(m2, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                    M2C_FIELD(m2, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(m2, u16*, 0x42) =
                        M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                    M2C_FIELD(m2, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(m2, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(m2, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
                } while (0);
                M2C_FIELD(m2, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x92);
                M2C_FIELD(m2, u16*, 0x8) = M2C_FIELD(arg0, u16*, 0x94);
                M2C_FIELD(m2, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(m2, u16*, 0xC) = M2C_FIELD(arg0, u16*, 0xE);
                M2C_FIELD(m2, void**, 0x50) = arg0;
                M2C_FIELD(m2, u8*, 0x16) = 6;
                M2C_FIELD(m2, u16*, 0x54) = M2C_FIELD(arg0, u16*, 0x84);
                M2C_FIELD(m2, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
                M2C_FIELD(m2, u8*, 0x0) = 0x51;
            }
            m3 = alloc_sprite_slot();
            if (m3 != 0) {
                do {
                    M2C_FIELD(m3, u8*, 0x0) = 0x41;
                    M2C_FIELD(m3, u8*, 0x1) = 7;
                    M2C_FIELD(m3, u8*, 0x2) = 1;
                    M2C_FIELD(m3, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                    M2C_FIELD(m3, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(m3, u16*, 0x42) =
                        M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                    M2C_FIELD(m3, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(m3, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(m3, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
                } while (0);
                t = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(m3, u16*, 0x8) = 0;
                M2C_FIELD(m3, u16*, 0xA) = t;
                M2C_FIELD(m3, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
                M2C_FIELD(m3, u16*, 0xC) = 0;
                M2C_FIELD(m3, void**, 0x50) = arg0;
                M2C_FIELD(m3, u8*, 0x16) = 4;
                i = M2C_FIELD(arg0, u16*, 0x84);
                M2C_FIELD(m3, u16*, 0x54) = i;
                M2C_FIELD(m3, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
                M2C_FIELD(m3, u8*, 0x47) =
                    D_800FBFE4[(s16)i][0] + M2C_FIELD(m3, u8*, 0x56);
                M2C_FIELD(m3, u8*, 0x15) = D_800FBFE4[(s16)i][1];
                M2C_FIELD(m3, u8*, 0x0) = 0x51;
            }
            return;
        }
    }
    if (func_800F2100(arg0) == 0 && M2C_FIELD(arg0, s16*, 0x88) == 0 &&
        M2C_FIELD(arg0, s8*, 0x98) != 2) {
        ((void (*)(void*))move_object)(arg0);
        if (M2C_FIELD(arg0, s16*, 0xA) < 0) {
            M2C_FIELD(arg0, s16*, 0xA) = 0;
        }
        if (M2C_FIELD(arg0, s16*, 0xE) < 0) {
            M2C_FIELD(arg0, s16*, 0xE) = 0;
        }
    }
    m4 = alloc_sprite_slot();
    if (m4 != 0) {
        do {
            M2C_FIELD(m4, u8*, 0x0) = 0x41;
            M2C_FIELD(m4, u8*, 0x1) = 7;
            M2C_FIELD(m4, u8*, 0x2) = 1;
            M2C_FIELD(m4, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m4, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m4, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m4, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m4, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m4, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        t = M2C_FIELD(arg0, u16*, 0x92);
        M2C_FIELD(m4, u16*, 0x8) = 0;
        M2C_FIELD(m4, u16*, 0xA) = t;
        M2C_FIELD(m4, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x94);
        M2C_FIELD(m4, u16*, 0xC) = 0;
        M2C_FIELD(m4, void**, 0x50) = arg0;
        M2C_FIELD(m4, u8*, 0x16) = 5;
        i = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m4, u16*, 0x54) = i;
        M2C_FIELD(m4, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x96);
        M2C_FIELD(m4, u8*, 0x47) =
            D_800FBFF4[(s16)i][0] + M2C_FIELD(m4, u8*, 0x56);
        M2C_FIELD(m4, u8*, 0x15) = D_800FBFF4[(s16)i][1];
    }
    m5 = alloc_sprite_slot();
    if (m5 != 0) {
        do {
            M2C_FIELD(m5, u8*, 0x0) = 0x41;
            M2C_FIELD(m5, u8*, 0x1) = 7;
            M2C_FIELD(m5, u8*, 0x2) = 0;
            M2C_FIELD(m5, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m5, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m5, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m5, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m5, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m5, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        M2C_FIELD(m5, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x92);
        M2C_FIELD(m5, u16*, 0x8) = M2C_FIELD(arg0, u16*, 0x94);
        M2C_FIELD(m5, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(m5, u16*, 0xC) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(m5, void**, 0x50) = arg0;
        M2C_FIELD(m5, u8*, 0x16) = 6;
        M2C_FIELD(m5, u16*, 0x54) = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m5, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
    }
    m6 = alloc_sprite_slot();
    if (m6 != 0) {
        do {
            M2C_FIELD(m6, u8*, 0x0) = 0x41;
            M2C_FIELD(m6, u8*, 0x1) = 7;
            M2C_FIELD(m6, u8*, 0x2) = 1;
            M2C_FIELD(m6, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m6, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m6, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m6, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m6, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m6, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        t = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(m6, u16*, 0x8) = 0;
        M2C_FIELD(m6, u16*, 0xA) = t;
        M2C_FIELD(m6, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(m6, u16*, 0xC) = 0;
        M2C_FIELD(m6, void**, 0x50) = arg0;
        M2C_FIELD(m6, u8*, 0x16) = 4;
        i = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m6, u16*, 0x54) = i;
        M2C_FIELD(m6, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
        M2C_FIELD(m6, u8*, 0x47) =
            D_800FBFE4[(s16)i][0] + M2C_FIELD(m6, u8*, 0x56);
        M2C_FIELD(m6, u8*, 0x15) = D_800FBFE4[(s16)i][1];
    }
    M2C_FIELD(arg0, s16*, 0x88) = (s16)(M2C_FIELD(arg0, s16*, 0x88) + 1) % 3;
    r = M2C_FIELD(arg0, u16*, 0x96) + 1;
    M2C_FIELD(arg0, u16*, 0x96) = (u16)r % 5;
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F0820);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F0DC4);
// clang-format on

#define func_80041AB8 func_800F19E4
#define D_80075FD8 D_800FC264
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800F1A20
#define D_80075FD8 D_800FC2E4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F1A5C);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F1AA4);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F1B48);
// clang-format on

#define func_800ECB00 func_800F1BEC
#include "../shared/rock_10/func_800ECB00.c"
#undef func_800ECB00

#define func_8003744C func_800F1C28
#define D_80073C1C D_800FC2AC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1C64(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 3;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800EABD8 func_800EFCC4
#define func_800ECB90 func_800F1C7C
#include "../shared/rock_10/func_800ECB90.c"
#undef func_800ECB90
#undef func_800EABD8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1CD0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) == 2) {
        M2C_FIELD(arg0, u8*, 0x89) = 0U;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800ECC10 func_800F1CFC
#include "../shared/rock_10/func_800ECC10.c"
#undef func_800ECC10

#define func_8003744C func_800F1D24
#define D_80073C1C D_800FC2BC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F1D60);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EFCC4(void*, M2C_UNK); /* extern */

void func_800F1E2C(void* arg0) {
    s32 temp_v1;
    u8 temp_a0;
    u8 temp_v0;

    temp_a0 = M2C_FIELD(arg0, u8*, 0x86);
    temp_v0 = M2C_FIELD(arg0, u8*, 0x88);
    temp_v1 = temp_a0 - temp_v0;
    if ((temp_v1 >= 0 && temp_v1 != 4) ||
        (temp_v1 < 0 && temp_a0 != (temp_v0 - 4))) {
        func_800EFCC4(arg0, 0);
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0x12E;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800ECDB0 func_800F1E9C
#include "../shared/rock_10/func_800ECDB0.c"
#undef func_800ECDB0

#include "common.h"

void func_800F1ED8(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F1EE0);
// clang-format on

#define func_8003744C func_800F1F40
#define D_80073C1C D_800FC2C8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1F7C(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 4;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800F1F8C
#define D_80073C1C D_800FC2D0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

void func_800F1FC8(void) {
}

#include "common.h"

s8* func_8002C5F0(s8* p, s32 back);
extern u8 D_800FBFD4[];

#include "../shared/rock_22/func_800F1FD0.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F20BC(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x8C);
    M2C_FIELD(arg0, u8*, 0x98) = (u8)M2C_FIELD(temp_a1, u8*, 0x98);
    if ((s8)M2C_FIELD(temp_a1, u8*, 0x98) == 2) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
    }
    M2C_FIELD(temp_a1, u8*, 0x98) = 0U;
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F2100);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800F2158(void* arg0) {
    u8 temp_v1;
    void* temp_a0;

    temp_a0 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_a0, s8*, 4) == 4) {
        return 0;
    }
    temp_v1 = M2C_FIELD(temp_a0, u8*, 0x89);
    if (temp_v1 == 1) {
        return 1;
    }
    return temp_v1 != 0;
}

#define func_800ED0AC func_800F2198
#define D_800E987C D_800E9A94
#include "../shared/rock_10/func_800ED0AC.c"
#undef func_800ED0AC
#undef D_800E987C

#include "../shared/rock_22/func_800F22B8.c"

#include "common.h"

void func_800F2374(void) {
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F237C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F239C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F23F0(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define SPAD (*(u8**)0x1F80004C)

s32 random_byte();
M2C_UNK func_8002F288(M2C_UNK*);
void func_8002F418(struct X4_PlayerObj* arg0);
extern u8 D_800FC58C[];
extern s32 D_800FC62C[];
extern s32 D_800FC634[];
extern s32 D_800FC63C[];

void func_800F2410(struct X4_MainObj* self) {
    s32 i;

    self->state = 1;
    self->action = 2;
    self->on_screen = 1;
    self->hp = 4;
    self->contact_damage = 3;
    self->action_phase = 0;
    self->unk7C = 0;
    self->invincibility_timer = 0;
    self->animation_table = (void*)D_800FC58C;
    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    func_8002F288((M2C_UNK*)self);
    self->air_state = 0;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    switch (self->unk2) {
    case 0:
        self->x_speed = 0x80000;
        self->unk15 = 0x40;
        break;
    case 1:
        self->x_speed = -0x80000;
        self->unk15 = 0;
        break;
    case 2:
        self->y_speed = 0x80000;
        break;
    }
    self->unk16 = 6;
    SPAD[0x80] = random_byte() & 1;
    SPAD[0x81] = self->unk2;
    self->hurt_box = (void*)D_800FC634[self->unk2 >> 1];
    self->attack_box = (void*)D_800FC63C[self->unk2 >> 1];
    self->terrain_box = (void*)D_800FC62C[self->unk2 >> 1];
    self->collision_data = &D_800743DC;
    func_8002F418((struct X4_PlayerObj*)self);
    if (self->collision_flags) {
        self->action = 2;
    } else {
        self->action = 5;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

#define SPAD (*(u8**)0x1F80004C)

s32 func_8002CAB4(struct X4_BaseObj*);
M2C_UNK func_8002CB50();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void drop_item(struct X4_BaseObj* arg0, s8 arg1, s16 arg2, s16 arg3);
extern s32 D_800FC5F8;
extern void (*D_800FC68C[])(u8*);

void func_800F259C(u8* arg0) {
    s16 x;
    s16 y;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800FC68C[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    func_80030ECC(arg0);
    if (check_enemy_hits(arg0) < 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        func_80049E50(arg0);
        func_800477E4(8, &D_800FC5F8, arg0);
        {
            // !FAKE: depin: dropping it breaks the match (68/73)
            register u8* sp asm("$2") = SPAD;
            x = M2C_FIELD(arg0, s16*, 0xA);
            y = M2C_FIELD(arg0, s16*, 0xE);
            if (sp[0x81] < 2) {
                // !FAKE: depin: dropping it breaks the match (46/73)
                register u8* a asm("$4") = arg0;
                // !FAKE: depin: dropping it breaks the match (39/73)
                register s32 t asm("$6") = x;
                // !FAKE: depin: dropping it breaks the match (45/73)
                register s32 k asm("$5") = 0x12;
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    t -= 0x10;
                } else {
                    t += 0x10;
                }
                ((void (*)())drop_item)(a, k, (s16)t, y);
            } else {
                drop_item((struct X4_BaseObj*)arg0, 0x12, x, y + 0x10);
            }
        }
    } else if (func_8002CAB4((struct X4_BaseObj*)arg0) == 0) {
        func_8002CB50(arg0);
        return;
    }
    M2C_FIELD(arg0, s8*, 0x4) = 2;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
s32 func_800F2FB8(void*, u8, s32);
extern s32 D_800FC62C[];
extern u8 D_800FC6C4[];
extern u8 D_800FC6C8[];

void func_800F26C0(struct X4_BaseObj* self) {
    s32 anim;

    if (SPAD[0x81] < 2) {
        if (SPAD[0x81] == 0) {
            self->unk15 = 0x40;
            SPAD[0x82] = 1;
        } else {
            self->unk15 = 0;
            SPAD[0x82] = 2;
        }
        F16(SPAD, 0x84) = (random_byte() & 1) ? 0x50 : 0x20;
        if (func_800F2FB8(self, SPAD[0x80], 0) != 0) {
            SPAD[0x80] ^= 1;
        }
        anim = D_800FC6C4[SPAD[0x80]];
        F16(SPAD, 0x8A) = 0x15;
    } else {
        F16(SPAD, 0x84) = (random_byte() & 1) ? 0x40 : 0x20;
        if (func_800F2FB8(self, SPAD[0x80], 1) != 0) {
            SPAD[0x80] ^= 1;
        }
        anim = 2;
        self->unk15 = D_800FC6C8[SPAD[0x80]];
        F16(SPAD, 0x8A) = 0x17;
        SPAD[0x82] = 4;
    }
    {
        // !FAKE: depin: dropping it breaks the match (105/123)
        register s32 v asm("$6");

        v = D_800FC62C[(s8)self->unk2 >> 1];
        F32(self, 0x68) = v;
        ((void (*)(void*, s32, s32))set_animation)(self, anim, v);
    }
    self->action_phase = 1;
    F16(SPAD, 0x86) = F16(self, 0xA);
    F16(SPAD, 0x88) = F16(self, 0xE);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 func_800F2FB8(void*, u8, s32);
s32 func_800F3158(void*);
s32 func_800F3F38(void*);

void func_800F28AC(struct X4_BaseObj* self) {
    u8* sp;

    sp = SPAD;
    if (sp[0x81] < 2) {
        if (F8(self, 0x46) < 0) {
            s16 a;
            s16 b;
            u16 range;
            s32 d;

            a = F16(self, 0xE);
            b = F16(sp, 0x88);
            range = FU16(sp, 0x84);
            d = a - b;
            if (d >= 0 ? range >= d : range >= b - a) {
                if (func_800F2FB8(self, SPAD[0x80], 0) != 0) {
                    // !FAKE: goto keeps the shared far/near blocks (C0173); the ternary removed only the call gotos
                    goto far0;
                }
                // !FAKE: goto keeps the shared far/near blocks (C0173); the ternary removed only the call gotos
                goto near;
            }
        far0:
            if (func_800F3F38(self) & 1) {
                self->action_phase = 4;
                if (F32(self, 0x24) < 0) {
                    SPAD[0x80] = 1;
                } else {
                    SPAD[0x80] = 0;
                }
                F32(self, 0x20) = 0;
                F32(self, 0x24) = F32(self, 0x24) * 3;
                set_animation(self, 6);
            } else if (func_800F3158(self) != 0) {
                self->action = 4;
                self->action_phase = 0;
            } else {
                self->action_phase = 2;
                set_animation(self, 6);
            }
        } else if (F8(self, 0x45) != 0) {
            if (sp[0x80] == 0) {
                F16(self, 0xE) = FU16(self, 0xE) - FU16(sp, 0x8A);
            } else {
                F16(self, 0xE) = FU16(self, 0xE) + FU16(sp, 0x8A);
            }
            F8(self, 0x45) = 0;
        }
    } else {
        if (F8(self, 0x46) < 0) {
            s16 a;
            s16 b;
            u16 range;
            s32 d;

            a = F16(self, 0xA);
            b = F16(sp, 0x86);
            range = FU16(sp, 0x84);
            d = a - b;
            if (d >= 0 ? range >= d : range >= b - a) {
                if (func_800F2FB8(self, SPAD[0x80], 1) != 0) {
                    // !FAKE: goto keeps the shared far/near blocks (C0173); the ternary removed only the call gotos
                    goto far1;
                }
                // !FAKE: goto keeps the shared far/near blocks (C0173); the ternary removed only the call gotos
                goto near;
            }
            if (0) {
            near:
                if (F16(self, 0x7C) >= 0x3C && func_800F3158(self) != 0) {
                    self->action = 4;
                    self->action_phase = 0;
                }
                animate_object(self);
                return;
            }
        far1:
            if (func_800F3F38(self) & 2) {
                self->action_phase = 4;
                if (F32(self, 0x20) >= 0) {
                    self->unk15 = 0x40;
                    SPAD[0x80] = 1;
                } else {
                    self->unk15 = 0;
                    SPAD[0x80] = 0;
                }
                F32(self, 0x24) = 0;
                F32(self, 0x20) = F32(self, 0x20) * 3;
                set_animation(self, 5);
            } else if (func_800F3158(self) != 0) {
                self->action = 4;
                self->action_phase = 0;
            } else {
                self->action_phase = 2;
                set_animation(self, 5);
            }
        } else if (F8(self, 0x45) != 0) {
            if (sp[0x80] == 0) {
                F16(self, 0xA) = FU16(self, 0xA) - FU16(sp, 0x8A);
            } else {
                F16(self, 0xA) = FU16(self, 0xA) + FU16(sp, 0x8A);
            }
            F8(self, 0x45) = 0;
        }
    }
    animate_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define SPAD (*(u8**)0x1F80004C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);
M2C_UNK func_8002F288(M2C_UNK*);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
extern s16 D_800970AA;

void func_800F2BDC(struct X4_MainObj* self) {
    s32 ref;
    // !FAKE: depin: dropping it breaks the match (41/165)
    register s32 p asm("$3");
    s16 x;
    s16 y;
    s32 near;
    s32 d;
    u8 r;

    move_object((s32)self);
    func_8002F288((M2C_UNK*)self);
    near = 0;
    if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index < 2) {
        if (SP_CUR_MAIN_OBJ->ext.main_19.unk80 == 0) {
            p = (u16)self->y_pos.i.hi;
            y = p - self->terrain_box->unk3;
            ref = p;
        } else {
            p = (u16)self->y_pos.i.hi;
            y = p + self->terrain_box->unk3;
            ref = p;
        }
        if (self->unk15 == 0) {
            x = self->x_pos.i.hi - 4;
        } else {
            x = self->x_pos.i.hi + 4;
        }
        d = D_800970AE - (s16)ref;
        if (d >= 0 ? d < 0x18 : (s16)ref - D_800970AE < 0x18) {
            near = 1;
        }
    } else {
        if (self->unk15 == 0) {
            p = (u16)self->x_pos.i.hi;
            x = p - self->terrain_box->unk2;
            ref = p;
        } else {
            p = (u16)self->x_pos.i.hi;
            x = p + self->terrain_box->unk2;
            ref = p;
        }
        y = self->y_pos.i.hi - 4;
        d = D_800970AA - (s16)ref;
        if (d >= 0 ? d < 0x18 : (s16)ref - D_800970AA < 0x18) {
            near = 1;
        }
    }
    r = ((u8(*)(void*, s16, s16, s32))func_80030234)(self, x, y, ref);
    if ((self->collision_flags & ~SP_CUR_MAIN_OBJ->ext.main_19.unk82) ||
        r < 0x38 || near) {
        if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index < 2) {
            set_animation(self, 0xB);
            {
                // !FAKE: depin: dropping it breaks the match (159/165)
                register s32 six asm("$2") = 6;
                self->action_phase = six;
            }
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
            if ((self->collision_flags >>
                 (SP_CUR_MAIN_OBJ->ext.main_19.unk80 + 2)) &
                1) {
                SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
            }
        } else {
            set_animation(self, 0xA);
            {
                s32 six = 6;
                // !FAKE: depin: dropping it breaks the match (156/165)
                register s32 f asm("$2") = self->unk15;
                self->action_phase = six;
                self->unk15 = f ^ 0x40;
            }
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
            if ((self->collision_flags >> SP_CUR_MAIN_OBJ->ext.main_19.unk80) &
                1) {
                SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
            }
        }
    } else {
        animate_object(self);
    }
}

#include "common.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK animate_object();
void* func_8002C458();
s32 random_byte();
void set_velocity_from_angle(void*, s32);
extern s16 D_800FC6D8[];

void func_800F2E70(u8* arg0) {
    u8* p;
    s32 i;

    if (F8(arg0, 0x46) < 0) {
        F8(arg0, 5) = 2;
        F8(arg0, 6) = 0;
        F8(SPAD, 0x80) = random_byte() & 1;
        return;
    }
    if (F8(arg0, 0x45) != 0) {
        p = func_8002C458();
        if (p != 0) {
            F8(p, 0) = 0x41;
            F8(p, 1) = 0x24;
            i = (FU8(SPAD, 0x81) * 2) & 0xFF;
            F16(p, 0xA) = F16(arg0, 0xA) + D_800FC6D8[i];
            F16(p, 0xE) = F16(arg0, 0xE) + D_800FC6D8[i | 1];
            F32(p, 0x30) = F32(arg0, 0x30);
            F16(p, 0x40) = F16(arg0, 0x40);
            F32(p, 0x3C) = F32(arg0, 0x3C);
            F16(p, 0x42) = F16(arg0, 0x42) & 0x7FFF;
            {
                u8 t = FU8(arg0, 0x16);
                *(u8**)(p + 0x7C) = arg0;
                F8(p, 0x16) = t;
            }
            F8(p, 0x15) = F8(arg0, 0x15);
            set_velocity_from_angle(p, FU8(SPAD, 0x83));
        }
        F8(arg0, 0x45) = 0;
        return;
    }
    animate_object(arg0);
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800F3FF8(struct X4_MainObj*, s32, s32);
u8 func_800F4094(struct X4_PlayerObj* self, s16 arg1, s16 arg2);

s32 func_800F2FB8(void* arg0, u8 arg1, s32 arg2) {
    struct X4_MainObj* self = arg0;
    // !FAKE: depin: dropping it breaks the match (18/104)
    register s32 d asm("$6");
    s16 dx;
    s16 x;
    s16 y;
    s32 t;
    u8 r;
    s32 ret;

    if ((u8)arg2 == 0) {
        if (arg1 == 0) {
            // !FAKE: depin: dropping it breaks the match (98/104)
            register s32 m asm("$3") = -SP_CUR_MAIN_OBJ->ext.main_19.unk8A;
            m <<= 16;
            y = (m >> 16) - self->terrain_box->unk3;
            d = m >> 16;
        } else {
            d = (s16)SP_CUR_MAIN_OBJ->ext.main_19.unk8A;
            y = self->terrain_box->unk3 + d;
        }
        dx = 1;
        if (self->unk15 == 0) {
            dx = -1;
            x = -4;
        } else {
            x = 4;
        }
        t = func_800F3FF8(self, dx, d);
        r = func_800F4094((struct X4_PlayerObj*)self, x, y);
        if ((t & 0xF) == (1 << SP_CUR_MAIN_OBJ->ext.main_19.animation_index)) {
            ret = r < 0x38;
        } else {
            ret = 1;
        }
    } else {
        s16 e;

        if (arg1 == 0) {
            e = -SP_CUR_MAIN_OBJ->ext.main_19.unk8A;
            x = e - self->terrain_box->unk2;
        } else {
            e = (s16)SP_CUR_MAIN_OBJ->ext.main_19.unk8A;
            x = self->terrain_box->unk2 + e;
        }
        t = func_800F3FF8(self, e, -1);
        r = func_800F4094((struct X4_PlayerObj*)self, x, -4);
        ret = 1;
        if ((t & 0xF) == 4) {
            ret = r < 0x38;
        }
    }
    return ret;
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F3158);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F32B0);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

#define SPAD (*(u8**)0x1F80004C)

s32 func_8002CAB4(struct X4_BaseObj*);
M2C_UNK func_8002CB50();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void drop_item(struct X4_BaseObj* arg0, s8 arg1, s16 arg2, s16 arg3);
extern s32 D_800FC5F8;
extern void (*D_800FC6E4[])(u8*);

void func_800F3444(u8* arg0) {
    s32 r;
    s16 x;
    s16 y;
    u8 v;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800FC6E4[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    func_80030ECC(arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        func_80049E50(arg0);
        func_800477E4(8, &D_800FC5F8, arg0);
        {
            // !FAKE: depin: dropping it breaks the match (91/94)
            register u8* sp asm("$4") = SPAD;
            x = M2C_FIELD(arg0, s16*, 0xA);
            y = M2C_FIELD(arg0, s16*, 0xE);
            v = sp[0x80];
        }
        if (v != 2) {
            switch (v) {
            case 0:
                y += 0x10;
                break;
            case 1:
                x -= 0x10;
                break;
            case 3:
                x += 0x10;
                break;
            }
            drop_item((struct X4_BaseObj*)arg0, 0x12, x + 0x10, y);
        }
        M2C_FIELD(arg0, s8*, 0x4) = 2;
        return;
    }
    if (r != 0) {
        M2C_FIELD(arg0, s8*, 0x5) = 1;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
    }
    if (func_8002CAB4((struct X4_BaseObj*)arg0) == 0) {
        func_8002CB50(arg0);
    } else {
        M2C_FIELD(arg0, s8*, 0x4) = 2;
    }
    if (SPAD[0x82] >= 0x39) {
        M2C_FIELD(arg0, s8*, 0x4) = 2;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK animate_object();
M2C_UNK apply_object_motion(void*);
M2C_UNK func_8002F288(M2C_UNK*);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800F40E0(struct X4_MainObj* self);
extern u8 D_800FC6FC[];

void func_800F35BC(struct X4_MainObj* self) {
    s16 x;
    s16 y;
    u8 hit;
    u8 dir;
    u8 mask;
    struct X4_Unk_unk68* box;

    if (self->action_phase == 0) {
        func_800F40E0(self);
        self->action_phase = 1;
        return;
    }
    x = self->x_pos.i.hi;
    y = self->y_pos.i.hi;
    if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index == 0) {
        u8 d = SP_CUR_MAIN_OBJ->ext.main_19.unk80;
        if (d == 2) {
            y -= 2;
        }
        if (d == 3) {
            x -= 2;
            y -= 2;
        }
    } else {
        u8 d = SP_CUR_MAIN_OBJ->ext.main_19.unk80;
        if (d == 1) {
            x += 2;
            y -= 2;
        }
        if (d == 2) {
            x -= 2;
            y -= 2;
        }
        if (d == 3) {
            x -= 2;
            y += 2;
        }
    }
    hit = func_80030234((struct X4_PlayerObj*)self, x, y);
    SP_CUR_MAIN_OBJ->ext.main_19.unk82 = hit;
    dir = SP_CUR_MAIN_OBJ->ext.main_19.unk80;
    mask =
        D_800FC6FC[(SP_CUR_MAIN_OBJ->ext.main_19.animation_index << 2) + dir];
    if (hit < 0x38) {
        self->x_pos.i.hi = SP_CUR_MAIN_OBJ->ext.main_19.unk86;
        self->y_pos.i.hi = SP_CUR_MAIN_OBJ->ext.main_19.unk88;
        SP_CUR_MAIN_OBJ->ext.main_19.unk83 ^= 1;
        if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index != 0) {
            SP_CUR_MAIN_OBJ->ext.main_19.unk80--;
        } else {
            SP_CUR_MAIN_OBJ->ext.main_19.unk80++;
        }
        SP_CUR_MAIN_OBJ->ext.main_19.unk80 &= 3;
        func_800F40E0(self);
    } else if (self->collision_flags & mask) {
        switch (mask) {
        case 1:
            box = self->terrain_box;
            self->x_pos.i.hi += box->unk0 + box->unk2;
            self->y_pos.i.hi += box->unk1;
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 = mask;
            break;
        case 2:
            box = self->terrain_box;
            self->x_pos.i.hi -= box->unk0 + box->unk2;
            self->y_pos.i.hi += box->unk1;
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 = 3;
            break;
        case 4:
            if (dir == 1) {
                self->x_pos.i.hi -= self->terrain_box->unk0;
            } else {
                self->x_pos.i.hi += self->terrain_box->unk0;
            }
            box = self->terrain_box;
            self->y_pos.i.hi -= box->unk1 + box->unk3;
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 = 2;
            break;
        case 8:
            if (dir == 1) {
                self->x_pos.i.hi -= self->terrain_box->unk0;
            } else {
                self->x_pos.i.hi += self->terrain_box->unk0;
            }
            box = self->terrain_box;
            self->y_pos.i.hi += box->unk1 + box->unk3;
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 = 0;
            break;
        default:
            animate_object(self);
            break;
        }
        func_800F40E0(self);
    } else {
        animate_object(self);
    }
    SP_CUR_MAIN_OBJ->ext.main_19.unk86 = self->x_pos.i.hi;
    SP_CUR_MAIN_OBJ->ext.main_19.unk88 = self->y_pos.i.hi;
    apply_object_motion(self);
    func_8002F288((M2C_UNK*)self);
}

#include "common.h"
#include "mmx6/x4.h"
extern struct X4_Unk_unk68* D_800FC644[4];
extern struct X4_Unk_unk68* D_800FC654[4];
extern struct X4_Unk_unk68* D_800FC664[4];
extern s16 D_800FC704[8];
extern s16 D_800FC714[8];
extern u8 D_800FC724[8];
extern u8 D_800FC72C[8];
s32 set_animation(void*, s32);

static inline void set_launch_39E8(struct X4_MainObj* self) {
    s32 index;
    index = (SP_CUR_MAIN_OBJ->ext.main_19.animation_index << 2) +
            SP_CUR_MAIN_OBJ->ext.main_19.unk80;
    self->x_speed = D_800FC704[index] << 16;
    self->y_speed = D_800FC714[index] << 16;
    self->unk15 = D_800FC724[index];
    set_animation(self, D_800FC72C[index]);
    self->hurt_box = D_800FC644[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
    self->attack_box = D_800FC654[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
    self->terrain_box = D_800FC664[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
}

void func_800F39E8(struct X4_MainObj* self) {
    if (self->action_phase == 0) {
        set_launch_39E8(self);
        self->action_phase = 1;
        self->unk7C = 0x1E;
        return;
    }
    if (--self->unk7C == 0) {
        self->action = 2;
        self->action_phase = 0;
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_19_surface_hopper.c:surface_hopper_update, AGPL-3.0; proven shared with X6 by exact signature a46c53ea4229 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800FC674[])(struct X4_MainObj*);
extern void (*D_800FC680[])(struct X4_MainObj*);

void func_800F3B38(struct X4_MainObj* self) {
    if (self->unk2 < 3) {
        D_800FC674[self->state](self);
    } else {
        D_800FC680[self->state](self);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800F3BB0(void) {
    ((M2C_UNK(*)())func_8002CA14)();
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_19_surface_hopper.c:surface_hopper_appear, AGPL-3.0; proven shared with X6 by exact signature 279ef0018214 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/system.h"
extern u8 D_800FC6A4[4];
s32 set_animation(void*, s32);
M2C_UNK animate_object();

void func_800F3BD0(struct X4_MainObj* self) {
    if (self->action_phase == 0) {
        self->action_phase = 1;
        set_animation(self,
                      D_800FC6A4[SP_CUR_MAIN_OBJ->ext.main_19.animation_index]);
        return;
    }

    if (self->animation_step.fields.relative_step < 0) {
        self->action = 2;
        self->action_phase = 0;
        SP_CUR_MAIN_OBJ->ext.main_19.unk80 = random_byte() & 1;
    }

    animate_object(ANIMATED_OBJECT(self));
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl, AGPL-3.0; proven shared with X6 by exact signature 6c2ea09cdb15 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800FC6A8[])(struct X4_MainObj*);

void func_800F3C64(struct X4_MainObj* self) {
    self->unk7C++;
    D_800FC6A8[self->action_phase](self);
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl_turn, AGPL-3.0; proven shared with X6 by exact signature c738d9c59df1 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 set_animation(void*, s32);
M2C_UNK animate_object();

void func_800F3CAC(struct X4_MainObj* self) {
    if (self->animation_step.fields.relative_step < 0) {
        self->action_phase = 3;
        if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index < 2) {
            set_animation(self, 0xB);
        } else {
            set_animation(self, 0xA);
        }
    }
    animate_object(ANIMATED_OBJECT(self));
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_19_surface_hopper.c:surface_hopper_crawl_turn_end, AGPL-3.0; proven shared with X6 by exact signature f1c046e43f2b (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK animate_object();

void func_800F3D24(struct X4_MainObj* self) {
    if (self->animation_step.fields.relative_step < 0) {
        self->action_phase = 0;
        SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
    }
    animate_object(ANIMATED_OBJECT(self));
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
extern s32 D_800FC62C[];

void func_800F3D74(void* arg0) {
    s32 var_a2;
    u8* temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        temp_v1 = SPAD;
        var_a2 = 7;
        if (temp_v1[0x81] < 2U) {
            var_a2 = 9;
            if (temp_v1[0x80] == 0) {
                var_a2 = 8;
            }
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
        } else {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
        }
        M2C_FIELD(arg0, s32*, 0x68) =
            D_800FC62C[(s8)M2C_FIELD(arg0, u8*, 2) >> 1];
        ((void (*)(void*, s32))set_animation)(arg0, var_a2);
        M2C_FIELD(arg0, u8*, 6) = 5;
        return;
    }
    animate_object(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F3E34(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    animate_object();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object();
M2C_UNK func_8002F288(M2C_UNK*);

void func_800F3E6C(u8* arg0) {
    move_object((s32)arg0);
    func_8002F288((M2C_UNK*)arg0);
    {
        // !FAKE: test byte lands in the first return register
        register s32 t asm("$2") = arg0[0x70];
        if (t != 0) {
            arg0[5] = 2;
            arg0[6] = 0;
        }
    }
}

#define func_8003744C func_800F3EB0
#define D_80073C1C D_800FC6CC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_19_surface_hopper.c:surface_hopper_leap_start, AGPL-3.0; proven shared with X6 by exact signature f3e8264e3395 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800FC6D4[];
s32 set_animation(void*, s32);

void func_800F3EEC(struct X4_MainObj* self) {
    self->action_phase = 1;
    self->unk7C = 0;
    set_animation(
        self, D_800FC6D4[SP_CUR_MAIN_OBJ->ext.main_19.animation_index >> 1]);
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
s32 func_8002D380(void*, void*);
void set_velocity_from_angle(void*, s32);

s32 func_800F3F38(void* arg0) {
    s32 ret;
    s16 dx;
    s16 dy;

    ret = 0;
    dx = g_Player.x_pos.i.hi - ((struct X4_PlayerObj*)arg0)->x_pos.i.hi;
    dy = g_Player.y_pos.i.hi - ((struct X4_PlayerObj*)arg0)->y_pos.i.hi;
    if ((dx < 0 ? -dx : dx) < 0x40 || (dy < 0 ? -dy : dy) >= 0x60) {
        ret = 1;
    }
    if ((dx < 0 ? -dx : dx) >= 0x80) {
        ret |= 2;
    }
    set_velocity_from_angle(arg0, func_8002D380(arg0, &g_Player));
    return ret;
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK func_8002F288(M2C_UNK*);

s32 func_800F3FF8(struct X4_MainObj* self, s32 a1, s32 a2) {
    s16 arg1 = a1;
    s16 arg2 = a2;
    s32 x = self->x_pos.val;
    s32 y = self->y_pos.val;
    s32 sx = self->unk18.val;
    s32 sy = self->unk1C.val;
    u8 r;

    self->unk18.val = x;
    self->unk1C.val = y;
    self->x_pos.i.hi += arg1;
    self->y_pos.i.hi += arg2;
    func_8002F288((M2C_UNK*)self);
    r = self->collision_flags;
    self->x_pos.val = x;
    self->y_pos.val = y;
    self->unk18.val = sx;
    self->unk1C.val = sy;
    self->collision_flags = 0;
    return r;
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_19_surface_hopper.c:surface_hopper_probe_tile, AGPL-3.0; proven shared with X6 by exact signature bc88cc45895f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
u8 func_80030234(struct X4_PlayerObj*, s16, s16);

u8 func_800F4094(struct X4_PlayerObj* self, s16 arg1, s16 arg2) {
    arg1 = self->x_pos.i.hi + arg1;
    arg2 = self->y_pos.i.hi + arg2;
    return func_80030234(self, arg1, arg2);
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_19_surface_hopper.c:surface_hopper_set_launch, AGPL-3.0; proven shared with X6 by exact signature 636a950af3be (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_Unk_unk68* D_800FC644[4];
extern struct X4_Unk_unk68* D_800FC654[4];
extern struct X4_Unk_unk68* D_800FC664[4];
extern s16 D_800FC704[8];
extern s16 D_800FC714[8];
extern u8 D_800FC724[8];
extern u8 D_800FC72C[8];
s32 set_animation(void*, s32);

void func_800F40E0(struct X4_MainObj* self) {
    s32 index;

    index = (SP_CUR_MAIN_OBJ->ext.main_19.animation_index << 2) +
            SP_CUR_MAIN_OBJ->ext.main_19.unk80;
    self->x_speed = D_800FC704[index] << 16;
    self->y_speed = D_800FC714[index] << 16;
    self->unk15 = D_800FC724[index];
    set_animation(self, D_800FC72C[index]);
    self->hurt_box = D_800FC644[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
    self->attack_box = D_800FC654[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
    self->terrain_box = D_800FC664[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
}

#define func_80041AB8 func_800F41EC
#define D_80075FD8 D_800FC73C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F4228(struct X4_PlayerObj* arg0) {
    // volatile local view keeps retail store order (sched1 otherwise sinks byte stores)
    volatile struct X4_PlayerObj* v = arg0;
    s32 x;
    // !FAKE: numeric pin holds retail register for the store-run schedule
    register s32 t asm("$5");
    // !FAKE: numeric pin holds retail register for the store-run schedule
    register void* p asm("$3");
    // !FAKE: numeric pin holds retail register for the store-run schedule
    register s32 x3 asm("$3");
    s32 y3;
    // !FAKE: numeric pin holds retail register for the store-run schedule
    register void* q asm("$2");

    t = 1;
    q = &D_800FC738;
    p = &D_800FC734;
    x = v->x_vel.val;
    v->terrain_box = q;
    v->state = t;
    v->on_screen = t;
    v->hp = t;
    t = v->y_vel.val;
    v->unk58 = &D_8007429C;
    v->unk16 = 0;
    v->unk54 = p;
    v->unk50 = p;
    v->unk60 = 3;
    x3 = x * 3;
    y3 = t * 3;
    v->x_vel.val = x3;
    arg0->y_vel.val = y3;
    set_animation(arg0, 0x11);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
s32 func_8002D654(s8*, u8*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);
extern struct X4_PlayerObj g_Player;

void func_800F42AC(void* arg0) {
    // !FAKE: separate state store tail in the second return register
    register s32 v asm("$3");

    animate_object();
    move_object(arg0);
    func_80030ECC(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        v = 2;
        // !FAKE: shared state store block with the 0x70 arm
        goto block_6;
    }
    if (func_8002D654((s8*)arg0, (u8*)&g_Player) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x70) != 0 ||
            (func_8002EE10(arg0), M2C_FIELD(arg0, u8*, 0x70) != 0)) {
            func_80049D90(arg0);
            v = 2;
        block_6:
            M2C_FIELD(arg0, u8*, 4) = v;
            return;
        }
        if (is_off_screen(arg0, 0x20, 0x20) == 0) {
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
    }
    M2C_FIELD(arg0, u8*, 4) = 2;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F4380(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F43A0);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F4514);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F55A8(void*);

extern M2C_UNK D_8007433C;
extern u8 D_800FC8D0[];
extern u8 D_800FC8D8[];

void func_800F461C(struct X4_PlayerObj* self) {
    struct X4_PlayerObj* parent;
    s8 kind;

    self->state++;
    self->on_screen = 1;
    self->hp = 1;
    self->unk60 = 6;
    self->unk50 = D_800FC8D0;
    self->unk58 = &D_8007433C;
    self->terrain_box = (void*)D_800FC8D8;
    self->unk54 = D_800FC8D0;
    kind = self->character;
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->y_vel.val = 0;
    self->gravity = 0;
    self->unk42 &= 0x7FFF;
    parent = M2C_FIELD(self, struct X4_PlayerObj**, 0x7C);
    if (kind == 0) {
        if (self->facing == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0x20;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0x20;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi - 8;
    } else if (kind == 1) {
        if (self->facing == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0x1D;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0x1D;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi + 0xE;
    } else {
        if (self->facing == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0xC;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0xC;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi + 0x12;
    }
    set_animation(self, 3);
    func_800F55A8(self);
    M2C_FIELD(self, s32*, 0x84) = 0x10;
    M2C_FIELD(self, s32*, 0x8C) = 0;
}

#define func_800EB950 func_800F4784
#define D_800F61F8 D_800FC8E0
#include "../shared/rock_15/func_800EB950.c"
#undef func_800EB950
#undef D_800F61F8

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F48E0);
// clang-format on

#define func_800EBC08 func_800F4A3C
#include "../shared/rock_15/func_800EBC08.c"
#undef func_800EBC08

#define func_800EA1D8 func_800F4BA4
#define D_800FAA64 D_800FC87C
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#define func_800EBDBC func_800F4BF0
#include "../shared/rock_15/func_800EBDBC.c"
#undef func_800EBDBC

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800F4C7C(struct ObjectHeader* arg0) {
    if (arg0->state == 3) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    ((M2C_UNK(*)())func_8002CA54)();
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4CBC(void* arg0) {
    M2C_FIELD(arg0, u8*, 5) = (u8)M2C_FIELD(arg0, u8*, 0x94);
}

#define func_8003744C func_800F4CC8
#define D_80073C1C D_800FC8AC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EBED0 func_800F4D04
#include "../shared/rock_15/func_800EBED0.c"
#undef func_800EBED0

#define func_800EBF3C func_800F4D70
#include "../shared/rock_15/func_800EBF3C.c"
#undef func_800EBF3C

#define func_8003744C func_800F4DD8
#define D_80073C1C D_800FC8B4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F4E14);
// clang-format on

#define func_800EC0E8 func_800F4F1C
#include "../shared/rock_15/func_800EC0E8.c"
#undef func_800EC0E8

#define func_8003744C func_800F4FF0
#define D_80073C1C D_800FC8BC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EC1F8 func_800F502C
#include "../shared/rock_15/func_800EC1F8.c"
#undef func_800EC1F8

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F5088);
// clang-format on

#define func_800EC2B0 func_800F50E4
#include "../shared/rock_15/func_800EC2B0.c"
#undef func_800EC2B0

#define func_8003744C func_800F512C
#define D_80073C1C D_800FC8C8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EC334 func_800F5168
#include "../shared/rock_15/func_800EC334.c"
#undef func_800EC334

#define func_800EC378 func_800F51AC
#include "../shared/rock_15/func_800EC378.c"
#undef func_800EC378

#define func_800EC3C8 func_800F51FC
#include "../shared/rock_15/func_800EC3C8.c"
#undef func_800EC3C8

#define func_800EC428 func_800F525C
#include "../shared/rock_15/func_800EC428.c"
#undef func_800EC428

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F52AC);
// clang-format on

#define func_800EC574 func_800F53A8
#define D_800F6154 D_800FC83C
#include "../shared/rock_15/func_800EC574.c"
#undef func_800EC574
#undef D_800F6154

#define func_800EC648 func_800F547C
#define D_800F6154 D_800FC83C
#include "../shared/rock_15/func_800EC648.c"
#undef func_800EC648
#undef D_800F6154

#define func_80041AB8 func_800F5544
#define D_80075FD8 D_800FC8F0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5580(void) {
    clear_object_slot();
}

#include "common.h"

void func_800F55A0(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F55A8);
// clang-format on

#define func_80041AB8 func_800F5650
#define D_80075FD8 D_800FC900
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EC858 func_800F568C
#include "../shared/rock_15/func_800EC858.c"
#undef func_800EC858

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800F56DC(void* arg0) {
    void* temp_v1;

    animate_object();
    temp_v1 = M2C_FIELD(arg0, void**, 0x50);
    if ((M2C_FIELD(temp_v1, s8*, 0) == 0) ||
        (M2C_FIELD(temp_v1, s32*, 0x8C) != 0)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_v1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_v1, u16*, 0xE);
    func_8002CCB0(arg0, 0x30, 0x30);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F574C(void) {
    clear_object_slot();
}

#define func_80041AB8 func_800F576C
#define D_80075FD8 D_800FC92C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EC974 func_800F57A8
#define D_800F6254 D_800FC93C
#include "../shared/rock_15/func_800EC974.c"
#undef func_800EC974
#undef D_800F6254

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F58CC);
// clang-format on

#define func_800ECB50 func_800F5984
#include "../shared/rock_15/func_800ECB50.c"
#undef func_800ECB50

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5A44(void) {
    clear_object_slot();
}

#include "common.h"

void func_800F5A64(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F5AAC(void*); /* extern */
M2C_UNK func_800F5B5C();   /* extern */

void func_800F5A6C(struct ObjectHeader* arg0) {
    if (arg0->state == 0) {
        func_800F5AAC(arg0);
        return;
    }
    func_800F5B5C();
}

#define func_800ECC78 func_800F5AAC
#include "../shared/rock_15/func_800ECC78.c"
#undef func_800ECC78

#define func_800ECD28 func_800F5B5C
#define D_80097420 D_80097420
#include "../shared/rock_15/func_800ECD28.c"
#undef func_800ECD28
#undef D_80097420

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F5C00);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800757DC;
extern s32 D_8007587C;
extern struct X4_PlayerObj g_Player;
extern void (*D_800FCF68[])(void*);

#define F(type, off) M2C_FIELD(self, type*, off)
#define O(type, off) M2C_FIELD(other, type*, off)
#define PL(type, off) M2C_FIELD(&g_Player, type*, off)

void func_800F5F50(void* self) {
    void* other;
    s32 r;

    struct X4_PlayerObj* pl = &g_Player;

    if (M2C_FIELD(pl, s8*, 0xE0) == 0) {
        D_800FCF68[F(s8, 5)](self);
    } else if (F(s8, 2) != 0) {
        animate_object(self);
    }
    func_80030ECC(self);
    r = check_enemy_hits(self);
    if (F(s8, 2) == 0) {
        if (F(u8, 0x8D) == 7) {
            struct X4_PlayerObj* pl = &g_Player;
            M2C_FIELD(pl, u8*, 0x7A) = 1;
            F(u8, 4) = 2;
            F(u8, 5) = 0;
            F(u8, 6) = 0;
            return;
        }
        if (F(s8, 5) != 2) {
            F(u8, 0x5C) = 0;
        }
        F(u8, 3) = 0;
        return;
    }
    if ((u8)(F(u8, 2) - 3) < 2) {
        other = F(void*, 0x88);
        if (O(s8, 5) != 2) {
            O(u8, 0x5C) = O(u8, 0x5C) + F(u8, 0x5C);
            if (O(s8, 0x5C) == -0x80) {
                O(u8, 0x5C) = 0x7F;
            }
        }
        if (r < 0) {
            O(u8, 0x8D) = O(u8, 0x8D) + F(u8, 2);
            ((void (*)(void*))func_80049E50)(self);
            F(u8, 4) = 3;
            F(u8, 5) = 0;
            F(u8, 6) = 0;
            return;
        }
        if (F(u8, 0x8C) == 0) {
            if (r != 0 && r != 0x7F) {
                F(void*, 0x58) = &D_8007433C;
                F(u8, 0x8C) = 0x1E;
                F(u16, 0x42) = F(u16, 0x42) | 0x8000;
            }
        } else {
            if (--F(u8, 0x8C) == 0) {
                F(void*, 0x58) = &D_800757DC;
                F(u16, 0x42) = F(u16, 0x42) & 0x7FFF;
                return;
            }
            if (!(F(volatile u8, 0x8C) & 1)) {
                F(u16, 0x42) = F(u16, 0x42) | 0x8000;
            } else {
                F(u16, 0x42) = F(u16, 0x42) & 0x7FFF;
            }
        }
    } else {
        other = F(void*, 0x84);
        if (O(s8, 4) == 2) {
            F(s32, 0x8) = F(s32, 0x18);
            F(s32, 0xC) = F(s32, 0x1C);
            F(u16, 0x42) = O(u16, 0x42);
            F(u8, 3) = O(u8, 3);
            return;
        }
        if (F(s8, 5) == 6 && O(u8, 0x8E) == 0 && F(u8, 0x8C) == 0) {
            F(void*, 0x58) = &D_8007587C;
        } else {
            F(void*, 0x58) = &D_8007433C;
        }
        {
            // !FAKE: depin: dropping it breaks the match (187/193)
            register void* a asm("$4") = &D_8007433C;
            F(void*, 0x58) = a;
        }
        if (O(u8, 0x8D) == F(s8, 2) + 2) {
            F(u16, 0x42) = F(u16, 0x42) & 0x7FFF;
        }
        if (F(u8, 0x8C) != 0) {
            if (--F(u8, 0x8C) != 0 && !(F(volatile u8, 0x8C) & 1)) {
                F(u16, 0x42) = F(u16, 0x42) | 0x8000;
            } else {
                F(u16, 0x42) = F(u16, 0x42) & 0x7FFF;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void set_boss_level();
void* func_8002BCCC(void*, s32);
M2C_UNK func_8003D308(M2C_UNK, u8);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800F6254(void* arg0) {
    s32 i;
    void* p;
    u8 v;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
        background_objects[0].unk26 = background_objects[0].unk24;
    }
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        u8* e = (u8*)&g_playthrough_state;
        e[0x8C] = 0x74;
        set_boss_level();
        v = e[0x8F];
        if (v == 0) {
            e[0x8C] += 4;
        } else if (v == 1) {
            e[0x8C] += 6;
        } else if (v == 2) {
            e[0x8C] += 8;
        } else {
            e[0x8C] += 9;
        }
        i = 0;
        do {
            p = func_8002BCCC(arg0, 0);
            if (p != 0) {
                M2C_FIELD(p, u8*, 0) = 0x41;
                M2C_FIELD(p, u8*, 1) = 0x3C;
                M2C_FIELD(p, u8*, 2) = i + 1;
                M2C_FIELD(p, u16*, 0xA) = 0x2080;
                if (i == 0) {
                    M2C_FIELD(p, u16*, 0xE) = 0x60;
                    M2C_FIELD(p, u16*, 0x7C) = 0;
                } else {
                    M2C_FIELD(p, u16*, 0xE) = 0x120;
                    M2C_FIELD(p, u16*, 0x7C) = 0x3C;
                }
                {
                    u8* e2 = (u8*)&g_playthrough_state;
                    s32 t = (s8)e2[0x8C];
                    M2C_FIELD(p, void**, 0x84) = arg0;
                    M2C_FIELD(p, s8*, 0x5C) = t / 2;
                }
            }
            i++;
        } while (i < 2);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        if (!(D_80097420.frame_counter & 0x3F)) {
            play_sound(2, 0x69, arg0);
        }
        {
            u8* e3 = (u8*)&g_playthrough_state;
            e3[0x24] = 1;
            e3[0x25] = 0;
            *(void**)(e3 + 0x20) = arg0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
void* func_8002BCCC(void*, s32);
void* func_8002C458();
s32 random_byte();

void func_800F6418(void* arg0) {
    void* s2;
    void* p;
    void* q;

    s2 = M2C_FIELD(arg0, void**, 0x84);
    if (M2C_FIELD(s2, s8*, 6) >= 4 && !(D_80097420.frame_counter & 7)) {
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x1E;
            M2C_FIELD(p, u8*, 2) = (random_byte() & 7) + 0xB;
            M2C_FIELD(p, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(p, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(p, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(p, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(p, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(p, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(p, void**, 0x7C) = arg0;
        }
    }
    animate_object(arg0);
    if (M2C_FIELD(s2, s8*, 6) == 5) {
        q = func_8002BCCC(arg0, 0);
        if (q != 0) {
            M2C_FIELD(q, u8*, 0) = 0x41;
            M2C_FIELD(q, u8*, 1) = 0x3C;
            M2C_FIELD(q, u8*, 2) = M2C_FIELD(arg0, u8*, 2) + 2;
            M2C_FIELD(q, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(q, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(q, u8*, 0x5C) = M2C_FIELD(arg0, u8*, 0x5C);
            M2C_FIELD(q, void**, 0x84) = arg0;
            M2C_FIELD(q, void**, 0x88) = M2C_FIELD(arg0, void**, 0x84);
        }
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 random_byte();
void func_800FA140(void* arg0);
extern s32 D_800FC954;
extern u8 D_800FD59C;

void func_800F6594(void* arg0) {
    void* s0;
    s16 r;
    s16 v;

    r = random_byte() & 3;
    s0 = M2C_FIELD(arg0, void**, 0x88);
    animate_object(arg0);
    func_800FA140(arg0);
    v = M2C_FIELD(s0, s16*, 0x7C);
    if (v == 0) {
        if (r == 0) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                M2C_FIELD(arg0, u8*, 0x93) = 3;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            }
        } else if (r == 1) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 2;
                M2C_FIELD(arg0, u8*, 0x93) = 0;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            }
        } else if (r == 2) {
            M2C_FIELD(arg0, s16*, 0x7E) = 1;
            M2C_FIELD(arg0, u8*, 0x93) = 3;
        } else if (r == 3) {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
        set_animation(arg0, 0xF);
    } else if (v == 1) {
        if (r < 2) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0;
                M2C_FIELD(arg0, u8*, 0x93) = 0;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            }
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
        set_animation(arg0, 0xE);
    } else if (v == 2) {
        if (r < 2) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 2;
                M2C_FIELD(arg0, u8*, 0x93) = 0;
                set_animation(arg0, 0xF);
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
                set_animation(arg0, 0xC);
            }
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            set_animation(arg0, 0xC);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
    } else if (v == 3) {
        if (r < 2) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 2;
                M2C_FIELD(arg0, u8*, 0x93) = 0;
                set_animation(arg0, 0xF);
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
                set_animation(arg0, 0xD);
            }
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            set_animation(arg0, 0xD);
        }
        M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
    } else if (v == 4) {
        if (D_800970AE > 0xD0) {
            if (M2C_FIELD(arg0, s8*, 0x8F) == 2) {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
                M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
                set_animation(arg0, 0xC);
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                M2C_FIELD(arg0, u8*, 0x93) = 3;
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
                M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
                set_animation(arg0, 0xF);
            }
        } else if (M2C_FIELD(arg0, s8*, 0x8F) == 2) {
            M2C_FIELD(arg0, s16*, 0x7E) = 0;
            M2C_FIELD(arg0, u8*, 0x93) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
            set_animation(arg0, 0xE);
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
            set_animation(arg0, 0xD);
        }
    } else if (v == 5) {
        if (D_800970AE > 0xD0) {
            if (M2C_FIELD(arg0, s8*, 0x8F) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
                M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
                set_animation(arg0, 0xD);
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                M2C_FIELD(arg0, u8*, 0x93) = 3;
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
                M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
                set_animation(arg0, 0xF);
            }
        } else if (M2C_FIELD(arg0, s8*, 0x8F) == 3) {
            M2C_FIELD(arg0, s16*, 0x7E) = 0;
            M2C_FIELD(arg0, u8*, 0x93) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
            set_animation(arg0, 0xE);
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
            set_animation(arg0, 0xC);
        }
    }
    play_sound(2, 0x6B, arg0);
    M2C_FIELD(arg0, void**, 0x54) = &D_800FC954;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
void* func_8002C458();
M2C_UNK move_object(s32);
s32 random_byte();
extern u16 D_800FD59A;

#define SPAWN_HEAD(kind)                                                       \
    c->active = 0x41;                                                          \
    c->id = 0x1E;                                                              \
    c->unk2 = kind;                                                            \
    c->unk42 = arg0->unk42 & 0x7FFF;                                           \
    c->animation_table = (u32**)arg0->animation_table;                         \
    c->unk3C = (void*)arg0->sprite_frames;                                     \
    c->unk40 = arg0->unk40;                                                    \
    c->bg_offset = arg0->bg_offset;

void func_800F69A0(struct X4_MainObj* arg0) {
    struct X4_ShotObj* c;
    s32 state;
    s32 n;
    s32 i;
    s8 k;

    ((void (*)())animate_object)();
    if (arg0->unk7C != 0) {
        ((void (*)(void*))move_object)(arg0);
        arg0->unk7C--;
        return;
    }
    state = arg0->unk7E;
    switch (state) {
    case 0:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(7)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi - 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
        }
        n = (u8)((u32)random_byte() % 3) + 1;
        for (i = 0; i < n; i++) {
            c = func_8002C458();
            if (c != 0) {
                SPAWN_HEAD(0)
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi - 0x20;
                c->unk7C = (void*)arg0;
            }
        }
        play_sound(2, 0x6F, arg0);
        M2C_FIELD(arg0, u8*, 0x93) = 0xB4;
        arg0->unk7C = (u8)((u32)random_byte() % 6) + 2;
        arg0->action_phase++;
        break;
    case 1:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(1)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
            c->x_vel.val = -0x20000;
            c->y_vel.val = 0;
        }
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(1)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
            c->x_vel.val = 0x20000;
            c->y_vel.val = 0;
        }
        arg0->unk7C = 0x5A;
        M2C_FIELD(arg0, u8*, 0x93)--;
        arg0->action_phase++;
        break;
    case 2:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(8)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
        }
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(2)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x20;
            c->unk7C = (void*)arg0;
        }
        M2C_FIELD(arg0, u8*, 0x93) = 0;
        arg0->unk7C = 0x12C;
        arg0->action_phase++;
        break;
    case 3:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(3)
            k = M2C_FIELD(arg0, s8*, 0x45);
            if (k == 0) {
                c->x_pos.i.hi = arg0->x_pos.i.hi + 0x10;
                c->y_pos.i.hi = arg0->y_pos.i.hi;
            } else if (k == 1) {
                c->x_pos.i.hi = arg0->x_pos.i.hi - 0x10;
                c->y_pos.i.hi = arg0->y_pos.i.hi;
            } else if (k == 2) {
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi - 0x10;
            } else if (k == 3) {
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            }
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
        }
        M2C_FIELD(arg0, u8*, 0x93)--;
        arg0->unk7C = D_800FD59A;
        arg0->action_phase++;
        break;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
void* func_8002C458();
s32 random_byte();
extern u16 D_800FD59A;

#define SPAWN_HEAD(kind)                                                       \
    c->active = 0x41;                                                          \
    c->id = 0x1E;                                                              \
    c->unk2 = kind;                                                            \
    c->unk42 = arg0->unk42 & 0x7FFF;                                           \
    c->animation_table = (u32**)arg0->animation_table;                         \
    c->unk3C = (void*)arg0->sprite_frames;                                     \
    c->unk40 = arg0->unk40;                                                    \
    c->bg_offset = arg0->bg_offset;

void func_800F6F9C(struct X4_MainObj* arg0) {
    struct X4_ShotObj* c;
    s32 state;
    s32 n;
    s32 i;
    s8 k;

    ((void (*)())animate_object)();
    if (arg0->unk7C != 0) {
        arg0->unk7C--;
        if (arg0->unk7E == 0) {
            if (M2C_FIELD(arg0, u8*, 0x93) != 0) {
                M2C_FIELD(arg0, u8*, 0x93)--;
            }
        }
        return;
    }
    state = arg0->unk7E;
    switch (state) {
    case 0:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(7)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi - 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
        }
        n = (u8)((u32)random_byte() % 3) + 1;
        for (i = 0; i < n; i++) {
            c = func_8002C458();
            if (c != 0) {
                SPAWN_HEAD(0)
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi - 0x20;
                c->unk7C = (void*)arg0;
            }
        }
        play_sound(2, 0x6F, arg0);
        if (M2C_FIELD(arg0, u8*, 0x93) != 0) {
            M2C_FIELD(arg0, u8*, 0x93)--;
        }
        arg0->unk7C = (u8)((u32)random_byte() % 6) + 2;
        break;
    case 1:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(1)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
            c->x_vel.val = -0x20000;
            c->y_vel.val = 0;
        }
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(1)
            c->x_pos.i.hi = arg0->x_pos.i.hi;
            c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
            c->x_vel.val = 0x20000;
            c->y_vel.val = 0;
        }
        arg0->unk7C = 0x5A;
        M2C_FIELD(arg0, u8*, 0x93)--;
        break;
    case 2:
        break;
    case 3:
        c = func_8002C458();
        if (c != 0) {
            SPAWN_HEAD(3)
            k = M2C_FIELD(arg0, s8*, 0x45);
            if (k == 0) {
                c->x_pos.i.hi = arg0->x_pos.i.hi + 0x10;
                c->y_pos.i.hi = arg0->y_pos.i.hi;
            } else if (k == 1) {
                c->x_pos.i.hi = arg0->x_pos.i.hi - 0x10;
                c->y_pos.i.hi = arg0->y_pos.i.hi;
            } else if (k == 2) {
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi - 0x10;
            } else if (k == 3) {
                c->x_pos.i.hi = arg0->x_pos.i.hi;
                c->y_pos.i.hi = arg0->y_pos.i.hi + 0x10;
            }
            c->unk15 = arg0->unk15;
            c->unk7C = (void*)arg0;
        }
        M2C_FIELD(arg0, u8*, 0x93)--;
        arg0->unk7C = D_800FD59A;
        break;
    }
    if (M2C_FIELD(arg0, u8*, 0x93) == 0) {
        if (arg0->x_speed != 0) {
            arg0->x_speed = -arg0->x_speed;
            arg0->unk7C = 0xB0;
        } else {
            arg0->unk7C = 0x90;
            arg0->y_speed = -arg0->y_speed;
        }
        arg0->action_phase++;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK animate_object();
void* func_8002C458();
s32 random_byte();
extern void (*D_800FD014[])(void*);

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800F74B8(u8* arg0) {
    u8* parent;
    u8* c;

    parent = FP(arg0, 0x84);
    ((void (*)())animate_object)();
    if (D_800CCF38 >= 2 && FU8(parent, 0x8D) != F8(arg0, 2) + 2) {
        if (FU8(arg0, 0x93) != 0) {
            FU8(arg0, 0x93)--;
        } else {
            c = func_8002C458();
            if (c != 0 && !(random_byte() & 1)) {
                FU8(c, 0) = 0x41;
                FU8(c, 1) = 0x1E;
                FU8(c, 2) = 0xA;
                FU16(c, 0x42) = FU16(arg0, 0x42) & 0x7FFF;
                F32(c, 0x30) = F32(arg0, 0x30);
                F32(c, 0x3C) = F32(arg0, 0x3C);
                FU16(c, 0x40) = FU16(arg0, 0x40);
                FU8(c, 0x14) = FU8(arg0, 0x14);
                FU16(c, 0xA) = FU16(arg0, 0xA);
                FU16(c, 0xE) = FU16(arg0, 0xE);
                FU8(c, 0x15) = FU8(arg0, 0x15);
                FP(c, 0x7C) = arg0;
            }
            FU8(arg0, 0x93) = (random_byte() & 3) * 0x10 + 0x60;
        }
    }
    if (FU8(parent, 0x8E) != 0) {
        if (F16(arg0, 0x7C) != 0) {
            F16(arg0, 0x7C)--;
        }
    } else {
        D_800FD014[F8(arg0, 6)](arg0);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA140(void* arg0);
extern s32 D_800FD5A0;

void func_800F7630(void* arg0) {
    void* s0;
    u8 t;
    s8 v;

    t = M2C_FIELD(arg0, u8*, 0x8E);
    s0 = M2C_FIELD(arg0, void**, 0x84);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = t - 1;
        return;
    }
    func_800FA140(arg0);
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(s0, u8*, 7)++;
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        ((u8*)s0 + 0x8F)[M2C_FIELD(arg0, s8*, 2)] = M2C_FIELD(arg0, u8*, 0x8F);
        return;
    }
    v = M2C_FIELD(arg0, s8*, 0x8F);
    if (v == 0) {
        if (M2C_FIELD(s0, u8*, 0x15) != 0) {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = -d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0xB0 / (d >> 4);
            }
        } else {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0x140 / (d >> 4);
            }
        }
    } else if (v == 1) {
        if (M2C_FIELD(s0, u8*, 0x15) == 0) {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = -d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0xB0 / (d >> 4);
            }
        } else {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0x140 / (d >> 4);
            }
        }
    } else if (v == 2) {
        if (M2C_FIELD(s0, u8*, 0x15) != 0) {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0x140 / (d >> 4);
            }
        } else {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0xB0 / (d >> 4);
            }
        }
    } else if (v == 3) {
        if (M2C_FIELD(s0, u8*, 0x15) != 0) {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0xB0 / (d >> 4);
            }
        } else {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0x140 / (d >> 4);
            }
        }
    }
    M2C_FIELD(arg0, u8*, 6)++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32); /* extern */

void func_800F7850(void* arg0) {
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_v0;
    u8 temp_v0;
    void* temp_s1;

    temp_v0 = M2C_FIELD(arg0, u8*, 0x8E);
    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = (u8)(temp_v0 - 1);
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
    }
    move_object(arg0);
    temp_v0_2 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0_2 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
    } else if (temp_v0_2 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
    } else {
        temp_v0_3 = M2C_FIELD(arg0, s32*, 0x24);
        if (temp_v0_3 > 0) {
            var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 4;
        } else if (temp_v0_3 < 0) {
            var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 8;
        } else {
            return;
        }
    }
    if (var_v0 != 0) {
        if (M2C_FIELD(temp_s1, s16*, 0x7C) != 0) {
            M2C_FIELD(arg0, u8*, 0x8E) = 0x28U;
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F7938(void* self) {
    void* other;
    s16 mode;
    s32 c;

    other = F(void*, 0x84);
    animate_object(self);
    {
        // !FAKE: depin: dropping it breaks the match (61/65)
        register s32 a asm("$2") = F(u16, 0xA);
        s32 b = F(u16, 0xE);
        F(u16, 0x94) = a;
        F(u16, 0x96) = b;
    }
    mode = M2C_FIELD(other, s16*, 0x7C);
    if (mode == 0) {
        c = F(u8, 6);
        F(s32, 0x24) = 0xFFFF0000;
        F(s32, 0x20) = 0;
        F(s32, 0x28) = 0;
        F(s32, 0x2C) = 0x4000;
        F(u8, 6) = c + 1;
    } else if (mode == 1) {
        c = F(u8, 6);
        F(s32, 0x24) = 0x10000;
        F(s32, 0x20) = 0;
        F(s32, 0x28) = 0;
        F(s32, 0x2C) = -0x4000;
        F(u8, 6) = c + 1;
    } else if (mode == 2) {
        F(u8, 6)++;
        F(s32, 0x20) = 0x10000;
        F(s32, 0x28) = -0x4000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
    } else if (mode == 3) {
        F(u8, 6)++;
        F(s32, 0x20) = 0xFFFF0000;
        F(s32, 0x28) = 0x4000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
    } else if (mode == 4) {
        // !FAKE: goto: mode 4 jumps into mode 5 arm; arms stay unmerged (no cross-jump)
        goto nine;
    } else if (mode == 5) {
    nine:
        F(u8, 5) = 9;
        F(u8, 6) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

#define HIT()                                                                  \
    {                                                                          \
        F(u8, 6)++;                                                            \
        start_pad_vibration(5);                                                \
        play_sound(0, 4, self);                                                \
        func_8002943C(0x5A, 5, 2);                                             \
    }

void func_800F7A3C(void* self) {
    animate_object();
    apply_object_motion(self);
    if (F(s32, 0x20) > 0) {
        if (F(s32, 0x20) > 0x40000) {
            F(s32, 0x20) = 0x40000;
        }
        if (F(u8, 0x70) & 1) {
            HIT();
        }
    } else if (F(s32, 0x20) < 0) {
        if (F(s32, 0x20) < -0x40000) {
            F(s32, 0x20) = -0x40000;
        }
        if (F(u8, 0x70) & 2) {
            HIT();
        }
    } else if (F(s32, 0x24) > 0) {
        if (F(s32, 0x24) > 0x40000) {
            F(s32, 0x24) = 0x40000;
        }
        if (F(u8, 0x70) & 4) {
            HIT();
        }
    } else if (F(s32, 0x24) < 0) {
        if (F(s32, 0x24) < -0x40000) {
            F(s32, 0x24) = -0x40000;
        }
        if (F(u8, 0x70) & 8) {
            HIT();
        }
    }
}

#undef F
#undef HIT

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
extern s32 D_800FD040[];
extern s32 D_800FD280[];
extern s32 D_800FD5A0;

void func_800F7B88(void* arg0) {
    void* s0;
    // !FAKE: pin table base register
    register s32 tbl asm("$6");
    s32 d;
    s32 x;
    s32 y;

    s0 = M2C_FIELD(arg0, void**, 0x84);
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        tbl = (s32)D_800FD040;
    } else {
        tbl = (s32)D_800FD280;
    }
    x = *(s32*)(((M2C_FIELD(s0, s16*, 0x7C) << 3) +
                 (M2C_FIELD(s0, s16*, 0x7E) * 3 << 4)) +
                tbl);
    d = D_800FD5A0;
    x *= d;
    M2C_FIELD(arg0, s32*, 0x20) = x;
    tbl += ((M2C_FIELD(s0, s16*, 0x7C) << 3) +
            (M2C_FIELD(s0, s16*, 0x7E) * 3 << 4));
    y = ((s32*)tbl)[1] * d;
    M2C_FIELD(arg0, s32*, 0x24) = y;
    if (x == 0 && y == 0) {
        M2C_FIELD(arg0, u8*, 6)++;
    }
    M2C_FIELD(arg0, u8*, 6)++;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
void func_800FA140(void* arg0);
extern s32 D_800FD5A0;

void func_800F7C74(void* arg0) {
    void* s1;
    s16 v;

    s1 = M2C_FIELD(arg0, void**, 0x84);
    animate_object(arg0);
    func_800FA140(arg0);
    v = M2C_FIELD(s1, s16*, 0x7C);
    if (v == 0) {
        s32 d;
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            // !FAKE: depin: dropping it breaks the match (80/83)
            register s32 c asm("$4");
            d = D_800FD5A0;
            c = M2C_FIELD(arg0, u8*, 6);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            d = -d;
            M2C_FIELD(arg0, s32*, 0x24) = d;
            M2C_FIELD(arg0, u8*, 6) = c + 1;
            return;
        }
    } else if (v == 1) {
        s32 d;
        if (M2C_FIELD(arg0, s8*, 0x8F) == 2) {
            d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = d;
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
    } else if (v == 2) {
        s32 d;
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = d;
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
    } else if (v == 3) {
        s32 d;
        if (M2C_FIELD(arg0, s8*, 0x8F) == 1) {
            d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -d;
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
    } else if ((u16)(M2C_FIELD(s1, u16*, 0x7C) - 4) >= 2) {
        return;
    }
    M2C_FIELD(s1, u8*, 7)++;
    M2C_FIELD(arg0, s8*, 5) = 5;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
}

#include "common.h"
#include "mmx6/globals.h"

s32 random_byte();

#define F6(p) (*(u8*)((u8*)(p) + 0x6))
#define F7(p) (*(s8*)((u8*)(p) + 0x7))
#define F7C(p) (*(s16*)((u8*)(p) + 0x7C))
#define F7E(p) (*(s16*)((u8*)(p) + 0x7E))
#define F90(p) (*(u8*)((u8*)(p) + 0x90))
#define F91(p) (*(u8*)((u8*)(p) + 0x91))

void func_800F7DC0(void* arg0) {
    s32 r;

    r = random_byte() & 3;
    if (F7(arg0) >= 2) {
        if (F7C(arg0) == 0) {
            if (r == 0) {
                F90(arg0) = 1;
                F91(arg0) = 3;
            } else if (r == 1) {
                F90(arg0) = 2;
                F91(arg0) = 3;
            } else if (r == 2) {
                F90(arg0) = 1;
                F91(arg0) = 1;
            } else if (r == 3) {
                F90(arg0) = r;
                F91(arg0) = r;
            }
        } else if (F7C(arg0) == 1) {
            if (r >= 2) {
                F90(arg0) = 3;
            } else {
                F90(arg0) = 0;
            }
            F91(arg0) = 3;
        } else if ((u16)(F7C(arg0) - 2) < 2) {
            if (r < 2) {
                F90(arg0) = 0;
            } else {
                F90(arg0) = 1;
            }
            F91(arg0) = 3;
        } else if ((u16)(F7C(arg0) - 4) < 2) {
            if (D_800970AE < 0xC0) {
                F90(arg0) = 0;
            } else {
                F90(arg0) = 1;
            }
            F91(arg0) = 3;
        }
        F7E(arg0) = 0;
        F7(arg0) = 0;
        F6(arg0) = F6(arg0) + 1;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)
#define SPAD28 (*(u8**)0x1F800028)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
s32 func_8002A47C(s32);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
s32 random_byte();
extern struct X4_PlayerObj g_Player;
extern s32 D_800FC970;
extern s32 D_800FC97C;
extern s32 D_800FC980;
extern s32 D_800FC984;
extern s32 D_800FC988;
extern s32 D_800FC98C;
extern s32 D_800FC990;
extern s32 D_800FCE98;
extern s32 D_800FCF50;
extern s32 D_800FD4F4[];
extern s32 D_800FD514[];

void func_800F7EE8(void* arg0) {
    s32 a;
    s32 b;
    s32 ang;
    s8 kind;

    kind = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s8*, 4) = 1;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x88) = 0;
    M2C_FIELD(arg0, s8*, 0x16) = 3;
    if (kind == 0) {
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x5000;
        M2C_FIELD(arg0, s32*, 0x20) = D_800FD4F4[random_byte() & 7];
        M2C_FIELD(arg0, s32*, 0x24) = D_800FD514[random_byte() & 7];
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC980;
        M2C_FIELD(arg0, void**, 0x68) = NULL;
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 0x24);
    } else if (kind == 1) {
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC980;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FC970;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0x32;
        ((void (*)(void*, s32))set_animation)(arg0, 0x19);
        play_sound(2, 0x6C, arg0);
    } else if (kind == 2) {
        play_sound(2, 0x6F, arg0);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FC97C;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = NULL;
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 0x24);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x12C;
    } else if (kind == 3) {
        ang = ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                     g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
        {
            s32 t;
            s32 w;
            s32 u;
            s32 x;
            t = rcos(ang);
            w = t << 4;
            M2C_FIELD(arg0, s32*, 0x20) = ((t << 6) + w) >> 1;
            u = -rsin(ang);
            x = u << 4;
            M2C_FIELD(arg0, s32*, 0x24) = ((u << 6) + x) >> 1;
        }
        M2C_FIELD(arg0, void**, 0x30) = &D_800FCE98;
        M2C_FIELD(arg0, s8*, 0x60) = 6;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC98C;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FC97C;
        M2C_FIELD(arg0, s8*, 5) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 0x1E);
        M2C_FIELD(arg0, s8*, 0x16) = 2;
        play_sound(2, 0x6C, arg0);
    } else if (kind == 4) {
        M2C_FIELD(arg0, s8*, 0x16) = 1;
        ((void (*)(void*, s32))set_animation)(arg0, 0x1F);
        M2C_FIELD(arg0, s8*, 5) = 5;
    } else if (kind == 5) {
        play_sound(2, 0x70, arg0);
        M2C_FIELD(arg0, u16*, 0x40) = 0x4A0;
        M2C_FIELD(arg0, u16*, 0x42) =
            (((func_8002A47C(0x3C) - 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(0x3C) + 7) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, void**, 0x3C) =
            (u8*)SPAD20 + SPAD20[func_8002A47C(0x3C) + 1];
        M2C_FIELD(arg0, void**, 0x30) = &D_800FCF50;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC988;
        M2C_FIELD(arg0, void**, 0x68) = NULL;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s8*, 0x60) = 8;
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x12C;
        M2C_FIELD(arg0, s8*, 0x15) = 0;
        a = func_8002A47C(0x3C) * 4;
        a += 0x24;
        load_palette(func_8002A47C(0x3C) * 4 + 0x1C, (s32*)((a << 5) + SPAD28),
                     4);
    } else if (kind == 6) {
        M2C_FIELD(arg0, u16*, 0x40) = 0x4A0;
        M2C_FIELD(arg0, u16*, 0x42) =
            (((func_8002A47C(0x3C) - 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(0x3C) + 7) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, void**, 0x3C) =
            (u8*)SPAD20 + SPAD20[func_8002A47C(0x3C) + 1];
        M2C_FIELD(arg0, void**, 0x30) = &D_800FCF50;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC984;
        M2C_FIELD(arg0, void**, 0x68) = NULL;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s8*, 0x60) = 8;
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x12C;
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    } else if (kind == 7) {
        M2C_FIELD(arg0, s8*, 0x16) = 2;
        ((void (*)(void*, s32))set_animation)(arg0, 0x17);
        M2C_FIELD(arg0, s8*, 5) = 5;
    } else if (kind == 8) {
        M2C_FIELD(arg0, s8*, 0x16) = 2;
        ((void (*)(void*, s32))set_animation)(arg0, 0x18);
        M2C_FIELD(arg0, s8*, 5) = 5;
    } else if (kind == 9) {
        M2C_FIELD(arg0, s8*, 0x60) = 8;
        play_sound(2, 0x6D, arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC990;
        M2C_FIELD(arg0, s8*, 0x16) = 2;
        M2C_FIELD(arg0, void**, 0x68) = NULL;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0x28;
        ((void (*)(void*, s32))set_animation)(arg0, 0x1C);
        M2C_FIELD(arg0, s8*, 5) = 4;
    } else if (M2C_FIELD(arg0, s8*, 2) == 10) {
        play_sound(2, 0x6C, arg0);
        ang = ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                     g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
        {
            s32 t;
            s32 w;
            s32 u;
            s32 x;
            t = rcos(ang);
            w = t << 4;
            M2C_FIELD(arg0, s32*, 0x20) = ((t << 5) + w) >> 1;
            u = -rsin(ang);
            x = u << 4;
            M2C_FIELD(arg0, s32*, 0x24) = ((u << 5) + x) >> 1;
        }
        M2C_FIELD(arg0, void**, 0x30) = &D_800FCE98;
        M2C_FIELD(arg0, s8*, 0x60) = 6;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC98C;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FC97C;
        M2C_FIELD(arg0, s8*, 5) = 6;
        ((void (*)(void*, s32))set_animation)(arg0, 0x1D);
        M2C_FIELD(arg0, s8*, 0x16) = 2;
    } else {
        if (M2C_FIELD(arg0, s8*, 2) == 20) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x29);
            M2C_FIELD(arg0, s16*, 0x8C) = 0x78;
            M2C_FIELD(arg0, s8*, 5) = 6;
        } else if (M2C_FIELD(arg0, s8*, 2) == 21) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x29);
            M2C_FIELD(arg0, s16*, 0x8C) = 0x3C;
            M2C_FIELD(arg0, s8*, 5) = 7;
        } else {
            play_sound(2, 0x6A, arg0);
            ((void (*)(void*, s32))set_animation)(
                arg0, M2C_FIELD(arg0, s8*, 2) - 0xB);
            M2C_FIELD(arg0, s16*, 0xA) =
                M2C_FIELD(arg0, s16*, 0xA) +
                ((s8)((u32)random_byte() % 7) * 16 - 0x30);
            M2C_FIELD(arg0, s16*, 0xE) =
                M2C_FIELD(arg0, s16*, 0xE) +
                ((s8)((u32)random_byte() % 7) * 16 - 0x30);
            M2C_FIELD(arg0, s8*, 0x15) = random_byte() & 0x40;
            M2C_FIELD(arg0, s8*, 5) = 5;
        }
        M2C_FIELD(arg0, s8*, 0x16) = 2;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void* func_8002C458();
M2C_UNK move_object(s32);
extern s16 D_800970AA;

void func_800F85E4(struct X4_MainObj* self) {
    struct X4_MainObj* o;
    u8 f;

    animate_object();
    move_object((s32)self);
    {
        // !FAKE: depin: dropping it breaks the match (146/148)
        register s32 t asm("$2") = self->collision_flags;
        if (t == 0) {
            return;
        }
    }
    {
        o = func_8002C458();
        if (o != 0) {
            o->active = 0x41;
            o->id = 0x1E;
            o->unk2 = 4;
            o->unk42 = self->unk42 & 0x7FFF;
            o->animation_table = self->animation_table;
            o->sprite_frames = self->sprite_frames;
            o->unk40 = self->unk40;
            o->bg_offset = self->bg_offset;
            o->x_pos.i.hi = self->x_pos.i.hi;
            o->y_pos.i.hi = self->y_pos.i.hi;
            o->unk15 = self->unk15;
            F32(o, 0x7C) = F32(self, 0x7C);
        }
        f = self->collision_flags;
        if (f & 8) {
            if (D_800970AA > self->x_pos.i.hi) {
                self->unk15 = 0x40;
                self->x_speed = 0x40000;
            } else {
                self->unk15 = 0;
                self->x_speed = -0x40000;
            }
            self->y_speed = 0;
            set_animation(self, 0x20);
        } else if (f & 4) {
            if (D_800970AA > self->x_pos.i.hi) {
                self->unk15 = 0x40;
                self->x_speed = 0x40000;
            } else {
                self->unk15 = 0;
                self->x_speed = -0x40000;
            }
            self->y_speed = 0;
            set_animation(self, 0x27);
        } else {
            if (f & 2) {
                if (D_800970AE > self->y_pos.i.hi) {
                    self->y_speed = -0x40000;
                    set_animation(self, 0x25);
                } else {
                    self->y_speed = 0x40000;
                    set_animation(self, 0x21);
                }
                self->unk15 = 0;
            } else {
                if (D_800970AE > self->y_pos.i.hi) {
                    self->y_speed = -0x40000;
                    set_animation(self, 0x25);
                } else {
                    self->y_speed = 0x40000;
                    set_animation(self, 0x21);
                }
                self->unk15 = 0x40;
            }
            self->x_speed = 0;
        }
        self->action_phase++;
        play_sound(2, 0x6E, self);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F8834(void* arg0) {
    u8 flags;

    animate_object();
    move_object((s32)arg0);
    if (F_S32(arg0, 0x20) > 0) {
        flags = F_U8(arg0, 0x70);
        if (flags & 1) {
            if (flags & 4) {
                F_S32(arg0, 0x24) = -0x40000;
                ((void (*)(void*, s32))set_animation)(arg0, 0x25);
            } else {
                F_S32(arg0, 0x24) = 0x40000;
                ((void (*)(void*, s32))set_animation)(arg0, 0x21);
            }
            F_U8(arg0, 0x15) = 0x40;
            F_S32(arg0, 0x20) = 0;
            F_U8(arg0, 0x6)++;
        }
    } else if (F_S32(arg0, 0x20) < 0) {
        flags = F_U8(arg0, 0x70);
        if (flags & 2) {
            if (flags & 4) {
                F_S32(arg0, 0x24) = -0x40000;
                ((void (*)(void*, s32))set_animation)(arg0, 0x25);
            } else {
                F_S32(arg0, 0x24) = 0x40000;
                ((void (*)(void*, s32))set_animation)(arg0, 0x21);
            }
            F_U8(arg0, 0x15) = 0;
            F_S32(arg0, 0x20) = 0;
            F_U8(arg0, 0x6)++;
        }
    } else if (F_S32(arg0, 0x24) > 0) {
        flags = F_U8(arg0, 0x70);
        if (flags & 4) {
            if (flags & 2) {
                F_U8(arg0, 0x15) = 0x40;
                F_S32(arg0, 0x20) = 0x40000;
            } else {
                F_U8(arg0, 0x15) = 0;
                F_S32(arg0, 0x20) = -0x40000;
            }
            ((void (*)(void*, s32))set_animation)(arg0, 0x27);
            F_S32(arg0, 0x24) = 0;
            F_U8(arg0, 0x6)++;
        }
    } else if (F_S32(arg0, 0x24) < 0) {
        flags = F_U8(arg0, 0x70);
        if (flags & 8) {
            if (flags & 2) {
                F_U8(arg0, 0x15) = 0x40;
                F_S32(arg0, 0x20) = 0x40000;
            } else {
                F_U8(arg0, 0x15) = 0;
                F_S32(arg0, 0x20) = -0x40000;
            }
            F_S32(arg0, 0x24) = 0;
            ((void (*)(void*, s32))set_animation)(arg0, 0x20);
            F_U8(arg0, 0x6)++;
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object();              /* extern */
M2C_UNK move_object(s32);              /* extern */

void func_800F89F4(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    u8 temp_v1;

    animate_object();
    move_object(arg0);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
        if (temp_v1 & 1) {
            if (temp_v1 & 4) {
                set_animation(arg0, 0x28);
            } else {
                set_animation(arg0, 0x22);
            }
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, u8*, 5) = 5;
            M2C_FIELD(arg0, u8*, 6) = 0;
            M2C_FIELD(arg0, u16*, 0xA) -= 8;
        }
    } else if (temp_v0 < 0) {
        temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
        if (temp_v1 & 2) {
            if (temp_v1 & 4) {
                set_animation(arg0, 0x28);
            } else {
                set_animation(arg0, 0x22);
            }
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, u8*, 5) = 5;
            M2C_FIELD(arg0, u8*, 6) = 0;
            M2C_FIELD(arg0, u16*, 0xA) += 8;
        }
    } else {
        temp_v0_2 = M2C_FIELD(arg0, s32*, 0x24);
        if (temp_v0_2 > 0) {
            temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
            if (temp_v1 & 4) {
                if (temp_v1 & 2) {
                    M2C_FIELD(arg0, u8*, 0x15) = 0;
                    set_animation(arg0, 0x23);
                } else {
                    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                    set_animation(arg0, 0x23);
                }
                M2C_FIELD(arg0, u8*, 5) = 5;
                M2C_FIELD(arg0, u8*, 6) = 0;
                M2C_FIELD(arg0, u16*, 0xE) += 8;
            }
        } else if (temp_v0_2 < 0) {
            temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
            if (temp_v1 & 8) {
                if (temp_v1 & 2) {
                    M2C_FIELD(arg0, u8*, 0x15) = 0;
                    set_animation(arg0, 0x26);
                } else {
                    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                    set_animation(arg0, 0x26);
                }
                M2C_FIELD(arg0, u8*, 5) = 5;
                M2C_FIELD(arg0, u8*, 6) = 0;
                M2C_FIELD(arg0, u16*, 0xE) -= 8;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void* func_8002C458();
M2C_UNK move_object(s32);
s32 random_byte();

void func_800F8BAC(void* arg0) {
    void* p;
    void* c;
    s32 v;
    s32 m;
    s32 i;
    s32 off;

    animate_object();
    ((void (*)(s32))move_object)((s32)arg0);
    p = M2C_FIELD(arg0, void**, 0x7C);
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0 || M2C_FIELD(p, s8*, 6) == 0 ||
        M2C_FIELD(p, s8*, 4) >= 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x1B);
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
        return;
    }
    v = M2C_FIELD(arg0, s32*, 0x20);
    if (v > 0) {
        m = M2C_FIELD(arg0, u8*, 0x70) & 1;
        // !FAKE: goto shares the mask test of both sign arms; nested if/else moved bytes
        goto test;
    }
    if (v < 0) {
        m = M2C_FIELD(arg0, u8*, 0x70) & 2;
    test:
        if (m != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -v;
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x8E) == 0) {
        off = 0x40;
        M2C_FIELD(arg0, u16*, 0x8E) =
            ((u8)((u32)random_byte() % 5) + 1) * 10 + 0x3C;
        i = 1;
        M2C_FIELD(arg0, u16*, 0x8E) =
            ((u8)((u32)random_byte() % 6) + 1) * 10 + 0x1E;
        do {
            c = func_8002C458();
            if (c != 0) {
                M2C_FIELD(c, s8*, 0) = 0x41;
                M2C_FIELD(c, s8*, 1) = 0x1E;
                M2C_FIELD(c, s8*, 2) = 9;
                M2C_FIELD(c, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(c, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(c, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(c, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(c, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
                M2C_FIELD(c, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(c, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + off;
                M2C_FIELD(c, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
            }
            i--;
            off += 0x40;
        } while (i >= 0);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800F8DC8);
// clang-format on

#define func_80041AB8 func_800F8E24
#define D_80075FD8 D_800FCF98
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();        /* extern */
M2C_UNK func_8003D308(M2C_UNK, u8); /* extern */

void func_800F8E60(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 3) {
        clear_object_slot();
        return;
    }
    func_8003D308(0x14, D_800970B5);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, s8*, 0x61) = 0x19;
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s8*, 5) = 1;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();

void func_800F8ECC(void* arg0) {
    void* temp_v0;
    s32 t;

    t = M2C_FIELD(arg0, u16*, 0x7C) - 1;
    M2C_FIELD(arg0, u16*, 0x7C) = t;
    if ((t << 0x10) == 0) {
        M2C_FIELD(arg0, u8*, 5) = 2;
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x1A;
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        if ((M2C_FIELD(arg0, s8*, 0x61) -= 5) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        {
            s32 v = M2C_FIELD(arg0, s8*, 0x61);
            // !FAKE: clamp result lives in the first return register
            register s32 m asm("$2");
            // !FAKE: compare result shares the first return register
            register s32 c asm("$2");

            if ((c = v < 6) != 0) {
                m = 5;
            } else {
                m = v;
            }
            M2C_FIELD(arg0, s16*, 0x7E) = m;
        }
    }
    M2C_FIELD(arg0, u8*, 3) = 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800F8FB4(void* arg0) {
    void* temp_v1;

    temp_v1 = M2C_FIELD(arg0, void**, 0x80);
    M2C_FIELD(arg0, s8*, 3) = 0;
    if (M2C_FIELD(temp_v1, s8*, 0) != 0) {
        if (M2C_FIELD(temp_v1, s8*, 7) == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        s32 y;
        g_playthrough_state.unkF = 0x10;
        g_playthrough_state.enable_boss = 0;
        g_playthrough_state.boss_ptr = 0;
        y = background_objects[0].y_pos.u.hi;
        background_objects[0].unk2A = y;
        clear_object_slot(arg0);
    }
}

#define func_8003744C func_800F9060
#define D_80073C1C D_800FCFA4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, u8); /* extern */

void func_800F909C(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();
M2C_UNK func_8003D308(M2C_UNK, u8);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FD598;

void func_800F90D4(void* arg0) {
    void* temp_v0;

    if (D_800CCEDF == 0 && D_800970A5 == 0x14) {
        background_objects[0].unk47 = 2;
        D_800FD598 = background_objects[0].unk48;
        func_8003D308(0x1D, 0x40);
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x18;
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = 0x80;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800F9170(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    if (!(D_80097420.frame_counter & 0x3F)) {
        play_sound(2, 0x69, arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800F91B0(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x79) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
    if (!(D_80097420.frame_counter & 0x3F)) {
        play_sound(2, 0x69, arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80040488(M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

void func_800F921C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) >= 2) {
        M2C_FIELD(arg0, s8*, 7) = 0;
        background_objects[0].unk48 = 2;
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
        background_objects[0].unk26 = 0x1F30;
        ((void (*)(s32))func_80040488)(0);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    if (!(D_80097420.frame_counter & 0x3F)) {
        play_sound(2, 0x69, arg0);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800F92B0(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F92EC(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

void func_800F9300(void) {
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003D330();
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF5C;
extern u8 D_800FD598;

void func_800F9308(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        play_sound(0, 0xE, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
    }
    if (++M2C_FIELD(arg0, s8*, 0x5C) == D_800CCF5C) {
        // !FAKE: base built straight in the first arg register
        register struct X4_BackgroundObj* bg asm("$4") = background_objects;
        s32 v = D_800FD598;
        bg->unk2A = 0x10;
        bg->unk48 = v;
        func_8003D330(bg, v);
        M2C_FIELD(arg0, u8*, 5) = 0xA;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

#define func_8003744C func_800F93A4
#define D_80073C1C D_800FCFCC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F93E0(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();

void func_800F9410(void* arg0) {
    u8* s1;

    s1 = *(u8**)((u8*)arg0 + 0x84);
    ((void (*)())animate_object)();
    if (*(s8*)((u8*)arg0 + 2) == 1) {
        *(u8*)((u8*)arg0 + 6) += 1;
        return;
    }
    if (*(s8*)((u8*)arg0 + 0x45) == 1) {
        s1[6] += 1;
        *(u8*)((u8*)arg0 + 6) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();

void func_800F9498(u8* arg0) {
    u8* s1;

    s1 = *(u8**)(arg0 + 0x84);
    ((void (*)())animate_object)();
    if ((*(s16*)(arg0 + 0x7C))++ >= 0x78) {
        s1[7]++;
        arg0[6]++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
extern s32 D_800FD5A0;

void func_800F950C(void* arg0) {
    void* temp_s1;

    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    animate_object();
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        if (M2C_FIELD(temp_s1, s8*, 6) == 7) {
            M2C_FIELD(arg0, s32*, 0x20) = (s32)-D_800FD5A0;
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    } else {
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, u8*, 6) = 0U;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(s32);

void func_800F9584(void* arg0) {
    void* parent;

    parent = M2C_FIELD(arg0, void**, 0x84);
    ((void (*)())animate_object)();
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(parent, u8*, 0x6)++;
        M2C_FIELD(arg0, u8*, 0x5) = 5;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}

#define func_8003744C func_800F95EC
#define D_80073C1C D_800FCFE4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK animate_object();                    /* extern */

void func_800F9628(void* arg0) {
    void* temp_s1;

    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_s1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_s1, u16*, 0xE);
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 0x10) {
        play_sound(2, 0x6B, arg0);
    }
    if ((M2C_FIELD(temp_s1, s32*, 4) & 0xFFFF00) == 0x900) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, s8*, 0x93) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(s32);

void func_800F96C4(void* arg0) {
    s8 v;

    ((void (*)(void))animate_object)();
    if (*(s16*)((u8*)arg0 + 0x7C) != 0) {
        ((void (*)(void*))move_object)(arg0);
        *(s16*)((u8*)arg0 + 0x7C) -= 1;
        return;
    }
    v = *(s8*)((u8*)arg0 + 0x45);
    if (v == 0) {
        set_animation(arg0, 0x2A);
    } else if (v == 1) {
        set_animation(arg0, 0x2B);
    } else if (v == 2) {
        set_animation(arg0, 0x2C);
    } else if (v == 3) {
        set_animation(arg0, 0x2D);
    }
    play_sound(2, 0x6B, arg0);
    *((u8*)arg0 + 6) += 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800F97A4(void* arg0) {
    animate_object(arg0);
    if (((s8*)arg0)[0x45] == 4) {
        ((void (*)(void*, s32))set_animation)(arg0, 0xB);
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F97F0(void* arg0) {
    void* temp_s1;

    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    ((void (*)())animate_object)();
    M2C_FIELD(temp_s1, u8*, 7) = (u8)(M2C_FIELD(temp_s1, u8*, 7) + 1);
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
}

#define func_8003744C func_800F9838
#define D_80073C1C D_800FD000
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define R22_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define R22_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define R22_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define R22_S32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK animate_object();
s32 random_byte();
extern u16 D_800FD5A4;

void func_800F9874(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x84);
    animate_object();
    {
        // !FAKE: depin: dropping it breaks the match (61/66)
        register s32 m asm("$2") = 0xFF00FF00;
        s32 k = 0xA00;
        if ((R22_S32(p, 4) & m) == k) {
            switch (R22_S8(p, 6)) {
            case 0:
                break;
            case 1:
                if (R22_S16(p, 0x7C) != 0) {
                    R22_U8(arg0, 0x8E) = 0x28;
                }
                {
                    s32 t = D_800FD5A4;
                    R22_S16(arg0, 0x7E) = 0;
                    R22_S16(arg0, 0x7C) = t;
                }
                R22_U8(arg0, 0x93) = ((random_byte() & 3) << 4) + 0x60;
                R22_U8(arg0, 5) = 6;
                R22_U8(arg0, 6) = 0;
                return;
            case 2:
                R22_S16(arg0, 0x7C) = 0;
                R22_S16(arg0, 0x7E) = 0;
                R22_U8(arg0, 5) = 8;
                R22_U8(arg0, 6) = 0;
                return;
            case 3:
                R22_U8(arg0, 5) = 9;
                R22_S16(arg0, 0x7C) = 0;
                R22_S16(arg0, 0x7E) = 0;
                R22_U8(arg0, 6) = 0;
                R22_U8(arg0, 7) = 0;
                if (R22_U8(p, 0x8D) == R22_S8(arg0, 2) + 2) {
                    R22_U8(arg0, 5) = 7;
                }
                break;
            }
        }
    }
}

#include "common.h"

void func_800F997C(void) {
}

#include "common.h"

void func_800F9984(void) {
}

#include "common.h"

void func_800F998C(void) {
}

#include "common.h"

void func_800F9994(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 random_byte();

void func_800F999C(void* arg0) {
    s32 temp_a0;
    u16 temp_v0;

    animate_object();
    temp_a0 = random_byte() & 3;
    if (D_80097420.frame_counter & 1) {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x94);
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x96);
    } else if (temp_a0 == 0) {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) + 1;
    } else if (temp_a0 == 1) {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) - 1;
    } else if (temp_a0 == 2) {
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + 1;
    } else if (temp_a0 == 3) {
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) - 1;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0x29) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */

void func_800F9A8C(u8* arg0) {
    u16 t;

    ((void (*)())animate_object)();
    t = *(u16*)(arg0 + 0x7C);
    *(u16*)(arg0 + 0x7C) = t + 1;
    if ((s16)t >= 0x79) {
        if (*(s32*)(arg0 + 0x20) > 0) {
            *(s32*)(arg0 + 0x20) = -0x30000;
        } else if (*(s32*)(arg0 + 0x20) < 0) {
            *(s32*)(arg0 + 0x20) = 0x30000;
        } else if (*(s32*)(arg0 + 0x24) > 0) {
            *(s32*)(arg0 + 0x24) = -0x30000;
        } else if (*(s32*)(arg0 + 0x24) < 0) {
            *(s32*)(arg0 + 0x24) = 0x30000;
        }
        arg0[6]++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800F9B30(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;

    animate_object();
    move_object(arg0);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
    } else if (temp_v0 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
    } else {
        temp_v0_2 = M2C_FIELD(arg0, s32*, 0x24);
        if (temp_v0_2 > 0) {
            var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 4;
        } else if (temp_v0_2 < 0) {
            var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 8;
        } else {
            return;
        }
    }
    if (var_v0 != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F9BD4(void* arg0) {
    animate_object();
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    M2C_FIELD(arg0, s8*, 5) = 9;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
}

#define func_8003744C func_800F9C20
#define D_80073C1C D_800FD01C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800F9C5C
#define D_80073C1C D_800FD034
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800F9C98(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;

    animate_object();
    move_object(arg0);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
    } else if (temp_v0 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
    } else {
        temp_v0_2 = M2C_FIELD(arg0, s32*, 0x24);
        if (temp_v0_2 > 0) {
            var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 4;
        } else if (temp_v0_2 < 0) {
            var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 8;
        } else {
            return;
        }
    }
    if (var_v0 != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F9D3C(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x84);
    M2C_FIELD(temp_a1, u8*, 7) = (u8)(M2C_FIELD(temp_a1, u8*, 7) + 1);
    M2C_FIELD(arg0, s8*, 5) = 5;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
}

#define func_8003744C func_800F9D68
#define D_80073C1C D_800FD4C0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();

void func_800F9DA4(void* arg0) {
    void* s0;

    s0 = M2C_FIELD(arg0, void**, 0x84);
    ((void (*)())animate_object)();
    if ((M2C_FIELD(arg0, s8*, 7) != 0) ||
        (M2C_FIELD(s0, u8*, 0x8D) == (M2C_FIELD(arg0, s8*, 2) + 2))) {
        M2C_FIELD(arg0, u8*, 6)++;
        M2C_FIELD(s0, u8*, 0x9A)++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();

void func_800F9E1C(u8* arg0) {
    u8* temp_s0;

    temp_s0 = *(u8**)(arg0 + 0x84);
    ((void (*)())animate_object)(arg0);
    if (*(s8*)(temp_s0 + 0x9A) >= 2) {
        arg0[6] = arg0[6] + 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
M2C_UNK move_object(s32); /* extern */

void func_800F9E74(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    void* temp_s1;

    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    animate_object();
    move_object(arg0);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
    } else if (temp_v0 < 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
    } else {
        temp_v0_2 = M2C_FIELD(arg0, s32*, 0x24);
        if (temp_v0_2 > 0) {
            var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 4;
        } else if (temp_v0_2 < 0) {
            var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 8;
        } else {
            return;
        }
    }
    if (var_v0 != 0) {
        M2C_FIELD(temp_s1, u8*, 7) = (u8)(M2C_FIELD(temp_s1, u8*, 7) + 1);
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
    }
}

#define func_8003744C func_800F9F38
#define D_80073C1C D_800FD4D0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;

void func_800F9F74(void* arg0) {
    // !FAKE: pin the engine base to the register retail uses
    register u8* e asm("$3");

    e = (u8*)&g_playthrough_state;
    if (M2C_FIELD(arg0, s8*, 0x5C) < ((s8)e[0x8C] / 2)) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    } else {
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
    }
    e = (u8*)&g_playthrough_state;
    if (e[0x68] >= 2U) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    if (!(random_byte() & 1)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, u8*, 0x9A) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}

#include "common.h"
#include "mmx6/x4.h"

s32 random_byte();
extern struct X4_PlayerObj g_Player;
extern u8 D_800FD4E4[];

void func_800FA01C(u8* arg0) {
    if (arg0[0x8E] != 0) {
        arg0[0x8E]--;
    }
    {
        volatile u8* pl = (u8*)&g_Player;
        arg0[0x93] = pl[0xA4];
    }
    if (*(s8*)(arg0 + 7) >= 2) {
        u8 c;
        u8 t;
        *(s16*)(arg0 + 0x7C) = (u8)((u32)random_byte() % 6);
        c = arg0[6];
        t = D_800FD4E4[*(s8*)(arg0 + 0x90) + *(s8*)(arg0 + 0x91) * 4];
        arg0[7] = 0;
        arg0[6] = c + 1;
        *(s16*)(arg0 + 0x7E) = (s8)t;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA0DC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) >= 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 7) = 0;
    }
}

#include "common.h"

void func_800FA108(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800757DC;

void func_800FA110(struct PlayerObj* arg0) {
    arg0->on_screen = 0;
    if (arg0->shot_cooldown != 0) {
        arg0->shot_cooldown = 0U;
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800757DC;
        arg0->on_screen = 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA140(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x8F) = 0U;
    if (M2C_FIELD(arg0, s16*, 0xA) >= 0x2009) {
        M2C_FIELD(arg0, u8*, 0x8F) = 1U;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) >= 0xC1) {
        M2C_FIELD(arg0, u8*, 0x8F) = (u8)(M2C_FIELD(arg0, u8*, 0x8F) + 2);
    }
}

#include "common.h"

void func_800FA188(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800FA190);
// clang-format on

#include "../shared/rock_22/func_800FA1EC.c"

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
void* func_8002C458();
M2C_UNK move_object();

void func_800FA24C(void* arg0) {
    void* p;

    animate_object();
    move_object(arg0);
    {
        // !FAKE: retail reads the test byte into the first return register
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x70);

        if (t == 0) {
            return;
        }
    }
    {
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x1E;
            M2C_FIELD(p, u8*, 2) = 5;
            M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(p, u16*, 0xA) = 0x1FC0;
            M2C_FIELD(p, u16*, 0xE) = 0x158;
            M2C_FIELD(p, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
        }
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x1E;
            M2C_FIELD(p, u8*, 2) = 6;
            M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(p, u16*, 0xA) = 0x2088;
            M2C_FIELD(p, u16*, 0xE) = 0x158;
            M2C_FIELD(p, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
        }
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800FA328(void* arg0) {
    ((void (*)())animate_object)();
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, u8*, 0) |= 0x10;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK animate_object();
s32 func_8002A47C(s32);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);

void func_800FA384(void* arg0) {
    s32 t;
    s32 r;
    s32 base;

    ((void (*)())animate_object)();
    M2C_FIELD(arg0, u16*, 0x8C) = (u16)(M2C_FIELD(arg0, u16*, 0x8C) + 1);
    if (M2C_FIELD(arg0, s8*, 2) == 5) {
        t = (func_8002A47C(0x3C) * 4) + 0x24;
        r = (func_8002A47C(0x3C) << 7) + 0x380;
        base = SPAD28;
        ((void (*)())func_8002B54C)(base + r, base + (t << 5), 0x40,
                                    M2C_FIELD(arg0, s16*, 0x8C));
        D_800C4560 |= 1;
    }
    if (M2C_FIELD(arg0, s16*, 0x8C) >= 0x1F) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}

#define func_800FA1EC func_800FA438
#define D_800FD534 D_800FD540
#include "../shared/rock_22/func_800FA1EC.c"
#undef func_800FA1EC
#undef D_800FD534

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */

void func_800FA498(struct ObjectHeader* arg0) {
    animate_object();
    apply_object_motion(arg0);
    if (is_off_screen(arg0, 0xF0, 0xF0) == 0) {
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    arg0->state = 2;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 random_byte();

void func_800FA4F8(u8* arg0) {
    u8* p;

    animate_object();
    p = *(u8**)(arg0 + 0x7C);
    if (*(s8*)(p + 6) == 0 || *(s8*)(p + 4) >= 2) {
        set_animation(arg0, 0x1B);
        *(s32*)(arg0 + 0x50) = 0;
        arg0[6] = 2;
        return;
    }
    if (*(s16*)(arg0 + 0x8C) != 0) {
        (*(s16*)(arg0 + 0x8C))--;
        return;
    }
    *(s16*)(arg0 + 0x8C) = 0x78;
    *(s16*)(arg0 + 0x8E) = ((u8)((u32)random_byte() % 5) + 1) * 10 + 0x3C;
    {
        u32 r = random_byte();
        arg0[6]++;
        *(s16*)(arg0 + 0x8E) = ((u8)(r % 6) + 1) * 10 + 0x1E;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800FA614(void* arg0) {
    animate_object();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_800FA1EC func_800FA64C
#define D_800FD534 D_800FD54C
#include "../shared/rock_22/func_800FA1EC.c"
#undef func_800FA1EC
#undef D_800FD534

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800FA6AC(void* arg0) {
    ((void (*)())animate_object)();
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                       /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800FA6F4(void* arg0) {
    animate_object();
    func_8002CCB0(arg0, 0x40, 0x40);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
M2C_UNK func_80030ECC(void*);
M2C_UNK func_80049D90(void*);

void func_800FA73C(u8* arg0) {
    animate_object();
    move_object((s32)arg0);
    {
        // !FAKE: test byte lands in the first return register
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
        if ((t != 0) || (func_80030ECC(arg0) != 0)) {
            func_80049D90(arg0);
            M2C_FIELD(arg0, u8*, 0x4) = 2;
            return;
        }
    }
    if (is_off_screen(arg0, 0xF0, 0xF0) == 0) {
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    M2C_FIELD(arg0, u8*, 0x4) = 2;
}

#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800FA7CC(u8* arg0) {
    u8* p;

    animate_object();
    p = M2C_FIELD(arg0, u8**, 0x7C);
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(p, u16*, 0xA);
    {
        // !FAKE: copied halfword lands in the second argument register
        register s32 t asm("$5") = M2C_FIELD(p, u16*, 0xE);
        M2C_FIELD(arg0, u16*, 0xE) = t;
        animate_object(arg0, t);
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x40, 0x40);
    if (M2C_FIELD(arg0, s16*, 0x8C) != 0) {
        M2C_FIELD(arg0, s16*, 0x8C) = M2C_FIELD(arg0, u16*, 0x8C) - 1;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 2;
}

#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80030ECC(void*);
extern void (*D_800FD558[])(void*);

void func_800FA848(u8* arg0) {
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    func_80030ECC(arg0);
    D_800FD558[M2C_FIELD(arg0, s8*, 0x5)](arg0);
}

#include "../shared/rock_22/func_800FA8A0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_8002F288(M2C_UNK*);
extern void (*D_800FD584[])(struct X4_MainObj*);

void func_800FA8C0(struct X4_MainObj* self) {
    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    D_800FD584[self->state](self);
    func_8002F288((M2C_UNK*)self);
    self->on_screen = 0;
}

#include "common.h"
#include "mmx6/globals.h"

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800FC948;
extern s32 D_800FC950;
extern s32 D_800FCE98;

void func_800FA920(void* arg0) {
    void* temp_a1;
    s32 b;
    s32 one;
    s32* p54;
    // !FAKE: regalloc
    register s32* p68 asm("$3");

    F(arg0, s32**, 0x30) = &D_800FCE98;
    one = 1;
    p54 = &D_800FC950;
    p68 = &D_800FC948;
    b = D_800970B4;
    temp_a1 = F(arg0, void**, 0x7C);
    F(arg0, u8*, 0x4) = one;
    F(arg0, u8*, 0x75) = one;
    F(arg0, s32**, 0x54) = p54;
    F(arg0, u8*, 0x62) = 0;
    F(arg0, u8*, 0x61) = 0;
    F(arg0, u8*, 0x3) = 0;
    F(arg0, u8*, 0x5) = 0;
    F(arg0, u8*, 0x6) = 0;
    F(arg0, s32**, 0x68) = p68;
    F(arg0, u8*, 0x5C) = 0;
    F(arg0, u8*, 0x60) = 6;
    F(arg0, u8*, 0x14) = b;
    F(arg0, s32*, 0x8) = F(temp_a1, s32*, 0x8);
    F(arg0, s32*, 0xC) = F(temp_a1, s32*, 0xC);
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK collide_solid_object();
M2C_UNK func_8003208C();
extern s32 D_800FC948;
extern s32 D_800FC950;

void func_800FA998(s32* arg0) {
    s32* self;
    u8* temp_s1;

    self = arg0;
    temp_s1 = (u8*)self[0x7C / 4];
    self[0x8 / 4] = *(s32*)(temp_s1 + 8);
    self[0xC / 4] = *(s32*)(temp_s1 + 0xC);
    func_8003208C();
    if (D_80097185 == 0) {
        collide_solid_object(self);
    }
    if (((s8*)temp_s1)[3] == 0) {
        self[0x54 / 4] = 0;
        self[0x68 / 4] = 0;
        return;
    }
    self[0x54 / 4] = (s32)&D_800FC950;
    self[0x68 / 4] = (s32)&D_800FC948;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FAA2C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800FAA4C);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800FC2B8);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800FC488);

INCLUDE_ASM("asm/rock_22/nonmatchings/E9860", func_800FD0CC);
// clang-format on
