SRCDIR = src
OBJDIR = obj

LOCAL_BUILD_DIR=TurnLeftLib

EXC_SRC_DIRECTORY=$(CURDIR)/../exceptions/src/
EXC_SRC_HEADERS=$(wildcard $(EXC_SRC_DIRECTORY)/*.h)
EXC_SRC_HEADER_FILES=$(notdir $(EXC_SRC_HEADERS))
EXC_SRC_TMP=$(addprefix $(LOCAL_BUILD_DIR)/$(SRCDIR)/,$(EXC_SRC_HEADER_FILES))

ARCHIVE_HEADERS_DIRECTORY=$(CURDIR)/../global_headers/
ARCHIVE_HEADERS = $(wildcard $(ARCHIVE_HEADERS_DIRECTORY)/*)
ARCHIVE_HEADERS_TMP=$(addprefix $(LOCAL_BUILD_DIR)/, $(notdir $(ARCHIVE_HEADERS)))

INCLUDE_DIRS = /usr/include /usr/local/include $(CURDIR)
INCLUDES = $(foreach f, $(INCLUDE_DIRS), -I$(f))

HEADER_FILES = $(wildcard $(SRCDIR)/*.h)
SRC_FILES = $(wildcard $(SRCDIR)/*.cpp)
OBJECT_FILES = $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(notdir $(SRC_FILES))))
TEMP_HEADERS = $(addprefix $(LOCAL_BUILD_DIR)/,$(HEADER_FILES))

all : exception-headers global-headers $(OBJECT_FILES)

$(OBJECT_FILES) : $(TEMP_HEADERS) $(EXC_SRC_TMP) $(ARCHIVE_HEADERS_TMP) | $(OBJDIR)/

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	g++ -c -Wall $(INCLUDES) -o $@ $<

$(LOCAL_BUILD_DIR)/$(SRCDIR)/%.h : $(SRCDIR)/%.h | $(LOCAL_BUILD_DIR)/$(SRCDIR)/
	cp $< $@

$(LOCAL_BUILD_DIR)/%.h : $(ARCHIVE_HEADERS_DIRECTORY)/%.h
	cp $@ $<

exception-headers: $(EXC_SRC_HEADERS) | $(LOCAL_BUILD_DIR)/$(SRCDIR)/
	for h in $(EXC_SRC_HEADERS); do \
		cp $$h $(CURDIR)/$(LOCAL_BUILD_DIR)/$(SRCDIR)/; \
		done;

global-headers: $(ARCHIVE_HEADERS) | $(LOCAL_BUILD_DIR)/
	for h in $(ARCHIVE_HEADERS); do \
		cp $$h $(LOCAL_BUILD_DIR)/; \
		done;


$(OBJDIR)/:
	mkdir -p $@

$(LOCAL_BUILD_DIR)/:
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
