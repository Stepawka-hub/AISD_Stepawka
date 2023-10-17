#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
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
		std::cout << "\n <1> - Работа со списком\n <2> - Работа с динамическим массивом\n <3> - Работа со стеком\n <4> - Сортировочная станция\n";
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
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "\n << Работа с динамическим массивом >>\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "\n <1> - Получить значение элемента\n <2> - Добавить элемент в массив\n <3> - Изменить значение элемента\n <4> - Удалить элемент из массива\n <5> - Вывести размер массива\n";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " <0> - Вернуться в главное меню\n";
		break;

	case 4:
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "\n << Работа со стеком >>\n";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "\n <1> - Добавить элемент в стек\n <2> - Удалить последний элемент\n <3> - Получить последний элемент\n";
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << " <0> - Вернуться в главное меню\n";
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
		case '4':
			SortingStation();
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
			std::cout << "Узел был добавлен в начало списка с указанными данными.\n";
			system("pause");
			break;

		case '2':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Введите данные: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			List.add_end(data);
			std::cout << "Узел был добавлен в конец списка с указанными данными.\n";
			system("pause");
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
				break;
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
				std::cout << "Узел был добавлен в конец списка.\n";
			else if (index < 0)
				std::cout << "Узел был добавлен в начало списка.\n";
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
			std::cout << "Укажите позицию (индекс) узла, который нужно удалить (0 - " << List.getsize()-1 << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			SetConsoleTextAttribute(hConsole, 14);
			if (index < 0 || index >= List.getsize()) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Указан неверный индекс!\n";
			}
			else {
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << "Узел на позиции ";
				SetConsoleTextAttribute(hConsole, 14);
				std::cout << "'" << index << "'";
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << " был удалён!\n";
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
			std::cout << "Введите данные: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			Stack.add_end(data);
			std::cout << "Элемент был занесён в стек!\n";
			system("pause");
			break;

		case '2':
			system("cls");
			if (Stack.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Стек пуст!";
				break;
			}
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "Элемент был удалён из стека!\n";
			Stack.delete_end();
			system("pause");
			break;

		case '3':
			system("cls");
			if (Stack.getsize() == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Стек пуст!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Данные последнего элемента стека: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << Stack[Stack.getsize() - 1] << "\n\n";
			system("pause");
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
				std::cout << "Массив пуст!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Укажите индекс элемента, значение которого нужно получить (0 - " << arrsize-1 << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			if (index > arrsize-1 || index < 0) {
				std::cout << "Указан неверный индекс!\n";
				system("pause");
				break;
			}

			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Значение элемента под указанным индексом: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << Array[index] << "\n";
			system("pause");
			break;

		case '2':
			system("cls");
			arrsize = Array.getsize();
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Укажите позицию нового элемента (0 - " << arrsize << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			if (index > arrsize || index < 0) {
				std::cout << "Указан неверный индекс!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Введите значение нового элемента: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			Array.add(index, data);
			std::cout << "Новый элемент был успешно добавлен!\n";
			system("pause");
			break;

		case '3':
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Массив пуст!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Укажите индекс элемента, значение которого нужно изменить (0 - " << arrsize - 1 << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "Указан неверный индекс!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Введите новое значение элемента под указанным индексом: ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> data;
			Array[index] = data;
			std::cout << "Значение изменено!";
			system("pause");
			break;

		case '4':
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Массив пуст!\n";
				system("pause");
				break;
			}
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Укажите позицию элемента, который нужно удалить (0 - " << arrsize - 1 << "): ";
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "Указан неверный индекс!\n";
				system("pause");
				break;
			}
			Array.remove(index);
			std::cout << "Элемент на указанной позиции был удалён из массива!\n";
			system("pause");
			break;

		case '5':
			system("cls");
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Размер массива: ";
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

int TApplication::SortingStation() {
	system("cls");
	std::string Token;
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Разрешённые символы: ";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "+, -, *, /, ^, sin, cos, (, ), 0, 1, 2, 3, 4, 5, 6, 7, 8, 9\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Введите выражение (Обязателен пробел перед и после пробелов): ";
	SetConsoleTextAttribute(hConsole, 14);
	std::getline(std::cin, Token);
	Token.push_back(' ');

	while (QueueOutput.getsize())
		QueueOutput.delete_end();
	while (SortStack.getsize())
		SortStack.delete_end();
	SortingAlgorithm(Token);

	return 1;
}

void TApplication::SortingAlgorithm(std::string & Token) {
	std::string PartToken, top; short firstpos = 0, lastpos = 0, size = 0, obracket = 0, cbracket = 0;
	SetConsoleTextAttribute(hConsole, 11);

	for (int i = 0; i < Token.length(); ++i) {
		size = SortStack.getsize();
		lastpos = Token.find_first_of(' ', firstpos);
		if (lastpos == std::string::npos)
			break;
		PartToken = Token.substr(firstpos, lastpos - firstpos);
		firstpos = lastpos + 1;

		if (isdigit(PartToken[0]))
			QueueOutput.add_end(PartToken);

		else if (PartToken == "cos")
			SortStack.add_end(PartToken);

		else if (PartToken == "sin")
			SortStack.add_end(PartToken);

		else if (IsOperator(PartToken)) {
			if (size != 0)
				top = SortStack[size - 1];
			while ((IsOperator(top)) && (SortStack.getsize() != 0) && (IsPriority(top) >= IsPriority(PartToken))) {
				QueueOutput.add_end(top);
				SortStack.delete_end();
				size = SortStack.getsize();
				if (size != 0)
					top = SortStack[size - 1];
			}
			SortStack.add_end(PartToken);
		}

		else if (PartToken[0] == '(') {
			++obracket;
			SortStack.add_end("(");
		}

		else if (PartToken[0] == ')') {
			++cbracket;
			if (cbracket > obracket) {
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "Составлено неверное выражение!\n";
				system("pause");
				return;
			}

			while (SortStack[SortStack.getsize() - 1] != "(") {
				QueueOutput.add_end(SortStack[SortStack.getsize() - 1]);
				SortStack.delete_end();
				if (SortStack.getsize() == 0) {
					SetConsoleTextAttribute(hConsole, 12);
					std::cout << "Составлено неверное выражение!\n";
					system("pause");
					return;
				}
			}

			SortStack.delete_end();
			size = SortStack.getsize();
			if (size != 0) {
				if (SortStack[size - 1] == "sin" || SortStack[size - 1] == "cos") {
					QueueOutput.add_end(SortStack[size - 1]);
					SortStack.delete_end();
				}
			}
		}

		else {
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Составлено неверное выражение!\n";
			system("pause");
			return;
		}
	}

	if (obracket != cbracket) {
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Составлено неверное выражение!\n";
		system("pause");
		return;
	}

	size = SortStack.getsize();
	if (size != 0)
		top = SortStack[size - 1];
	while (IsOperator(top) && size > 0) {
		if (top == "(") {
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Составлено неверное выражение!\n";
			system("pause");
			return;
		}

		QueueOutput.add_end(top);
		SortStack.delete_end();
		size = SortStack.getsize();
		if (size != 0)
			top = SortStack[size - 1];
	}

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "Полученное выражение: ";
	SetConsoleTextAttribute(hConsole, 14);
	for (int i = 0; i < QueueOutput.getsize(); ++i)
		std::cout << QueueOutput[i] << " ";

	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "\nПодсчитанное выражение: ";
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << GetResult();
	std::cout << "\n";
	system("pause");
}

bool TApplication::IsOperator(std::string& Token) {
	return Token == "+" || Token == "-" || Token == "*" || Token == "/" || Token == "^";
}

int TApplication::IsPriority(std::string& op1) {
	if (op1 == "^")
		return 3;
	if (op1 == "*" || op1 == "/")
		return 2;
	if (op1 == "+" || op1 == "-")
		return 1;

	return 0;
}

double TApplication::GetResult() {
	std::string Token;
	LinkedList<double> CalcStack;
	double op1, op2;

	for (int i = 0; i < QueueOutput.getsize(); ++i) {
		Token = QueueOutput[i];
		if (isdigit(Token[0]))
			CalcStack.add_end(atof(Token.c_str()));

		else if (Token == "sin" || Token == "cos") {
			op1 = CalcStack[CalcStack.getsize() - 1];
			CalcStack.delete_end();

			if (Token == "cos")
				CalcStack.add_end(cos(op1));
			else
				CalcStack.add_end(sin(op1));
		}

		else {
			op2 = CalcStack[CalcStack.getsize() - 1];
			CalcStack.delete_end();
			op1 = CalcStack[CalcStack.getsize() - 1];
			CalcStack.delete_end();

			if (Token == "^")
				CalcStack.add_end(pow(op1, op2));
			if (Token == "+")
				CalcStack.add_end(op1 + op2);
			else if (Token == "-")
				CalcStack.add_end(op1 - op2);
			else if (Token == "*")
				CalcStack.add_end(op1 * op2);
			else if (Token == "/") {
				if (op2 == 0) {
					SetConsoleTextAttribute(hConsole, 12);
					std::cout << "\nЗнаменатель не может быть равен 0!\n";
					return 0;
				}
				CalcStack.add_end(op1 / op2);
			}
		}
	}

	if (CalcStack.getsize() != 0)
		return CalcStack[CalcStack.getsize() - 1];
	else {
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Составлено неверное выражение!\n";
		system("pause");
	}

	return 0;
}

TApplication::~TApplication() {
}