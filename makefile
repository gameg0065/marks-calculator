main: readAndPrint.o variables.o
	g++ -std=c++0x -o main main.cpp readAndPrint.o
readAndPrint:
	g++ -std=c++0x -c readAndPrint.cpp
# functions:
# 	g++ -c functions.cpp
# main:
# 	g++ -c main.cpp
variables:
	g++ -std=c++0x -c variables.cpp
clean:
	rm *.o main