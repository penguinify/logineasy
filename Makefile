CC = gcc
INCLUDES = -I./include
SRC = src/main.c
OBJ = $(SRC:.c=.o)
TARGET = ./dist/logineasy

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
