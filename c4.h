#ifndef __C4_H__
#define __C4_H__

#include <Arduino.h>
#define MEM_SZ           192*1024
#define STK_SZ            32
#define RSTK_SZ           32
#define LSTK_SZ           15
#define TSTK_SZ           32
#define FSTK_SZ            4
#define NAME_LEN          17 // To make dict-entry size 24 (13+1+1+1+4)
#define CODE_SLOTS         8*1024 // 8*1024*4 = 32k
// #define FILE_NONE
#define FILE_PICO
// #define FILE_TEENSY

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <time.h>

#define VERSION   20241112
#define _SYS_LOAD_

#define btwi(n,l,h)   ((l<=n) && (n<=h))
#define _IMMED              1
#define _INLINE             2

#define CELL_T        int32_t
#define CELL_SZ       4
#define addressFmt    ": %s $%lx ; inline"
#define WC_T          uint32_t
#define WC_SZ         4
#define NUM_BITS      0xE0000000
#define NUM_MASK      0x1FFFFFFF

enum { COMPILE=1, DEFINE=2, INTERP=3, COMMENT=4 };

typedef CELL_T cell;
typedef WC_T wc_t;
typedef unsigned char byte;
typedef struct { wc_t xt; byte fl, ln; char nm[NAME_LEN+1]; } DE_T;
typedef struct { wc_t op; const char *name; byte fl; } PRIM_T;

// These are defined by c4.cpp
extern void push(cell x);
extern cell pop();
extern void strCpy(char *d, const char *s);
extern int  strEq(const char *d, const char *s);
extern int  strEqI(const char *d, const char *s);
extern int  strLen(const char *s);
extern int  lower(const char c);
extern void zTypeF(const char *fmt, ...);
extern void inner(wc_t start);
extern void outer(const char *src);
extern void outerF(const char *fmt, ...);
extern void c4Init();
extern void ok();

// c4.cpp needs these to be defined
extern cell inputFp, outputFp;
extern void zType(const char *str);
extern void emit(const char ch);
extern void ttyMode(int isRaw);
extern int  key();
extern int  qKey();
extern cell timer();
extern void fileInit();
extern void filePush(cell fh);
extern cell filePop();
extern cell fileOpen(const char *name, const char *mode);
extern void fileClose(cell fh);
extern void fileDelete(const char *name);
extern cell fileRead(char *buf, int sz, cell fh);
extern cell fileWrite(char *buf, int sz, cell fh);
extern int  fileGets(char *buf, int sz, cell fh);
extern void fileLoad(const char *name);
extern void blockLoad(int blk);
extern void blockLoadNext(int blk);
extern void sys_load();

#endif //  __C4_H__