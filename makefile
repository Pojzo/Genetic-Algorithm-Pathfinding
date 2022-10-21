CC := g++
FLAGS := -Wall -Wextra -pedantic -g -lsfml-graphics -lsfml-system -lsfml-window
TARGET := main

all: main

main: main.o canvas.o
	$(CC) $(FLAGS) -o $(TARGET) main.o canvas.o

main.o: canvas.hpp
	$(CC) $(FLAGS) -c main.cpp

canvas.o: canvas.cpp canvas.hpp
	$(CC) $(FLAGS) -c canvas.cpp
