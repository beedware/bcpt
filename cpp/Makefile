CXX := g++
CXXFLAGS := -O2 -Wall -Wextra -Wshadow -Wfatal-errors -std=gnu++23 -fsanitize=address,undefined -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

.PHONY: build run

build: main.out

main.out: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

run: main.out
	./main.out
