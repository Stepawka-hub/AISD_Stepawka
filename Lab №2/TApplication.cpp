#include <iostream>
#include <string>
#include "TApplication.h"

#define RAND_MAX = 100

TApplication::TApplication() {
}

int TApplication::Menu(int status) {
	system("cls");
	switch (status) {
	case 1:
		std::cout << "\n\x1B[93m << Меню >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - Работа со списком\n <2> - Работа с динамическим массивом\n <3> - Работа со стеком\033[0m\n";
		std::cout << "\x1B[91m <0> - Выход из программы\033[0m\n";
		break;

	case 2:
		std::cout << "\n\x1B[93m << Работа со списком >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - Добавить узел в начало списка\n <2> - Добавить узел в конец списка\n <3> - Удалить узел из начала списка\n <4> - Удалить узел с конца списка\n <5> - Вывести данные узла по индексу\n <6> - Добавить узел по индексу\n <7> - Удалить узел по индексу\033[0m\n";
		std::cout << "\x1B[91m <0> - Вернуться в главное меню\033[0m\n";
		break;

	case 3:
		std::cout << "\n\x1B[93m << Работа с динамическим массивом >>\033[0m\n";
		std::cout << "\n\x1B[93m << Основные функции >>\n \x1B[96m<1> - Получить значение элемента\n <2> - Добавить элемент в массив\n <3> - Изменить значение элемента\n <4> - Удалить элемент из массива\n <5> - Вывести размер массива\033[0m\n";
	    std::cout << "\n\x1B[93m << Вспомогательные функции >>\n \x1B[96m<6> - Заполнить массив случайными числами\n <7> - Вывести все элементы массива\n <8> - Очистить весь массив\n <9> - Отсортировать массив\033[0m\n";
		std::cout << "\x1B[91m <0> - Вернуться в главное меню\033[0m\n";
		break;

	case 4:
		std::cout << "\n\x1B[93m << Работа со стеком >>\033[0m\n";
		std::cout << "\n \x1B[96m<1> - Добавить элемент в стек\n <2> - Удалить последний элемент\n <3> - Получить последний элемент\n <4> - Вывести размер стека\033[0m\n";
		std::cout << "\x1B[91m <0> - Вернуться в главное меню\n";
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
		std::cout << "\n\x1B[93m Введите нужный пункт меню: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			std::cout << "\x1B[96mВведите данные: \x1B[93m";
			std::cin >> data;
			List.add_top(data);
			std::cout << "Узел был добавлен в начало списка с указанными данными.\n";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[96mВведите данные: \x1B[93m";
			std::cin >> data;
			List.add_end(data);
			std::cout << "Узел был добавлен в конец списка с указанными данными.\n";
			system("pause");
			break;

		case 3:
			system("cls");
			if (List.getsize() == 0) {
				std::cout << "\x1B[91mСписок пуст!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[93mУзел с начала списка был удалён!\n";
			List.delete_top();
			system("pause");
			break;

		case 4:
			system("cls");
			if (List.getsize() == 0) {
				std::cout << "\x1B[91mСписок пуст!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[93mУзел с конца списка был удалён!\n";
			List.delete_end();
			system("pause");
			break;

		case 5:
			system("cls");
			if (List.getsize() == 0) {
				std::cout << "\x1B[91mСписок пуст!\n";
				system("pause");
				break;
			}
			else {
				std::cout << "\x1B[96mУкажите индекс возвращаемого узла (0 - " << List.getsize() - 1 << "): \x1B[93m";
				std::cin >> index;
			}

			if (index < 0 || index >= List.getsize()) {
				std::cout << "\x1B[91mВы указали неверный индекс!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96mДанные узла: \x1B[93m";
			std::cout << List[index] << "\n\n";
			system("pause");
			break;

		case 6:
			system("cls");
			std::cout << "\x1B[96mУкажите позицию (индекс) нового узла: \x1B[93m";
			std::cin >> index;
			std::cout << "\x1B[96mВведите данные: \x1B[93m";
			std::cin >> data;
			List.insert(index, data);
			if (index + 1 > List.getsize())
				std::cout << "\x1B[96mУзел был добавлен в конец списка.\n";
			else if (index < 0)
				std::cout << "\x1B[96mУзел был добавлен в начало списка.\n";
			else
				std::cout << "\x1B[96mУзел был добавлен на позицию \x1B[93m" << "'" << index << "'" << "\n";
			system("pause");
			break;

		case 7:
			system("cls");
			if (List.getsize() == 0) {
				std::cout << "\x1B[91mСписок пуст! Удаление узла по индексу невозможно!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96mУкажите позицию (индекс) узла, который нужно удалить (0 - " << List.getsize()-1 << "): \x1B[93m";
			std::cin >> index;
			if (index < 0 || index >= List.getsize())
				std::cout << "\x1B[91mУказан неверный индекс!\n";
			else
				std::cout << "\x1B[96mУзел на позиции\x1B[93m " << "'" << index << "'" << "\x1B[96m был удалён!\n";
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
		std::cout << "\n\x1B[93m Введите нужный пункт меню: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			x = false;
			break;

		case 1:
			system("cls");
			std::cout << "\x1B[96mВведите данные: \x1B[93m";
			std::cin >> data;
			Stack.add_end(data);
			std::cout << "Элемент был занесён в стек!\n";
			system("pause");
			break;

		case 2:
			system("cls");
			if (Stack.getsize() == 0) {
				std::cout << "\x1B[91mСтек пуст!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[93mЭлемент был удалён из стека!\n";
			Stack.delete_end();
			system("pause");
			break;

		case 3:
			system("cls");
			if (Stack.getsize() == 0) {
				std::cout << "\x1B[91mСтек пуст!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96mДанные последнего элемента стека: \x1B[93m";
			std::cout << Stack[Stack.getsize() - 1] << "\n\n";
			system("pause");
			break;

		case 4:
			system("cls");
			std::cout << "\x1B[96mРазмер стека: \x1B[93m";
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
	int i, elements;
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
			arrsize = Array.getsize();
			if (arrsize == 0) {
				std::cout << "\x1B[91mМассив пуст!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96mУкажите индекс элемента, значение которого нужно получить (0 - " << arrsize - 1 << "): \x1B[93m";
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "\x1B[91mУказан неверный индекс!\n";
				system("pause");
				break;
			}

			std::cout << "\x1B[96mЗначение элемента под указанным индексом: \x1B[93m";
			std::cout << Array[index] << "\n";
			system("pause");
			break;

		case 2:
			system("cls");
			arrsize = Array.getsize();
			std::cout << "\x1B[96mУкажите позицию нового элемента (0 - " << arrsize << "): \x1B[93m";
			std::cin >> index;
			if (index > arrsize || index < 0) {
				std::cout << "\x1B[91mУказан неверный индекс!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96mВведите значение нового элемента: \x1B[93m";
			std::cin >> data;
			Array.add(index, data);
			std::cout << "Новый элемент был успешно добавлен!\n";
			system("pause");
			break;

		case 3:
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				std::cout << "\x1B[91mМассив пуст!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96mУкажите индекс элемента, значение которого нужно изменить (0 - " << arrsize - 1 << "): \x1B[93m";
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "\x1B[91m Указан неверный индекс!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96mВведите новое значение элемента под указанным индексом: \x1B[93m";
			std::cin >> data;
			Array[index] = data;
			std::cout << "Значение изменено!\n";
			system("pause");
			break;

		case 4:
			system("cls");
			arrsize = Array.getsize();
			if (arrsize == 0) {
				std::cout << "\x1B[91mМассив пуст!\n";
				system("pause");
				break;
			}
			std::cout << "\x1B[96mУкажите позицию элемента, который нужно удалить (0 - " << arrsize - 1 << "): \x1B[93m";
			std::cin >> index;
			if (index > arrsize - 1 || index < 0) {
				std::cout << "\x1B[91m Указан неверный индекс!\n";
				system("pause");
				break;
			}
			Array.remove(index);
			std::cout << "Элемент на указанной позиции был удалён из массива!\n";
			system("pause");
			break;

		case 5:
			system("cls");
			std::cout << "\x1B[96mРазмер массива: \x1B[93m";
			std::cout << Array.getsize() << "\n";
			system("pause");
			break;

		case 6:
			elements = 0;
			arrsize = Array.getsize();

			system("cls");
			std::cout << "\x1B[96mУкажите количество добавляемых элементов: \x1B[93m";
			std::cin >> elements;
			for (i = 0; i < elements; ++i)
				Array.add(arrsize + i, rand());
			std::cout << "Элементы были успешно добавлены!\n";
			system("pause");
			break;

		case 7:
			arrsize = Array.getsize();
			system("cls");

			if (arrsize == 0) {
				std::cout << "\x1B[91mМассив пуст!\n";
				system("pause");
				break;
			}

			for (i = 0; i < arrsize; ++i)
				std::cout << "\x1B[96mElement [" << i << "]:\t\x1B[93m" << Array[i] << "\n";
			system("pause");
			break;


		case 8:
			arrsize = Array.getsize();
			system("cls");

			if (arrsize == 0) {
				std::cout << "\x1B[91mМассив пуст!\n";
				system("pause");
				break;
			}

			for (i = 1; i <= arrsize; ++i)
				Array.remove(arrsize - i);
			system("pause");
			break;

		case 9:
			system("cls");
			Array.sort();
			std::cout << "\x1B[93mМассив отсортирован!\x1B[93m\n";
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