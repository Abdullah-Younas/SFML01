all: compile link

compile:
	g++ -Isrc/include -c TicTacToe.cpp

link:
	g++ TicTacToe.o -o TicTacToe -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system