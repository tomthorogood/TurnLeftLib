SRCDIR = src
OBJDIR = obj

INCLUDE_DIRS = /usr/include /usr/local/include $(CURDIR) $(CURDIR)/$(SRCDIR) $(CURDIR)/../../ 
INCLUDES = $(foreach f, $(INCLUDE_DIRS), -I$(f))

HEADER_FILES = $(wildcard $(SRCDIR)/*.h)
SRC_FILES = $(wildcard $(SRCDIR)/*.cpp)
OBJECT_FILES = $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(notdir $(SRC_FILES))))

all : $(OBJECT_FILES)

$(OBJECT_FILES) : | $(OBJDIR)/

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	g++ -c -Wall $(INCLUDES) -o $@ $<

$(OBJDIR)/:
	mkdir -p $(OBJDIR)/

clean:
	rm -rf $(OBJDIR)
	clear&&clear

test-output:
	echo $(INCLUDES)
	echo $(HEADER_FILES)
	echo $(SRC_FILES)
	echo $(OBJECT_FILES)
