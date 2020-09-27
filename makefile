# Program name: project1_Anderson_Jacob
# Author: Jacob Anderson
# Date: 9/27/18
# Description: makefile for project1. This will create an
# executable that runs a Langton's ant simulation based on
# parameters input by the user.

# This makefile is inspired by the example makefile from Oregon State.
# Available at: https://oregonstate.instructure.com/courses/1692879/files/71792854

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = ant.o board.o menuFunctions.o project1_Anderson_Jacob.o

SRCS = ant.cpp board.cpp menuFunctions.cpp project1_Anderson_Jacob.cpp

HEADERS = Ant.hpp Board.hpp menuFunctions.hpp

project1_Anderson_Jacob: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o langtonAnt.exe
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

# Command to clean the files
clean:
	rm ${OBJS} langtonAnt.exe
