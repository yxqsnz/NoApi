#pragma once
#include "pthread.h"
struct ThreadHandle {
  pthread_t Inner;
  void *Data;
  void *FunctionPointer;
  char *Name;
};
struct __Thread {
  struct ThreadHandle (*Create)(void(FnPtr)(void *Arg));
  void (*SetName)(struct ThreadHandle *th, const char *Name);
  void (*SetData)(struct ThreadHandle *th, void *Data);
  void (*Start)(struct ThreadHandle *th);
  void *(*Join)(struct ThreadHandle *th);
};
/* Creates a New Thread */
struct ThreadHandle CreateThread(void(FnPtr)(void *Arg));
/* Renames a Thread */
void ThreadSetName(struct ThreadHandle *th, const char *Name);
/* Set Thread's Data */
void ThreadSetData(struct ThreadHandle *th, void *Data);
/* Starts a Thread */
void ThreadStart(struct ThreadHandle *th);
/* Wait a Thread to stop */
void *ThreadJoin(struct ThreadHandle *th);
static struct __Thread Thread = {.Create = CreateThread,
                                 .SetName = ThreadSetName,
                                 .SetData = ThreadSetData,
                                 .Start = ThreadStart,
                                 .Join = ThreadJoin};
