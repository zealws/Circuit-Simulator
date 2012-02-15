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
	-Isrc/gc/include \
	-Isrc/sparsehash

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
	src/Circuit/CustomComponent.o \
	src/Circuit/Component.o \
	src/Circuit/Wire.o \
	src/Observer/Observable.o \
	src/Observer/Observer.o \
	src/Observer/UpdateCounter.o \
	src/CircuitIterator/CircuitIterator.o \
	src/CircuitIterator/BFSCircuitEvaluator.o \
	src/Exceptions/WireError.o \
	src/Exceptions/CircuitEvalError.o \
	src/Exceptions/ComponentError.o

# These files will be copied to the distribution folder
# when building it.
DIST_FILES = \
	src/CircuitSimulator.h \
	src/Circuit/WireState.h \
	src/Circuit/Circuit.h \
	src/Circuit/CustomComponent.h \
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
	src/Exceptions/ComponentError.h \
	src/BaseCircuits/BaseCircuits.h \
	src/sparsehash/sparse_hash_map.h \
	src/sparsehash/sparse_hash_set.h \
	src/sparsehash/sparsetable.h \
	src/sparsehash/template_util.h \
	src/sparsehash/type_traits.h \
	src/sparsehash/hashtable-common.h \
	src/sparsehash/libc_allocator_with_realloc.h \
	src/sparsehash/sparseconfig.h \
	src/sparsehash/sparsehashtable.h

# These files will NOT be copied to the distribution folder
# when building it.
OTHER_FILES =  \
	src/Exceptions/WireError.cpp \
	src/Exceptions/CircuitEvalError.cpp \
	src/Exceptions/ComponentError.cpp \
	src/CircuitIterator/CircuitIterator.cpp \
	src/CircuitIterator/BFSCircuitEvaluator.cpp \
	src/Observer/UpdateCounter.cpp \
	src/Observer/Observable.cpp \
	src/Observer/Observer.cpp \
	src/Circuit/WireState.cpp \
	src/Circuit/CustomComponent.cpp \
	src/Circuit/Circuit.cpp \
	src/Circuit/Wire.cpp \
	src/Circuit/Component.cpp

# List of Source Files for the dependency generator
SRCS = $(DIST_FILES) $(OTHER_FILES)

# List of all source files
# Mainly so that I can do linecounts and searches easily
ALL = Makefile Makefile.inc Makefile.real $(SRCS)
