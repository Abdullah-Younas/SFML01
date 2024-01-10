all: compile link

compile:
	g++ -Isrc/include -c Textures.cpp

link:
	g++ Textures.o -o Textures -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system