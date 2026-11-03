#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void check_box_collision(struct X4_PlayerObj* a, struct X4_PlayerObj* b,
                         s32 mode);
void func_8002F288(struct X4_PlayerObj*);
s32 func_80032208(struct X4_MainObj* self, struct X4_PlayerObj* tgt);
void func_800324C8(struct X4_MainObj* a, struct X4_MainObj* b, u8 flags);
extern s8 D_800950A0[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

// 0x80031DA8 collide_solid_object: box-collides the player (mode 0) and the ride armor (mode 1) with the object's terrain box, restoring the old position on blocked moves.
// basis: xref check_box_collision (docs/leads/derived.tsv:14)
// callers: func_80050250, func_800510C4, update_capsule, func_80051890 and 54 overlay object functions (rock_00..rock_32)
void collide_solid_object(struct X4_MainObj* arg0) {
    struct X4_PlayerObj* p;
    s16 x;
    s16 y;

    if (arg0->terrain_box != 0 && D_800C4568 == 0) {
        p = &g_Player;
        x = p->x_pos.i.hi;
        y = p->y_pos.i.hi;
        if (func_80032208(arg0, p) == 0) {
            if (arg0->unk76 > 0) {
                func_800324C8(arg0, (struct X4_MainObj*)p, arg0->unk72);
            }
            check_box_collision((struct X4_PlayerObj*)arg0, p, 0);
            if (p->x_pos.i.hi != x || p->y_pos.i.hi != y) {
                func_8002F288(p);
                if ((p->collision_flags & 0xC) != 0xC &&
                    (p->collision_flags & 3) != 3) {
                    p->unk18.val = p->x_pos.val;
                    p->unk1C.val = p->y_pos.val;
                } else {
                    p->x_pos.i.hi = x;
                    p->y_pos.i.hi = y;
                }
            }
        }
        if (((u32)arg0 < (u32)D_800950A0 ||
             (u32)arg0 >= (u32)(D_800950A0 + 0x1400)) &&
            D_800CD340.active != 0) {
            p = (struct X4_PlayerObj*)&D_800CD340;
            func_80032208(arg0, p);
            if (arg0->unk77 > 0) {
                func_800324C8(arg0, (struct X4_MainObj*)p, arg0->unk73);
            }
            check_box_collision((struct X4_PlayerObj*)arg0, p, 1);
            if (g_Player.action == 0x12) {
                do {
                    g_Player.x_pos = p->x_pos;
                } while (0);
                do {
                    g_Player.y_pos = p->y_pos;
                } while (0);
            }
        }
    }
}
#undef g_Player
