CXX?=g++
CXXFLAGS=-std=c++14 -Wall -Wextra -Wpedantic -g
DIR=$(USER)

main: input.o main.o output.o cache_video.o
	$(CXX) $(CXXFLAGS) $^ -o $@

submision: all
	mkdir $(DIR); ./main $(DIR)
