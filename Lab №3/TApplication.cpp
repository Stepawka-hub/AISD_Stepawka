#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "TApplication.h"

TApplication::TApplication() {
}

int TApplication::Menu(int status) {
	system("cls");
	switch (status) {
	case 1:
		std::cout << "\n\x1B[93m << Главное меню >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - Работа с двоичным деревом\n <2> - Работа с АВЛ деревом\033[0m\n";
		std::cout << "\x1B[91m <0> - Выход из программы\033[0m\n";
		break;

	case 2:
		std::cout << "\n\x1B[93m << Работа с двоичным деревом >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - Считать дерево с файла\n <2> - Вывести элементы дерева на экран\033[0m\n";
		std::cout << "\x1B[91m <0> - Вернуться в главное меню\033[0m\n";
		break;

	case 3:
		std::cout << "\n\x1B[93m << Работа с АВЛ деревом >>\033[0m\n";
		std::cout << "\n\x1B[93m << Основные функции >>\033[0m";
		std::cout << "\n \x1B[96m<1> - Построить дерево на основе бинарного\n <2> - Алгоритм вставки\n <3> - Алгоритм поиска\n <4> - Алгоритм удаления\033[0m\n";
		
		std::cout << "\n\x1B[93m << Виды обходов >>\033[0m";
		std::cout << "\n \x1B[96m<5> - Обход в ширину\n <6> - Прямой обход\n <7> - Центрированный обход\n <8> - Обратный обход\033[0m\n";
		std::cout << "\x1B[91m <0> - Вернуться в главное меню\033[0m\n";
		break;
	}

	return 0;
}

int TApplication::Executor() {
	int key;
	while (true) {
		Menu(1);
		std::cout << "\n\x1B[93m Введите нужный пункт меню: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			return 0;
		case 1:
			BinaryMenu();
			break;
		case 2:
			AVLMenu();
			break;
		default:
			break;
		}
	}

	return 0;
}

int TApplication::BinaryMenu() {
	Menu(2);
	std::ifstream input("parsing.txt");
	std::string line;
	bool x = true; short index = 0;
	int data = 0, key;
	while (x) {
		std::cout << "\n\x1B[93m Введите нужный пункт меню: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			if (input.is_open())
				std::getline(input, line);
			else
				std::cout << "\x1B[93mФайл не удалось открыть!\n";
			BTree.Parsing(line);
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[93m";
			BTree.BypassInDepth(BTree.GetRoot());
			std::cout << "\n";
			system("pause");
			break;

		default:
			break;
		}

		Menu(2);
	}

	return 0;
}

int TApplication::AVLMenu() {
	Menu(3);
	bool x = true; short index = 0;
	unsigned int data = 0, key;
	while (x) {
		std::cout << "\n\x1B[93m Введите нужный пункт меню: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			AVLTree.create(BTree);
			std::cout << "\x1B[96m*АВЛ дерево было создано на основе бинарного!*\n\x1B[93m";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[93mВведите значение (ключ) нового узла:\x1B[96m ";
			std::cin >> data;
			AVLTree.insert(data);
			std::cout << "\x1B[96mУзел был успешно добавлен!\n";
			system("pause");
			break;

		case 3:
			system("cls");
			std::cout << "\x1B[93mВведите ключ узла, который нужно найти:\x1B[96m ";
			std::cin >> data;
			AVLTree.search(data);
			system("pause");
			break;

		case 4:
			system("cls");
			std::cout << "\x1B[93mВведите ключ узла, который нужно удалить:\x1B[96m ";
			std::cin >> data;
			AVLTree.remove(data);
			system("pause");
			break;

		case 5:
			system("cls");
			std::cout << "\x1B[93m*Обход в ширину*\n";
			system("pause");
			break;

		case 6:
			system("cls");
			std::cout << "\x1B[93m*Прямой обход*\x1B[96m\n";
			AVLTree.orderCLR();
			std::cout << "\n";
			system("pause");
			break;

		case 7:
			system("cls");
			std::cout << "\x1B[93m*Центрированный обход*\x1B[96m\n";
			AVLTree.orderLCR();
			std::cout << "\n";
			system("pause");
			break;

		case 8:
			system("cls");
			std::cout << "\x1B[93m*Обратный обход*\x1B[96m\n";
			AVLTree.orderLRC();
			std::cout << "\n";
			system("pause");
			break;

		default:
			break;
		}

		Menu(3);
	}

	return 0;
}

TApplication::~TApplication() {
}