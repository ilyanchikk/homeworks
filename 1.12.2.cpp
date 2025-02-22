#include <Windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

int* create_arr(int size);
void print_arr(int* array, int elements);
void deletearr(int* array);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size{ 0 };
	int x{ 0 };
	std::ifstream infile("in2.txt");
	if (infile.is_open()) {
		infile >> size;
		int* int_ptr = create_arr(size);
		for (int el = size - 1; el >= 0; --el) {
			infile >> int_ptr[el];
		}
		print_arr(int_ptr, size);
		deletearr(int_ptr);
	}
	infile.close();
}
int* create_arr(int size) {
	return new int[size] {};
}
void print_arr(int* array, int elements) {
	for (int el = 0; el < elements; ++el) {
		std::cout << array[el] << ' ';
	}
	std::cout << std::endl;
}
void deletearr(int* array) {
	delete[] array;
}