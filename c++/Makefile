CC := g++
CFLAGS := --std=c++20 -g
SRCS := $(wildcard *.cc)

% : src/%.cc
	$(CC) $(CFLAGS) -o $@ $< 
