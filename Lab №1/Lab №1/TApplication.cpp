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
		std::cout << "\n <1> - ������ �� �������\n <2> - ������ � ������������ ��������\n <3> - ������ �� ������\n";
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
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "\n << ������ � ������������ �������� >>\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "\n <1> - �������� �������� ��������\n <2> - �������� ������� � ������\n <3> - �������� �������� ��������\n <4> - ������� ������� �� �������\n <5> - ������� ������ �������\n";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " <0> - ��������� � ������� ����\n";
		break;

	case 4:
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "\n << ������ �� ������ >>\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "\n <1> - �������� ������� � ����\n <2> - ������� ��������� �������\n <3> - �������� ��������� �������\n <4> - ������������� �������\n";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " <0> - ��������� � ������� ����\n";
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
			DynamicArrayMenu();
			break;
		case '3':
			StackMenu();
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
			std::cout << "���� ��� �������� � ������ ������ � ���������� �������.\n";
			system("pause");
			break;

		case '2':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			List.add_end(data);
			std::cout << "���� ��� �������� � ����� ������ � ���������� �������.\n";
			system("pause");
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
				break;
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
				std::cout << "���� ��� �������� � ����� ������.\n";
			else if (index < 0)
				std::cout << "���� ��� �������� � ������ ������.\n";
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
			std::cout << "������� ������� (������) ����, ������� ����� ������� (0 - " << List.getsize()-1 << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			SetConsoleTextAttribute(hConsole, 14);
			if (index < 0 || index >= List.getsize()) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "������ �������� ������!\n";
			}
			else {
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << "���� �� ������� ";
				SetConsoleTextAttribute(hConsole, 14);
				std::cout << "'" << index << "'";
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << " ��� �����!\n";
			}
			List.erase(index);
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
	Menu(4);
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
			Stack.add_end(data);
			std::cout << "������� ��� ������ � ����!\n";
			system("pause");
			break;

		case '2':
			system("cls");
			if (Stack.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "���� ����!";
				break;
			}
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "������� ��� ����� �� �����!\n";
			Stack.delete_end();
			system("pause");
			break;

		case '3':
			system("cls");
			if (Stack.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "���� ����!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������ ���������� �������� �����: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << Stack[Stack.getsize() - 1] << "\n\n";
			system("pause");
			break;

		case '4':
			break;

		default:
			break;
		}
		Menu(4);
	}

	return 0;

	return 0;
}

int TApplication::DynamicArrayMenu() {
	Menu(3);
	bool x = true; short index = 0, arrsize = Array.getsize();
	int data = 0;
	while (x) {
		switch (_getch()) {
		case '0':
			x = false;
			break;

		case '1':
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "������ ����!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������ ��������, �������� �������� ����� �������� (0 - " << arrsize-1 << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			if (index > arrsize-1 || index < 0) {
				std::cout << "������ �������� ������!\n";
				system("pause");
				break;
			}

			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "�������� �������� ��� ��������� ��������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << Array[index] << "\n";
			system("pause");
			break;

		case '2':
			system("cls");
			arrsize = Array.getsize();
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������� ������ �������� (0 - " << arrsize << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			if (index > arrsize || index < 0) {
				std::cout << "������ �������� ������!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� �������� ������ ��������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			Array.add(index, data);
			std::cout << "����� ������� ��� ������� ��������!\n";
			system("pause");
			break;

		case '3':
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "������ ����!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������ ��������, �������� �������� ����� �������� (0 - " << arrsize - 1 << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "������ �������� ������!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ����� �������� �������� ��� ��������� ��������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			Array[index] = data;
			std::cout << "�������� ��������!";
			system("pause");
			break;

		case '4':
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "������ ����!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������� ������� ��������, ������� ����� ������� (0 - " << arrsize - 1 << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "������ �������� ������!\n";
				system("pause");
				break;
			}
			Array.remove(index);
			std::cout << "������� �� ��������� ������� ��� ����� �� �������!\n";
			system("pause");
			break;

		case '5':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "������ �������: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << Array.getsize() << "\n";
			system("pause");
			break;

		default:
			continue;
			break;
		}
		Menu(3);
	}

	return 0;
}

TApplication::~TApplication() {
}