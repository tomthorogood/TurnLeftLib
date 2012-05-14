COMPILE_DEBUG = g++ -Wall -g
INCLUDES = -I/home/tom/dev/ -I/usr/include/c++/4.4
TESTS = commonwords explosion ptrarray wordaggregator hungryvector log
TEST_SUFFIX = "_test.cpp"
TXT_RESOURCES = commonwords aggregatortext aggregatortext2 
TXT_OUTPUTS = logtest_output
CC = $(COMPILE_DEBUG) -c $(INCLUDES)

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
		utils/Log.o \
		utils/PtrArray.o \
		utils/HungryVector.o \
		utils/Explosion.o \
		utils/CommonWords.o \
		utils/RandomCharSet.o \
		utils/WordAggregator.o

install:
	cp libturnleft.a /usr/local/lib/

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
		do rm $$f; done;

clean-objects:
	rm -rf *.o
	rm -rf *.cc
	rm -rf *.a
	cd utils/ && $(MAKE) clean

clean: clean-tests clean-objects

