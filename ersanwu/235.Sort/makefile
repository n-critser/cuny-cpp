#CC = g++
CXX = g++
CXXFLAGS = -Wall -Werror


main: main.o
	$(CXX) $(CXXFLAGS) main.o
main.o : main.cpp 
	$(CXX) $(CXXFLAGS) -c -g main.cpp
all : main
clean :
	-rm main main.o
            