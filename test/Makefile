.PHONY: clean

CIRCUIT_INCLUDES = ../build/include/
CIRCUIT_LIB = ../build/lib/

CXX = g++
CXX_FLAGS = -g -I$(CIRCUIT_INCLUDES)

main: main.cpp $(CIRCUIT_LIB)/* $(CIRCUIT_INCLUDES)/*.h
	g++ $(CXX_FLAGS) -o main main.cpp $(CIRCUIT_LIB)/*

main.cpp:

clean:
	rm -f main
