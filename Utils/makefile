includes = -I$(CURDIR)/../../
CPP_FLAGS = -Wall -c $(includes)

source_files := $(wildcard *.cpp)
header_files := $(wildcard *.h)
object_files := $(patsubst %.cpp, %.o, $(source_files))

all: $(object_files)

%.o:%.cpp
	g++ $(CPP_FLAGS) -o $@ $<

clean:
	rm -rf *.o
