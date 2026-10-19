#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern struct X4_StageObjectRecord* D_8007349C[][2];

void func_8002A33C(void) {
    struct X4_StageObjectRecord* rec;
    u8 t;

    rec = D_8007349C[D_800CCED0.stage][D_800CCED0.substage];
    t = rec->object_type;
    while (t != 0xF) {
        rec->object_type = t & 0xF;
        rec->flags &= 0x70;
        rec++;
        t = rec->object_type;
    }
}
