#include <iostream>
#include <fstream>
#include <string>


bool overwrite(const std::string path, const std::string str);


int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1. Запись в файл и считывание из файла
	std::ofstream out;
	std::ifstream in;
	std::string path = "home30.txt";

	std::cout << "Задача 1.\n";

	out.open(path,std::ios::app);

	if (out.is_open()) {
		std::string str;
		while (str != "end") {
			std::cout << "-> ";
			std::getline(std::cin, str);
			out << str << '\n';
		}
		std::cout << std::endl;
	}
	else
		std::cout << "ОШИБКА!!!\n\n";

	out.close();

	in.open(path);

	if (in.is_open()) {
		std::cout << "Содержимое файла:\n";
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
	}
	else
		std::cout << "Ошибка!!!\n\n";

	in.close();

	if (!remove(path.c_str()))
		std::cout << "Файл удален!\n\n";
	else
		std::cout << "Ошибка удаления файла!\n\n";


	// Задача 2. Функция overwrite

	std::string path2 = "home30_2.txt";
	std::string str;
	std::cout << "Введите строку - >";
	std::getline(std::cin, str);

	if (overwrite(path2, str))
		std::cout << "Файл изменен!\n\n";
	else
		std::cout << "Файла не существует.\n\n";


	return 0;
}


bool overwrite(const std::string path, const std::string str) {

	std::ifstream in;
	std::ofstream out;

	in.open(path);
	if (in.is_open()) {

		in.close();

		out.open(path);

		if (out.is_open()) {

			out << str << '\n';
		}
		else
			std::cout << "Ошибка!\n\n";

		out.close();

		return true;
	}

	return false;
}