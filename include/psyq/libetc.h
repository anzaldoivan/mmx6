/* psyq/libetc.h -- prototypes of the LIBETC.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBETC_H
#define PSYQ_LIBETC_H

// LIBETC VSYNC.OBJ+0x0, retail SLUS_013.95 0x80060964
int VSync(int);
// LIBETC INTR.OBJ+0x0, retail SLUS_013.95 0x80060B74
int ResetCallback(void);
// LIBETC INTR.OBJ+0x30, retail SLUS_013.95 0x80060BA4
int InterruptCallback();
// LIBETC INTR.OBJ+0x60, retail SLUS_013.95 0x80060BD4
int DMACallback();
// LIBETC INTR.OBJ+0x90, retail SLUS_013.95 0x80060C04
int VSyncCallback(void (*)(void));
// LIBETC INTR.OBJ+0xc4, retail SLUS_013.95 0x80060C38
int VSyncCallbacks();
// LIBETC INTR.OBJ+0xf4, retail SLUS_013.95 0x80060C68
int StopCallback(void);
// LIBETC INTR.OBJ+0x124, retail SLUS_013.95 0x80060C98
int RestartCallback(void);
// LIBETC INTR.OBJ+0x154, retail SLUS_013.95 0x80060CC8
int CheckCallback(void);
// LIBETC INTR.OBJ+0x164, retail SLUS_013.95 0x80060CD8
int GetIntrMask();
// LIBETC INTR.OBJ+0x17c, retail SLUS_013.95 0x80060CF0
int SetIntrMask();
// LIBETC INTR_VB.OBJ+0x0, retail SLUS_013.95 0x80061234
int startIntrVSync();
// LIBETC INTR_DMA.OBJ+0x0, retail SLUS_013.95 0x80061354
int startIntrDMA();
// LIBETC VMODE.OBJ+0x0, retail SLUS_013.95 0x800615F4
long SetVideoMode(long);
// LIBETC VMODE.OBJ+0x14, retail SLUS_013.95 0x80061608
long GetVideoMode(void);

#endif /* PSYQ_LIBETC_H */
