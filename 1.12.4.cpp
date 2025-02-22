#include <Windows.h>
#include <iostream>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <fstream>

int** create_arr(int rows, int columns);
void deletearr(int** array, int rows);
void printarr(int** array, int rows, int columns);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int rows{ 0 };
	int columns{ 0 };
	std::ifstream infile("in4.txt");
	if (infile.is_open()) {
		infile >> rows >> columns;
		int** int_ptr = create_arr(rows, columns);
		for (int row = 0; row < rows; ++row) {
			for (int column = columns - 1; column >= 0; --column) {
				infile >> int_ptr[row][column];
			}
		}
		printarr(int_ptr, rows, columns);
		deletearr(int_ptr, rows);
		infile.close();
	}
}
int** create_arr(int rows, int columns) {
	 int** array = new int*[rows];
	 for (int row = 0; row < rows; ++row) {
		 array[row] = new int[columns] {};
	 }
	 return array;
}
void printarr(int** array, int rows, int columns) {
	for (int row = 0; row < rows; ++row) {
		for (int column = 0; column < columns; ++column) {
			std::cout << array[row][column] << ' ';
		}
		std::cout << std::endl;
	}
}
void deletearr(int** array, int rows) {
	for (int arr = 0; arr < rows; ++array) {
		delete[] array[arr];
	}
	delete[] array;
}