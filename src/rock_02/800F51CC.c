#define func_80041AB8 func_800F51CC
#define D_80075FD8 D_800FB898
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/rock_02/func_800F5208.c"

#include "../shared/rock_02/func_800F527C.c"

#define func_8003744C func_800F5380
#define D_80073C1C D_800FB8A4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F53BC(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

M2C_UNK func_80040488(M2C_UNK);
M2C_UNK func_800F82C0();

void func_800F53D0(void* arg0) {
    ((void (*)())func_800F82C0)();
    if (D_8008EAFC == 0) {
        func_80040488(0);
        {
            // !FAKE: depin: dropping it breaks the match (17/20)
            register s32 v asm("$2") = ((u8*)arg0)[6] + 1;
            ((u8*)arg0)[6] = v;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80040498();
M2C_UNK func_800F82C0();
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FBC7C;
#define D_800FBC7C (*(u8*)&D_800FBC7C)

void func_800F5420(void* arg0) {
    ((void (*)())func_800F82C0)();
    if (func_80040498() == 0) {
        if (((s8*)arg0)[2] == 0) {
            background_objects[0].unk24 = 0x1800;
            background_objects[0].unk26 = 0x17B0;
        }
        *(s16*)((u8*)arg0 + 0x7C) = 2;
        ((u8*)arg0)[6] += 1;
        background_objects[0].unk48 = D_800FBC7C;
    }
}
#undef D_800FBC7C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8003D330();
M2C_UNK func_800F82C0();
extern u8 D_800CCF5C;
#define D_800CCF5C (*(s8*)&D_800CCF5C)

void func_800F549C(void* arg0) {
    ((void (*)())func_800F82C0)();
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        play_sound(0, 0xE, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
    }
    if (++M2C_FIELD(arg0, s8*, 0x5C) == D_800CCF5C) {
        if (M2C_FIELD(arg0, s8*, 2) == 2) {
            ((void (*)(void*, s32))set_animation)(arg0, 7);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
        func_8003D330();
        M2C_FIELD(arg0, u8*, 6) = 0xB;
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
    }
}
#undef D_800CCF5C

#include "../shared/rock_02/func_800F5568.c"

#include "../shared/rock_02/func_800F55EC.c"

#include "../shared/rock_02/func_800F56F8.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*); /* extern */
M2C_UNK func_8003D330();       /* extern */
M2C_UNK func_800F82C0();       /* extern */

void func_800F5760(void* arg0) {
    func_800F82C0();
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_8003D330();
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/rock_02/func_800F57C8.c"

#define func_8003744C func_800F5834
#define D_80073C1C D_800FB8D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F5870(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);
extern s16 D_80097222;

void func_800F588C(void* arg0) {
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x70) {
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x70;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x40000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFC0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x100;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800F82C0();

void func_800F590C(struct X4_MainObj* arg0) {
    // !FAKE: depin: dropping it breaks the match (6/17)
    register s16 d asm("$2");

    func_800F82C0();
    d = arg0->unk7C - 1;
    arg0->unk7C = d;
    if (d == 0) {
        arg0->action_phase = 4;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(s32);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F5950(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object((s32)arg0);
    if (F(s8, arg0, 0x45) == 1) {
        if (F(u8, arg0, 0x15) != 0) {
            F(s32, arg0, 0x20) = 0x40000;
        } else {
            F(s32, arg0, 0x20) = 0xFFFC0000;
        }
        F(s32, arg0, 0x28) = 0x100;
        F(s32, arg0, 0x24) = 0;
        F(s32, arg0, 0x2C) = 0;
        F(u8, arg0, 6) = F(u8, arg0, 6) + 1;
    }
}

#include "../shared/rock_02/func_800F59C0.c"

#include "../shared/rock_02/func_800F5A60.c"

#include "../shared/rock_02/func_800F5AFC.c"

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK move_object(s32);
extern u16 D_8009721A;

void func_800F5B30(void* arg0) {
    s32 t;
    s32 v;

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x40) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x40;
        t = SPAD4C[0x85] + 1;
        SPAD4C[0x85] = t;
        v = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}

#define func_8003744C func_800F5BC0
#define D_80073C1C D_800FB8F4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F5BFC.c"

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C_800F5C40 (*(u8**)0x1F80004C)

M2C_UNK func_800F82C0();

void func_800F5C40(void* self) {
    s32 n;
    s32 v;

    func_800F82C0();
    {
        // !FAKE: depin: dropping it breaks the match (28/33)
        register s32 t asm("$2");
        t = M2C_FIELD(self, u16*, 0x7C) - 1;
        M2C_FIELD(self, u16*, 0x7C) = t;
        if ((s16)t != 0) {
            return;
        }
    }
    n = ++SPAD4C_800F5C40[0x85];
    v = D_800FB810[(n & 3) + SPAD4C_800F5C40[0x84] * 4];
    M2C_FIELD(self, u8*, 0x6) = 0;
    M2C_FIELD(self, u8*, 0x5) = v;
}

#undef SPAD4C_800F5C40

#define func_8003744C func_800F5CC4
#define D_80073C1C D_800FB8FC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F5D00.c"

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C_800F5D44 (*(u8**)0x1F80004C)

M2C_UNK func_800F82C0();

void func_800F5D44(void* self) {
    s32 n;
    // !FAKE: depin: dropping it breaks the match (29/36)
    register s32 t asm("$2");
    s32 v;

    func_800F82C0();
    t = M2C_FIELD(self, u16*, 0x7C);
    M2C_FIELD(self, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x29) {
        M2C_FIELD(self, u16*, 0x7C) = 0;
        n = ++SPAD4C_800F5D44[0x85];
        v = D_800FB810[(n & 3) + SPAD4C_800F5D44[0x84] * 4];
        M2C_FIELD(self, u8*, 0x6) = 0;
        M2C_FIELD(self, u8*, 0x5) = v;
    }
}

#undef SPAD4C_800F5D44

#define func_8003744C func_800F5DD4
#define D_80073C1C D_800FB908
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F5E10.c"

#include "../shared/rock_02/func_800F5E5C.c"

#include "../shared/rock_02/func_800F5EE8.c"

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F5FD4(struct X4_MainObj* arg0) {
    // !FAKE: depin: dropping it breaks the match (26/33)
    register s32 t asm("$2");

    ((M2C_UNK(*)())animate_object)();
    func_800F82C0(arg0);
    t = *(u16*)&arg0->unk7C + 1;
    arg0->unk7C = t;
    if ((s16)t == 0x79) {
        play_sound(2, 0x24, arg0);
    }
    if (arg0->unk7 == 1) {
        arg0->unk7 = 0;
        arg0->unk7C = 0;
        arg0->action_phase++;
        set_animation(arg0, 9);
    }
}

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_800F82C0();

#define SPAD (*(u8**)0x1F80004C)

void func_800F6058(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (32/38)
    register s32 t asm("$2");
    s32 c;
    s32 v;

    animate_object(arg0);
    func_800F82C0(arg0);
    t = *(u16*)(arg0 + 0x7C);
    {
        s32 n = t + 1;
        *(u16*)(arg0 + 0x7C) = n;
    }
    if ((s16)t >= 0x28) {
        *(u16*)(arg0 + 0x7C) = 0;
        c = SPAD[0x85] + 1;
        SPAD[0x85] = c;
        v = D_800FB810[(c & 3) + SPAD[0x84] * 4];
        arg0[6] = 0;
        arg0[5] = v;
    }
}

#define func_8003744C func_800F60F0
#define D_80073C1C D_800FB91C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F612C.c"

#include "../shared/rock_02/func_800F6268.c"

#include "../shared/rock_02/func_800F6328.c"

#include "../shared/rock_02/func_800F6400.c"

#define func_8003744C func_800F64C0
#define D_80073C1C D_800FB938
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F64FC.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
extern u16 D_8009721A;
#define D_8009721A (*(s16*)&D_8009721A)

void func_800F6548(u8* arg0) {
    s32 lim;
    s32 y;
    ((void (*)(s32))move_object)((s32)arg0);
    lim = D_8009721A - 0x60;
    y = *(s16*)(arg0 + 0xE);
    y = y < lim;
    if (y) {
        // !FAKE: depin: dropping it breaks the match (20/23)
        register s32 c asm("$2");
        open_text_box(6, 0xFF, 0);
        c = arg0[6];
        arg0[3] = 0;
        arg0[6] = c + 1;
    }
}
#undef D_8009721A

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800F65A4(struct ObjectHeader* arg0) {
    if (D_8008EAFC == 0) {
        D_800CCEDF = 0x40;
        arg0->on_screen = 0;
        clear_object_slot();
    }
}

#define func_8003744C func_800F65DC
#define D_80073C1C D_800FB950
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F6618.c"

#include "../shared/rock_02/func_800F6684.c"

#include "../shared/rock_02/func_800F6708.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F6810(void* arg0) {
    func_800F82C0();
    animate_object(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (19/26)
        register s32 temp_v0 asm("$2") = M2C_FIELD(arg0, u16*, 0x7C);
        M2C_FIELD(arg0, u16*, 0x7C) = temp_v0 + 1;
        if ((s16)temp_v0 < 0x5B) {
            return;
        }
    }
    {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*); /* extern */
M2C_UNK func_800F82C0();       /* extern */

void func_800F6878(void* arg0) {
    func_800F82C0();
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFC0000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern s16 D_80097222;

void func_800F68CC(void* arg0) {
    animate_object(arg0);
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x70) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_80097222 + 0x70;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFA0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x100;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "../shared/rock_02/func_800F6954.c"

#define func_800F59C0 func_800F69A4
#include "../shared/rock_02/func_800F59C0.c"
#undef func_800F59C0

#define func_800F5A60 func_800F6A44
#define background_objects background_objects
#include "../shared/rock_02/func_800F5A60.c"
#undef func_800F5A60
#undef background_objects

#include "../shared/rock_02/func_800F6AE0.c"

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern u16 D_8009721A;

void func_800F6B20(void* arg0) {
    s32 t;
    s32 v;

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x40) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x40;
        if (--M2C_FIELD(arg0, s16*, 0x7E) != 0) {
            set_animation(arg0, 7);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6) = 1;
            return;
        }
        t = SPAD4C[0x85] + 1;
        SPAD4C[0x85] = t;
        v = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}

#define func_8003744C func_800F6BE0
#define D_80073C1C D_800FB97C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F6C1C.c"

#include "common.h"

#define SPAD (*(u8**)0x1F80004C)

s32 animate_object();
s32 func_800F82C0();

void func_800F6D18(u8* arg0) {
    u8* p;
    // !FAKE: depin: dropping it breaks the match (29/36)
    register u16 t asm("$2");

    p = SPAD;
    if (*(s8*)(p + 0x89) == 0) {
        *(s8*)(p + 0x89) = 0x78;
    }
    animate_object(arg0);
    func_800F82C0(arg0);
    t = *(u16*)(arg0 + 0x7C);
    *(u16*)(arg0 + 0x7C) = t + 1;
    if ((s16)t >= 0x3C) {
        *(u16*)(arg0 + 0x7C) = 0;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0xFFFC0000;
        arg0[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern s16 D_80097222;

void func_800F6DA8(void* arg0) {
    u8* sp;

    sp = SPAD4C;
    if (M2C_FIELD(sp, s8*, 0x89) == 0) {
        M2C_FIELD(sp, s8*, 0x89) = 0x78;
    }
    animate_object(arg0);
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x74) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_80097222 + 0x74;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFA0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x1000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800F82C0();
extern M2C_UNK D_8007523C;

void func_800F6E50(void* arg0) {
    u8* p = SPAD4C;
    // !FAKE: depin: dropping it breaks the match (29/36)
    register s32 t asm("$2");

    if (M2C_FIELD(p, s8*, 0x89) == 0) {
        M2C_FIELD(p, s8*, 0x89) = 0x78;
    }
    func_800F82C0(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t > 0x28) {
        SPAD4C[0x89] = 0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007523C;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_800F82C0();

void func_800F6EE0(void* arg0) {
    func_800F82C0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (17/24)
        register s32 temp_v0 asm("$2") = M2C_FIELD(arg0, u16*, 0x7C);
        M2C_FIELD(arg0, u16*, 0x7C) = temp_v0 + 1;
        if ((s16)temp_v0 < 0x1F) {
            return;
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (21/24)
        register s32 temp_b asm("$2");
        set_animation(arg0, 0x13);
        temp_b = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = temp_b + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_800F82C0();
extern struct X4_BackgroundObj background_objects[3];

void func_800F6F40(void* arg0) {
    func_800F82C0();
    ((void (*)(void*))animate_object)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        {
            s32 t = background_objects[0].unk1E - 0x140;
            if (M2C_FIELD(arg0, s16*, 0xA) <
                background_objects[0].unk1E +
                    (background_objects[0].unk1C - t) / 2) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK move_object(s32);
extern u16 D_8009721A;

void func_800F6FE0(void* arg0) {
    s32 t;
    s32 v;

    ((void (*)(void*))move_object)(arg0);
    if ((s16)D_8009721A + 0x40 >= M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x40;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        t = SPAD4C[0x85] + 1;
        SPAD4C[0x85] = t;
        v = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}

#define func_8003744C func_800F7074
#define D_80073C1C D_800FB9A4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F70B0.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F712C(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (23/30)
    register s32 t asm("$2");
    func_800F82C0();
    animate_object(arg0);
    t = *(u16*)(arg0 + 0x7C) + 1;
    *(s16*)(arg0 + 0x7C) = t;
    if ((s16)t >= 10) {
        start_pad_vibration(7);
        play_sound(2, 0x1D, arg0);
        arg0[6]++;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F71A4(u8* arg0) {
    s32 t;

    func_800F82C0();
    animate_object(arg0);
    if ((s8)arg0[2] == 1) {
        if ((*(s16*)(arg0 + 0x7C))++ < 0x42) {
            return;
        }
        play_sound(2, 0x1D, arg0);
        t = arg0[6];
        *(s16*)(arg0 + 0x7C) = 0;
    } else {
        play_sound(2, 0x1D, arg0);
        t = arg0[6];
        *(s16*)(arg0 + 0x7C) = 0x3A;
    }
    t--;
    arg0[6] = t;
}

#define func_8003744C func_800F723C
#define D_80073C1C D_800FB9B8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5F80 func_800F7278
#include "../shared/rock_23/func_800F5F80.c"
#undef func_800F5F80

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);
extern s16 D_80097222;

void func_800F72F4(void* arg0) {
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x70) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_80097222 + 0x70;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFA0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x100;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#define func_800F6954 func_800F7374
#include "../shared/rock_02/func_800F6954.c"
#undef func_800F6954

#define func_800F59C0 func_800F73C4
#include "../shared/rock_02/func_800F59C0.c"
#undef func_800F59C0

#define func_800F5A60 func_800F7464
#define background_objects background_objects
#include "../shared/rock_02/func_800F5A60.c"
#undef func_800F5A60
#undef background_objects

#include "../shared/rock_02/func_800F7500.c"

#define func_8003744C func_800F7534
#define D_80073C1C D_800FB9D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F7570.c"

#include "../shared/rock_02/func_800F7624.c"

#define func_800F56F8 func_800F76A8
#include "../shared/rock_02/func_800F56F8.c"
#undef func_800F56F8

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F7710(void* arg0) {
    u8* sp;
    u8 v;

    func_800F82C0();
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        sp = SPAD;
        v = D_800FB810[(sp[0x85] & 3) + sp[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}

#define func_8003744C func_800F777C
#define D_80073C1C D_800FB9E8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F77B8.c"

#include "../shared/rock_02/func_800F7818.c"

#include "../shared/rock_02/func_800F78DC.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();
#define SPAD4C (*(u8**)0x1F80004C)

void func_800F7970(u8* arg0) {
    ((M2C_UNK(*)())animate_object)();
    func_800F82C0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (31/37)
        register s32 t asm("$2") = *(u16*)(arg0 + 0x7C);
        s32 n = t + 1;
        *(u16*)(arg0 + 0x7C) = n;
        if ((s16)t >= 0x3C) {
            *(u16*)(arg0 + 0x7C) = 0;
            set_animation(arg0, 9);
            {
                // !FAKE: depin: dropping it breaks the match (18/37)
                register s32 v asm("$2") = arg0[6] + 1;
                arg0[6] = v;
            }
            return;
        }
    }
    if (SPAD4C[0x8A] != 0x11) {
        set_animation(arg0, 9);
        {
            // !FAKE: depin: dropping it breaks the match (20/37)
            register s32 v asm("$2") = 5;
            arg0[6] = v;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK animate_object();
M2C_UNK func_800F82C0(void* arg0);

void func_800F7A04(u8* arg0) {
    ((M2C_UNK(*)())animate_object)();
    func_800F82C0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (19/22)
        register u8* sp asm("$2") = SPAD4C;
        s32 b = sp[0x8A];
        // !FAKE: depin: dropping it breaks the match (19/22)
        register s32 k asm("$3") = 0x11;

        if (b == k) {
            return;
        }
    }
    {
        *(s16*)(arg0 + 0x7C) = 0x3C;
        arg0[6] = arg0[6] + 1;
    }
}

#undef SPAD4C

#include "../shared/rock_02/func_800F7A5C.c"

#define func_8003744C func_800F7AF0
#define D_80073C1C D_800FBA00
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_02/func_800F7B2C.c"

#include "../shared/rock_02/func_800F7B9C.c"

#include "../shared/rock_02/func_800F7C64.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F7CFC(void* arg0) {
    s16 t;

    ((void (*)(void*))animate_object)(arg0);
    ((void (*)(void*))func_800F82C0)(arg0);
    t = M2C_FIELD(arg0, s16*, 0x7C)++;
    if (t >= 0x3C) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    }
    if (SPAD4C[0x8A] != 0x11) {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u8*, 0x6) = 5;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
}

#include "../shared/rock_02/func_800F7D9C.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_800F82C0(void* arg0);

void func_800F7E68(u8* arg0) {
    ((M2C_UNK(*)())animate_object)();
    func_800F82C0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (15/22)
        register s32 t asm("$2") = *(u16*)(arg0 + 0x7C);

        *(u16*)(arg0 + 0x7C) = t + 1;
        if ((s16)t < 0x79) {
            return;
        }
    }
    {
        arg0[5] = 0xB;
        arg0[6] = 0;
    }
}

#define func_8003744C func_800F7EC0
#define D_80073C1C D_800FBA18
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F7B2C func_800F7EFC
#include "../shared/rock_02/func_800F7B2C.c"
#undef func_800F7B2C

#include "../shared/rock_02/func_800F7F6C.c"

#include "../shared/rock_02/func_800F8044.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F80C4(void* arg0) {
    u16 t;

    ((void (*)())animate_object)();
    ((void (*)())func_800F82C0)(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x3C) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        ((void (*)(void*, s32))set_animation)(arg0, 0x13);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    if (SPAD[0x8A] != 0x11) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x13);
        M2C_FIELD(arg0, u8*, 0x6) = 5;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
}

#define func_800F7D9C func_800F8160
#include "../shared/rock_02/func_800F7D9C.c"
#undef func_800F7D9C

#define func_800F7A5C func_800F822C
#include "../shared/rock_02/func_800F7A5C.c"
#undef func_800F7A5C

#include "common.h"
#define M2C_UNK s32

#define SPAD4C (*(u8**)0x1F80004C)

#include "mmx6/state.h"
extern u8 D_800FBA30[];

M2C_UNK func_800F82C0(void* arg0) {
    if (!(*(u8*)&D_80097420 & 1)) {
        *(u16*)((u8*)arg0 + 0xE) += (s8)D_800FBA30[(s8)SPAD4C[0x8C]];
        SPAD4C[0x8C] = (SPAD4C[0x8C] + 1) & 0xF;
    }
}

#undef SPAD4C

#include "common.h"

void func_800F8330(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", func_800F8338);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();     /* extern */
M2C_UNK func_8002EE10(void*); /* extern */
s32 check_enemy_hits(void*);  /* extern */
M2C_UNK func_80049D90(void*); /* extern */

M2C_UNK move_object(s32);
void func_800F8394(struct MainObj* arg0) {
    ((M2C_UNK(*)())animate_object)();
    ((M2C_UNK(*)())move_object)(arg0);
    if ((check_enemy_hits(arg0) < 0) || (arg0->collision_flags != 0) ||
        (func_8002EE10(arg0), (arg0->collision_flags != 0))) {
        func_80049D90(arg0);
        arg0->state = 2;
    }
}

#include "common.h"
#include "mmx6/rock_02.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */
extern M2C_UNK D_800FB310;
extern M2C_UNK D_800FB31C;

void func_800F8408(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FB304;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FB310;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800FB31C;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern s32 D_800754BC;

void func_800F8468(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (33/35)
    register s32 v asm("$2");

    animate_object(arg0);
    if (M2C_FIELD(arg0, u8*, 0x8E) != 0) {
        M2C_FIELD(arg0, u8*, 0x8E)--;
        return;
    }
    M2C_FIELD(arg0, s32**, 0x58) = &D_800754BC;
    move_object(arg0);
    v = M2C_FIELD(arg0, u8*, 0x70) & 8;
    if (v) {
        v = M2C_FIELD(arg0, u8*, 0x15);
        if (v == 0) {
            v = 0xFFFD0000;
        } else {
            v = 0x30000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = v;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        v = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = v + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK animate_object();
M2C_UNK move_object(s32);

void func_800F84F4(struct X4_MainObj* self) {
    u8 t;
    s32 v;

    animate_object(self);
    t = ((u8*)self)[0x8E];
    if (t != 0) {
        ((u8*)self)[0x8E] = t - 1;
        return;
    }
    move_object((s32)self);
    v = self->unk15;
    if (v == 0) {
        v = self->collision_flags & 2;
    } else {
        v = self->collision_flags & 1;
    }
    if (v != 0) {
        self->x_speed = 0;
        self->y_speed = 0x30000;
        self->terrain_box = 0;
        self->action_phase++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

M2C_UNK move_object(s32);
void func_800F8580(void* arg0) {
    u8 temp_v0;

    ((M2C_UNK(*)())animate_object)();
    temp_v0 = M2C_FIELD(arg0, u8*, 0x8E);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = (u8)(temp_v0 - 1);
        return;
    }
    ((M2C_UNK(*)())move_object)(arg0);
}

#include "../shared/rock_02/func_800F85C4.c"

#include "../shared/rock_02/func_800F8684.c"

#include "../shared/rock_02/func_800F86D0.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F8714(struct ObjectHeader* arg0) {
    void* temp_a1;

    ((M2C_UNK(*)())animate_object)();
    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    if (((M2C_FIELD(temp_a1, s32*, 4) & 0xFFFF00) == 0xB0200) ||
        ((M2C_FIELD(temp_a1, s8*, 5) == 9) &&
         (M2C_FIELD(temp_a1, s8*, 6) >= 4))) {
        arg0->on_screen = 0;
        arg0->state = 2;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F878C(void* arg0) {
    void* temp_a1;

    ((M2C_UNK(*)())animate_object)();
    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
    if ((M2C_FIELD(temp_a1, s8*, 5) == 0xA) &&
        (M2C_FIELD(temp_a1, s8*, 6) >= 9)) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#include "../shared/rock_02/func_800F87FC.c"

#include "../shared/rock_02/func_800F88FC.c"

#define func_8003744C func_800F8974
#define D_80073C1C D_800FBA54
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F88FC func_800F89B0
#include "../shared/rock_02/func_800F88FC.c"
#undef func_800F88FC

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(s32);

void func_800F8A28(u8* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object((s32)arg0);
    {
        // !FAKE: decrement temp lands in the first return register as retail
        register s32 temp_v0 asm("$2") = arg0[0x8D] - 1;
        arg0[0x8D] = temp_v0;
        if (!(temp_v0 & 0xFF)) {
            arg0[6]++;
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK move_object(s32);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800F8A80(void* arg0) {
    s32 ang;

    ((M2C_UNK(*)())animate_object)();
    {
        s32 u = M2C_FIELD(arg0, u8*, 7);
        // !FAKE: depin: dropping it breaks the match (45/49)
        register s32 t asm("$2") = M2C_FIELD(arg0, s8*, 7);
        if (t != 0) {
            s32 c = u - 1;
            M2C_FIELD(arg0, s8*, 7) = c;
            if ((s8)c == 0) {
                ang = ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                             g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
                {
                    s32 t;
                    s32 w;
                    s32 u;
                    s32 x;
                    t = rcos(ang);
                    w = t << 4;
                    M2C_FIELD(arg0, s32*, 0x20) = (t << 6) + w;
                    u = -rsin(ang);
                    x = u << 4;
                    M2C_FIELD(arg0, s32*, 0x24) = (u << 6) + x;
                }
                play_sound(2, 0x7D, arg0);
            }
        } else {
            move_object((s32)arg0);
        }
    }
}
#undef g_Player

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */

void func_800F8B44(void) {
    ((M2C_UNK(*)())animate_object)();
}

#define func_8003744C func_800F8B64
#define D_80073C1C D_800FBA5C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
extern u16 D_8009721A;

void func_800F8BA0(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x88) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x88;
        play_sound(2, 0x80, arg0);
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        func_80029478(0x1E, 2, 2);
        {
            // !FAKE: depin: dropping it breaks the match (30/33)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}

#include "../shared/rock_02/func_800F8C24.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F8C80(void* arg0) {
    u8 temp_v1;
    u8 var_v0;
    void* temp_s0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())animate_object)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(temp_v1 - 1);
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    M2C_FIELD(temp_s0, s8*, 0x88) = 1;
    if (M2C_FIELD(arg0, s8*, 2) == 9) {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF0;
    } else {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF;
    }
    M2C_FIELD(temp_s0, u8*, 0x8A) = var_v0;
    M2C_FIELD(arg0, s8*, 4) = 2;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                                /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800F8D14(void* arg0) {
    s32 var_s0;
    u8 temp_v1;

    ((M2C_UNK(*)())animate_object)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        if (!(temp_v1 & 7)) {
            func_80049EBC(arg0, 1, 0x20, 0x40);
        }
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(M2C_FIELD(arg0, u8*, 0x8D) - 1);
        return;
    }
    var_s0 = 3;
    do {
        func_80049EBC(arg0, 1, 0x20, 0x40);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    M2C_FIELD(arg0, s8*, 4) = 2;
}

#include "../shared/rock_02/func_800F8DB8.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(); /* extern */

void func_800F8E28(void* arg0) {
    u8 temp_v1;
    u8 var_v0;
    void* temp_s0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())animate_object)();
    temp_v1 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(temp_v1 - 1);
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 9) {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF0;
    } else {
        var_v0 = M2C_FIELD(temp_s0, u8*, 0x8A) & 0xF;
    }
    M2C_FIELD(temp_s0, u8*, 0x8A) = var_v0;
    M2C_FIELD(arg0, s8*, 4) = 2;
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_02.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern M2C_UNK D_800FB310;

void func_800F8EB4(void* arg0) {
    s32 ang;
    void* g;

    ((M2C_UNK(*)())animate_object)();
    g = &g_Player;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FB304;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FB310;
    ang = ratan2(M2C_FIELD(g, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                 M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 7;
    M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) << 7;
    M2C_FIELD(arg0, u8*, 0x8D) = 0x14;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
#undef g_Player

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                   /* extern */
s32 is_off_screen(void*, M2C_UNK, M2C_UNK); /* extern */

M2C_UNK move_object(s32);
void func_800F8F64(void* arg0) {
    M2C_UNK* var_v0;
    u8 temp_v0;

    ((M2C_UNK(*)())animate_object)();
    temp_v0 = M2C_FIELD(arg0, u8*, 0x8D);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = (u8)(temp_v0 - 1);
        return;
    }
    if (D_80097187 == 2) {
        var_v0 = &D_8007537C;
    } else {
        var_v0 = &D_800752DC;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = var_v0;
    ((M2C_UNK(*)())move_object)(arg0);
    if (is_off_screen(arg0, 0x30, 0x30) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_800F85C4 func_800F8FF0
#include "../shared/rock_02/func_800F85C4.c"
#undef func_800F85C4

#include "../shared/rock_02/func_800F90B0.c"

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F90FC (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern s32 D_800FBB2C;

void func_800F90FC(void* arg0) {
    s32 a;
    s32 base;
    s32 c;

    if (M2C_FIELD(arg0, s8*, 0x2) == 0 && D_800CCEED == 2) {
        return;
    }
    M2C_FIELD(arg0, u16*, 0x40) = D_80095098[func_8002A47C(0x84)] >> 7;
    M2C_FIELD(arg0, u16*, 0x42) =
        ((func_8002A47C(0x84) * 4 + 0x20) % 16) |
        (((func_8002A47C(0x84) + 8) / 4 + 0x1E0) << 6);
    a = func_8002A47C(0x84);
    base = SPAD20_800F90FC;
    c = *(s32*)(a * 4 + base);
    M2C_FIELD(arg0, s32**, 0x30) = &D_800FBB2C;
    M2C_FIELD(arg0, u16*, 0xA) = 0x1750;
    M2C_FIELD(arg0, u16*, 0xE) = 0x194;
    M2C_FIELD(arg0, u8*, 0x16) = 3;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, s32*, 0x3C) = base + c;
    ((void (*)())animate_object)(arg0);
    M2C_FIELD(arg0, u8*, 0x3) = 1;
    M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        return;
    }
    M2C_FIELD(arg0, u16*, 0xA) += 0x14;
    ((void (*)(void*, s32))set_animation)(arg0, 1);
    M2C_FIELD(arg0, u8*, 0x5) = 5;
}

#undef SPAD20_800F90FC

#define func_80041AB8 func_800F9274
#define D_80075FD8 D_800FBB3C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800FBB48[])(u8*);

void func_800F92B0(u8* arg0) {
    ((M2C_UNK(*)())animate_object)();
    D_800FBB48[*(s8*)(arg0 + 5)](arg0);
    func_8002CCB0(arg0, 0x80, 0x20);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002C22C();        /* extern */
M2C_UNK clear_object_slot(s32); /* extern */

void func_800F9308(s32 arg0) {
    func_8002C22C();
    clear_object_slot(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F9334(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F936C(void* arg0) {
    if (D_800970A5 == 0x14) {
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s16 D_800970AA;

void func_800F93B8(struct X4_BaseObj* arg0) {
    if (D_800970AA >= 0x16C0) {
        ((void (*)(s32, s32))func_8003D308)(0x14, 0x40);
        ((void (*)(s32, s32, s32))open_text_box)(2, 0xFF, 0);
        arg0->action++;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void* alloc_sprite_slot();

void func_800F9414(u8* arg0) {
    u8* temp_v0;

    if (D_8008EAFC == 0) {
        temp_v0 = alloc_sprite_slot();
        if (temp_v0 != 0) {
            temp_v0[0] = 0x41;
            temp_v0[1] = 8;
            temp_v0[2] = 1;
        }
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        arg0[6] = 0x14;
        arg0[5] = arg0[5] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F9488(u8* arg0) {
    s32 t;

    t = arg0[6] - 1;
    arg0[6] = t;
    if ((t << 0x18) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 2);
        arg0[5] = arg0[5] + 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK move_object(s32);                    /* extern */
M2C_UNK func_8003D330();                     /* extern */

void func_800F94DC(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1 == 1) {
        play_sound(5, 0, arg0);
    } else if (temp_v1 == 2) {
        move_object(arg0);
    }
    if (M2C_FIELD(arg0, s16*, 0xE) < 0xC0) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003D330();
        }
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#define func_80041AB8 func_800F9570
#define D_80075FD8 D_800FBB60
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
extern u32* D_80095098;

void func_800F95AC(struct X4_MainObj* self) {
    s32* p;
    s32 v;

    if (D_800CCEED >= 2) {
        ((M2C_UNK(*)())clear_object_slot)();
        return;
    }
    self->unk40 = D_80095098[func_8002A47C(0x91)] >> 7;
    self->unk42 = ((func_8002A47C(0x91) * 4 + 0x20) % 16) |
                  (((func_8002A47C(0x91) + 8) / 4 + 0x1E0) << 6);
    v = func_8002A47C(0x91);
    p = SPAD20;
    v = p[v];
    self->unk16 = 0x13;
    self->animation_step.fields.frame_index = 0;
    self->state++;
    self->sprite_frames = (const u8*)p + v;
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F96AC(void* arg0) {
    func_8002CCB0(arg0, 0x30, 0x20);
    if (D_800CCEED >= 2) {
        clear_object_slot(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F96F8(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#define func_80041AB8 func_800F9718
#define D_80075FD8 D_800FBB6C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F9754 (*(s32*)0x1F800020)

s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
extern u32* D_80095098;

void func_800F9754(void* arg0) {
    s32 a;
    s32 base;
    s32 c;

    if (D_800CCEED >= 2) {
        ((M2C_UNK(*)())clear_object_slot)();
        return;
    }
    M2C_FIELD(arg0, u16*, 0x40) = D_80095098[func_8002A47C(0x92)] >> 7;
    M2C_FIELD(arg0, u16*, 0x42) =
        ((func_8002A47C(0x92) * 4 + 0x20) % 16) |
        (((func_8002A47C(0x92) + 8) / 4 + 0x1E0) << 6);
    a = func_8002A47C(0x92);
    base = SPAD20_800F9754;
    c = *(s32*)(a * 4 + base);
    M2C_FIELD(arg0, u8*, 0x16) = 0x13;
    M2C_FIELD(arg0, u8*, 0x47) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    M2C_FIELD(arg0, s32*, 0x3C) = base + c;
}

#undef SPAD20_800F9754

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F9854(void* arg0) {
    func_8002CCB0(arg0, 0x20, 0x20);
    if (D_800CCEED >= 2) {
        clear_object_slot(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F98A0(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
struct X4_QuadObj* alloc_class6_slot(void);
s32 random_byte();

void func_800F98C0(void* arg0) {
    s8 state;
    void* parent;
    struct X4_QuadObj* q;
    u8 kind;

    state = M2C_FIELD(arg0, s8*, 0x45);
    parent = M2C_FIELD(arg0, void**, 0x50);
    if (state == 1) {
        M2C_FIELD(arg0, u8*, 0x54) = 0x78;
        M2C_FIELD(parent, u8*, 0x5) = 5;
        M2C_FIELD(arg0, u8*, 0x5)++;
    } else if (state == 2) {
        M2C_FIELD(parent, u16*, 0x42) |= 0x8000;
        kind = M2C_FIELD(arg0, u8*, 0x47);
        if (kind == 0x12 || kind == 0x14 || kind == 0x18) {
            q = alloc_class6_slot();
            if (q != 0) {
                q->active = 0x13;
                q->id = 0xF;
                switch (random_byte() % 3) {
                case 0:
                    M2C_FIELD(q, s32*, 0x38) = 0;
                    break;
                case 1:
                    M2C_FIELD(q, s32*, 0x38) = 0x400;
                    break;
                case 2:
                    if (M2C_FIELD(arg0, u8*, 0x15) == 0x40) {
                        M2C_FIELD(q, s32*, 0x38) = 0xE00;
                    } else {
                        M2C_FIELD(q, s32*, 0x38) = 0x200;
                    }
                    break;
                }
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    q->x_pos.i.hi = M2C_FIELD(arg0, u16*, 0xA) + 0x38;
                } else {
                    q->x_pos.i.hi = M2C_FIELD(arg0, u16*, 0xA) - 0x38;
                }
                play_sound(2, 0x68, arg0);
                q->y_pos.i.hi = M2C_FIELD(arg0, u16*, 0xE);
                q->unk36 = 0;
                q->bg_offset = M2C_FIELD(arg0, u8*, 0x14);
                q->unk34 = 0x13;
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F9A54 (*(s32*)0x1F800020)

s32 func_8002A47C(s32);
void* enemy_slot_alloc();
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800F9A54(void* arg0) {
    void* obj;
    s32 a;
    s32 base;

    if (g_Player.hp < 2) {
        g_Player.hp = 2;
    }
    obj = enemy_slot_alloc();
    M2C_FIELD(obj, u8*, 0x0) = 0x41;
    M2C_FIELD(obj, u8*, 0x1) = 0x37;
    M2C_FIELD(obj, u8*, 0x2) = 0;
    M2C_FIELD(obj, u16*, 0xA) = 0x1812;
    M2C_FIELD(obj, u16*, 0xE) = 0x15A;
    M2C_FIELD(obj, u16*, 0x40) = 0x1E0;
    M2C_FIELD(obj, u16*, 0x42) =
        ((func_8002A47C(0x37) * 4 + 0x20) % 16) |
        (((func_8002A47C(M2C_FIELD(obj, s8*, 0x1)) + 8) / 4 + 0x1E0) << 6);
    a = func_8002A47C(M2C_FIELD(obj, s8*, 0x1));
    base = SPAD20_800F9A54;
    M2C_FIELD(obj, s32*, 0x3C) = base + M2C_FIELD(base, s32*, a * 4);
    D_800CCEF6 = 1;
    M2C_FIELD(arg0, u8*, 0x4)++;
}

#undef SPAD20_800F9A54
#undef g_Player

#define func_80041AB8 func_800F9B70
#define D_80075FD8 D_800FBC3C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
extern const u8* const D_800FBC2C[];

void func_800F9BAC(struct X4_MainObj* self) {
    u8 dir;

    self->animation_table = D_800FBC2C;
    dir = D_800970B5;
    self->unk15 = dir;
    if (dir == 0) {
        self->x_pos.i.hi += 0x60;
    } else {
        self->x_pos.i.hi -= 0x60;
    }
    {
        s32 y = (u16)D_80097206;
        self->unk16 = 3;
        self->y_pos.i.hi = y - 0x20;
    }
    ((void (*)(void*, s32))set_animation)(self, 0);
    {
        s32 st = (u8)self->state;
        self->on_screen = 1;
        self->bg_offset = 0;
        self->action_phase = 0x3C;
        self->state = ++st;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800FBC48[])(void*);

void func_800F9C4C(s8* arg0) {
    animate_object(arg0);
    D_800FBC48[arg0[5]](arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F9CA4(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

void func_800F9CC4(u8* arg0) {
    s32 t;

    t = arg0[6] - 1;
    arg0[6] = t;
    if ((t << 0x18) == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0xA, arg0);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0xFFF80000;
        arg0[5] = arg0[5] + 1;
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);

void func_800F9D24(void* arg0) {
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (D_80097206 + 0xAA)) {
        M2C_FIELD(arg0, s16*, 0xE) = (s16)((u16)D_80097206 + 0xAA);
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800F9D88(u8* arg0) {
    if (((s8*)arg0)[0x45] == 1) {
        set_animation(arg0, 2);
        play_sound(2, 0x66, arg0);
        arg0[5]++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */

void func_800F9DE0(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8*, 0x54) - 1;
    M2C_FIELD(arg0, u8*, 0x54) = temp_v0;
    if ((temp_v0 << 0x18) == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0xB, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F9E44(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
        M2C_FIELD(arg0, u8*, 0x5) = M2C_FIELD(arg0, u8*, 0x5) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK move_object(s32);

void func_800F9E94(struct X4_MainObj* self) {
    move_object((s32)self);
    if ((self->y_pos.i.hi + 0x16) <= (D_80097206 - 0x20)) {
        self->action++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800F9EE8(struct X4_MainObj* self) {
    if (*(s8*)self->attack_box == 0) {
        ((void (*)(s32, s32, s32))open_text_box)(3, 0xFF, 0);
        self->action++;
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F9F3C(void* arg0) {
    if (D_8008EAFC == 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_02/nonmatchings/E9860", D_800F9F68);
// clang-format on
