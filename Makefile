CXX?=g++
CXXFLAGS=-std=c++14 -Wall -Wextra -Wpedantic
DIR=$(USER)

all: main

submision: all
	mkdir $(DIR); ./main $(DIR)
