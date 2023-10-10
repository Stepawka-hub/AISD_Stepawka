#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "TApplication.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

TApplication::TApplication() {
}

int TApplication::Menu(int status) {
	system("cls");
	switch (status) {
	case 1:
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "\n << Меню >>\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "\n <1> - Работа со списком\n <2> - Работа со стеком\n <3> - Работа с динамическим массивом\n";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " <0> - Выход из программы\n";
		break;

	case 2:
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "\n << Работа со списком >>\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "\n <1> - Добавить узел в начало списка\n <2> - Добавить узел в конец списка\n <3> - Удалить узел из начала списка\n <4> - Удалить узел с конца списка\n <5> - Вывести данные узла по индексу\n <6> - Добавить узел по индексу\n <7> - Удалить узел по индексу\n";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " <0> - Вернуться в главное меню\n";
		break;

	case 3:
		break;

	case 4:
		break;
	}

	return 0;
}

int TApplication::Executor() {
	while (true) {
		Menu(1);
		switch (_getch()) {
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

int TApplication::LinkedListMenu() {
	Menu(2);
	bool x = true; short index = 0;
	int data;
	while (x) {
		switch (_getch()) {
		case '0':
			x = false;
			break;

		case '1':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Введите данные: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			List.add_top(data);
			break;

		case '2':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Введите данные: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			List.add_end(data);
			break;

		case '3':
			system("cls");
			if (List.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Список пуст!";
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Узел с начала списка был удалён!\n";
			List.delete_top();
			system("pause");
			break;

		case '4':
			system("cls");
			if (List.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Список пуст!";
			}
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "Узел с конца списка был удалён!\n";
			List.delete_end();
			system("pause");
			break;

		case '5':
			system("cls");
			if (List.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Список пуст!\n";
				system("pause");
				break;
			}
			else {
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << "Укажите индекс возвращаемого узла (0 - " << List.getsize() - 1 << "): ";
				SetConsoleTextAttribute(hConsole, 14);
				std::cin >> index;
			}

			if (index < 0 || index >= List.getsize()) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Вы указали неверный индекс!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Данные узла: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << List[index] << "\n\n";
			system("pause");
			break;

		case '6':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Укажите позицию (индекс) нового узла: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Введите данные: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			List.insert(index, data);
			SetConsoleTextAttribute(hConsole, 14);
			if (index + 1 > List.getsize())
				std::cout << "Неверный индекс. Узел был добавлен в конец списка.\n";
			else if (index < 0)
				std::cout << "Неверный индекс. Узел был добавлен в начало списка.\n";
			else {
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << "Узел был добавлен на позицию ";
				SetConsoleTextAttribute(hConsole, 14);
				std::cout << "'" << index << "'" << "\n";
			}
			system("pause");
			break;

		case '7':
			system("cls");
			if (List.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Список пуст! Удаление узла по индексу невозможно!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Укажите позицию (индекс) узла, который нужно удалить: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			List.erase(index);
			SetConsoleTextAttribute(hConsole, 14);
			if (index + 1 > List.getsize())
				std::cout << "Неверный индекс. Был удалён узел с конца списка.\n";
			else if (index < 0)
				std::cout << "Неверный индекс. Был удалён узел с начала списка.\n";
			else {
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << "Узел на позиции ";
				SetConsoleTextAttribute(hConsole, 14);
				std::cout << "'" << index << "'" << "\n";
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << " был удалён!";
			}
			system("pause");
			break;

		default:
			break;
		}
		Menu(2);
	}

	return 0;
}

int TApplication::StackMenu() {
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\n << Работа со стеком >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - Добавить узел в начало списка\n <2> - Добавить узел в конец списка\n <3> - Удалить узел сначала списка\n <4> - Удалить узел с конца списка\n <5> - Вывести данные узла по индексу";
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