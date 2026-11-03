#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void animate_object(struct X4_AnimatedObj*);
extern void (*D_801F36F8[])(void*);

void update_hover(s8* arg0) {
    if (arg0[0xD3] != 0) {
        ((void (*)())func_8003AFF4)();
        return;
    }
    if (try_shoot_in_air(arg0) == 0) {
        animate_object((struct X4_AnimatedObj*)arg0);
        D_801F36F8[arg0[6]](arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void animate_object(struct X4_AnimatedObj*);
M2C_UNK end_dash(s32);
M2C_UNK player_load_weapon_palette();
extern void (*D_801F3724[])(void*);

void func_801EB844(s8* arg0) {
    if (arg0[0xD3] != 0) {
        arg0[0xE0] = 0;
        ((void (*)())player_load_weapon_palette)();
        end_dash((s32)arg0);
        return;
    }
    animate_object((struct X4_AnimatedObj*)arg0);
    D_801F3724[arg0[6]](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void animate_object(struct X4_AnimatedObj*);
s32 try_enter_ladder(void*);
extern void (*D_801F3730[])(s8*);

void update_air_dash(s8* p) {
    if (((u8*)p)[0x89] & 8) {
        player_land(p);
        return;
    }
    if (p[0xD3] != 0) {
        func_8003AFF4((s32)p);
        return;
    }
    if ((func_80039984(p) == 0) && (try_enter_ladder(p) == 0)) {
        animate_object((struct X4_AnimatedObj*)p);
        D_801F3730[p[6]](p);
    }
}

#include "../shared/rock_00/func_801EB968.c"

#define func_8003744C func_801EB9B0
#define D_80073C1C D_801F3748
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void animate_object(struct X4_AnimatedObj*);
void* func_8002C32C();
M2C_UNK end_dash(s32);
void func_801EC6D0(void*, s32);

void func_801EB9EC(u8* arg0) {
    u8* obj;

    if (((s8*)arg0)[0xD3] != 0) {
        ((M2C_UNK(*)())end_dash)();
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        end_dash((s32)arg0);
        return;
    }
    animate_object((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[7] == 0) {
        func_801EC6D0(arg0, 0x32);
    } else {
        func_801EC6D0(arg0, 0x33);
    }
    if (arg0[0x45] & 1) {
        arg0[0x45] &= 0xFE;
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2E;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
        }
    }
    if (((s8*)arg0)[0x46] == 0) {
        end_dash((s32)arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void animate_object(struct X4_AnimatedObj*);
void* func_8002C32C();
s32 func_80039C40(void*);
s32 check_crouch_input(void*);
M2C_UNK end_dash(s32);

void func_801EBAE0(u8* arg0) {
    u8* obj;

    if (((s8*)arg0)[0xD3] != 0) {
        ((void (*)())end_dash)();
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        // !FAKE: goto: shared call block inlined where retail lays it (C0115)
        goto call;
    }
    animate_object((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[0x45] & 0x80) {
        arg0[0x45] &= 0x7F;
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x32;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
            obj[0x15] = arg0[0x15];
        }
    }
    if (((s8*)arg0)[0x46] == 0) {
    call:
        end_dash((s32)arg0);
        return;
    }
    if (((s8*)arg0)[0x93] == 0 && (arg0[0x45] & 0x40) &&
        func_80039C40(arg0) == 0) {
        check_crouch_input(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void animate_object(struct X4_AnimatedObj*);
M2C_UNK end_dash(s32);
extern void (*D_801F3778[])(void*);

void func_801EBBEC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        end_dash((s32)arg0);
        return;
    }
    animate_object((struct X4_AnimatedObj*)arg0);
    D_801F3778[M2C_FIELD(arg0, s8*, 6)](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void animate_object(struct X4_AnimatedObj*);
struct X4_VisualObj* find_free_visual_obj(void);
M2C_UNK end_dash(s32);

void func_801EBC58(struct X4_MainObj* self) {
    struct X4_VisualObj* v;

    animate_object((struct X4_AnimatedObj*)self);
    if (self->action_phase == 0 && (self->animation_step.fields.event & 0x80)) {
        v = find_free_visual_obj();
        if (v != 0) {
            v->active = 9;
            v->id = 0x17;
            v->unk2 = 0;
            v->animation_step.fields.frame_index = 3;
        }
        self->action_phase++;
    }
    if (self->animation_step.fields.relative_step == 0) {
        end_dash((s32)self);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

void animate_object(struct X4_AnimatedObj*);
M2C_UNK end_dash(s32);

void func_801EBCF4(s8* arg0) {
    s32 var_a0;

    animate_object((struct X4_AnimatedObj*)arg0);
    var_a0 = 0;
    if ((arg0[0x99] == 0) || (arg0[0x93] != 3)) {
        var_a0 = 1;
    }
    if ((arg0[0x46] == 0) && (arg0[6] == 1)) {
        var_a0 = 1;
    }
    if (var_a0 != 0) {
        end_dash((s32)arg0);
    }
}

#include "../shared/rock_00/func_801EBD70.c"

#define func_801EBD70 func_801EBDCC
#define D_801F3760 D_801F376C
#include "../shared/rock_00/func_801EBD70.c"
#undef func_801EBD70
#undef D_801F3760

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

void animate_object(struct X4_AnimatedObj*);
M2C_UNK end_dash(s32);

void func_801EBE28(s8* arg0) {
    s32 var_a0;

    animate_object((struct X4_AnimatedObj*)arg0);
    var_a0 = 0;
    if ((arg0[0x99] == 0) || (arg0[0x93] != 7)) {
        var_a0 = 1;
    }
    if ((arg0[0x46] == 0) && (arg0[6] == 1)) {
        var_a0 = 1;
    }
    if (var_a0 != 0) {
        end_dash((s32)arg0);
    }
}

#define func_801EB968 func_801EBEA4
#define D_801F3738 D_801F3758
#include "../shared/rock_00/func_801EB968.c"
#undef func_801EB968
#undef D_801F3738

#define func_8003744C func_801EBEEC
#define D_80073C1C D_801F3780
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation(void*, M2C_UNK);
extern u8 func_801F3698[];

// str 0x801F3698 sha1=4f9ab48fb4b5a74dbaff79949a7171d7221c076e = "printable byte run: data, not text"
M2C_UNK func_801EBF28(void* arg0) {
    player_set_animation(arg0, func_801F3698[M2C_FIELD(arg0, s8*, 0x96)]);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK player_set_animation(void*, M2C_UNK);
extern u8 D_801F36C8[];

// str 0x801F36C8 sha1=05619cf61313e05817cc31351c1b4dda443ee78a = "printable byte run: data, not text"
M2C_UNK func_801EBF5C(void* arg0) {
    u8 v;

    v = D_801F36C8[*(s8*)((u8*)arg0 + 0x97)];
    ((void (*)(void*, s32))player_set_animation)(arg0, v);
    if (v == 0x5D) {
        *(u8*)((u8*)arg0 + 0x44) = *(u8*)((u8*)arg0 + 0x91) - 8;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_spawn_visual(M2C_UNK, M2C_UNK, s8, M2C_UNK);

void func_801EBFBC(void* arg0) {
    ((void (*)(void*, s32))func_8003F508)(arg0, 0x15);
    if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, u8*, 0x45) &= 0x7F;
        player_spawn_visual(0x21, 0x21, 0, 0);
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 check_dash_input(void*);     /* extern */
s32 try_enter_wall_cling(void*); /* extern */
M2C_UNK func_8003B298(void*);    /* extern */
s32 func_801EC35C();             /* extern */
s32 func_801EC3AC(void*);        /* extern */
void player_hover_set_direction(struct X4_PlayerObj* self,
                                s32 direction); /* extern */

void player_hover_idle(struct PlayerObj* arg0) {
    s32 temp_v0;

    if ((func_801EC35C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        if ((check_dash_input(arg0) != 0) && (arg0->shot_cooldown == 0)) {
            func_8003B298(arg0);
            return;
        }
        temp_v0 = func_801EC3AC(arg0);
        if (temp_v0 != 0) {
            arg0->is_clone = 0x28;
            player_hover_set_direction(arg0, temp_v0);
            return;
        }
        func_8003F508(arg0, 0x15);
    }
}
