#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK animate_object();                    /* extern */
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define EXT84(o) (*(s32*)((u8*)(o) + 0x84))
#define E43C (((s32*)&g_playthrough_state)[0x43C / 4])
#define E90 (((s32*)&g_playthrough_state)[0x90 / 4])
#define X (self->x_pos.u.hi)
#define Y (self->y_pos.u.hi)
#define BG background_objects[0]
#define ECHECK                                                                 \
    {                                                                          \
        s32* e = (s32*)&g_playthrough_state;                                   \
        if (e[0x43C / 4] == 0) {                                               \
            e[0x43C / 4] = e[0x90 / 4];                                        \
        }                                                                      \
    }

void func_80050670(struct X4_MainObj* self, u8* arg1) {
    if (self->animation_step.fields.event < 2) {
        animate_object();
        if (self->animation_step.fields.event == 1) {
            play_sound(0, 0x11, self);
            self->animation_step.fields.event = 0;
        }
    } else {
        arg1[0x10] = 0;
        arg1[0x12] = 0;
        BG.unk26 = X;
        BG.unk24 = X;
        EXT84(self) = 0xA400;
        switch (self->unk2) {
        case 1:
            BG.unk24 = X + 0x50;
            break;
        case 2:
            BG.unk24 = X;
            BG.unk28 = 0xE0;
            BG.unk2A = 0xE0;
            break;
        case 4:
            BG.unk24 = X + 0x20;
            ECHECK;
            break;
        case 5:
            BG.unk26 = 0x1780;
            BG.unk24 = 0x1780;
            BG.unk2A = 0x130;
            BG.unk28 = 0x130;
            EXT84(self) = 0xD400;
            break;
        case 6:
            BG.unk24 = 0x18F0;
            BG.unk2A = 0x130;
            BG.unk28 = 0x140;
            ECHECK;
            break;
        case 7:
            BG.unk26 = 0x3B0;
            BG.unk24 = 0x3D0;
            BG.unk2A = Y - 0xA0;
            BG.unk28 = 0xA40;
            break;
        case 8:
            BG.unk26 = X - 0x10;
            BG.unk24 = X - 0x10;
            BG.unk2A = 0x650;
            break;
        case 9:
            BG.unk24 = 0x970;
            BG.unk2A = 0x9E0;
            BG.unk28 = 0xB00;
            break;
        case 10:
            BG.unk26 = 0x9F0;
            BG.unk24 = 0x9F0;
            BG.unk2A = 0x3B0;
            EXT84(self) = 0x3D800;
            break;
        case 11:
            BG.unk24 = 0x970;
            BG.unk2A = 0x820;
            BG.unk28 = 0x900;
            break;
        case 12:
            BG.unk26 = 0x9F0;
            BG.unk24 = 0x9F0;
            BG.unk2A = 0x870;
            EXT84(self) = 0x3D800;
            break;
        case 13:
            BG.unk26 = X - 0x10;
            BG.unk24 = X + 0x10;
            break;
        case 14:
            BG.unk24 = 0xDB0;
            BG.unk28 = 0x4A0;
            break;
        case 15:
            BG.unk26 = X - 0x10;
            BG.unk24 = X - 0x10;
            BG.unk28 = 0x3B0;
            break;
        case 16:
            BG.unk24 = X + 0x20;
            BG.unk2A = 0x3B0;
            BG.unk28 = 0x3B0;
            ECHECK;
            break;
        case 19:
            BG.unk26 = 0x4F0;
            BG.unk24 = 0x4F0;
            BG.unk2A = 0x450;
            BG.unk28 = 0x4A0;
            break;
        case 20:
            BG.unk24 = 0x690;
            BG.unk2A = 0x470;
            BG.unk28 = 0x4A0;
            ECHECK;
            break;
        case 22:
            BG.unk24 = X + 0x20;
            ECHECK;
            break;
        case 23:
            BG.unk24 = 0x2350;
            BG.unk2A = 0x280;
            BG.unk28 = 0x2B0;
            ECHECK;
            break;
        case 24:
            BG.unk28 = 0x1E0;
            break;
        case 25:
            BG.unk24 = 0x1CC0;
            break;
        case 26:
            BG.unk24 = 0x1FA0;
            BG.unk28 = 0xA0;
            break;
        case 27:
            BG.unk2A = 0x340;
            BG.unk28 = 0x3A0;
            BG.unk24 = BG.unk26 + 0x10;
            ECHECK;
            break;
        case 28:
            BG.unk26 = 0xB40;
            BG.unk24 = 0xB40;
            break;
        case 29:
            BG.unk24 = 0xC90;
            BG.unk28 = 0xE0;
            BG.unk2A = 0xE0;
            break;
        case 30:
            BG.unk26 = X - 0x30;
            BG.unk24 = Y - 0x30;
            break;
        case 31:
            BG.unk24 = X + 0x20;
            BG.unk2A = Y - 0x90;
            break;
        case 33:
            BG.unk24 = X + 0x20;
            break;
        case 36:
            ECHECK;
            break;
        case 37:
            BG.unk26 = 0xB20;
            BG.unk24 = 0xB20;
            EXT84(self) = 0xD400;
            break;
        case 39:
            BG.unk28 = 0;
            BG.unk2A = 0;
            break;
        case 3:
        case 40:
            BG.unk26 = X - 0x30;
            BG.unk24 = X - 0x30;
            BG.unk2A = Y - 0x40;
            BG.unk28 = Y - 0x40;
            EXT84(self) = 0xD400;
            break;
        case 41:
            BG.unk24 = X + 0x20;
            BG.unk2A = Y - 0x70;
            BG.unk28 = Y - 0x70;
            break;
        case 17:
        case 21:
        case 32:
        case 42:
            BG.unk26 = X - 0x10;
            BG.unk24 = X - 0x10;
            break;
        case 43:
            BG.unk24 = X + 0x20;
            BG.unk2A = Y - 0x70;
            BG.unk28 = Y - 0x70;
            break;
        case 44:
            BG.unk26 = X - 0x70;
            BG.unk24 = X - 0x70;
            EXT84(self) = 0x1C400;
            break;
        case 46:
            BG.unk26 = X - 0x30;
            BG.unk24 = X - 0x30;
            EXT84(self) = 0xD400;
            break;
        case 50:
            BG.unk2A = Y - 0xA0;
            BG.unk28 = Y - 0xA0;
            break;
        case 35:
        case 38:
        case 45:
        case 47:
        case 49:
        case 51:
            BG.unk24 = X + 0x20;
            BG.unk2A = Y - 0xA0;
            BG.unk28 = Y - 0xA0;
            break;
        }
        self->action = 3;
    }
    background_objects[0].unk34 &= 0xF;
}

#undef EXT84
#undef E43C
#undef E90
#undef X
#undef Y
#undef BG
#undef ECHECK
