#CC = g++
CXX = g++
CXXFLAGS = -Wall -Werror

objects = main.o Contact.o 

main: $(objects)
	$(CXX) $(CXXFLAGS) $(objects)
main.o : main.cpp Contact.h
	$(CXX) $(CXXFLAGS) -c -g main.cpp Contact.cpp
	
Contact.o : Contact.cpp Contact.h
all : main
clean :
	-rm main main.o
            