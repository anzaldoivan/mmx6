#include "common.h"
#include "mmx6/x4.h"

void task_yield(s32);
extern u16 g_screen_width;
extern struct X4_DrawInfo* g_cur_draw_info;
extern struct X4_Main70Ext D_800C885C;
extern s32 D_80090C88;
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

#define F1_STATE D_800C885C.alarm_timer
#define F1_LVL f->flash_timer
#define F1_CNT (*(s8*)&f->unk84)
#define F1_SPD (*(s8*)&f->unk85)

void SetDispMask(int);
#define M2C_UNK s32
M2C_UNK end_task_slot(M2C_UNK arg0);
void func_800133A0(void);
void func_80013530(void) {
    u8* tile;
    struct X4_FixedPointPosition* mode;
    s32 i;
    u32* ot;
    struct MainBssState* e;
    u8 c;
    struct X4_Main70Ext* f;

    F1_STATE = 0;
    *(s8*)&D_800C885C.unk84 = 0;
    if (D_80097420.transition.active > 0) {
        D_800C885C.flash_timer = 0xFF;
    } else {
        D_800C885C.flash_timer = 0;
    }
    for (;;) {
        task_yield(1);
        i = FRAME;
        tile = D_800C4838 + i * 16;
        PB(tile, 3) = 3;
        PB(tile, 7) = 0x62;
        mode = (struct X4_FixedPointPosition*)(D_800CF968 + i * 8);
        PH(tile, 8) = 0;
        PH(tile, 0xA) = 0;
        PH(tile, 0xC) = g_screen_width;
        ((u8*)mode)[3] = 1;
        f = &D_800C885C;
        c = F1_LVL;
        e = &D_80097420;
        PH(tile, 0xE) = 0xF0;
        PB(tile, 4) = c;
        PB(tile, 5) = c;
        PB(tile, 6) = c;
        ot = &g_cur_draw_info->ordering_table.fade;
        mode->y = 0xE1000045;
        SETADDR(mode, tile);
        SETADDR(tile, GETADDR(ot));
        SETADDR(ot, mode);
        if (F1_STATE == 0) {
            if (e->transition.active > 0) {
                F1_LVL -= F1_SPD;
                if (F1_LVL <= 0) {
                    F1_LVL = 0;
                    F1_SPD = 2;
                    F1_STATE++;
                }
                if (F1_CNT == 2) {
                    ((s32(*)())SetDispMask)(1);
                }
                F1_CNT++;
            } else {
                F1_LVL += F1_SPD;
                if (F1_LVL >= 0x100) {
                    F1_LVL = 0xFF;
                    F1_SPD = 2;
                    F1_STATE++;
                }
            }
        } else if (F1_SPD == 0) {
            if (e->transition.active < 0) {
                ((s32(*)())SetDispMask)(0);
            }
            e->transition.active = 0;
            ((s32(*)())func_800133A0)();
            ((void (*)())end_task_slot)(3);
        } else {
            F1_SPD--;
        }
    }
}
