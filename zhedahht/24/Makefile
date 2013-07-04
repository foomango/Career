CXX := g++
CXXFLAGS := -g 
LDFLAGS :=

TARGETS := main

all: $(TARGETS)

$(TARGETS): %: %.o
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS)

.PHONY: all clean

clean:
	$(RM) $(TARGETS) *.o
