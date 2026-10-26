/* psyq/libgpu.h -- prototypes of the LIBGPU.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBGPU_H
#define PSYQ_LIBGPU_H

struct DISPENV;
struct DRAWENV;
struct DR_AREA;
struct DR_ENV;
struct DR_MODE;
struct DR_OFFSET;
struct RECT;

// LIBGPU SYS.OBJ+0x0, retail SLUS_013.95 0x80065DD4
int ResetGraph(int);
// LIBGPU SYS.OBJ+0x174, retail SLUS_013.95 0x80065F48
int SetGraphDebug(int);
// LIBGPU SYS.OBJ+0x1d0, retail SLUS_013.95 0x80065FA4
int SetGraphQueue();
// LIBGPU SYS.OBJ+0x274, retail SLUS_013.95 0x80066048
int GetGraphDebug(void);
// LIBGPU SYS.OBJ+0x284, retail SLUS_013.95 0x80066058
unsigned long DrawSyncCallback(void (*)(void));
// LIBGPU SYS.OBJ+0x2e4, retail SLUS_013.95 0x800660B8
void SetDispMask(int);
// LIBGPU SYS.OBJ+0x37c, retail SLUS_013.95 0x80066150
int DrawSync(int);
// LIBGPU SYS.OBJ+0x500, retail SLUS_013.95 0x800662D4
int ClearImage(struct RECT *, unsigned char, unsigned char, unsigned char);
// LIBGPU SYS.OBJ+0x590, retail SLUS_013.95 0x80066364
int ClearImage2(struct RECT *, unsigned char, unsigned char, unsigned char);
// LIBGPU SYS.OBJ+0x628, retail SLUS_013.95 0x800663FC
int LoadImage(struct RECT *, unsigned long *);
// LIBGPU SYS.OBJ+0x688, retail SLUS_013.95 0x8006645C
int StoreImage(struct RECT *, unsigned long *);
// LIBGPU SYS.OBJ+0x6e8, retail SLUS_013.95 0x800664BC
int MoveImage(struct RECT *, int, int);
// LIBGPU SYS.OBJ+0x7a0, retail SLUS_013.95 0x80066574
unsigned long *ClearOTag(unsigned long *, int);
// LIBGPU SYS.OBJ+0x868, retail SLUS_013.95 0x8006663C
unsigned long *ClearOTagR(unsigned long *, int);
// LIBGPU SYS.OBJ+0x914, retail SLUS_013.95 0x800666E8
void DrawPrim(void *);
// LIBGPU SYS.OBJ+0x970, retail SLUS_013.95 0x80066744
void DrawOTag(unsigned long *);
// LIBGPU SYS.OBJ+0x9e0, retail SLUS_013.95 0x800667B4
struct DRAWENV *PutDrawEnv(struct DRAWENV *);
// LIBGPU SYS.OBJ+0xaa0, retail SLUS_013.95 0x80066874
void DrawOTagEnv(unsigned long *, struct DRAWENV *);
// LIBGPU SYS.OBJ+0xb78, retail SLUS_013.95 0x8006694C
struct DRAWENV *GetDrawEnv(struct DRAWENV *);
// LIBGPU SYS.OBJ+0xbac, retail SLUS_013.95 0x80066980
struct DISPENV *PutDispEnv(struct DISPENV *);
// LIBGPU SYS.OBJ+0x10a4, retail SLUS_013.95 0x80066E78
struct DISPENV *GetDispEnv(struct DISPENV *);
// LIBGPU SYS.OBJ+0x10d8, retail SLUS_013.95 0x80066EAC
int GetODE(void);
// LIBGPU SYS.OBJ+0x1108, retail SLUS_013.95 0x80066EDC
void SetDrawArea(struct DR_AREA *, struct RECT *);
// LIBGPU SYS.OBJ+0x1188, retail SLUS_013.95 0x80066F5C
void SetDrawOffset(struct DR_OFFSET *, unsigned short *);
// LIBGPU SYS.OBJ+0x11c8, retail SLUS_013.95 0x80066F9C
void SetDrawEnv(struct DR_ENV *, struct DRAWENV *);
// LIBGPU SYS.OBJ+0x2a98, retail SLUS_013.95 0x8006886C
int LoadImage2(struct RECT *, unsigned long *);
// LIBGPU SYS.OBJ+0x2b84, retail SLUS_013.95 0x80068958
int StoreImage2(struct RECT *, unsigned long *);
// LIBGPU SYS.OBJ+0x2c70, retail SLUS_013.95 0x80068A44
int MoveImage2(struct RECT *, int, int);
// LIBGPU SYS.OBJ+0x2db4, retail SLUS_013.95 0x80068B88
int DrawOTag2(unsigned long *);
// LIBGPU SYS.OBJ+0x2eb0, retail SLUS_013.95 0x80068C84
int _GPU_ResetCallback();
// LIBGPU E03.OBJ+0x0, retail SLUS_013.95 0x80068CD4
struct DRAWENV *SetDefDrawEnv(struct DRAWENV *, int, int, int, int);
// LIBGPU E04.OBJ+0x0, retail SLUS_013.95 0x80068D94
struct DISPENV *SetDefDispEnv(struct DISPENV *, int, int, int, int);
// LIBGPU P00.OBJ+0x0, retail SLUS_013.95 0x80068DD4
unsigned short GetTPage(int, int, int, int);
// LIBGPU P41.OBJ+0x0, retail SLUS_013.95 0x80068E14
void SetDrawMode(struct DR_MODE *, int, int, int, struct RECT *);

#endif /* PSYQ_LIBGPU_H */
