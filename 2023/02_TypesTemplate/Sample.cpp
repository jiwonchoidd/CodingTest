#include <iostream>

template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
	std::cout << "args호출" << sizeof...(args) << std::endl;
	std::cout <<"type호출" << sizeof...(Types) << std::endl;
}

int main() {
	print(1, 3.1,1, "abc");
}