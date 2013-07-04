CXX := g++
CXXFLAGS += -g -I../../common
LDFLAGS += 

TARGETS := main main2

all: $(TARGETS)

$(TARGETS): %: %.o ../../common/tree.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: all clean

clean:
	$(RM) $(TARGETS) *.o
