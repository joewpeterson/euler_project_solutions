CC=gcc
OBJ=main.o ../common_lib/track_runtime.o
SRC = main.c ../common_lib/track_runtime.c


run: $(OBJ)
	$(CC) -o run $(OBJ) -lm

%.o: %.c
	$(CC) $< -c -o $@  -lm


.PHONY:clean

clean:
	rm $(OBJ) run 
