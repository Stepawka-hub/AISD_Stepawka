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
		std::cout << "\n << ���� >>\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "\n <1> - ������ �� �������\n <2> - ������ �� ������\n <3> - ������ � ������������ ��������\n";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " <0> - ����� �� ���������\n";
		break;

	case 2:
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "\n << ������ �� ������� >>\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "\n <1> - �������� ���� � ������ ������\n <2> - �������� ���� � ����� ������\n <3> - ������� ���� �� ������ ������\n <4> - ������� ���� � ����� ������\n <5> - ������� ������ ���� �� �������\n <6> - �������� ���� �� �������\n <7> - ������� ���� �� �������\n";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " <0> - ��������� � ������� ����\n";
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
			std::cout << "������� ������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			List.add_top(data);
			break;

		case '2':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			List.add_end(data);
			break;

		case '3':
			system("cls");
			if (List.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "������ ����!";
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "���� � ������ ������ ��� �����!\n";
			List.delete_top();
			system("pause");
			break;

		case '4':
			system("cls");
			if (List.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "������ ����!";
			}
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "���� � ����� ������ ��� �����!\n";
			List.delete_end();
			system("pause");
			break;

		case '5':
			system("cls");
			if (List.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "������ ����!\n";
				system("pause");
				break;
			}
			else {
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << "������� ������ ������������� ���� (0 - " << List.getsize() - 1 << "): ";
				SetConsoleTextAttribute(hConsole, 14);
				std::cin >> index;
			}

			if (index < 0 || index >= List.getsize()) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "�� ������� �������� ������!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������ ����: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << List[index] << "\n\n";
			system("pause");
			break;

		case '6':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������� (������) ������ ����: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			List.insert(index, data);
			SetConsoleTextAttribute(hConsole, 14);
			if (index + 1 > List.getsize())
				std::cout << "�������� ������. ���� ��� �������� � ����� ������.\n";
			else if (index < 0)
				std::cout << "�������� ������. ���� ��� �������� � ������ ������.\n";
			else {
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << "���� ��� �������� �� ������� ";
				SetConsoleTextAttribute(hConsole, 14);
				std::cout << "'" << index << "'" << "\n";
			}
			system("pause");
			break;

		case '7':
			system("cls");
			if (List.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "������ ����! �������� ���� �� ������� ����������!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������� (������) ����, ������� ����� �������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			List.erase(index);
			SetConsoleTextAttribute(hConsole, 14);
			if (index + 1 > List.getsize())
				std::cout << "�������� ������. ��� ����� ���� � ����� ������.\n";
			else if (index < 0)
				std::cout << "�������� ������. ��� ����� ���� � ������ ������.\n";
			else {
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << "���� �� ������� ";
				SetConsoleTextAttribute(hConsole, 14);
				std::cout << "'" << index << "'" << "\n";
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << " ��� �����!";
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
	std::cout << "\n << ������ �� ������ >>\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\n <1> - �������� ���� � ������ ������\n <2> - �������� ���� � ����� ������\n <3> - ������� ���� ������� ������\n <4> - ������� ���� � ����� ������\n <5> - ������� ������ ���� �� �������";
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