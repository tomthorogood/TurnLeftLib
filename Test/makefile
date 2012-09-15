artifact := libturnleft_test.a
t_artifact := test_example
includes := -I$(CURDIR)
linker := -L$(CURDIR)
#libs := 

cpp_files := $(wildcard *.cpp)
obj_files := $(patsubst %.cpp, %.o, $(cpp_files))

all: artifact
test: t_artifact

artifact: $(obj_files)
	ar cr $(artifact) $(obj_files)

%.o: %.cpp
	g++ $(includes) -c -Wall -o $@ $< $(libs)

t_artifact: example/example.cpp
	g++ $(includes) $(linker) -Wall -o $(t_artifact) $< -lturnleft_test

clean:
	rm -f $(obj_files)
	rm -f $(artifact)
	rm -f $(t_artifact)
