#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern u16 D_800F12A8[][2];
extern s8 D_800F1CD0[][5];

void func_800EF064(void* arg0) {
    s8 i;
    s8 t;
    u16 v;

    i = *(s8*)((u8*)arg0 + 2);
    t = D_800F1CD0[D_800CCED0.character_state.bytes[3]][i];
    if (t != -1) {
        v = D_800F12A8[t][0];
        *(u16*)((u8*)arg0 + 0xA) = v;
        *(u16*)((u8*)arg0 + 0xE) =
            D_800F12A8[D_800F1CD0[D_800CCED0.character_state.bytes[3]][i]][1] +
            1;
        if (D_800971F8[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi > 0x400) {
            *(u16*)((u8*)arg0 + 0xA) = v + 0x600;
        }
    }
    ((void (*)())func_8002CB50)(arg0);
    if (D_800F1CD0[D_800CCED0.character_state.bytes[3]]
                  [*(s8*)((u8*)arg0 + 2)] == -1) {
        *(u8*)((u8*)arg0 + 3) = 0;
    }
}
