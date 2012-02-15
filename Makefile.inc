###########
# Options #
###########

# Final exe name
EXE = circuit

# Folder to place headers and objects.
DIST = build

# Included Directories
INCLUDES = \
	-Isrc/Circuit \
	-Isrc/Observer \
	-Isrc/CircuitIterator \
	-Isrc/Exceptions \
	-Isrc/gc/include

GC_LIB = src/gc/lib/
GC_INCLUDE = src/gc/include/

# Compiler
CXX = g++
CXXFLAGS = -g -fpermissive $(INCLUDES)

# Linker
LD = g++
LDFLAGS = -g

# Makedepend
DEP = makedepend
DEPFLAGS = -m -Y

CIRCUIT_LIBRARY = src/BaseCircuits/

# List of object files for linking and building the dist folder
OBJS =  src/Circuit/WireState.o \
	src/Circuit/Circuit.o \
	src/Circuit/Subcircuit.o \
	src/Circuit/Component.o \
	src/Circuit/Wire.o \
	src/Observer/Observable.o \
	src/Observer/Observer.o \
	src/Observer/UpdateCounter.o \
	src/CircuitIterator/CircuitIterator.o \
	src/CircuitIterator/BFSCircuitEvaluator.o \
	src/Exceptions/WireError.o \
	src/Exceptions/CircuitEvalError.o \
	src/Exceptions/SubcircuitError.o

# These files will be copied to the distribution folder
# when building it.
DIST_FILES = \
	src/CircuitSimulator.h \
	src/Circuit/WireState.h \
	src/Circuit/Circuit.h \
	src/Circuit/Subcircuit.h \
	src/Circuit/Component.h \
	src/Circuit/Wire.h \
	src/Circuit/CircuitWireDecs.h \
	src/Observer/Observable.h \
	src/Observer/Observer.h \
	src/Observer/ObserverDecs.h \
	src/Observer/UpdateCounter.h \
	src/CircuitIterator/CircuitIterator.h \
	src/CircuitIterator/BFSCircuitEvaluator.h \
	src/Exceptions/Exceptions.h \
	src/Exceptions/CircuitEvalError.h \
	src/Exceptions/WireError.h \
	src/Exceptions/SubcircuitError.h \
	src/BaseCircuits/BaseCircuits.h

# These files will NOT be copied to the distribution folder
# when building it.
OTHER_FILES =  \
	src/Exceptions/WireError.cpp \
	src/Exceptions/CircuitEvalError.cpp \
	src/Exceptions/SubcircuitError.cpp \
	src/CircuitIterator/CircuitIterator.cpp \
	src/CircuitIterator/BFSCircuitEvaluator.cpp \
	src/Observer/UpdateCounter.cpp \
	src/Observer/Observable.cpp \
	src/Observer/Observer.cpp \
	src/Circuit/WireState.cpp \
	src/Circuit/Subcircuit.cpp \
	src/Circuit/Circuit.cpp \
	src/Circuit/Wire.cpp \
	src/Circuit/Component.cpp

# List of Source Files for the dependency generator
SRCS = $(DIST_FILES) $(OTHER_FILES)


# List of all source files
# Mainly so that I can do linecounts and searches easily
ALL = Makefile Makefile.inc Makefile.real $(SRCS)
