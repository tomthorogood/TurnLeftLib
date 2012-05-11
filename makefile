COMPILE_DEBUG = g++ -g
WEBSERVER_DEVEL = -lwthttp
WEBSERVER_PRODUCTION = -lwtfcgi $(WEBSERVER_DEVEL)
INCLUDES = -I/home/tom/dev/
TESTS = "commonwords" "explosion" "ptrarray" "wordaggregator" "hungryvector"
TEST_SUFFIX = "_test.cpp"

tests:
	echo $(TESTS);
	for f in $(TESTS);
	do \
		echo $$f ;\
		$(COMPILE_DEBUG) $(INCLUDES) tests/$$f$(TEST_SUFFIX) -o $$f ; \
	done

commonwords_test:
	$(COMPILE_DEBUG) $(INCLUDES) tests/commonwords_test.cpp -o commonwords;
	cp tests/commonwords.txt .

mtest:
	for x in 1 2 3 4 5; \
	do \
		echo $$x ;\
	done

clean:
	rm commonwords*
