LIBRARY_NAME := turnleft
LIB_FILENAME := lib$(LIBRARY_NAME).a
INSTALL_DIR  := TurnLeftLib

library := libturnleft.a
includes := -I$(CURDIR)/../

UTILS_OBJECTS = $(patsubst %.cpp, %.o, $(wildcard Utils/*.cpp))
EXCEPTIONS_OBJECTS = $(patsubst %.cpp, %.o, $(wildcard Exceptions/*.cpp))

UTILS_HEADERS := $(wildcard Utils/*.h)
UTILS_INSTALL := /usr/local/include/$(INSTALL_DIR)/Utils/

EXCEPTIONS_HEADERS := $(wildcard Exceptions/*.h)
EXCEPTIONS_INSTALL := /usr/local/include/$(INSTALL_DIR)/Exceptions/


all : $(library)

$(library): | $(EXCEPTIONS_OBJECTS) $(UTILS_OBJECTS) 
	ar -crf $(LIB_FILENAME) $(EXCEPTIONS_OBJECTS) $(UTILS_OBJECTS)

clean: clean-this clean-subs

Exceptions/%.o :
	cd Exceptions && $(MAKE) all

Utils/%.o :
	cd Utils && $(MAKE) all

clean-this:
	rm -f $(LIB_FILENAME)

clean-subs:
	cd Exceptions && $(MAKE) clean
	cd Utils && $(MAKE) clean

install:
	mkdir -p $(EXCEPTIONS_INSTALL)
	mkdir -p $(UTILS_INSTALL)
	cp $(UTILS_HEADERS) $(UTILS_INSTALL)
	cp $(EXCEPTIONS_HEADERS) $(EXCEPTIONS_INSTALL)
	cp $(LIB_FILENAME) /usr/local/bin/


uninstall:
	rm -rf $(UTILS_INSTALL)
	rm -rf $(EXCEPTIONS_INSTALL)
	rm -f /usr/local/bin/$(LIB_FILENAME)

test-output:
	@echo $(UTILS_OBJECTS)
	@echo $(EXCEPTIONS_OBJECTS)

.PHONY: utils exceptions
