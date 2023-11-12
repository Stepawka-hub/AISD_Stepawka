#include <iostream>
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
		std::cout << "\n \x1B[96m<1> - Считать дерево с файла\n <2> - Вывести элементы дерева на экран\n <3> - Алгоритм вставки\n <4> - Алгоритм поиска\n <5> - Алгоритм удаления\033[0m\n";
		
		std::cout << "\n\x1B[93m << Виды обходов >>\033[0m";
		std::cout << "\n \x1B[96m<6> - Обход в ширину\n <7> - Прямой обход\n <8> - Центрированный обход\n <9> - Обратный обход\033[0m\n";
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
			std::cout << "\x1B[93m*Дерево считывается с файла*\n";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[93m*Дерево выводится в консоль*\n";
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
			std::cout << "\x1B[93m*Дерево считывается с файла*\n";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[93m*Дерево выводится на экран*\n";
			system("pause");
			break;

		case 3:
			system("cls");
			std::cout << "\x1B[93m*Алгоритм вставки*\n";
			system("pause");
			break;

		case 4:
			system("cls");
			std::cout << "\x1B[93m*Алгоритм поиска*\n";
			system("pause");
			break;

		case 5:
			system("cls");
			std::cout << "\x1B[93m*Алгоритм удаления*\n";
			system("pause");
			break;

		case 6:
			system("cls");
			std::cout << "\x1B[93m*Обход в ширину*\n";
			system("pause");
			break;

		case 7:
			system("cls");
			std::cout << "\x1B[93m*Прямой обход*\n";
			system("pause");
			break;

		case 8:
			system("cls");
			std::cout << "\x1B[93m*Центрированный обход*\n";
			system("pause");
			break;

		case 9:
			system("cls");
			std::cout << "\x1B[93m*Обратный обход*\n";
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