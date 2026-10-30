#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800139F4(s32);
s32 play_sound(s32 a0, s32 a1, void* arg2);
void stop_cd_audio(void);
void func_8001CD5C(struct X4_EngineObj*);
void func_8001CE68(struct X4_EngineObj*);
extern s8 D_80097424;
extern u16 g_pad1_buttons[];

void func_8001CF78(struct X4_EngineObj* arg0) {
    if (D_80097424 == 0) {
        if (g_pad1_buttons[2] & 0x1000) {
            play_sound(0, 0xC, 0);
            if (arg0->unk2 == 0) {
                arg0->unk2 = 2;
            } else {
                arg0->unk2--;
            }
        }
        if (g_pad1_buttons[2] & 0x4000) {
            play_sound(0, 0xC, 0);
            if (arg0->unk2 == 2) {
                arg0->unk2 = 0;
            } else {
                arg0->unk2++;
            }
        }
        func_8001CD5C(arg0);
        func_8001CE68(arg0);
        if (g_pad1_buttons[2] & 0x840) {
            play_sound(0, 0x22, 0);
            func_800139F4(8);
            stop_cd_audio();
            {
                // !FAKE: depin: dropping it breaks the match (88/91)
                register s32 t asm("$3") = (u8)arg0->unk1 + 1;
                arg0->unk1 = t;
            }
        }
        if (g_pad1_buttons[2] == 0) {
            if (++arg0->unk4 > 0x4650) {
                stop_cd_audio();
                func_800139F4(8);
                arg0->unk4 = 0;
                {
                    s32 t = (u8)arg0->unk1 + 2;
                    arg0->unk1 = t;
                }
            }
        } else {
            arg0->unk4 = 0;
        }
    }
}
