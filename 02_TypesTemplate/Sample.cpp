#include <iostream>

template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
	std::cout << "argsȣ��" << sizeof...(args) << std::endl;
	std::cout <<"typeȣ��" << sizeof...(Types) << std::endl;
}

int main() {
	print(1, 3.1,1, "abc");
}