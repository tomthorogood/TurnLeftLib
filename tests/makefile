I_DIR := /usr/include /usr/local/include $(CURDIR) $(CURDIR)/../ /usr/include/c++/4.6.3
INCLUDE = $(foreach d, $(I_DIR), -I$d)
C_FLAGS := -Wall -g
CC := g++
FILE_SUFFIX = "_test.cpp"
TESTS = commonwords explosion ptrarray wordaggregator hungryvector log enumparser
OUTPUT_DIR = $(CURDIR)/../test_build

all:
	mkdir -p $(OUTPUT_DIR)
	for f in $(TESTS); do\
		$(CC) $(C_FLAGS) $$f$(FILE_SUFFIX) -o $(OUTPUT_DIR)/$$f;\
		done;
	cp *.txt $(OUTPUT_DIR)/

maketest:
	for f in $(TESTS); do\
		echo \"$(CC) $(C_FLAGS) $$f$(FILE_SUFFIX) -o $(OUTPUT_DIR)/$$f\";\
		done;

clean:
	rm -rf $(OUTPUT_DIR)
	rm -f *.o
	rm -f *.a
	rm -f *.out
