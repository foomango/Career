CXX := g++
CXXFLAGS := -g
LDFLAGS := 

TARGETS := $(shell ls *.cc | tr '\n' ' ' |sed 's/\.cc/\.elf/g')

all: $(TARGETS)

%.elf: %.o
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: all clean

clean:
	$(RM) $(TARGETS) *.o
