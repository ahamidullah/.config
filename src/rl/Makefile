OBJS = *.cpp
CC = g++
CFLAGS = -fno-diagnostics-color -O0 -g -std=c++14 -DDEBUG=1 -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-overflow -Wwrite-strings
LFLAGS = -L/usr/X11R6/lib/ -lSDL2 -lSDL2_image
OBJ_NAME = rl

all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJ_NAME)

.PHONY: run clean
run : all
	./rl

clean: rm -f $(OBJ_NAME) *.o
