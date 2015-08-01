# Makefile
#LDFLAGS=-lncurses

all: SMR-cli

SMR-cli:
	gcc cli-main.c -o SMR-cli -lncurses
