#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;
extern s8 D_8009724F;
extern s8 D_800CCEF6;

void func_800EC580(void* self) {
    M2C_FIELD(self, s32*, 0x80) = 0;
    M2C_FIELD(self, s32*, 0x84) = 0;
    M2C_FIELD(self, s32*, 0x88) = 0;
    M2C_FIELD(self, s32*, 0x8C) = 0;
    M2C_FIELD(self, s32*, 0x90) = 0;
    M2C_FIELD(self, s32*, 0x94) = 0;
    if (M2C_FIELD(self, s8*, 0x2) >= 4) {
        D_8009724F = 0;
        D_800CCEF6 = 1;
        if ((M2C_FIELD(self, s8*, 0x2) == 5) && (g_Player.x_pos.i.hi < 0x3B0)) {
            if (g_Player.y_pos.i.hi < 0x1B0) {
                g_Player.y_pos.i.hi = 0x1B0;
            }
        } else {
            clear_object_slot(self);
        }
    } else {
        clear_object_slot(self);
    }
}

#define func_8003744C func_800EC630
#define D_80073C1C D_800F3F58
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern void (*D_800F3F6C[])(void*);

void func_800EC66C(s8* arg0) {
    if (g_Player.y_pos.i.hi < 0x1B0) {
        g_Player.y_pos.i.hi = 0x1B0;
    }
    D_800F3F6C[arg0[6]](arg0);
}

#define func_8003744C func_800EC6C8
#define D_80073C1C D_800F3F7C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EC704
#define D_80073C1C D_800F3F8C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EC740
#define D_80073C1C D_800F3FB0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800F3FC4[])(void*);

void func_800EC77C(void* self) {
    struct X4_BackgroundObj* bg;
    void* a;
    void* b;

    D_800F3FC4[M2C_FIELD(self, s8*, 6)](self);
    if ((u32)(M2C_FIELD(self, u8*, 2) - 8) < 2) {
        bg = background_objects;
        bg[2].y_pos.val += 0xFFFF0000;
        a = M2C_FIELD(self, void**, 0x84);
        b = M2C_FIELD(self, void**, 0x88);
        M2C_FIELD(a, u16*, 0x90)++;
        M2C_FIELD(b, u16*, 0x90)++;
        if (M2C_FIELD(self, s16*, 0x7E)++ >= 0x70) {
            play_sound(5, 3, self);
            bg[2].unk3 = 0;
            if (M2C_FIELD(self, s8*, 6) == 4 && bg[1].unk3 == 0) {
                bg[0].unk28 = 0xB00;
                bg[0].unk2A = 0x3B0;
                M2C_FIELD(self, s8*, 4) = 3;
                M2C_FIELD(a, s8*, 4) = 2;
                M2C_FIELD(b, s8*, 4) = 2;
            }
        }
    }
}

#define func_8003744C func_800EC8A0
#define D_80073C1C D_800F3FD8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EC8DC
#define D_80073C1C D_800F3FE0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC918(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0x10000;
    M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EC940(void* self) {
    if (F(s16, 0x7C) != 0) {
        F(s16, 0x7C)--;
        return;
    }
    if (F(s32, 0x20) > 0x1FFFF) {
        F(s32, 0x20) = 0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (F(u8, 0x70) & 1) {
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        {
            // !FAKE: pin the -0x1000 constant so it loads before the first store
            register s32 k asm("$3") = -0x1000;
            F(s32, 0x24) = 0x10000;
            F(s32, 0x20) = 0;
            F(s32, 0x28) = 0;
            F(s32, 0x2C) = k;
        }
        F(s16, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        F(u8, 6)++;
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ECA04(void* self) {
    if (F(s16, 0x7C) != 0) {
        F(s16, 0x7C)--;
        return;
    }
    if (F(s32, 0x24) > 0x1FFFF) {
        F(s32, 0x24) = 0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (F(u8, 0x70) & 4) {
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        F(s32, 0x20) = 0xFFFF0000;
        F(s32, 0x28) = 0x1000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
        F(s16, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        F(u8, 6)++;
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800ECAC8(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) - 1;
        return;
    }
    if (M2C_FIELD(arg0, s32*, 0x20) <= -0x20000) {
        M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        play_sound(2, 0x18, arg0);
        func_80012D9C(3);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x1000;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ECB88(void* self) {
    if (F(s16, 0x7C) != 0) {
        F(s16, 0x7C)--;
        return;
    }
    if (F(s32, 0x24) <= -0x20000) {
        F(s32, 0x24) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (F(u8, 0x70) & 8) {
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        F(s16, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        F(u8, 6) = 0;
    }
}

#undef F

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECC24(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0x10000;
    M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ECC4C(void* self) {
    if (F(s16, 0x7C) != 0) {
        F(s16, 0x7C)--;
        return;
    }
    if (F(s32, 0x20) > 0x1FFFF) {
        F(s32, 0x20) = 0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (F(u8, 0x70) & 1) {
        play_sound(2, 0x18, self);
        func_80012D9C(3);
        F(s32, 0x20) = 0xFFFF0000;
        F(s32, 0x28) = 0x1000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
        F(s16, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        F(u8, 6)++;
    }
}

#undef F

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECD10(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800ECD24(u8* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) - 1;
        return;
    }
    if (M2C_FIELD(arg0, s32*, 0x20) <= -0x20000) {
        M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x18, arg0);
        ((void (*)(s32))func_80012D9C)(3);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        ((void (*)(s32, s32, s32))func_8002943C)(0x3C, 2, 1);
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}

#include "common.h"

void func_800ECDC0(u8* arg0) {
    arg0[0x8C] = 0;
    *(s32*)(arg0 + 0x20) = 0xFFFF0000;
    *(s32*)(arg0 + 0x24) = 0xFFFF0000;
    *(s32*)(arg0 + 0x28) = 0x1000;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[6] = 3;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECDE8(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

void func_800ECDFC(u8* arg0) {
    *(s32*)(arg0 + 0x20) = 0xFFFF0000;
    *(s32*)(arg0 + 0x24) = 0xFFFF0000;
    *(s32*)(arg0 + 0x28) = 0x1000;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[6] = 3;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800ECE20(struct X4_MainObj* self) {
    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->x_speed > 0x1FFFF) {
        self->x_speed = 0x20000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (self->collision_flags & 1) {
        play_sound(2, 0x18, self);
        ((void (*)(s32))func_80012D9C)(3);
        self->unk7C = 0x3C;
        func_8002943C(0x3C, 2, 1);
        self->unk6 = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ECEC0(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800ECED4(void* arg0) {
    if (F(s16, 0x7C) != 0) {
        F(s16, 0x7C) = F(u16, 0x7C) - 1;
        return;
    }
    if (F(s32, 0x20) <= -0x20000) {
        F(s32, 0x20) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    if (F(u8, 0x70) & 2) {
        play_sound(2, 0x18, arg0);
        func_80012D9C(3);
        F(s32, 0x20) = 0x10000;
        F(s32, 0x28) = -0x1000;
        F(s16, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        F(u8, 6) = 1;
    }
}

#undef F

#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();

void func_800ECF84(u8* arg0) {
    s16 var_v0_2;
    s8 temp_v1;

    if (random_byte() & 1) {
        M2C_FIELD(arg0, s16*, 0xA) = 0xB80;
        M2C_FIELD(arg0, u8*, 0x8E) =
            (M2C_FIELD(arg0, u8*, 0x8E) + 0x10) & 0x1F0;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = 0xC20;
        M2C_FIELD(arg0, u8*, 0x8E) = (M2C_FIELD(arg0, u8*, 0x8E) + 1) & 0xF;
    }
    temp_v1 = M2C_FIELD(arg0, s8*, 0x8E);
    if (temp_v1 == 3) {
        var_v0_2 = 0xB80;
        // !FAKE: goto into the shared store block for both matching counter values
        goto block_7;
    }
    if (temp_v1 == 0x30) {
        var_v0_2 = 0xC20;
    block_7:
        M2C_FIELD(arg0, s16*, 0xA) = var_v0_2;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
    }
    {
        // !FAKE: numeric pin loads the -0x1000 constant early into the second return register
        register s32 b asm("$3") = -0x1000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = b;
        M2C_FIELD(arg0, u8*, 0x6) = 2;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED02C(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D230(void*);
extern s16 D_80097222;

void func_800ED040(struct X4_MainObj* self) {
    s32 v;

    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->y_speed > 0x2FFFF) {
        self->y_speed = 0x30000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (self->y_pos.i.hi < D_80097222 + 0x90) {
        v = self->gravity;
        if (v < 0) {
            self->gravity = -v;
        }
    }
    if (self->y_speed < 0) {
        self->y_speed = -0x10000;
        self->gravity = 0x1000;
        self->unk7C = 0x5A;
        self->unk6 = 4;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED0F8(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*);
extern s16 D_80097222;

void func_800ED10C(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s8*, 0x8D) = 1;
        M2C_FIELD(arg0, s16*, 0x7C)--;
        return;
    }
    M2C_FIELD(arg0, s8*, 0x8D) = 0;
    if (M2C_FIELD(arg0, s32*, 0x24) <= -0x20000) {
        M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    if (D_80097222 + 0x1A0 < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800ED190(void* arg0) {
    s32 x = D_800970AA;

    if (M2C_FIELD(arg0, s16*, 0xA) < x) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x10000;
        M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        return;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x28) = 0x1000;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 3;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_800970AA;
M2C_UNK func_8002D230(void*);

void func_800ED1F8(struct X4_MainObj* self) {
    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->x_speed > 0x1FFFF) {
        self->x_speed = 0x20000;
    }
    if (((self->x_pos.i.hi - D_800970AA) < 0
             ? (D_800970AA - self->x_pos.i.hi)
             : (self->x_pos.i.hi - D_800970AA)) < 0x30 ||
        self->x_pos.i.hi > 0xE90) {
        self->y_speed = 0x10000;
        self->gravity = -0x1000;
        self->x_speed = 0;
        self->x_accel = 0;
        self->unk7C = 0x32;
        self->unk6++;
        return;
    }
    func_8002D230(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D230(void*);
extern s16 D_80097222;

void func_800ED2B8(struct X4_MainObj* self) {
    s32 v;

    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->y_speed > 0x2FFFF) {
        self->y_speed = 0x30000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (self->y_pos.i.hi < D_80097222 + 0xC0) {
        v = self->gravity;
        if (v < 0) {
            self->gravity = -v;
        }
    }
    if (self->y_speed < 0) {
        self->y_speed = -0x10000;
        self->gravity = 0x1000;
        self->unk7C = 0x5A;
        self->unk6 = 4;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800ED370(struct X4_MainObj* self) {
    s32 d;
    s16 x;
    u16 xu;

    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->x_speed <= -0x20000) {
        self->x_speed = -0x20000;
    }
    x = self->x_pos.i.hi;
    xu = self->x_pos.u.hi;
    d = x - D_800970AA;
    if ((d < 0 ? D_800970AA - x : d) < 0x30 || (s16)xu < 0xCE0) {
        self->y_speed = 0x10000;
        self->gravity = -0x1000;
        self->x_speed = 0;
        self->x_accel = 0;
        self->unk7C = 0x32;
        self->unk6 = 2;
        return;
    }
    ((void (*)())func_8002D230)(self, x, xu);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*);
extern s16 D_80097222;

void func_800ED424(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = 1;
        M2C_FIELD(arg0, s16*, 0x7C) -= 1;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x8D) = 0;
    if (M2C_FIELD(arg0, s32*, 0x24) <= -0x20000) {
        M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
    }
    ((void (*)(void*))func_8002D230)(arg0);
    if ((D_80097222 + 0x160) < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800ED4A4(struct X4_MainObj* arg0) {
    if ((u32)((u8)arg0->unk2 - 8) < 2) {
        background_objects[0].unk28 = background_objects[0].unk2A;
        play_sound(5, 1, arg0);
        func_80012D9C(4);
    }
    arg0->unk7C = 0x78;
    arg0->unk6++;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_80090D5C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

void func_800ED514(void* arg0) {
    D_800CF854 = 0x1F;
    D_80097430 = 0x3E0;
    D_80090D5C = 0x7C00;
    D_800C4560 |= 1;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B2F8(s32);                                  /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s16 D_80090D5C;
extern s8 D_8009724F;
extern s16 D_80097430;
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800CF854;

void func_800ED55C(void* arg0) {
    s32 var_s0;

    func_8002B2F8(0);
    var_s0 = 0xB;
    D_80090D5C = 0;
    D_80097430 = 0;
    D_800CF854 = 0;
    g_playthrough_state.enable_boss = 0;
    g_playthrough_state.boss_ptr = 0;
    D_8009724F = 0;
    do {
        func_80049EBC(arg0, 1, 0x40, 0x40);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED5EC(void* arg0) {
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 8) >= 2U) {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);

extern struct X4_PlayerObj g_Player;
extern s8 D_8009724F;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F3F14;

void func_800ED610(struct X4_MainObj* self) {
    if (self->unk2 == 4) {
        if (g_Player.y_pos.i.hi >= 0xA11) {
            D_8009724F = 1;
        }
    }
    if (g_Player.unk5 == 0x14) {
        g_playthrough_state.gameplay_locked = 1;
        if (self->unk2 == 4) {
            func_80027BA0(0, 0x4C0, 0x930, &D_800F3F14);
        }
        g_playthrough_state.enable_boss = 1;
        M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x7F;
        set_boss_level();
        g_playthrough_state.unk25 = 0;
        g_playthrough_state.boss_ptr = self;
        self->unk7E = 3;
        self->unk6++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8003D330();                     /* extern */
#include "mmx6/state.h"

void func_800ED6E8(void* arg0) {
    s8 kind;

    if (--M2C_FIELD(arg0, s16*, 0x7E) == 0) {
        play_sound(0, 0xE, 0);
        M2C_FIELD(arg0, u16*, 0x7E) = 3;
    }
    if (!(D_80097420.frame_counter & 1)) {
        if ((s8)++M2C_FIELD(arg0, u8*, 0x5C) == 0x7F) {
            func_8003D330();
            kind = M2C_FIELD(arg0, s8*, 0x2);
            if (kind == 4) {
                M2C_FIELD(arg0, u8*, 0x5) = 2;
            } else if (kind == 5) {
                M2C_FIELD(arg0, u8*, 0x5) = 3;
            } else if (kind == 6) {
                M2C_FIELD(arg0, u8*, 0x5) = 4;
            } else if (kind == 7) {
                M2C_FIELD(arg0, u8*, 0x5) = 5;
            } else if (kind == 0xA) {
                M2C_FIELD(arg0, u8*, 0x5) = 7;
            }
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

void func_800ED7D8(void* arg0) {
    struct X4_BackgroundObj* bg;

    if (!(D_80097420.frame_counter & 3)) {
        func_80029478(3, 2, 1);
    }
    bg = background_objects;
    bg[2].y_pos.val += 0x8000;
    if (bg[2].y_pos.i.hi >= 0x6B0) {
        play_sound(5, 3, arg0);
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s16 D_80097222;

void func_800ED860(void* arg0) {
    if (!(D_80097420.frame_counter & 3)) {
        func_80029478(3, 2, 1);
    }
    if (!(D_80097420.frame_counter & 0x1F)) {
        play_sound(2, 3, arg0);
    }
    M2C_FIELD(arg0, s32*, 0xC) = (s32)(M2C_FIELD(arg0, s32*, 0xC) + 0xFFFF0000);
    if ((D_80097222 + 0xC0) >= M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();

extern struct X4_EngineObj g_playthrough_state;

void func_800ED904(struct X4_MainObj* self) {
    g_playthrough_state.enable_boss = 1;
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x7F;
    set_boss_level(0);
    g_playthrough_state.unk25 = 0;
    g_playthrough_state.boss_ptr = self;
    self->unk7E = 3;
    self->unk6++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);              /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8003D330();                     /* extern */

void func_800ED968(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7E) == 0) {
        play_sound(0, 0xE, 0);
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
    }
    if (!(D_80097420.frame_counter & 1)) {
        if (++M2C_FIELD(arg0, s8*, 0x5C) == 0x7F) {
            func_8003D330();
            M2C_FIELD(arg0, u8*, 5) = 6;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x1000;
            M2C_FIELD(arg0, u8*, 6) = 4;
            play_sound(5, 1, arg0);
            func_80012D9C(4);
        }
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EDA3C(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800EDA5C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();    /* extern */
M2C_UNK move_object(void*); /* extern */

void func_800EDAB8(s32 arg0) {
    func_80017A04();
    move_object(arg0);
}

#include "common.h"

void func_800EDAE4(void) {
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F3F0C[];

void func_800EDAEC(void* arg0) {
    if ((u32)D_80097420.frame_counter ==
        (u32)D_80097420.frame_counter / 10 * 10) {
        M2C_FIELD(arg0, u8*, 0x92) = (M2C_FIELD(arg0, u8*, 0x92) + 1) & 3;
        if (M2C_FIELD(arg0, s16*, 0xA) == 0xCE0) {
            background_objects[2].unk40 =
                D_800F3F0C[M2C_FIELD(arg0, u8*, 0x92)] - 0xCA0;
        } else {
            background_objects[2].unk40 =
                D_800F3F0C[M2C_FIELD(arg0, u8*, 0x92)] - 0xB20;
        }
    }
    background_objects[2].unk4C = 1;
}

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800EDB90);
// clang-format on

#define func_800EE70C func_800EDCD0
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EE70C.c"
#undef func_800EE70C
#undef g_Player

#define func_800EE800 func_800EDDC4
#define D_80097420 D_80097420
#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EDDC4(u8* arg0) {
    s32 a;
    s32 b;
    void* t;

    a = FU16(arg0, 0x80) + 1;
    b = FU16(arg0, 0x82) - 1;
    FU16(arg0, 0x80) = a;
    FU16(arg0, 0x82) = b;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (D_80097420.transition.active == 0) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi = FU16(arg0, 0x84);
        t = *(void**)(arg0 + 0x88);
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk19 = 0;
        g_Player.unk68 = t;
    }
}
#undef func_800EE800
#undef D_80097420

#define func_800EE8C4 func_800EDE88
#define background_objects background_objects
#include "../shared/commander_yammark/func_800EE8C4.c"
#undef func_800EE8C4
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800EDF88);

INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800EE37C);
// clang-format on

#define func_800EA1D8 func_800EE488
#define D_800FAA64 D_800F4068
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#define func_800EEF10 func_800EE4D4
#define D_800F7808 D_800F4078
#include "../shared/commander_yammark/func_800EEF10.c"
#undef func_800EEF10
#undef D_800F7808

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EE550(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    func_8002CA54();
}

#define func_800EEFCC func_800EE590
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EEFCC.c"
#undef func_800EEFCC
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;
extern s8 D_800CCEF6;

void func_800EE608(void* arg0) {
    if ((D_800CCEF6 == 0) && (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA))) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EE654(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800EE690
#define D_80073C1C D_800F4090
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EE6CC
#define D_80073C1C D_800F412C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF144 func_800EE708
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;
extern s8 D_800CCEDF;

void func_800EE708(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        D_800CCEDF = M2C_FIELD(arg0, u8*, 2) | 0x40;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF144

#define func_800EF1E8 func_800EE7AC
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;

void func_800EE7AC(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF1E8

#define func_800EF27C func_800EE840
#define D_80097420 D_80097420
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

extern s16 D_800970AA;

void func_800EE840(void* arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, u16*, 0x80) - 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x82) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a2;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a1;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a2;
    } else {
        D_800970AA = temp_a1;
    }
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF27C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EE8A8(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_9C (*(s32**)0x1F80009C)
#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
s32 random_byte();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_80074FBC;
extern u8 D_800970B4;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F414C;
extern s32 D_800F4154;
extern s32 D_800F42B4;
extern u16 D_800F447C;
extern u16 D_800F447E;
#define D_800F447E (*(s16*)&D_800F447E)
extern s16 D_800F4480;
#define D_800F4480 (*(u16*)&D_800F4480)
extern s16 D_800F4482;
extern s16 D_800F4484;
extern s16 D_800F4486;
extern s16 D_800F448E;
extern s32 D_800F4490;

void func_800EE8C8(struct X4_MainObj* self) {
    s32 i;
    u16 a;
    u16 e;
    void* o;
    s32* p;
    u8 t;
    u16 v;

    if (g_playthrough_state.stage == 0xC) {
        p = SCRATCH_9C;
        self->sprite_frames = (u8*)p + *p;
        self->unk42 = 0x7948;
    }
    D_800F447C = 0x1130;
    D_800F448E = 0;
    self->contact_damage = 4;
    self->hp = 0;
    self->unk62 = 0;
    self->unk40 = 0x140;
    if (g_playthrough_state.stage == 0xC) {
        D_800F447E = -0x810;
        D_800F4480 = 0x150;
        D_800F4482 = -0xA00;
        D_800F4484 = -0xF0;
        D_800F4486 = 0x800;
        background_objects[1].y_pos.i.hi = 0x800;
    } else {
        D_800F447E = 0;
        D_800F4480 = 0;
        D_800F4482 = 0;
        D_800F4484 = 0;
        D_800F4486 = 0x1010;
    }
    t = D_800970B4;
    self->unk16 = 5;
    self->unk15 = 0;
    self->hurt_box = &D_800F414C;
    self->attack_box = &D_800F4154;
    self->terrain_box = 0;
    self->collision_data = &D_80074FBC;
    self->invincibility_timer = 0;
    self->bg_offset = t;
    ((void (*)(s32, s32, s32))func_8003D308)(0x14, 0x40, t);
    a = D_800F447C + D_800F447E;
    e = D_800F4480 + 0x390;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->animation_table = &D_800F42B4;
    self->x_pos.i.hi = a;
    self->y_pos.i.hi = e;
    for (i = 0; i < 3; i++) {
        o = func_8002C458();
        if (o != NULL) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x12;
            M2C_FIELD(o, u8*, 2) = 3;
            v = D_800F447E;
            M2C_FIELD(o, void**, 0x7C) = self;
            M2C_FIELD(o, s16*, 0xA) = i * 0x70 + (v + 0x1058);
        }
    }
    for (i = 0; i < 3; i++) {
        o = func_8002C458();
        if (o != NULL) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x12;
            M2C_FIELD(o, u8*, 2) = 4;
            v = D_800F447E;
            M2C_FIELD(o, void**, 0x7C) = self;
            M2C_FIELD(o, s16*, 0xA) = i * 0x70 + (v + 0x1058);
        }
    }
    for (i = 0; i < 4; i++) {
        M2C_FIELD(SCRATCH_4C + i, u8*, 0x90) =
            ((random_byte() & 3) + 1) * 0x1E;
    }
    M2C_FIELD(SCRATCH_4C, u8*, 0x89) = 0;
    M2C_FIELD(SCRATCH_4C, u8*, 0x8A) = 0;
    M2C_FIELD(SCRATCH_4C, u8*, 0x8B) = 0;
    M2C_FIELD(SCRATCH_4C, u8*, 0x86) = 0;
    M2C_FIELD(SCRATCH_4C, u8*, 0x94) = 0;
    M2C_FIELD(SCRATCH_4C, u16*, 0x96) = 0;
    M2C_FIELD(SCRATCH_4C, u16*, 0x84) = self->unk42;
    M2C_FIELD(SCRATCH_4C, void**, 0x8C) = self->sprite_frames;
    D_800F4490 = 0;
    background_objects[1].unk4 = 9;
    set_animation(self, 4);
    self->state = 1;
    self->unk5 = 2;
    self->unk6 = 0;
    self->unk7 = 0;
    self->on_screen = 1;
    background_objects[1].pad52[0] = -1;
    background_objects[1].unk3 = 1;
}
#undef D_800F447E
#undef D_800F4480

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800F04CC(void*);

extern u8 D_800E9860[];
extern M2C_UNK D_8007433C;
extern s32 D_80074FBC;
extern u8 D_8008EAFC;
extern s8 D_800970A2;
extern s8 D_8009711A;
extern u8 D_800CCF38;
extern void (*D_800F4358[])(void*);
extern u16 D_800F447E;
extern s32 D_800F4490;

#define B(p, o) M2C_FIELD(p, s8*, o)
#define UB(p, o) M2C_FIELD(p, u8*, o)

void func_800EEC40(void* self) {
    X4_RECT offs = *(X4_RECT*)(D_800E9860 + 0x50);
    u8* spad;
    u8* p;
    u8* obj;
    s32 i;
    s32 r;
    s8 st;

    if (D_800CCF38 >= 2) {
        spad = SPAD;
        if (UB(spad, 0x8B) == 2 && B(self, 5) != 3 && B(spad, 0x88) != 3 &&
            B(self, 5) != 8) {
            for (i = 0; i < 4; i++) {
                p = SPAD + 0x90;
                p += i;
                if (--*p == 0) {
                    obj = func_8002C458();
                    if (obj != NULL) {
                        UB(obj, 0) = 0x41;
                        UB(obj, 1) = 0x12;
                        UB(obj, 2) = 5;
                        UB(obj, 0x14) = UB(self, 0x14);
                        M2C_FIELD(obj, s16*, 0xA) =
                            ((s16*)&offs)[i] + D_800F447E;
                        UB(obj, 0x15) = UB(self, 0x15);
                        M2C_FIELD(obj, void**, 0x7C) = self;
                        play_sound(2, 0x19, self);
                    }
                    (SPAD + i)[0x90] = ((random_byte() & 3) + 1) * 30;
                }
            }
        }
    }
    if (B(self, 0x45) == 0x11 && D_8008EAFC == 0) {
        play_sound(2, 0xB, self);
    }
    func_800F04CC(self);
    D_800F4358[B(self, 5)](self);
    if (B(self, 5) != 2) {
        D_800F4490++;
    }
    func_80030ECC(self);
    r = check_enemy_hits(self);
    if (r < 0) {
        D_8009711A = 1;
        B(self, 4) = 2;
        B(self, 5) = 0;
        B(self, 6) = 0;
        play_sound(2, 0x20, self);
        return;
    }
    if (UB(SPAD, 0x86) == 0) {
        if (r != 0 && r != 0x7F) {
            st = B(self, 5);
            if (st == 8) {
                M2C_FIELD(self, void**, 0x58) = &D_8007433C;
                if ((u32)(r - 0x19) < 2) {
                    UB(SPAD, 0x86) = 2;
                } else {
                    UB(SPAD, 0x86) = 30;
                }
            } else if (D_800970A2 != 0) {
                if (st != 0xB) {
                    M2C_FIELD(self, void**, 0x58) = &D_8007433C;
                    obj = func_8002C458();
                    if (obj != NULL) {
                        UB(obj, 0) = 0x41;
                        UB(obj, 1) = 0x12;
                        UB(obj, 2) = 6;
                        M2C_FIELD(obj, s32*, 8) = M2C_FIELD(self, s32*, 8);
                        M2C_FIELD(obj, s32*, 0xC) = M2C_FIELD(self, s32*, 0xC);
                        UB(obj, 0x15) = UB(self, 0x15);
                        UB(obj, 0x16) = UB(self, 0x16);
                        M2C_FIELD(obj, void**, 0x7C) = self;
                        UB(obj, 7) = 30;
                    }
                    B(self, 3) = 0;
                    B(SPAD, 0x88) = B(self, 5);
                    B(self, 5) = 0xB;
                }
            } else if (r == 6 || r == 0xF) {
                if (st != 0xB) {
                    M2C_FIELD(self, void**, 0x58) = &D_8007433C;
                    obj = func_8002C458();
                    if (obj != NULL) {
                        UB(obj, 0) = 0x41;
                        UB(obj, 1) = 0x12;
                        UB(obj, 2) = 6;
                        M2C_FIELD(obj, s32*, 8) = M2C_FIELD(self, s32*, 8);
                        M2C_FIELD(obj, s32*, 0xC) = M2C_FIELD(self, s32*, 0xC);
                        UB(obj, 0x15) = UB(self, 0x15);
                        UB(obj, 0x16) = UB(self, 0x16);
                        M2C_FIELD(obj, void**, 0x7C) = self;
                        UB(obj, 7) = 90;
                    }
                    B(self, 3) = 0;
                    B(SPAD, 0x88) = B(self, 5);
                    B(self, 5) = 0xB;
                    play_sound(2, 0x21, self);
                }
            } else {
                M2C_FIELD(self, void**, 0x58) = &D_8007433C;
                M2C_FIELD(self, u16*, 0x42) |= 0x8000;
                UB(SPAD, 0x86) = 30;
            }
        }
    } else if (--UB(SPAD, 0x86) == 0) {
        M2C_FIELD(self, void**, 0x58) = &D_80074FBC;
        M2C_FIELD(self, u16*, 0x42) &= 0x7FFF;
    } else if (!(UB(SPAD, 0x86) & 1)) {
        M2C_FIELD(self, u16*, 0x42) |= 0x8000;
    } else {
        M2C_FIELD(self, u16*, 0x42) &= 0x7FFF;
    }
    if (B(self, 3) != 0) {
        func_8002CCB0(self, 0x80, 0x80);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F4350[];
extern void (*D_800F4388[])(void*);
extern s16 D_800F4482;
extern s16 D_800F4484;
extern s16 D_800F4486;
extern s16 D_800F448E;

void func_800EF0FC(void* self) {
    u8* spad;
    u8 st;

    D_800F4388[M2C_FIELD(self, s8*, 5)](self);
    M2C_FIELD(SPAD, u16*, 0x96)++;
    M2C_FIELD(SPAD, u16*, 0x96) = (u8)M2C_FIELD(SPAD, u16*, 0x96);
    st = M2C_FIELD(SPAD, u8*, 0x8B);
    if (st == 3 || st == 1) {
        if (D_800F448E == 0) {
            play_sound(2, 2, self);
            ((void (*)(s32))func_80012D9C)(4);
            D_800F448E = 1;
        }
        spad = SPAD;
        if ((s16)((s16)M2C_FIELD(spad, u16*, 0x96) % 10) == 0) {
            u8 idx;
            M2C_FIELD(spad, u8*, 0x8A)++;
            M2C_FIELD(SPAD, u8*, 0x8A) &= 3;
            idx = M2C_FIELD(SPAD, u8*, 0x8A);
            background_objects[1].unk4C = 1;
            background_objects[1].unk40 =
                (D_800F4350[idx] - D_800F4486) + D_800F4482;
        }
        background_objects[1].y_pos.u.hi -= 2;
        if ((s16)background_objects[1].y_pos.u.hi <= D_800F4484 + 0x900) {
            play_sound(2, 3, self);
            M2C_FIELD(SPAD, u8*, 0x8B) = 0;
        }
    } else if (st == 4 || st == 2) {
        if (D_800F448E == 0) {
            play_sound(2, 2, self);
            ((void (*)(s32))func_80012D9C)(4);
            D_800F448E = 1;
        }
        spad = SPAD;
        if ((s16)((s16)M2C_FIELD(spad, u16*, 0x96) % 10) == 0) {
            u8 idx;
            M2C_FIELD(spad, u8*, 0x8A)++;
            M2C_FIELD(SPAD, u8*, 0x8A) &= 3;
            idx = M2C_FIELD(SPAD, u8*, 0x8A);
            background_objects[1].unk4C = 1;
            background_objects[1].unk40 =
                (D_800F4350[idx] - D_800F4486) + D_800F4482;
        }
        background_objects[1].y_pos.u.hi += 2;
        if ((s16)background_objects[1].y_pos.u.hi >= D_800F4484 + 0xBA0) {
            play_sound(2, 3, self);
            M2C_FIELD(SPAD, u8*, 0x8B) = 0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_9C (*(s32**)0x1F80009C)
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F4330;

void func_800EF3FC(struct X4_MainObj* self) {
    s32 a;
    s32 b;

    func_8003D308(0x14, g_Player.unk15);
    func_80029478(0, 0, 0);
    play_sound(2, 3, self);
    self->unk40 = 0x440;
    self->unk42 &= 0x7FFF;
    if (g_playthrough_state.stage == 0xC) {
        s32* p = SCRATCH_9C;
        s32 o = p[1];
        self->unk42 = 0x794C;
        self->sprite_frames = (u8*)p + o;
    } else {
        a = func_8002A47C(self->id);
        b = func_8002A47C(self->id);
        a = (a + 1) * 4;
        self->unk42 = (a + 0x20) % 16 | (((b + 9) / 4 + 0x1E0) << 6);
        self->sprite_frames =
            (u8*)SCRATCH_20 + SCRATCH_20[func_8002A47C(self->id) + 1];
    }
    self->animation_table = &D_800F4330;
    set_animation(self, 0);
    {
        // !FAKE: depin: dropping it breaks the match (85/88)
        register s32 c7f asm("$2") = 0x7F;
        self->unk7C = c7f;
    }
    {
        // !FAKE: depin: dropping it breaks the match (80/88)
        register s32 c19 asm("$3") = 0x19;
        self->unk7E = c19;
        self->invincibility_timer = c19;
    }
    self->on_screen = 1;
    self->unk5 = 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

void* enemy_slot_alloc();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F4490;

void func_800EF55C(struct X4_MainObj* self) {
    s8* p;
    s8* obj;
    // !FAKE: depin: dropping it breaks the match (84/93)
    register s32 y asm("$5");

    self->on_screen = 0;
    p = *(s8**)(SCRATCH_4C + 0x80);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--self->unk7E == -1) {
                self->unk7E = 5;
                self->unk42 ^= 0x8000;
            }
            func_8002CCB0(self, 0x60, 0x60);
        }
    } else {
        if (g_playthrough_state.stage != 0xC) {
            if ((u32)D_800F4490 < 0x1519) {
                obj = enemy_slot_alloc();
                if (obj != 0) {
                    obj[0] = 0x41;
                    obj[1] = 0xF;
                    obj[2] = 0x10;
                }
            } else {
                obj = enemy_slot_alloc();
                if (obj != 0) {
                    obj[0] = 0x41;
                    obj[1] = 0xF;
                    obj[2] = 0x11;
                }
            }
        } else {
            g_playthrough_state.unkF = -0x80;
            g_playthrough_state.character_state
                .bytes[g_playthrough_state.checkpoint + 6] = 1;
            g_playthrough_state.checkpoint += 8;
        }
        g_playthrough_state.enable_boss = 0;
        g_playthrough_state.boss_ptr = 0;
        y = background_objects[0].y_pos.u.hi;
        background_objects[0].unk2A = y;
        clear_object_slot(self, y);
    }
}

#include "../shared/rock_05/func_800EF6D0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AE;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800F4480;
extern s16 D_800F4484;

void func_800EF7D4(struct X4_MainObj* self) {
    s32 d;

    if (D_800970AE > D_800F4480 + 0x440) {
        background_objects[1].y_pos.i.hi = D_800F4484 + 0x900;
        d = self->y_pos.i.hi;
        if (d <= D_800F4480 + 0x3D8) {
            d -= 0x3D8;
            if (d - D_800F4480 >= 0) {
                if (d - D_800F4480 >= 0x11) {
                    goto fa1;
                }
            } else if (D_800F4480 - d >= 0x11) {
            fa1:
                set_animation(self, 4);
            }
            self->y_speed = -0x50000;
        } else {
            d -= 0x3D8;
            if (d - D_800F4480 >= 0) {
                if (d - D_800F4480 >= 0x11) {
                    goto fa2;
                }
            } else if (D_800F4480 - d >= 0x11) {
            fa2:
                set_animation(self, 3);
            }
            self->y_speed = 0x50000;
        }
        SCRATCH_4C[0x8B] = 1;
    } else {
        background_objects[1].y_pos.i.hi = D_800F4484 + 0xBA0;
        d = self->y_pos.i.hi;
        if (d <= D_800F4480 + 0x438) {
            d -= 0x438;
            if (d - D_800F4480 >= 0) {
                if (d - D_800F4480 >= 0x11) {
                    goto fb1;
                }
            } else if (D_800F4480 - d >= 0x11) {
            fb1:
                set_animation(self, 4);
            }
            self->y_speed = -0x50000;
        } else {
            d -= 0x438;
            if (d - D_800F4480 >= 0) {
                if (d - D_800F4480 >= 0x11) {
                    goto fb2;
                }
            } else if (D_800F4480 - d >= 0x11) {
            fb2:
                set_animation(self, 3);
            }
            self->y_speed = 0x50000;
        }
        SCRATCH_4C[0x8B] = 2;
    }
    background_objects[1].unk4C = 1;
    self->unk6++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s16 D_800F4480;

void func_800EF9B8(struct X4_MainObj* self) {
    u8 mode = SCRATCH_4C[0x8B];

    if (mode == 1) {
        if (self->y_speed > 0) {
            if (self->y_pos.i.hi <= D_800F4480 + 0x3D8) {
                self->y_pos.i.hi = D_800F4480 + 0x3D8;
                self->unk6++;
                return;
            }
        } else if (self->y_pos.i.hi >= D_800F4480 + 0x3D8) {
            self->y_pos.i.hi = D_800F4480 + 0x3D8;
            self->unk6++;
            return;
        }
    } else if (mode == 2) {
        if (self->y_speed > 0) {
            if (self->y_pos.i.hi <= D_800F4480 + 0x438) {
                self->y_pos.i.hi = D_800F4480 + 0x438;
                self->unk6++;
                return;
            }
        } else if (self->y_pos.i.hi >= D_800F4480 + 0x438) {
            self->y_pos.i.hi = D_800F4480 + 0x438;
            self->unk6++;
            return;
        }
    }
    ((void (*)(void*))func_80017A04)(self);
    ((void (*)(s32))move_object)((s32)self);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
s32 random_byte();                   /* extern */
extern u8 D_800CCF5F;
extern s16 D_800F4480;

/* one arm per coin flip; the result-ignoring calls go through a void fn-ptr cast (C0103) */
#define ARM(off)                                                               \
    {                                                                          \
        s32 temp_v1 = M2C_FIELD(arg0, s16*, 0xE) - (off);                      \
        s32 temp_v0 = temp_v1 - D_800F4480;                                    \
        if (temp_v0 >= 0 ? temp_v0 < 0x10 : (D_800F4480 - temp_v1) < 0x10) {   \
            ((void (*)(void*, s32))set_animation)(arg0, 0);                    \
            M2C_FIELD(arg0, s16*, 0x7C) = 0x32;                                \
            if (D_800CCF5F < 2) {                                              \
                M2C_FIELD(arg0, s16*, 0x7E) = 3;                               \
            } else if (D_800CCF5F == 3) {                                      \
                M2C_FIELD(arg0, s16*, 0x7E) = 4;                               \
            } else {                                                           \
                M2C_FIELD(arg0, s16*, 0x7E) = 5;                               \
            }                                                                  \
            M2C_FIELD(arg0, u8*, 6) = 2;                                       \
        } else {                                                               \
            if (M2C_FIELD(arg0, s16*, 0xE) > D_800F4480 + (off)) {             \
                ((void (*)(void*, s32))set_animation)(arg0, 3);                \
                M2C_FIELD(arg0, s32*, 0x24) = 0x50000;                         \
            } else {                                                           \
                ((void (*)(void*, s32))set_animation)(arg0, 4);                \
                M2C_FIELD(arg0, s32*, 0x24) = 0xFFFB0000;                      \
            }                                                                  \
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;             \
        }                                                                      \
    }

void func_800EFAD4(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    if ((M2C_FIELD(arg0, s16*, 0x7C) = random_byte() & 1) == 0) {
        ARM(0x438)
    } else {
        ARM(0x468)
    }
}

#undef ARM

#include "common.h"
#define M2C_UNK s32

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern u8 D_800E9860[];
extern s8 D_800CCF5C;
extern s16 D_800F4480;

void func_800EFCA8(void* arg0) {
    s16 buf[3];
    s32 t;
    s16* src;

    src = (s16*)(D_800E9860 + 0x58);
    __builtin_memcpy(buf, src, 6);
    move_object(arg0);
    func_80017A04(arg0);
    if (F32(arg0, 0x24) == 0x50000) {
        if (S16(arg0, 0xE) < buf[S16(arg0, 0x7C)] + D_800F4480) {
            S16(arg0, 0xE) = buf[S16(arg0, 0x7C)] + D_800F4480;
            S16(arg0, 0x7C) = 3;
        }
    } else {
        if (buf[S16(arg0, 0x7C)] + D_800F4480 < S16(arg0, 0xE)) {
            S16(arg0, 0xE) = buf[S16(arg0, 0x7C)] + D_800F4480;
            S16(arg0, 0x7C) = 3;
        }
    }
    t = S16(arg0, 0x7C);
    if (t == 3) {
        ((void (*)(void*, s32))set_animation)(
            arg0, 0); /* void fn-ptr cast at the unused result (C0103) */
        S16(arg0, 0x7C) = 0x32;
        if (S8(arg0, 0x5C) < D_800CCF5C / 8) {
            S16(arg0, 0x7E) = 5;
        } else if (S8(arg0, 0x5C) < D_800CCF5C / 4) {
            S16(arg0, 0x7E) = 4;
        } else {
            S16(arg0, 0x7E) = t;
        }
        F8(arg0, 6)++;
    }
}

#include "../shared/rock_05/func_800EFE14.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_9C (*(s32**)0x1F80009C)
#define SCRATCH_4C (*(u8**)0x1F80004C)
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_8007433C;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F4150;
extern s32 D_800F4158;
extern s32 D_800F4330;
extern s16 D_800F4484;

void func_800EFFBC(struct X4_MainObj* self) {
    s32 a;
    s32 b;
    u8 t;

    t = SCRATCH_4C[0x8B];
    if (t == 1) {
        background_objects[1].y_pos.u.hi -= 2;
        if ((s16)background_objects[1].y_pos.u.hi <= D_800F4484 + 0x900) {
            self->unk7C = 0;
            SCRATCH_4C[0x8B] = 0;
            play_sound(2, 3, self);
        }
    } else if (t == 2) {
        background_objects[1].y_pos.u.hi += 2;
        if ((s16)background_objects[1].y_pos.u.hi >= D_800F4484 + 0xBA0) {
            self->unk7C = 0;
            SCRATCH_4C[0x8B] = 0;
            play_sound(2, 3, self);
        }
    }
    if (self->unk7C == 0) {
        self->unk7E = 3;
        self->contact_damage = 8;
        self->hurt_box = &D_800F4150;
        self->attack_box = &D_800F4158;
        self->collision_data = &D_8007433C;
        self->unk40 += 0x300;
        if (g_playthrough_state.stage == 0xC) {
            self->sprite_frames = (u8*)SCRATCH_9C + SCRATCH_9C[1];
            self->unk42 = 0x794C;
        } else {
            a = func_8002A47C(self->id);
            b = func_8002A47C(self->id);
            a = (a + 1) * 4;
            self->unk42 = (a + 0x20) % 16 | (((b + 9) / 4 + 0x1E0) << 6);
            self->sprite_frames =
                (u8*)SCRATCH_20 + SCRATCH_20[func_8002A47C(self->id) + 1];
        }
        self->animation_table = &D_800F4330;
        self->on_screen = 1;
        set_animation(self, 4);
        self->unk7C = 0x32;
        ((void (*)(s32, s32, s32))func_80029478)(0x78, 4, 2);
        self->unk6++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800F4480;

void func_800F01FC(struct X4_MainObj* self) {
    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (!(D_80097420.frame_counter & 1)) {
        background_objects[0].y_pos.u.hi += 2;
    } else {
        background_objects[0].y_pos.u.hi -= 2;
    }
    if (self->unk7E != 0) {
        if (self->unk7E == 3) {
            play_sound(2, 0x24, self);
        }
        self->unk7E--;
        self->unk6++;
        play_sound(2, 0xF, self);
        func_80012D9C(3);
        if (random_byte() & 1) {
            self->y_pos.u.hi = D_800F4480 + 0x450;
            return;
        }
        self->y_pos.u.hi = D_800F4480 + 0x3F0;
        return;
    }
    self->unk6 = 5;
    func_80029478(1, 4, 2);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F447E;
#define D_800F447E (*(s16*)&D_800F447E)

void func_800F0318(struct X4_MainObj* self) {
    s16 x;

    self->on_screen = 1;
    if (!(D_80097420.frame_counter & 1)) {
        background_objects[0].y_pos.u.hi += 2;
    } else {
        background_objects[0].y_pos.u.hi -= 2;
    }
    move_object(self);
    ((void (*)(void*))func_80017A04)(self);
    x = self->x_pos.i.hi;
    if (D_800F447E + 0x1220 < x) {
        self->x_speed = 0xFFF80000;
        self->unk15 = 0;
        self->unk7C = 0x32;
        func_80029478(0x78, 4, 2);
        {
            // !FAKE: depin: dropping it breaks the match (36/60)
            register s32 t asm("$2") = (u8)self->unk6 - 1;
            self->unk6 = t;
        }
    } else if (x < D_800F447E + 0xF80) {
        self->x_speed = 0x80000;
        self->unk15 = 0x40;
        self->unk7C = 0x32;
        func_80029478(0x78, 4, 2);
        {
            // !FAKE: depin: dropping it breaks the match (36/60)
            register s32 t asm("$2") = (u8)self->unk6 - 1;
            self->unk6 = t;
        }
    }
}
#undef D_800F447E

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern u16 D_800F447E;
extern s16 D_800970AA;

void func_800F0408(u8* arg0) {
    s16 x;
    // !FAKE: depin: dropping it breaks the match (44/49)
    register s32 t asm("$3");

    func_80017A04();
    move_object(arg0);
    x = *(s16*)(arg0 + 0xA);
    if (x < (s16)D_800F447E + 0x1030) {
        *(u16*)(arg0 + 0xA) = D_800F447E + 0x1030;
    } else if ((s16)D_800F447E + 0x1150 < x) {
        *(u16*)(arg0 + 0xA) = D_800F447E + 0x1150;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[6] = 5;
        return;
    }
    if (arg0[0x15] == 0) {
        t = *(s16*)(arg0 + 0xA);
        t = t < D_800970AA;
    } else {
        t = *(s16*)(arg0 + 0xA) > D_800970AA;
    }
    if (t) {
        *(s32*)(arg0 + 0x28) = -0x4000;
        arg0[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F4350[];
extern s16 D_800F4482;
extern s16 D_800F4484;
extern s16 D_800F4486;
extern s16 D_800F448E;

void func_800F04CC(void* self) {
    u8* spad;
    u8 st;

    M2C_FIELD(SPAD, u16*, 0x96)++;
    M2C_FIELD(SPAD, u16*, 0x96) = (u8)M2C_FIELD(SPAD, u16*, 0x96);
    spad = SPAD;
    if ((s16)((s16)M2C_FIELD(spad, u16*, 0x96) % 10) == 0) {
        u8 idx;
        M2C_FIELD(spad, u8*, 0x8A)++;
        M2C_FIELD(SPAD, u8*, 0x8A) &= 3;
        idx = M2C_FIELD(SPAD, u8*, 0x8A);
        background_objects[1].unk4C = 1;
        background_objects[1].unk40 =
            (D_800F4350[idx] - D_800F4486) + D_800F4482;
    }
    st = M2C_FIELD(SPAD, u8*, 0x8B);
    if (st == 3) {
        if (D_800F448E == 0) {
            play_sound(2, 2, self);
            ((void (*)(s32))func_80012D9C)(4);
            D_800F448E = 1;
        }
        background_objects[1].y_pos.u.hi -= 2;
        if ((s16)background_objects[1].y_pos.u.hi <= D_800F4484 + 0x900) {
            play_sound(2, 3, self);
            M2C_FIELD(SPAD, u8*, 0x8B) = 0;
            D_800F448E = 0;
        }
    } else if (st == 4) {
        if (D_800F448E == 0) {
            play_sound(2, 2, self);
            ((void (*)(s32))func_80012D9C)(4);
            D_800F448E = 1;
        }
        background_objects[1].y_pos.u.hi += 2;
        if ((s16)background_objects[1].y_pos.u.hi >= D_800F4484 + 0xBA0) {
            play_sound(2, 3, self);
            M2C_FIELD(SPAD, u8*, 0x8B) = 0;
            D_800F448E = 0;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800F06F0);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 random_byte();
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern u16 D_800F447E; /* TU spelling (func_800EEC40) */
#define D_800F447E_S16 (*(s16*)&D_800F447E)
extern s16 D_800F4480;

#define SPAWN3(self)                                                           \
    {                                                                          \
        M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s8*, 7) = 1;                  \
        for (i = 0; i < 3; i++) {                                              \
            r[i] = (u8)((u32)random_byte() % 11);                            \
        }                                                                      \
        if (r[0] == r[1]) {                                                    \
            r[1] = (r[0] + 5) % 11;                                            \
        }                                                                      \
        if (r[2] == r[0] || r[2] == r[1]) {                                    \
            r[2] = (r[0] + 1) % 11;                                            \
            if (r[2] == r[1]) {                                                \
                r[2] = (r[2] + 5) % 11;                                        \
            }                                                                  \
        }                                                                      \
        for (i = 0; i < 3; i++) {                                              \
            struct X4_BaseObj* child = func_8002C458();                        \
            if (child != NULL) {                                               \
                child->active = 0x41;                                          \
                child->id = 0x12;                                              \
                child->unk2 = 2;                                               \
                child->bg_offset = self->bg_offset;                            \
                child->x_pos.i.hi = self->x_pos.i.hi;                          \
                child->y_pos.i.hi = self->y_pos.i.hi;                          \
                child->unk15 = self->unk15;                                    \
                M2C_FIELD(child, void**, 0x7C) =                               \
                    M2C_FIELD(self, void**, 0x7C);                             \
                child->unk7 = r[i] + 1;                                        \
            }                                                                  \
        }                                                                      \
    }

void func_800F0EE4(struct X4_BaseObj* self) {
    s32 r[3];
    s32 i;

    func_80017A04();
    func_8002D230(self);
    if (self->x_pos.i.hi < D_800F447E_S16 + 0x1030) {
        self->x_pos.i.hi = D_800F447E_S16 + 0x1030;
    } else if (self->x_pos.i.hi > D_800F447E_S16 + 0x1150) {
        self->x_pos.i.hi = D_800F447E_S16 + 0x1150;
    }
    if (check_enemy_hits(self) < 0) {
        func_80049E50(self);
        SPAWN3(self)
        goto tail;
    }
    if (self->y_pos.i.hi > D_800F4480 + 0x430) {
        SPAWN3(self)
    tail:
        play_sound(2, 0xD, self);
        ((void (*)(s32))func_80012D9C)(5);
        self->state = 2;
        return;
    }
    if (func_8002CBFC(self, 0x60, 0x60) == 0) {
        func_8002CCB0(self, 0x30, 0x30);
        return;
    }
    self->state = 2;
    M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s8*, 7) = 1;
}

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800F1384);
// clang-format on

#include "../shared/rock_05/func_800F13E0.c"

#define func_8003744C func_800F14D4
#define D_80073C1C D_800F4394
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F1510(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_4C (*(u8**)0x1F80004C)

void* alloc_class3_slot();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F448C;

void func_800F1548(void* arg0) {
    u8* e;
    u8* b;
    u8* o;

    e = (u8*)&g_playthrough_state;
    if (M2C_FIELD(e, s8*, 0xF) == 0 && D_800970A5 == 0x14) {
        b = (u8*)background_objects;
        M2C_FIELD(b, u8*, 0x47) = 2;
        D_800F448C = M2C_FIELD(b, u8*, 0x48);
        if (M2C_FIELD(e, s8*, 0xC) != 0xC) {
            func_8003D308(0x1D, 0x40);
        }
        o = alloc_class3_slot();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0x18;
            M2C_FIELD(SCRATCH_4C, u8**, 0x80) = o;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x10;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s32 D_800F4144;
extern s16 D_800F4480;

void func_800F1604(void* arg0) {
    ((void (*)(void*))move_object)(arg0);
    ((void (*)())func_80017A04)(arg0);
    if ((D_800F4480 + 0x420) < ((s16*)arg0)[7]) {
        ((s32**)arg0)[0x68 / 4] = &D_800F4144;
    }
    if (((u8*)arg0)[0x70] & 8) {
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}

#include "../shared/rock_05/func_800F1678.c"

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800F16DC);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
s32 func_80040498();                   /* extern */
extern s8 D_80097240;

void func_800F172C(void* arg0) {
    func_80017A04();
    if (func_80040498() == 0) {
        set_animation(arg0, 1);
        D_80097240 = 2;
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                     /* extern */
M2C_UNK func_8003D330();                     /* extern */
extern s8 D_80097240;
extern s8 D_800CCF5C;
extern s32 D_800F4148;
extern u8 D_800F448C;

void func_800F1788(void* arg0) {
    s8 state;

    func_80017A04();
    state = M2C_FIELD(arg0, s8*, 0x45);
    if (state != 0) {
        if (state == 2) {
            play_sound(2, 0xA, arg0);
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            play_sound(0, 0xE, 0);
            M2C_FIELD(arg0, s16*, 0x7C) = 2;
        }
        if ((s8)++M2C_FIELD(arg0, u8*, 0x5C) == D_800CCF5C) {
            // !FAKE: depin: dropping it breaks the match (33/50)
            register s32 v asm("$4") = D_800F448C;
            D_80097240 = v;
            func_8003D330(v);
            M2C_FIELD(arg0, s32**, 0x68) = &D_800F4148;
            M2C_FIELD(arg0, u8*, 6) = 0;
            M2C_FIELD(arg0, u8*, 5) = 3;
        }
    }
}

#define func_8003744C func_800F1850
#define D_80073C1C D_800F43B4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_05/func_800F188C.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*); /* extern */
M2C_UNK move_object(void*);   /* extern */

void func_800F18D8(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    func_80017A04(arg0);
    move_object(arg0);
}

#include "../shared/rock_05/func_800F1930.c"

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800F19A8);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800F4484;

void func_800F19F8(u8* arg0) {
    s32 t;
    // !FAKE: depin: dropping it breaks the match (47/51)
    register s32 k asm("$3");

    ((M2C_UNK(*)())func_80017A04)();
    {
        // !FAKE: depin: dropping it breaks the match (48/51)
        register u8* p asm("$2") = SCRATCH_4C;
        t = p[0x8B];
    }
    k = 2;
    if (t == k) {
        background_objects[1].y_pos.u.hi -= 2;
        if ((s16)background_objects[1].y_pos.u.hi > D_800F4484 + 0xB30) {
            return;
        }
        goto hit;
    } else if (t == 1) {
        background_objects[1].y_pos.u.hi += 2;
        if ((s16)background_objects[1].y_pos.u.hi >= D_800F4484 + 0x990) {
        hit:
            play_sound(2, 3, arg0);
            arg0[5] = 7;
            arg0[6] = 0;
        }
    }
}

#define func_8003744C func_800F1AC4
#define D_80073C1C D_800F43D0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_05/func_800F1B00.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F2B4C();

void func_800F1B44(void* arg0) {
    func_800F2B4C();
    set_animation(arg0, 5);
    ((void (*)(void*))func_80017A04)(arg0);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();
void func_800F2B4C();

void func_800F1B88(void* arg0) {
    s8 temp_s1;
    void* temp_v0;

    func_800F2B4C();
    func_80017A04(arg0);
    temp_s1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_s1 == 1) {
        temp_v0 = func_8002C458();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, u8*, 0) = 0x41;
            M2C_FIELD(temp_v0, u8*, 1) = 0x12;
            M2C_FIELD(temp_v0, u8*, 2) = temp_s1;
            M2C_FIELD(temp_v0, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(temp_v0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(temp_v0, void**, 0x7C) = arg0;
            ((s32(*)(s32, s32, void*, void*))play_sound)(2, 0xC, arg0, temp_v0);
            play_sound(2, 0x23, arg0);
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "../shared/rock_05/func_800F1C48.c"

#define func_8003744C func_800F1CAC
#define D_80073C1C D_800F43E0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_05/func_800F1CE8.c"

#include "../shared/rock_05/func_800F1D4C.c"

#include "../shared/rock_05/func_800F1E60.c"

#define func_8003744C func_800F1EDC
#define D_80073C1C D_800F43F4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_05/func_800F1F18.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s16 D_800F4480;

void func_800F1F64(u8* arg0) {
    s32 x;
    s32 d;
    s32 a;
    s32 b;

    if (arg0[0x70] & 1) {
        x = *(s16*)(arg0 + 0xE) - 0x438;
        d = x - D_800F4480;
        if (d >= 0) {
            if (d >= 0x11) {
                goto call;
            }
        } else if (D_800F4480 - x >= 0x11) {
        call:
            set_animation(arg0, 3);
        }
        a = D_800F4480 + 0x438;
        b = *(s16*)(arg0 + 0xE);
        *(s32*)(arg0 + 0x20) = 0;
        if (a >= b) {
            *(s32*)(arg0 + 0x24) = 0xFFFB0000;
        } else {
            *(s32*)(arg0 + 0x24) = 0x50000;
        }
        arg0[6]++;
        return;
    }
    move_object(arg0);
    func_80017A04(arg0);
}

#include "common.h"
#define M2C_UNK s32

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s16 D_800F4480;

#define SETB                                                                   \
    {                                                                          \
        S16(arg0, 0xE) = D_800F4480 + 0x438;                                   \
        ((void (*)(void*, s32))set_animation)(arg0, 0);                        \
        S16(arg0, 0x7C) = 0x32;                                                \
        F8(arg0, 6)++;                                                         \
        return;                                                                \
    }

void func_800F2030(void* arg0) {
    if (F32(arg0, 0x24) == 0x50000) {
        if (S16(arg0, 0xE) <= D_800F4480 + 0x438) {
            SETB
        }
    } else if (S16(arg0, 0xE) >= D_800F4480 + 0x438) {
        SETB
    }
    move_object(arg0);
    func_80017A04(arg0);
}
#undef SETB

#include "../shared/rock_05/func_800F20D8.c"

#include "../shared/rock_05/func_800F213C.c"

#include "../shared/rock_05/func_800F21AC.c"

#include "../shared/rock_05/func_800F2218.c"

#include "../shared/rock_05/func_800F2284.c"

#define func_8003744C func_800F22E8
#define D_80073C1C D_800F4414
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_05/func_800F2324.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);              /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                     /* extern */
M2C_UNK move_object(void*);                  /* extern */
extern u16 D_800F447E;
#define D_800F447E_S (*(s16*)&D_800F447E)

void func_800F23B0(void* arg0) {
    s16 y;

    ((void (*)(void*))move_object)(arg0);
    ((void (*)(void*))func_80017A04)(arg0);
    y = M2C_FIELD(arg0, s16*, 0xA);
    if ((D_800F447E_S + 0x11F0) < y) {
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFF80000;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        play_sound(2, 2, arg0);
        func_80012D9C(4);
        return;
    }
    if (y < (D_800F447E_S + 0xFA0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        play_sound(2, 2, arg0);
        func_80012D9C(4);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
extern s32 D_80074FBC;
extern s32 D_800F414C;
extern s32 D_800F4154;
extern s32 D_800F42B4;
extern u16 D_800F447E;
extern s16 D_800F4480;

void func_800F2478(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (55/58)
    register s32 var_v0 asm("$2");
    u16 e;

    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(SCRATCH_4C, u16*, 0x84);
    {
        s32 t = M2C_FIELD(SCRATCH_4C, s32*, 0x8C);
        M2C_FIELD(arg0, u16*, 0x40) = 0x140;
        M2C_FIELD(arg0, void**, 0x30) = &D_800F42B4;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F414C;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F4154;
        M2C_FIELD(arg0, void**, 0x58) = &D_80074FBC;
        M2C_FIELD(arg0, s32*, 0x3C) = t;
    }
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        var_v0 = D_800F447E + 0x1140;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        var_v0 = D_800F447E + 0x1040;
    }
    M2C_FIELD(arg0, s16*, 0xA) = var_v0;
    e = D_800F4480;
    {
        // !FAKE: depin: dropping it breaks the match (50/58)
        register s32 k asm("$4") = 0xFFFB0000;
        M2C_FIELD(arg0, s32*, 0x24) = k;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = e + 0x380;
    set_animation(arg0, 4);
    {
        // !FAKE: depin: dropping it breaks the match (55/58)
        register s32 c asm("$2") = M2C_FIELD(arg0, u8*, 0x6) + 1;
        M2C_FIELD(arg0, u8*, 0x6) = c;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s16 D_800970AE;
extern s32 D_800F4148;
extern s16 D_800F4480;

void func_800F2560(void* arg0) {
    s16* q = &D_800970AE;

    M2C_FIELD(arg0, u8*, 0x3) = 1;
    move_object(arg0);
    func_80017A04(arg0);
    if ((D_800F4480 + 0x440) < *q) {
        if ((D_800F4480 + 0x3D8) < M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE) = (u16)D_800F4480 + 0x3D8;
            goto block_5;
        }
    } else if ((D_800F4480 + 0x438) < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_800F4480 + 0x438;
    block_5:
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F4148;
        M2C_FIELD(arg0, u8*, 0x5) = 7;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}

#define func_8003744C func_800F2608
#define D_80073C1C D_800F4430
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
s32 random_byte();                   /* extern */
extern s16 D_800F4480;

void func_800F2644(void* arg0) {
    s32 temp_v0;
    s32 temp_v1;

    M2C_FIELD(arg0, s16*, 0x7E) = (s16)((random_byte() & 1) + 1);
    temp_v1 = M2C_FIELD(arg0, s16*, 0xE) - 0x460;
    temp_v0 = temp_v1 - D_800F4480;
    if (temp_v0 >= 0) {
        if (temp_v0 < 0x11) {

        } else {
            goto block_4;
        }
    } else if ((D_800F4480 - temp_v1) >= 0x11) {
    block_4:
        set_animation(arg0, 4);
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFB0000;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "../shared/rock_05/func_800F26D4.c"

#include "../shared/rock_05/func_800F272C.c"

#include "common.h"
#define M2C_UNK s32

extern u16 D_800F447E;
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);

void func_800F2798(u8* arg0) {
    s8 state;
    s16 x;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        state = 5;
        goto store;
    }
    {
        func_80017A04(arg0);
        func_8002D230(arg0);
        x = *(s16*)(arg0 + 0xA);
        if (x < (s16)D_800F447E + 0x1030) {
            *(u16*)(arg0 + 0xA) = D_800F447E + 0x1030;
        } else if ((s16)D_800F447E + 0x1150 < x) {
            *(u16*)(arg0 + 0xA) = D_800F447E + 0x1150;
        }
        if (*(s32*)(arg0 + 0x20) != 0) {
            return;
        }
        if (*(u8*)(arg0 + 0x15) == 0) {
            *(u8*)(arg0 + 0x15) = 0x40;
            *(s32*)(arg0 + 0x20) = 0x40000;
        } else {
            *(u8*)(arg0 + 0x15) = 0;
            *(s32*)(arg0 + 0x20) = 0xFFFC0000;
        }
        state = 3;
        *(s32*)(arg0 + 0x28) = 0;
    }
store:
    *(u8*)(arg0 + 6) = state;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
void func_800F2B4C();                  /* extern */

void func_800F2860(void* arg0) {
    func_800F2B4C();
    set_animation(arg0, 3);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0x50000;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
s32 random_byte();
void func_800F2B4C();
extern s32 D_800F4144;
extern s16 D_800F4480;

void func_800F28AC(struct X4_BaseObj* self) {
    ((void (*)())func_800F2B4C)();
    ((void (*)(void*))func_80017A04)(self);
    ((void (*)(void*))move_object)(self);
    if (F16(self, 0xE) < D_800F4480 + 0x3E0) {
        FP(self, 0x68) = &D_800F4144;
    }
    if (FU8(self, 0x70) & 4) {
        if (!(random_byte() & 3)) {
            SPAD[0x89]++;
            self->unk5 = 4;
            self->unk6 = 0;
            return;
        }
        self->unk6++;
        ((void (*)(void*, s32))set_animation)(self, 0);
        F16(self, 0x7C) = 0x3C;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F2B4C();
extern s32 D_800F4148;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F2970(void* self) {
    ((void (*)())func_800F2B4C)();
    ((void (*)(void*))func_80017A04)(self);
    if (--F(s16, 0x7C) == 0) {
        if (F(s16, 0x7E) != 0) {
            F(s16, 0x7E)--;
            set_animation(self, 4);
            F(s32, 0x20) = 0;
            F(s32, 0x24) = 0xFFFB0000;
            F(void*, 0x68) = 0;
            F(u8, 6) = 1;
            return;
        }
        F(void*, 0x68) = &D_800F4148;
        F(u8, 5) = 7;
        F(u8, 6) = 0;
    }
}

#undef F

#define func_8003744C func_800F2A0C
#define D_80073C1C D_800F4450
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_05/func_800F2A48.c"

#include "../shared/rock_05/func_800F2A9C.c"

#include "../shared/rock_05/func_800F2AF0.c"

#include "common.h"

extern s16 D_800970AA;

void func_800F2B4C(u8* e) {
    s16 x = *(s16*)(e + 0xA);

    if (D_800970AA < x) {
        e[0x15] = 0;
    } else {
        e[0x15] = 0x40;
    }
}

#include "common.h"

void func_800F2B7C(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800F2B84);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                     /* extern */
s32 check_enemy_hits(void*);                    /* extern */
M2C_UNK func_80049D90(void*);                   /* extern */

void func_800F2BE0(struct ObjectHeader* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    move_object(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049D90(arg0);
        arg0->state = 2;
        return;
    }
    if (func_8002CBFC(arg0, 0x60, 0x60) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    arg0->state = 2;
}

#include "../shared/rock_05/func_800F2C60.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D230(void*);          /* extern */
s32 check_enemy_hits(void*);           /* extern */

void func_800F2CC8(void* arg0) {
    s8 temp_v1_2;
    u8 temp_v1;

    ((M2C_UNK(*)())func_80017A04)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x95);
    if (temp_v1 < 0x1EU) {
        M2C_FIELD(arg0, u8*, 0x95) = (u8)(temp_v1 + 1);
        return;
    }
    func_8002D230(arg0);
    if (check_enemy_hits(arg0) < 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        set_animation(arg0, 9);
    }
    temp_v1_2 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1_2 == 2) {
        M2C_FIELD(arg0, s8*, 4) = temp_v1_2;
    }
    M2C_FIELD(arg0, s8*, 3) = 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                     /* extern */
s32 check_enemy_hits(void*);                    /* extern */
M2C_UNK func_80049E50(void*);                   /* extern */

void func_800F2D6C(struct ObjectHeader* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    move_object(arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        goto block_5;
    }
    if (func_8002CBFC(arg0, 0x60, 0x60) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    arg0->on_screen = 0;
block_5:
    arg0->state = 2;
}

#include "../shared/rock_05/func_800F2DEC.c"

#include "../shared/rock_05/func_800F2E84.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F2F00(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800F2F20);
// clang-format on
