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

# Target for cross-compiling to Darwin (macOS)
build-darwin: CC = x86_64-apple-darwin19-gcc
build-darwin: $(TARGET)-darwin

$(TARGET)-darwin: $(OBJ:.o=-darwin.o)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.darwin.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean-darwin:
	rm -f $(OBJ:.o=-darwin.o) $(TARGET)-darwin
