#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0);
M2C_UNK load_player_files(void);
M2C_UNK func_80013DE8();
void pump_file_loads(void);
void read_dat_file(s32 arg0, s32* arg1, u8* arg2);
void silence_sound(u8 arg0, u8 arg1);
void stop_cd_audio(void);
void func_80021400(void);
void func_80025F84(void);
void reset_level(void);
void func_8002C1DC();
void func_8002C2B8();
extern u8 D_800710BC[];
extern s8 D_80097426;

void func_8001D460(void* arg0) {
    set_resolution(0);
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    D_80097426 = 1;
    func_80025F84();
    stop_cd_audio();
    silence_sound(0xFF, 0);
    reset_level();
    func_8002C2B8();
    func_8002C1DC();
    ((void (*)())read_dat_file)(D_800710BC[M2C_FIELD(arg0, s8*, 0xC)],
                                0x801F6000);
    pump_file_loads();
    func_80021400();
    load_player_files();
    func_80013DE8();
    M2C_FIELD(arg0, s16*, 0x4) = 0x960;
    M2C_FIELD(arg0, u8*, 0x1) += 1;
}
