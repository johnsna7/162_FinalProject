###################################################
# Name: makefile
# Author: Nathan Johnson
# Date: 06.08.2019
# Description: makefile for Final Project
# #################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

# Object/Class Functions
OBJS = Game.o Item.o Player.o Space.o Room.o Armory.o Barracks.o
SRCS = Game.cpp Item.cpp Player.cpp Space.cpp Room.cpp Armory.cpp Barracks.cpp

OBJS += Engine.o Storage.o Treasury.o
SRCS += Engine.cpp Storage.cpp Treasury.cpp

# Main Function
OBJS += main.o
SRCS += main.cpp

# Validation Functions
OBJS += getInt.o
SRCS += getInt.cpp

# Menu
OBJS += menu.o
SRCS += menu.cpp

FILENAME = SpyBot.exe

${FILENAME}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${FILENAME}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o  *.exe

run:
	valgrind --leak-check=full --show-leak-kinds=all  ${FILENAME}
