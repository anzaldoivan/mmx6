#include "common.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

M2C_UNK func_8002C9D4();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);

void func_80051FA8(struct X4_AnimatedObj* arg0) {
    if (func_8002CBFC(arg0, 0x88, 0x88) == 1) {
        func_8002C9D4(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_80051FE8(void* arg0, void* arg1) {
    s8 v;
    s32 one = 1;

    FU8(arg0, 3) = one;
    F32(arg0, 0x3C) = F32(arg1, 0x3C);
    F32(arg0, 0x30) = F32(arg1, 0x30);
    F16(arg0, 0x40) = F16(arg1, 0x40);
    F16(arg0, 0x42) = F16(arg1, 0x42);
    FU8(arg0, 0x15) = 0;
    F32(arg0, 8) = F32(arg1, 8);
    F32(arg0, 0xC) = F32(arg1, 0xC);
    switch (F8(arg0, 1)) {
    case 35:
        FU8(arg0, 0x16) = 3;
        set_animation(arg0, F8(arg0, 2));
        break;
    case 36:
        FU8(arg0, 0x16) = one;
        set_animation(arg0, 7);
        break;
    case 37:
        v = F8(arg0, 2);
        FU8(arg0, 0x16) = 0;
        if (v == 0) {
            set_animation(arg0, 8);
        } else if (v == 3) {
            set_animation(arg0, 0xE);
        } else {
            set_animation(arg0, 9);
        }
        break;
    }
    FU8(arg0, 5) = 0;
    FU8(arg0, 4) = FU8(arg0, 4) + 1;
}

#undef set_animation

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CA14();
s32 func_8002CAB4(struct X4_BaseObj*);
extern s8 D_8008EAB0;
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_8005211C(void* arg0) {
    u16* r;
    u16 v;

    if (func_8002CAB4(arg0) == 0) {
        r = M2C_FIELD(arg0, u16**, 0x18);
        if (g_Player.x_pos.i.hi <= r[1] && r[0] <= g_Player.x_pos.i.hi &&
            g_Player.y_pos.i.hi <= r[3] && r[2] <= g_Player.y_pos.i.hi) {
            background_objects[0].unk47 = 2;
            v = M2C_FIELD(arg0, u16**, 0x18)[4];
            if (v != 0xFFFF) {
                background_objects[0].unk26 = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[5];
            if (v != 0xFFFF) {
                background_objects[0].unk24 = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[6];
            if (v != 0xFFFF) {
                background_objects[0].unk2A = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[7];
            if (v != 0xFFFF) {
                background_objects[0].unk28 = v;
            }
            if (M2C_FIELD(arg0, s8*, 2) & 0x80) {
                D_8008EAB0 = 1;
                clear_object_slot(arg0, &g_Player);
            }
        }
    } else {
        func_8002CA14(arg0);
    }
}

#define func_80041AB8 func_80052258
#define D_80075FD8 D_800791E8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8005211C(void* arg0);
extern s32 D_80079D70[];
extern struct X4_EngineObj g_playthrough_state;

void func_80052294(u8* arg0) {
    F8(arg0, 0x14) = 0;
    arg0[4]++;
    F32(arg0, 0x18) = D_80079D70[g_playthrough_state.stage * 2 +
                                 g_playthrough_state.substage] +
                      (arg0[2] & 0x7F) * 0x10;
    func_8005211C(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14();
extern u8* D_80079ED4[];
extern s32 D_80079EDC[][16];
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern struct X4_EffectObj D_8009B7B0[0x20];
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_80052300(void* arg0) {
    u8 i;
    u16 c;
    u8* p;

    i = 0;
    if (M2C_FIELD(arg0, s8*, 2) != -1) {
        M2C_FIELD(arg0, u8**, 0x14) = D_80079ED4[M2C_FIELD(arg0, s8*, 2)];
        M2C_FIELD(arg0, u8*, 0x18) = M2C_FIELD(arg0, u8**, 0x14)[2];
        do {
            D_80090C90[i] = D_80079EDC[M2C_FIELD(arg0, s8*, 2)][i];
            i++;
        } while (i < 0x10);
        D_800CF850 = M2C_FIELD(arg0, u8**, 0x14)[3] & 1;
        D_8009742C = M2C_FIELD(arg0, u8**, 0x14)[3] & 2;
        D_80090D56 = M2C_FIELD(arg0, u8**, 0x14)[3] & 4;
        c = *(u16*)M2C_FIELD(arg0, u8**, 0x14);
        D_800CF854 = c & 0x1F;
        D_80097430 = c & 0x3E0;
        D_80090D5C = c & 0x7C00;
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    D_80090D5C = 0;
    D_80097430 = 0;
    D_800CF854 = 0;
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    for (p = (u8*)D_8009B7B0; p < (u8*)D_8009B7B0 + 0x1200; p += 0x30) {
        if (M2C_FIELD(p, s8*, 2) == 2 && p != arg0) {
            func_8002CA14(p);
        }
    }
    func_8002CA14(arg0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CA14();
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_800524B8(u8* arg0) {
    u8* p;
    u8* q;
    u16 v;
    u8 t;

    if ((s8)--arg0[0x18] == -1) {
        q = *(u8**)(arg0 + 0x14) += 4;
        if (*(u16*)q == 0x8000) {
            t = q[3];
            if (t == 1) {
                func_8002CA14(arg0, q);
                D_800C4560 = t;
                return;
            }
            *(u8**)(arg0 + 0x14) = q + ((s8)q[2] << 2);
        }
        p = *(u8**)(arg0 + 0x14);
        v = *(u16*)p;
        arg0[0x18] = p[2];
        D_800CF854 = v & 0x1F;
        D_80097430 = v & 0x3E0;
        D_80090D5C = v & 0x7C00;
        D_800CF850 = (*(u8**)(arg0 + 0x14))[3] & 1;
        D_8009742C = (*(u8**)(arg0 + 0x14))[3] & 2;
        D_80090D56 = (*(u8**)(arg0 + 0x14))[3] & 4;
        D_800C4560 |= 5;
    }
}

#define func_80041AB8 func_800525D4
#define D_80075FD8 D_80079F5C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8** D_8007A01C[];
extern u8* D_80079F64[];
extern u8 D_800C4560;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800E4480;
M2C_UNK func_8002C9D4();

#define SCRATCH_28 (*(s32**)0x1F800028)
#define SCRATCH_30 (*(s32**)0x1F800030)
#define F_U8(o) (*(u8*)(arg0 + (o)))
#define F_S8(o) (*(s8*)(arg0 + (o)))
#define F_PTR(o) (*(u8**)(arg0 + (o)))
#define F_WPTR(o) (*(s32**)(arg0 + (o)))

void func_80052610(u8* arg0) {
    u8* p;
    s32* dst;
    s32* src;
    u32 i;

    i = F_U8(2);
    F_U8(0) = 9;
    F_PTR(0x1C) = D_8007A01C[g_playthrough_state.stage * 2 +
                             g_playthrough_state.substage][i];
    if (F_PTR(0x1C) == 0) {
        func_8002C9D4(arg0);
        return;
    }
    i = (u8)(i - 1);
    p = D_80079F64[g_playthrough_state.stage * 2 +
                   g_playthrough_state.substage];
    while (i != 0xFF) {
        i = (u8)(i - 1);
        p += 2;
    }
    F_WPTR(0x18) = SCRATCH_28 + p[0] * 8;
    dst = F_WPTR(0x18);
    F_WPTR(0x14) = SCRATCH_30 + F_PTR(0x1C)[0] * 8;
    src = F_WPTR(0x14);
    F_U8(0x21) = F_PTR(0x1C)[1];
    F_U8(0x20) = p[1];
    for (i = 0; i < F_S8(0x20) * 8; i++) {
        *dst++ = *src++;
    }
    D_800C4560 |= 1;
    F_U8(4)++;
    if (g_playthrough_state.stage == 8 && g_playthrough_state.checkpoint == 0) {
        D_800E4480 = 1;
    } else {
        D_800E4480 = 0;
    }
}

#include "common.h"

extern u8 D_800C4560;
extern s8 D_800E4480;

#define SCRATCH_30 (*(s32**)0x1F800030)
#define F_U8(o) (*(u8*)(arg0 + (o)))
#define F_S8(o) (*(s8*)(arg0 + (o)))
#define F_PTR(o) (*(u8**)(arg0 + (o)))
#define F_SPTR(o) (*(s8**)(arg0 + (o)))
#define F_WPTR(o) (*(s32**)(arg0 + (o)))

void func_800527A4(u8* arg0) {
    s32* dst;
    s32* src;
    u32 i;
    s8 step;

    if (D_800E4480 == 0 && (s8)--F_U8(0x21) == -1) {
        F_PTR(0x1C) += 2;
        step = F_SPTR(0x1C)[1];
        if (step == 0) {
            F_U8(4)++;
            return;
        }
        if (step < 0) {
            F_PTR(0x1C) += step * 2;
        }
        dst = F_WPTR(0x18);
        F_U8(0x21) = F_PTR(0x1C)[1];
        F_WPTR(0x14) = SCRATCH_30 + F_PTR(0x1C)[0] * 8;
        src = F_WPTR(0x14);
        for (i = 0; i < F_S8(0x20) * 8; i++) {
            *dst++ = *src++;
        }
        D_800C4560 |= 1;
    }
}

#define func_80041AB8 func_80052898
#define D_80075FD8 D_8007A0D4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800528D4(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#include "psyq/libsnd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern u16 D_8007A0E0[];
extern u8 D_8008EC08;
extern s8 D_80090D50[6];
extern u8 D_8009509C;
extern s32 D_80097760;
extern s32 D_8009776C;
extern s32 D_800B91B8;
extern u8 D_800CC868;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CCEDC;
extern u8 D_800CD40C;
extern u32 D_800E4488;
extern s32 D_800E448C;
extern s32 D_800E4490;

#define ENG_43B (*(u8*)((u8*)&g_playthrough_state + 0x43B))

void func_800528F4(struct X4_BaseObj* self) {
    u8 sp10;
    s8 state;

    sp10 = 0xA0;
    state = self->unk5;
    switch (state) {
    case 0:
        if (D_800CD40C == 0) {
            // !FAKE: depin: dropping it breaks the match (161/228)
            register u16* p asm("$3") = D_8007A0E0;
            p += g_playthrough_state.stage;

            if (*p == 0) {
                goto set3;
            }
            if (g_playthrough_state.stage >= 0x13) {
                if (ENG_43B == 0) {
                    *p = 0x8A;
                } else if (ENG_43B == 1) {
                    *p = 0x8B;
                } else {
                    *p = 0x8C;
                }
            } else if (g_playthrough_state.stage == 0) {
                if (g_playthrough_state.character_state.bytes[0] != 0) {
                    D_800CC868 = 0;
                    D_8007A0E0[0] = 0x7C;
                } else {
                    D_8007A0E0[0] = 0x7B;
                }
            }
            {
                struct X4_EngineObj* e = &g_playthrough_state;

                if (e->stage == 0xC && e->substage != 0) {
                    s8 cur = e->character_state.bytes[0xB];

                    if (cur == e->character_state.bytes[0xC] &&
                        D_800CC868 != 0) {
                    set3:
                        self->unk5 = 3;
                        return;
                    }
                    if (cur == 1) {
                        D_8007A0E0[e->stage] = 0x85;
                    } else {
                        D_8007A0E0[e->stage] = 0x86;
                    }
                    D_800CC868 = 0;
                    g_playthrough_state.character_state.bytes[0xC] =
                        g_playthrough_state.character_state.bytes[0xB];
                }
            }
            if (D_800CC868 == 0) {
                self->unk5++;
            } else {
                self->unk5 = 3;
            }
        }
        if (self->unk5 == 1) {
            if (D_80090D50[5] != -1) {
                SsVabClose(D_80090D50[5]);
                D_80090D50[5] = -1;
                D_800E4490 = D_8009776C;
            } else {
                D_800E4490 = D_80097760;
            }
        }
        break;
    case 1:
        D_800E448C = D_800B91B8;
        func_80014F70(D_8007A0E0[D_800CCEDC], 4, D_800E4490);
        D_800E4488 = 0;
        self->unk5++;
        break;
    case 2:
        if (D_8009509C == state && D_8008EC08 == 0) {
            D_800CC868 = 1;
            self->unk5++;
            if (g_playthrough_state.stage == 0xC &&
                g_playthrough_state.substage != 0) {
                D_800B91B8 = D_800E448C;
            }
        } else if (D_8009509C & 0xC0) {
            func_80014F70(D_8007A0E0[D_800CCEDC], 4, D_800E4490);
            D_800E4488 = 0;
        } else if (++D_800E4488 >= 0x259) {
            func_800648B4(0);
            while (CdReset(0) == 0) {
            }
            while (CdControlB(0xE, (s32)&sp10, 0) == 0) {
            }
            VSync(3);
            D_8009509C = 0xC0;
        }
        break;
    case 3:
        self->state++;
        break;
    }
}

#define func_80041AB8 func_80052C84
#define D_80075FD8 D_8007A110
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80018774(M2C_UNK); /* extern */

void func_80052CC0(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x16) = -1;
    M2C_FIELD(arg0, s16*, 0x14) = 0x64;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_80018774(3);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */
extern s32 D_8008EC0C;
extern s16 D_8009741A;

void func_80052CFC(s32 arg0) {
    D_8008EC0C = 1;
    D_8009741A = 0x3C;
    ((M2C_UNK(*)())clear_object_slot)(arg0);
}

#define func_80041AB8 func_80052D30
#define D_80075FD8 D_8007A11C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*, void*); /* extern */
extern s8 D_800CCEED;

void func_80052D6C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    if ((M2C_FIELD(arg0, u8*, 2) & 0xF) == D_800CCEED) {
        func_8002CA14(arg0, arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14();
s32 func_8002CAB4(struct X4_BaseObj*);
extern s16 D_800970AA;
extern s16 D_800970AE;
extern s8 D_800CCEED;

void func_80052DB8(void* arg0) {
    s32 t;
    u8 b;

    if (func_8002CAB4(arg0) == 0) {
        b = M2C_FIELD(arg0, u8*, 2);
        if (M2C_FIELD(arg0, s8*, 2) & 0x80) {
            t = M2C_FIELD(arg0, s16*, 0xE) > D_800970AE;
        } else {
            t = M2C_FIELD(arg0, s16*, 0xA) > D_800970AA;
        }
        if (t == 0) {
            D_800CCEED = b & 0x7F;
            ((void (*)())func_8002CA14)(arg0, b);
        }
    } else {
        ((void (*)())func_8002CA14)(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

s32 func_80014B78(void);
void read_rock_bin_member(s32, s32);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
void* func_8002BCCC(void*, s32);
M2C_UNK clear_object_slot();
extern u8 D_800CD30B;

#define SCRATCH_30 (*(s32**)0x1F800030)

void func_80052E44(u8* arg0) {
    s32 a0;
    u8* p;
    s32* a1;
    u8 d;

    if (*(s8*)(arg0 + 4) == 0) {
        switch (D_800CD30B) {
        default:
            a0 = 0x2D;
            break;
        case 0:
            a0 = 0x2B;
            break;
        case 1:
            a0 = 0x2C;
            break;
        }
        read_rock_bin_member(a0, 0x800FA000);
        {
            s32 t = arg0[4] + 1;
            arg0[4] = t;
        }
        return;
    }
    if (func_80014B78() != 0) {
        p = func_8002BCCC(0, 0);
        if (p != 0) {
            p[0] = 0x41;
            d = D_800CD30B;
            if (d == 0) {
                p[1] = 0x35;
                a1 = SCRATCH_30;
            } else if (d == 1) {
                p[1] = 0x37;
                p[2] = d;
                a1 = SCRATCH_30 + 0x40;
            } else {
                p[1] = 0x3F;
                a1 = SCRATCH_30 + 0x60;
            }
            load_palette(0x58, a1, 8);
            ((M2C_UNK(*)())clear_object_slot)(arg0);
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80052F64);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B6B0();
extern struct X4_PlayerObj g_Player;
extern s8 D_800970A5;
extern struct X4_EngineObj g_playthrough_state;

void func_80053274(void* arg0) {
    u8* p = arg0;
    u8* e;

    if ((((s8*)p)[2] & 0xF0) || D_800970A5 == 0x14) {
        e = (u8*)&g_playthrough_state;
        e[0x1C] = 1;
        if (*(u16*)(p + 0x14) != 0) {
            ((void (*)())func_8002B6B0)();
            {
                u8* pl = (u8*)&g_Player;
                pl[0x71] |= 8;
            }
        }
        p[0] |= 8;
        e[0x16] = 1;
        e[0x12] = 1;
        e[0x13] = 1;
        e[0x19] = 1;
        e[0x11] = 1;
        e[0x18] = 1;
        e[0x17] = 1;
        e[0x14] = 1;
        e[0x15] = 1;
        open_text_box(p[2] & 0xF, 0xFF, 0);
        p[5]++;
    }
}

#define func_80041AB8 func_8005335C
#define D_80075FD8 D_8007ACD4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_80053398
#define D_80075FD8 D_8007ACE0
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002C9D4(); /* extern */

void func_800533D4(void) {
    func_8002C9D4();
}
