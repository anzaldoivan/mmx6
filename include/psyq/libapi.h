/* psyq/libapi.h -- prototypes of the LIBAPI.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBAPI_H
#define PSYQ_LIBAPI_H

struct DIRENTRY;

// LIBAPI C57.OBJ+0x0, retail SLUS_013.95 0x80069DB4
void InitHeap(unsigned long *, unsigned long);
// LIBAPI C68.OBJ+0x0, retail SLUS_013.95 0x80069DC4
void FlushCache(void);
// LIBAPI C73.OBJ+0x0, retail SLUS_013.95 0x80069DD4
int GPU_cw();
// LIBAPI C114.OBJ+0x8, retail SLUS_013.95 0x80069DEC
void _96_remove(void);
// LIBAPI A07.OBJ+0x0, retail SLUS_013.95 0x80069E04
void DeliverEvent(unsigned long, unsigned long);
// LIBAPI A08.OBJ+0x0, retail SLUS_013.95 0x80069E14
long OpenEvent(unsigned long, long, long, long (*)());
// LIBAPI A09.OBJ+0x0, retail SLUS_013.95 0x80069E24
long CloseEvent(long);
// LIBAPI A10.OBJ+0x0, retail SLUS_013.95 0x80069E34
long WaitEvent(long);
// LIBAPI A11.OBJ+0x0, retail SLUS_013.95 0x80069E44
long TestEvent(long);
// LIBAPI A12.OBJ+0x0, retail SLUS_013.95 0x80069E54
long EnableEvent(long);
// LIBAPI A13.OBJ+0x0, retail SLUS_013.95 0x80069E64
long DisableEvent(long);
// LIBAPI A14.OBJ+0x0, retail SLUS_013.95 0x80069E74
long OpenTh(long (*)(), unsigned long, unsigned long);
// LIBAPI A15.OBJ+0x0, retail SLUS_013.95 0x80069E84
int CloseTh(long);
// LIBAPI A16.OBJ+0x0, retail SLUS_013.95 0x80069E94
int ChangeTh(long);
// LIBAPI A23.OBJ+0x0, retail SLUS_013.95 0x80069EA4
void ReturnFromException(void);
// LIBAPI A24.OBJ+0x0, retail SLUS_013.95 0x80069EB4
int ResetEntryInt();
// LIBAPI A25.OBJ+0x0, retail SLUS_013.95 0x80069EC4
int HookEntryInt();
// LIBAPI A36.OBJ+0x0, retail SLUS_013.95 0x80069ED4
int EnterCriticalSection(void);
// LIBAPI A37.OBJ+0x0, retail SLUS_013.95 0x80069EE4
void ExitCriticalSection(void);
// LIBAPI A50.OBJ+0x0, retail SLUS_013.95 0x80069EF4
long open(char *, unsigned long);
// LIBAPI A52.OBJ+0x0, retail SLUS_013.95 0x80069F04
long read(long, void *, long);
// LIBAPI A53.OBJ+0x0, retail SLUS_013.95 0x80069F14
long write(long, void *, long);
// LIBAPI A54.OBJ+0x0, retail SLUS_013.95 0x80069F24
long close(long);
// LIBAPI A65.OBJ+0x0, retail SLUS_013.95 0x80069F34
long format(char *);
// LIBAPI A67.OBJ+0x0, retail SLUS_013.95 0x80069F44
struct DIRENTRY *nextfile(struct DIRENTRY *);
// LIBAPI A91.OBJ+0x0, retail SLUS_013.95 0x80069F54
void ChangeClearPAD(long);
// LIBAPI L10.OBJ+0x0, retail SLUS_013.95 0x80069F64
int ChangeClearRCnt();
// LIBAPI COUNTER.OBJ+0x0, retail SLUS_013.95 0x80069F74
long SetRCnt(unsigned long, unsigned short, long);
// LIBAPI COUNTER.OBJ+0x9c, retail SLUS_013.95 0x8006A010
long GetRCnt(unsigned long);
// LIBAPI COUNTER.OBJ+0xd4, retail SLUS_013.95 0x8006A048
long StartRCnt(unsigned long);
// LIBAPI COUNTER.OBJ+0x104, retail SLUS_013.95 0x8006A078
long StopRCnt(unsigned long);
// LIBAPI COUNTER.OBJ+0x138, retail SLUS_013.95 0x8006A0AC
long ResetRCnt(unsigned long);
// LIBAPI FIRST.OBJ+0x0, retail SLUS_013.95 0x8006A0E4
struct DIRENTRY *firstfile(char *, struct DIRENTRY *);
// LIBAPI A66.OBJ+0x0, retail SLUS_013.95 0x8006A384
int firstfile2();
// LIBAPI PAD.OBJ+0x0, retail SLUS_013.95 0x8006A394
int SetInitPadFlag();
// LIBAPI PAD.OBJ+0xc, retail SLUS_013.95 0x8006A3A0
int ReadInitPadFlag();
// LIBAPI PAD.OBJ+0x1c, retail SLUS_013.95 0x8006A3B0
int PAD_init();
// LIBAPI PAD.OBJ+0xac, retail SLUS_013.95 0x8006A440
long InitPAD(char *, long, char *, long);
// LIBAPI PAD.OBJ+0x13c, retail SLUS_013.95 0x8006A4D0
long StartPAD(void);
// LIBAPI A18.OBJ+0x0, retail SLUS_013.95 0x8006A624
int InitPAD2();
// LIBAPI A19.OBJ+0x0, retail SLUS_013.95 0x8006A634
int StartPAD2();
// LIBAPI A21.OBJ+0x0, retail SLUS_013.95 0x8006A644
int PAD_init2();
// LIBAPI L02.OBJ+0x0, retail SLUS_013.95 0x8006A654
int SysEnqIntRP();
// LIBAPI L03.OBJ+0x0, retail SLUS_013.95 0x8006A664
int SysDeqIntRP();
// LIBAPI PATCH.OBJ+0x0, retail SLUS_013.95 0x8006A674
void EnablePAD(void);
// LIBAPI PATCH.OBJ+0x14, retail SLUS_013.95 0x8006A688
void DisablePAD(void);
// LIBAPI PATCH.OBJ+0x28, retail SLUS_013.95 0x8006A69C
int _patch_pad();
// LIBAPI CHCLRPAD.OBJ+0x0, retail SLUS_013.95 0x8006A714
int _remove_ChgclrPAD();

#endif /* PSYQ_LIBAPI_H */
