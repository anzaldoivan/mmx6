#include "common.h"

void func_800F4144(void) {
}

#define func_8003744C func_800F414C
#define D_80073C1C D_800F7C14
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/globals.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();               /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F4188(void* arg0) {
    void* temp_v0;

    if (D_800970A5 == 0x14) {
        D_8009723F = 2;
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x18;
            M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/commander_yammark/func_800F4220.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
void* enemy_slot_alloc();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern s32 D_800F7950;
extern s16 D_800F7DC4;
extern u16* D_800F7DF0;
extern s16 D_800F7E0C;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F42D8(void* arg0) {
    s32 i;
    void* p;

    if (P(arg0, 0x68) == 0 && H(arg0, 0xE) >= D_800F7DC4 - 0x80) {
        P(arg0, 0x68) = &D_800F7950;
    }
    i = 0;
    if (UB(arg0, 0x70) & 8) {
        // !FAKE: depin: dropping it breaks the match (66/71)
        register u16* q asm("$4") = D_800F7DF0;
        // !FAKE: depin: dropping it breaks the match (64/71)
        register s32 n asm("$3") = *(s16*)q;
        D_800F7E0C = 0;
        if (n > 0) {
            do {
                p = enemy_slot_alloc();
                if (p != 0) {
                    u8 b;
                    UB(p, 0x0) = UB(arg0, 0x0);
                    b = UB(arg0, 0x1);
                    UB(p, 0x2) = 1;
                    UB(p, 0x5) = 0;
                    P(p, 0x80) = arg0;
                    UB(p, 0x1) = b;
                }
                i++;
            } while (i < *(s16*)D_800F7DF0);
        }
        W(arg0, 0x24) = 0;
        UB(arg0, 0x6)++;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern struct X4_EngineObj g_playthrough_state;
extern u16* D_800F7DF0;
#define D_800F7DF0 (*(s16**)&D_800F7DF0)
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F43F4(struct X4_MainObj* self) {
    if (D_800F7E0C == *D_800F7DF0 * 2) {
        struct X4_EngineObj* e = &g_playthrough_state;
        if (e->stage != 0xC) {
            open_text_box(0, 0xFF, e->character_state.bytes[8]);
            e->character_state.bytes[8] = 1;
        }
        D_800F7E0E = 2;
        self->unk7C = 0;
        self->action_phase++;
    }
    animate_object(self);
    apply_object_motion(self);
    func_8002CCB0(self, 0x40, 0x40);
}
#undef D_800F7DF0

#include "../shared/commander_yammark/func_800F44A4.c"

#include "../shared/commander_yammark/func_800F4508.c"

#include "../shared/commander_yammark/func_800F4588.c"

#include "../shared/commander_yammark/func_800F4674.c"

#include "common.h"

void func_800F46D8(void) {
}

#define func_800F4674 func_800F46E0
#define D_800F7C30 D_800F7C34
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#include "../shared/commander_yammark/func_800F4744.c"

#include "common.h"
#include "mmx6/rock_03.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F7E0C;

void func_800F4824(void* arg0) {
    if (D_800F7E0C == D_800F7E10) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/commander_yammark/func_800F4858.c"

#include "../shared/commander_yammark/func_800F48A8.c"

#include "../shared/commander_yammark/func_800F48EC.c"

#define func_800F4674 func_800F4980
#define D_800F7C30 D_800F7C50
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#define func_800F4744 func_800F49E4
#include "../shared/commander_yammark/func_800F4744.c"
#undef func_800F4744

#include "common.h"
#include "mmx6/rock_03.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F7E0C;

void func_800F4AC4(void* arg0) {
    if (D_800F7E0C == D_800F7E10) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4858 func_800F4AF8
#include "../shared/commander_yammark/func_800F4858.c"
#undef func_800F4858

#include "../shared/commander_yammark/func_800F4B48.c"

#define func_800F4674 func_800F4B98
#define D_800F7C30 D_800F7C6C
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#define func_800F4744 func_800F4BFC
#include "../shared/commander_yammark/func_800F4744.c"
#undef func_800F4744

#include "common.h"
#include "mmx6/rock_03.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F7E0C;

void func_800F4CDC(void* arg0) {
    if (D_800F7E0C == D_800F7E10) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F4D10(u8* arg0) {
    if (D_800F7E0C == 0) {
        set_animation(arg0, 0);
        play_sound(2, 0x27, arg0);
        D_800F7E0E = 2;
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[6]++;
    }
}

#include "../shared/commander_yammark/func_800F4D70.c"

#define func_800F4674 func_800F4DE0
#define D_800F7C30 D_800F7C88
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#define func_800F4744 func_800F4E44
#include "../shared/commander_yammark/func_800F4744.c"
#undef func_800F4744

#include "common.h"
#include "mmx6/rock_03.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F7E0C;

void func_800F4F24(void* arg0) {
    if (D_800F7E0C == D_800F7E10) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F4F58(struct X4_MainObj* arg0) {
    if (D_800F7E0C == 0) {
        set_animation(arg0, 0);
        play_sound(2, 0x27, arg0);
        D_800F7E0E = 5;
        arg0->unk7C = 0;
        *((u8*)arg0 + 6) = *((u8*)arg0 + 6) + 1;
    }
}

#include "../shared/commander_yammark/func_800F4FB8.c"

#include "../shared/commander_yammark/func_800F5048.c"

#include "../shared/commander_yammark/func_800F5108.c"

#define func_800F4674 func_800F517C
#define D_800F7C30 D_800F7CA8
#include "../shared/commander_yammark/func_800F4674.c"
#undef func_800F4674
#undef D_800F7C30

#define func_800F4744 func_800F51E0
#include "../shared/commander_yammark/func_800F4744.c"
#undef func_800F4744

#include "common.h"
#include "mmx6/rock_03.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F7E0C;

void func_800F52C0(void* arg0) {
    if (D_800F7E0C == D_800F7E10) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/commander_yammark/func_800F52F4.c"

#include "../shared/commander_yammark/func_800F5358.c"

#include "../shared/commander_yammark/func_800F53D4.c"

#include "../shared/commander_yammark/func_800F5434.c"

#define func_80041AB8 func_800F54A4
#define D_80075FD8 D_800F7CC8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/commander_yammark/func_800F54E0.c"

#include "../shared/commander_yammark/func_800F5564.c"
