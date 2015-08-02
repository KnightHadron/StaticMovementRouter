# Makefile
#LDFLAGS=-lncurses

all: SMR-cli

SMR-cli: cli-main.c
	gcc cli-main.c -o SMR-cli -lncurses
