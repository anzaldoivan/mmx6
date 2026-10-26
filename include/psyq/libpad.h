/* psyq/libpad.h -- prototypes of the LIBPAD.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBPAD_H
#define PSYQ_LIBPAD_H

// LIBPAD PDCMD1.OBJ+0x0, retail SLUS_013.95 0x8006A7D4
void PadSetAct(int, unsigned char *, int);
// LIBPAD PDCMD2.OBJ+0x0, retail SLUS_013.95 0x8006A814
int PadSetActAlign(int, unsigned char *);
// LIBPAD PDENT2.OBJ+0x0, retail SLUS_013.95 0x8006A984
int PadGetState(int);
// LIBPAD PDENT3.OBJ+0x0, retail SLUS_013.95 0x8006AA54
int PadInfoMode(int, int, int);
// LIBPAD PDMAIINI.OBJ+0x0, retail SLUS_013.95 0x8006AB54
void PadStartCom(void);
// LIBPAD PDMAIINI.OBJ+0xcc, retail SLUS_013.95 0x8006AC20
void PadStopCom(void);
// LIBPAD PDDIRINI.OBJ+0x0, retail SLUS_013.95 0x8006AC64
void PadInitDirect(unsigned char *, unsigned char *);
// LIBPAD PDDIRRES.OBJ+0x0, retail SLUS_013.95 0x8006AD14
int _padInitDirPort();
// LIBPAD PDDIRRES.OBJ+0x930, retail SLUS_013.95 0x8006B644
int _dirFailAuto();
// LIBPAD PDRESRES.OBJ+0x0, retail SLUS_013.95 0x8006B764
int _padIsVsync();
// LIBPAD PDRESRES.OBJ+0x68, retail SLUS_013.95 0x8006B7CC
int _padIntPad();
// LIBPAD PDRESRES.OBJ+0x1f8, retail SLUS_013.95 0x8006B95C
int _padInitSioMode();
// LIBPAD PDRESRES.OBJ+0x61c, retail SLUS_013.95 0x8006BD80
int _padSioRW();
// LIBPAD PDRESRES.OBJ+0x840, retail SLUS_013.95 0x8006BFA4
int _padSioRW2();
// LIBPAD PDRESRES.OBJ+0xabc, retail SLUS_013.95 0x8006C220
int _padClrIntSio0();
// LIBPAD PDRESRES.OBJ+0xb4c, retail SLUS_013.95 0x8006C2B0
int _padWaitRXready();
// LIBPAD PDRESRES.OBJ+0xb74, retail SLUS_013.95 0x8006C2D8
int _padSetCmd();
// LIBPAD PDRESRES.OBJ+0xb84, retail SLUS_013.95 0x8006C2E8
int _padSendAtLoadInfo();
// LIBPAD PDRESRES.OBJ+0xc08, retail SLUS_013.95 0x8006C36C
int _padRecvAtLoadInfo();
// LIBPAD PDRESRES.OBJ+0xe78, retail SLUS_013.95 0x8006C5DC
int _padGetActSize();
// LIBPAD PDRESRES.OBJ+0xeb0, retail SLUS_013.95 0x8006C614
int _padLoadActInfo();
// LIBPAD PDRESRES.OBJ+0x1424, retail SLUS_013.95 0x8006CB88
int _padCmdParaMode();
// LIBPAD PDRESRES.OBJ+0x14cc, retail SLUS_013.95 0x8006CC30
int _padSetRC2wait();
// LIBPAD PDRESRES.OBJ+0x14ec, retail SLUS_013.95 0x8006CC50
int _padChkRC2wait();

#endif /* PSYQ_LIBPAD_H */
