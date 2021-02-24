main: readAndPrint.o calcFunctions.o randomGenerator.o variables.o main.o
	g++ -std=c++0x -o main main.cpp readAndPrint.o calcFunctions.o randomGenerator.o
readAndPrint:
	g++ -std=c++0x -c readAndPrint.cpp
calcFunctions:
	g++ -c calcFunctions.cpp
randomGenerator:
	g++ -c randomGenerator.cpp
variables:
	g++ -std=c++0x -c variables.cpp
clean:
	rm *.o main