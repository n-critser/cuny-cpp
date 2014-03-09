#CC = g++
CXX = g++
CXXFLAGS = -c -g  -Wall -Werror

all : map

map: main.o
	$(CXX)  main.o -o map

main.o : main.cpp sMap.h
	$(CXX) $(CXXFLAGS)  main.cpp sMapimpl.cpp

#sMap.o : sMapimple.cpp sMap.h
#	$(CXX) $(CXXFLAGS) sMapimple.cpp
clean :
	-rm *.o map


#Need more makefile experience!!!
#READ THIS LINK FIRST
#**http://www.cs.umd.edu/class/spring2002/cmsc214/Tutorial/makefile.html**
#***********************************************************************
#http://www.eecs.umich.edu/eecs/courses/eecs380/HANDOUTS/Makefile-Tutorial.html
#http://mrbook.org/tutorials/make/
#

#
#