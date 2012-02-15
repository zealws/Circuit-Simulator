.PHONY: clean

CIRCUIT_INCLUDES = ../build/include
CIRCUIT_LIB = ../build/lib

CXX = g++
CXX_FLAGS = -g -I$(CIRCUIT_INCLUDES) $(CIRCUIT_LIB)/*

all: linkedInComponents independentComponents errorMsgBetter errorMsgBad $(CIRCUIT_LIB)/*

linkedInComponents: linkedInComponents.cpp
	g++ $(CXX_FLAGS) -o linkedInComponents linkedInComponents.cpp

independentComponents: independentComponents.cpp
	g++ $(CXX_FLAGS) -o independentComponents independentComponents.cpp

errorMsgBad: errorMsgBad.cpp
	g++ $(CXX_FLAGS) -o errorMsgBad errorMsgBad.cpp

errorMsgBetter: errorMsgBetter.cpp
	g++ $(CXX_FLAGS) -o errorMsgBetter errorMsgBetter.cpp

clean:
	rm -f linkedInComponents independentComponents errorMsgBetter errorMsgBad
