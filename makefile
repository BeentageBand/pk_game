export CXX=gcc
export CPP=g++
export TEST_DEPS=gmock_main gtest gmock
export DEPS=jsoncpp
export LDFLAGS=$(shell pkg-config --libs --static $(DEPS))
export CXXFLAGS=-std=gnu++11 $(shell pkg-config --cflags $(DEPS) $(TEST_DEPS)) 
export OUT=out
export BINARY=battle_main
export TEST=pkm-dal dal lru nullable
export SUBDIRS=apps dal services utils .
ifndef test
test=dummy-test
endif

TEST_LDFLAGS=$(shell pkg-config --libs --static $(TEST_DEPS))

.PHONY: all clean binary test single-test 

all : binary test  

binary : $(OUT) $(BINARY:%=$(OUT)/%) 

test : $(OUT) $(OUT)/unit-test 
	./$(OUT)/unit-test

single-test : $(OUT) $(OUT)/$(test)
	./$(OUT)/$(test)

clean :
	rm -rf out

$(OUT) :
	mkdir -p $@

$(TEST:%=$(OUT)/%.o) : tst 
	make -C $<

$(BINARY:%=$(OUT)/%) : $(BINARY:%=$(OUT)/%.o) 
	$(CXX) $(CXXFLAGS) $(LDFLAFS) $(SUBDIRS:%=-I %) -o $@ -c $<

$(BINARY:%=$(OUT)/%.o) : launcher
	make -C $<

$(OUT)/$(test).o : tst/$(test).cc
	$(CXX) $(CXXFLAGS) $(SUBDIRS:%=-I %) -o $@ -c $<

$(OUT)/unit-test : $(TEST:%=$(OUT)/%.o)
	$(CPP) $(CXXFLAGS) $(LDFLAGS) $(TEST_LDFLAGS) $(SUBDIRS:%=-I %) -o $@ $^
$(OUT)/$(test) : $(OUT)/$(test).o
	$(CPP) $(CXXFLAGS) $(LDFLAGS) $(TEST_LDFLAGS) $(SUBDIRS:%=-I %) -o $@ $^
