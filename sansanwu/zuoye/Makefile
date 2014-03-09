#
# Copied from Stewart Weiss Makefile CSCI335
#
# Type make to compile all programs in this filder 
#
#

CPP 	 =  /usr/bin/g++
CC  	 =  /usr/bin/gcc
SRCS 	 = $(wildcard *.cpp)
OBJS 	 = $(patsubst %.cpp, %.o, $(SRCS))
EXECS	 = $(patsubst %.cpp, %,$(SRCS))
CPPFLAGS = -Wall -g -I../include #-std=c++11
CFLAGS 	 = -Wall -g

.PHONY: all clean cleanall

all: $(EXECS)

clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(EXECS)

install: $(EXECS)
	cp $(EXECS) /usr/local/bin #~/bin

.cpp:
	$(CPP) $(CPPFLAGS) -o $@ $@.cpp

.c:
	$(CC) $(CFLAGS) -o $@ $@.c
