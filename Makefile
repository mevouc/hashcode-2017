CXX?=g++
CXXFLAGS=-std=c++14 -Wall -Wextra -Wpedantic
DIR=$(USER)

main: input.o main.o output.o
	$(CXX) $(CXXFLAGS) $^ -o $@

submision: all
	mkdir $(DIR); ./main $(DIR)
