# Makefile

# Variables
CC=gcc
SRC=./src/main.c
OUTPUT=./dist/logineasy
CFLAGS=-Wall -O2

# Default target
all: build

# Build target
build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT)

# Clean target
clean:
	rm -f $(OUTPUT)

# Cross-compile for macOS
build-darwin:
	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT) --target=x86_64-apple-darwin

.PHONY: all build clean build-darwin
