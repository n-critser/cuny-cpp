#CC = g++
CXX = g++
CXXFLAGS = -Wall -Werror

objects = main.o Contact.o ContactViewer.o ContactController.o 

main: $(objects)
	$(CXX) $(CXXFLAGS) $(objects)
main.o : main.cpp ABCList.hpp ABList.hpp  LinkedList.hpp Contact.h ContactViewer.h ContactController.h
	$(CXX) $(CXXFLAGS) -c -g main.cpp Contact.cpp	ContactController.cpp ContactViewer.cpp
	
Contact.o : Contact.cpp Contact.h 
ContactViewer.o : ContactViewer.cpp ContactViewer.h Contact.h ContactController.h
ContactController.o : ContactController.cpp ContactController.h Contact.h LinkedList.hpp ABCList.hpp ABList.hpp
all : main
clean :
	-rm main main.o