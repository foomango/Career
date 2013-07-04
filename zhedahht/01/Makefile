CXX := g++
CXXFLAGS := -g -I../../common
LDFLAGS := ../../common/tree.o

TARGETS := main
all: $(TARGETS)

$(TARGETS): %: %.o
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS)

%.o: %.c
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: all clean

clean:
	$(RM) $(TARGETS) *.o
