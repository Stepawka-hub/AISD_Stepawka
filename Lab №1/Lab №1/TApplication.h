#pragma once
#include "linked_list.h"
#include "dynamic_array.h"

class TApplication {
private:
	LinkedList<int> List;
	DynamicArray<int> Array;
	LinkedList<int> Stack;
	LinkedList<std::string> SortStack, QueueOutput;
	int Menu(int);
	int LinkedListMenu();
	int StackMenu();
	int DynamicArrayMenu();
	int SortingStation();
	void SortingAlgorithm(std::string &);
	bool IsOperator(std::string&);
	int IsPriority(std::string&);
	double GetResult();

public:
	TApplication();
	int Executor();
	~TApplication();
};
