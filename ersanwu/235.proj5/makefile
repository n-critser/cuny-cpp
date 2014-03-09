#CC = g++
CXX = g++
CXXFLAGS = -c -g  -Wall -Werror

all : proj5

proj5: main.o Organism.o
	$(CXX)  main.o Organism.o -o proj5

main.o : main.cpp Organism.h BinaryTree.h
	$(CXX) $(CXXFLAGS)  main.cpp BinaryTree.h Organism.cpp

Organism.o : Organism.cpp Organism.h
	$(CXX) $(CXXFLAGS) Organism.cpp
clean :
	-rm *.o proj5
         
#Need more makefile experience!!!
#READ THIS LINK FIRST
#**http://www.cs.umd.edu/class/spring2002/cmsc214/Tutorial/makefile.html**
#***********************************************************************
#http://www.eecs.umich.edu/eecs/courses/eecs380/HANDOUTS/Makefile-Tutorial.html
#http://mrbook.org/tutorials/make/
#

#
#