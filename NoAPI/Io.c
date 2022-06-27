#include "Io.h"

#include "StdError.h"
#include "StdErrorKind.h"
#include "String.h"
#define SYS_TRY(err, expr) \
  if (expr < 0) {          \
    SetLastError(err);     \
  }
int IOWriteString(struct FileHandle *fh, const char *Data) {
  int wrote;
  SYS_TRY(STATUS_IO_FAIL, (wrote = SysWrite(fh->fd, Data, String.Count(Data))));
  return wrote;
}
struct FileHandle IOOpenFile(const char *path, enum FileOpenFlag flags,
                             const char *mode) {
  struct FileHandle fh;
  SYS_TRY(STATUS_IO_FAIL, (fh.fd = SysOpen(path, flags, mode)));
  return fh;
}
void IOFlush(struct FileHandle *fh) {
  SYS_TRY(STATUS_IO_FAIL, SysFSync(fh->fd));
}
struct FileHandle GetStdout() {
  struct FileHandle fh;
  fh.fd = 1;
  return fh;
}
