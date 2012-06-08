LIBRARY_NAME = turnleft
LIB_FILENAME = lib$(LIBRARY_NAME).a

HEADER_INSTALL_DIR = /usr/local/include/TurnLeftLib
LIB_INSTALL_DIR = /usr/local/lib

OBJECTS_DIR = obj

UTILS_DIR = utils
UTILS_HEADERS = $(wildcard $(UTILS_DIR)/src/*.h)
UTILS_OBJECTS = $(wildcard $(UTILS_DIR)/$(OBJECTS_DIR)/*.o)

EXCEPTIONS_DIR = exceptions
EXCEPTIONS_HEADERS = $(wildcard $(EXCEPTIONS_DIR)/src/*.h)
EXCEPTIONS_OBJECTS = $(wildcard $(EXCEPTIONS_DIR)/$(OBJECTS_DIR)/*.o)

ABSTRACT_HEADERS = $(wildcard global_headers/*)
ALL_OBJECTS = $(UTILS_OBJECTS) $(EXCEPTIONS_OBJECTS)

SUBS = $(UTILS_DIR) $(EXCEPTIONS_DIR)

$(LIB_FILENAME): exceptions utils
	ar -crf $(LIB_FILENAME) $(UTILS_OBJECTS) $(EXCEPTIONS_OBJECTS)

exceptions: $(EXCEPTIONS_OBJECTS)
	cd $(EXCEPTIONS_DIR)/ && $(MAKE)

utils : $(UTILS_OBJECTS)
	cd $(UTILS_DIR)/ && $(MAKE)

install: | $(HEADER_INSTALL_DIR) $(LIB_INSTALL_DIR) $(HEADER_INSTALL_DIR)/src
	cp $(LIB_FILENAME) $(LIB_INSTALL_DIR)

	for f in $(EXCEPTIONS_HEADERS) $(UTILS_HEADERS); do \
		cp $$f $(HEADER_INSTALL_DIR)/src; \
		done;
	for f in $(ABSTRACT_HEADERS); do \
		cp $$f $(HEADER_INSTALL_DIR)/; \
		done;

$(HEADER_INSTALL_DIR) :
	mkdir -p $@

$(LIB_INSTALL_DIR) :
	mkdir -p $@

$(HEADER_INSTALL_DIR)/src :
	mkdir -p $@

clean: clean-this clean-subs

clean-this:
	rm -f $(LIB_FILENAME)

clean-subs:
	cd $(UTILS_DIR) && $(MAKE) clean
	cd $(EXCEPTIONS_DIR) && $(MAKE) clean

uninstall:
	rm -rf $(HEADER_INSTALL_DIR)/
	rm -f $(LIB_INSTALL_DIR)/$(LIB_FILENAME)

test-output:
	echo $(UTILS_OBJECTS)
	echo $(ALL_OBJECTS)

.PHONY: utils exceptions
