CXX := g++
CXXFLAGS := -O3
LDFLAGS := 

TARGETS := $(shell ls *.cc | tr '\n' ' ' |tr -d '.cc')

all: $(TARGETS)

$(TARGETS): %: %.o
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: all clean

clean:
	$(RM) $(TARGETS) *.o
