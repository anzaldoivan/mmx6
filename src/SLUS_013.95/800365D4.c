#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                    /* extern */
s32 check_dash_input(struct X4_PlayerObj*); /* extern */
void end_dash(s32 arg0);                    /* extern */
M2C_UNK func_8003B298(void*);               /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);      /* extern */
M2C_UNK func_8003F700(void*);               /* extern */
s32 func_801ECA50(void*);                   /* extern */

void func_800365D4(void* arg0) {
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (check_dash_input(arg0) != 0) {
        func_8003B298(arg0);
        func_8003BA04(arg0, 0x55);
        {
            // !FAKE: depin: dropping it breaks the match (91/94)
            register s32 a asm("$2") = 0x1F;
            // !FAKE: depin: dropping it breaks the match (91/94)
            register s32 b asm("$3") = 4;
            M2C_FIELD(arg0, u8*, 5) = a;
            M2C_FIELD(arg0, u8*, 6) = b;
        }
        return;
    }
    ((void (*)())func_80017A04)(arg0);
    if ((M2C_FIELD(arg0, u16*, 0x7C) & 8) ||
        (M2C_FIELD(arg0, u16*, 0x80) & 0x80) ||
        !(M2C_FIELD(arg0, u8*, 0x89) & 4)) {
        M2C_FIELD(arg0, u8*, 7) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s8*, 7) = M2C_FIELD(arg0, u8*, 7) - 1;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003F700(arg0);
        } else if (func_801ECA50(arg0) != 0) {
            return;
        }
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            func_8003BA04(arg0, 0x8C);
        }
        if (M2C_FIELD(arg0, s8*, 0x90) != 0) {
            func_8003BA04(arg0, 0x54);
        }
    }
    if ((M2C_FIELD(arg0, s8*, 7) == 0) && (M2C_FIELD(arg0, s8*, 0x46) == 0)) {
        end_dash((s32)arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
M2C_UNK func_8002D5D0(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003D394(void* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_8003674C(struct X4_MainObj* arg0) {
    ((void (*)())func_80017A04)();
    if (arg0->unk6 == 0) {
        if (arg0->animation_step.fields.relative_step == 0) {
            background_objects[0].unk28 = background_objects[0].y_pos.i.hi;
            background_objects[0].unk2A = background_objects[0].y_pos.i.hi;
            background_objects[0].unk20 = background_objects[0].y_pos.i.hi;
            background_objects[0].unk22 = background_objects[0].y_pos.i.hi;
            ((void (*)(void*, s32))func_8003BA04)(arg0, 4);
            arg0->terrain_box = 0;
            arg0->unk6++;
        }
    } else {
        if (func_8002CBFC(arg0, 0x20, 0x40) == 0) {
            func_8002D5D0(arg0);
            func_8003D394(arg0);
            return;
        }
        arg0->on_screen = 0;
        arg0->state = 3;
        arg0->unk5 = 0;
        arg0->unk6 = 0;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80039C40(void*);
s32 func_80039CFC(void*);
s32 try_enter_ladder(void*);
s32 func_8003A628(void*);
void func_8003AD18(void* arg0);
M2C_UNK func_8003AE8C(void*);
s32 func_801EA560(void*);
s32 func_801EBE04(void*);
s32 func_801EBE54(void*);
s32 func_801EBEDC(void*);
s32 func_801EC86C(void*);

void func_80036800(void* arg0) {
    if ((func_8003A628(arg0) == 0) && (try_enter_ladder(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (func_80039C40(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0)))) {
        if (func_80039CFC(arg0) != 0) {
            func_8003AE8C(arg0);
            return;
        }
        ((void (*)())func_80017A04)(arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
            func_8003AD18(arg0);
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
s32 select_air_dash(void*);            /* extern */
s32 func_80039984(void*);              /* extern */
s32 try_enter_wall_cling(void*);              /* extern */
s32 func_8003A488(void*);              /* extern */
s32 check_ceiling_jump();              /* extern */
M2C_UNK func_8003B054(void*);          /* extern */
void func_8003D18C(void* arg0);        /* extern */
void func_8003D394(void* arg0);        /* extern */
s32 func_8003E174(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA454(void*);              /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EC028();                   /* extern */

void func_800368FC(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        if (((s32(*)())check_ceiling_jump)() == 0) {
            func_8003B054(arg0);
        }
    } else {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            var_v0 = func_8003E174(arg0);
            goto block_8;
        }
        if ((func_801EA560(arg0) == 0) && (func_801EA454(arg0) == 0)) {
            var_v0 = func_801EC028(arg0);
        block_8:
            if ((var_v0 == 0) && (func_8003A488(arg0) == 0) &&
                (func_80039984(arg0) == 0) && (try_enter_wall_cling(arg0) == 0) &&
                (select_air_dash(arg0) == 0)) {
                func_80017A04(arg0);
                func_8003D18C(arg0);
                func_8003D394(arg0);
                func_8003F508(arg0, 0xB);
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
s32 func_80039C9C(void*);
s32 try_enter_ladder(void*);
s32 func_8003A628(void*);
s32 check_ceiling_jump(void*);
void func_8003ADB4(void* arg0);
s32 func_8003F13C(void*);
M2C_UNK func_8003F508(void*, M2C_UNK);
s32 func_801EBE04(void*);
s32 func_801EBE54(void*);
s32 func_801EBEDC(void*);
s32 func_801EC86C(void*);

void func_80036A04(void* arg0) {
    if ((func_8003A628(arg0) == 0) && (try_enter_ladder(arg0) == 0) &&
        (check_ceiling_jump(arg0) == 0) && (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EBE04(arg0) == 0))) &&
        (player_check_dash_jump_walk(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0))) &&
        (func_80039C9C(arg0) == 0)) {
        ((void (*)())func_80017A04)(arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
            func_8003ADB4(arg0);
            return;
        }
        func_8003F508(arg0, 0xC);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
s32 func_8003A33C(void*);              /* extern */
M2C_UNK func_8003AFF4(s32);            /* extern */
M2C_UNK func_8003B054(void*);          /* extern */
void func_8003B548(void*);             /* extern */
s32 func_8003E174(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */

void func_80036B10(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        func_8003B054(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        if (func_8003E174(arg0) != 0) {
            return;
        }
        if (M2C_FIELD(arg0, u8*, 0x89) & 3) {
            goto block_main;
        }
    }
    func_8003AFF4((s32)arg0);
    return;
block_main:
    if (func_8003A33C(arg0) == 0) {
        ((void (*)())func_80017A04)(arg0);
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            if (M2C_FIELD(arg0, u8*, 0x89) & 1) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            M2C_FIELD(arg0, u8*, 0x45) &= 0x3F;
        }
        if (--M2C_FIELD(arg0, s8*, 0x8A) == 0) {
            func_8003B548(arg0);
            return;
        }
        func_8003F508(arg0, 0xD);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80036C68(); /* extern */
void func_80036D4C(); /* extern */

void func_80036C28(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        func_80036C68();
        return;
    }
    func_80036D4C();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CFB0(void* arg);
M2C_UNK func_8003AFF4(s32);
void func_8003D394(void* arg0);
s32 func_8003E174(void*);
M2C_UNK func_8003F508(void*, M2C_UNK);

void func_80036C68(void* arg0) {
    s32 var_a1;
    s32 var_v0;
    u8 temp_a0;
    u8 temp_v0;
    s32 t4;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        ((void (*)())func_8003AFF4)();
        return;
    }
    if (func_8003E174(arg0) == 0) {
        temp_a0 = M2C_FIELD(arg0, u8*, 0x89);
        t4 = temp_a0 & 4;
        var_a1 = t4 != 0;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            var_v0 = temp_a0 & 2;
        } else {
            var_v0 = temp_a0 & 1;
        }
        if (var_v0 != 0) {
            var_a1 = 1;
        }
        if (var_a1 != 0) {
            func_8003AFF4((s32)arg0);
            return;
        }
        ((void (*)())func_80017A04)(arg0);
        func_8002CFB0(arg0);
        func_8003D394(arg0);
        if (--M2C_FIELD(arg0, s8*, 0x8A) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            return;
        }
        func_8003F508(arg0, 0xE);
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();        /* extern */
s32 select_air_dash(void*);     /* extern */
s32 func_80039984(void*);       /* extern */
s32 try_enter_wall_cling(void*);       /* extern */
s32 func_8003A488(void*);       /* extern */
void func_8003D18C(void* arg0); /* extern */
void func_8003D394(void* arg0); /* extern */
s32 func_8003E174(void*);       /* extern */
void player_set_animation_shooting(struct X4_PlayerObj* self,
                                   s32 animation); /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK);             /* extern */
s32 func_801EBF94(void*);                          /* extern */

void func_80036D4C(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x89) & 4) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 0x80)) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        var_v0 = func_8003E174(arg0);
    } else {
        var_v0 = func_801EBF94(arg0);
    }
    if ((var_v0 == 0) && (func_8003A488(arg0) == 0) &&
        (func_80039984(arg0) == 0) && (try_enter_wall_cling(arg0) == 0) &&
        (select_air_dash(arg0) == 0)) {
        func_80017A04(arg0);
        func_8003D18C(arg0);
        func_8003D394(arg0);
        if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            player_set_animation_shooting(arg0, 0xB);
            M2C_FIELD(arg0, s8*, 0x67) = -1;
            M2C_FIELD(arg0, s8*, 5) = 7;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        func_8003F508(arg0, 0xE);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK handle_slide_down(); /* extern */
M2C_UNK func_80036FBC();     /* extern */

void func_80036E70(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        handle_slide_down();
        return;
    }
    func_80036FBC();
}
