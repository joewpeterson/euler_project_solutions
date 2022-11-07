CC=gcc
OBJ=main.o inc_by_min_pf.o prime_f.o ../common_lib/track_runtime.o
SRC = main.c inc_by_min_pf.c prime_f.c ../common_lib/track_runtime.c


run: $(OBJ)
	$(CC) -o run $(OBJ) -lm

%.o: %.c
	$(CC) $< -c -o $@  -lm


.PHONY:clean

clean:
	rm $(OBJ) run 
