#Thomas Coll 09/02/2019
#First simple Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread

SIMPLE: main.cpp Barrier.cpp Semaphore.cpp
	g++ -g -std=c++11 -pthread Semaphore.cpp SafeBuffer.cpp Event.cpp main.cpp

DEBUG: main.cpp Barrier.cpp Semaphore.cpp
	g++ -g -std=c++11 -Wall -pthread Semaphore.cpp SafeBuffer.cpp Event.cpp main.cpp
CLEAN:
	rm *.o

DOC:
	doxygen
