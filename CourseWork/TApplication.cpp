#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Graph.h"
#include "TApplication.h"

TApplication::TApplication() {
}

int TApplication::Menu(int status) {
	system("cls");
	std::cout << "\n\x1B[93m << Главное меню >>\033[0m\n";
	std::cout << "\n \x1B[96m<1> - Вывести матрицу смежности\n <2> - Обойти граф в глубину\n <3> - Обойти граф в ширину\n <4> - Поиск минимального остова\n <5> - Матрица инцидентности\n <6> - Список смежности\033[0m\n";
	std::cout << "\x1B[91m <0> - Выход из программы\033[0m\n";

	return 0;
}

int TApplication::Executor() {
	int v = 0;
	std::string filename = "matrix.txt";
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "\x1B[91mОшибка открытия файла!" << std::endl;
		return 1;
	}

	std::string line;
	std::getline(file, line);
	for (char c : line) {
		if (std::isalpha(c))
			++v;
	}
	Graph MyGraph(v, filename);

	int key;
	while (true) {
		Menu(1);
		std::cout << "\n\x1B[93m Введите нужный пункт меню: \x1B[96m";
		std::cin >> key;
		switch (key) {
		case 0:
			return 0;
		case 1:
			system("cls");
			std::cout << "\x1B[93mМатрица смежности:\n\n\x1B[96m";
			std::cout << MyGraph;
			std::cout << "\n";
			system("pause");
			break;

		case 2:
			system("cls");
			std::cout << "\x1B[93mОбход графа в глубину: \x1B[96m\n";
			MyGraph.DFS();
			std::cout << "\n\n";
			system("pause");
			break;

		case 3:
			system("cls");
			std::cout << "\x1B[93mОбход графа в ширину: \x1B[96m\n";
			MyGraph.BFS();
			std::cout << "\n\n";
			system("pause");
			break;

		case 4:
			system("cls");
			std::cout << "\x1B[93mПоиск минимального остова: \x1B[96m\n\n";
			MyGraph.Kruskal();
			std::cout << "\n\n";
			system("pause");
			break;

		case 5:
			system("cls");
			std::cout << "\x1B[93mМатрица инцидентности: \x1B[96m\n\n";
			MyGraph.getIM();
			std::cout << "\n\n";
			system("pause");
			break;

		case 6:
			system("cls");
			std::cout << "\x1B[93mСписок смежности: \x1B[96m\n\n";
			MyGraph.getAList();
			std::cout << "\n\n";
			system("pause");
			break;

		default:
			break;
		}
	}

	return 0;
}

TApplication::~TApplication() {
}