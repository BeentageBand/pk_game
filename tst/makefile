SRCS=$(wildcard *.cc)
.PHONY : all clean $(MAKECMDGOALS:%=%.cmd)

all : $(SRCS:%.cc=../$(OUT)/%.o)
	$(ECHO) "compiling all-tst"

clean : 
	$(ECHO) "clean all-tst"
	rm -rf $(SRCS:%=$(OUT)/%.o)

%.cmd : ../$(OUT)/%.o
	$(ECHO) "compiling $@-tst"

../$(OUT)/%.o : %.cc
	$(CXX) $(CXXFLAGS) $(SUBDIRS:%= -I ../%) -o $@ -c $^
