#include <Windows.h>
#include <iostream>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <fstream>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream infile("in.txt");
	if (infile.is_open()) {
		std::string data{};
		while (infile >> data)
		{
			std::cout << data << std::endl;
		}
	}
	infile.close();
}

