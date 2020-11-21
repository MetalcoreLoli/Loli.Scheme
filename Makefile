SOURCES=main.cpp ./sources/*.cpp
HEADERS=./headers/*.h

build:
	g++ -g $(HEADERS) $(SOURCES) -o bin/app

debug:
	gdb bin/app

run:
	./bin/app

test:
	clear && make build run
