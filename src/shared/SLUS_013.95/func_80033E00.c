#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800122A4();
M2C_UNK func_800139A0(s8);
M2C_UNK func_800139F4(M2C_UNK);
void func_800210E8();
M2C_UNK func_80025FB0();
M2C_UNK func_80026028();
void func_8002ACA8(); /* extern; was M2C_UNK (W15 regate of 2ACA8) */
s8* func_8002C590(void);
struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK clear_object_slot();

extern u16 D_800739DC[][6];
extern struct X4_PlayerObj g_Player;
extern s8 D_80097424;
extern u8 D_800C4560;
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_QuadObj* D_800E4440[];

void func_80033E00(struct X4_PlayerObj* self) {
    s8* p;
    struct X4_QuadObj* q;
    s32 i;

    switch (self->unk6) {
    case 0:
        func_800139F4(0x20);
        self->unk6++;
        func_80026028();
        break;
    case 1:
        if (D_80097424 != 0) {
            func_80026028();
        } else {
            self->unk6++;
        }
        break;
    case 2:
        for (i = 0; i < 10; i++) {
            p = func_8002C590();
            if (p != 0) {
                p[0] = 1;
                p[1] = 2;
                p[2] = i;
            }
        }
        for (i = 0; i < 4; i++) {
            D_800E4440[i] = q = alloc_class6_slot();
            if (q != 0) {
                q->active = 1;
                D_800E4440[i]->id = 0xB;
                *(u8*)&D_800E4440[i]->unk36 = 0xFF;
                if (g_Player.unk2 != 0) {
                    D_800E4440[i]->unk34 = 0x1F;
                } else {
                    D_800E4440[i]->unk34 = 0x7C00;
                }
                D_800E4440[i]->bg_offset = -1;
                D_800E4440[i]->x_pos.u.hi = 0;
                D_800E4440[i]->y_pos.u.hi = 0;
                D_800E4440[i]->on_screen = 1;
                D_800E4440[i]->vertices[0].x.u.hi = D_800739DC[i][0];
                D_800E4440[i]->vertices[0].y.u.hi = D_800739DC[i][1];
                D_800E4440[i]->vertices[1].x.u.hi = D_800739DC[i][2];
                D_800E4440[i]->vertices[1].y.u.hi = D_800739DC[i][3];
                D_800E4440[i]->vertices[2].x.u.hi = D_800739DC[i][2];
                D_800E4440[i]->vertices[2].y.u.hi = D_800739DC[i][3];
                D_800E4440[i]->vertices[3].x.u.hi = D_800739DC[i][4];
                D_800E4440[i]->vertices[3].y.u.hi = D_800739DC[i][5];
            }
        }
        func_800139A0(0x20);
        self->unk6++;
        func_800210E8();
        break;
    case 3:
        if (D_80097424 == 0) {
            self->unk6++;
        }
        func_800210E8();
        D_800C4560 |= 1;
        func_8002ACA8();
        func_80025FB0();
        break;
    case 4: {
        s8* e = (s8*)&g_playthrough_state;
        u8 t = e[0xD1];
        s8 c = e[0xD1];
        if (g_pad1_buttons[2] & 0x1000) {
            if (c >= -15) {
                e[0xD1] = t - 1;
            }
        }
        if (g_pad1_buttons[2] & 0x4000) {
            s8* e = (s8*)&g_playthrough_state;
            if (e[0xD1] < 16) {
                e[0xD1]++;
            }
        }
        if (g_pad1_buttons[2] & 0x8000) {
            s8* e = (s8*)&g_playthrough_state;
            if (e[0xD0] >= -15) {
                e[0xD0]--;
            }
        }
        if (g_pad1_buttons[2] & 0x2000) {
            s8* e = (s8*)&g_playthrough_state;
            if (e[0xD0] < 16) {
                e[0xD0]++;
            }
        }
        if (g_pad1_buttons[2] & 0x40) {
            self->unk6++;
        }
        if (g_pad1_buttons[2] & 0x10) {
            s8* e = (s8*)&g_playthrough_state;
            e[0xD0] = 0;
            e[0xD1] = 0;
        }
        {
            s8* e = (s8*)&g_playthrough_state;
            func_800122A4(e[0xD0], e[0xD1]);
        }
        func_800210E8();
        func_8002ACA8();
        func_80025FB0();
        break;
    }
    case 5:
        if (g_pad1_buttons[0] == 0) {
            self->unk6++;
        }
        func_800210E8();
        func_8002ACA8();
        func_80025FB0();
        break;
    case 6:
        for (i = 0; i < 4; i++) {
            if (D_800E4440[i] != 0) {
                clear_object_slot(D_800E4440[i]);
            }
        }
        {
            s8* e = (s8*)&g_playthrough_state;
            e[1] = 0;
        }
        self->state = 0;
        self->unk5 = 0;
        func_800210E8();
        func_8002ACA8();
        func_80025FB0();
        break;
    }
}
