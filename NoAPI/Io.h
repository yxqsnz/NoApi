#pragma once
#include "StdCall.h"
#include "String.h"
struct FileHandle {
  int fd;
};
enum FileOpenFlag {
  FILE_CREATE = 64,
};

struct __IO {
  int (*WriteString)(struct FileHandle *fh, const char *Data);
  void (*Flush)(struct FileHandle *fh);
  struct FileHandle (*OpenFile)(const char *path, enum FileOpenFlag flags,
                                const char *mode);
};

struct FileHandle IOOpenFile(const char *path, enum FileOpenFlag flags,
                             const char *mode);
struct FileHandle GetStdout();
int IOWriteString(struct FileHandle *fh, const char *Data);
void IOFlush(struct FileHandle *fh);
static struct __IO IO = {
    .WriteString = IOWriteString, .Flush = IOFlush, .OpenFile = IOOpenFile};
