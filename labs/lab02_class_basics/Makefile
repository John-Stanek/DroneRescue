vector_app: main.o vector3.o
	g++ main.o vector3.o -o vector_app

main.o: main.cc
	g++ -c main.cc -o main.o

vector3.o: vector3.cc vector3.h
	g++ -c vector3.cc -o vector3.o

clean:
	rm -f *.o vector_app

