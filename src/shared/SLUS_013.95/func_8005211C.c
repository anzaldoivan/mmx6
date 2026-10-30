#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CA14();
s32 func_8002CAB4(struct X4_BaseObj*);
extern s8 D_8008EAB0;
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_8005211C(void* arg0) {
    u16* r;
    u16 v;

    if (func_8002CAB4(arg0) == 0) {
        r = M2C_FIELD(arg0, u16**, 0x18);
        if (g_Player.x_pos.i.hi <= r[1] && r[0] <= g_Player.x_pos.i.hi &&
            g_Player.y_pos.i.hi <= r[3] && r[2] <= g_Player.y_pos.i.hi) {
            background_objects[0].unk47 = 2;
            v = M2C_FIELD(arg0, u16**, 0x18)[4];
            if (v != 0xFFFF) {
                background_objects[0].unk26 = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[5];
            if (v != 0xFFFF) {
                background_objects[0].unk24 = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[6];
            if (v != 0xFFFF) {
                background_objects[0].unk2A = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[7];
            if (v != 0xFFFF) {
                background_objects[0].unk28 = v;
            }
            if (M2C_FIELD(arg0, s8*, 2) & 0x80) {
                D_8008EAB0 = 1;
                clear_object_slot(arg0, &g_Player);
            }
        }
    } else {
        func_8002CA14(arg0);
    }
}
