all: compile link

compile:
	g++ -Isrc/include -c text.cpp

link:
	g++ text.o -o text -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system