/* psyq/libsnd.h -- prototypes of the LIBSND.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBSND_H
#define PSYQ_LIBSND_H

struct ProgAtr;
struct VagAtr;

// LIBSND SSCLOSE.OBJ+0x17c, retail SLUS_013.95 0x80055D50
void SsSeqClose(short);
// LIBSND SSCLOSE.OBJ+0x1a0, retail SLUS_013.95 0x80055D74
void SsSepClose(short);
// LIBSND SSEND.OBJ+0x0, retail SLUS_013.95 0x80055DA4
void SsEnd(void);
// LIBSND SSINIT.OBJ+0x0, retail SLUS_013.95 0x80055E54
int _SsInit();
// LIBSND SSINIT_C.OBJ+0x0, retail SLUS_013.95 0x80055EF4
void SsInit(void);
// LIBSND SSISEOS.OBJ+0x0, retail SLUS_013.95 0x80055F54
short SsIsEos(short, short);
// LIBSND SSOPENP.OBJ+0x0, retail SLUS_013.95 0x80055F94
short SsSepOpen(unsigned long *, short, short);
// LIBSND CC_0.OBJ+0x0, retail SLUS_013.95 0x80056294
void _SsContBankChange(short, short);
// LIBSND CC_6.OBJ+0x0, retail SLUS_013.95 0x80056314
void _SsContDataEntry(short, short, unsigned char);
// LIBSND CC_7.OBJ+0x0, retail SLUS_013.95 0x80056694
void _SsContMainVol(short, short, unsigned char);
// LIBSND CC_10.OBJ+0x0, retail SLUS_013.95 0x80056764
void _SsContPanpot(short, short, unsigned char);
// LIBSND CC_11.OBJ+0x0, retail SLUS_013.95 0x80056834
void _SsContExpression(short, short, unsigned char);
// LIBSND CC_64.OBJ+0x0, retail SLUS_013.95 0x80056924
void _SsContDamper(short, short, unsigned char);
// LIBSND CC_91.OBJ+0x0, retail SLUS_013.95 0x800569D4
void _SsContExternal(short, short, unsigned char);
// LIBSND CC_98.OBJ+0x0, retail SLUS_013.95 0x80056A64
void _SsContNrpn1(short, short, unsigned char);
// LIBSND CC_99.OBJ+0x0, retail SLUS_013.95 0x80056B64
void _SsContNrpn2(short, short, unsigned char);
// LIBSND CC_100.OBJ+0x0, retail SLUS_013.95 0x80056CA4
void _SsContRpn1(short, short, unsigned char);
// LIBSND CC_101.OBJ+0x0, retail SLUS_013.95 0x80056D14
void _SsContRpn2(short, short, unsigned char);
// LIBSND CC_121.OBJ+0x0, retail SLUS_013.95 0x80056D84
void _SsContResetAll(short, short);
// LIBSND DE_0.OBJ+0x0, retail SLUS_013.95 0x80056E44
void _SsSetNrpnVabAttr0(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_1.OBJ+0x0, retail SLUS_013.95 0x80056ED4
void _SsSetNrpnVabAttr1(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_2.OBJ+0x0, retail SLUS_013.95 0x80056F94
void _SsSetNrpnVabAttr2(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_3.OBJ+0x0, retail SLUS_013.95 0x80057024
void _SsSetNrpnVabAttr3(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_4.OBJ+0x0, retail SLUS_013.95 0x800570B4
void _SsSetNrpnVabAttr4(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND CCADSR.OBJ+0x0, retail SLUS_013.95 0x80057164
int _SsUtResolveADSR();
// LIBSND CCADSR.OBJ+0x5c, retail SLUS_013.95 0x800571C0
int _SsUtBuildADSR();
// LIBSND DE_5.OBJ+0x0, retail SLUS_013.95 0x80057264
void _SsSetNrpnVabAttr5(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_6.OBJ+0x0, retail SLUS_013.95 0x80057324
void _SsSetNrpnVabAttr6(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_7.OBJ+0x0, retail SLUS_013.95 0x800573D4
void _SsSetNrpnVabAttr7(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_8.OBJ+0x0, retail SLUS_013.95 0x80057484
void _SsSetNrpnVabAttr8(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_9.OBJ+0x0, retail SLUS_013.95 0x80057534
void _SsSetNrpnVabAttr9(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_10.OBJ+0x0, retail SLUS_013.95 0x800575F4
void _SsSetNrpnVabAttr10(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_11.OBJ+0x0, retail SLUS_013.95 0x800576A4
void _SsSetNrpnVabAttr11(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_12.OBJ+0x0, retail SLUS_013.95 0x80057754
void _SsSetNrpnVabAttr12(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_13.OBJ+0x0, retail SLUS_013.95 0x80057834
void _SsSetNrpnVabAttr13(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_14.OBJ+0x0, retail SLUS_013.95 0x800578D4
void _SsSetNrpnVabAttr14(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND DE_16.OBJ+0x0, retail SLUS_013.95 0x800579A4
void _SsSetNrpnVabAttr16(short, short, short, struct VagAtr, short, unsigned char);
// LIBSND MIDIBEND.OBJ+0x0, retail SLUS_013.95 0x80057A64
void _SsSetPitchBend(short, short);
// LIBSND MIDICC.OBJ+0x0, retail SLUS_013.95 0x80057B14
void _SsSetControlChange(short, short, unsigned char);
// LIBSND MIDIMETA.OBJ+0x0, retail SLUS_013.95 0x80057D44
void _SsGetMetaEvent(short, short, unsigned char);
// LIBSND MIDINOTE.OBJ+0x0, retail SLUS_013.95 0x80057F14
void _SsNoteOn(short, short, unsigned char, unsigned char);
// LIBSND MIDIPROG.OBJ+0x0, retail SLUS_013.95 0x80057FF4
void _SsSetProgramChange(short, short, unsigned char);
// LIBSND MIDITIME.OBJ+0x0, retail SLUS_013.95 0x80058064
int _SsReadDeltaValue();
// LIBSND SEPINIT.OBJ+0x0, retail SLUS_013.95 0x80058114
int _SsInitSoundSep();
// LIBSND SSPLAY.OBJ+0x0, retail SLUS_013.95 0x800584F4
void SsSeqPlay(short, char, short);
// LIBSND SSPLAY_2.OBJ+0x0, retail SLUS_013.95 0x80058534
void SsSepPlay(short, short, char, short);
// LIBSND PLAYMODE.OBJ+0x0, retail SLUS_013.95 0x80058614
int Snd_SetPlayMode();
// LIBSND SSSATTR.OBJ+0x0, retail SLUS_013.95 0x80058734
void SsSetSerialAttr(char, char, char);
// LIBSND SSSMV.OBJ+0x0, retail SLUS_013.95 0x80058B74
void SsSetMVol(short, short);
// LIBSND SSSTART.OBJ+0x230, retail SLUS_013.95 0x80058DF4
void SsStart(void);
// LIBSND SSSTART.OBJ+0x250, retail SLUS_013.95 0x80058E14
void SsStart2(void);
// LIBSND SSCALL.OBJ+0x0, retail SLUS_013.95 0x80058ED4
void SsSeqCalledTbyT(void);
// LIBSND CRES.OBJ+0x0, retail SLUS_013.95 0x80059144
int _SsSndCrescendo();
// LIBSND PAUSE.OBJ+0x0, retail SLUS_013.95 0x80059354
int _SsSndPause();
// LIBSND PLAY.OBJ+0x0, retail SLUS_013.95 0x800593F4
int _SsSndPlay();
// LIBSND MIDIREAD.OBJ+0x0, retail SLUS_013.95 0x80059424
int _SsSeqPlay();
// LIBSND MIDIREAD.OBJ+0xfc, retail SLUS_013.95 0x80059520
int _SsSeqGetEof();
// LIBSND MIDIREAD.OBJ+0x340, retail SLUS_013.95 0x80059764
int _SsGetSeqData();
// LIBSND NEXT.OBJ+0x0, retail SLUS_013.95 0x80059B14
int _SsSndNextSep();
// LIBSND REPLAY.OBJ+0x0, retail SLUS_013.95 0x80059C14
int _SsSndReplay();
// LIBSND SSSTOP.OBJ+0x0, retail SLUS_013.95 0x80059C74
int _SsSndStop();
// LIBSND SSSTOP.OBJ+0x180, retail SLUS_013.95 0x80059DF4
void SsSeqStop(short);
// LIBSND SSSTOP.OBJ+0x1a8, retail SLUS_013.95 0x80059E1C
void SsSepStop(short, short);
// LIBSND SSSV.OBJ+0x0, retail SLUS_013.95 0x80059E54
void SsSetSerialVol(char, short, short);
// LIBSND SSTABLE.OBJ+0x0, retail SLUS_013.95 0x80059F64
void SsSetTableSize(char *, short, short);
// LIBSND SSTICK.OBJ+0x0, retail SLUS_013.95 0x8005A184
void SsSetTickMode(long);
// LIBSND SSVOL.OBJ+0x0, retail SLUS_013.95 0x8005A2D4
int _SsSndSetVol();
// LIBSND SSVOL.OBJ+0x90, retail SLUS_013.95 0x8005A364
void SsSeqSetVol(short, short, short);
// LIBSND SSVOL.OBJ+0xf8, retail SLUS_013.95 0x8005A3CC
void SsSepSetVol(short, short, short, short);
// LIBSND TEMPO.OBJ+0x0, retail SLUS_013.95 0x8005A464
int _SsSndTempo();
// LIBSND UT_GPA.OBJ+0x0, retail SLUS_013.95 0x8005A684
short SsUtGetProgAtr(short, short, struct ProgAtr *);
// LIBSND UT_GVA.OBJ+0x0, retail SLUS_013.95 0x8005A794
short SsUtGetVagAtr(short, short, short, struct VagAtr *);
// LIBSND UT_KEYV.OBJ+0x0, retail SLUS_013.95 0x8005A9D4
short SsUtKeyOnV(short, short, short, short, short, short, short, short);
// LIBSND UT_KEYV.OBJ+0x36c, retail SLUS_013.95 0x8005AD40
short SsUtKeyOffV(short);
// LIBSND UT_RDEL.OBJ+0x0, retail SLUS_013.95 0x8005ADB4
void SsUtSetReverbDelay(short);
// LIBSND UT_RDEP.OBJ+0x0, retail SLUS_013.95 0x8005B7A4
void SsUtSetReverbDepth(short, short);
// LIBSND UT_REV.OBJ+0x0, retail SLUS_013.95 0x8005B834
short SsUtSetReverbType(short);
// LIBSND UT_RFB.OBJ+0x0, retail SLUS_013.95 0x8005B9C4
void SsUtSetReverbFeedback(short);
// LIBSND UT_SVA.OBJ+0x0, retail SLUS_013.95 0x8005BA44
short SsUtSetVagAtr(short, short, short, struct VagAtr *);
// LIBSND UT_VVOL4.OBJ+0x0, retail SLUS_013.95 0x8005BC14
short SsUtSetVVol(short, short, short);
// LIBSND VM_ALOC2.OBJ+0x0, retail SLUS_013.95 0x8005BCA4
int _SsVmDoAllocate();
// LIBSND VM_DOFF.OBJ+0x0, retail SLUS_013.95 0x8005BE74
int _SsVmDamperOff();
// LIBSND VM_DON.OBJ+0x0, retail SLUS_013.95 0x8005BE84
int _SsVmDamperOn();
// LIBSND VM_F.OBJ+0x0, retail SLUS_013.95 0x8005BE94
int _SsVmFlush();
// LIBSND VM_INIT.OBJ+0x0, retail SLUS_013.95 0x8005D0F4
int _SsVmInit();
// LIBSND VM_KEY.OBJ+0x0, retail SLUS_013.95 0x8005D4E4
int _SsVmKeyOn();
// LIBSND VM_KEY.OBJ+0x51c, retail SLUS_013.95 0x8005DA00
int _SsVmKeyOff();
// LIBSND VM_KEY.OBJ+0x67c, retail SLUS_013.95 0x8005DB60
int _SsVmSeKeyOn();
// LIBSND VM_KEY.OBJ+0x768, retail SLUS_013.95 0x8005DC4C
int _SsVmSeKeyOff();
// LIBSND VM_ALOC1.OBJ+0x0, retail SLUS_013.95 0x8005DC84
int _SsVmAlloc();
// LIBSND VM_N2P.OBJ+0x0, retail SLUS_013.95 0x8005DEF4
int note2pitch();
// LIBSND VM_N2P.OBJ+0x4c, retail SLUS_013.95 0x8005DF40
int note2pitch2();
// LIBSND VM_N2P.OBJ+0xb4, retail SLUS_013.95 0x8005DFA8
unsigned short SsPitchFromNote(short, short, unsigned char, unsigned char);
// LIBSND VM_NO1.OBJ+0x0, retail SLUS_013.95 0x8005E0D4
int vmNoiseOn();
// LIBSND VM_NOFF.OBJ+0x0, retail SLUS_013.95 0x8005E694
int vmNoiseOff();
// LIBSND VM_NOWOF.OBJ+0x0, retail SLUS_013.95 0x8005E6D4
int _SsVmKeyOffNow();
// LIBSND VM_NOWON.OBJ+0x0, retail SLUS_013.95 0x8005E794
int _SsVmKeyOnNow();
// LIBSND VM_PB.OBJ+0x0, retail SLUS_013.95 0x8005EC64
int _SsVmPBVoice();
// LIBSND VM_PB.OBJ+0x1ec, retail SLUS_013.95 0x8005EE50
int _SsVmPitchBend();
// LIBSND VM_PROG2.OBJ+0x0, retail SLUS_013.95 0x8005EF34
int _SsVmSetProgVol();
// LIBSND VM_SEQ.OBJ+0x0, retail SLUS_013.95 0x8005EFA4
int _SsVmSetSeqVol();
// LIBSND VM_SEQ.OBJ+0x56c, retail SLUS_013.95 0x8005F510
int _SsVmGetSeqVol();
// LIBSND VM_SEQ.OBJ+0x5d0, retail SLUS_013.95 0x8005F574
int _SsVmSeqKeyOff();
// LIBSND VM_STAV.OBJ+0x0, retail SLUS_013.95 0x8005F624
int _SsVmSelectToneAndVag();
// LIBSND VM_VOL.OBJ+0x0, retail SLUS_013.95 0x8005F6F4
int _SsVmSetVol();
// LIBSND VM_VSU.OBJ+0x0, retail SLUS_013.95 0x8005FC94
int _SsVmVSetUp();
// LIBSND VS_MONO.OBJ+0x0, retail SLUS_013.95 0x8005FD54
void SsSetMono(void);
// LIBSND VS_MONO.OBJ+0x10, retail SLUS_013.95 0x8005FD64
void SsSetStereo(void);
// LIBSND VS_VAB.OBJ+0x0, retail SLUS_013.95 0x8005FD74
void SsVabClose(short);
// LIBSND VS_VH.OBJ+0x0, retail SLUS_013.95 0x800601A4
short SsVabOpenHeadSticky(unsigned char *, short, unsigned long);
// LIBSND VS_VH.OBJ+0x34, retail SLUS_013.95 0x800601D8
short SsVabFakeHead(unsigned char *, short, unsigned long);
// LIBSND VS_VH.OBJ+0x70, retail SLUS_013.95 0x80060214
int _SsVabOpenHeadWithMode();
// LIBSND VS_VTBP.OBJ+0x0, retail SLUS_013.95 0x80060604
short SsVabTransBodyPartly(unsigned char *, unsigned long, short);
// LIBSND VS_VTC.OBJ+0x0, retail SLUS_013.95 0x80060884
short SsVabTransCompleted(short);

#endif /* PSYQ_LIBSND_H */
