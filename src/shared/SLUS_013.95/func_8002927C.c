#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_80071E80[])(struct X4_BackgroundObj*);
void func_80028EBC(struct X4_BackgroundObj* arg0);
void func_80029A6C(struct X4_BackgroundObj* arg0);
void func_80029AFC(struct X4_BackgroundObj* arg0);

void func_8002927C(void) {
    struct X4_BackgroundObj* bg = &background_objects[0];
    struct X4_PlayerObj* p;

    if (bg->unk44 != 0) {
        p = &g_Player;
        if (*(s8*)((u8*)p + 0xCC) == 0 &&
            (p->unk2 == 0 || p->nova_strike_active == 0)) {
            D_80071E80[bg->unk4](bg);
            if (p->ride_animation != -2) {
                if (bg->unk34 & 0x10) {
                    func_80029A6C(bg);
                }
                if (bg->unk34 & 1) {
                    func_80029AFC(bg);
                }
            }
            func_80028EBC(bg);
        }
    }
}
