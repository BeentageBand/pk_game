export CXX=gcc
export CPP=g++
export LDFLAGS= -ljsoncpp 
export CXXFLAGS=-std=gnu++11 
export OUT=out
export BINARY=battle_main
export TEST=dal nullable
export SUBDIRS=apps dal services utils .
export LDDIRS=
ifndef test
test=dummy-test
endif

TEST_LDFLAGS=-lgmock_main -lgtest -lgmock

.PHONY: all clean binary test single-test 

all : binary test  

binary : $(OUT) $(BINARY:%=$(OUT)/%) 

test : $(OUT) $(OUT)/unit-test 

single-test : $(OUT) $(OUT)/$(test)

clean :
	rm -rf out

$(OUT) :
	mkdir -p $@

$(TEST:%=$(OUT)/%.o) : tst 
	make -C $<
$(OUT)/$(test).o : tst/$(test).cc
	$(CXX) $(CXXFLAGS) $(SUBDIRS:%=-I %) -o $@ -c $<

$(OUT)/unit-test : $(TEST:%=$(OUT)/%.o)
	$(CPP) $(CXXFLAGS) $(LDFLAGS) $(TEST_LDFLAGS) $(SUBDIRS:%=-I %) -o $@ $^
$(OUT)/$(test) : $(OUT)/$(test).o
	$(CPP) $(CXXFLAGS) $(LDFLAGS) $(TEST_LDFLAGS) $(SUBDIRS:%=-I %) -o $@ $^
