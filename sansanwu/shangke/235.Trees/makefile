#CC = g++
CXX = g++
CXXFLAGS = -c -g  -Wall -Werror

all : trees

trees: main.o Organism.o
	$(CXX)  main.o Organism.o -o trees

main.o : main.cpp Organism.h BinaryTree.h BSTree.h 
	$(CXX) $(CXXFLAGS)  main.cpp  Organism.cpp

Organism.o : Organism.cpp Organism.h
	$(CXX) $(CXXFLAGS) Organism.cpp
clean :
	-rm *.o trees
         
#Need more makefile experience!!!
#READ THIS LINK FIRST
#**http://www.cs.umd.edu/class/spring2002/cmsc214/Tutorial/makefile.html**
#***********************************************************************
#http://www.eecs.umich.edu/eecs/courses/eecs380/HANDOUTS/Makefile-Tutorial.html
#http://mrbook.org/tutorials/make/
#

#
#