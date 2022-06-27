#pragma once
struct __String {
  long long (*Count)(const char *Target);
  long long (*CopyTo)(const char *Source, char *Target);
};
long long GetStringLength(const char *Target);
long long CopyString(const char *Source, char *Target);
static struct __String String = {.Count = GetStringLength,
                                 .CopyTo = CopyString};
