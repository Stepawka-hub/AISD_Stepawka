#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "TApplication.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

TApplication::TApplication() {
	keychange = -1;
}

int TApplication::Executor() {
	char a;
	while (true) {
		MainMenu();
		system("cls");
		switch (keychange) {
		case '0':
			return 0;
		case '1':
			LinkedListMenu();
			break;
		case '2':
			StackMenu();
			break;
		case '3':
			DynamicArrayMenu();
			break;
		default:
			break;
		}
	}

	return 0;
}

int TApplication::MainMenu() {
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\n << Меню >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - Работа со списком\n <2> - Работа со стеком\n <3> - Работа с динамическим массивом\n";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " <0> - Выход из программы\n";
	keychange = _getch();
	return 0;
}

int TApplication::LinkedListMenu() {
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\n << Работа со списком >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - Добавить узел в начало списка\n <2> - Добавить узел в конец списка\n <3> - Удалить узел из начала списка\n <4> - Удалить узел с конца списка\n";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " <0> - Вернуться в главное меню\n";
	
	bool x = true;
	double data;
	while (x) {
		switch (_getch()) {
		case '0':
			x = false;
			continue;
			break;

		case '1':
			system("cls");
			std::cout << "Введите данные (вещественное число): ";
			std::cin >> data;
			List.add_top(data);
			break;

		case '2':
			system("cls");
			std::cout << "Введите данные (вещественное число): ";
			std::cin >> data;
			List.add_end(data);
			break;

		case '3':
			system("cls");
			List.delete_top();
			break;

		case '4':
			system("cls");
			List.delete_end();
			break;

		default:
			continue;
			break;
		}
		LinkedListMenu();
	}

	return 0;
}

int TApplication::StackMenu() {
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\n << Работа со стеком >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - Добавить узел в начало списка\n <2> - Добавить узел в конец списка\n <3> - Удалить узел сначала списка\n <4> - Удалить узел с конца списка\n";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " <0> - Вернуться в главное меню\n";
	
	bool x = true;
	while (x) {
		switch (_getch()) {
		case '0':
			x = false;
			break;

		case '1':
			break;

		case '2':
			break;

		case '3':
			break;

		case '4':
			break;

		default:
			continue;
			break;
		}
	}

	return 0;
}

int TApplication::DynamicArrayMenu() {
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\n << Работа с динамическим >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - Добавить узел в начало списка\n <2> - Добавить узел в конец списка\n <3> - Удалить узел сначала списка\n <4> - Удалить узел с конца списка\n";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " <0> - Вернуться в главное меню\n";
	
	bool x = true;
	while (x) {
		switch (_getch()) {
		case '0':
			x = false;
			break;

		case '1':
			break;

		case '2':
			break;

		case '3':
			break;

		case '4':
			break;

		default:
			continue;
			break;
		}
	}

	return 0;
}

TApplication::~TApplication() {
}