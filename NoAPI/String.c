#include "String.h"

#include "Memory.h"
long long GetStringLength(const char *Target) {
  const char *seg = Target;
  while (*Target) Target++;
  return Target - seg;
}
long long CopyString(const char *Source, char *Output) {
  long long StringLen = String.Count(Source);
  Output = Memory.Alloc(StringLen);
  for (int i = 0; i < StringLen; ++i) {
    Output[i] = Source[i];
  }
  return StringLen;
}
