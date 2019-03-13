SUBDIR=pkm battle gameplay

all: battle_main.o
	gcc -std=c++11 -o battle_main battle_main.o

%.o : %.cc
	gcc -std=c++11 -I . -o $@ -c $<
