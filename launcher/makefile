SRCS=$(wildcard *.cc)

.PHONY : all

all : $(SRCS:%.cc=$(OUT)/%.o)

$(OUT)/%.o : %.cc
		$(CXX) $(CXXFLAGS) $(SUBDIRS:%=-I ../%) -o $@ -c $^
