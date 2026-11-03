#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 func_80039C40(void*);
M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK set_pose_size();
void func_8003CD00(void* arg0);
M2C_UNK func_801ECD54(void*, M2C_UNK);

void func_801EC68C(void* arg0) {
    set_pose_size(arg0);
    if (M2C_FIELD(arg0, s8*, 0x6) == 0) {
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    } else {
        animate_object(arg0);
        func_801ECD54(arg0, 0x25);
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        if (func_80039C40(arg0) != 0) {
            return;
        }
        M2C_FIELD(arg0, u8*, 0x8E) = 1;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        ((void (*)())player_set_animation_frame)(arg0, 0x51, 2);
        M2C_FIELD(arg0, u8*, 0x5) = 0x1A;
        M2C_FIELD(arg0, u8*, 0x6) = 1;
    }
    func_8003CD00(arg0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
s32 get_tile_attr_above(void*);
M2C_UNK start_jump(void*);
M2C_UNK func_801ECD54(void*, M2C_UNK);

#define U16(o) (*(u16*)(p + (o)))

void func_801EC76C(s8* p) {
    s32 v;

    if (p[6] == 0) {
        p[6]++;
    } else {
        animate_object(p);
        func_801ECD54(p, (s8)((p[0x45] & 0x7F) + 0x26));
    }
    if (U16(0x80) & 2) {
        p[0x15] = 0;
    }
    if (U16(0x80) & 1) {
        p[0x15] = 0x40;
    }
    if (p[0xD3] == 0) {
        p[0x8E] = 0;
        if (U16(0x80) & 0x80) {
            start_jump(p);
            return;
        }
        p[0x8E] = 1;
    }
    if (p[0x46] == 0) {
        p[0x8E] = 0;
        v = get_tile_attr_above(p);
        if (v == 0x2E) {
            v = 0x1B;
        } else {
            v = 0x1C;
        }
        p[5] = v;
        p[6] = 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_clear_dash();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
M2C_UNK func_801EC95C(void*);
M2C_UNK func_801ECD3C(void*);
M2C_UNK func_801ECD90(void*, M2C_UNK);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 check_shoenzan_input(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (!(F_U8(arg0, 0xC9) & 4)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x7C) & 4)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x80) & 0x10)) {
        return 0;
    }
    F_U8(arg0, 0x8E) = 1;
    player_set_animation(arg0, 0x5A);
    func_801ECD90(arg0, 0x1A);
    func_801ECD90(arg0, 0x22);
    play_sound(1, 7, arg0);
    play_sound(1, 0x16, arg0);
    play_sound_unless_low_health(arg0, 5);
    player_clear_dash(arg0);
    F_U8(arg0, 0x5) = 0x37;
    F_U8(arg0, 0x6) = 0;
    func_801ECD3C(arg0);
    func_801EC95C(arg0);
    return 1;
}

#undef F_S8
#undef F_U8
#undef F_U16

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK end_dash(s32);
void func_801ECE60(void* arg0);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK func_801EC95C(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        F_U8(arg0, 0x8E) = 0;
        ((void (*)())end_dash)();
        return;
    }
    if (F_S8(arg0, 0x6) == 0) {
        F_U8(arg0, 0x6) = F_U8(arg0, 0x6) + 1;
    } else {
        animate_object(arg0);
    }
    func_801ECE60(arg0);
}

#undef F_S8
#undef F_U8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK player_set_animation(void*, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void update_zero_stand_animation(s8* p) {
    if ((u8)p[0x17] == 6) {
        u8* g = (u8*)&g_playthrough_state;
        if (p[0x5C] >= (s8)((s8)(g - -p[2])[0x5B] / 3)) {
            player_set_animation(p, 5);
            return;
        }
    }
    animate_object(p);
}
