#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void task_yield(s32);
M2C_UNK end_task_slot(M2C_UNK);
s32 play_sound(s32 a0, s32 a1, void* arg2);
void silence_sound(u8, u8);
void stop_cd_audio(void);
void func_80025F84(void);
void reset_level(void);
void func_8002C2B8();
extern void (*D_800710E8[])(void*);
extern s32 D_80097420;
extern u16 g_pad1_buttons[];
extern M2C_UNK D_800CD3F8;
void func_800139F4(s32);
void func_8001D0E4(void) {
    s32 mask;

    {
        s8* st = (s8*)&D_800CD3F8;
        s8* g = (s8*)&D_80097420;
        st[0xD] = 1;
        g[6] = 0;
        g[8] = 1;
    }
    func_80025F84();
    stop_cd_audio();
    silence_sound(0xFF, 0);
    reset_level();
    func_8002C2B8();
    while (1) {
        {
            void* a = &D_800CD3F8;
            D_800710E8[M2C_FIELD(&D_800CD3F8, s8*, 0)](a);
        }
        if (M2C_FIELD(&D_800CD3F8, s8*, 0xD) == 0) {
            mask = 0x800;
            if (M2C_FIELD(&D_800CD3F8, s8*, 0) != 1) {
                mask = 0x8F0;
            }
            if (g_pad1_buttons[2] & mask) {
                // !FAKE: depin: dropping it breaks the match (74/77)
                register s8* g asm("$2");
                play_sound(0, 0x22, 0);
                M2C_FIELD(&D_800CD3F8, s8*, 0xD) = 1;
                M2C_FIELD(&D_800CD3F8, u8*, 0xE) =
                    M2C_FIELD(&D_800CD3F8, u8*, 0);
                end_task_slot(1);
                g = (s8*)&D_80097420;
                if (g[4] == 0) {
                    ((M2C_UNK(*)())func_800139F4)(8);
                }
                M2C_FIELD(&D_800CD3F8, s8*, 0) = 5;
                M2C_FIELD(&D_800CD3F8, s8*, 1) = 0;
                M2C_FIELD(&D_800CD3F8, s8*, 2) = 0;
                M2C_FIELD(&D_800CD3F8, s8*, 3) = 0;
            }
        }
        task_yield(1);
    }
}
