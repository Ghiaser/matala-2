323889451
ghia48.serhan@gmail.com
# Compiler and compiler flags
CXX = g++
CXXFLAGS =  -g

# Define all executables
TARGETS = tests_add_sub tests_equal_inequal tests_inc_dec tests_multiply tests_print demo

# Default rule
all: $(TARGETS)

# Rule for each executable
tests_add_sub: Graph.o tests_add_sub.o
	$(CXX) $(CXXFLAGS) -o $@ $^

tests_equal_inequal: Graph.o tests_equal_inequal.o
	$(CXX) $(CXXFLAGS) -o $@ $^

tests_inc_dec: Graph.o tests_inc_dec.o
	$(CXX) $(CXXFLAGS) -o $@ $^

tests_multiply: Graph.o tests_multiply.o
	$(CXX) $(CXXFLAGS) -o $@ $^

tests_print: Graph.o tests_print.o
	$(CXX) $(CXXFLAGS) -o $@ $^

demo: Demo.o Graph.o Algorithms.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to make object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
clean:
	rm -f *.o $(TARGETS)

# Rule to ensure these targets are treated as commands
.PHONY: all clean
