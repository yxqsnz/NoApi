#include "Thread.h"
#include "StdErrorKind.h"
#include "String.h"
#include "StdError.h"
#include <pthread.h>
struct ThreadHandle CreateThread(void (FnPtr)(void *Arg)) {
  struct ThreadHandle th;
  th.FunctionPointer = FnPtr;
  return th;
}
void ThreadSetName(struct ThreadHandle *th, const char *ThreadName) {
  String.CopyTo(ThreadName, th->Name);
}
void ThreadSetData(struct ThreadHandle *th, void *Data) {
  th->Data = Data;
}
void* ThreadJoin(struct ThreadHandle* th) {
  void* ret;
  if(pthread_join(th->Inner, &ret) != 0)
  {
    SetLastError(STATUS_THREAD_JOIN_FAIL);
    return NULL;
  }
  return ret;
}
void ThreadStart(struct ThreadHandle *th) {
  if(th->FunctionPointer == NULL)
  {
    SetLastError(STATUS_THREAD_NO_FUNCTION);
    return;
  }
  pthread_create(&th->Inner, NULL, th->FunctionPointer, &th->Data);
}
