COMPILE_DEBUG = g++ -Wall -g
INCLUDES = -I$(CURDIR) -I$(CURDIR)/../ -I/usr/include/c++/4.6.3
TESTS = commonwords explosion ptrarray wordaggregator hungryvector log
TEST_SUFFIX = "_test.cpp"
TXT_RESOURCES = commonwords aggregatortext aggregatortext2 
TXT_OUTPUTS = logtest_output
CC = $(COMPILE_DEBUG) -c $(INCLUDES)
LIBOUTPUT = /usr/local/lib
HEADEROUTPUT = /usr/include/TurnLeftLib

tests:
	for f in $(TESTS); \
	do  $(COMPILE_DEBUG) $(INCLUDES) tests/$$f$(TEST_SUFFIX) -o $$f; done;
	for f in $(TXT_RESOURCES); \
		do cp tests/$$f.txt .; done;

mtest:
	for x in $(TESTS); \
	do \
		echo "$(COMPILE_DEBUG) $(INCLUDES) tests/$$x$(TEST_SUFFIX) -o $$x" ;\
	done


exceptions:
	cp Exceptions Exceptions.cc
	g++ -c $(INCLUDES) Exceptions.cc exceptions/src/FileNotFoundException.h \
	exceptions/src/MissingParameterException.h

utils:
	cd utils/ && $(MAKE) all	
	ar crs libturnleft.a \
		utils/Inlines.o \
		utils/Log.o \
		utils/PtrArray.o \
		utils/HungryVector.o \
		utils/Explosion.o \
		utils/CommonWords.o \
		utils/RandomCharSet.o \
		utils/WordAggregator.o

install:
	cp libturnleft.a $(LIBOUTPUT)
	mkdir -p $(HEADEROUTPUT)
	cp -r . $(HEADEROUTPUT)
	cp $(CURDIR)/utils/src/commonwords/commonwords.txt $(HEADEROUTPUT)
	chmod 775 $(HEADEROUTPUT)/commonwords.txt
	cd $(HEADEROUTPUT) && $(MAKE) clean-objects

.PHONY: tests utils exceptions

#####################
# CLEANUP FUNCTIONS #
#####################
clean-tests:
	for f in $(TESTS); \
		do rm $$f; done;
	for f in $(TXT_RESOURCES); \
		do rm $$f.txt; done;
	for f in $(TXT_OUTPUTS); \
		do rm $$f.txt; done;

clean-objects:
	cd utils/ && $(MAKE) clean
	rm -rf *.o
	rm -rf *.cc
	rm -rf *.a
	rm -rf *.gch

clean: clean-tests clean-objects

