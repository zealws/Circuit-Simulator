.PHONY: clean

BUILD = ../../build
CIRCUIT_INCLUDES = $(BUILD)/include
CIRCUIT_LIB = $(BUILD)/lib

CXX = g++
CXX_FLAGS = -g -I$(CIRCUIT_INCLUDES) $(CIRCUIT_LIB)/*

all: linkedInComponents independentComponents $(CIRCUIT_LIB)/*

linkedInComponents: linkedInComponents.cpp
	g++ $(CXX_FLAGS) -o linkedInComponents linkedInComponents.cpp

independentComponents: independentComponents.cpp
	g++ $(CXX_FLAGS) -o independentComponents independentComponents.cpp

clean:
	rm -f linkedInComponents independentComponents
