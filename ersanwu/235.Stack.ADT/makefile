#CC = g++
CXX = g++
CXXFLAGS = -Wall -Werror


main: main.o
	$(CXX) $(CXXFLAGS) main.o
main.o : main.cpp BaseStack.h AStack.h PStack.h
	$(CXX) $(CXXFLAGS) -c -g main.cpp 	
all : main
clean :
	-rm main main.o
            