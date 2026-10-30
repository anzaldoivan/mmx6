#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);
void func_8003B954(struct X4_PlayerObj* self);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CDF0();
M2C_UNK func_8003D10C(void*);
void func_8003F000(void* arg0);
M2C_UNK func_8003F3DC(void*);
extern struct X4_EngineObj g_playthrough_state;

void func_8003B870(struct X4_PlayerObj* self) {
    ((void (*)())func_8003CDF0)();
    ((void (*)(void*))func_8003F3DC)(self);
    g_playthrough_state.gameplay_locked = 1;
    if (g_playthrough_state.unkF & 0x10) {
        func_8003D10C(self);
        func_8003F000(self);
        if (self->unk2 == 0) {
            play_bgm_xa_track(4, 0x7F);
        } else {
            play_bgm_xa_track(5, 0x7F);
            self->weapon = 0;
        }
        self->unk5 = 0x19;
        self->unk6 = 0;
        return;
    }
    if (g_playthrough_state.unkF & 0x40) {
        self->state = 3;
        self->unk5 = 0;
        self->unk6 = 0;
        return;
    }
    func_8003BA04(self, 3);
    func_8003F000(self);
    if (self->unk2 != 0) {
        self->weapon = 0;
    }
    func_8003B954(self);
}
