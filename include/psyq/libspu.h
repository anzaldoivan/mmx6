/* psyq/libspu.h -- prototypes of the LIBSPU.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBSPU_H
#define PSYQ_LIBSPU_H

struct SpuCommonAttr;
struct SpuReverbAttr;
struct SpuVoiceAttr;

// LIBSPU S_CRWA.OBJ+0x0, retail SLUS_013.95 0x80054B94
long SpuClearReverbWorkArea(long);
// LIBSPU SPU.OBJ+0x0, retail SLUS_013.95 0x80054D34
int _spu_init();
// LIBSPU SPU.OBJ+0x440, retail SLUS_013.95 0x80055174
int _spu_FiDMA();
// LIBSPU SPU.OBJ+0x4fc, retail SLUS_013.95 0x80055230
int _spu_Fr_();
// LIBSPU SPU.OBJ+0x5a4, retail SLUS_013.95 0x800552D8
int _spu_t();
// LIBSPU SPU.OBJ+0x824, retail SLUS_013.95 0x80055558
int _spu_Fw();
// LIBSPU SPU.OBJ+0x8a8, retail SLUS_013.95 0x800555DC
int _spu_Fr();
// LIBSPU SPU.OBJ+0x90c, retail SLUS_013.95 0x80055640
int _spu_FsetRXX();
// LIBSPU SPU.OBJ+0x950, retail SLUS_013.95 0x80055684
int _spu_FsetRXXa();
// LIBSPU SPU.OBJ+0x9f4, retail SLUS_013.95 0x80055728
int _spu_FgetRXXa();
// LIBSPU SPU.OBJ+0xa30, retail SLUS_013.95 0x80055764
int _spu_FsetPCR();
// LIBSPU SPU.OBJ+0xad8, retail SLUS_013.95 0x8005580C
int _spu_Fw1ts();
// LIBSPU S_INI.OBJ+0x0, retail SLUS_013.95 0x80055874
int _SpuInit();
// LIBSPU S_INI.OBJ+0xe8, retail SLUS_013.95 0x8005595C
void SpuStart(void);
// LIBSPU S_DCB.OBJ+0x0, retail SLUS_013.95 0x800559D4
int _SpuDataCallback();
// LIBSPU S_M_UTIL.OBJ+0x0, retail SLUS_013.95 0x80055A04
int _SpuIsInAllocateArea();
// LIBSPU S_M_UTIL.OBJ+0x80, retail SLUS_013.95 0x80055A84
int _SpuIsInAllocateArea_();
// LIBSPU S_GKS.OBJ+0x0, retail SLUS_013.95 0x80055B14
long SpuGetKeyStatus(unsigned long);
// LIBSPU S_STM.OBJ+0x0, retail SLUS_013.95 0x80055BA4
long SpuSetTransferMode(long);
// LIBSPU S_Q.OBJ+0x0, retail SLUS_013.95 0x80058594
void SpuQuit(void);
// LIBSPU S_SCA.OBJ+0x0, retail SLUS_013.95 0x800587F4
void SpuSetCommonAttr(struct SpuCommonAttr *);
// LIBSPU S_SRMP.OBJ+0x0, retail SLUS_013.95 0x8005ADF4
long SpuSetReverbModeParam(struct SpuReverbAttr *);
// LIBSPU S_SRA.OBJ+0x0, retail SLUS_013.95 0x8005B2D4
int _spu_setReverbAttr();
// LIBSPU S_SR.OBJ+0x0, retail SLUS_013.95 0x8005B8D4
long SpuSetReverb(long);
// LIBSPU S_SNV.OBJ+0x0, retail SLUS_013.95 0x8005C364
unsigned long SpuSetNoiseVoice(long, unsigned long);
// LIBSPU S_SAV.OBJ+0x0, retail SLUS_013.95 0x8005C394
int _SpuSetAnyVoice();
// LIBSPU S_GNV.OBJ+0x0, retail SLUS_013.95 0x8005C654
unsigned long SpuGetNoiseVoice(void);
// LIBSPU S_GAV.OBJ+0x0, retail SLUS_013.95 0x8005C684
int _SpuGetAnyVoice();
// LIBSPU S_SRV.OBJ+0x0, retail SLUS_013.95 0x8005C6B4
unsigned long SpuSetReverbVoice(long, unsigned long);
// LIBSPU S_GRV.OBJ+0x0, retail SLUS_013.95 0x8005C6E4
unsigned long SpuGetReverbVoice(void);
// LIBSPU S_SK.OBJ+0x0, retail SLUS_013.95 0x8005C714
void SpuSetKey(long, unsigned long);
// LIBSPU S_SVA.OBJ+0x0, retail SLUS_013.95 0x8005C8D4
void SpuSetVoiceAttr(struct SpuVoiceAttr *);
// LIBSPU S_N2P.OBJ+0x0, retail SLUS_013.95 0x8005CED4
int _spu_note2pitch();
// LIBSPU S_N2P.OBJ+0xd0, retail SLUS_013.95 0x8005CFA4
int _spu_pitch2note();
// LIBSPU S_GVEX.OBJ+0x0, retail SLUS_013.95 0x8005D0D4
void SpuGetVoiceEnvelope(int, short *);
// LIBSPU S_M_INIT.OBJ+0x0, retail SLUS_013.95 0x8005D444
long SpuInitMalloc(long, char *);
// LIBSPU S_IT.OBJ+0x0, retail SLUS_013.95 0x8005D4A4
int _spu_setInTransfer();
// LIBSPU S_IT.OBJ+0x28, retail SLUS_013.95 0x8005D4CC
int _spu_getInTransfer();
// LIBSPU S_SNC.OBJ+0x0, retail SLUS_013.95 0x8005E644
long SpuSetNoiseClock(long);
// LIBSPU S_M_F.OBJ+0x0, retail SLUS_013.95 0x8005FE24
void SpuFree(unsigned long);
// LIBSPU S_M_INT.OBJ+0x0, retail SLUS_013.95 0x8005FEA4
int _spu_gcSPU();
// LIBSPU S_STSA.OBJ+0x0, retail SLUS_013.95 0x80060794
unsigned long SpuSetTransferStartAddr(unsigned long);
// LIBSPU S_WP.OBJ+0x0, retail SLUS_013.95 0x800607F4
unsigned long SpuWritePartly(unsigned char *, unsigned long);
// LIBSPU S_ITC.OBJ+0x0, retail SLUS_013.95 0x800608B4
long SpuIsTransferCompleted(long);

#endif /* PSYQ_LIBSPU_H */
