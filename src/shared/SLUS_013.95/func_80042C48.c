#include "common.h"
#include "mmx6/x4.h"

extern struct X4_StageObjectRecord* D_8007349C[][2];
extern struct X4_EngineObj D_800CCED0;

s32 func_80042C48(struct X4_BaseObj* self) {
    struct X4_StageObjectRecord* rec;
    u16 i;

    rec = D_8007349C[D_800CCED0.stage][D_800CCED0.substage];
    i = 0;
    while (rec->object_type != 0xF) {
        if (rec->id == 0xF) {
            if (self->backref == rec) {
                return i;
            }
            i++;
            if (i >= 0x100) {
                return 0;
            }
        }
        rec++;
    }
    return 0;
}
