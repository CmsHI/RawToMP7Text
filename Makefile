CXX=g++
CXXFLAGS=-Wall -g

test/test :
	$(CXX) $(CXXFLAGS) -I./include ./src/DefineLinks.cc ./test/tests.cc -o test/testGlobal
