CXX := g++
CXXFLAGS := -g -I.
LDFLAGS := 

all: main

main.o: 

main: main.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: all clean

clean:
	$(RM) main *.o
