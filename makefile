export CXX=gcc
export LDFLAGS= -ljsoncpp 
export CXXFLAGS=-std=gnu++11 
export OUT=out
export BINARY=battle_main
export TEST=dal nullable

export SUBDIRS=\
.              \
apps           \
services       \
dal            

.PHONY: all clean binary test single-test 

all : binary test  

binary : $(BINARY:%=$(OUT)/%) 

test : $(TEST:%=$(OUT)/%)

single-test : $(OUT)/$(test)

clean :
	rm -rf out

$(OUT) :
	mkdir -p $@

$(BINARY:%=$(OUT)/%) : $(OUT) $(BINARY:%=$(OUT)/%.o)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

LDFLAGS+=-lgtest -lgmock_main

$(TEST:%=$(OUT)/%) : $(OUT) $(OUT)/%
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BINARY:%=$(OUT)/%.o) : launcher
	$(MAKE) -C $<

$(TEST) : tst
	$(MAKE) $@ -C $<
