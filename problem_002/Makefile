CC=gcc
OBJ=main.o ../common_lib/track_runtime.o
SRC = main.c ../common_lib/track_runtime.c

run: $(OBJ)
	$(CC) -o run $(OBJ)

%.o: %.c
	$(CC) $< -c -o $@ 


.PHONY:clean

clean:
	rm $(OBJ) run 
