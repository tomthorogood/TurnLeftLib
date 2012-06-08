SRCDIR = src
OBJDIR = obj

LOCAL_BUILD_DIR=TurnLeftLib

INCLUDE_DIRS = /usr/include /usr/local/include $(CURDIR)
INCLUDES = $(foreach f, $(INCLUDE_DIRS), -I$(f))

HEADER_FILES = $(wildcard $(SRCDIR)/*.h)
SRC_FILES = $(wildcard $(SRCDIR)/*.cpp)
OBJECT_FILES = $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(notdir $(SRC_FILES))))
TEMP_HEADERS = $(addprefix $(LOCAL_BUILD_DIR)/,$(HEADER_FILES))

all : $(OBJECT_FILES)

$(OBJECT_FILES) : $(TEMP_HEADERS) | $(OBJDIR)/

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	g++ -c -Wall $(INCLUDES) -o $@ $<

$(LOCAL_BUILD_DIR)/$(SRCDIR)/%.h : $(SRCDIR)/%.h | $(LOCAL_BUILD_DIR)/$(SRCDIR)/
	cp $< $@

$(OBJDIR)/:
	mkdir -p $@

$(LOCAL_BUILD_DIR)/$(SRCDIR)/:
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)
	rm -rf $(LOCAL_BUILD_DIR)
	clear&&clear

test-output:
	@echo \n TEMPORARY HEADERS
	@echo $(TEMP_HEADERS)
#	@echo $(INCLUDES)
#	@echo $(HEADER_FILES)
#	@echo $(SRC_FILES)
#	@echo $(OBJECT_FILES)
