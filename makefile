export CXX=gcc
export LDFLAGS= -ljsoncpp
export CXXFLAGS=-std=gnu++11 
export OUT=out
export BINARY=battle_main
export SUBDIRS=\
.              \
apps           \
services       \
dal            \
test

.PHONY: all clean

all :  $(BINARY:%=$(OUT)/%) $(TEST:%=$(OUT)/%)

clean :
	rm -rf out

$(OUT) :
	mkdir -p $@

$(BINARY:%=$(OUT)/%) : $(OUT) $(BINARY:%=$(OUT)/%.o)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(TEST:%=$(OUT)/%) : $(OUT) $(TEST:%=$(OUT)/%.o)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BINARY:%=$(OUT)/%.o) : launcher
	$(MAKE) -C $<

$(TEST:%=$(OUT)/%.o) : test
	$(MAKE) -C $<
