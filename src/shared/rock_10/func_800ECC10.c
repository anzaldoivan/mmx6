/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_43_web_spider.c:web_spider_swing_wait, AGPL-3.0; proven shared with X6 by exact signature 8cebceb7e09c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800ECC10(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        self->unk6 = 0;
    }
}
