SOURCES=main.cpp ./sources/*.cpp
HEADERS=./headers/*.h

build:
	g++ -g $(HEADERS) $(SOURCES) -o bin/app
run:
	./bin/app
