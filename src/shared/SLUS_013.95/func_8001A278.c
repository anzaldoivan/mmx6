#include "common.h"
#include "mmx6/x4.h"

extern struct X4_MiscObj D_800CD410[];

void func_800232D4(void*);
void func_800239CC(void*);

void func_8001A278(void) {
    struct X4_MiscObj* p;

    for (p = D_800CD410; p < D_800CD410 + 0x60; p++) {
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
