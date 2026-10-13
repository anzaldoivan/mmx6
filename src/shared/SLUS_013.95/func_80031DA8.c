#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8002E1A0(struct X4_PlayerObj* a, struct X4_PlayerObj* b, s32 mode);
void func_8002F288(struct X4_PlayerObj*);
s32 func_80032208(struct X4_MainObj* self, struct X4_PlayerObj* tgt);
void func_800324C8(struct X4_MainObj* a, struct X4_MainObj* b, u8 flags);
extern s8 D_800950A0[];
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern u8 D_800C4568;
extern struct X4_RideArmorObj D_800CD340;

void func_80031DA8(struct X4_MainObj* arg0) {
    struct X4_PlayerObj* p;
    s16 x;
    s16 y;

    if (arg0->terrain_box != 0 && D_800C4568 == 0) {
        p = &D_800970A0;
        x = p->x_pos.i.hi;
        y = p->y_pos.i.hi;
        if (func_80032208(arg0, p) == 0) {
            if (arg0->unk76 > 0) {
                func_800324C8(arg0, (struct X4_MainObj*)p, arg0->unk72);
            }
            func_8002E1A0((struct X4_PlayerObj*)arg0, p, 0);
            if (p->x_pos.i.hi != x || p->y_pos.i.hi != y) {
                func_8002F288(p);
                if ((p->unk70 & 0xC) != 0xC && (p->unk70 & 3) != 3) {
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
            func_8002E1A0((struct X4_PlayerObj*)arg0, p, 1);
            if (D_800970A0.unk5 == 0x12) {
                do {
                    D_800970A0.x_pos = p->x_pos;
                } while (0);
                do {
                    D_800970A0.y_pos = p->y_pos;
                } while (0);
            }
        }
    }
}
#undef D_800970A0
