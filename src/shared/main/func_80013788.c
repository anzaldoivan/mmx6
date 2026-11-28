#include "common.h"
#include "mmx6/x4.h"

void task_yield(s32);
extern u16 g_screen_width;
extern struct X4_DrawInfo* g_cur_draw_info;
extern struct X4_Main70Ext D_800C885C;
extern s32 D_80090C88;
#define D_80090C88 (*(struct X4_Main70Ext*)&D_80090C88)
extern u8 D_800C4838[];
extern u8 D_8008EAD0[];
extern u8 D_800CF968[];
extern u8 D_800CF978[];

#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) (((X4_P_TAG*)(p))->addr)
#define FRAME (*(s32*)SP(0))
#define PB(p, o) (*(u8*)((p) + (o)))
#define PH(p, o) (*(s16*)((p) + (o)))
#define PW(p, o) (*(u32*)((p) + (o)))

#define F2_STATE D_80090C88.alarm_timer
#define F2_LVL f->flash_timer
#define F2_CNT (*(s8*)&f->unk84)
#define F2_SPD (*(s8*)&f->unk85)

void SetDispMask(int);
#define M2C_UNK s32
M2C_UNK end_task_slot(M2C_UNK arg0);
void func_800133A0(void);
void func_80013788(void) {
    u8* tile;
    struct X4_FixedPointPosition* mode;
    s32 i;
    u32* ot;
    struct MainBssState* e;
    u8 c;
    struct X4_Main70Ext* f;

    F2_STATE = 0;
    *(s8*)&D_80090C88.unk84 = 0;
    if (D_80097420.transition.fade_amount > 0) {
        D_80090C88.flash_timer = 0xFF;
    } else {
        D_80090C88.flash_timer = 0;
    }
    for (;;) {
        task_yield(1);
        f = &D_80090C88;
        c = (u16)F2_LVL >> 4;
        i = FRAME;
        tile = D_8008EAD0 + i * 16;
        PB(tile, 3) = 3;
        PB(tile, 7) = 0x62;
        mode = (struct X4_FixedPointPosition*)(D_800CF978 + i * 8);
        PH(tile, 8) = 0;
        PH(tile, 0xA) = 0;
        PH(tile, 0xC) = g_screen_width;
        PH(tile, 0xE) = 0xF0;
        ((u8*)mode)[3] = 1;
        e = &D_80097420;
        PB(tile, 4) = c;
        PB(tile, 5) = c;
        PB(tile, 6) = c;
        ot = &g_cur_draw_info->ordering_table.unk3;
        mode->y = 0xE1000025;
        SETADDR(mode, tile);
        SETADDR(tile, GETADDR(ot));
        SETADDR(ot, mode);
        if (F2_STATE == 0) {
            if (e->transition.fade_amount > 0) {
                F2_LVL -= F2_SPD;
                if (F2_LVL <= 0) {
                    F2_LVL = 0;
                    F2_STATE++;
                }
            } else if (e->transition.fade_amount < 0) {
                F2_LVL += F2_SPD;
                if (F2_LVL >= 0x1000) {
                    F2_LVL = 0xFFF;
                    F2_STATE++;
                }
            }
        } else if (e->transition.fade_amount > 0) {
            e->transition.fade_amount = 0;
            ((s32(*)())func_800133A0)();
        } else {
            e->transition.fade_amount = 0;
            F2_STATE--;
        }
    }
}
#undef D_80090C88
