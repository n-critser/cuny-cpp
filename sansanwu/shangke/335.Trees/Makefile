#
# Copied from Stewart Weiss Makefile CSCI335
#
# Type make to compile all programs in this filder 
#
#

EXNAME   = trees
CPP 	 =  /usr/bin/g++
CC  	 =  /usr/bin/gcc
SRCS 	 = $(wildcard *.cpp)
HEADS    = $(wildcard *.h)# Logger.h Poly.h
OBJS 	 = main.o #$(patsubst %.cpp, %.o, $(SRCS))
EXECS	 = $(EXNAME) #$(patsubst %.cpp, %,$(SRCS))
CPPFLAGS = -Wall -Werror -g -I../include #-std=c++11 #-Werror  stronger than -Wall
CFLAGS 	 = -Wall -g
DEBUG    = *.debug
#	@echo $(HEADS)

# EXECUTABLE
$(EXNAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^
	@ echo "Changed files: $?"

# OBJECTS
main.o: main.cpp Logger.h BSTree.h AvlTree.h
#Poly.o: Poly.cpp Poly.h Logger.h
# END OBJECTS
.PHONY: all clean cleanall help

all: $(EXECS)

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(EXECS) $(DEBUG)

install: $(EXECS)
	cp $(EXECS) /usr/local/bin #~/bin

.cpp:
	$(CPP) $(CPPFLAGS) -o $@ $@.cpp

.c:
	$(CC) $(CFLAGS) -o $@ $@.c

#****************
# $ make help ----> Target : help : gives some hints to compiling
help:
	@echo "HEADERS: Making with headers-->  $(HEADS)"
	@echo "Usage: make all (must have an appropriate FILE.c for this to build)"
	@echo "Warning: you will most likely have to upload using SUPERUSER sudo command"
	@echo "Usage: make clean (removes all *.hex, *.o , *.out files)"
	@echo "See README.org for complete project help"
#********************************************************
