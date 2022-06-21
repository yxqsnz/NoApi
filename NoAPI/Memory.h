#pragma once
extern void *malloc(unsigned long s);
extern void free(void *ptr);
struct __Memory {
  void *(*Alloc)(unsigned long Size);
  void (*Free)(void *Poiter);
};
static struct __Memory Memory = {malloc, free};
