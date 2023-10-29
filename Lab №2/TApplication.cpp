#include <iostream>
#include <string>
#include "TApplication.h"


TApplication::TApplication() {
}

int TApplication::Menu(int status) {
	system("cls");
	switch (status) {
	case 1:
		std::cout << "\n\x1B[93m << ���� >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - ������ �� �������\n <2> - ������ � ������������ ��������\n <3> - ������ �� ������\033[0m\n";
		std::cout << "\x1B[91m <0> - ����� �� ���������\033[0m\n";
		break;

	case 2:
		std::cout << "\n\x1B[93m << ������ �� ������� >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - �������� ���� � ������ ������\n <2> - �������� ���� � ����� ������\n <3> - ������� ���� �� ������ ������\n <4> - ������� ���� � ����� ������\n <5> - ������� ������ ���� �� �������\n <6> - �������� ���� �� �������\n <7> - ������� ���� �� �������\033[0m\n";
		std::cout << "\x1B[91m <0> - ��������� � ������� ����\033[0m\n";
		break;

	case 3:
		std::cout << "\n\x1B[93m << ������ � ������������ �������� >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - �������� �������� ��������\n <2> - �������� ������� � ������\n <3> - �������� �������� ��������\n <4> - ������� ������� �� �������\n <5> - ������� ������ �������\033[0m\n";
		std::cout << "\x1B[91m <0> - ��������� � ������� ����\033[0m\n";
		break;

	case 4:
		std::cout << "\n\x1B[93m << ������ �� ������ >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - �������� ������� � ����\n <2> - ������� ��������� �������\n <3> - �������� ��������� �������\n <4> - ������� ������ �����\033[0m\n";
		std::cout << "\x1B[91m <0> - ��������� � ������� ����\n";
		break;
	}

	return 0;
}

int TApplication::Executor() {
	int key;
	while (true) {
		Menu(1);
		std::cout << "\n\x1B[93m ������� ������ ����� ����: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			return 0;
		case 1:
			LinkedListMenu();
			break;
		case 2:
			DynamicArrayMenu();
			break;
		case 3:
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
	int data, key;
	while (x) {
		std::cout << "\n\x1B[93m ������� ������ ����� ����: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			std::cout << "\x1B[96m������� ������: \x1B[93m";
			std::cin >> data;
			List.add_top(data);
			std::cout << "���� ��� �������� � ������ ������ � ���������� �������.\n";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[96m������� ������: \x1B[93m";
			std::cin >> data;
			List.add_end(data);
			std::cout << "���� ��� �������� � ����� ������ � ���������� �������.\n";
			system("pause");
			break;

		case 3:
			system("cls");
			if (List.getsize() == 0) {
				std::cout << "\x1B[91m������ ����!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[93m���� � ������ ������ ��� �����!\n";
			List.delete_top();
			system("pause");
			break;

		case 4:
			system("cls");
			if (List.getsize() == 0) {
				std::cout << "\x1B[91m������ ����!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[93m���� � ����� ������ ��� �����!\n";
			List.delete_end();
			system("pause");
			break;

		case 5:
			system("cls");
			if (List.getsize() == 0) {
				std::cout << "\x1B[91m������ ����!\n";
				system("pause");
				break;
			}
			else {
				std::cout << "\x1B[96m������� ������ ������������� ���� (0 - " << List.getsize() - 1 << "): \x1B[93m";
				std::cin >> index;
			}

			if (index < 0 || index >= List.getsize()) {
				std::cout << "\x1B[91m�� ������� �������� ������!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96m������ ����: \x1B[93m";
			std::cout << List[index] << "\n\n";
			system("pause");
			break;

		case 6:
			system("cls");
			std::cout << "\x1B[96m������� ������� (������) ������ ����: \x1B[93m";
			std::cin >> index;
			std::cout << "\x1B[96m������� ������: \x1B[93m";
			std::cin >> data;
			List.insert(index, data);
			if (index + 1 > List.getsize())
				std::cout << "\x1B[96m���� ��� �������� � ����� ������.\n";
			else if (index < 0)
				std::cout << "\x1B[96m���� ��� �������� � ������ ������.\n";
			else
				std::cout << "\x1B[96m���� ��� �������� �� ������� \x1B[93m" << "'" << index << "'" << "\n";
			system("pause");
			break;

		case 7:
			system("cls");
			if (List.getsize() == 0) {
				std::cout << "\x1B[91m������ ����! �������� ���� �� ������� ����������!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96m������� ������� (������) ����, ������� ����� ������� (0 - " << List.getsize()-1 << "): \x1B[93m";
			std::cin >> index;
			if (index < 0 || index >= List.getsize())
				std::cout << "\x1B[91m������ �������� ������!\n";
			else
				std::cout << "\x1B[96m���� �� �������\x1B[93m " << "'" << index << "'" << "\x1B[96m ��� �����!\n";
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
	int data, key;
	while (x) {
		std::cout << "\n\x1B[93m ������� ������ ����� ����: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			std::cout << "\x1B[96m������� ������: \x1B[93m";
			std::cin >> data;
			Stack.add_end(data);
			std::cout << "������� ��� ������ � ����!\n";
			system("pause");
			break;

		case 2:
			system("cls");
			if (Stack.getsize() == 0) {
				std::cout << "\x1B[91m���� ����!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[93m������� ��� ����� �� �����!\n";
			Stack.delete_end();
			system("pause");
			break;

		case 3:
			system("cls");
			if (Stack.getsize() == 0) {
				std::cout << "\x1B[91m���� ����!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96m������ ���������� �������� �����: \x1B[93m";
			std::cout << Stack[Stack.getsize() - 1] << "\n\n";
			system("pause");
			break;

		case 4:
			system("cls");
			std::cout << "\x1B[96m������ �����: \x1B[93m";
			std::cout << Stack.getsize() << "\n";
			system("pause");
			break;

		default:
			break;
		}
		Menu(4);
	}

	return 0;
}

int TApplication::DynamicArrayMenu() {
	Menu(3);
	bool x = true; short index = 0, arrsize = Array.getsize();
	int data = 0, key;
	while (x) {
		std::cout << "\n\x1B[93m ������� ������ ����� ����: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				std::cout << "\x1B[91m������ ����!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96m������� ������ ��������, �������� �������� ����� �������� (0 - " << arrsize-1 << "): \x1B[93m";
				std::cin >> index;
			if (index > arrsize-1 || index < 0) {
				std::cout << "\x1B[91m������ �������� ������!\n";
				system("pause");
				break;
			}

			std::cout << "\x1B[96m�������� �������� ��� ��������� ��������: \x1B[93m";
			std::cout << Array[index] << "\n";
			system("pause");
			break;

		case 2:
			system("cls");
			arrsize = Array.getsize();
			std::cout << "\x1B[96m������� ������� ������ �������� (0 - " << arrsize << "): \x1B[93m";
			std::cin >> index;
			if (index > arrsize || index < 0) {
				std::cout << "\x1B[91m������ �������� ������!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96m������� �������� ������ ��������: \x1B[93m";
			std::cin >> data;
			Array.add(index, data);
			std::cout << "����� ������� ��� ������� ��������!\n";
			system("pause");
			break;

		case 3:
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				std::cout << "\x1B[91m������ ����!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96m������� ������ ��������, �������� �������� ����� �������� (0 - " << arrsize - 1 << "): \x1B[93m";
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "\x1B[91m ������ �������� ������!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96m������� ����� �������� �������� ��� ��������� ��������: \x1B[93m";
			std::cin >> data;
			Array[index] = data;
			std::cout << "�������� ��������!\n";
			system("pause");
			break;

		case 4:
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				std::cout << "\x1B[91m������ ����!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96m������� ������� ��������, ������� ����� ������� (0 - " << arrsize - 1 << "): \x1B[93m";
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "\x1B[91m ������ �������� ������!\n";
				system("pause");
				break;
			}
			Array.remove(index);
			std::cout << "������� �� ��������� ������� ��� ����� �� �������!\n";
			system("pause");
			break;

		case 5:
			system("cls");
			std::cout << "\x1B[96m������ �������: \x1B[93m";
			std::cout << Array.getsize() << "\n";
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