#CC = g++
CXX = g++
CXXFLAGS = -c -g  -Wall -Werror

all : lists

lists: main.o 
	$(CXX)  main.o -o lists

main.o : main.cpp   UCList.h #List.h
	$(CXX) $(CXXFLAGS)  main.cpp  

#Organism.o : Organism.cpp Organism.h
#	$(CXX) $(CXXFLAGS) Organism.cpp
clean :
	rm *.o lists

#Need more makefile experience!!!
#READ THIS LINK FIRST
#**http://www.cs.umd.edu/class/spring2002/cmsc214/Tutorial/makefile.html**
#***********************************************************************
#http://www.eecs.umich.edu/eecs/courses/eecs380/HANDOUTS/Makefile-Tutorial.html
#http://mrbook.org/tutorials/make/
#

#
#