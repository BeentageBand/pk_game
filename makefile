export CXX=gcc
export LDFLAGS=
export CXXFLAGS=-std=gnu++11 
export OUT=out
export BINARY=battle_main
export SUBDIRS=\
apps           \
meta           \
services       \
dal

.PHONY: all clean

all :  $(BINARY:%=$(OUT)/%)

clean :
	rm -rf out

$(OUT) :
	mkdir -p $@

$(BINARY:%=$(OUT)/%) : $(OUT) $(BINARY:%=$(OUT)/%.o)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BINARY:%=$(OUT)/%.o) : launcher
	$(MAKE) -C launcher

