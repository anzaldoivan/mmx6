#include "common.h"
#include "mmx6/class4.h"

extern s32 D_800C1220[];

// 0x8002C4C4 alloc_class4_slot: returns a cleared free slot of the class 4 pool D_800C1220.
// basis: code origin table type 0x4 (docs/leads/objects.tsv:342), scan of D_800C1220 for active == 0
// callers: init_capsule and overlay objects (rock_03 func_800EC25C and others)
void* alloc_class4_slot(void) {
    s8* p;
    s8* end;
    s8* q;
    s32 k;

    p = (s8*)D_800C1220;
    end = p + 0x3340;
    if (p < end) {
        do {
            if (*p == 0) {
                q = p;
                k = 0xA3;
                do {
                    *q = 0;
                    k--;
                    q++;
                } while (k != -1);
                ((struct Class4Obj*)p)->attack_box = 0;
                ((struct Class4Obj*)p)->hurt_box = 0;
                ((struct Class4Obj*)p)->terrain_box = 0;
                return p;
            }
            p += 0xA4;
        } while (p < end);
    }
    return 0;
}
