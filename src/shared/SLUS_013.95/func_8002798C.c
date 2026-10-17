#include "common.h"
#include "mmx6/x4.h"

extern u8* D_800762E0[][2];
extern u16 D_8008EC10;
extern struct X4_EngineObj D_800CCED0;
extern u8* D_800EA514[];

void func_800268B0(s32 arg0);

#define SCRATCH_04 (*(u8**)0x1F800004)

void func_8002798C(void) {
    u8* src;
    u8* dst;
    u32 i;

    if (D_800CCED0.stage == 0xB) {
        src = D_800EA514[D_800CCED0.checkpoint];
    } else {
        src = D_800762E0[D_800CCED0.stage][D_800CCED0.substage];
    }
    i = 0;
    dst = SCRATCH_04;
    if (D_8008EC10 * 3 != 0) {
        do {
            *dst = *src;
            src++;
            i++;
            dst++;
        } while (i < (u32)(D_8008EC10 * 3));
    }
    func_800268B0(-1);
}
