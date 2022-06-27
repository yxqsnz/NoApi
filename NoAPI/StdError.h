#pragma once
static int StdError_Errno = 0;
static inline int GetLastError() { return StdError_Errno; }
static int SetLastError(int err) { return StdError_Errno = err; }
