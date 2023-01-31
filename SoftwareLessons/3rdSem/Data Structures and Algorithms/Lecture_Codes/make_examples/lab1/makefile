All: compile b2 run

compile:
	g++ -c main.cpp -o main.o
	g++ -c mylib.cpp -o mylib.o

b2: 
	g++ main.o mylib.o -o program.o
	
run: 
	./program.o