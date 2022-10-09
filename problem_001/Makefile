CC=gcc
OBJ=main.o track_runtime.o
SRC = main.c track_runtime.c

run: $(OBJ)
	$(CC) -o run $(OBJ)

%.o: %.c
	$(CC) $< -c -o $@ 


.PHONY:clean

clean:
	rm $(OBJ) run 
