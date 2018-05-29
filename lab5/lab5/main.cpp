#include "Deque.h"
#include "Empty_queue_exception.h"

#include <string.h>

template<typename T>
T min(const T a, const T b, const T c) {
	T min;
	min = a < b ? a : b;
	min = min < c ? min : c;
	return min;
}

const char * min(const char* a, const char* b, const char* c) {
	const char * tmp = strcmp(a, b) < 0 ? a : b;
	const char * result = strcmp(tmp, c) < 0 ? tmp : c;
	return result;
}

int main() {
	Deque<int> deque;
	deque.put(10);
	deque.put(2);
	deque.put(3);
	std::cout << min(5, 9, 4) << std::endl;
	std::cout << min("hghg","rrr","aer") << std::endl;
	std::cout << deque << std::endl;
	std::cin.get();
}