All: compile b2 run

compile:
	g++ -c message.cpp -o message.o
	g++ -c p1.cpp -o p1.o

b2: 
	g++ message.o p1.o -o program.o
	
run: 
	./program.o

	