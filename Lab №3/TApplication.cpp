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
		std::cout << "\n\x1B[93m << ������� ���� >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - ������ � �������� �������\n <2> - ������ � ��� �������\033[0m\n";
		std::cout << "\x1B[91m <0> - ����� �� ���������\033[0m\n";
		break;

	case 2:
		std::cout << "\n\x1B[93m << ������ � �������� ������� >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - ������� ������ � �����\n <2> - ������� �������� ������ �� �����\033[0m\n";
		std::cout << "\x1B[91m <0> - ��������� � ������� ����\033[0m\n";
		break;

	case 3:
		std::cout << "\n\x1B[93m << ������ � ��� ������� >>\033[0m\n";
		std::cout << "\n\x1B[93m << �������� ������� >>\033[0m";
		std::cout << "\n \x1B[96m<1> - ������� ������ � �����\n <2> - ������� �������� ������ �� �����\n <3> - �������� �������\n <4> - �������� ������\n <5> - �������� ��������\033[0m\n";
		
		std::cout << "\n\x1B[93m << ���� ������� >>\033[0m";
		std::cout << "\n \x1B[96m<6> - ����� � ������\n <7> - ������ �����\n <8> - �������������� �����\n <9> - �������� �����\033[0m\n";
		std::cout << "\x1B[91m <0> - ��������� � ������� ����\033[0m\n";
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
		std::cout << "\n\x1B[93m ������� ������ ����� ����: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			std::cout << "\x1B[93m*������ ����������� � �����*\n";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[93m*������ ��������� � �������*\n";
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
		std::cout << "\n\x1B[93m ������� ������ ����� ����: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			std::cout << "\x1B[93m*������ ����������� � �����*\n";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[93m*������ ��������� �� �����*\n";
			system("pause");
			break;

		case 3:
			system("cls");
			std::cout << "\x1B[93m*�������� �������*\n";
			system("pause");
			break;

		case 4:
			system("cls");
			std::cout << "\x1B[93m*�������� ������*\n";
			system("pause");
			break;

		case 5:
			system("cls");
			std::cout << "\x1B[93m*�������� ��������*\n";
			system("pause");
			break;

		case 6:
			system("cls");
			std::cout << "\x1B[93m*����� � ������*\n";
			system("pause");
			break;

		case 7:
			system("cls");
			std::cout << "\x1B[93m*������ �����*\n";
			system("pause");
			break;

		case 8:
			system("cls");
			std::cout << "\x1B[93m*�������������� �����*\n";
			system("pause");
			break;

		case 9:
			system("cls");
			std::cout << "\x1B[93m*�������� �����*\n";
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