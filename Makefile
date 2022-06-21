CC = zig cc
linux:
	$(CC) -o Target/No.so -pthread -shared NoAPI/*.c 
app: linux
	$(CC) -o Target/App.exe Main.c Target/No.so
