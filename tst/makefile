SRCS=$(wildcard *.cc)
.PHONY : all clean $(MAKECMDGOALS:%=%.cmd)

all : $(SRCS:%.cc=../$(OUT)/%.o)
	echo "compiling all-tst"

clean : 
	echo "clean all-tst"
	rm -rf $(SRCS:%=$(OUT)/%.o)

%.cmd : ../$(OUT)/%.o
	$(ECHO) "compiling $@-tst"

../$(OUT)/%.o : %.cc
	$(CPP) $(CXXFLAGS) $(SUBDIRS:%= -I ../%) -o $@ -c $^
