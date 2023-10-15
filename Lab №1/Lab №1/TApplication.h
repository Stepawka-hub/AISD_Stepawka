#pragma once
#include "linked_list.h"
#include "dynamic_array.h"

class TApplication {
private:
	LinkedList<int> List;
	DynamicArray<int> Array;
	LinkedList<int> Stack;
	int Menu(int status);
	int LinkedListMenu();
	int StackMenu();
	int DynamicArrayMenu();

public:

	TApplication();
	int Executor();
	~TApplication();
};
