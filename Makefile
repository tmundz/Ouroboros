CC=gcc
FLAGS = -I -Wall -Wextra -g
DEPS = ./src/common.h ./src/web-client.h
OBJ = ./build/Ouroboros.o
TARGET = ./bin/Ouroboros

.PHONY: all clean 

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS)

$(OBJ): ./src/web-client.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

clean:
	rm -rf ./build/*.o bin/$(TARGET)
