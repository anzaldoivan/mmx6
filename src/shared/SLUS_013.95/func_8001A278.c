#include "common.h"
#include "mmx6/x4.h"

extern struct X4_MiscObj g_displayed_sprites[];

void func_800232D4(void*);
void func_800239CC(void*);

void func_8001A278(void) {
    struct X4_MiscObj* p;

    for (p = g_displayed_sprites; p < g_displayed_sprites + 0x60; p++) {
        if (p->on_screen != 0 && p->id == 0x16) {
            if (p->on_screen == 1) {
                func_800232D4(p);
            }
            if (p->on_screen == 2) {
                func_800239CC(p);
            }
        }
    }
}
