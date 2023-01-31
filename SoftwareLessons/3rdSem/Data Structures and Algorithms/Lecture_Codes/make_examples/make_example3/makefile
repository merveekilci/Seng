all: compile  run

compile:
	g++ -I ./include -o ./lib/operators.o -c ./src/operators.cpp
	g++ -I ./include -o ./bin/test ./lib/operators.o ./src/test.cpp
run:
	./bin/test
