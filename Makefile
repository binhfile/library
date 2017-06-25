all:
	$(CXX) -pthread -std=c++11 -Wall -Wextra test/test.cpp -o test

test:
	 ./test || exit 1