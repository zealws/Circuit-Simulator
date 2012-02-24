.PHONY: clean

BUILD = ../build
CIRCUIT_INCLUDES = $(BUILD)/include
CIRCUIT_LIB = $(BUILD)/lib

CXX = g++
CXXFLAGS = -g -I$(CIRCUIT_INCLUDES) $(CIRCUIT_LIB)/*

EXEs = \
	error-messages/errorMsgBad \
	error-messages/errorMsgBetter \
	component-declaration/independentComponents \
	component-declaration/linkedInComponents \
	edge-trigger/edgeTrigger \
	int-encoder/intEncoder

all: $(EXEs)

%: %.o

%.o: %.cpp

clean:
	rm -f $(EXEs)
