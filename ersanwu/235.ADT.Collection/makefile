#CC = g++
CXX = g++
CXXFLAGS = -Wall -Werror


main: main.o
	$(CXX) $(CXXFLAGS) main.o
main.o : main.cpp ABCList.hpp ABList.hpp DoubleLinkList.h LinkedList.hpp BaseStack.h AStack.h PStack.h BaseQueue.h PQueue.h AQueue.h
	$(CXX) $(CXXFLAGS) -c -g main.cpp 	
all : main
clean :
	-rm main main.o
            