

Flags = -Wall -pedantic-errors -std=c++20 -flto -O3
CPP = g++ 


main : Makefile   stack.o main.o 
	$(CPP) $(Flags) -o main   stack.o main.o 

stack.o : Makefile   stack.cpp   stack.h 
	$(CPP) -c $(Flags) stack.cpp -o  stack.o


main.o : Makefile   main.cpp   stack.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


