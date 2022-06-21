#pragma once
const int syscall(int, ...);
inline int SysRead(int fd, void *buf, long count) {
  return syscall(0, fd, buf, count);
}
inline int SysWrite(int fd, const void *buf, long count) {
  return syscall(1, fd, buf, count);
}
inline int SysFSync(int fd) {
  return syscall(74, fd);
}
inline int SysOpen(const char *path, int flags, const char* mode) {
  return syscall(2, path, flags, mode);
}
