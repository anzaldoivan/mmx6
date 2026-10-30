#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void set_resolution(s32 arg0);
M2C_UNK func_80013DE8();
void func_80017E24(void);
void func_8001D218();
void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
void reset_level(void);
void func_8002C1DC();
void func_8002C2B8();

void func_8001DE10(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 2;
    func_8001D218();
    func_8002C1DC();
    g_playthrough_state.stage = 0xE;
    g_playthrough_state.substage = 0;
    func_80013DE8();
    set_resolution(1);
    func_80017E24();
    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    background_objects[0].unk3 = 1;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 0;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}
