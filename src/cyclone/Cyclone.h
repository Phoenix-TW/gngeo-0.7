
// Cyclone 68000 Emulator - Header File

// Most code (c) Copyright 2004 Dave, All rights reserved.
// Some coding/bugfixing was done by notaz
// Cyclone 68000 is free for non-commercial use.

// For commercial use, separate licencing terms must be obtained.

#ifdef __cplusplus
extern "C" {
#endif

extern int CycloneVer; // Version number of library

struct Cyclone
{
  unsigned int d[8];   // [r7,#0x00]
  unsigned int a[8];   // [r7,#0x20]
  unsigned int pc;     // [r7,#0x40] Memory Base+PC
  unsigned char srh;   // [r7,#0x44] Status Register high (T_S__III)
  unsigned char xc;    // [r7,#0x45] Extend flag (____??X?)
  unsigned char flags; // [r7,#0x46] Flags (ARM order: ____NZCV) [68k order is XNZVC]
  unsigned char irq;   // [r7,#0x47] IRQ level
  unsigned int osp;    // [r7,#0x48] Other Stack Pointer (USP/SSP)
  unsigned int vector; // [r7,#0x4c] IRQ vector (temporary)
  int (*InvalidOpCallback)(unsigned short opcode);             // [r7,#0x50] - optional invalid op call back
  int (*IrqCallback)(int int_level);          // [r7,#0x54] - optional irq callback function
  int stopped;         // [r7,#0x58] 1 == processor is in stopped state
  int cycles;          // [r7,#0x5c]
  int membase;         // [r7,#0x60] Memory Base (ARM address minus 68000 address)
  unsigned int   (*checkpc)(unsigned int pc); // [r7,#0x64] - Called to recalc Memory Base+pc
  unsigned char  (*read8  )(unsigned int a);  // [r7,#0x68]
  unsigned short (*read16 )(unsigned int a);  // [r7,#0x6c]
  unsigned int   (*read32 )(unsigned int a);  // [r7,#0x70]
  void (*write8 )(unsigned int a,unsigned char  d); // [r7,#0x74]
  void (*write16)(unsigned int a,unsigned short d); // [r7,#0x78]
  void (*write32)(unsigned int a,unsigned int   d); // [r7,#0x7c]
  unsigned char  (*fetch8 )(unsigned int a);  // [r7,#0x80]
  unsigned short (*fetch16)(unsigned int a);  // [r7,#0x84]
  unsigned int   (*fetch32)(unsigned int a);  // [r7,#0x88]
};

void CycloneRun(struct Cyclone *pcy);

#ifdef __cplusplus
} // End of extern "C"
#endif
