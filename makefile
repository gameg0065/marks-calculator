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
main_arr: c_array/readAndPrint.o c_array/calcFunctions.o randomGenerator.o c_array/variables.o c_array/main.o
	g++ -std=c++0x -o c_array/main c_array/main.cpp c_array/readAndPrint.o c_array/calcFunctions.o randomGenerator.o
readAndPrint_arr:
	g++ -std=c++0x -c c_array/readAndPrint.cpp
calcFunctions_arr:
	g++ -c c_array/calcFunctions.cpp
variables:
	g++ -std=c++0x -c c_array/variables.cpp