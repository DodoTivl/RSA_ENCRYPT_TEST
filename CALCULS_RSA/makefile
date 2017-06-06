CFLAGS = -W -Wall -ansi -pedantic

all:calculs_RSA

calculs_RSA:main.o
	g++ -o calculs_RSA $^ -lgmpxx -lgmp $(CFLAGS)
