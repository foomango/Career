CXX := g++
CXXFLAGS += -g -I.
LDFLAGS += 

TARGETS := test_gentree test_genstack

all: $(TARGETS)

test_gentree: tree.o test_gentree.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

test_genstack: test_genstack.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: all clean

clean:
	$(RM) *.o $(TARGETS)
