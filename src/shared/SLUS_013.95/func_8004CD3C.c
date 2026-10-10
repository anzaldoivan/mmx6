#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D2D4();
void func_8004D074(struct X4_QuadObj* arg0);
extern u16 D_80078414[];
extern u8 D_80078460[];

void func_8004CD3C(struct X4_QuadObj* arg0) {
    u16* p;
    s32 n;
    u8* t;

    switch (arg0->unk5) {
    case 0:
        t = D_80078460;
        arg0->unk5 = 1;
        p = &D_80078414[t[func_8002D2D4() & 0xF] * 8];
        arg0->vertices[0].x.u.hi = *p++;
        arg0->vertices[0].y.u.hi = *p++;
        arg0->vertices[1].x.u.hi = *p++;
        arg0->vertices[1].y.u.hi = *p++;
        arg0->vertices[2].x.u.hi = *p++;
        arg0->vertices[2].y.u.hi = *p++;
        arg0->vertices[3].x.u.hi = *p++;
        arg0->vertices[3].y.u.hi = *p++;
        n = 1;
        if (func_8002D2D4() & 1) {
            n = 2;
        }
        if (func_8002D2D4() & 1) {
            arg0->x_pos.i.hi = -0xB0;
            arg0->ext.ready_line.x_vel.val = n * 0x180000;
            arg0->ext.ready_line.y_vel.val = 0;
            arg0->ext.ready_line.x_accel.val = 0;
            arg0->ext.ready_line.y_accel.val = 0;
            arg0->runtime.legacy.unk48 = 0;
        } else {
            arg0->x_pos.i.hi = 0x1F0;
            arg0->ext.ready_line.x_vel.val = -(n * 0x180000);
            arg0->ext.ready_line.y_vel.val = 0;
            arg0->ext.ready_line.x_accel.val = 0;
            arg0->ext.ready_line.y_accel.val = 0;
            arg0->runtime.legacy.unk48 = 1;
        }
        arg0->y_pos.i.hi = (func_8002D2D4() & 7) * 4 + 0x68;
        arg0->runtime.legacy.unk52 = arg0->unk7 << 3;
        break;
    case 1:
        if (*(u16*)&arg0->runtime.legacy.unk52 != 0) {
            (*(u16*)&arg0->runtime.legacy.unk52)--;
            break;
        }
        if (arg0->runtime.legacy.unk48 == 0) {
            if (arg0->x_pos.i.hi >= 0x140) {
                goto set2;
            }
            goto call;
        }
        if (arg0->x_pos.i.hi < -0xB0) {
        set2:
            arg0->unk5 = 2;
            break;
        }
    call:
        func_8004D074(arg0);
        break;
    case 2:
        ((u8*)arg0->link.owner)[0x14]--;
        arg0->state = 2;
        arg0->unk5 = 0;
        break;
    }
}
