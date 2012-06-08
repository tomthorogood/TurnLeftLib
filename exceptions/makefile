OBJECTS_DIR = obj
SRC_DIR = src

INCLUDE_DIRS = /usr/include /usr/local/include $(CURDIR) $(CURDIR)/$(SRC_DIR) $(CURDIR)../../
INCLUDES = $(foreach f, $(INCLUDE_DIRS), -I$(f))

HEADER_FILES = $(wildcard $(SRC_DIR)/*.h)
SOURCE_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECT_FILES = $(addprefix $(OBJECTS_DIR)/, $(patsubst %.cpp, %.o, $(notdir $(SOURCE_FILES))))

all : $(OBJECT_FILES)

$(OBJECT_FILES) : | $(OBJECTS_DIR)/

$(OBJECTS_DIR)/%.o : $(SRC_DIR)/%.cpp
	g++ -c -Wall $(INCLUDES) -o $@ $<

$(OBJECTS_DIR)/:
	mkdir -p $(OBJECTS_DIR)/

clean:
	rm -rf $(OBJECTS_DIR)
	clear&&clear

test-output:
#	echo $(HEADER_FILES)
#	echo $(SOURCE_FILES)
	echo $(OBJECT_FILES)
