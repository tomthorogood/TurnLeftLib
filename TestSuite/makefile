artifact := libturnleft_test.a
t_artifact := test_example
includes := -I$(CURDIR)
linker := -L$(CURDIR)
install_path := /usr/local/include/TurnLeftLib/TestSuite

cpp_files := $(wildcard *.cpp)
obj_files := $(patsubst %.cpp, %.o, $(cpp_files))
hpp_files := $(wildcard *.h)

all: artifact
test: t_artifact
	./$(t_artifact)

artifact: $(obj_files)
	ar cr $(artifact) $(obj_files)

%.o: %.cpp
	g++ $(includes) -c -Wall -o $@ $< $(libs)

t_artifact: example/example.cpp artifact
	g++ $(includes) $(linker) -Wall -o $(t_artifact) $< -lturnleft_test

install: artifact
	mkdir -p $(install_path)
	for f in $(hpp_files) ; do \
		cp $$f $(install_path)/ ; \
	done;
	cp $(artifact) /usr/local/lib/

clean:
	rm -f $(obj_files)
	rm -f $(artifact)
	rm -f $(t_artifact)
