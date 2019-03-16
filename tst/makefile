SRCS=$(wildcard *.cc)
.PHONY : all clean $(SRCS:%.cc=%)

all : $(SRCS:%.cc=%)

$(SRCS:%.cc=%) : $(SRCS:%.cc=$(OUT)/%.o)
  
clean : 
	rm -rf $(SRCS:%=$(OUT)/%.o)

$(OUT)/%.o : %.cc
	$(CXX) $(CXXFLAGS) $(SUBDIRS:%= -I ../%) -o $@ -c $^
