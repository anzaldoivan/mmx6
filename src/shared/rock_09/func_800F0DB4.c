// rolefeed (3.1 T4): func_800F0DB4 of src/rock_09/E9860.c

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F6924[];

void func_800F0DB4(void* arg0) {
    u32 r;
    u8 i;
    s32 v;
    u8* e;

    r = random_byte() & 0xF;
    e = (u8*)&g_playthrough_state;
    M2C_FIELD(arg0, u8*, 0x87) = 0;
    if (M2C_FIELD(e, u8*, 0x68) == 2) {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 1;
            }
        } else if (r < 8) {
            M2C_FIELD(arg0, u8*, 0x86) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x86) = M2C_FIELD(e, u8*, 0x68);
        }
    } else if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C) ||
               r < 8) {
        M2C_FIELD(arg0, u8*, 0x86) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x86) = 1;
    }
    i = M2C_FIELD(arg0, u8*, 0x87)++;
    v = D_800F6924[i + M2C_FIELD(arg0, u8*, 0x86) * 6];
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 5) = v;
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}
