#include "NoAPI/Io.h"
#include "NoAPI/Thread.h"
void MyThread(void *Arg) {
  struct FileHandle stdout = GetStdout();
  IO.WriteString(&stdout, "Hello, From `MyThread`\n");
  IO.Flush(&stdout);
}
int main() {
  struct FileHandle stdout;
  struct ThreadHandle thread;

  stdout = GetStdout();
  IO.WriteString(&stdout, "Hello from main thread!\n");

  thread = Thread.Create(MyThread);
  Thread.SetData(&thread, &stdout);
  Thread.SetName(&thread, "Hello Threading");
  Thread.Start(&thread);
  Thread.Join(&thread);
}
