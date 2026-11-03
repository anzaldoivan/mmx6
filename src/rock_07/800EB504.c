#define func_80041AB8 func_800EB504
#define D_80075FD8 D_800F885C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800F86CC[])(void*);

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define BG ((u8*)&background_objects[0])

void func_800EB540(u8* self) {
    u8* bg;
    s32 t;

    D_800F86CC[S8(self, 0x5)](self);
    bg = BG;
    U16(self, 0xA) = U16(self, 0x82) + (U16(bg, 0xA) + U16(bg, 0x5E));
    t = U16(bg, 0xE) + 0x3B8;
    t -= U16(bg, 0x62);
    U16(self, 0xE) = U16(self, 0x86) + t;
}

#undef S8
#undef U16
#undef BG

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800EB5C0(struct X4_MainObj* arg0) {
    g_playthrough_state.checkpoint = 2;
    arg0->unk7C = 0x7F;
    arg0->unk7E = 0x19;
    arg0->invincibility_timer = 0x19;
    arg0->unk42 &= 0x7FFF;
    arg0->action++;
    ((s8*)&g_playthrough_state)[0x26] = 1;
    func_8003D308(0x14, D_800970B5);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8003D330();

void func_800EB62C(struct X4_MainObj* arg0) {
    struct X4_MainObj* p = (struct X4_MainObj*)arg0->ext.raw[2];

    if (p->active != 0) {
        if (p->unk7 == 0) {
            if (--arg0->unk7E == -1) {
                arg0->unk7E = 5;
                arg0->unk42 ^= 0x8000;
            }
        }
    } else {
        func_8003D330();
        clear_object_slot(arg0);
    }
}

#include "common.h"

void func_800EB6B8(s8* arg0) {
    s8* p;

    p = *(s8**)(arg0 + 0x80);
    if (arg0[5] == 0) {
        arg0[3] = 0;
        *(s32*)(arg0 + 0x68) = 0;
        *(s32*)(arg0 + 0x50) = 0;
        *(s32*)(arg0 + 0x54) = 0;
        arg0[5]++;
    }
    if (p[4] != 1) {
        arg0[4] = 5;
        return;
    }
    if (p[7] == 0) {
        return;
    }
    switch (p[7]) {
    case 5:
        if (arg0[2] == 0x10) {
            p[7] = 0;
        }
        break;
    case 6:
        if (arg0[2] == 0x11) {
            p[7] = 0;
        }
        break;
    case 7:
        if (arg0[2] == 0x12) {
            p[7] = 0;
        }
        break;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB770(void) {
    clear_object_slot();
}

#define func_8003744C func_800EB790
#define D_80073C1C D_800F86DC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800EB7CC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0x12C;
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
