# These are phony targets since they don't actually create files with those names
.PHONY : dist examples clean realclean squeakyclean deleteBackups linecount depend

include Makefile.inc

dist: Makefile.dep $(OBJS)
	if [ ! -d $(DIST) ] ; then mkdir $(DIST) ; fi
	if [ ! -d $(DIST)/lib ] ; then mkdir $(DIST)/lib ; fi
	if [ ! -d $(DIST)/include ] ; then mkdir $(DIST)/include ; fi
	cp $(OBJS) $(DIST)/lib/
	cp $(GC_LIB)/* $(DIST)/lib/
	cp -r $(GC_INCLUDE)/* $(DIST)/include/
	cp -r $(CIRCUIT_LIBRARY)/* $(DIST)/include/
	cp $(DIST_FILES) $(DIST)/include/

examples: dist
	make --no-print-directory -C examples

# Cleans up the source directory's object files
# And files that were created automatically by flex and bison
clean:
	rm -f $(OBJS)
	rm -rf $(DIST)

# Cleans up everything that was created at compile time
# Including the automatically created dependencies
realclean: clean deleteBackups
	rm -f 	$(EXE) \
		Makefile.dep
	rm -rf $(DIST)
	rm -r html/ latex/
	make --no-print-directory -C examples clean

# Delete backup files (created automatically by my text editor)
deleteBackups:
	rm -f `find . | grep "\.*~"`

# Performs a line count of all the files i've written
linecount:
	wc -l $(ALL)

# Make the dependency file
# We need to have build flex and bison already, since we use those cpp files to
# build our dependencies.
Makefile.dep: $(SRCS)
	if [ ! -e Makefile.dep ] ; then touch Makefile.dep ; fi
	$(DEP) $(DEPFLAGS) -fMakefile.dep -- $(CXXFLAGS) -- $(SRCS) 2> /dev/null
	rm -f Makefile.dep.bak

# for convenience
depend: Makefile.dep

# Build documentation using doxygen
doc: Doxyfile $(SRCS)
	doxygen Doxyfile
