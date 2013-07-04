CXX := g++
CXXFLAGS := -g -I../../common
LDFLAGS := 

TARGETS := main
all: $(TARGETS)

$(TARGETS): %: %.o
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: all clean

clean:
	$(RM) $(TARGETS) *.o
