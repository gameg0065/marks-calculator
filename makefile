main: readAndPrint.o calcFunctions.o variables.o
	g++ -std=c++0x -o main main.cpp readAndPrint.o calcFunctions.o
readAndPrint:
	g++ -std=c++0x -c readAndPrint.cpp
calcFunctions:
	g++ -c calcFunctions.cpp
# main:
# 	g++ -c main.cpp
variables:
	g++ -std=c++0x -c variables.cpp
clean:
	rm *.o main