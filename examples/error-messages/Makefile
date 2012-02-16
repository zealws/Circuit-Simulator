.PHONY: clean

BUILD = ../../build
CIRCUIT_INCLUDES = $(BUILD)/include
CIRCUIT_LIB = $(BUILD)/lib

CXX = g++
CXX_FLAGS = -g -I$(CIRCUIT_INCLUDES) $(CIRCUIT_LIB)/*

all: errorMsgBetter errorMsgBad $(CIRCUIT_LIB)/*

errorMsgBad: errorMsgBad.cpp
	g++ $(CXX_FLAGS) -o errorMsgBad errorMsgBad.cpp

errorMsgBetter: errorMsgBetter.cpp
	g++ $(CXX_FLAGS) -o errorMsgBetter errorMsgBetter.cpp

clean:
	rm -f errorMsgBetter errorMsgBad
