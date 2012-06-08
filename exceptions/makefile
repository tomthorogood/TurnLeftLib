OBJECTS_DIR = obj
SRC_DIR = src

LOCAL_BUILD_DIR=TurnLeftLib

INCLUDE_DIRS = /usr/include /usr/local/include $(CURDIR)
INCLUDES = $(foreach f, $(INCLUDE_DIRS), -I$(f))

# src/foo.h
HEADER_FILES = $(wildcard $(SRC_DIR)/*.h)

# src/foo.cpp
SOURCE_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# obj/foo.o
OBJECT_FILES = $(addprefix $(OBJECTS_DIR)/, $(patsubst %.cpp, %.o, $(notdir $(SOURCE_FILES))))

# TurnLeftLib/src/foo.h
TEMP_HEADERS = $(addprefix $(LOCAL_BUILD_DIR)/,$(HEADER_FILES))

# Make all the object files!
all : $(OBJECT_FILES)

# {Make object files} 
# 		Requires Temporary Headers and the obj/ directory
$(OBJECT_FILES) : $(TEMP_HEADERS) | $(OBJECTS_DIR)/

# {Make an object file}
# 		Requires the associated source file
$(OBJECTS_DIR)/%.o : $(SRC_DIR)/%.cpp
	g++ -c -Wall $(INCLUDES) -o $@ $<

# {Create a header file in the local build directory}
# 		Requires:
# 			The associated header file in the current source directory
# 			The local build directory
#
$(LOCAL_BUILD_DIR)/$(SRC_DIR)/%.h : $(SRC_DIR)/%.h | $(LOCAL_BUILD_DIR)/$(SRC_DIR)/
	cp $< $@

# {Create obj/}
$(OBJECTS_DIR)/:
	mkdir -p $(OBJECTS_DIR)/

# {Create TurnLeftLib/src/}
$(LOCAL_BUILD_DIR)/$(SRC_DIR)/:
	mkdir -p $@

# ...clean.
clean:
	rm -rf $(OBJECTS_DIR)
	rm -rf $(LOCAL_BUILD_DIR)
	clear&&clear


# Print various things for testing
test-output:
	@echo 
	@echo -{ TEMPORARY HEADERS -}
	@echo $(TEMP_HEADERS)
	@echo
	@echo -{ CURRENT HEADER LOCATIONS }-
	@echo $(HEADER_FILES)
