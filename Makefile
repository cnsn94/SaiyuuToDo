PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

FLAGS = -Wall -Wextra -Wvla -pedantic

release: FLAGS += -O3
release: all

debug: FLAGS += -g
debug: all

all: main.o
	g++ $(FLAGS) main.o -o main
main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

clean:
	rm -f *.o main                                

run:
	./main