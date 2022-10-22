CC := g++
FLAGS := -Wall -Wextra -pedantic -g -lsfml-graphics -lsfml-system -lsfml-window
TARGET := main

all: main

main: main.o population.o canvas.o agent.o utils.o
	$(CC) $(FLAGS) -o $(TARGET) main.o population.o canvas.o agent.o utils.o

main.o: main.cpp canvas.hpp population.hpp
	$(CC) $(FLAGS) -c main.cpp

population.o: population.cpp population.hpp canvas.hpp agent.hpp utils.hpp
	$(CC) $(FLAGS) -c population.cpp

canvas.o: canvas.cpp canvas.hpp agent.hpp
	$(CC) $(FLAGS) -c canvas.cpp

agent.o: agent.cpp agent.hpp utils.hpp
	$(CC) $(FLAGS) -c agent.cpp

utils.o: utils.cpp utils.hpp
	$(CC) $(FLAGS) -c utils.cpp

clean:
	rm *o
