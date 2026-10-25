#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8003C4EC(struct X4_PlayerObj* self);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
M2C_UNK func_8003DF58(void* self);
M2C_UNK func_8003F480();

M2C_UNK func_8003F3DC(void* arg0) {
    s8* p = arg0;
    s8 mode;

    if (p[2] == 0) {
        func_8003F480();
        func_8003DF58(p);
        func_8003C4EC((struct X4_PlayerObj*)p);
        mode = p[0x93];
        if (mode == 1) {
            player_spawn_visual(1, 0x1B, 0, 0);
        } else if (mode == 6) {
            player_spawn_visual(1, 0x1B, 0xA, 0);
        } else if (mode == 8) {
            player_spawn_visual(1, 0x1B, 0xC, 0);
        }
    }
}
