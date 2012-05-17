COMPILE_DEBUG = g++ -Wall -g
INCLUDES = -I/home/tom/Dev/ -I/usr/include/c++/4.6.3
TESTS = commonwords explosion ptrarray wordaggregator hungryvector log
TEST_SUFFIX = "_test.cpp"
TXT_RESOURCES = commonwords aggregatortext aggregatortext2 
TXT_OUTPUTS = logtest_output
CC = $(COMPILE_DEBUG) -c $(INCLUDES)

all: log ptrarray hungryvector explosion commonwords \
	randomcharset wordaggregator

commonwords:
	cp CommonWords CommonWords.cc;
	$(CC) CommonWords.cc src/commonwords/commonwords.cpp \
	src/commonwords/commonwords.h;

explosion:
	cp Explosion Explosion.cc;
	$(CC) Explosion.cc src/explosion/explosion.cpp \
	src/explosion/explosion.h

hungryvector:
	cp HungryVector HungryVector.cc;
	$(CC) HungryVector.cc src/hungryvector.h;

log:
	cp Log Log.cc
	$(CC)  Log.cc src/log/log.cpp src/log/log.h

ptrarray:
	cp PtrArray PtrArray.cc;
	$(CC)  PtrArray.cc src/ptrarray.h ;

randomcharset:
	cp RandomCharSet RandomCharSet.cc;
	$(CC) RandomCharSet.cc src/randomcharset.h;

wordaggregator:
	cp WordAggregator WordAggregator.cc;
	$(CC)  WordAggregator.cc src/wordaggregator/wordaggregator.cpp \
	src/wordaggregator/wordaggregator.h;

clean:
	rm *.o *.cc
