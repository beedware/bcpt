CC := gcc
CFLAGS := -O2 -g -Wall -Wextra -Wshadow -Wfatal-errors -std=gnu23 -fsanitize=address,undefined
LDLIBS := -lm

.PHONY: build run

build: main.out

main.out: main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

run: main.out
	./main.out
