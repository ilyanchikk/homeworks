#include <Windows.h>
#include <iostream>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <fstream>

int* create_arr(int size);
void fil_arr(int* array, int elements);
void deletearr(int* array);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size{ 0 };
	int x{ 0 };
	std::cout << "Введите количество элементов массива: ";
	std::cin >> size;
	std::ofstream outfile("out.txt");
	if (outfile.is_open()) {
		int* int_ptr = create_arr(size);
		fil_arr(int_ptr, size);
		outfile << size << std::endl;
		for (int el = size - 1; el >= 0; --el) {
			outfile << int_ptr[el] << ' ';
		}
		deletearr(int_ptr);
	}
	outfile.close();
}
int* create_arr(int size) {
	return new int[size] {};
}
void fil_arr(int* array, int elements) {
	for (int el = 0; el < elements; ++el) {
		std::cout << "Введите элемент arr: " << '[' << el << ']';
		std::cin >> array[el];
		std::cout << std::endl;
	}
}
void deletearr(int* array) {
	delete[] array;
}