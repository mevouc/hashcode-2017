CXX?=g++
CXXFLAGS=-std=c++14 -Wall -Wextra -Wpedantic -g
DIR=$(USER)

main: input.o main.o output.o cache_video.o users.o
	$(CXX) $(CXXFLAGS) $^ -o $@

submission: main
	mkdir $(DIR); ./main $(DIR) < in/kittens.in
