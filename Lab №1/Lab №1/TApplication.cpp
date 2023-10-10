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
	std::cout << "\n << ���� >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - ������ �� �������\n <2> - ������ �� ������\n <3> - ������ � ������������ ��������\n";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " <0> - ����� �� ���������\n";
	keychange = _getch();
	return 0;
}

int TApplication::LinkedListMenu() {
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "\n << ������ �� ������� >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - �������� ���� � ������ ������\n <2> - �������� ���� � ����� ������\n <3> - ������� ���� �� ������ ������\n <4> - ������� ���� � ����� ������\n";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " <0> - ��������� � ������� ����\n";
	
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
			std::cout << "������� ������ (������������ �����): ";
			std::cin >> data;
			List.add_top(data);
			break;

		case '2':
			system("cls");
			std::cout << "������� ������ (������������ �����): ";
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
	std::cout << "\n << ������ �� ������ >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - �������� ���� � ������ ������\n <2> - �������� ���� � ����� ������\n <3> - ������� ���� ������� ������\n <4> - ������� ���� � ����� ������\n";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " <0> - ��������� � ������� ����\n";
	
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
	std::cout << "\n << ������ � ������������ >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - �������� ���� � ������ ������\n <2> - �������� ���� � ����� ������\n <3> - ������� ���� ������� ������\n <4> - ������� ���� � ����� ������\n";
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " <0> - ��������� � ������� ����\n";
	
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