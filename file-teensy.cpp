#include "c4a.h"

#ifdef FILE_TEENSY

// TODO: support LittleFS for the Teensy

cell inputFp, outputFp;
void fileInit() {}
void filePush(cell fh) {}
cell inPop() { return 0; }
cell fileOpen(const char *name, const char *mode) { return 0; }
void fileClose(cell fh) {}
void fileDelete(const char *name) {}
cell fileRead(char *buf, int sz, cell fh) { return 0; }
cell fileWrite(char *buf, int sz, cell fh) { return 0; }
int  fileGets(char *buf, int sz, cell fh) { return 0; }
void fileLoad(const char *name) {}
void blockLoad(int blk) {}
void blockLoadNext(int blk) {}

#endif // FILE_TEENSY
