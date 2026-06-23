CC = gcc

TARGET = game.exe

CFLAGS = -Wall -Wextra \
          -Icjson \
          -Iraylib/include \
          -Isrc

LDFLAGS = -Lraylib/lib

LIBS = -lraylib -lgdi32 -lwinmm -lopengl32

SRC = $(wildcard src/*.c) \
      $(wildcard src/*/*.c)

all:
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)