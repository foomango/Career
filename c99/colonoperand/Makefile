CXX := gcc
CXXFLAGS := -g
LDFLAGS := 

TARGETS := $(shell ls *.c | tr '\n' ' ' |sed 's/\.c/\.elf/g')

all: $(TARGETS)

%.elf: %.o
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS)

%.o: %.c
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: all clean

clean:
	$(RM) $(TARGETS) *.o
