/* psyq/libcd.h -- prototypes of the LIBCD.LIB functions the retail main links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBCD_H
#define PSYQ_LIBCD_H

struct CdlFILE;
struct CdlLOC;

// LIBCD CDROM.OBJ+0x0, retail main 0x80061624
void StSetRing(unsigned long *, unsigned long);
// LIBCD EVENT.OBJ+0x0, retail main 0x80061654
int CdInit(void);
// LIBCD ISO9660.OBJ+0x0, retail main 0x80061824
struct CdlFILE *CdSearchFile(struct CdlFILE *, char *);
// 0x80061B1C CD_newmedia: rereads the disc volume descriptor and root directory after a media change.
// basis: string strings.tsv:26:main:0x800119FC
// str 0x800119FC "CD_newmedia: Read error in cd_read(PVD)\n" = "debug print when the volume descriptor read fails"
// static in the vendor object: no prototype, no caller in C
// 0x80061E84 CD_cachefile: loads one directory's file list into the CD file cache.
// basis: string strings.tsv:33:main:0x80011ADC
// str 0x80011ADC "CD_cachefile: dir not found\n" = "debug print when the directory is missing"
// static in the vendor object: no prototype, no caller in C
// LIBCD CDREAD2.OBJ+0x0, retail main 0x80062194
int CdRead2(long);
// LIBCD C_002.OBJ+0x0, retail main 0x80062244
void StClearRing(void);
// LIBCD C_003.OBJ+0x0, retail main 0x800622A4
void StUnSetRing(void);
// LIBCD C_004.OBJ+0x0, retail main 0x80062324
int data_ready_callback();
// LIBCD C_004.OBJ+0x8c, retail main 0x800623B0
int StGetBackloc(struct CdlLOC *);
// LIBCD C_005.OBJ+0x0, retail main 0x80062414
void StSetStream(unsigned long, unsigned long, unsigned long, void (*)(), void (*)());
// LIBCD C_007.OBJ+0x0, retail main 0x800624A4
unsigned long StFreeRing(unsigned long *);
// LIBCD C_008.OBJ+0x0, retail main 0x80062554
int init_ring_status();
// LIBCD C_009.OBJ+0x0, retail main 0x80062594
unsigned long StGetNext(unsigned long **, unsigned long **);
// LIBCD C_010.OBJ+0x0, retail main 0x80062654
void StSetMask(unsigned long, unsigned long, unsigned long);
// LIBCD C_011.OBJ+0x0, retail main 0x80062674
void StCdInterrupt(void);
// LIBCD BIOS_1.OBJ+0x564, retail main 0x800636C8
int CD_sync();
// LIBCD BIOS_1.OBJ+0x7e4, retail main 0x80063948
int CD_ready();
// LIBCD BIOS_1.OBJ+0xaac, retail main 0x80063C10
int CD_cw();
// LIBCD BIOS_1.OBJ+0xeb8, retail main 0x8006401C
int CD_vol();
// LIBCD BIOS_1.OBJ+0xf40, retail main 0x800640A4
int CD_flush();
// LIBCD BIOS_1.OBJ+0x1014, retail main 0x80064178
int CD_initvol();
// LIBCD BIOS_1.OBJ+0x1104, retail main 0x80064268
int CD_initintr();
// LIBCD BIOS_1.OBJ+0x1150, retail main 0x800642B4
int CD_init();
// LIBCD BIOS_1.OBJ+0x1330, retail main 0x80064494
int CD_datasync();
// LIBCD BIOS_1.OBJ+0x1498, retail main 0x800645FC
int CD_set_test_parmnum();
// LIBCD S_007.OBJ+0x0, retail main 0x80064804
int CdReset(int);
// LIBCD S_016.OBJ+0x0, retail main 0x800648D4
int CdControl(unsigned char, unsigned char *, unsigned char *);
// LIBCD S_016.OBJ+0x13c, retail main 0x80064A10
int CdControlF(unsigned char, unsigned char *);
// LIBCD S_016.OBJ+0x270, retail main 0x80064B44
int CdControlB(unsigned char, unsigned char *, unsigned char *);
// LIBCD BIOS_2.OBJ+0x0, retail main 0x80064CD4
int CD_getsector();
// LIBCD CDR_1.OBJ+0x560, retail main 0x80065364
void CdReadBreak(void);
// LIBCD CDR_1.OBJ+0x700, retail main 0x80065504
int CdRead(int, unsigned long *, int);
// LIBCD CDR_1.OBJ+0x89c, retail main 0x800656A0
int CdReadSync(int, unsigned char *);
// LIBCD S_006.OBJ+0x0, retail main 0x800657C4
struct CdlLOC *CdLastPos(void);
// LIBCD BIOS_3.OBJ+0x0, retail main 0x80065834
int CD_getsector2();

#endif /* PSYQ_LIBCD_H */
